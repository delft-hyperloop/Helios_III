use canzero_config::config::{SignalRef, Type, TypeSignalEncoding};

use crate::cnl::frame::Value;

use super::{signal_deserializer::SignalDeserializer, AttributeDeserializer};

pub enum EncodedDeserializer {
    PrimitiveDeserializer(SignalDeserializer),
    CompositeDeserializer(Vec<AttributeDeserializer>),
    EnumDeserializer(EnumDeserializer),
}

pub struct EnumDeserializer {
    entries: Vec<(String, u64)>,
    signal_deserializer: SignalDeserializer,
}

impl EncodedDeserializer {
    pub fn new(encoding: &TypeSignalEncoding) -> Self {
        match encoding {
            TypeSignalEncoding::Primitive(prim) => {
                match prim.ty() as &Type {
                    Type::Primitive(_) => { // NOTE: config refers to unsigned, signed and decimal
                                            // values as primitives
                        Self::PrimitiveDeserializer(SignalDeserializer::new(prim.signal()))
                    }
                    Type::Enum { name : _, description : _, size : _, entries, visibility : _ } => {
                        Self::EnumDeserializer(EnumDeserializer { entries : entries.clone(), signal_deserializer: SignalDeserializer::new(prim.signal()) })
                    }
                    Type::Struct { name : _, description : _, attribs :_ , visibility : _ } =>  panic!("DETECTED INVALID CONFIG : primitive encoding associated with a structured type!"),
                    Type::Array { len : _, ty : _ } => todo!("FUCK ARRAYS"),
                }
            }
            TypeSignalEncoding::Composite(comp) => Self::CompositeDeserializer(
                comp.attributes()
                    .iter()
                    .map(|attribute_encoding| {
                        AttributeDeserializer::new(
                            attribute_encoding.name(),
                            EncodedDeserializer::new(attribute_encoding),
                        )
                    })
                    .collect(),
            ),
        }
    }

    /// creates a EncodedDeserializer from a signal
    /// because deserialized signals can only be deserialized into
    /// - Value::Unsigned
    /// - Value::Signed,
    /// - Value::Real
    /// no type information is required!
    pub fn new_from_signal(signal: &SignalRef) -> Self {
        Self::PrimitiveDeserializer(SignalDeserializer::new(signal))
    }

    pub fn deserializer(&self, data: u64) -> Value {
        match &self {
            Self::PrimitiveDeserializer(signal_deserializer) => {
                signal_deserializer.deserialize(data)
            }
            Self::CompositeDeserializer(attribute_deserializers) => Value::StructValue(
                attribute_deserializers
                    .iter()
                    .map(|attribute_deserializer| attribute_deserializer.deserialize(data))
                    .collect(),
            ),
            Self::EnumDeserializer(EnumDeserializer {
                entries,
                signal_deserializer,
            }) => {
                let Value::UnsignedValue(unsigned_value) = signal_deserializer.deserialize(data)
                else {
                    panic!(
                        "DETECTED INVALID CONFIG: enums associated with a non unsigned signal type"
                    );
                };
                // NOTE map unsigned value to enum value (string)
                // if not a valid unsigned value set enum value to UNDEFINED
                // UNKNOWN is capitalized to avoid confusion with js frontend.
                Value::EnumValue(
                    entries
                        .iter()
                        .find(|(_, value)| value == &unsigned_value)
                        .unwrap_or(&("UNDEFINED".to_owned(), 0))
                        .0
                        .clone(),
                )
            }
        }
    }
}
