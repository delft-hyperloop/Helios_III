use defmt::*;
use embassy_executor::Spawner;
use embassy_stm32::{bind_interrupts, peripherals, rng, Config};
use embassy_stm32::can::{Fdcan, FdcanRx, FdcanTx, Instance};
use embassy_time::{Duration, Timer};
use embedded_io_async::{Read, Write};
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};
use embassy_stm32::gpio::{Level, Output, Speed};
use embassy_stm32::peripherals::{FDCAN1, FDCAN2};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::{Receiver, Sender};
// use embedded_hal::can::Id;
use heapless::binary_heap::Max;
use heapless::Vec;
use crate::{CanReceiver, DATA_IDS, DataReceiver, DataSender, Datatype, Event, EVENT_IDS, EventSender};
use crate::core::communication::Datapoint;
use crate::pconfig::{bytes_to_u64, id_as_value};


#[embassy_executor::task]
pub async fn can_transmitter(
    can_receiver: CanReceiver,
    mut bus : FdcanTx<'static, impl Instance>
) -> ! {
    loop {
        let frame = can_receiver.receive().await;
        bus.write(&frame).await;
    }
}


#[embassy_executor::task]
pub async fn can_receiving_handler(
    x: Spawner,
    event_sender : EventSender,
    can_receiver: CanReceiver,
    data_sender: DataSender,
    mut bus : FdcanRx<'static, impl Instance>
) -> ! {
    loop {
        match bus.read().await {
            Ok((frame, timestamp)) => {
                let id = id_as_value(frame.id());
                if DATA_IDS.contains(&id) {
                    data_sender.send(Datapoint::new(
                        Datatype::from_id(id),
                        bytes_to_u64(frame.data()),
                        timestamp.as_ticks())
                    ).await;
                } else if EVENT_IDS.contains(&id) {
                    event_sender.send(Event::from_id(id)).await;
                }
            }
            Err(_) => {
                // info!("Error reading from CAN bus");
            }
        }
    }
}


#[embassy_executor::task]
pub async fn can_two_receiver_handler(
    x: Spawner,
    event_sender : EventSender,
    can_receiver: CanReceiver,
    data_sender: DataSender,
    bus : FdcanRx<'static, FDCAN2>
) -> ! {

    loop {

    }
}