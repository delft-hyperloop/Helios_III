use std::time::Duration;

use crate::cnl::frame::Value;


#[derive(Debug, Clone)]
pub struct ObjectEntryValue {
    pub value: Value,
    pub timestamp: Duration,
    pub delta_time: Duration,
}

impl ObjectEntryValue {
    pub fn new(value : Value, timestamp : Duration, delta_time : Duration) -> Self {
        Self {
            value,
            timestamp,
            delta_time
        }
    }
}
