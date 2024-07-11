//! Data handling module
//!
//! All data goes through the MPMC queues defined in `main.rs`.
//! This module is the middle man between the data producers and the ground station.

mod batteries;
mod sources;
use crate::Datatype;
use crate::ValueCheckResult;
use crate::DataReceiver;
use crate::DataSender;
use crate::Event;
use crate::EventSender;
use crate::Datapoint;
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
        match data.datatype.check_bounds(data.value) {
            ValueCheckResult::Fine => {},
            ValueCheckResult::Warn => {
                outgoing.send(value_warning(data.datatype, data.value)).await;
            }
            ValueCheckResult::Error => {
                outgoing.send(value_error(data.datatype, data.value)).await;
            }
            ValueCheckResult::BrakeNow => {
                event_sender.send(Event::ValueOutOfBounds).await;
                outgoing.send(value_critical(data.datatype, data.value)).await;
            }
        }
        // 2. check specific data types

        outgoing.send(data).await;
    }
}

fn value_warning(dt: Datatype, v: u64) -> Datapoint {
    Datapoint::new(Datatype::ValueWarning, dt.to_id() as u64, v)
}

fn value_error(dt: Datatype, v: u64) -> Datapoint {
    Datapoint::new(Datatype::ValueError, dt.to_id() as u64, v)
}

fn value_critical(dt: Datatype, v: u64) -> Datapoint {
    Datapoint::new(Datatype::ValueCausedBraking, dt.to_id() as u64, v)
}
