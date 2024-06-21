use std::time::Duration;

use canzero_appdata::AppData;
use canzero_udp::scanner::UdpNetworkScanner;
use serde::Serialize;
use tauri::Manager;

use crate::state::startup::{NetworkConnectionCreateInfo, StartupState};

#[tauri::command]
pub async fn download_network_configuration(
    state: tauri::State<'_, StartupState>,
) -> Result<(), String> {
    let network_config = tokio::task::spawn_blocking(|| {
        let Ok(appdata) = AppData::read() else {
            return Err(
                "No config set use \n$ canzero config set-path <path-to-config>".to_owned(),
            );
        };
        let Some(config_path) = appdata.get_config_path() else {
            return Err(
                "No config set use \n$ canzero config set-path <path-to-config>".to_owned(),
            );
        };
        let Ok(network_config) = appdata.config() else {
            return Err(format!("Failed to parse configuration at {config_path:?}"));
        };
        Ok(network_config)
    })
    .await
    .expect("Failed to join blocking task (during download_network_configuration)")?;
    state.set_network_config(network_config).await;
    Ok(())
}

#[allow(unused)]
pub enum ConnectionType {
    SocketCan = 0,
    Tcp = 1,
}

impl Serialize for ConnectionType {
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: serde::Serializer,
    {
        serializer.serialize_u8(match self {
            ConnectionType::SocketCan => 0,
            ConnectionType::Tcp => 1,
        })
    }
}

#[derive(Serialize)]
pub struct ConnectionDescription {
    tag: ConnectionType,
    description: String,
}

#[tauri::command]
pub async fn discover_servers(
    state: tauri::State<'_, StartupState>,
) -> Result<Vec<ConnectionDescription>, String> {
    let scanner = UdpNetworkScanner::create()
        .await
        .map_err(|err| format!("{err:?}"))?;
    scanner.start();
    let mut connections = vec![];
    loop {
        match scanner.next_timeout(Duration::from_millis(1000)).await {
            Some(Ok(con)) => {
                connections.push(con);
                continue;
            },
            Some(Err(err)) => {
                return Err(format!("{err:?}"));
            }
            None => break,
        }
    }
    drop(scanner);

    // CANzero discovery broadcast are always broadcast on port 9002!

    let connections: Vec<NetworkConnectionCreateInfo> = connections
        .into_iter()
        .map(NetworkConnectionCreateInfo::Tcp)
        .collect();

    #[cfg(feature = "socket-can")]
    let Some(network_configuration): Option<canzero_config::config::NetworkRef> =
        state.network_configuration().await
    else {
        return Err("Failed to discover networks. No network configuration avaiable.".to_owned());
    };
    #[cfg(feature = "socket-can")]
    let connections = {
        let mut connections = connections.clone();
        check_for_socketcan(&network_configuration, &mut connections);
        connections
    };

    state.set_connections(connections.clone()).await;
    Ok(connections
        .iter()
        .map(|con| match con {
            NetworkConnectionCreateInfo::Tcp(nd) => ConnectionDescription {
                tag: ConnectionType::Tcp,
                description: format!(
                    "{} at {}:{}",
                    nd.server_name, nd.server_addr, nd.service_port
                ),
            },
            #[cfg(feature = "socket-can")]
            NetworkConnectionCreateInfo::SocketCan => ConnectionDescription {
                tag: ConnectionType::SocketCan,
                description: format!(
                    "SocketCAN at {:?}",
                    network_configuration
                        .buses()
                        .iter()
                        .map(|bus| bus.name())
                        .collect::<Vec<&str>>()
                ),
            },
        })
        .collect())
}

#[cfg(feature = "socket-can")]
pub fn check_for_socketcan(
    network_ref: &canzero_config::config::NetworkRef,
    connections: &mut Vec<NetworkConnectionCreateInfo>,
) {
    for bus in network_ref.buses() {
        let Ok(_) = nix::net::if_::if_nametoindex(bus.name()) else {
            return;
        };
    }
    connections.push(NetworkConnectionCreateInfo::SocketCan);
}

#[tauri::command]
pub async fn try_connect(
    state: tauri::State<'_, StartupState>,
    app_handle: tauri::AppHandle,
    connection_index: usize,
) -> Result<(), String> {
    state.try_connect(connection_index, &app_handle).await
}

#[tauri::command]
pub async fn complete_setup(
    app_handle: tauri::AppHandle,
    startup_state: tauri::State<'_, StartupState>,
) -> Result<(), String> {
    // create cnl state
    let cnl_state = startup_state.complete_setup(&app_handle).await?;
    app_handle.manage(cnl_state);

    // create new window
    tauri::WindowBuilder::new(
        &app_handle,
        "main",
        tauri::WindowUrl::App("index.html".into()),
    )
    .title("CANzero control-panel")
    .inner_size(800f64, 600f64)
    .resizable(true)
    .visible(true)
    .build()
    .map_err(|err| format!("{err:?}"))?;

    return Ok(());
}

#[tauri::command]
pub fn close_startup(app_handle: tauri::AppHandle) {
    let Some(startup_window) = app_handle.get_window("startup") else {
        return;
    };
    startup_window
        .close()
        .expect("Failed to close startup window");
}
