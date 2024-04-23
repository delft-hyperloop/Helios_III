#![allow(non_snake_case)]

extern crate regex;
extern crate serde;

use std::fs;
use std::sync::Mutex;
use serde::Deserialize;

#[derive(Debug, Deserialize)]
pub struct Config {
    Command: Vec<Command>,
}

#[derive(Debug, Deserialize)]
pub struct Command {
    name: String,
    id: u16,
}


pub const COMMANDS_PATH: &str = "../config/commands.toml";

pub fn main(id_list: &Mutex<Vec<u16>>) -> String {
    let config_str = fs::read_to_string(COMMANDS_PATH).unwrap();
    let config: Config = toml::from_str(&config_str).unwrap();
    // println!("{:?}", config);

    let mut enum_definitions = String::new();
    let mut match_to_id = String::from("\t\tmatch *self {\n");
    let mut match_from_id = String::from("\t\tmatch id {\n");
    let mut id_list = id_list.lock().unwrap();
    for command in config.Command {
        if command.id & 0b1111_1000_0000_0000 != 0 {
            panic!("IDs need to be u11. Found {} > {}", command.id, 2^11);
        } else {
            if id_list.contains(&command.id) {
                panic!("ID {} already taken!! {}:{} : pick a different one.", command.id, command.name, command.id);
            }
            id_list.push(command.id);
        }
        enum_definitions.push_str(&format!("\t{}(u64),\n", command.name));
        match_to_id.push_str(&format!("\t\t\tCommand::{}(_) => {},\n", command.name, command.id));
        match_from_id.push_str(&format!("\t\t\t{} => Command::{}(0u64),\n", command.id, command.name));
    }

    format!("\n
pub enum Command {{
{}
}}
impl Command {{
    pub fn to_id(&self)->u16 {{
{}
        }}
    }}
    pub fn from_id(id:u16) -> Self {{
{}
            _ => Command::DefaultCommand(0)
        }}
    }}
}}", enum_definitions, match_to_id, match_from_id)
}