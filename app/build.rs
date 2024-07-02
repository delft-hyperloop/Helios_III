extern crate regex;
extern crate serde;
use std::env;
use std::fs;
use std::path::Path;
use std::str::FromStr;
use regex::Regex;
use serde::Deserialize;

#[derive(Debug, Deserialize)]
struct Config {
    gs: GS,
}

#[derive(Debug, Deserialize)]
struct GS {
    ip: [u8; 4],
    port: u16,
}

pub const NETCONFIG_PATH: &str = "../config/netconfig.toml";

fn main() {
    let out_dir = env::var("OUT_DIR").unwrap();
    let dest_path = Path::new(&out_dir).join("config.rs");

    configure_ip(&dest_path);

    println!("cargo:rerun-if-changed={}", NETCONFIG_PATH);

    println!("cargo:rustc-link-arg-bins=--nmagic");
    println!("cargo:rustc-link-arg-bins=-Tlink.x");
    println!("cargo:rustc-link-arg-bins=-Tdefmt.x");
}

fn configure_ip(dest_path: &Path) {
    let ip_file = fs::read_to_string(NETCONFIG_PATH).unwrap();
    let ipconfig: Config = toml::from_str(&ip_file).unwrap();
    fs::write(&dest_path, format!("static GS_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});", ipconfig.gs.ip[0], ipconfig.gs.ip[1], ipconfig.gs.ip[2], ipconfig.gs.ip[3], ipconfig.gs.port)).unwrap();
}
