use canzero_config::config::{self, SignalRef};

use crate::cnl::frame::Value;

pub struct SignalDeserializer {
    bit_mask: u64,
    bit_offset: u32,
    bit_size : u8,
    type_info: SignalDeserializerTypeInfo,
}

enum SignalDeserializerTypeInfo {
    DecimalSignalDeserializer { offset: f64, scale: f64 },
    UnsignedSignalDeserializer,
    SignedSignalDeserializer,
}

impl SignalDeserializer {
    pub fn new(signal: &SignalRef) -> Self {
        let bit_offset = signal.byte_offset() as u32; // NOTE stupid naming =^)
        let bit_size = signal.size() as u32;
        Self {
            bit_offset,
            bit_mask: (u64::MAX >> (u64::BITS - bit_size)),
            bit_size : bit_size as u8,
            type_info: match signal.ty() {
                config::SignalType::UnsignedInt { size: _ } => {
                    SignalDeserializerTypeInfo::UnsignedSignalDeserializer
                }
                config::SignalType::SignedInt { size: _ } => {
                    SignalDeserializerTypeInfo::SignedSignalDeserializer
                }
                config::SignalType::Decimal {
                    size: _,
                    offset,
                    scale,
                } => SignalDeserializerTypeInfo::DecimalSignalDeserializer {
                    offset: *offset,
                    scale: *scale,
                },
            },
        }
    }

    pub fn deserialize(&self, data: u64) -> Value {
        let unsigned_bits = data >> (self.bit_offset) & self.bit_mask;
        match &self.type_info {
            SignalDeserializerTypeInfo::DecimalSignalDeserializer { offset, scale } => {
                Value::RealValue(unsigned_bits as f64 * scale + offset)
            }
            SignalDeserializerTypeInfo::UnsignedSignalDeserializer => {
                Value::UnsignedValue(unsigned_bits)
            }
            SignalDeserializerTypeInfo::SignedSignalDeserializer => {
                let neg = unsigned_bits & (1 << (self.bit_size - 1)) != 0;
                if neg {
                    // pad with ones
                    Value::SignedValue(unsafe {
                        std::mem::transmute(
                            u64::MAX << (self.bit_size as u32 - 1) | unsigned_bits,
                        )
                    })
                } else {
                    Value::SignedValue(unsafe { std::mem::transmute(unsigned_bits) })
                }
            }
        }
    }
}
