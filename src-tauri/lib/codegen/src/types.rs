use canzero_config::config::{self, Type};

use crate::errors::Result;
use crate::messages::signal_type_to_c_type;
use crate::options::Options;

pub fn generate_types(
    node_config: &config::NodeRef,
    header: &mut String,
    options: &Options,
) -> Result<()> {
    let mut indent = String::new();
    for _ in 0..options.indent() {
        indent.push(' ');
    }

    for ty in node_config.types() {
        match ty as &config::Type {
            config::Type::Struct {
                name,
                description: _,
                attribs,
                visibility: _,
            } => {
                let mut def = format!("typedef struct {{\n");
                for (attrib_name, attrib_type) in attribs {
                    let ctype = to_c_type_name(attrib_type);
                    def.push_str(&format!("{indent}{ctype} m_{attrib_name};\n"));
                }
                def.push_str(&format!("}} {name};\n"));
                header.push_str(&def);
            }
            config::Type::Enum {
                name,
                description: _,
                size: _,
                entries,
                visibility: _,
            } => {
                let mut def = format!("typedef enum {{\n");
                for (entry_name, entry_value) in entries {
                    def.push_str(&format!("{indent}{name}_{entry_name} = {entry_value},\n"));
                }
                def.push_str(&format!("}} {name};\n"));
                header.push_str(&def);
            }
            config::Type::Array { len: _, ty: _ } => todo!(),
            config::Type::Primitive(_) => {
                panic!("primitives should not be explicitly defined as node types")
            }
        }
    }
    Ok(())
}

pub fn to_c_type_name(ty: &Type) -> &str {
    match ty {
        config::Type::Primitive(signal_type) => signal_type_to_c_type(signal_type),
        config::Type::Struct {
            name,
            description: _,
            attribs: _,
            visibility: _,
        } => name,
        config::Type::Enum {
            name,
            description: _,
            size: _,
            entries: _,
            visibility: _,
        } => name,
        config::Type::Array { len: _, ty: _ } => todo!(),
    }
}
