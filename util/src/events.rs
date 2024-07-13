#![allow(non_snake_case)]
use std::fs;
use std::hash::DefaultHasher;
use std::hash::Hash;
use std::hash::Hasher;

use anyhow::Result;
use serde::Deserialize;

#[derive(Deserialize, Hash)]
pub struct Config {
    Event: Vec<Event>,
}

#[derive(Deserialize, Hash)]
pub struct Event {
    name: String,
    id: u16,
    priority: usize,
    params: Option<String>,
}

pub fn get_events_config(path: &str) -> Result<Config> {
    let config_str = fs::read_to_string(path)?;
    Ok(toml::from_str(&config_str)?)
}

pub fn get_event_items(path: &str) -> Result<Vec<(u16, String)>> {
    Ok(get_events_config(path)?.Event.iter().map(|x| (x.id, x.name.clone())).collect())
}

pub fn generate_events(path: &str, drv: bool) -> Result<String> {
    let config: Config = get_events_config(path)?;

    let mut hasher = DefaultHasher::new();
    config.hash(&mut hasher);
    let hash = hasher.finish();

    let mut enum_definitions = String::new();
    let mut match_to_id = String::new();
    let mut match_from_id = String::new();
    let mut priorities = String::new();
    let mut to_idx = String::new();
    let mut to_str = String::new();

    let event_count = config.Event.len();
    let mut event_ids = vec![];
    for (i, event) in config.Event.iter().enumerate() {
        event_ids.push(event.id);

        match &event.params {
            None => {
                enum_definitions.push_str(&format!("    {},\n", event.name));
                match_to_id
                    .push_str(&format!("            Event::{} => {},\n", event.name, event.id));
                // to_str.push_str(&format!("Event::{} => \"{}\",\n", command.name, command.name));
                priorities.push_str(&format!(
                    "            Event::{} => {},\n",
                    event.name, event.priority
                ));
                match_from_id
                    .push_str(&format!("            {} => Event::{},\n", event.id, event.name));
                to_idx.push_str(&format!("            Event::{} => {},\n", event.name, i));
            },
            Some(x) => {
                enum_definitions.push_str(&format!("    {}({}),\n", event.name, x));
                match_to_id
                    .push_str(&format!("            Event::{}(_) => {},\n", event.name, event.id));
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
            },
        }
        to_str.push_str(&format!("\"{}\",", event.name));
    }

    Ok(format!(
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
        event_ids.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(", ")
    ) + &format!("\npub const EVENTS_HASH: u64 = {hash};"))
}
