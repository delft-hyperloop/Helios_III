use canzero_config::config;
use canzero_config::config::bus::BusRef;

use crate::options::Options;

use crate::errors::Result;

pub fn generate_poll(
    node_config: &config::NodeRef,
    buses: &Vec<BusRef>,
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
    let indent3 = format!("{indent2}{indent}");
    let indent4 = format!("{indent2}{indent2}");

    for bus in buses {
        let bus_id = bus.id();
        let bus_name = bus.name();
        let poll_func_name = format!("{namespace}_can{bus_id}_poll");
        let poll_func_decl = format!("void {poll_func_name}();\n");
        header.push_str(&poll_func_decl);

        let mut poll_func_def = format!("void {poll_func_name}() {{\n");
        poll_func_def.push_str(&format!("{indent}{namespace}_frame frame;\n"));
        poll_func_def.push_str(&format!(
            "{indent}while ({namespace}_{bus_name}_recv(&frame)) {{\n"
        ));
        poll_func_def.push_str(&format!(
            "{indent2}switch (frame.id) {{\n"
        ));
        for message in node_config.rx_messages() {
            if message.bus().id() != bus_id {
                continue;
            }
            let message_name = message.name();
            // first bit stands for ide bit
            let id = match message.id() {
                config::MessageId::StandardId(id) => format!("0x{id:X}"),
                config::MessageId::ExtendedId(id) => format!("(0x{id:X} | {}_FRAME_IDE_BIT)", namespace.to_uppercase()),
            };
            poll_func_def.push_str(&format!("{indent3}case {id}:
{indent4}{namespace}_handle_{message_name}(&frame);
{indent4}break;
"
            ));
        }
        poll_func_def.push_str(&format!("{indent2}}}\n"));
        poll_func_def.push_str(&format!("{indent}}}\n"));

        poll_func_def.push_str("}\n");
        source.push_str(&poll_func_def);
    }

    Ok(())
}
