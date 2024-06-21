use crate::cnl::watchdog::WdgStatus;
use crate::state::cnl_state::CNLState;

#[tauri::command]
pub async fn listen_to_node_latest(
    node_name: String,
    state: tauri::State<'_, CNLState>,
) -> Result<String, ()> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: listen_to_node_latest({node_name:?})");

    let cnl = state.lock().await;
    let node = cnl.nodes().iter().find(|no| no.name() == &node_name);
    let node = match node {
        Some(node) => node,
        None => return Err(()),
    };
    Ok(node.listen().await)
}

#[tauri::command]
pub async fn unlisten_from_node_latest(
    node_name: String,
    state: tauri::State<'_, CNLState>,
) -> Result<(), ()> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: unlisten_from_node_latest({node_name:?})");
    let cnl = state.lock().await;
    let node = cnl.nodes().iter().find(|no| no.name() == &node_name);
    let node = match node {
        Some(node) => node,
        None => return Err(()),
    };
    Ok(node.unlisten().await)
}

#[tauri::command]
pub async fn get_heartbeat_status(
    node_name: String,
    bus_name: String,
    state: tauri::State<'_, CNLState>,
) -> Result<WdgStatus, ()> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: get_heartbeat_status({node_name:?})");
    let cnl = state.lock().await;
    let node = cnl.nodes().iter().find(|no| no.name() == &node_name);
    let node = match node {
        Some(node) => node,
        None => return Err(()),
    };
    let bus = node.buses().iter().find(|bus| bus.name() == &bus_name);
    let bus = match bus {
        Some(bus) => bus,
        None => return Err(()),
    };
    node.get_heartbeat_status(bus.id())
}

#[tauri::command]
pub async fn listen_to_heartbeat(
    node_name: String,
    bus_name: String,
    state: tauri::State<'_, CNLState>,
) -> Result<String, ()> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: listen_to_heartbeat_status({node_name:?})");
    let cnl = state.lock().await;
    let node = cnl.nodes().iter().find(|no| no.name() == &node_name);
    let node = match node {
        Some(node) => node,
        None => return Err(()),
    };
    let bus = node.buses().iter().find(|bus| bus.name() == &bus_name);
    let bus = match bus {
        Some(bus) => bus,
        None => return Err(()),
    };
    node.listen_heartbeat_change(bus.id()).await
}

#[tauri::command]
pub async fn unlisten_from_heartbeat(
    node_name: String,
    bus_name: String,
    state: tauri::State<'_, CNLState>,
) -> Result<(), ()> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: unlisten_from_heartbeat_status({node_name:?})");
    let cnl = state.lock().await;
    let node = cnl.nodes().iter().find(|no| no.name() == &node_name);
    let node = match node {
        Some(node) => node,
        None => return Err(()),
    };
    let bus = node.buses().iter().find(|bus| bus.name() == &bus_name);
    let bus = match bus {
        Some(bus) => bus,
        None => return Err(()),
    };
    node.unlisten_heartbeat_change(bus.id()).await
}

