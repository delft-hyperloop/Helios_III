use crate::{
    errors::Result,
    options::Options,
};

pub fn generate_update(
    source: &mut String,
    header: &mut String,
    options: &Options,
) -> Result<()> {
    let namespace = options.namespace();
    let mut indent = String::new();
    for _ in 0..options.indent() {
        indent.push(' ');
    }

    let can_update_continue_name = format!("{namespace}_update_continue");

    let can_update_continue_decl =
        format!("uint32_t {can_update_continue_name}(uint32_t delta_time);\n");
    header.push_str(&can_update_continue_decl);

    let can_update_continue_def = format!(
        "uint32_t {can_update_continue_name}(uint32_t time){{
{indent}schedule_jobs(time);
{indent}return scheduler_next_job_timeout();
}}\n");
    source.push_str(&can_update_continue_def);

    Ok(())
}
