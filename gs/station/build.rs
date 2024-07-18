#![allow(non_snake_case)]

extern crate serde;
use std::env;
use std::fmt::Write;
use std::fs;
use std::path::Path;
use std::path::PathBuf;

use anyhow::Result;
use goose_utils::check_config;
use goose_utils::commands::generate_commands;
use goose_utils::datatypes::generate_datatypes;
use goose_utils::events::generate_events;
use goose_utils::ip::configure_gs_ip;
use serde::Deserialize;

#[derive(Debug, Deserialize)]
struct Config {
    gs: GS,
    pod: Pod,
}

#[derive(Debug, Deserialize)]
struct Pod {
    net: NetConfig,
    comm: CommConfig,
}
#[derive(Debug, Deserialize)]
struct NetConfig {
    ip: [u8; 4],
    port: u16,
}

#[derive(Debug, Deserialize)]
struct CommConfig {
    levi_requested_data: Vec<String>,
}

#[derive(Debug, Deserialize)]
struct GS {
    ip: [u8; 4],
    force: bool,
    port: u16,
    buffer_size: usize,
    timeout: u64,
    heartbeat: u64,
    status_channel: String,
    warning_channel: String,
    info_channel: String,
    error_channel: String,
    shortcut_channel: String,
    levi_exec_path: PathBuf,
}

pub const CONFIG_PATH: &str = "../../config/config.toml";
pub const DATATYPES_PATH: &str = "../../config/datatypes.toml";
pub const COMMANDS_PATH: &str = "../../config/commands.toml";
pub const EVENTS_PATH: &str = "../../config/events.toml";

fn main() -> Result<()> {
    tauri_build::build();
    let out_dir = env::var("OUT_DIR")?;
    let dest_path = Path::new(&out_dir).join("config.rs");
    let gs_file = fs::read_to_string(CONFIG_PATH)?;

    let config: Config = toml::from_str(&gs_file)?;

    let mut content = String::from("//@generated\n");

    content.push_str(&check_config(DATATYPES_PATH, COMMANDS_PATH, EVENTS_PATH, CONFIG_PATH)?);

    content.push_str(&configure_gs(&config));
    content.push_str(&configure_gs_ip(config.gs.ip, config.gs.port, config.gs.force)?);
    let dt = generate_datatypes(DATATYPES_PATH, true)?;
    content.push_str(&dt);
    content.push_str(&generate_commands(COMMANDS_PATH, false)?);
    content.push_str(&generate_events(EVENTS_PATH, false)?);
    content.push_str(&configure_channels(&config));
    content.push_str(&goose_utils::info::generate_info(CONFIG_PATH, true)?);
    content.push_str(&levi_req_data(&config, dt)?);

    fs::write(dest_path.clone(), content).unwrap_or_else(|_| {
        panic!("Couldn't write to {}! Build failed.", dest_path.to_str().unwrap());
    });

    println!("cargo:rerun-if-changed={}", CONFIG_PATH);
    println!("cargo:rerun-if-changed={}", COMMANDS_PATH);
    println!("cargo:rerun-if-changed={}", DATATYPES_PATH);
    println!("cargo:rerun-if-changed={}", EVENTS_PATH);

    Ok(())
}

fn levi_req_data(config: &Config, dt: String) -> Result<String> {
    for data in config.pod.comm.levi_requested_data.iter() {
        if !dt.contains(data) {
            return Err(anyhow::anyhow!(
                "Data type {:?} not found in datatypes.toml
            Check that the (case-sensitive) spelling is correct, and that the datatype exists.",
                data
            ));
        }
    }
    Ok(format!(
        "\npub const LEVI_REQUESTED_DATA: [Datatype; {}] = [{}];\n",
        config.pod.comm.levi_requested_data.len(),
        config.pod.comm.levi_requested_data.iter().fold(String::new(), |mut acc, x| {
            let _ = write!(acc, "Datatype::{}, ", x);
            acc
        })
    ))
}

fn configure_gs(config: &Config) -> String {
    // format!("pub fn gs_socket() -> std::net::SocketAddr {{ std::net::SocketAddr::new(std::net::IpAddr::from([{},{},{},{}]),{}) }}\n", config.gs.ip[0], config.gs.ip[1], config.gs.ip[2], config.gs.ip[3], config.gs.port)
    format!(
        "pub static POD_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});\n",
        config.pod.net.ip[0],
        config.pod.net.ip[1],
        config.pod.net.ip[2],
        config.pod.net.ip[3],
        config.pod.net.port
    ) + &*format!("pub const NETWORK_BUFFER_SIZE: usize = {};\n", config.gs.buffer_size)
        + &format!("pub const IP_TIMEOUT: u64 = {};\n", config.gs.timeout)
        + &format!("pub const HEARTBEAT: u64 = {};\n", config.gs.heartbeat)
        + &format!(
            "pub const LEVI_EXEC_PATH: &str = \"{}\";\n",
            config.gs.levi_exec_path.to_str().unwrap()
        )
}

fn configure_channels(config: &Config) -> String {
    format!("\npub const STATUS_CHANNEL: &str = \"{}\";\n", config.gs.status_channel)
        + &*format!("pub const WARNING_CHANNEL: &str = \"{}\";\n", config.gs.warning_channel)
        + &*format!("pub const INFO_CHANNEL: &str = \"{}\";\n", config.gs.info_channel)
        + &*format!("pub const ERROR_CHANNEL: &str = \"{}\";\n", config.gs.error_channel)
        + &*format!("pub const SHORTCUT_CHANNEL: &str = \"{}\";\n", config.gs.shortcut_channel)
}
