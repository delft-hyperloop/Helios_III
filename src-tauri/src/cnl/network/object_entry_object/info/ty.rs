use canzero_config::config;
use serde::{ser::SerializeMap, Serialize};

#[derive(Clone, Serialize)]
pub struct ObjectEntryIntType {
    bit_size: u8,
}

#[derive(Clone, Serialize)]
pub struct ObjectEntryUIntType {
    bit_size: u8,
}

#[derive(Clone, Serialize)]
pub struct ObjectEntryRealType {
    bit_size: u8,
    min: f64,
    max: f64,
}

#[derive(Clone, Serialize)]
pub struct ObjectEntryEnumType {
    name: String,
    variants: Vec<String>,
}

#[derive(Clone, Serialize)]
pub struct ObjectEntryStructType {
    name: String,
    attributes: ObjectEntryStructAttributeMap,
}

#[derive(Clone)]
pub struct ObjectEntryStructAttributeMap(Vec<(String, ObjectEntryType)>);

#[derive(Clone)]
pub enum ObjectEntryType {
    Int(ObjectEntryIntType),
    Uint(ObjectEntryUIntType),
    Real(ObjectEntryRealType),
    Enum(ObjectEntryEnumType),
    Struct(ObjectEntryStructType),
}

impl ObjectEntryType {
    pub fn new(ty: &config::Type) -> ObjectEntryType {
        match ty {
            config::Type::Primitive(signal_type) => match signal_type {
                config::SignalType::UnsignedInt { size } => {
                    ObjectEntryType::Uint(ObjectEntryUIntType { bit_size: *size })
                }
                config::SignalType::SignedInt { size } => {
                    ObjectEntryType::Int(ObjectEntryIntType { bit_size: *size })
                }
                config::SignalType::Decimal {
                    size,
                    offset,
                    scale,
                } => {
                    let unsigned_max =
                        u64::MAX >> (u64::BITS - *size as u32);
                    let decimal_range = unsigned_max as f64 * *scale;
                    let min = *offset;
                    let max = decimal_range + min;
                    ObjectEntryType::Real(ObjectEntryRealType {
                        bit_size: *size,
                        min,
                        max,
                    })
                }
            },

            config::Type::Struct {
                name,
                description: _,
                attribs,
                visibility: _,
            } => ObjectEntryType::Struct(ObjectEntryStructType {
                name: name.clone(),
                attributes: ObjectEntryStructAttributeMap(
                    attribs
                        .iter()
                        .map(|(attrib_name, attrib_type)| {
                            (attrib_name.clone(), ObjectEntryType::new(attrib_type))
                        })
                        .collect(),
                ),
            }),
            config::Type::Enum {
                name,
                description : _,
                size : _,
                entries,
                visibility : _,
            } => ObjectEntryType::Enum(ObjectEntryEnumType {
                name: name.clone(),
                variants: entries.iter().map(|(variant, _)| variant.clone()).collect(),
            }),
            config::Type::Array { len : _, ty : _ } => todo!("FUCK YOU"),
        }
    }
}

impl Serialize for ObjectEntryType {
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: serde::Serializer,
    {
        let mut map = serializer.serialize_map(Some(2))?;
        match &self {
            ObjectEntryType::Int(info) => {
                map.serialize_entry("id", "int")?;
                map.serialize_entry("info", info)?;
            }
            ObjectEntryType::Uint(info) => {
                map.serialize_entry("id", "uint")?;
                map.serialize_entry("info", info)?;
            }
            ObjectEntryType::Real(info) => {
                map.serialize_entry("id", "real")?;
                map.serialize_entry("info", info)?;
            }
            ObjectEntryType::Enum(info) => {
                map.serialize_entry("id", "enum")?;
                map.serialize_entry("info", info)?;
            }
            ObjectEntryType::Struct(info) => {
                map.serialize_entry("id", "struct")?;
                map.serialize_entry("info", info)?;
            }
        }
        map.end()
    }
}

impl Serialize for ObjectEntryStructAttributeMap {
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: serde::Serializer {
        let mut map = serializer.serialize_map(Some(self.0.len()))?;
        for (attrib_name, attrib_ty) in &self.0 {
            map.serialize_entry(attrib_name, attrib_ty)?;
        }
        map.end()
    }
}
