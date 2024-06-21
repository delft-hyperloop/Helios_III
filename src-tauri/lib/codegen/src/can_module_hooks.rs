use canzero_config::config::bus::BusRef;

use crate::{
    errors::Result,
    options::Options,
};

pub fn generate_hooks(
    buses: &Vec<BusRef>,
    _source: &mut String,
    header: &mut String,
    options: &Options,
) -> Result<()> {
    let namespace = options.namespace();
    let mut indent = String::new();
    for _ in 0..options.indent() {
        indent.push(' ');
    }
    for bus in buses {
        let bus_name = bus.name();
        let can_setup_name = format!("{namespace}_{bus_name}_setup");
        let can_setup_decl = format!("extern void {can_setup_name}(uint32_t baudrate, {namespace}_can_filter* filters, int filter_count);\n");
        header.push_str(&can_setup_decl);

        let can_send_name = format!("{namespace}_{bus_name}_send");
        let can_send_decl = format!("extern void {can_send_name}({namespace}_frame* frame);\n");
        header.push_str(&can_send_decl);
        let can_recv_name = format!("{namespace}_{bus_name}_recv");
        let can_recv_decl = format!("extern int {can_recv_name}({namespace}_frame* frame);\n");
        header.push_str(&can_recv_decl);
    }

    let can_request_update_name = format!("{namespace}_request_update");
    let can_request_update_decl = format!("extern void {can_request_update_name}(uint32_t time);\n");
    header.push_str(&can_request_update_decl);

    let can_get_time = format!("{namespace}_get_time");
    let can_get_time_decl = format!("extern uint32_t {can_get_time}();\n");
    header.push_str(&can_get_time_decl);


    let enter_cirtical_name = format!("{namespace}_enter_critical");
    let enter_cirtical_decl = format!("extern void {enter_cirtical_name}();\n");
    header.push_str(&enter_cirtical_decl);

    let exit_cirtical_name = format!("{namespace}_exit_critical");
    let exit_cirtical_decl = format!("extern void {exit_cirtical_name}();\n");
    header.push_str(&exit_cirtical_decl);

    Ok(())
}
