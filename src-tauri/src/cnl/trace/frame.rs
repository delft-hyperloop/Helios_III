use canzero_config::config::MessageId;
use serde::{ser::SerializeMap, Serialize};

use crate::cnl::frame::{Attribute, Frame, Value};

use canzero_common::CanFrame;

#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub enum CanErrorType {
    BitError,
    BitStuffing,
    FormError,
    AckError,
    CrcError,
}

impl CanErrorType {
    pub fn name(&self) -> &'static str {
        match &self {
            CanErrorType::BitError => "Bit Error",
            CanErrorType::BitStuffing => "Bit Stuffing Error",
            CanErrorType::FormError => "Form Error",
            CanErrorType::AckError => "ACK Error",
            CanErrorType::CrcError => "CRC Error",
        }
    }
    pub fn description(&self) -> &'static str {
        match &self {
                CanErrorType::BitError => "Node transmited a dominant/recessive bit, but read back the opposite logic level.",
                CanErrorType::BitStuffing => "Node detected a sequence of 6 bits of the same logic level between SOF and CRC.",
                CanErrorType::FormError => "Node detected a bit of an invalid logic level in the SOF/EOF field or ACK/CRC delimiter.",
                CanErrorType::AckError => "Node transmits a CAN message, but the ACK slot is not made dominant by receiver(s).",
                CanErrorType::CrcError => "Node calculated a CAN message CRC that differs from the transmitted CRC field value.",
            }
    }
}

#[derive(Clone)]
pub enum TraceFrame {
    Undefined(CanFrame),
    Error(CanErrorType),
    Frame(Frame),
}

impl TraceFrame {
    pub fn id(&self) -> u32 {
        match &self {
            TraceFrame::Undefined(can_frame) => can_frame.key(),
            TraceFrame::Error(err) => match err {
                CanErrorType::BitError => 0x20000001,
                CanErrorType::BitStuffing => 0x20000002,
                CanErrorType::FormError => 0x20000004,
                CanErrorType::AckError => 0x20000008,
                CanErrorType::CrcError => 0x20000016,
            },
            TraceFrame::Frame(frame) => match frame.id() {
                MessageId::StandardId(id) => *id,
                MessageId::ExtendedId(id) => *id,
            },
        }
    }
    pub fn ide(&self) -> bool {
        match &self {
            TraceFrame::Undefined(can_frame) => can_frame.get_ide_flag(),
            TraceFrame::Error(_) => false,
            TraceFrame::Frame(frame) => match frame.id() {
                MessageId::StandardId(_) => false,
                MessageId::ExtendedId(_) => true,
            },
        }
    }
    pub fn dlc(&self) -> u8 {
        match &self {
            TraceFrame::Undefined(can_frame) => can_frame.get_dlc(),
            TraceFrame::Error(_) => 0,
            TraceFrame::Frame(frame) => frame.dlc(),
        }
    }
    pub fn name(&self) -> &str {
        match &self {
            TraceFrame::Undefined(can_frame) => {
                if can_frame.get_rtr_flag() {
                    "Data-Frame"
                } else {
                    "Remote-Frame"
                }
            }
            TraceFrame::Error(err) => err.name(),
            TraceFrame::Frame(frame) => frame.name(),
        }
    }

    pub fn key(&self) -> TraceFrameKey {
        match &self {
            TraceFrame::Undefined(can_frame) => TraceFrameKey::Undefined(can_frame.key()),
            TraceFrame::Error(err) => TraceFrameKey::Error(err.clone()),
            TraceFrame::Frame(frame) => TraceFrameKey::Frame(frame.id().clone()),
        }
    }

    pub fn key_u32(&self) -> u32 {
        match &self {
            TraceFrame::Undefined(can_frame) => can_frame.key(),
            TraceFrame::Error(err) => match err {
                CanErrorType::BitError => 0x20000001,
                CanErrorType::BitStuffing => 0x20000002,
                CanErrorType::FormError => 0x20000004,
                CanErrorType::AckError => 0x20000008,
                CanErrorType::CrcError => 0x20000016,
            },
            TraceFrame::Frame(frame) => match frame.id() {
                MessageId::StandardId(id) => *id,
                MessageId::ExtendedId(id) => *id | 0x80000000,
            },
        }
    }
}

impl Serialize for TraceFrame {
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: serde::Serializer,
    {
        let mut map = serializer.serialize_map(None)?;
        map.serialize_entry("name", self.name())?;
        map.serialize_entry("dlc", &self.dlc())?;
        map.serialize_entry(
            "id",
            &if self.ide() {
                format!("0x{:X}x", self.id())
            } else {
                format!("0x{:X}", self.id())
            },
        )?;
        match &self {
            TraceFrame::Undefined(can_frame) => {
                map.serialize_entry("ty", "undefined")?;
                map.serialize_entry("detail", &can_frame.get_data_u64())?;
            }
            TraceFrame::Error(err) => {
                map.serialize_entry("ty", "error")?;
                map.serialize_entry("detail", err.description())?;
            }
            TraceFrame::Frame(frame) => {
                map.serialize_entry("ty", "normal")?;
                let mut flat_attributes = vec![];
                fn build_flat_attributes(
                    attributes: &mut Vec<Attribute>,
                    current: &Attribute,
                    prefix: &str,
                ) {
                    match current.value() {
                        Value::UnsignedValue(_)
                        | Value::SignedValue(_)
                        | Value::RealValue(_)
                        | Value::EnumValue(_) => attributes.push(Attribute::new(
                            &format!("{prefix}{}", current.name()),
                            current.value().clone(),
                        )),
                        Value::StructValue(attribs) => {
                            for attrib in attribs {
                                build_flat_attributes(
                                    attributes,
                                    attrib,
                                    &format!("{}.", current.name()),
                                );
                            }
                        }
                    }
                }
                for attrib in frame.attributes() {
                    build_flat_attributes(&mut flat_attributes, attrib, "");
                }
                map.serialize_entry("detail", &flat_attributes)?;
            }
        }
        map.end()
    }
}

#[derive(PartialEq, Eq, Hash)]
pub enum TraceFrameKey {
    Undefined(u32),
    Error(CanErrorType),
    Frame(MessageId),
}
