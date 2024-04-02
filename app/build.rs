#![allow(non_snake_case)]

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
    command: Command,
    datapoints: Datapoints,
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
    ground_fault_detection_can_id_threshold : u16,
    high_voltage_bms_can_id_threshold : u16,
}

#[derive(Debug, Deserialize)]
struct Command {
    Levitate: [u8; 2],
    StopLevitating: [u8; 2],
    Configure: [u8; 2],
    StartRun: [u8; 2],
    EmergencyBrake: [u8; 2],
    Shutdown: [u8; 2],
}

#[derive(Debug, Deserialize)]
struct Datapoints {
    PropulsionTemperature: u8,
    LevitationTemperature: u8,
    BatteryVoltage: u8,
    BatteryCurrent: u8,
    BatteryTemperature: u8,
    BatteryBalance: u8,
    SingleCellVoltage: u8,
    SingleCellTemperature: u8,
    BrakeTemperature: u8,
    PropulsionSpeed: u8,
    BrakePressure: u8,
    HighVoltage: u8,
    HighVoltageInsulation: u8,
    FSMState: u8,
    FSMEvent: u8,
    //BMS INFO

}


pub const NETCONFIG_PATH: &str = "../config/config.toml";

fn main() {
    let out_dir = env::var("OUT_DIR").unwrap();
    let dest_path = Path::new(&out_dir).join("config.rs");

    let ip_file = fs::read_to_string(NETCONFIG_PATH).unwrap();
    let config: Config = toml::from_str(&ip_file).unwrap();

    let mut content = String::new();

    content.push_str(&*configure_ip(&config));
    content.push_str(&*configure_pod(&config));
    content.push_str(&*configure_internal(&config));
    content.push_str(&*configure_commands(&config));
    content.push_str(&*configure_datatype_encoding(&config));

    fs::write(dest_path.clone(), content).expect(&*format!("Couldn't write to {}! Build failed.", dest_path.to_str().unwrap()));
    println!("cargo:rerun-if-changed={}", NETCONFIG_PATH);

    // linking
    println!("cargo:rustc-link-arg-bins=--nmagic");
    println!("cargo:rustc-link-arg-bins=-Tlink.x");
    println!("cargo:rustc-link-arg-bins=-Tdefmt.x");
}

fn configure_datatype_encoding(config: &Config) -> String {
    format!("pub enum Datatype {{\
        PropulsionTemperature,\
        LevitationTemperature,\
        BatteryVoltage,\
        BatteryCurrent,\
        BatteryTemperature,\
        SingleCellVoltage,\
        SingleCellTemperature,\
        BrakeTemperature,\
        PropulsionSpeed,\
        BrakePressure,\
        HighVoltage,\
        HighVoltageInsulation,\
        FSMState,\
        FSMEvent,\
    }}")
    + &*format!("pub fn encode_datatype(datatype: &Datatype) -> u8 {{\
        match datatype {{\
            Datatype::PropulsionTemperature => {},\
            Datatype::LevitationTemperature => {},\
            Datatype::BatteryVoltage => {},\
            Datatype::BatteryCurrent => {},\
            Datatype::BatteryTemperature => {},\
            Datatype::SingleCellVoltage => {},\
            Datatype::SingleCellTemperature => {},\
            Datatype::BrakeTemperature => {},\
            Datatype::PropulsionSpeed => {},\
            Datatype::BrakePressure => {},\
            Datatype::HighVoltage => {},\
            Datatype::HighVoltageInsulation => {},\
            Datatype::FSMState => {},\
            Datatype::FSMEvent => {},\
        }}\
    }}", config.datapoints.PropulsionTemperature, config.datapoints.LevitationTemperature, config.datapoints.BatteryVoltage, config.datapoints.BatteryCurrent, config.datapoints.BatteryTemperature,config.datapoints.SingleCellVoltage,config.datapoints.SingleCellTemperature ,config.datapoints.BrakeTemperature, config.datapoints.PropulsionSpeed, config.datapoints.BrakePressure, config.datapoints.HighVoltage,config.datapoints.HighVoltageInsulation, config.datapoints.FSMState, config.datapoints.FSMEvent)
}

fn configure_commands(config: &Config) -> String {
    format!("pub struct Commands;impl Commands{}\
    pub const LEVITATE: [u8; 2] = [{},{}];\
    pub const STOP_LEVITATING: [u8; 2] = [{},{}];\
    pub const CONFIGURE: [u8; 2] = [{},{}];\
    pub const START_RUN: [u8; 2] = [{},{}];\
    pub const EMERGENCY_BRAKE: [u8; 2] = [{},{}];\
    pub const SHUTDOWN: [u8; 2] = [{},{}];\
    {}\n", "{", config.command.Levitate[0], config.command.Levitate[1], config.command.StopLevitating[0], config.command.StopLevitating[1], config.command.Configure[0], config.command.Configure[1], config.command.StartRun[0], config.command.StartRun[1], config.command.EmergencyBrake[0], config.command.EmergencyBrake[1], config.command.Shutdown[0], config.command.Shutdown[1], "}")
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
// ground_fault_detection_can_id_threshold = 0x40
// high_voltage_bms_can_id_threshold = 0x150
fn configure_internal(config: &Config) -> String {
    format!("pub const EVENT_QUEUE_SIZE: usize = {};", config.pod.internal.event_queue_size)
    + &*format!("pub const DATA_QUEUE_SIZE: usize = {};", config.pod.internal.data_queue_size)
    + &*format!("pub const CAN_QUEUE_SIZE: usize = {};", config.pod.internal.can_queue_size)
    + &*format!("pub const GROUND_FAULT_DETECTION_CAN_ID_THRESHOLD: u16 = {};", config.pod.internal.ground_fault_detection_can_id_threshold)
    + &*format!("pub const HIGH_VOLTAGE_BMS_CAN_ID_THRESHOLD: u16 = {};", config.pod.internal.high_voltage_bms_can_id_threshold)
}
