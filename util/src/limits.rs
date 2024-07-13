use std::fmt;

use serde::de::Deserializer;
use serde::de::MapAccess;
use serde::de::Visitor;
use serde::de::{self};
use serde::Deserialize;

use crate::datatypes::Limit;
use crate::datatypes::Severities;

impl<'de> Deserialize<'de> for Limit {
    fn deserialize<D>(deserializer: D) -> Result<Self, D::Error>
    where
        D: Deserializer<'de>,
    {
        struct LimitVisitor;

        impl<'de> Visitor<'de> for LimitVisitor {
            type Value = Limit;

            fn expecting(&self, formatter: &mut fmt::Formatter) -> fmt::Result {
                formatter.write_str("an integer, a table with severities, or the string 'no'")
            }

            fn visit_u64<E>(self, value: u64) -> Result<Limit, E>
            where
                E: de::Error,
            {
                Ok(Limit::Single(value))
            }

            fn visit_i64<E>(self, value: i64) -> Result<Limit, E>
            where
                E: de::Error,
            {
                Ok(Limit::Single(value as u64))
            }

            fn visit_map<M>(self, map: M) -> Result<Limit, M::Error>
            where
                M: MapAccess<'de>,
            {
                let severities =
                    Severities::deserialize(de::value::MapAccessDeserializer::new(map))?;
                Ok(Limit::Multiple(severities))
            }

            fn visit_str<E>(self, v: &str) -> Result<Limit, E>
            where
                E: de::Error,
            {
                match v {
                    "no" => Ok(Limit::No),
                    _ => Err(de::Error::unknown_variant(v, &["no"])),
                }
            }
        }

        deserializer.deserialize_any(LimitVisitor)
    }
}
