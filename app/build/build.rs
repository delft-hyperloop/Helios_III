#![allow(non_snake_case)]

extern crate serde;

use serde::Deserialize;
use std::env;
use std::fs;
use std::path::Path;
use std::sync::Mutex;
use goose_utils;

/*
   BUILD CONFIGURATION
   POD MAIN APPLICATION

*/

#[derive(Debug, Deserialize)]
struct Config {
    gs: GS,
    pod: POD,
}

#[derive(Debug, Deserialize)]
struct GS {
    ip: [u8; 4],
    port: u16,
    udp_port: u16,
    buffer_size: usize,
    timeout: u64,
}

#[derive(Debug, Deserialize)]
struct POD {
    net: NetConfig,
    internal: InternalConfig,
    bms: BMS,
}

#[derive(Debug, Deserialize)]
struct BMS {
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

fn main() {
    let out_dir = env::var("OUT_DIR").unwrap();
    let id_list = Mutex::new(Vec::new());
    let dest_path = Path::new(&out_dir).join("config.rs");

    let ip_file = fs::read_to_string(CONFIG_PATH).unwrap();
    let config: Config = toml::from_str(&ip_file).unwrap();

    let mut content = String::new();

    content.push_str(&*configure_ip(&config));
    content.push_str(&*configure_pod(&config));
    content.push_str(&*configure_internal(&config));
    content.push_str(&*goose_utils::commands::generate_commands(&id_list, COMMANDS_PATH));
    content.push_str(&*goose_utils::datatypes::generate_datatypes(&id_list, DATATYPES_PATH, false));
    content.push_str(&*goose_utils::events::generate_events(&id_list, EVENTS_PATH));
    // content.push_str(&*can::main(&id_list));

    fs::write(dest_path.clone(), content).expect(&*format!(
        "Couldn't write to {}! Build failed.",
        dest_path.to_str().unwrap()
    ));
    println!("cargo:rerun-if-changed={}", CONFIG_PATH);

    // linking
    println!("cargo:rustc-link-arg-bins=--nmagic");
    println!("cargo:rustc-link-arg-bins=-Tlink.x");
    println!("cargo:rustc-link-arg-bins=-Tdefmt.x");
}

fn configure_ip(config: &Config) -> String {
    format!(
        "pub static GS_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});\n",
        config.gs.ip[0], config.gs.ip[1], config.gs.ip[2], config.gs.ip[3], config.gs.port
    ) + &*format!(
        "pub static GS_UPD_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});\n",
        config.gs.ip[0], config.gs.ip[1], config.gs.ip[2], config.gs.ip[3], config.gs.udp_port
    ) + &*format!(
        "pub const NETWORK_BUFFER_SIZE: usize = {};\n",
        config.gs.buffer_size
    ) + &*format!("pub const IP_TIMEOUT: u64 = {};\n", config.gs.timeout)
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
    ) + &*format!(
        "pub const KEEP_ALIVE: u64 = {};\n",
        config.pod.net.keep_alive
    )
}

fn configure_internal(config: &Config) -> String {
    format!(
        "pub const EVENT_QUEUE_SIZE: usize = {};\n",
        config.pod.internal.event_queue_size
    ) + &*format!(
        "pub const DATA_QUEUE_SIZE: usize = {};\n",
        config.pod.internal.data_queue_size
    ) + &*format!(
        "pub const CAN_QUEUE_SIZE: usize = {};\n",
        config.pod.internal.can_queue_size
    ) + &*format!(
        "pub const LV_IDS: [u16;{}] = [{}];\n",
        config.pod.bms.lv_ids.len(),
        config
            .pod
            .bms
            .lv_ids
            .iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(", ")
    ) + &*format!(
        "pub const HV_IDS: [u16;{}] = [{}];\n",
        config.pod.bms.hv_ids.len(),
        config
            .pod
            .bms
            .hv_ids
            .iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(", ")
    ) + &*format!(
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
    ) + &*format!(
        "pub const BATTERY_GFD_IDS: [u16;{}] = [{},{},{}];\n",
        config.pod.bms.lv_ids.len() + config.pod.bms.hv_ids.len() + config.pod.bms.gfd_ids.len(),
        config
            .pod
            .bms
            .lv_ids
            .iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(", "),
        config
            .pod
            .bms
            .hv_ids
            .iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(", "),
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
