#![allow(non_snake_case)]

extern crate serde;
use goose_utils::commands::generate_commands;
use goose_utils::datatypes::generate_datatypes;
use goose_utils::events::generate_events;
use serde::Deserialize;
use std::env;
use std::fs;
use std::path::Path;

#[derive(Debug, Deserialize)]
struct Config {
    gs: GS,
    pod: POD,
}

#[derive(Debug, Deserialize)]
struct POD {
    net: NetConfig,
}
#[derive(Debug, Deserialize)]
struct NetConfig {
    ip: [u8; 4],
    port: u16,
}

#[derive(Debug, Deserialize)]
struct GS {
    ip: [u8; 4],
    port: u16,
    udp_port: u16,
    buffer_size: usize,
    timeout: u64,
}

pub const CONFIG_PATH: &str = "../../config/config.toml";
pub const DATATYPES_PATH: &str = "../../config/datatypes.toml";
pub const COMMANDS_PATH: &str = "../../config/commands.toml";
pub const EVENTS_PATH: &str = "../../config/events.toml";

fn main() {
    tauri_build::build();
    let out_dir = env::var("OUT_DIR").unwrap();
    let dest_path = Path::new(&out_dir).join("config.rs");
    let gs_file = fs::read_to_string(CONFIG_PATH).unwrap();
    let id_list = Mutex::new(Vec::new());

    let config: Config = toml::from_str(&gs_file).unwrap();

    let mut content = String::new();

    content.push_str(&*configure_ip(&config));
    content.push_str(&*generate_datatypes(id_list, DATATYPES_PATH));
    content.push_str(&*generate_commands(id_list, COMMANDS_PATH));
    content.push_str(&*generate_events(id_list, EVENTS_PATH));

    fs::write(dest_path.clone(), content).expect(&*format!(
        "Couldn't write to {}! Build failed.",
        dest_path.to_str().unwrap()
    ));
    println!("cargo:rerun-if-changed={}", CONFIG_PATH);
    println!("cargo:rerun-if-changed={}", COMMANDS_PATH);
    println!("cargo:rerun-if-changed={}", DATATYPES_PATH);
    println!("cargo:rerun-if-changed={}", EVENTS_PATH);
}

fn configure_ip(config: &Config) -> String {
    format!("pub fn GS_SOCKET() -> std::net::SocketAddr {{ std::net::SocketAddr::new(std::net::IpAddr::from([{},{},{},{}]),{}) }}\n", config.gs.ip[0], config.gs.ip[1], config.gs.ip[2], config.gs.ip[3], config.gs.port)
  + &*format!(
    "pub static POD_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});\n",
    config.pod.net.ip[0],
    config.pod.net.ip[1],
    config.pod.net.ip[2],
    config.pod.net.ip[3],
    config.pod.net.port
  ) + &*format!(
    "pub const NETWORK_BUFFER_SIZE: usize = {};\n",
    config.gs.buffer_size
  ) + &*format!("pub const IP_TIMEOUT: u64 = {};\n", config.gs.timeout)
}
