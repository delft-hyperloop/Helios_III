use serde::Serialize;

use crate::{state::cnl_state::CNLState, cnl::network::object_entry_object::info::ObjectEntryInformation};

// In typescript represented as types/NetworkInformation
#[derive(Serialize, Clone)]
pub struct NetworkInformation {
    node_names: Vec<String>,
}
#[tauri::command]
pub async fn network_information(
    state: tauri::State<'_, CNLState>,
) -> Result<NetworkInformation, ()> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: (get) network_information()");
    let cnl = state.lock().await;
    Ok(NetworkInformation {
        node_names: cnl.nodes().iter().map(|n| n.name().to_owned()).collect(),
    })
}

// In typescript represented as types/NodeInformation
#[derive(Serialize, Clone)]
pub struct NodeInformation {
    name: String,
    description: Option<String>,
    id: u8,
    object_entries: Vec<String>,
    commands: Vec<String>,
    buses: Vec<String>,
}

#[tauri::command]
pub async fn node_information(
    state: tauri::State<'_, CNLState>,
    node_name: String,
) -> Result<NodeInformation, String> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: (get) node_information({node_name:?})");
    let cnl = state.lock().await;
    let node = cnl.nodes().iter().find(|n| n.name() == &node_name);
    match node {
        Some(node) => Ok(NodeInformation {
            name: node.name().to_owned(),
            description: node.description().cloned(),
            id: node.id(),
            object_entries: node
                .object_entries()
                .iter()
                .map(|oe| oe.name().to_owned())
                .collect(),
            commands: node
                .commands()
                .iter()
                .map(|c| c.name().to_owned())
                .collect(),
            buses: node.buses().iter().map(|b| b.name().to_owned()).collect(),
        }),
        None => Err(format!("node with name '{node_name}' doesn't exist")),
    }
}



#[tauri::command]
pub async fn object_entry_information(
    state: tauri::State<'_, CNLState>,
    node_name: String,
    object_entry_name: String,
) -> Result<ObjectEntryInformation, String> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: (get) object_entry_information({node_name:?}, {object_entry_name:?})");

    let cnl = state.lock().await;
    let node = cnl.nodes().iter().find(|n| n.name() == &node_name);
    let Option::Some(node) = node else {
        return Err(format!("node with name '{node_name}' doesn't exist"));
    };
    let object_entry = node
        .object_entries()
        .iter()
        .find(|oe| oe.name() == &object_entry_name);
    // determine ObjectEntryFormat

    match object_entry {
        Some(object_entry) => Ok(object_entry.information()),
        None => Err(format!(
            "node '{node_name}' doesn't have a object entry with name '{object_entry_name}'"
        )),
    }
}

// In typescript represented as types/CommandInformation
#[derive(Serialize, Clone)]
pub struct CommandInformation {
    name: String,
    description: Option<String>,
}

#[tauri::command]
pub async fn command_information(
    state: tauri::State<'_, CNLState>,
    node_name: String,
    command_name: String,
) -> Result<CommandInformation, String> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: (get) command_information({node_name:?}, {command_name:?})");

    let cnl = state.lock().await;
    let node = cnl.nodes().iter().find(|n| n.name() == &node_name);
    let Option::Some(node) = node else {
        return Err(format!("node with name '{node_name}' doesn't exist"));
    };
    let command = node.commands().iter().find(|c| c.name() == command_name);
    match command {
        Some(command) => Ok(CommandInformation {
            name: command_name,
            description: command.description().cloned(),
        }),
        None => Err(format!(
            "node '{node_name}' doesn't have a command with name '{command_name}'"
        )),
    }
}
