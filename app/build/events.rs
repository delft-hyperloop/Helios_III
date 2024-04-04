#![allow(non_snake_case)]

extern crate regex;
extern crate serde;
use std::env;
use std::fmt::format;
use std::fs;
use std::path::Path;
use serde::Deserialize;

#[derive(Deserialize)]
struct Config {
    Event: Vec<Event>,
}

#[derive(Deserialize)]
struct Event {
    name: String,
    id: u16,
    priority: usize,
    params: Option<String>
}

pub const COMMANDS_PATH: &str = "../config/events.toml";

pub fn main() -> String {
    let config_str = fs::read_to_string(COMMANDS_PATH).unwrap();
    let config: Config = toml::from_str(&config_str).unwrap();

    let mut enum_definitions = String::new();
    let mut match_to_id = String::from("match *self {\n");
    let mut match_from_id = String::from("match id {\n");
    let mut priorities = String::new();
    let mut to_idx = String::new();
    let mut to_str = String::new();

    let event_count = config.Event.len();
    let mut i = 0;
    for command in config.Event {
        match command.params {
            None => {
                enum_definitions.push_str(&format!("{},\n", command.name));
                match_to_id.push_str(&format!("Event::{} => {},\n", command.name, command.id));
                // to_str.push_str(&format!("Event::{} => \"{}\",\n", command.name, command.name));
                priorities.push_str(&format!("Event::{} => {},\n", command.name, command.priority));
                match_from_id.push_str(&format!("{} => Event::{},\n", command.id, command.name));
                to_idx.push_str(&format!("Event::{} => {},", command.name, i));
            }
            Some(x) => {
                enum_definitions.push_str(&format!("{}({}),\n", command.name, x));
                match_to_id.push_str(&format!("Event::{}(_) => {},\n", command.name, command.id));
                // to_str.push_str(&format!("Event::{}(_) => \"{}\",\n", command.name, command.name));
                priorities.push_str(&format!("Event::{}(_) => {},\n", command.name, command.priority));
                match_from_id.push_str(&format!("{} => Event::{}(0),\n", command.id, command.name));
                to_idx.push_str(&format!("Event::{}(_) => {},", command.name, i));
            }
        }
        to_str.push_str(&format!("\"{}\",", command.name));
    }

    format!("pub static EVENTS_DISPLAY: [&str; {}] = [{}\"Unknown\"];", event_count+1, to_str)
    + &* format!("#[derive(Debug, PartialEq, Eq)]
             pub enum Event {{
                {}
             }}
             impl Event {{
                pub fn to_id(&self)->u16 {{
                    {}
                    }}
                }}
                pub fn from_id(id:u16) -> Self {{
                    {}
                        _ => Event::DefaultEvent,
                    }}
                }}
                pub fn priority(&self) -> usize {{
                    match self {{
                        {}
                        _ => 0,
                    }}
                }}
                fn to_idx(&self) -> usize {{
                    match self {{
                        {}
                        _ => {},
                    }}
                }}
                pub fn to_str(&self) -> &'static str {{
                    EVENTS_DISPLAY[self.to_idx()]
                }}
             }}", enum_definitions, match_to_id, match_from_id, priorities, to_idx, event_count)
}

/*
                pub fn to_str(&self) -> &'static str {{
                    {}
                    }}
                }}
                */