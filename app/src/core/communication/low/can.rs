use defmt::*;
use defmt_rtt as _;
use embassy_executor::Spawner;
use embassy_stm32::can::CanRx;
use embassy_stm32::can::CanTx;
use embassy_stm32::can::Frame;
use embassy_stm32::can::Instance;
use embassy_time::Duration;
use embassy_time::Instant;
use embassy_time::Timer;
use panic_probe as _;

// use embedded_hal::can::Id;
use crate::core::communication::Datapoint;
use crate::core::controllers::battery_controller::ground_fault_detection_isolation_details;
use crate::core::controllers::battery_controller::ground_fault_detection_voltage_details;
use crate::core::controllers::can_controller::CanTwoUtils;
use crate::pconfig::bytes_to_u64;
use crate::pconfig::id_as_value;
use crate::pconfig::queue_event;
use crate::pconfig::send_event;
use crate::send_data;
use crate::try_spawn;
use crate::CanReceiver;
use crate::CanSender;
use crate::DataSender;
use crate::Datatype;
use crate::Event;
use crate::EventSender;
use crate::Info;
use crate::BATTERY_GFD_IDS;
use crate::DATA_IDS;
use crate::EVENT_IDS;
use crate::GFD_IDS;
use crate::HV_IDS;
use crate::LV_IDS;

#[embassy_executor::task(pool_size = 2)]
pub async fn can_transmitter(
    can_receiver: CanReceiver,
    mut bus: CanTx<'static, impl Instance>,
) -> ! {
    loop {
        let frame = can_receiver.receive().await;
        bus.write(&frame).await;
    }
}

static mut HV_LAST_RECEIVED: Instant = Instant::from_millis(0);
static mut LV_LAST_RECEIVED: Instant = Instant::from_millis(0);

#[embassy_executor::task(pool_size = 2)]
pub async fn can_receiving_handler(
    x: Spawner,
    event_sender: EventSender,
    can_sender: CanSender,
    data_sender: DataSender,
    mut bus: CanRx<'static, impl Instance>,
    mut utils: Option<CanTwoUtils>,
) -> ! {
    let bus_nr = if utils.is_none() { 1 } else { 2 };
    info!("[CAN] Ready for bus {:?}", bus_nr);
    let mut error_counter = 0u64;
    let mut gfd_counter = 0u64;
    if bus_nr == 2 {
        try_spawn!(event_sender, x.spawn(can_two_watchdog(event_sender, data_sender)));
    }
    loop {
        match bus.read().await {
            Ok(envelope) => {
                error_counter = 0;
                let (frame, timestamp) = envelope.parts();
                let id = id_as_value(frame.id());
                trace!("[CAN ({})] received frame: id={:?} data={:?}", bus_nr, id, frame.data());
                if DATA_IDS.contains(&id) {
                    if BATTERY_GFD_IDS.contains(&id) && utils.is_some() {
                        let ut = utils.as_mut().unwrap();
                        if HV_IDS.contains(&id) {
                            ut.hv_controller
                                .bms_can_handle(id, frame.data(), data_sender, timestamp.as_ticks())
                                .await;
                            unsafe {
                                HV_LAST_RECEIVED = Instant::now();
                            }
                        } else if LV_IDS.contains(&id) {
                            ut.lv_controller
                                .bms_can_handle(id, frame.data(), data_sender, timestamp.as_ticks())
                                .await;
                            unsafe {
                                LV_LAST_RECEIVED = Instant::now();
                            }
                        } else if GFD_IDS.contains(&id) {
                            if id == Datatype::IMDVoltageDetails.to_id() {
                                ground_fault_detection_isolation_details(
                                    frame.data(),
                                    data_sender,
                                    timestamp.as_ticks(),
                                )
                                .await;
                            } else if id == Datatype::IMDIsolationDetails.to_id() {
                                ground_fault_detection_voltage_details(
                                    frame.data(),
                                    data_sender,
                                    timestamp.as_ticks(),
                                )
                                .await;
                            } else if gfd_counter > 2 && frame.data()[2] == 0xFE {
                                gfd_counter = 0;
                                can_sender
                                    .send(
                                        Frame::new_extended(0x18EAFF17, &[0x03u8, 0xFFu8, 0x00u8])
                                            .unwrap(),
                                    )
                                    .await;
                                can_sender
                                    .send(
                                        Frame::new_extended(0x18EAFF17, &[0x02u8, 0xFFu8, 0x00u8])
                                            .unwrap(),
                                    )
                                    .await;
                            } else {
                                gfd_counter += 1;
                            }
                        }
                    } else {
                        trace!("#{}", bytes_to_u64(frame.data()));
                        data_sender
                            .send(Datapoint::new(
                                Datatype::from_id(id),
                                bytes_to_u64(frame.data()),
                                timestamp.as_ticks(),
                            ))
                            .await;
                    }
                } else if EVENT_IDS.contains(&id) {
                    // since we are never supposed to change the speed through the can bus (and run config is the only event with an actual value), i want a magic number that i can filter out from the run config handler just to make sure the pod doesn't do something stupid
                    send_event(event_sender, Event::from_id(id, Some(69420)));
                } else {
                    send_data!(
                        data_sender,
                        Datatype::UnknownCanId,
                        id as u64,
                        bytes_to_u64(frame.data())
                    );
                }
            },
            Err(e) => {
                if error_counter < 10 || error_counter % 2500 == 0 {
                    error!(
                        "[CAN ({})] Error reading from CAN bus (#{}): {:?}",
                        bus_nr, error_counter, e
                    );
                }
                Timer::after_millis(500).await;
                error_counter = error_counter.wrapping_add(1);
            },
        }
        // # VERY IMPORTANT
        // without this, our main pcb is magically converted to an adhd CAN
        // pcb with no mind for anything else. Tread carefully around it
        // thread_delay(100).await;
        Timer::after_micros(500).await;
    }
}

#[embassy_executor::task]
async fn can_two_watchdog(event_sender: EventSender, data_sender: DataSender) {
    Timer::after_secs(20).await;
    let mut lv_trigger = true;
    let mut hv_trigger = true;
    loop {
        if unsafe { HV_LAST_RECEIVED.elapsed() > Duration::from_millis(2500) } {
            if lv_trigger {
                queue_event(event_sender, Event::EmergencyBraking).await;
                lv_trigger = false;
                send_data!(data_sender, Datatype::Info, Info::HvBmsTimedOut as u64);
            }
        } else {
            lv_trigger = true;
        }
        if unsafe { LV_LAST_RECEIVED.elapsed() > Duration::from_millis(2500) } {
            if hv_trigger {
                queue_event(event_sender, Event::EmergencyBraking).await;
                hv_trigger = false;
                send_data!(data_sender, Datatype::Info, Info::LvBmsTimedOut as u64);
            }
        } else {
            hv_trigger = true;
        }
    }
}
