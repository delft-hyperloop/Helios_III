#![allow(non_snake_case)]

extern crate regex;
extern crate serde;

use serde::Deserialize;
use std::fs;
use std::sync::Mutex;

#[derive(Debug, Deserialize)]
pub struct Config {
    Command: Vec<Command>,
}

#[derive(Debug, Deserialize)]
pub struct Command {
    name: String,
    id: u16,
}

pub fn generate_commands(id_list: &Mutex<Vec<u16>>, path: &str) -> String {
    let config_str = fs::read_to_string(path).unwrap();
    let config: Config = toml::from_str(&config_str).unwrap();
    // println!("{:?}", config);

    let mut enum_definitions = String::new();
    let mut match_to_id = String::new();
    let mut match_from_id = String::new();
    let mut to_bytes = String::new();
    let mut id_list = id_list.lock().unwrap();
    for command in config.Command {
        if command.id & 0b1111_1000_0000_0000 != 0 {
            panic!("IDs need to be u11. Found {} > {}", command.id, 2 ^ 11);
        } else {
            if id_list.contains(&command.id) {
                panic!(
                    "ID {} already taken!! {}:{} : pick a different one.",
                    command.id, command.name, command.id
                );
            }
            id_list.push(command.id);
        }
        enum_definitions.push_str(&format!("\t{}(u64),\n", command.name));
        match_to_id.push_str(&format!(
            "\t\t\tCommand::{}(_) => {},\n",
            command.name, command.id
        ));
        match_from_id.push_str(&format!(
            "\t\t\t{} => Command::{}(0u64),\n",
            command.id, command.name
        ));
        to_bytes.push_str(&format!(
            "\t\t\tCommand::{}(val) => buf[2..10].copy_from_slice(&val.to_be_bytes()),\n",
            command.name
        ));
    }

    format!(
        "\n
pub enum Command {{
{}
}}
impl Command {{
    pub fn to_id(&self)->u16 {{
        match *self {{\n
{}
        }}
    }}
    pub fn from_id(id:u16) -> Self {{
        match id {{
{}
            _ => Command::DefaultCommand(0)
        }}
    }}
    pub fn as_bytes(&self) -> [u8; 20] {{
        let mut buf = [0u8; 20];
        buf[0..2] = self.to_id().to_be_bytes();
        match *self {{
{}
        }}
        buf
    }}
}}",
        enum_definitions, match_to_id, match_from_id
    )
}
