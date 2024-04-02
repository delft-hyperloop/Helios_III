#![allow(non_snake_case)]

extern crate serde;
use std::env;
use std::fs;
use std::path::Path;
use serde::{Deserialize};

/*
    BUILD CONFIGURATION
    GROUND STATION

 */

#[derive(Debug, Deserialize)]
struct Config {
    gs: GS,
}

#[derive(Debug, Deserialize)]
struct GS {
    ip: [u8; 4],
    port: u16,
    buffer_size: usize,
    timeout: u64,
}


pub const NETCONFIG_PATH: &str = "../config/config.toml";


fn main() {
    let out_dir = env::var("OUT_DIR").unwrap();
    let dest_path = Path::new(&out_dir).join("config.rs");

    configure_ip(&dest_path);

    println!("cargo:rerun-if-changed={}", NETCONFIG_PATH);

}

fn configure_ip(dest_path: &Path) {
    let ip_file = fs::read_to_string(NETCONFIG_PATH).unwrap();

    // make a new string builder to concatenate all the file contents, so we only have to write to file once
    let mut config = String::new();

    let ipconfig: Config = toml::from_str(&ip_file).unwrap();
    config.push_str(&format!("pub fn GS_SOCKET() -> std::net::SocketAddr {} std::net::SocketAddr::new(std::net::IpAddr::from([{},{},{},{}]),{}) {}\n", "{", ipconfig.gs.ip[0], ipconfig.gs.ip[1], ipconfig.gs.ip[2], ipconfig.gs.ip[3], ipconfig.gs.port, "}"));
    config.push_str(&format!("const IP_BUFFER_SIZE: usize = {};\n", ipconfig.gs.buffer_size));
    config.push_str(&format!("const IP_TIMEOUT: u64 = {};\n", ipconfig.gs.timeout));
    println!("\n\n\n\n\n\n\nconfig.rs will have {}\n\n\n\n\n\n\n", config);
    fs::write(&dest_path, config).unwrap();
}
