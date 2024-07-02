// i decided to not throw build errors but compilation errors when a can message
// is mapped to a non-existing event or datatype
#![allow(non_snake_case)]

extern crate regex;
extern crate serde;

use std::fs;
use std::sync::Mutex;
use serde::Deserialize;
use crate::datatypes::get_data_config;
use crate::events::get_events_config;

#[derive(Deserialize)]
struct Config {
    Message: Vec<Message>,
}

#[derive(Deserialize)]
struct Message {
    name: String,
    id: u16,
    datapoint: Option<String>,
    event: Option<String>,
}

pub const CAN_PATH: &str = "../config/can.toml";

pub fn main(id_list: &Mutex<Vec<u16>>) -> String {
    let config_str = fs::read_to_string(CAN_PATH).unwrap();
    let config: Config = toml::from_str(&config_str).unwrap();

    let event_conf = get_events_config();
    let data_conf = get_data_config();
    let mut messages = String::new();
    let mut id_list = id_list.lock().unwrap();

    for msg in config.Message {
        if msg.id & 0b1111_1000_0000_0000 != 0 {
            panic!("IDs need to be u11. Found {} > {}", msg.id, 2^11);
        } else {
            if id_list.contains(&msg.id) {
                panic!("ID {} already taken!! {}:{} : pick a different one.", msg.id, msg.name, msg.id);
            }
            id_list.push(msg.id);
        }
        let mut cur_msg = String::new();
        if msg.datapoint.is_some() {
            cur_msg.push_str(&*format!("\t\t\tdata_sender.send(Datapoint::new(Datatype::{}, data, timestamp)).await;\n", msg.datapoint.unwrap()))
        }
        if msg.event.is_some() {
            cur_msg.push_str(&*format!("\t\t\tevent_sender.send(Event::{}).await;\n", msg.event.unwrap()));
        }
        messages.push_str(&*format!("\t\t{} => {{\n{}\t\t}}\n", msg.id, cur_msg));
    }

    format!("
pub fn parse_can_message(id : u16, data : u64, timestamp : u64, event_sender: EventSender, data_sender: DataSender) {{
    match id {{
{}
    }}
}}
",messages)
}