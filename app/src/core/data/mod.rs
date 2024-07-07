//! Data handling module
//!
//! All data goes through the MPMC queues defined in `main.rs`.
//! This module is the middle man between the data producers and the ground station.

mod batteries;

use crate::DataReceiver;
use crate::DataSender;
use crate::Event;
use crate::EventSender;

#[embassy_executor::task]
pub async fn data_middle_step(
    incoming: DataReceiver,
    outgoing: DataSender,
    event_sender: EventSender,
) -> ! {
    loop {
        let data = incoming.receive().await;

        // 1. check thresholds
        if data.datatype.check_bounds(data.value) {
            event_sender.send(Event::ValueOutOfBounds).await;
        }
        // 2. check specific data types

        outgoing.send(data).await;
    }
}
