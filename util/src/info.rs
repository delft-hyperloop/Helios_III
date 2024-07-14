#![allow(non_snake_case)]

use anyhow::Result;
use serde::Deserialize;

#[derive(Debug, Deserialize)]
pub struct Config {
    pub Info: Vec<Info>,
}

#[derive(Debug, Deserialize)]
pub struct Info {
    pub label: String,
    pub colour: Option<String>,
}

pub fn generate_info(path: &str, drv: bool) -> Result<String> {
    let config_str = std::fs::read_to_string(path)?;
    let config: Config = toml::from_str(&config_str)?;

    let mut enum_definitions = String::new();
    let mut match_to_id = String::new();
    let mut match_from_id = String::new();
    let mut colours = String::new();
    for (i, info) in config.Info.iter().enumerate() {
        enum_definitions.push_str(&format!("    {},\n", info.label));
        match_to_id.push_str(&format!("            Info::{} => {},\n", info.label, i));
        match_from_id.push_str(&format!("            {} => Info::{},\n", i, info.label));
        if let Some(c) = &info.colour {
            colours.push_str(&format!("{:?}, ", c));
        } else {
            colours.push_str("\"gray\", ");
        }
    }

    Ok(format!(
        "
pub const INFO_COLOURS: [&str; {}] = [{}\"yellow\"];

#[allow(non_camel_case_types)]
#[allow(non_snake_case)]
{}
pub enum Info {{
{}
    UnknownInfo,
}}
impl Info {{
    pub fn to_idx(&self) -> u64 {{
        match *self {{
{}
            _ => 0
        }}
    }}
    pub fn from_id(id: u16) -> Self {{
        match id {{
{}
            _ => Info::UnknownInfo,
        }}
    }}
    pub fn to_colour_str(&self) -> &str {{
        INFO_COLOURS[self.to_idx() as usize]
    }}
}}
    ",
        config.Info.len() + 1,
        colours,
        if drv {
            "#[derive(Debug, Clone, Copy, PartialEq, Eq, serde::Serialize, serde::Deserialize, PartialOrd, Ord)]"
        } else {
            "#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, defmt::Format)]"
        },
        enum_definitions,
        match_to_id,
        match_from_id
    ))
}
