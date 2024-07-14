#![allow(non_snake_case)]

use std::fs;
use std::hash::DefaultHasher;
use std::hash::Hash;
use std::hash::Hasher;

use anyhow::Result;
use serde::Deserialize;

#[derive(Debug, Deserialize, Hash)]
pub struct Config {
    pub(crate) Command: Vec<Command>,
}

#[derive(Debug, Deserialize, Hash)]
pub struct Command {
    pub name: String,
    pub id: u16,
}

fn get_command_config(path: &str) -> Result<Config> {
    let config_str = fs::read_to_string(path)?;
    Ok(toml::from_str(&config_str)?)
}

pub fn get_command_items(path: &str) -> Result<Vec<(u16, String)>> {
    let config: Config = get_command_config(path)?;
    Ok(config.Command.iter().map(|x| (x.id, x.name.clone())).collect())
}

pub fn generate_commands(path: &str, drv: bool) -> Result<String> {
    let config: Config = get_command_config(path)?;
    // println!("{:?}", config);

    let mut hasher = DefaultHasher::new();
    config.hash(&mut hasher);
    let hash = hasher.finish();

    let mut enum_definitions = String::new();
    let mut match_to_id = String::new();
    let mut match_from_id = String::new();
    let mut to_bytes = String::new();
    let mut ids = Vec::new();
    let mut names = String::new();
    let mut name_list = Vec::new();
    let mut to_idx = String::new();
    for (i, command) in config.Command.iter().enumerate() {
        enum_definitions.push_str(&format!("    {}(u64),\n", command.name));
        match_to_id
            .push_str(&format!("            Command::{}(_) => {},\n", command.name, command.id));
        match_from_id
            .push_str(&format!("            {} => Command::{}(val),\n", command.id, command.name));
        to_bytes.push_str(&format!(
            "            Command::{}(val) => {{ buf[3..11].copy_from_slice(&val.to_be_bytes()); }}\n",
            command.name
        ));
        ids.push(command.id.to_string());
        name_list.push(format!("\"{}\"", command.name));
        names.push_str(&format!(
            "            \"{}\" => Command::{}(p),\n",
            &command.name, &command.name
        ));
        to_idx.push_str(&format!("            Command::{}(_) => {i},\n", &command.name));
    }

    Ok(format!(
        "\n
#[allow(non_camel_case_types)]
#[allow(non_snake_case)]
{}
pub enum Command {{
{}
}}
impl Command {{
    pub fn to_id(&self)->u16 {{
        #[allow(unreachable_patterns)]
        match *self {{\n
{}
        }}
    }}
    pub fn from_id(id:u16, val: u64) -> Self {{
        #[allow(unreachable_patterns)]
        match id {{
{}
            _ => Command::DefaultCommand(0)
        }}
    }}
    pub fn as_bytes(&self) -> [u8; 20] {{
        let mut buf = [0u8; 20];
        buf[0] = 0xff;
        buf[1..3].copy_from_slice(&self.to_id().to_be_bytes());
        #[allow(unreachable_patterns)]
        match *self {{
{}
        }}
        buf[19] = 0xff;
        buf
    }}
    pub fn from_bytes(buf: &[u8; 20]) -> Self {{
        Command::from_id(u16::from_be_bytes([buf[1], buf[2]]), u64::from_be_bytes([buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9], buf[10]]))
    }}
    pub fn from_string(s: &str, p: u64) -> Self {{
        #[allow(unreachable_patterns)]
        match s {{
{}
            _ => Command::DefaultCommand(p)
        }}
    }}
    pub fn to_idx(&self) -> usize {{
        match *self {{
{}
        }}
    }}
    pub fn to_str(&self) -> &str {{
        COMMANDS_LIST[self.to_idx()]
    }}
}}
pub const COMMAND_IDS: [u16; {}] = [{}];
pub const COMMANDS_LIST: [&str; {}] = [{}];
",
        if drv { "#[derive(Debug, Clone, Copy, defmt::Format, PartialEq)]" } else { "#[derive(Debug, Clone, Copy, PartialEq, serde::Serialize, serde::Deserialize)]" },
        enum_definitions, match_to_id, match_from_id, to_bytes, names,
        to_idx,
        ids.len(), ids.join(", "), name_list.len(), name_list.join(", ")
    )
    + &format!("\npub const COMMAND_HASH: u64 = {hash};"))
}
