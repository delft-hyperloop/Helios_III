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
    // command: Command,
    // datapoints: Datapoints,
}

#[derive(Debug, Deserialize)]
struct GS {
    ip: [u8; 4],
    port: u16,
    buffer_size: usize,
    timeout: u64,
}


// #[derive(Debug, Deserialize)]
// struct Command {
//     Levitate: [u8; 2],
//     StopLevitating: [u8; 2],
//     Configure: [u8; 2],
//     StartRun: [u8; 2],
//     EmergencyBrake: [u8; 2],
//     Shutdown: [u8; 2],
// }

// #[derive(Debug, Deserialize)]
// struct Datapoints {
//     PropulsionTemperature: u8,
//     LevitationTemperature: u8,
//     BatteryVoltage: u8,
//     BatteryCurrent: u8,
//     BatteryTemperature: u8,
//     BrakeTemperature: u8,
//     PropulsionSpeed: u8,
//     BrakePressure: u8,
//     HighVoltageInsulation: u8,
//     FSMState: u8,
//     FSMEvent: u8,
// }


pub const CONFIG_PATH: &str = "../../config/config.toml";


fn main() {
    let out_dir = env::var("OUT_DIR").unwrap();
    let dest_path = Path::new(&out_dir).join("config.rs");

    let ip_file = fs::read_to_string(CONFIG_PATH).unwrap();
    let config: Config = toml::from_str(&ip_file).unwrap();

    let mut content = String::new();

    content.push_str(&*configure_ip(&config));
    // content.push_str(&*configure_commands(&config));


    fs::write(dest_path.clone(), content).expect(&*format!("Couldn't write to {}! Build failed.", dest_path.to_str().unwrap()));
    println!("cargo:rerun-if-changed={}", CONFIG_PATH);

}


// fn configure_commands(config: &Config) -> String {
//     format!("pub struct Commands;impl Commands{}\
//     pub const LEVITATE: [u8; 2] = [{},{}];\
//     pub const STOP_LEVITATING: [u8; 2] = [{},{}];\
//     pub const CONFIGURE: [u8; 2] = [{},{}];\
//     pub const START_RUN: [u8; 2] = [{},{}];\
//     pub const EMERGENCY_BRAKE: [u8; 2] = [{},{}];\
//     pub const SHUTDOWN: [u8; 2] = [{},{}];\
//     {}\n", "{", config.command.Levitate[0], config.command.Levitate[1], config.command.StopLevitating[0], config.command.StopLevitating[1], config.command.Configure[0], config.command.Configure[1], config.command.StartRun[0], config.command.StartRun[1], config.command.EmergencyBrake[0], config.command.EmergencyBrake[1], config.command.Shutdown[0], config.command.Shutdown[1], "}")
// }


fn configure_ip(ipconfig: &Config) -> String {
    format!("pub fn GS_SOCKET() -> std::net::SocketAddr {} std::net::SocketAddr::new(std::net::IpAddr::from([{},{},{},{}]),{}) {}\n", "{", ipconfig.gs.ip[0], ipconfig.gs.ip[1], ipconfig.gs.ip[2], ipconfig.gs.ip[3], ipconfig.gs.port, "}")
    + &*format!("const IP_BUFFER_SIZE: usize = {};\n", ipconfig.gs.buffer_size)
    + &*format!("const IP_TIMEOUT: u64 = {};\n", ipconfig.gs.timeout)
}
