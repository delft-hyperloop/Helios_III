#![allow(non_snake_case)]

extern crate serde;

use std::env;
use std::fs;
use std::path::Path;
use anyhow::Result;
use goose_utils::check_ids;
use goose_utils::ip::configure_gs_ip;
use serde::Deserialize;

/*
   BUILD CONFIGURATION
   POD MAIN APPLICATION

*/

#[derive(Debug, Deserialize)]
struct Config {
    gs: GS,
    pod: Pod,
}

#[derive(Debug, Deserialize)]
struct GS {
    ip: [u8; 4],
    force: bool,
    port: u16,
    // udp_port: u16,
    buffer_size: usize,
    timeout: u64,
    heartbeat: u64,
}

#[derive(Debug, Deserialize)]
struct Pod {
    net: NetConfig,
    internal: InternalConfig,
    bms: Bms,
}

#[derive(Debug, Deserialize)]
struct Bms {
    lv_ids: Vec<u16>,
    hv_ids: Vec<u16>,
    gfd_ids: Vec<u16>,
}

#[derive(Debug, Deserialize)]
struct NetConfig {
    ip: [u8; 4],
    port: u16,
    udp_port: u16,
    mac_addr: [u8; 6],
    keep_alive: u64,
}

#[derive(Debug, Deserialize)]
struct InternalConfig {
    event_queue_size: usize,
    data_queue_size: usize,
    can_queue_size: usize,
}

pub const CONFIG_PATH: &str = "../config/config.toml";
pub const DATATYPES_PATH: &str = "../config/datatypes.toml";
pub const COMMANDS_PATH: &str = "../config/commands.toml";
pub const EVENTS_PATH: &str = "../config/events.toml";

fn main() -> Result<()> {
    // if cfg!(debug_assertions) {
    //     env::set_var("DEFMT_LOG", "trace");
    // } else {
    //     env::set_var("DEFMT_LOG", "off");
    // }

    let out_dir = env::var("OUT_DIR")?;
    let dest_path = Path::new(&out_dir).join("config.rs");

    let ip_file = fs::read_to_string(CONFIG_PATH)?;
    let config: Config = toml::from_str(&ip_file)?;

    let mut content = String::from("//@generated\n");

    let _ = check_ids(DATATYPES_PATH, COMMANDS_PATH, EVENTS_PATH);

    content.push_str(&configure_ip(&config));
    content.push_str(&configure_gs_ip(config.gs.ip, config.gs.port, config.gs.force)?);
    content.push_str(&configure_pod(&config));
    content.push_str(&configure_internal(&config));
    content.push_str(&goose_utils::commands::generate_commands(COMMANDS_PATH, true)?);
    content.push_str(&goose_utils::datatypes::generate_datatypes(DATATYPES_PATH, false)?);
    content.push_str(&goose_utils::events::generate_events(EVENTS_PATH, true)?);
    content.push_str(&goose_utils::info::generate_info(CONFIG_PATH, false)?);
    // content.push_str(&*can::main(&id_list));

    fs::write(dest_path.clone(), content).unwrap_or_else(|e| {
        panic!("Couldn't write to {}! Build failed with error: {}", dest_path.to_str().unwrap(), e)
    });
    println!("cargo:rerun-if-changed={}", CONFIG_PATH);
    println!("cargo:rerun-if-changed={}", EVENTS_PATH);
    println!("cargo:rerun-if-changed={}", COMMANDS_PATH);
    println!("cargo:rerun-if-changed={}", DATATYPES_PATH);

    // linking
    println!("cargo:rustc-link-arg-bins=--nmagic");
    println!("cargo:rustc-link-arg-bins=-Tlink.x");
    println!("cargo:rustc-link-arg-bins=-Tdefmt.x");

    Ok(())
}

fn configure_ip(config: &Config) -> String {
    format!("pub const NETWORK_BUFFER_SIZE: usize = {};\n", config.gs.buffer_size)
        + &*format!("pub const IP_TIMEOUT: u64 = {};\n", config.gs.timeout)
}

fn configure_pod(config: &Config) -> String {
    format!(
        "pub static POD_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});\n",
        config.pod.net.ip[0],
        config.pod.net.ip[1],
        config.pod.net.ip[2],
        config.pod.net.ip[3],
        config.pod.net.port
    ) + &*format!(
        "pub static POD_UDP_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});\n",
        config.pod.net.ip[0],
        config.pod.net.ip[1],
        config.pod.net.ip[2],
        config.pod.net.ip[3],
        config.pod.net.udp_port
    ) + &*format!(
        "pub static POD_MAC_ADDRESS: [u8;6] = [{},{},{},{},{},{}];\n",
        config.pod.net.mac_addr[0],
        config.pod.net.mac_addr[1],
        config.pod.net.mac_addr[2],
        config.pod.net.mac_addr[3],
        config.pod.net.mac_addr[4],
        config.pod.net.mac_addr[5]
    ) + &*format!("pub const KEEP_ALIVE: u64 = {};\n", config.pod.net.keep_alive)
        + &*format!("pub const HEARTBEAT: u64 = {};\n", config.gs.heartbeat)
}

fn configure_internal(config: &Config) -> String {
    format!("pub const EVENT_QUEUE_SIZE: usize = {};\n", config.pod.internal.event_queue_size)
        + &*format!("pub const DATA_QUEUE_SIZE: usize = {};\n", config.pod.internal.data_queue_size)
        + &*format!("pub const CAN_QUEUE_SIZE: usize = {};\n", config.pod.internal.can_queue_size)
        + &*format!(
            "pub const LV_IDS: [u16;{}] = [{}];\n",
            config.pod.bms.lv_ids.len(),
            config.pod.bms.lv_ids.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(", ")
        )
        + &*format!(
            "pub const HV_IDS: [u16;{}] = [{}];\n",
            config.pod.bms.hv_ids.len(),
            config.pod.bms.hv_ids.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(", ")
        )
        + &*format!(
            "pub const GFD_IDS: [u16;{}] = [{}];\n",
            config.pod.bms.gfd_ids.len(),
            config
                .pod
                .bms
                .gfd_ids
                .iter()
                .map(|x| x.to_string())
                .collect::<Vec<String>>()
                .join(", ")
        )
        + &*format!(
            "pub const BATTERY_GFD_IDS: [u16;{}] = [{},{},{}];\n",
            config.pod.bms.lv_ids.len()
                + config.pod.bms.hv_ids.len()
                + config.pod.bms.gfd_ids.len(),
            config.pod.bms.lv_ids.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(", "),
            config.pod.bms.hv_ids.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(", "),
            config
                .pod
                .bms
                .gfd_ids
                .iter()
                .map(|x| x.to_string())
                .collect::<Vec<String>>()
                .join(", ")
        )
}
