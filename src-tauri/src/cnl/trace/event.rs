use std::{
    ops::Deref,
    time::{Duration, Instant},
};

use serde::{ser::SerializeMap, Serialize};

use super::frame::TraceFrame;

#[derive(Clone)]
pub struct TraceEvent {
    frame: TraceFrame,
    bus: String,
    key: u64,
    delta_time: Duration, // duration since last frame
    timestamp: Duration,  // duration since start of run [sor] (sor is determined by adapter)
    arrive: Instant,      // time of arrival at trace object
}

impl TraceEvent {
    pub fn new_relative(
        bus_name: &str,
        bus_id: u32,
        frame: TraceFrame,
        prev: Option<Duration>,
        timestamp: Duration,
    ) -> Self {
        let delta_time = match prev {
            Some(prev) => timestamp.saturating_sub(prev),
            None => timestamp,
        };
        Self {
            delta_time,
            bus: bus_name.to_owned(),
            key: (bus_id as u64) << 32 | (frame.key_u32() as u64),
            frame,
            timestamp,
            arrive: Instant::now(),
        }
    }
    pub fn bus(&self) -> &str {
        &self.bus
    }
    pub fn delta_time(&self) -> &Duration {
        &self.delta_time
    }
    pub fn timestamp(&self) -> &Duration {
        &self.timestamp
    }
}

impl Serialize for TraceEvent {
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: serde::Serializer,
    {
        let mut map = serializer.serialize_map(Some(3))?;
        map.serialize_entry("frame", &self.frame)?;
        map.serialize_entry("deltaTime", &format!("{}ms", self.delta_time.as_millis()))?;
        map.serialize_entry(
            "timeSinceLast",
            &Instant::now().duration_since(self.arrive).as_millis(),
        )?;
        map.serialize_entry("bus", &self.bus)?;
        map.serialize_entry("key", &self.key)?;
        map.serialize_entry(
            "absoluteTime",
            &format!("{:.1}s", self.timestamp.as_millis() as f32 / 1e3f32),
        )?;
        map.end()
    }
}

impl Deref for TraceEvent {
    type Target = TraceFrame;

    fn deref(&self) -> &Self::Target {
        &self.frame
    }
}
