#![allow(non_snake_case)]

mod commands;
mod datatypes;
mod events;

extern crate regex;
extern crate serde;
use std::env;
use std::fs;
use std::path::Path;
use serde::Deserialize;

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
    net : NetConfig,
    internal: InternalConfig,
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

fn main() {
    let out_dir = env::var("OUT_DIR").unwrap();
    let dest_path = Path::new(&out_dir).join("config.rs");

    let ip_file = fs::read_to_string(CONFIG_PATH).unwrap();
    let config: Config = toml::from_str(&ip_file).unwrap();

    let mut content = String::new();

    content.push_str(&*configure_ip(&config));
    content.push_str(&*configure_pod(&config));
    content.push_str(&*configure_internal(&config));
    content.push_str(&*commands::main());
    content.push_str(&*datatypes::main());
    content.push_str(&*events::main());

    fs::write(dest_path.clone(), content).expect(&*format!("Couldn't write to {}! Build failed.", dest_path.to_str().unwrap()));
    println!("cargo:rerun-if-changed={}", CONFIG_PATH);

    // linking
    println!("cargo:rustc-link-arg-bins=--nmagic");
    println!("cargo:rustc-link-arg-bins=-Tlink.x");
    println!("cargo:rustc-link-arg-bins=-Tdefmt.x");
}


fn configure_ip(config: &Config) -> String {
    format!("pub static GS_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});", config.gs.ip[0], config.gs.ip[1], config.gs.ip[2], config.gs.ip[3], config.gs.port)
        + &*format!("pub static GS_UPD_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});", config.gs.ip[0], config.gs.ip[1], config.gs.ip[2], config.gs.ip[3], config.gs.udp_port)
        + &*format!("pub const NETWORK_BUFFER_SIZE: usize = {};", config.gs.buffer_size)
        + &*format!("pub const IP_TIMEOUT: u64 = {};", config.gs.timeout)
}

fn configure_pod(config: &Config) -> String {
    format!("pub static POD_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});", config.pod.net.ip[0], config.pod.net.ip[1], config.pod.net.ip[2], config.pod.net.ip[3], config.pod.net.port)
        + &*format!("pub static POD_UDP_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});", config.pod.net.ip[0], config.pod.net.ip[1], config.pod.net.ip[2], config.pod.net.ip[3], config.pod.net.udp_port)
        + &*format!("pub static POD_MAC_ADDRESS: [u8;6] = [{},{},{},{},{},{}];", config.pod.net.mac_addr[0], config.pod.net.mac_addr[1], config.pod.net.mac_addr[2], config.pod.net.mac_addr[3], config.pod.net.mac_addr[4], config.pod.net.mac_addr[5])
        + &*format!("pub const KEEP_ALIVE: u64 = {};", config.pod.net.keep_alive)
}

fn configure_internal(config: &Config) -> String {
    format!("pub const EVENT_QUEUE_SIZE: usize = {};", config.pod.internal.event_queue_size)
    + &*format!("pub const DATA_QUEUE_SIZE: usize = {};", config.pod.internal.data_queue_size)
    + &*format!("pub const CAN_QUEUE_SIZE: usize = {};", config.pod.internal.can_queue_size)
}