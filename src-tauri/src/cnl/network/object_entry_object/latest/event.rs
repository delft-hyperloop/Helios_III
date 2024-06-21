use std::ops::Deref;

use serde::{Serialize, ser::SerializeMap};

use crate::cnl::network::object_entry_object::database::value::ObjectEntryValue;


#[derive(Clone, Debug)]
pub struct ObjectEntryEvent<'a>(&'a ObjectEntryValue);


impl<'a> ObjectEntryEvent<'a> {
    pub fn new(value : &'a ObjectEntryValue) -> Self {
        Self(value)
    }
}

impl<'a> Serialize for ObjectEntryEvent<'a> {
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: serde::Serializer,
    {
        let mut ser_map = serializer.serialize_map(Some(3))?;
        ser_map.serialize_entry("value", &self.0.value)?;
        ser_map.serialize_entry(
            "timestamp",
            &(self.0.timestamp.as_millis() % u64::MAX as u128),
        )?;
        ser_map.serialize_entry(
            "delta_time",
            &(self.0.delta_time.as_micros() % u64::MAX as u128),
        )?;

        ser_map.end()
    }

}


#[derive(Clone, Debug)]
pub struct OwnedObjectEntryEvent(ObjectEntryValue);

impl OwnedObjectEntryEvent {
    pub fn new(value : ObjectEntryValue) -> Self {
        Self(value)
    }
}

impl Deref for OwnedObjectEntryEvent {
    type Target = ObjectEntryValue;

    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

impl Serialize for OwnedObjectEntryEvent {
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: serde::Serializer {
        ObjectEntryEvent::new(&self.0).serialize(serializer)
    }
}

