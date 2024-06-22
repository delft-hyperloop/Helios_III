#![allow(non_snake_case)]

use serde::Deserialize;
use std::fs;
use std::sync::Mutex;

#[derive(Deserialize)]
pub struct Config {
    Event: Vec<Event>,
}

#[derive(Deserialize)]
pub struct Event {
    name: String,
    id: u16,
    priority: usize,
    params: Option<String>,
}

pub fn get_events_config(path: &str) -> Config {
    let config_str = fs::read_to_string(path).unwrap();
    toml::from_str(&config_str).unwrap()
}

pub fn generate_events(id_list: &Mutex<Vec<u16>>, path: &str, drv: bool) -> String {
    let config: Config = get_events_config(path);

    let mut enum_definitions = String::new();
    let mut match_to_id = String::new();
    let mut match_from_id = String::new();
    let mut priorities = String::new();
    let mut to_idx = String::new();
    let mut to_str = String::new();

    let event_count = config.Event.len();
    let mut i = 0;
    let mut id_list = id_list.lock().unwrap();
    let mut event_ids = vec![];
    for event in config.Event {
        if event.id & 0b1111_1000_0000_0000 != 0 {
            panic!("IDs need to be u11. Found {} > {}", event.id, 2 ^ 11);
        } else {
            if id_list.contains(&event.id) {
                panic!(
                    "ID {:#05x} already taken!! {}={} : pick a different one.",
                    event.id, event.name, event.id
                );
            }
            id_list.push(event.id);
            event_ids.push(event.id);
        }
        match event.params {
            None => {
                enum_definitions.push_str(&format!("    {},\n", event.name));
                match_to_id.push_str(&format!(
                    "            Event::{} => {},\n",
                    event.name, event.id
                ));
                // to_str.push_str(&format!("Event::{} => \"{}\",\n", command.name, command.name));
                priorities.push_str(&format!(
                    "            Event::{} => {},\n",
                    event.name, event.priority
                ));
                match_from_id.push_str(&format!(
                    "            {} => Event::{},\n",
                    event.id, event.name
                ));
                to_idx.push_str(&format!("            Event::{} => {},\n", event.name, i));
            }
            Some(x) => {
                enum_definitions.push_str(&format!("    {}({}),\n", event.name, x));
                match_to_id.push_str(&format!(
                    "            Event::{}(_) => {},\n",
                    event.name, event.id
                ));
                // to_str.push_str(&format!("Event::{}(_) => \"{}\",\n", command.name, command.name));
                priorities.push_str(&format!(
                    "            Event::{}(_) => {},\n",
                    event.name, event.priority
                ));
                match_from_id.push_str(&format!(
                    "            {} => Event::{}(v.unwrap_or(0)),\n",
                    event.id, event.name
                ));
                to_idx.push_str(&format!("            Event::{}(_) => {},\n", event.name, i));
            }
        }
        to_str.push_str(&format!("\"{}\",", event.name));
        i += 1;
    }

    format!(
        "\n\npub const EVENTS_DISPLAY: [&str; {}] = [{}\"Unknown\"];\n",
        event_count + 1,
        to_str
    ) + &*format!(
        "
{}
pub enum Event {{
{}
}}
impl Event {{
    pub fn to_id(&self)->u16 {{
        #[allow(unreachable_patterns)]
        match *self {{
{}
        }}
    }}
    pub fn from_id(id:u16, v: Option<u64>) -> Self {{
        #[allow(unreachable_patterns)]
        match id {{
{}
            _ => Event::DefaultEvent,
        }}
    }}
    pub fn priority(&self) -> usize {{
        #[allow(unreachable_patterns)]
        match self {{
{}
            _ => 0,
        }}
    }}
    fn to_idx(&self) -> usize {{
        #[allow(unreachable_patterns)]
        match self {{
{}
            _ => {},
        }}
    }}
    pub fn to_str(&self) -> &'static str {{
        EVENTS_DISPLAY[self.to_idx()]
    }}
}}",
        if drv {
            "#[derive(Debug, PartialEq, Eq, defmt::Format)]"
        } else {
            "#[derive(Debug, PartialEq, Eq)]"
        },
        enum_definitions,
        match_to_id,
        match_from_id,
        priorities,
        to_idx,
        event_count
    ) + &*format!(
        "\n\npub static EVENT_IDS : [u16;{}] = [{}];\n",
        event_ids.len(),
        event_ids
            .iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(", ")
    )
}
