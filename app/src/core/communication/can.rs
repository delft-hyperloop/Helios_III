use core::any::Any;
use defmt::*;
use embassy_executor::Spawner;
use embassy_stm32::can::frame::{Frame, Header};
use embassy_stm32::can::{CanRx, CanTx,  Instance};
use embassy_stm32::gpio::{Level, Output, Speed};
use embassy_stm32::peripherals::{FDCAN1, FDCAN2};
use embassy_stm32::{bind_interrupts, can, peripherals, rng, Config};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::{Receiver, Sender};
use embassy_time::{Duration, Timer};
use embedded_hal::can::Id;
use embedded_hal::prelude::_embedded_hal_blocking_spi_Write;
use embedded_io_async::{Read, Write};
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};
// use embedded_hal::can::Id;
use crate::core::communication::Datapoint;
use crate::core::controllers::battery_controller::{ground_fault_detection_isolation_details, BatteryController, GroundFaultDetection, ground_fault_detection_voltage_details};
use crate::core::controllers::can_controller::CanTwoUtils;
use crate::pconfig::{bytes_to_u64, id_as_value};
use crate::{
    CanReceiver, CanSender, DataReceiver, DataSender, Datatype, Event, EventSender,
    BATTERY_GFD_IDS, DATA_IDS, EVENT_IDS, GFD_IDS, HV_IDS, LV_IDS,
};
use heapless::binary_heap::Max;
use heapless::Vec;

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

#[embassy_executor::task(pool_size = 2)]
pub async fn can_receiving_handler(
    x: Spawner,
    event_sender: EventSender,
    can_receiver: CanReceiver,
    data_sender: DataSender,
    mut bus: CanRx<'static, impl Instance>,
    mut utils: Option<CanTwoUtils>,
) -> ! {
    info!(
        "[CAN] Ready for bus {:?}",
        if utils.is_none() { 1 } else { 2 }
    );
    loop {
        match bus.read().await {
            Ok(envelope) => {
                let (frame,timestamp) = envelope.parts();
                let id = id_as_value(frame.id());
                #[cfg(debug_assertions)]
                info!("[CAN] received frame: id={:?} data={:?}", id, frame.data());
                if DATA_IDS.contains(&id) {
                debug!("first if");
                    if BATTERY_GFD_IDS.contains(&id) && utils.is_some() {
                        debug!("second if");
                        let ut = utils.as_mut().unwrap();
                        if HV_IDS.contains(&id) {
                            debug!("hv if");
                            ut.hv_controller.bms_can_handle(
                                id,
                                frame.data(),
                                data_sender,
                                timestamp.as_ticks(),
                            );
                        } else if LV_IDS.contains(&id) {
                            debug!("lv if");
                            ut.lv_controller.bms_can_handle(
                                id,
                                frame.data(),
                                data_sender,
                                timestamp.as_ticks(),
                            ).await;
                           // event_sender.send(Event::ConnectionEstablishedEvent).await;
                        } else if GFD_IDS.contains(&id) {
                            if id == Datatype::IMDVoltageDetails.to_id() {
                                data_sender.send(Datapoint::new(
                                    Datatype::IMDVoltageDetails,
                                    ground_fault_detection_voltage_details(frame.data()).await,
                                    timestamp.as_ticks(),
                                )).await;
                            }
                            else {
                            data_sender.send(Datapoint::new(
                                Datatype::IMDIsolationDetails,
                                ground_fault_detection_isolation_details(frame.data()).await,
                                timestamp.as_ticks(),
                            )).await;
                            }

                        }
                    } else {
                        data_sender
                            .send(Datapoint::new(
                                Datatype::from_id(id),
                                bytes_to_u64(frame.data()),
                                timestamp.as_ticks(),
                            ))
                            .await;
                    }
                } else if EVENT_IDS.contains(&id) {
                    event_sender.send(Event::from_id(id, Some(69420))).await; // since we are never supposed to change the speed through the can bus (and run config is the only event with an actual value), i want a magic number that i can filter out from the run config handler just to make sure the pod doesn't do something stupid
                } else {
                    #[cfg(debug_assertions)]
                    info!("[CAN] unknown ID: {:?}", id);
                    data_sender
                        .send(Datapoint::new(
                            Datatype::UnknownCanId,
                            bytes_to_u64(frame.data()),
                            timestamp.as_ticks(),
                        ))
                        .await;
                }
            }
            Err(e) => {
                error!("[CAN] Error reading from CAN bus: {:?}", e);
            }
        }
        /// # VERY IMPORTANT
        /// without this, our main pcb is magically converted to an adhd CAN pcb
        /// with no mind for anything else. Tread carefully around it
        Timer::after_micros(100).await;
    }
}
