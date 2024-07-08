//! Data handling module
//!
//! All data goes through the MPMC queues defined in `main.rs`.
//! This module is the middle man between the data producers and the ground station.

mod batteries;

use crate::DataReceiver;
use crate::DataSender;
use crate::Event;
use crate::EventSender;

/// ## Individual handling of datapoints
/// A lot of the subsystems on the pod use their own "encoding" for data.
/// In order to make a reasonable matching between semantic meaning of
/// all data and the datatypes in config/datatypes, we need to extract it.
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
