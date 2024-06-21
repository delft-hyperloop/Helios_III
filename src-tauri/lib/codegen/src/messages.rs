use canzero_config::config::{self, MessageRef, SignalType, Type, TypeSignalEncoding};

use crate::errors::Result;
use crate::options::Options;
use crate::types::to_c_type_name;

pub fn generate_messages(
    tx_messages: &Vec<MessageRef>,
    rx_messages: &Vec<MessageRef>,
    header: &mut String,
    source: &mut String,
    options: &Options,
) -> Result<()> {
    let namespace = options.namespace();
    let mut indent = String::new();
    for _ in 0..options.indent() {
        indent.push(' ');
    }

    let mut all_messages = tx_messages.clone();
    for rx_message in rx_messages {
        if all_messages.iter().any(|m| m.name() == rx_message.name()) {
            continue;
        }
        all_messages.push(rx_message.clone());
    }

    // create structs for all messages
    for message in &all_messages {
        let message_type_name = format!("{namespace}_message_{}", message.name());
        // type declartion of the message struct!
        let mut type_def = format!("typedef struct {{\n");
        match message.encoding() {
            Some(encoding) => {
                for attrib in encoding.attributes() {
                    let attrib_type_name = to_c_type_name(attrib.ty());
                    let attrib_name = attrib.name();
                    type_def.push_str(&format!("{indent}{attrib_type_name} m_{attrib_name};\n"));
                }
            }
            None => {
                for signal in message.signals() {
                    let signal_type_name = signal_type_to_c_type(signal.ty());
                    let signal_name = signal.name();
                    type_def.push_str(&format!("{indent}{signal_type_name} m_{signal_name};\n"));
                }
            }
        }
        let id = match message.id() {
            config::MessageId::StandardId(id) => format!("0x{id:X}"),
            config::MessageId::ExtendedId(id) => {
                format!("(0x{id:X} | {}_FRAME_IDE_BIT)", namespace.to_uppercase())
            }
        };

        type_def.push_str(&format!("}} {message_type_name};\n"));
        header.push_str(&type_def);
        header.push_str(&format!(
            "static const uint32_t {message_type_name}_id = {id};\n"
        ));
    }
    // serialize message
    for message in tx_messages {
        let message_type_name = format!("{namespace}_message_{}", message.name());
        let id = match message.id() {
            config::MessageId::StandardId(id) => format!("0x{id:X}"),
            config::MessageId::ExtendedId(id) => {
                format!("(0x{id:X} | {}_FRAME_IDE_BIT)", namespace.to_uppercase())
            }
        };
        let dlc = message.dlc();
        // function to serialize the message struct into a can frame!
        let serialize_func_name = format!("serialize_{message_type_name}");
        let mut serialize_def = format!(
"static void {namespace}_{serialize_func_name}({message_type_name}* msg, {namespace}_frame* frame) {{
{indent}uint8_t* data = frame->data;
{indent}for(uint8_t i = 0; i < 8; ++i){{
{indent}{indent}data[i] = 0;
{indent}}}
{indent}frame->id = {id};
{indent}frame->dlc = {dlc};
");

        match message.encoding() {
            Some(encoding) => {
                fn write_attribute_parse_code(
                    serialized_def: &mut String,
                    attrib: &TypeSignalEncoding,
                    indent: &str,
                    attribute_prefix: &str,
                    attrib_offset: &mut usize,
                ) {
                    match attrib {
                        TypeSignalEncoding::Composite(composite) => {
                            let attrib_name = composite.name();
                            let attrib_prefix = format!("{attribute_prefix}{attrib_name}.m_");
                            for attrib in composite.attributes() {
                                write_attribute_parse_code(
                                    serialized_def,
                                    attrib,
                                    indent,
                                    &attrib_prefix,
                                    attrib_offset,
                                );
                            }
                        }
                        TypeSignalEncoding::Primitive(primitive) => {
                            let attrib_name = primitive.name();
                            match attrib.ty() as &Type {
                                config::Type::Primitive(signal_type) => {
                                    let var = match signal_type {
                                        SignalType::UnsignedInt { size: _ } => {
                                            format!("{attribute_prefix}{attrib_name}")
                                        }
                                        SignalType::SignedInt { size: _ } => {
                                            format!("{attribute_prefix}{attrib_name}")
                                        }

                                        SignalType::Decimal {
                                            size,
                                            offset,
                                            scale,
                                        } => {
                                            if *size <= 32 {
                                                serialized_def.push_str(&format!("{indent}uint32_t {attrib_name}_{attrib_offset} = (({attribute_prefix}{attrib_name} - {offset}) / {scale}) + 0.5f;\n"));
                                                let u32_max = (0xFFFFFFFF as u32)
                                                    >> (32 - *size as u32);

                                                serialized_def.push_str(&format!(
"{indent}if ({attrib_name}_{attrib_offset} > 0x{u32_max:X}) {{
{indent}{indent}{attrib_name}_{attrib_offset} = 0x{u32_max:X};
{indent}}}
"));
                                                format!("{attrib_name}_{attrib_offset}")
                                            } else {
                                                serialized_def.push_str(&format!("{indent}uint64_t {attrib_name}_{attrib_offset} = (({attribute_prefix}{attrib_name} - {offset}) / {scale}) + 0.5;\n"));
                                                let u64_max = (0xFFFFFFFFFFFFFFFF as u64)
                                                    >> (64 - *size as u32);

                                                serialized_def.push_str(&format!(
"{indent}if ({attrib_name}_{attrib_offset} > 0x{u64_max:X}ull) {{
{indent}{indent}{attrib_name}_{attrib_offset} = 0x{u64_max:X}ull;
{indent}}}
"));
                                                format!("{attrib_name}_{attrib_offset}")
                                            }
                                        }
                                    };
                                    let size = signal_type.size();
                                    let val = if size < 8 {
                                        format!("(uint8_t)({var} & (0xFF >> (8 - {size})))")
                                    } else if size == 8 {
                                        format!("{var}")
                                    } else if size < 16 {
                                        format!("(uint16_t)({var} & (0xFFFF >> (16 - {size})))")
                                    } else if size == 16 {
                                        format!("{var}")
                                    } else if size < 32 {
                                        format!("(uint32_t)({var} & (0xFFFFFFFF >> (32 - {size})))")
                                    } else if size == 32 {
                                        format!("{var}")
                                    } else if size < 64 {
                                        format!("(uint64_t)({var} & (0xFFFFFFFFFFFFFFFF >> (64 - {size})))")
                                    } else if size == 64 {
                                        format!("{var}")
                                    } else {
                                        panic!("primitive data types larger than 64 bit are not supported");
                                    };

                                    let word_bit_offset = *attrib_offset % 32;
                                    let write_logic = if word_bit_offset == 0 && size <= 32 {
                                        // word aligned word write
                                        // is asserted to be the first write to the word!
                                        let word_offset = *attrib_offset / 32; // intentional floor
                                        format!(
                                            "{indent}((uint32_t*)data)[{word_offset}] = {val};\n"
                                        )
                                    } else if word_bit_offset == 0 && size > 32 {
                                        // long word aligned long wrd write
                                        // is asserted to be the first bit of the data frame
                                        assert!(*attrib_offset == 0);
                                        format!("{indent}((uint64_t*)data)[0] = {val};\n")
                                    } else if word_bit_offset + size as usize <= 32 {
                                        // unaligned word write (does't cross word boundary)
                                        // is asserted to not be the first write to the word!
                                        let word_offset = *attrib_offset / 32; // intentional floor
                                        format!("{indent}((uint32_t*)data)[{word_offset}] |= {val} << {word_bit_offset};\n")
                                    } else if word_bit_offset + size as usize >= 32 {
                                        // unaligned long word write (crosses word boundary)
                                        // is asserted to not be the first write to the word!
                                        assert!(*attrib_offset <= 32);
                                        format!("{indent}((uint64_t*)data)[0] |= ((uint64_t){val}) << {word_bit_offset} ;\n")
                                    } else {
                                        panic!();
                                    };
                                    serialized_def.push_str(&write_logic);
                                    *attrib_offset += size as usize;
                                }
                                config::Type::Enum {
                                    name: _,
                                    description: _,
                                    size,
                                    entries: _,
                                    visibility: _,
                                } => {
                                    let var = format!("{attribute_prefix}{attrib_name}");
                                    let size = *size;
                                    let val = if size < 8 {
                                        format!("(uint8_t)({var} & (0xFF >> (8 - {size})))")
                                    } else if size == 8 {
                                        format!("(uint8_t){var}")
                                    } else if size < 16 {
                                        format!("(uint16_t)({var} & (0xFFFF >> (16 - {size})))")
                                    } else if size == 16 {
                                        format!("(uint16_t){var}")
                                    } else if size < 32 {
                                        format!("(uint32_t)({var} & (0xFFFFFFFF >> (32 - {size})))")
                                    } else if size == 32 {
                                        format!("(uint32_t){var}")
                                    } else if size < 64 {
                                        format!("(uint64_t)({var} & (0xFFFFFFFFFFFFFFFF >> (64 - {size})))")
                                    } else if size == 64 {
                                        format!("(uint64_t){var}")
                                    } else {
                                        panic!("primitive data types larger than 64 bit are not supported");
                                    };

                                    let word_bit_offset = *attrib_offset % 32;
                                    let write_logic = if word_bit_offset == 0 && size <= 32 {
                                        // word aligned word write
                                        // is asserted to be the first write to the word!
                                        let word_offset = *attrib_offset / 32; // intentional floor
                                        format!(
                                            "{indent}((uint32_t*)data)[{word_offset}] = {val};\n"
                                        )
                                    } else if word_bit_offset == 0 && size > 32 {
                                        // long word aligned long wrd write
                                        // is asserted to be the first bit of the data frame
                                        assert!(*attrib_offset == 0);
                                        format!("{indent}((uint64_t*)data)[0] = {val};\n")
                                    } else if word_bit_offset + size as usize <= 32 {
                                        // unaligned word write (does't cross word boundary)
                                        // is asserted to not be the first write to the word!
                                        let word_offset = *attrib_offset / 32; // intentional floor
                                        format!("{indent}((uint32_t*)data)[{word_offset}] |= {val} << {word_bit_offset};\n")
                                    } else if word_bit_offset + size as usize >= 32 {
                                        // unaligned long word write (crosses word boundary)
                                        // is asserted to not be the first write to the word!
                                        assert!(*attrib_offset <= 32);
                                        format!("{indent}((uint64_t*)data)[0] |= ((uint64_t){val}) << {word_bit_offset} ;\n")
                                    } else {
                                        panic!();
                                    };
                                    serialized_def.push_str(&write_logic);
                                    *attrib_offset += size as usize;
                                }
                                config::Type::Array { len: _, ty: _ } => todo!(),
                                config::Type::Struct {
                                    name: _,
                                    description: _,
                                    attribs: _,
                                    visibility: _,
                                } => panic!("structs are not primitive"),
                            };
                        }
                    }
                }

                let mut attrib_offset: usize = 0;
                for attrib in encoding.attributes() {
                    write_attribute_parse_code(
                        &mut serialize_def,
                        attrib,
                        &indent,
                        "msg->m_",
                        &mut attrib_offset,
                    );
                }
            }
            None => {
                for signal in message.signals() {
                    let attrib_offset: usize = signal.byte_offset();
                    let signal_name = signal.name();
                    let var = match signal.ty() {
                        SignalType::UnsignedInt { size: _ } => {
                            format!("msg->m_{signal_name}")
                        }
                        SignalType::SignedInt { size: _ } => {
                            format!("msg->m_{signal_name}")
                        }
                        SignalType::Decimal {
                            size,
                            offset,
                            scale,
                        } => {
                            if *size <= 32 {
                                format!("(uint32_t)(msg->m_{signal_name} * {scale} + {offset})")
                            } else {
                                format!("(uint64_t)(msg->m_{signal_name} * {scale} + {offset})")
                            }
                        }
                    };
                    let size = signal.size();
                    let val = if size < 8 {
                        format!("(uint8_t)({var} & (0xFF >> (8 - {size})))")
                    } else if size == 8 {
                        format!("{var}")
                    } else if size < 16 {
                        format!("(uint16_t)({var} & (0xFFFF >> (16 - {size})))")
                    } else if size == 16 {
                        format!("{var}")
                    } else if size < 32 {
                        format!("(uint32_t)({var} & (0xFFFFFFFF >> (32 - {size})))")
                    } else if size == 32 {
                        format!("{var}")
                    } else if size < 64 {
                        format!("(uint64_t)({var} & (0xFFFFFFFFFFFFFFFF >> (64 - {size})))")
                    } else if size == 64 {
                        format!("{var}")
                    } else {
                        panic!("primitive data types larger than 64 bit are not supported");
                    };

                    let word_bit_offset = attrib_offset % 32;
                    let write_logic = if word_bit_offset == 0 && size <= 32 {
                        // word aligned word write
                        // is asserted to be the first write to the word!
                        let word_offset = attrib_offset / 32; // intentional floor
                        format!("{indent}((uint32_t*)data)[{word_offset}] = {val};\n")
                    } else if word_bit_offset == 0 && size > 32 {
                        // long word aligned long wrd write
                        // is asserted to be the first bit of the data frame
                        assert!(attrib_offset == 0);
                        format!("{indent}((uint64_t*)data)[0] = {val};\n")
                    } else if word_bit_offset + size as usize <= 32 {
                        // unaligned word write (does't cross word boundary)
                        // is asserted to not be the first write to the word!
                        let word_offset = attrib_offset / 32; // intentional floor
                        format!("{indent}((uint32_t*)data)[{word_offset}] |= {val} << {word_bit_offset};\n")
                    } else if word_bit_offset + size as usize >= 32 {
                        // unaligned long word write (crosses word boundary)
                        // is asserted to not be the first write to the word!
                        assert!(attrib_offset <= 32);
                        format!("{indent}((uint64_t*)data)[0] |= ((uint64_t){val}) << {word_bit_offset} ;\n")
                    } else {
                        panic!();
                    };
                    serialize_def.push_str(&write_logic);
                }
            }
        };

        serialize_def.push_str("}\n");
        source.push_str(&serialize_def);
    }
    // deserialize
    for message in rx_messages {
        let message_type_name = format!("{namespace}_message_{}", message.name());
        // function to serialize the message struct into a can frame!
        let deserialize_func_name = format!("{namespace}_deserialize_{message_type_name}");
        let mut deserialize_def = format!(
"static void {deserialize_func_name}({namespace}_frame* frame, {message_type_name}* msg) {{
{indent}uint8_t* data = frame->data;
"
        );

        match message.encoding() {
            Some(encoding) => {
                fn write_attribute_write_code(
                    deserialized_def: &mut String,
                    attrib: &TypeSignalEncoding,
                    indent: &str,
                    attribute_prefix: &str,
                    attrib_bit_offset: &mut usize,
                ) {
                    match attrib {
                        TypeSignalEncoding::Composite(composite) => {
                            let attrib_name = composite.name();
                            let attrib_prefix = format!("{attribute_prefix}{attrib_name}.m_");
                            for attrib in composite.attributes() {
                                write_attribute_write_code(
                                    deserialized_def,
                                    attrib,
                                    indent,
                                    &attrib_prefix,
                                    attrib_bit_offset,
                                );
                            }
                        }
                        TypeSignalEncoding::Primitive(primitive) => {
                            let attrib_name = primitive.name();
                            let signal = primitive.signal();
                            match attrib.ty() as &Type {
                                config::Type::Primitive(signal_type) => {
                                    let var = format!("{indent}{attribute_prefix}{attrib_name}");
                                    let size = signal_type.size() as usize;

                                    let word_bit_offset = *attrib_bit_offset % 32;
                                    assert_eq!(*attrib_bit_offset, signal.byte_offset());
                                    let val_bits = if word_bit_offset == 0 && size <= 32 {
                                        let word_offset = *attrib_bit_offset / 32;
                                        format!("((uint32_t*)data)[{word_offset}] & (0xFFFFFFFF >> (32 - {size}))")
                                    } else if word_bit_offset == 0 && size > 32 {
                                        format!("((uint64_t*)data)[0] & (0xFFFFFFFFFFFFFFFF >> (64 - {size}))")
                                    } else if word_bit_offset + size <= 32 {
                                        let word_offset = *attrib_bit_offset / 32; //intentional floor
                                        format!("(((uint32_t*)data)[{word_offset}] >> {word_bit_offset}) & (0xFFFFFFFF >> (32 - {size}))")
                                    } else if word_bit_offset + size > 32 {
                                        format!("(((uint64_t*)data)[0] >> {attrib_bit_offset}) & (0xFFFFFFFFFFFFFFFF >> (64 - {size}))")
                                    } else {
                                        panic!();
                                    };

                                    let val = match signal_type {
                                        SignalType::UnsignedInt { size: _ } => {
                                            format!("({val_bits})")
                                        }
                                        SignalType::SignedInt { size } => {
                                            if *size <= 32 {
                                                deserialized_def.push_str(&format!("{indent}uint32_t tmp_{attrib_bit_offset} = {val_bits};\n"));
                                                format!("(tmp_{attrib_bit_offset} & (((uint32_t)0x1) << ({size} - 1)) != 0) ? (tmp_{attrib_bit_offset} | (((uint32_t)0xFFFFFFFFul) << ({size} - 1))) : tmp_{attrib_bit_offset}")
                                            }else {
                                                deserialized_def.push_str(&format!("{indent}uint64_t tmp_{attrib_bit_offset} = {val_bits};\n"));
                                                format!("(tmp_{attrib_bit_offset} & (((uint64_t)0x1) << ({size} - 1)) != 0) ? (tmp_{attrib_bit_offset} | (((uint64_t)0xFFFFFFFFFFFFFFFFull) << ({size} - 1))) : tmp_{attrib_bit_offset}")
                                            }
                                        }
                                        SignalType::Decimal {
                                            size: _,
                                            offset,
                                            scale,
                                        } => {
                                            format!("({val_bits}) * {scale} + {offset}")
                                        }
                                    };

                                    deserialized_def.push_str(&format!("{var} = {val};\n"));
                                    *attrib_bit_offset += size;
                                }
                                config::Type::Struct {
                                    name: _,
                                    description: _,
                                    attribs: _,
                                    visibility: _,
                                } => panic!("structs are not primitive"),
                                config::Type::Enum {
                                    name,
                                    description: _,
                                    size,
                                    entries: _,
                                    visibility: _,
                                } => {
                                    let var = format!("{indent}{attribute_prefix}{attrib_name}");
                                    let size = *size as usize;

                                    let word_bit_offset = *attrib_bit_offset % 32;
                                    assert_eq!(*attrib_bit_offset, signal.byte_offset());
                                    let val_bits = if word_bit_offset == 0 && size <= 32 {
                                        let word_offset = *attrib_bit_offset / 32;
                                        format!("((uint32_t*)data)[{word_offset}] & (0xFFFFFFFF >> (32 - {size}))")
                                    } else if word_bit_offset == 0 && size > 32 {
                                        format!("((uint64_t*)data)[0] & (0xFFFFFFFFFFFFFFFF >> (64 - {size}))")
                                    } else if word_bit_offset + size <= 32 {
                                        let word_offset = *attrib_bit_offset / 32; //intentional floor
                                        format!("(((uint32_t*)data)[{word_offset}] >> {word_bit_offset}) & (0xFFFFFFFF >> (32 - {size}))")
                                    } else if word_bit_offset + size > 32 {
                                        format!("(((uint64_t*)data)[0] >> {attrib_bit_offset}) & (0xFFFFFFFFFFFFFFFF >> (64 - {size}))")
                                    } else {
                                        panic!();
                                    };

                                    let val = format!("({name})({val_bits})");

                                    deserialized_def.push_str(&format!("{var} = {val};\n"));
                                    *attrib_bit_offset += size;
                                }
                                config::Type::Array { len: _, ty: _ } => todo!(),
                            };
                        }
                    }
                }

                let mut attrib_offset: usize = 0;
                for attrib in encoding.attributes() {
                    write_attribute_write_code(
                        &mut deserialize_def,
                        attrib,
                        &indent,
                        "msg->m_",
                        &mut attrib_offset,
                    );
                }
            }
            None => {
                for signal in message.signals() {
                    let signal_name = signal.name();
                    let var = match signal.ty() {
                        SignalType::UnsignedInt { size: _ } => {
                            format!("msg->{signal_name}")
                        }
                        SignalType::SignedInt { size: _ } => {
                            format!("msg->{signal_name}")
                        }
                        SignalType::Decimal {
                            size: _,
                            offset,
                            scale,
                        } => {
                            format!("(msg->{signal_name} * {scale} + {offset})")
                        }
                    };
                    let bit_write_code =
                        bit_access_code(signal.byte_offset(), signal.size() as usize, "data");

                    deserialize_def.push_str(&format!("{indent}{var} = {bit_write_code};"));
                }
            }
        };

        deserialize_def.push_str("}\n");
        source.push_str(&deserialize_def);
    }

    Ok(())
}

pub fn signal_type_to_c_type(signal_type: &SignalType) -> &str {
    match signal_type {
        config::SignalType::UnsignedInt { size } => {
            let bit_count = *size;
            if bit_count <= 8 {
                "uint8_t"
            } else if bit_count <= 16 {
                "uint16_t"
            } else if bit_count <= 32 {
                "uint32_t"
            } else if bit_count <= 64 {
                "uint64_t"
            } else {
                panic!()
            }
        }
        config::SignalType::SignedInt { size } => {
            let bit_count = *size;
            if bit_count <= 8 {
                "int8_t"
            } else if bit_count <= 16 {
                "int16_t"
            } else if bit_count <= 32 {
                "int32_t"
            } else if bit_count <= 64 {
                "int64_t"
            } else {
                panic!()
            }
        }
        config::SignalType::Decimal {
            size,
            offset: _,
            scale: _,
        } => {
            if *size <= 32 {
                "float"
            } else {
                "double"
            }
        }
    }
}

fn bit_access_code(bit_offset: usize, bit_size: usize, buffer_name: &str) -> String {
    if bit_size <= 32 && (bit_size + bit_offset % 32) <= 32 {
        //access half word access!
        let word_bit_offset = bit_offset % 32;
        let word_index = bit_offset / 32;
        let mask = (0xFFFFFFFF as u32) << (32 - bit_size as u32) >> word_bit_offset;
        let shift = word_bit_offset;
        format!("(((int32_t*){buffer_name})[{word_index}] & 0x{mask:X}) >> {shift}")
    } else {
        let mask = ((0xFFFFFFFFFFFFFFFF as u64)
            << ((32 as usize).saturating_sub(bit_size) as u32))
            >> bit_offset;
        let shift = bit_offset;
        format!("(*((int64_t*){buffer_name}) & 0x{mask:X}) >> {shift}")
    }
}
