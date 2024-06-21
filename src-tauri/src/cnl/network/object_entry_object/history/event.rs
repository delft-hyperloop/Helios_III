use serde::{Serialize, ser::SerializeMap, ser::SerializeSeq};

use crate::cnl::network::object_entry_object::{database::value::ObjectEntryValue, latest::event::ObjectEntryEvent};


#[derive(Clone)]
pub struct ObjectEntryHistoryEvent<'a> {
    new_values: &'a [ObjectEntryValue],
    deprecated_count: usize,
}

impl<'a> ObjectEntryHistoryEvent<'a> {
    pub fn new(new_values : &'a [ObjectEntryValue], deprecated_count : usize) -> Self {
        Self {
            new_values,
            deprecated_count,
        }
    }
}

impl<'a> Serialize for ObjectEntryHistoryEvent<'a> {
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: serde::Serializer {
        let mut map = serializer.serialize_map(None)?;


        struct Tmp<'a>(&'a [ObjectEntryValue]);
        impl<'a> Serialize for Tmp<'a> {
            fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
            where
                S: serde::Serializer {
                let mut seq = serializer.serialize_seq(Some(self.0.len()))?;
                for v in self.0 {
                    seq.serialize_element(&ObjectEntryEvent::new(v))?;
                }
                seq.end()
            }
        }
        
        map.serialize_entry("deprecated_count", &self.deprecated_count)?;
        map.serialize_entry("new_values", &Tmp(self.new_values))?;

        map.end()
    }
}
