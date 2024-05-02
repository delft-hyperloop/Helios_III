use core::any::Any;
use defmt::*;
use embassy_executor::Spawner;
use embassy_stm32::{bind_interrupts, peripherals, rng, Config, can};
use embassy_stm32::can::{Fdcan, FdcanRx, FdcanTx, Instance};
use embassy_stm32::can::frame::{ClassicFrame, Header};
use embassy_time::{Duration, Timer};
use embedded_io_async::{Read, Write};
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};
use embassy_stm32::gpio::{Level, Output, Speed};
use embassy_stm32::peripherals::{FDCAN1, FDCAN2};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::{Receiver, Sender};
use embedded_hal::can::Id;
use embedded_hal::prelude::_embedded_hal_blocking_spi_Write;
// use embedded_hal::can::Id;
use heapless::binary_heap::Max;
use heapless::Vec;
use crate::{BATTERY_GFD_IDS, CanReceiver, CanSender, DATA_IDS, DataReceiver, DataSender, Datatype, Event, EVENT_IDS, EventSender, GFD_IDS, HV_IDS, LV_IDS};
use crate::core::communication::Datapoint;
use crate::pconfig::{bytes_to_u64, id_as_value};
use crate::core::controllers::battery_controller::{BatteryController, ground_fault_detection_isolation_details, GroundFaultDetection};
use crate::core::controllers::can_controller::CanTwoUtils;


#[embassy_executor::task(pool_size=2)]
pub async fn can_transmitter(
    can_receiver: CanReceiver,
    mut bus : FdcanTx<'static, impl Instance>
) -> ! {
    loop {
        let frame = can_receiver.receive().await;
        bus.write(&frame).await;
    }
}


#[embassy_executor::task(pool_size=2)]
pub async fn can_receiving_handler(
    x: Spawner,
    event_sender : EventSender,
    can_receiver: CanReceiver,
    data_sender: DataSender,
    mut bus : FdcanRx<'static, impl Instance>,
    mut utils: Option<CanTwoUtils>,
) -> ! {
    loop {
        info!("Can Ready");
        match bus.read().await {
            Ok((frame, timestamp)) => {
                let id = id_as_value(frame.id());
                if DATA_IDS.contains(&id) {
                    if BATTERY_GFD_IDS.contains(&id) && utils.is_some() {
                        let ut = utils.as_mut().unwrap();
                        if HV_IDS.contains(&id) {
                            ut.hv_controller.bms_can_handle(id,frame.data(),data_sender,timestamp.as_ticks());
                        } else if LV_IDS.contains(&id) {
                            ut.lv_controller.bms_can_handle(id, frame.data(), data_sender, timestamp.as_ticks());
                        } else if GFD_IDS.contains(&id) {
                            // do something idk
                            // neither do I : Kiko
                        }
                    } else {
                        data_sender.send(Datapoint::new(
                            Datatype::from_id(id),
                            bytes_to_u64(frame.data()),
                            timestamp.as_ticks())
                        ).await;
                    }
                } else if EVENT_IDS.contains(&id) {
                    event_sender.send(Event::from_id(id)).await;
                }
                else {
                    info!("ID: {:?}", id);
                }
            }
            Err(e) => {
                error!("[CAN] Error reading from CAN bus: {:?}", e);
            }
        }
    }
}


// #[embassy_executor::task]
// pub async fn can_two_receiver_handler(
//     x: Spawner,
//     event_sender : EventSender,
//     can_receiver: CanReceiver,
//     data_sender: DataSender,
//     mut lv_controller: BatteryController,
//     mut hv_controller: BatteryController,
//     mut bus_rx : FdcanRx<'static, impl Instance>,
//     mut bus_tx : FdcanTx<'static, impl Instance>
// ) -> ! {
//     info!("---------- BMS LOAD SENT ----------");
//     loop {
//         info!("CAN 2 Receiver Handler is on baby");
//         match bus_rx.read().await {
//             Ok((frame,timestamp)) => {
//                 let id = id_as_value(frame.id());
//                 if id <= 0x40{  // <----- All the messages between 0 and 0x40 are from GFD
//
//                 }
//                 else if id > 0x40 && id <= 0x150 { // <----- All the messages between 0x40 and 0x150 are from HV BMS
//                     bus_tx.write(&ClassicFrame::new_standard(id,&[0;8]).unwrap());
//                     info!("MSG recieved from HV BMS");
//                 }
//                 else { // <----- All the messages above 0x150 are from the LVBMS
//                         bus_tx.write(&ClassicFrame::new_standard(id,&[0;8]).unwrap());
//                 }
//             }
//             Err(_) => {
//                  info!("Error reading from CAN bus");
//             }
//
//         }
//     }
// }
