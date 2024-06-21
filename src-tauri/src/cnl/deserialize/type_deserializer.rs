use std::io::Read;

use bitvec::slice::BitSlice;
use canzero_config::config::{SignalType, Type};

use crate::cnl::frame::{Attribute, Value};

pub struct TypeDeserializer {
    bit_size: usize,
    type_info: TypeDeserilaizeInfo,
}

enum TypeDeserilaizeInfo {
    PrimitiveInfo(SignalType),
    StructInfo { attributes: Vec<StructAttribute> },
    EnumInfo { entries: Vec<(String, u64)> },
}

struct StructAttribute {
    name: String,
    type_deserializer: TypeDeserializer,
    attribute_offset: usize,
}

impl TypeDeserializer {
    pub fn new(ty: &Type) -> Self {
        Self {
            bit_size: ty.size() as usize,
            type_info: match ty {
                Type::Primitive(signal_type) => {
                    TypeDeserilaizeInfo::PrimitiveInfo(signal_type.clone())
                }
                Type::Struct {
                    name : _,
                    description : _,
                    attribs,
                    visibility : _,
                } => {
                    let mut attribs_deserializer = vec![];
                    let mut bit_offset = 0usize;
                    for (attrib_name, attrib_type) in attribs {
                        attribs_deserializer.push(StructAttribute {
                            name: attrib_name.clone(),
                            type_deserializer: TypeDeserializer::new(attrib_type),
                            attribute_offset: bit_offset,
                        });
                        bit_offset += attrib_type.size() as usize;
                    }
                    TypeDeserilaizeInfo::StructInfo {
                        attributes: attribs_deserializer,
                    }
                }
                Type::Enum {
                    name: _,
                    description: _,
                    size: _,
                    entries,
                    visibility: _,
                } => TypeDeserilaizeInfo::EnumInfo {
                    entries: entries.clone(),
                },
                Type::Array { len : _, ty : _ } => todo!("FUCK YOU ARRAYS"),
            },
        }
    }


    pub fn deserialize(&self, bitslice: &BitSlice<u32>) -> Value {
        match &self.type_info {
            TypeDeserilaizeInfo::PrimitiveInfo(ty) => {
                // NOTE get unsigned value from bitslice.
                let mut bitvec = bitslice[0..self.bit_size].to_bitvec();
                let byte_padding = 8 * ((bitvec.len() + 7) / 8) - bitvec.len();
                for _ in 0..byte_padding {
                    bitvec.push(false);
                }
                let mut u8_vector = vec![];
                bitvec.read_to_end(&mut u8_vector).expect("failed to read from bitvector");
                // append / remove most significant bits!
                u8_vector.resize(8usize, 0u8);
                // NOTE cursed bullshit! C is so easy!
                let unsigned_value = u64::from_le_bytes(u8_vector.try_into().unwrap());
                match ty {
                    SignalType::UnsignedInt { size: _ } => Value::UnsignedValue(unsigned_value),
                    SignalType::SignedInt { size } => {
                        let neg = unsigned_value & (1 << (*size - 1)) != 0;
                        if neg {
                            // pad with ones
                            Value::SignedValue(unsafe {
                                std::mem::transmute(
                                    (u64::MAX << (*size as u32 - 1)) | unsigned_value,
                                )
                            })
                        } else {
                            Value::SignedValue(unsafe {std::mem::transmute(unsigned_value)})
                        }
                    }
                    SignalType::Decimal {
                        size: _,
                        offset,
                        scale,
                    } => Value::RealValue(unsigned_value as f64 * (*scale) + (*offset)),
                }
            }
            TypeDeserilaizeInfo::EnumInfo { entries } => {

                // NOTE get unsigned value from bitslice.
                let mut bitvec = bitslice[0..self.bit_size].to_bitvec();
                // NOTE pad bits for alignment
                let byte_padding = 8 * ((bitvec.len() + 7) / 8) - bitvec.len();
                for _ in 0..byte_padding {
                    bitvec.push(false);
                }
                let mut u8_vector = vec![];
                bitvec.read_to_end(&mut u8_vector).expect("failed to read from bitvector");
                // align for convertion to u64
                u8_vector.resize(8usize, 0u8);
                // NOTE cursed bullshit! C is so easy!
                let unsigned_value = u64::from_le_bytes(u8_vector.try_into().unwrap());
                println!("enum unsigned_value = {unsigned_value}");
                Value::EnumValue(
                    entries
                        .iter()
                        .find(|(_, v)| v == &unsigned_value)
                        .unwrap_or(&("UNDEFINED".to_owned(), 0))
                        .0
                        .clone(),
                )
            }
            TypeDeserilaizeInfo::StructInfo { attributes } => Value::StructValue(
                attributes
                    .iter()
                    .map(|attrib_deserializer| {
                        Attribute::new(
                            &attrib_deserializer.name,
                            attrib_deserializer
                                .type_deserializer
                                .deserialize(
                                    &bitslice[attrib_deserializer.attribute_offset..],
                                ),
                        )
                    })
                    .collect(),
            ),
        }
    }
}
