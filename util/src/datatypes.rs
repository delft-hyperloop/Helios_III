#![allow(non_snake_case, non_camel_case_types)]

use std::fs;

use serde::Deserialize;

#[derive(Deserialize)]
pub struct Config {
    pub(crate) Datatype: Vec<Datatype>,
}

#[derive(Deserialize)]
pub struct Datatype {
    pub name: String,
    pub id: u16,
    pub lower: Option<u64>,
    pub upper: Option<u64>,
}

pub fn get_data_config(path: &str) -> Config {
    let config_str = fs::read_to_string(path).unwrap();
    toml::from_str(&config_str).unwrap()
}

pub fn get_data_ids(path: &str) -> Vec<u16> {
    get_data_config(path).Datatype.iter().map(|x| x.id).collect()
}

pub fn generate_datatypes(path: &str, drv: bool) -> String {
    let config: Config = get_data_config(path);

    let mut enum_definitions = String::new();
    let mut match_to_id = String::new();
    let mut match_from_id = String::new();
    let mut data_ids = vec![];
    let mut from_str = String::new();
    let mut bounds = String::new();

    for dtype in config.Datatype {
        data_ids.push(dtype.id);
        enum_definitions.push_str(&format!("    {},\n", dtype.name));
        match_to_id.push_str(&format!("            Datatype::{} => {},\n", dtype.name, dtype.id));
        match_from_id.push_str(&format!("            {} => Datatype::{},\n", dtype.id, dtype.name));
        from_str.push_str(&format!("            {:?} => Datatype::{},\n", dtype.name, dtype.name));
        bounds.push_str(&format!(
            "            Datatype::{} => {} {} {},\n",
            dtype.name,
            dtype.lower.map(|x| format!("other >= {}u64", x)).unwrap_or("".to_string()),
            if dtype.lower.is_some() && dtype.upper.is_some() {
                "&&".to_string()
            } else {
                "".to_string()
            },
            dtype.upper.map(|x| format!("other <= {}u64", x)).unwrap_or_else(|| {
                if dtype.lower.is_none() && dtype.upper.is_none() {
                    "true".to_string()
                } else {
                    "".to_string()
                }
            }),
        ));
        if let Some(l) = dtype.lower {
            if l == 0 {
                panic!(
                    "
You set a lower bound of 0 for {}. \
Since all values are treated as u64, \
values less than 0 are impossible. 
Please ommit specifying this to keep the config clean :)
",
                    dtype.name
                );
            }
        }
    }

    format!(
        "\n
#[allow(non_camel_case_types)]
#[allow(non_snake_case)]
{}
pub enum Datatype {{
{}
}}\n
impl Datatype {{
    pub fn to_id(&self)->u16 {{
        #[allow(unreachable_patterns)]
        match *self {{
{}
        }}
    }}
    pub fn from_id(id:u16) -> Self {{
        #[allow(unreachable_patterns)]
        match id {{
{}
            _ => Datatype::DefaultDatatype,
        }}
    }}

    #[allow(clippy::should_implement_trait)]
    pub fn from_str(s: &str) -> Self {{
        match s {{
{}
            _ => Datatype::DefaultDatatype,
        }}
    }}


    pub fn check_bounds(&self, other: u64) -> bool {{
        match *self {{
{}
        }}
    }}
}}
",
        if drv {
            "#[derive(Debug, Clone, Copy, PartialEq, Eq, serde::Serialize, serde::Deserialize, PartialOrd, Ord)]"
        } else {
            "#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]"
        },
        enum_definitions,
        match_to_id,
        match_from_id,
        from_str,
        bounds,
    ) + &format!(
        "pub static DATA_IDS : [u16;{}] = [{}];\n",
        data_ids.len(),
        data_ids.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(", ")
    )
}
