#![allow(non_snake_case)]

extern crate regex;
extern crate serde;
use std::env;
use std::fs;
use std::path::Path;
use serde::Deserialize;
use toml::map::Map;

#[derive(Debug, Deserialize)]
struct Config {
    Command: Vec<Command>,
}

#[derive(Debug, Deserialize)]
struct Command {
    name: String,
    id: u16,
}


pub const COMMANDS_PATH: &str = "../config/commands.toml";

pub fn main() -> String {
    let config_str = fs::read_to_string(COMMANDS_PATH).unwrap();
    let config: Config = toml::from_str(&config_str).unwrap();
    // println!("{:?}", config);

    let mut enum_definitions = String::new();
    let mut match_to_id = String::from("match *self {\n");
    let mut match_from_id = String::from("match id {\n");

    for command in config.Command {
        enum_definitions.push_str(&format!("{}(u64),\n", command.name));
        match_to_id.push_str(&format!("Command::{}(_) => {},\n", command.name, command.id));
        match_from_id.push_str(&format!("{} => Command::{}(0u64),\n", command.id, command.name));
    }

    format!("\n\npub enum Command {{ {} }}\nimpl Command {{\n  pub fn to_id(&self)->u16 {{ {} }} }}\n pub fn from_id(id:u16) -> Self {{ {} _ => Command::DefaultCommand(0), }} }}\n}}", enum_definitions, match_to_id, match_from_id)
}