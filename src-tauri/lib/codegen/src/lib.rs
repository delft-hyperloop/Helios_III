use canzero_config::config;
use can_module_hooks::generate_hooks;
use command_hooks::generate_command_hooks;
use errors::{Error, Result};
use header_guard::{generate_header_guard_top, generate_header_guard_bottom};
use includes::generate_includes;
use options::Options;
use pil::generate_pil;
use rx_handlers::generate_rx_handlers;
use scheduler::generate_scheduler;
use senders::generate_senders;
use setters::generate_setters;
use setup::generate_setup;
use types::generate_types;
use update::generate_update;

use crate::{
    messages::generate_messages, object_entries::generate_object_entries, poll::generate_poll,
};

mod includes;
mod can_module_hooks;
mod command_hooks;
pub mod errors;
mod messages;
mod object_entries;
pub mod options;
mod pil;
mod poll;
mod rx_handlers;
mod setup;
mod types;
mod update;
mod header_guard;
mod scheduler;
mod setters;
pub mod senders;

pub fn generate(
    node_name: &str,
    network_config: config::NetworkRef,
    options: Options,
) -> Result<()> {
    let Some(node_config) = network_config
        .nodes()
        .iter()
        .find(|n| n.name() == node_name)
    else {
        return Err(Error::InvalidNodeName);
    };

    // TODO setup paths relativ to the workspace directory!

    let mut src = String::new();
    let mut header = String::new();

    generate_header_guard_top(&mut header)?;
    generate_includes(&mut src, &mut header, &options)?;
    generate_types(node_config, &mut header, &options)?;

    header += &format!("static const node_id CANZERO_NODE_ID = node_id_{};\n", node_name);

    generate_pil(&mut src, &mut header, &options)?;
    generate_hooks(network_config.buses(), &mut src, &mut header, &options)?;
    generate_command_hooks(node_config.commands(), &mut src, &mut header, &options)?;

    // generate_extern_guard_top(&mut header)?;
    generate_object_entries(
        node_config.object_entries(),
        &mut header,
        &mut src,
        &options,
    )?;
    generate_messages(
        node_config.tx_messages(),
        node_config.rx_messages(),
        &mut header,
        &mut src,
        &options,
    )?;
    // generate_rx_queue(&mut header, &mut src, &options)?;
    generate_scheduler(&network_config, node_config, &mut src, &mut header, &options)?;
    generate_rx_handlers(
        &network_config,
        node_config,
        &mut src,
        &mut header,
        &options,
    )?;
    generate_poll(
        node_config,
        network_config.buses(),
        &mut header,
        &mut src,
        &options,
    )?;
    generate_update(&mut src, &mut header, &options)?;
    generate_setup(node_config, &network_config, &mut src, &mut header, &options)?;
    
    generate_setters(node_config, &mut header, &mut src, &options)?;

    generate_senders(node_config, &network_config, &mut header, &mut src, &options)?;

    // generate_extern_guard_bottom(&mut header)?;
    generate_header_guard_bottom(&mut header)?;

    std::fs::write(options.source_file_path(), &src).expect(&format!(
        "failed to write to {}",
        options.source_file_path()
    ));
    std::fs::write(options.header_file_path(), &header).expect(&format!(
        "failed to write to {}",
        options.header_file_path()
    ));

    // src.include_file_buffer(&header);
    //
    // header.write(Some("CANZERO_H".to_owned())).unwrap();
    // src.write(None).unwrap();
    // println!("HEADER:");
    // println!("{header:?}");
    // println!("SOURCE:");
    // println!("{src:?}");

    Ok(())
}
