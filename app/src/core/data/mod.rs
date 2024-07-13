//! Data handling module
//!
//! All data goes through the MPMC queues defined in `main.rs`.
//! This module is the middle man between the data producers and the ground station.

mod batteries;
mod sources;

use embassy_time::{Duration, Instant};
use heapless::Vec;
use crate::{DataReceiver, HEARTBEATS, HEARTBEATS_LEN, Info};
use crate::DataSender;
use crate::Datapoint;
use crate::Datatype;
use crate::Event;
use crate::EventSender;
use crate::ValueCheckResult;

type HB = Vec<(Datatype, Duration, Instant), { HEARTBEATS_LEN }>;

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
            ValueCheckResult::Warn => {
                outgoing.send(value_warning(data.datatype, data.value)).await;
            },
            ValueCheckResult::Error => {
                outgoing.send(value_error(data.datatype, data.value)).await;
            },
            ValueCheckResult::BrakeNow => {
                event_sender.send(Event::ValueOutOfBounds).await;
                outgoing.send(value_critical(data.datatype, data.value)).await;
            },
        }
        // 2. check heartbeats
        let mut seen = !hb_dt.contains(&data.datatype);

        for (dt, out, last) in hb.iter_mut() {
            if !seen && *dt == data.datatype {
                seen = true;
                *last = Instant::now();
            } else {
                if last.elapsed() > *out {
                    event_sender.send(Event::EmergencyBraking).await;
                    outgoing.send(Datapoint::new(Datatype::HeartbeatExpired, dt.to_id() as u64, Instant::now().as_ticks())).await;
                }
            }
        }
        if !seen {
            match hb.push((data.datatype, timeout(data.datatype), Instant::now())) {
                Ok(_) => {},
                Err(_) => outgoing.send(Datapoint::new(Datatype::Info, Info::lamp_error_unreachable.to_idx(), Instant::now().as_ticks())).await,
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

fn value_warning(dt: Datatype, v: u64) -> Datapoint {
    Datapoint::new(Datatype::ValueWarning, dt.to_id() as u64, v)
}

fn value_error(dt: Datatype, v: u64) -> Datapoint {
    Datapoint::new(Datatype::ValueError, dt.to_id() as u64, v)
}

fn value_critical(dt: Datatype, v: u64) -> Datapoint {
    Datapoint::new(Datatype::ValueCausedBraking, dt.to_id() as u64, v)
}
