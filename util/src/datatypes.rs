#![allow(non_snake_case, non_camel_case_types)]
use std::fmt::Display;
use std::fmt::Formatter;
use std::fs;
use std::hash::DefaultHasher;
use std::hash::Hash;
use std::hash::Hasher;

use anyhow::Result;
use serde::Deserialize;

const NONE: fn() -> Limit = || Limit::No;

#[derive(Deserialize, Hash)]
pub struct Config {
    pub(crate) Datatype: Vec<Datatype>,
}

#[derive(Deserialize, Hash)]
pub struct Datatype {
    pub name: String,
    pub id: u16,
    #[serde(default = "NONE")]
    pub lower: Limit,
    #[serde(default = "NONE")]
    pub upper: Limit,
}

#[derive(Hash, Clone, Copy)]
pub enum Limit {
    No,
    Single(u64),
    Multiple(Severities),
}

impl Display for Limit {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result<(), std::fmt::Error> {
        match *self {
            Limit::No => write!(f, "Limit::No"),
            Limit::Single(x) => write!(f, "Limit::Single({x})"),
            Limit::Multiple(y) => {
                write!(
                    f,
                    "Limit::Multiple(Severities {{ warn: {}, err: {}, brake: {} }})",
                    y.warn.map(|x| format!("Some({x})")).unwrap_or("None".into()),
                    y.err.map(|x| format!("Some({x})")).unwrap_or("None".into()),
                    y.brake.map(|x| format!("Some({x})")).unwrap_or("None".into()),
                )
            },
        }
    }
}

#[derive(Deserialize, Hash, Clone, Copy)]
pub struct Severities {
    pub warn: Option<u64>,
    pub err: Option<u64>,
    pub brake: Option<u64>,
}

pub fn get_data_config(path: &str) -> Result<Config> {
    let config_str = fs::read_to_string(path)?;
    Ok(toml::from_str(&config_str)?)
}

pub fn get_data_items(path: &str) -> Result<Vec<(u16, String)>> {
    Ok(get_data_config(path)?.Datatype.iter().map(|x| (x.id, x.name.clone())).collect())
}

pub fn generate_datatypes(path: &str, drv: bool) -> Result<String> {
    let config: Config = get_data_config(path)?;

    let mut hasher = DefaultHasher::new();
    config.hash(&mut hasher);
    let hash = hasher.finish();

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
            "            Datatype::{} => ({}, {}),\n",
            dtype.name, dtype.upper, dtype.lower,
        ));
        //         bounds.push_str(&format!(
        //             "            Datatype::{} => {} {} {},\n",
        //             dtype.name,
        //             dtype.lower.map(|x| format!("other >= {}u64", x)).unwrap_or("".to_string()),
        //             if dtype.lower.is_some() && dtype.upper.is_some() {
        //                 "&&".to_string()
        //             } else {
        //                 "".to_string()
        //             },
        //             dtype.upper.map(|x| format!("other <= {}u64", x)).unwrap_or_else(|| {
        //                 if dtype.lower.is_none() && dtype.upper.is_none() {
        //                     "true".to_string()
        //                 } else {
        //                     "".to_string()
        //                 }
        //             }),
        //         ));
        //         if let Some(l) = dtype.lower {
        //             if l == 0 {
        //                 panic!(
        //                     "
        // You set a lower bound of 0 for {}. \
        // Since all values are treated as u64, \
        // values less than 0 are impossible.
        // Please ommit specifying this to keep the config clean :)
        // ",
        //                     dtype.name
        //                 );
        //             }
        //         }
    }

    Ok(format!(
        "\n
pub enum Limit {{
    No,
    Single(u64),
    Multiple(Severities)
}}

pub struct Severities {{
    pub warn: Option<u64>,
    pub err: Option<u64>,
    pub brake: Option<u64>,
}}

pub enum ValueCheckResult {{
    Fine,
    Warn,
    Error,
    BrakeNow,
}}

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


    pub fn bounds(&self) -> (Limit, Limit) {{
        match *self {{
{}
        }}
    }}

    pub fn check_bounds(&self, value: u64) -> ValueCheckResult {{
        let (up, low) = self.bounds();
        let ok_up = match up {{
            Limit::No => 0,
            Limit::Single(x) => if value > x {{ 1 }} else {{ 0 }},
            Limit::Multiple(Severities {{
                warn: a,
                err: b,
                brake: c,
            }}) => {{
                if let Some(cc) = c {{
                    if value > cc {{ 100 }} else {{ 0 }}
                }} else if let Some(bb) = b {{
                    if value > bb {{ 10 }} else {{ 0 }}
                }} else if let Some(aa) = a {{
                    if value > aa {{ 1 }} else {{ 0 }}
                }} else {{ 0 }}
            }}
        }};
        let ok_low = match low {{
            Limit::No => 0,
            Limit::Single(x) => if value < x {{ 1 }} else {{ 0 }},
            Limit::Multiple(Severities {{
                warn: a,
                err: b,
                brake: c,
            }}) => {{
                if let Some(cc) = c {{
                    if value < cc {{ 100 }} else {{ 0 }}
                }} else if let Some(bb) = b {{
                    if value < bb {{ 10 }} else {{ 0 }}
                }} else if let Some(aa) = a {{
                    if value < aa {{ 1 }} else {{ 0 }}
                }} else {{ 0 }}
            }}
        }};
        match ok_up + ok_low {{
            0 => ValueCheckResult::Fine,
            1..=9 => ValueCheckResult::Warn,
            10..=99 => ValueCheckResult::Error,
            _ => ValueCheckResult::BrakeNow,
        }}
    }}
}}
",
        if drv {
            "#[derive(Debug, Clone, Copy, PartialEq, Eq, serde::Serialize, serde::Deserialize, PartialOrd, Ord)]"
        } else {
            "#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, defmt::Format)]"
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
    ) + &format!("\npub const DATA_HASH: u64 = {hash};"))
}
