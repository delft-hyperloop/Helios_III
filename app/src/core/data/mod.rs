//! Data handling module
//!
//! All data goes through the MPMC queues defined in `main.rs`.
//! This module is the middle man between the data producers and the ground station.

mod batteries;
mod sources;

use embassy_time::Duration;
use embassy_time::Instant;
use heapless::Vec;

use crate::{DataReceiver, send_data};
use crate::DataSender;
use crate::Datapoint;
use crate::Datatype;
use crate::Event;
use crate::EventSender;
use crate::Info;
use crate::ValueCheckResult;
use crate::HEARTBEATS;
use crate::HEARTBEATS_LEN;
use crate::pconfig::{queue_event, ticks};

type HB = Vec<(Datatype, Duration, Option<Instant>), { HEARTBEATS_LEN }>;

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
    let mut hb = HB::new();
    let hb_dt = HEARTBEATS.iter().map(|x| x.0).collect::<Vec<Datatype, { HEARTBEATS_LEN }>>();

    loop {
        let data = incoming.receive().await;

        // 1. check thresholds
        match data.datatype.check_bounds(data.value) {
            ValueCheckResult::Fine => {},
            ValueCheckResult::Warn => send_data!(outgoing, Datatype::ValueWarning, data.datatype.to_id() as u64, data.value),
            ValueCheckResult::Error => send_data!(outgoing, Datatype::ValueError, data.datatype.to_id() as u64, data.value),
            ValueCheckResult::BrakeNow => {
                queue_event(event_sender, Event::ValueOutOfBounds).await;
                send_data!(outgoing, Datatype::ValueCausedBraking, data.datatype.to_id() as u64, data.value);
            },
        }
        // 2. check heartbeats
        let mut seen = !hb_dt.contains(&data.datatype);

        for (dt, out, last) in hb.iter_mut() {
            if !seen && *dt == data.datatype {
                seen = true;
                *last = Some(Instant::now());
            } else if last.is_some_and(|l| l.elapsed() > *out) {
                event_sender.send(Event::EmergencyBraking).await;
                outgoing
                    .send(Datapoint::new(
                        Datatype::HeartbeatExpired,
                        dt.to_id() as u64,
                        ticks(),
                    ))
                    .await;
                *last = None;
            }
        }
        if !seen {
            match hb.push((data.datatype, timeout(data.datatype), None)) {
                Ok(_) => {},
                Err(_) => {
                    send_data!(outgoing, Datatype::Info, Info::lamp_error_unreachable.to_idx());
                },
            }
        }

        // 3. check for special cases

        outgoing.send(data).await;
    }
}

fn timeout(dt: Datatype) -> Duration {
    for (d, t) in HEARTBEATS {
        if d == dt {
            return Duration::from_millis(t);
        }
    }
    Duration::from_millis(0) // This is unreachable,
    // but as to not panic we return zero timeout.
    // Since this will always be expired, it will always cause emergency braking
}
//
// fn value_warning(dt: Datatype, v: u64) -> Datapoint {
//     Datapoint::new(Datatype::ValueWarning, dt.to_id() as u64, v)
// }
//
// fn value_error(dt: Datatype, v: u64) -> Datapoint {
//     Datapoint::new(Datatype::ValueError, dt.to_id() as u64, v)
// }
//
// fn value_critical(dt: Datatype, v: u64) -> Datapoint {
//     Datapoint::new(Datatype::ValueCausedBraking, dt.to_id() as u64, v)
// }
