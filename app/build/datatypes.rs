#![allow(non_snake_case)]

extern crate regex;
extern crate serde;
use std::env;
use std::fs;
use std::path::Path;
use serde::Deserialize;

#[derive(Deserialize)]
struct Config {
    Datatype: Vec<Datatype>,
}

#[derive(Deserialize)]
struct Datatype {
    name: String,
    id: u16,
}


pub const COMMANDS_PATH: &str = "../config/datatypes.toml";

pub fn main() -> String {
    let config_str = fs::read_to_string(COMMANDS_PATH).unwrap();
    let config: Config = toml::from_str(&config_str).unwrap();

    let mut enum_definitions = String::new();
    let mut match_to_id = String::from("match *self {\n");
    let mut match_from_id = String::from("match id {\n");

    for dtype in config.Datatype {
        if dtype.id & 0b1111_1000_0000_0000 != 0 {
            panic!("IDs need to be u11. Found {} > {}", dtype.id, 2^11);
        }
        enum_definitions.push_str(&format!("{},\n", dtype.name));
        match_to_id.push_str(&format!("Datatype::{} => {},\n", dtype.name, dtype.id));
        match_from_id.push_str(&format!("{} => Datatype::{},\n", dtype.id, dtype.name));
    }

    format!("pub enum Datatype {{ {} }}\nimpl Datatype {{\n  pub fn to_id(&self)->u16 {{ {} }} }}\n pub fn from_id(id:u16) -> Self {{ {} _ => Datatype::DefaultDatatype, }} }}\n}}", enum_definitions, match_to_id, match_from_id)
}