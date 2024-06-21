use canzero_config::config::{NodeRef, Type, NetworkRef, self};

use crate::errors::Result;
use crate::options::Options;
use crate::types::to_c_type_name;


const UNSOLICITED_ID: u8 = 0xff;

pub fn generate_senders(
    node_config: &NodeRef,
    network_config: &NetworkRef,
    header: &mut String,
    source: &mut String,
    options: &Options,
) -> Result<()> {

    let namespace = options.namespace();
    let mut indent = String::new();
    for _ in 0..options.indent() {
        indent.push(' ');
    }
    let indent2 = format!("{indent}{indent}");
    let indent3 = format!("{indent}{indent2}");

    let get_resp_msg_name = network_config.get_resp_message().name();
    let frame_type_name = format!("{namespace}_message_{get_resp_msg_name}");
    let get_resp_bus_name = network_config.get_resp_message().bus().name();
    let mut sender_def = String::new();
    let node_name = node_config.name();

    for object_entry in node_config.object_entries() {
        let oe_name = object_entry.name();
        let oe_id = object_entry.id();
        let oe_type_name = to_c_type_name(object_entry.ty());
        let oe_var = format!("__oe_{oe_name}");
        let sender_name = format!("{namespace}_send_{oe_name}");

        let sender_decl = format!("void {sender_name}();\n\n");
        header.push_str(&sender_decl);

        sender_def.push_str(&format!(
"void {sender_name}() {{
{indent}{frame_type_name} msg;
"));

        let size = ty_size(object_entry.ty());
        let post_amble = if size <= 32 {
            fn generate_parse_logic(
                parse_code: &mut String,
                oe_name: &str,
                oe_type: &Type,
                bit_offset: &mut u8,
                base_indent: &str,
                msg_name: &str,
            ) {
                match oe_type {
                    Type::Primitive(signal_type) => {
                        match signal_type {
                            config::SignalType::UnsignedInt { size } => {
                                let parse_uint = if *size <= 8 {
                                    format!(
                                        "{base_indent}{msg_name}.m_data |= ((uint32_t)({oe_name} \
                                            & (0xFF >> (8 - {size})))) << {bit_offset};\n"
                                    )
                                } else if *size <= 16 {
                                    format!(
                                        "{base_indent}{msg_name}.m_data |= ((uint32_t)({oe_name} \
                                            & (0xFFFF >> (16 - {size})))) << {bit_offset};\n")
                                } else if *size <= 32 {
                                    format!(
                                        "{base_indent}{msg_name}.m_data |= ({oe_name} & \
                                            (0xFFFFFFFF >> (32 - {size}))) << {bit_offset};\n")
                                } else if *size <= 64 {
                                    panic!("values larger than 32 should be send in fragmented mode")
                                } else {
                                    panic!("unsigned integer larger than 64 are not supported");
                                };
                                parse_code.push_str(&parse_uint);
                                *bit_offset += size;
                            }
                            config::SignalType::SignedInt { size } => {
                                let parse_int = if *size <= 8 {
                                    format!("{base_indent}{msg_name}.m_data |= ((uint32_t)(((uint8_t){oe_name}) \
                                        & (0xFF >> (8 - {size})))) << {bit_offset};\n")
                                } else if *size <= 16 {
                                    format!("{base_indent}{msg_name}.m_data |= ((uint32_t)(((uint16_t){oe_name}) \
                                        & (0xFFFF >> (16 - {size})))) << {bit_offset};\n")
                                } else if *size <= 32 {
                                    format!("{base_indent}{msg_name}.m_data |= ((uint32_t)(((uint32_t){oe_name}) \
                                        & (0xFFFFFFFF >> (32 - {size})))) << {bit_offset};\n")
                                } else if *size <= 64 {
                                    panic!("values larger than 32 should be send in fragmented mode")
                                } else {
                                    panic!("signed integer larger than 64 are not supported");
                                };
                                parse_code.push_str(&parse_int);
                                *bit_offset += size;
                            }
                            config::SignalType::Decimal {
                                size,
                                offset,
                                scale,
                            } => {
                                let max_u32_value = u32::MAX >> (32u32 - *size as u32);
                                let parse_dec = if *size <= 32 {
                                format!(
                                    "{base_indent}{msg_name}.m_data |= min_u32(({oe_name} \
                                        - ({offset})) / {scale}, 0x{max_u32_value:X}) << {bit_offset};\n"
                                )
                                } else if *size <= 64 {
                                    panic!("values larger than 32 should be send in fragmented mode")
                                } else {
                                    panic!("decimals larger than 64 are not supported");
                                };
                                parse_code.push_str(&parse_dec);
                                *bit_offset += size;
                            }
                        };
                    }
                    Type::Struct {
                        name: _,
                        description: _,
                        attribs,
                        visibility: _,
                    } => {
                        for (attr_name, attr_type) in attribs {
                            let oe_name = oe_name.to_owned() + ".m_" + attr_name;
                            generate_parse_logic(
                                parse_code, &oe_name, attr_type, bit_offset, base_indent, msg_name
                            );
                        }
                    }
                    Type::Enum {
                        name: _,
                        description: _,
                        size,
                        entries: _,
                        visibility: _,
                    } => {
                        let parse_enum = if *size <= 8 {
                            format!(
                                "{base_indent}{msg_name}.m_data |= ((uint32_t)(((uint8_t){oe_name}) \
                                    & (0xFF >> (8 - {size})))) << {bit_offset};\n"
                            )
                        } else if *size <= 16 {
                            format!(
                                "{base_indent}{msg_name}.m_data |= ((uint32_t)((uint16_t){oe_name}) \
                                    & (0xFFFF >> (16 - {size})))) << {bit_offset};\n")
                        } else if *size <= 32 {
                            format!(
                                "{base_indent}{msg_name}.m_data |= (((uint32_t){oe_name}) & \
                                    (0xFFFFFFFF >> (32 - {size}))) << {bit_offset};\n")
                        } else if *size <= 64 {
                            panic!("enums larger than 32 should be send in fragmented mode")
                        } else {
                            panic!("enums larger than 64 are not supported");
                        };
                        parse_code.push_str(&parse_enum);
                        *bit_offset += size;
                    }
                    Type::Array { len: _, ty: _ } => todo!(),
                };
            }
            let mut parse_code = String::new();
            let mut bit_offset = 0;
            let oe_type = object_entry.ty();
            generate_parse_logic(
                &mut parse_code,
                &oe_var,
                oe_type,
                &mut bit_offset,
                &indent,
                "msg",
            );
            sender_def.push_str(&parse_code);
            sender_def.push_str(&format!("{indent}msg.m_header.m_eof = 1;\n"));
            String::new()

        } else {
            let buffer_name = format!("{oe_var}_send_fragmentation_buffer");
            let buffer_def =
                format!("static uint32_t DMAMEM {buffer_name}[{}];\n", size.div_ceil(32));
            source.push_str(&buffer_def);

            fn generate_fragmentation_logic(
                logic: &mut String,
                ty: &Type,
                var_name: &str,
                buffer: &str,
                bit_offset: &mut usize,
                indent2: &str,
                indent3: &str,
            ) {
                match ty {
                    Type::Primitive(signal_type) => {
                        let val = match signal_type {
                            config::SignalType::UnsignedInt { size: _ } => {
                                var_name.to_owned()
                            }
                            config::SignalType::SignedInt { size } => {
                                if *size <= 8 {
                                    format!("((uint8_t){var_name})")
                                } else if *size <= 16 {
                                    format!("((uint16_t){var_name})")
                                } else if *size <= 32 {
                                    format!("((uint32_t){var_name})")
                                } else if *size <= 64 {
                                    format!("((uint64_t){var_name})")
                                } else {
                                    panic!("singed integer larger than 64 are not supported");
                                }
                            }
                            config::SignalType::Decimal {
                                size,
                                offset,
                                scale,
                            } => {
                                println!("size = {size}");
                                if *size <= 8 {
                                    let max_u32_value = u32::MAX >> (32u32 - *size as u32);
                                    format!("min_u32(({var_name} - ((float){offset})) / (float){scale}, 0x{max_u32_value:X}ul)")
                                } else if *size <= 16 {
                                    let max_u32_value = u32::MAX >> (32u32 - *size as u32);
                                    format!("min_u32(({var_name} - ((float){offset})) / (float){scale}, 0x{max_u32_value:X}ul)")
                                } else if *size <= 32 {
                                    let max_u32_value = u32::MAX >> (32u32 - *size as u32);
                                    format!("min_u32(({var_name} - ((float){offset})) / (float){scale}, 0x{max_u32_value:X}ul)")
                                } else if *size <= 64 {
                                    let max_u64_value = u64::MAX >> (64u32 - *size as u32);
                                    format!("min_u64(({var_name} - ((double){offset})) / (double){scale}, 0x{max_u64_value:X}ull)")
                                } else {
                                    panic!("singed integer larger than 64 are not supported");
                                }
                            }
                        };
                        let size = signal_type.size() as usize;
                        let val = if size <= 32 {
                            format!("({val} & (0xFFFFFFFF >> (32 - {size})))")
                        } else if size <= 64 {
                            format!("({val} & (0xFFFFFFFFFFFFFFFF >> (64 - {size})))")
                        } else {
                            panic!(
                                "primitive data types larger than 64 are not supported"
                            )
                        };
                        if size <= 32 {
                            if *bit_offset % 32 == 0 {
                                let word_offset = *bit_offset / 32;
                                logic.push_str(&format!(
                                    "{indent2}{buffer}[{word_offset}] = {val};\n"
                                ));
                            } else if (*bit_offset % 32) + size <= 32 {
                                let word_offset = *bit_offset / 32;
                                let shift = *bit_offset % 32;
                                logic.push_str(&format!(
                                    "{indent2}{buffer}[{word_offset}] |= ({val} << {shift});\n"
                                ));
                            } else {
                                logic.push_str(&format!("{indent2}{{\n"));
                                logic.push_str(&format!("{indent3}uint32_t masked = {val};\n"));

                                let lower_word_offset = *bit_offset / 32;
                                let lower_shift = *bit_offset % 32;
                                logic.push_str(&format!("{indent3}{buffer}[{lower_word_offset}] |= (masked << {lower_shift});\n"));

                                let upper_word_offset = lower_word_offset + 1;
                                let upper_shift = 32 - lower_shift;
                                logic.push_str(&format!("{indent3}{buffer}[{upper_word_offset}] = (masked >> {upper_shift});\n"));

                                logic.push_str(&format!("{indent2}}}\n"));
                            }
                        } else if size <= 64 {
                            logic.push_str(&format!("{indent2}{{\n"));
                            logic.push_str(&format!(
                                "{indent3}uint64_t masked = {val};\n"
                            ));
                            if *bit_offset % 32 == 0 {
                                let lower_word_offset = *bit_offset / 32;
                                let upper_word_offset = lower_word_offset + 1;
                                logic.push_str(&format!("{indent3}{buffer}[{lower_word_offset}] = ((uint32_t*)&masked)[0];\n"));
                                logic.push_str(&format!("{indent3}{buffer}[{upper_word_offset}] = ((uint32_t*)&masked)[1];\n"));
                            } else if (*bit_offset % 32) + size <= 64 {
                                let lower_word_offset = *bit_offset / 32;
                                let lower_shift_left = *bit_offset % 32;
                                logic.push_str(&format!("{indent3}{buffer}[{lower_word_offset}] |= ((uint32_t*)&masked)[0] << {lower_shift_left};\n"));
                                let upper_word_offset = lower_word_offset + 1;
                                let lower_shift_right = 32 - *bit_offset % 32;
                                logic.push_str(&format!("{indent3}{buffer}[{upper_word_offset}] = ((uint32_t*)&masked)[0] >> {lower_shift_right};\n"));
                                let upper_shift_left = lower_shift_left;
                                logic.push_str(&format!("{indent3}{buffer}[{upper_word_offset}] |= ((uint32_t*)&masked)[1] << {upper_shift_left};\n"));
                            } else {
                                let lower_word_offset = *bit_offset / 32;
                                let lower_shift_left = *bit_offset % 32;
                                logic.push_str(&format!("{indent3}{buffer}[{lower_word_offset}] |= ((uint32_t*)&masked)[0] << {lower_shift_left};\n"));
                                let middle_word_offset = lower_word_offset + 1;
                                let lower_shift_right = 32 - *bit_offset % 32;
                                logic.push_str(&format!("{indent3}{buffer}[{middle_word_offset}] = ((uint32_t*)&masked)[0] >> {lower_shift_right};\n"));
                                let upper_shift_left = lower_shift_left;
                                logic.push_str(&format!("{indent3}{buffer}[{middle_word_offset}] |= ((uint32_t*)&masked)[1] << {upper_shift_left};\n"));
                                let upper_word_offset = middle_word_offset + 1;
                                let upper_shift_right =lower_shift_right;
                                logic.push_str(&format!("{indent3}{buffer}[{upper_word_offset}] = ((uint32_t*)&masked)[1] >> {upper_shift_right};\n"));
                            }
                            logic.push_str(&format!("{indent2}}}"));
                        } else {
                            panic!(
                                "primitive data types larger than 64 are not supported"
                            );
                        }
                        *bit_offset += size;
                    }
                    Type::Enum {
                        name: _,
                        description: _,
                        size,
                        entries: _,
                        visibility: _,
                    } => {
                        let size = *size as usize;
                        let val = if size <= 32 {
                            format!("({var_name} & (0xFFFFFFFF >> (32 - {size})))")
                        } else if size <= 64 {
                            format!("({var_name} & (0xFFFFFFFFFFFFFFFF >> (64 - {size})))")
                        } else {
                            panic!(
                                "primitive data types larger than 64 are not supported"
                            )
                        };
                        if size <= 32 {
                            if *bit_offset % 32 == 0 {
                                let word_offset = *bit_offset / 32;
                                logic.push_str(&format!(
                                    "{indent2}{buffer}[{word_offset}] = {val};\n"
                                ));
                            } else if (*bit_offset % 32) + size <= 32 {
                                let word_offset = *bit_offset / 32;
                                let shift = *bit_offset % 32;
                                logic.push_str(&format!(
                                    "{indent2}{buffer}[{word_offset}] |= ({val} << {shift});\n"
                                ));
                            } else {
                                logic.push_str(&format!("{indent2}{{\n"));
                                logic.push_str(&format!("{indent2}uint32_t masked = {val};\n"));

                                let lower_word_offset = *bit_offset / 32;
                                let lower_shift = *bit_offset % 32;
                                logic.push_str(&format!("{indent3}{buffer}[{lower_word_offset}] |= (masked << {lower_shift});\n"));

                                let upper_word_offset = lower_word_offset + 1;
                                let upper_shift = 32 - lower_shift;
                                logic.push_str(&format!("{indent3}{buffer}[{upper_word_offset}] = (masked >> {upper_shift});\n"));

                                logic.push_str(&format!("{indent2}}}\n"));
                            }
                        } else if size <= 64 {
                            logic.push_str(&format!("{indent2}{{\n"));
                            logic.push_str(&format!(
                                "{indent3}uint64_t masked = {val};\n"
                            ));
                            if *bit_offset % 32 == 0 {
                                let lower_word_offset = *bit_offset / 32;
                                let upper_word_offset = lower_word_offset + 1;
                                logic.push_str(&format!("{indent3}{buffer}[{lower_word_offset}] = ((uint32_t*)&masked)[0];\n"));
                                logic.push_str(&format!("{indent3}{buffer}[{upper_word_offset}] = ((uint32_t*)&masked)[1];\n"));
                            } else if (*bit_offset % 32) + size <= 64 {
                                let lower_word_offset = *bit_offset / 32;
                                let lower_shift_left = *bit_offset % 32;
                                logic.push_str(&format!("{indent3}{buffer}[{lower_word_offset}] |= ((uint32_t*)&masked)[0] << {lower_shift_left};\n"));
                                let upper_word_offset = lower_word_offset + 1;
                                let lower_shift_right = 32 - *bit_offset % 32;
                                logic.push_str(&format!("{indent3}{buffer}[{upper_word_offset}] = ((uint32_t*)&masked)[0] >> {lower_shift_right};\n"));
                                let upper_shift_left = lower_shift_left;
                                logic.push_str(&format!("{indent3}{buffer}[{upper_word_offset}] |= ((uint32_t*)&masked)[1] << {upper_shift_left};\n"));
                            } else {
                                let lower_word_offset = *bit_offset / 32;
                                let lower_shift_left = *bit_offset % 32;
                                logic.push_str(&format!("{indent3}{buffer}[{lower_word_offset}] |= ((uint32_t*)&masked)[0] << {lower_shift_left};\n"));
                                let middle_word_offset = lower_word_offset + 1;
                                let lower_shift_right = 32 - *bit_offset % 32;
                                logic.push_str(&format!("{indent3}{buffer}[{middle_word_offset}] = ((uint32_t*)&masked)[0] >> {lower_shift_right};\n"));
                                let upper_shift_left = lower_shift_left;
                                logic.push_str(&format!("{indent3}{buffer}[{middle_word_offset}] |= ((uint32_t*)&masked)[1] << {upper_shift_left};\n"));
                                let upper_word_offset = middle_word_offset + 1;
                                let upper_shift_right =lower_shift_right;
                                logic.push_str(&format!("{indent3}{buffer}[{upper_word_offset}] = ((uint32_t*)&masked)[1] >> {upper_shift_right};\n"));
                            }
                            logic.push_str(&format!("{indent2}}}"));
                        } else {
                            panic!(
                                "primitive data types larger than 64 are not supported"
                            );
                        }
                        *bit_offset += size;
                    }
                    Type::Struct {
                        name: _,
                        description: _,
                        attribs,
                        visibility: _,
                    } => {
                        for (attrib_name, attrib_ty) in attribs {
                            generate_fragmentation_logic(
                                logic,
                                &attrib_ty,
                                &format!("{var_name}.m_{attrib_name}"),
                                buffer,
                                bit_offset,
                                indent2,
                                indent3,
                            );
                        }
                    }
                    Type::Array { len: _, ty: _ } => todo!(),
                }
            }
            let mut fragmentation_logic = String::new();
            generate_fragmentation_logic(
                &mut fragmentation_logic,
                object_entry.ty(),
                &oe_var,
                &buffer_name,
                &mut 0,
                &indent,
                &indent2,
            );

            let buffer_size = size.div_ceil(32);
            let od_index = object_entry.id();
            sender_def += &format!(
"{fragmentation_logic}
{indent}msg.m_data = {buffer_name}[0];
{indent}msg.m_header.m_eof = 0;
"           );
            String::from(format!(
"{indent}schedule_get_resp_fragmentation_job({buffer_name}, {buffer_size}, {od_index}, {UNSOLICITED_ID});

"
            ))
        };
        let send_bus_name = network_config.get_resp_message().bus().name();
        sender_def += &format!(
"{indent}msg.m_header.m_sof = 1;
{indent}msg.m_header.m_toggle = 0;
{indent}msg.m_header.m_od_index = {oe_id};
{indent}msg.m_header.m_client_id = {UNSOLICITED_ID};
{indent}msg.m_header.m_server_id = node_id_{node_name};
{indent}{namespace}_frame sender_frame;
{indent}{namespace}_serialize_{namespace}_message_{get_resp_msg_name}(&msg, &sender_frame);
{indent}{namespace}_{get_resp_bus_name}_send(&sender_frame);
"
        );
        sender_def.push_str(&post_amble);

        sender_def.push_str("}\n");
    }

    source.push_str(&sender_def);
    Ok(())
}



fn ty_size(ty: &Type) -> usize {
    match ty {
        Type::Primitive(signal_type) => signal_type.size() as usize,
        Type::Struct {
            name: _,
            description: _,
            attribs,
            visibility: _,
        } => {
            let mut sum = 0;
            for (_, attrib) in attribs {
                sum += ty_size(attrib as &Type);
            }
            sum
        }
        Type::Enum {
            name: _,
            description: _,
            size,
            entries: _,
            visibility: _,
        } => *size as usize,
        Type::Array { len, ty } => *len * ty_size(ty),
    }
}
