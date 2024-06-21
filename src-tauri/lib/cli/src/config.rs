use std::{
    cmp::Ordering,
    path::PathBuf,
    sync::Arc,
};

use canzero_appdata::AppData;
use canzero_config::config::{self, Type};

use crate::errors::{Error, Result};

pub fn command_config_show() -> Result<()> {
    Err(Error::NotYetImplemented)
}

pub fn command_config_nodes_list() -> Result<()> {
    let appdata = AppData::read()?;
    let network = appdata.config()?;
    for node in network.nodes() {
        println!("{:15} {:3}", node.name(), node.id());
    }
    Ok(())
}

pub fn command_config_object_entries_list(node: String) -> Result<()> {
    let appdata = AppData::read()?;
    let network = appdata.config()?;
    let Some(node) = network.nodes().iter().find(|n| n.name() == node) else {
        return Err(Error::InvalidNodeName(node));
    };
    for oe in node.object_entries() {
        fn ty_to_name(ty: &Type) -> String {
            match ty {
                config::Type::Primitive(prim) => match prim {
                    config::SignalType::UnsignedInt { size } => format!("u{size}"),
                    config::SignalType::SignedInt { size } => format!("i{size}"),
                    config::SignalType::Decimal {
                        size,
                        offset,
                        scale,
                    } => {
                        let min = *offset;
                        let max = (2u128.pow(*size as u32) as f64 / *scale) + min;
                        format!("d{size}<{min}..{max}> (scale = {scale})")
                    }
                },
                config::Type::Struct {
                    name,
                    description: _,
                    attribs: _,
                    visibility: _,
                } => format!("{name}"),
                config::Type::Enum {
                    name,
                    description: _,
                    size: _,
                    entries: _,
                    visibility: _,
                } => format!("{name}"),
                config::Type::Array { len, ty } => {
                    format!("{}[{len}", ty_to_name(ty))
                }
            }
        }
        println!("[{}] = {} : {}", oe.id(), oe.name(), ty_to_name(oe.ty()));
    }

    Ok(())
}

pub fn command_config_set(path: PathBuf) -> Result<()> {
    let mut appdata = AppData::read()?;
    appdata.set_config_path(Some(path))?;
    Ok(())
}

pub fn command_config_get() -> Result<()> {
    let appdata = AppData::read()?;
    match appdata.get_config_path() {
        Some(path) => println!("{path:?}"),
        None => println!("No path to config specificied"),
    }
    Ok(())
}

pub fn command_config_messages_list(node: Option<String>, bus: Option<String>) -> Result<()> {
    let appdata = AppData::read()?;
    let network = appdata.config()?;

    if let Some(bus_name) = &bus {
        if !network.buses().iter().any(|b| b.name() == bus_name) {
            return Err(Error::InvalidBusName(bus_name.clone()));
        }
    };

    if let Some(node_name) = node {
        let Some(node) = network.nodes().iter().find(|n| n.name() == node_name) else {
            return Err(Error::InvalidNodeName(node_name));
        };

        let rx_messages = node.rx_messages().clone();
        let rx_messages = match &bus {
            Some(bus_name) => rx_messages
                .iter()
                .filter(|m| m.bus().name() == bus_name)
                .map(Arc::clone)
                .collect(),
            None => rx_messages,
        };
        println!("DIR BUS   ID     DLC  NAME");
        for msg in rx_messages {
            let name = msg.name();
            let dlc = msg.dlc();
            let id = msg.id();
            let bus = msg.bus().name();
            println!("RX  {bus}  {id} [{dlc}]  {name}");
        }

        let tx_messages = node.tx_messages().clone();
        let tx_messages = match &bus {
            Some(bus_name) => tx_messages
                .iter()
                .filter(|m| m.bus().name() == bus_name)
                .map(Arc::clone)
                .collect(),
            None => tx_messages,
        };
        for msg in tx_messages {
            let name = msg.name();
            let dlc = msg.dlc();
            let id = msg.id();
            let bus = msg.bus().name();
            println!("TX  {bus}  {id} [{dlc}]  {name}");
        }
    } else {
        let messages = match &bus {
            Some(bus_name) => network
                .messages()
                .iter()
                .filter(|m| m.bus().name() == bus_name)
                .map(Arc::clone)
                .collect(),
            None => network.messages().clone(),
        };

        println!("BUS   ID     DLC  NAME");
        for msg in messages {
            let name = msg.name();
            let dlc = msg.dlc();
            let id = msg.id();
            let bus = msg.bus().name();
            println!("{bus}  {id} [{dlc}]  {name}");
        }
    };

    Ok(())
}

pub fn command_config_check() -> Result<()> {
    let appdata = AppData::read()?;
    let _ = appdata.config()?;
    Ok(())
}

pub fn command_config_hash() -> Result<()> {
    let appdata = AppData::read()?;
    let network = appdata.config()?;

    println!("{}", network.portable_hash());
    Ok(())
}
