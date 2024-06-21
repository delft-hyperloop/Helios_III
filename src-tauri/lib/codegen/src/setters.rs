use canzero_config::config::stream::StreamRef;
use canzero_config::config::{NodeRef, Type};

use crate::errors::Result;
use crate::options::Options;
use crate::types::to_c_type_name;

pub fn generate_setters(
    node_config: &NodeRef,
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

    for object_entry in node_config.object_entries() {
        let oe_name = object_entry.name();
        let type_name = to_c_type_name(object_entry.ty());
        let oe_var = format!("__oe_{oe_name}");
        let setter_name = format!("{namespace}_set_{oe_name}");

        // find all tx-streams this object entry is a part of
        let tx_streams: Vec<&StreamRef> = node_config
            .tx_streams()
            .iter()
            .filter(|stream| {
                stream.mapping().iter().any(|mapping| match mapping {
                    Some(oe) => oe.id() == object_entry.id(),
                    None => false,
                } && stream.min_interval() != stream.max_interval())
            })
            .collect();

        if tx_streams.is_empty() {
            let mut setter_def = format!("static inline void {setter_name}({type_name} value){{\n");
            setter_def.push_str(&format!("{indent}extern {type_name} {oe_var};\n"));
            setter_def.push_str(&format!("{indent}{oe_var} = value;\n"));
            setter_def.push_str("}\n\n");
            header.push_str(&setter_def);
        }else {
            let setter_decl = format!("void {setter_name}({type_name} value);\n\n");
            header.push_str(&setter_decl);


            let mut setter_def = format!("void {setter_name}({type_name} value) {{\n");
            
            fn gen_condition(left : &str, right : &str, ty: &Type) -> String{
                match ty {
                    Type::Enum { name : _, description : _, size : _, entries : _, visibility : _ } |
                    Type::Primitive(_) => format!("{left} != {right}"),
                    Type::Struct { name : _, description : _, attribs, visibility : _ } => {
                        attribs.iter().map(|(attrib_name, attrib_ty)| {
                            gen_condition(&format!("{left}.{attrib_name}"), &format!("{right}.{attrib_name}"), attrib_ty)
                        }).fold("0".to_owned(), |acc, x| format!("{acc} || {x}"))
                    },
                    Type::Array { len : _, ty : _ } => panic!(),
                }
            }

            let condition = gen_condition(&oe_var, "value", object_entry.ty());

            setter_def.push_str(&format!(
"{indent}extern {type_name} {oe_var};
{indent}if ({condition}) {{
{indent2}{oe_var} = value;
"));

            for stream in tx_streams {
                println!("{:?}{:?}", stream.min_interval(), stream.max_interval());
                let stream_name = stream.name();
                let min_interval_ms = stream.min_interval().as_millis();
                let job_var = format!("{stream_name}_interval_job");
                setter_def.push_str(&format!(
"{indent2}if ({job_var}.climax > {job_var}.job.stream_job.last_schedule + {min_interval_ms}) {{
{indent3}{job_var}.climax = {job_var}.job.stream_job.last_schedule + {min_interval_ms};
{indent3}scheduler_promote_job(&{job_var});
{indent2}}}
"));
            }

            setter_def.push_str(&format!("{indent}}}\n"));


            setter_def.push_str("}\n");
            source.push_str(&setter_def);
            
        }
    }

    Ok(())
}
