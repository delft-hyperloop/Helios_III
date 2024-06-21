use std::{hash::Hash, time::Duration};

use super::{ConfigRef, ObjectEntryRef, MessageRef, Visibility};


pub type StreamRef = ConfigRef<Stream>;

#[derive(Debug)]
pub struct Stream {
    name: String,
    description: Option<String>,
    mappings: Vec<Option<ObjectEntryRef>>,
    message: MessageRef,
    visibility: Visibility,
    interval : (Duration, Duration),
}

impl Hash for Stream {
    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        for b in self.name.bytes() {
            state.write_u8(b);
        }
        for m in &self.mappings {
            match m {
                Some(oe) => {
                    state.write_u8(1);
                    oe.hash(state);
                }
                None => {
                    state.write_u8(0);
                }
            }
        }
        self.visibility.hash(state);
        let us1 = self.interval.0.as_micros();
        let us2 = self.interval.1.as_micros();
        state.write_u128(us1);
        state.write_u128(us2);
    }
}

impl Stream {
    pub fn new(name : String, description : Option<String>,
               mappings : Vec<Option<ObjectEntryRef>>,
               message : MessageRef,
               visibility : Visibility,
               interval : (Duration,Duration)) -> Self {
        Self {
            name,
            description,
            mappings,
            message,
            visibility,
            interval,
        }
    }
    pub fn min_interval(&self) -> &Duration {
        &self.interval.0
    }
    pub fn max_interval(&self) -> &Duration {
        &self.interval.1
    }
    pub fn interval(&self) -> &(Duration, Duration) {
        &self.interval
    }
    pub fn visibility(&self) -> &Visibility {
        &self.visibility
    }
    pub fn name(&self) -> &str {
        &self.name
    }
    pub fn description(&self) -> Option<&str> {
        match &self.description {
            Some(some) => Some(&some),
            None => None,
        }
    }
    pub fn mapping(&self) -> &Vec<Option<ObjectEntryRef>> {
        &self.mappings
    }
    pub fn message(&self) -> &MessageRef {
        &self.message
    }
}
