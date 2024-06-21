use canzero_config::config::MessageRef;

use self::encoding_deserializer::EncodedDeserializer;

use super::frame::{Attribute, Frame, FrameValue};

mod encoding_deserializer;
mod signal_deserializer;
pub mod type_deserializer;

pub struct FrameDeserializer {
    message_config: MessageRef,
    value_deserializer: FrameValueDeserializer,
}

impl FrameDeserializer {
    pub fn new(message_config: &MessageRef) -> Self {
        Self {
            message_config: message_config.clone(),
            value_deserializer: FrameValueDeserializer::new(message_config),
        }
    }
    pub fn deserialize(&self, data: u64) -> Frame {
        Frame::new(
            self.message_config.clone(),
            data,
            self.value_deserializer.deserialize(data),
        )
    }
}

pub struct FrameValueDeserializer {
    attribute_deserializer: Vec<AttributeDeserializer>,
}

struct AttributeDeserializer {
    attribute_name: String,
    encoded_deserializer: EncodedDeserializer,
}

impl AttributeDeserializer {
    pub fn new(name: &str, encoded_deserializer: EncodedDeserializer) -> Self {
        Self {
            attribute_name: name.to_owned(),
            encoded_deserializer,
        }
    }
    pub fn deserialize(&self, data: u64) -> Attribute {
        Attribute::new(
            &self.attribute_name,
            self.encoded_deserializer.deserializer(data),
        )
    }
}

impl FrameValueDeserializer {
    pub fn new(message_config: &MessageRef) -> FrameValueDeserializer {
        match message_config.encoding() {
            Some(message_encoding) => {
                // NOTE create encoded deserializer based on encoding
                Self {
                    attribute_deserializer: message_encoding
                        .attributes()
                        .iter()
                        .map(|type_encoding| {
                            AttributeDeserializer::new(
                                type_encoding.name(),
                                EncodedDeserializer::new(type_encoding),
                            )
                        })
                        .collect(),
                }
            }
            None => Self {
                attribute_deserializer: message_config
                    .signals()
                    .iter()
                    .map(|signal| {
                        AttributeDeserializer::new(
                            signal.name(),
                            EncodedDeserializer::new_from_signal(signal),
                        )
                    })
                    .collect(),
            },
        }
    }

    pub fn deserialize(&self, data: u64) -> FrameValue {
        FrameValue::new(
            self.attribute_deserializer
                .iter()
                .map(|attrib_deserializer| attrib_deserializer.deserialize(data))
                .collect(),
        )
    }
}
