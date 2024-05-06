#![allow(non_snake_case)]

extern crate regex;
extern crate serde;

use serde::Deserialize;
use std::fs;
use std::sync::Mutex;

#[derive(Deserialize)]
pub struct Config {
    Datatype: Vec<Datatype>,
}

#[derive(Deserialize)]
pub struct Datatype {
    name: String,
    id: u16,
}

pub const COMMANDS_PATH: &str = "../config/datatypes.toml";

pub fn get_data_config() -> Config {
    let config_str = fs::read_to_string(COMMANDS_PATH).unwrap();
    toml::from_str(&config_str).unwrap()
}

pub fn main(id_list: &Mutex<Vec<u16>>) -> String {
    let config: Config = get_data_config();

    let mut enum_definitions = String::new();
    let mut match_to_id = String::new();
    let mut match_from_id = String::new();
    let mut id_list = id_list.lock().unwrap();
    let mut data_ids = vec![];
    for dtype in config.Datatype {
        if dtype.id & 0b1111_1000_0000_0000 != 0 {
            panic!("IDs need to be u11. Found {} > {}", dtype.id, 2 ^ 11);
        } else {
            if id_list.contains(&dtype.id) {
                panic!(
                    "ID {} already taken!! {}:{} : pick a different one.",
                    dtype.id, dtype.name, dtype.id
                );
            }
            id_list.push(dtype.id);
            data_ids.push(dtype.id);
        }
        enum_definitions.push_str(&format!("\t{},\n", dtype.name));
        match_to_id.push_str(&format!(
            "\t\t\tDatatype::{} => {},\n",
            dtype.name, dtype.id
        ));
        match_from_id.push_str(&format!(
            "\t\t\t{} => Datatype::{},\n",
            dtype.id, dtype.name
        ));
    }

    format!(
        "\n
pub enum Datatype {{
{}
}}\n
impl Datatype {{
    pub fn to_id(&self)->u16 {{
        match *self {{
{}
        }}
    }}
    pub fn from_id(id:u16) -> Self {{
        match id {{
{}
            _ => Datatype::DefaultDatatype,
        }}
    }}
}}
pub static DATA_IDS : [u16;{}] = [{}];\n",
        enum_definitions,
        match_to_id,
        match_from_id,
        data_ids.len(),
        data_ids
            .iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(", ")
    )
}
