#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use canzero_cli::run_cli;
use tauri::Manager;

use crate::{
    commands::{connection_status, network_information, object_entry_commands, search_string_storage::SearchStringStorage},
    state::startup::StartupState,
};

mod cnl;
mod commands;
mod notification;
mod state;

#[tokio::main(flavor = "multi_thread", worker_threads = 8)]
async fn main() {
    let _ = fix_path_env::fix();
    tauri::async_runtime::set(tokio::runtime::Handle::current());

    // setup tauri
    tauri::Builder::default()
        .manage(SearchStringStorage { store: Default::default() })
        .setup(|app| {
            let handle = app.handle();
            tokio::spawn(async move {
                let armv7_binary = handle
                    .path_resolver()
                    .resolve_resource("xcompl/canzero-cli-armv7-unknown-linux-gnueabihf")
                    .unwrap();
                if !run_cli(Some(armv7_binary)).await {
                    std::process::exit(0);
                }
                handle.manage(StartupState::new());
                handle.manage(SearchStringStorage{store : Default::default()});
                tauri::WindowBuilder::new(
                    &handle,
                    "startup",
                    tauri::WindowUrl::App("startup.html".into()),
                )
                .center()
                .title("CANzero-Startup")
                .decorations(true)
                .resizable(false)
                .inner_size(960f64, 540f64)
                .build().unwrap();
            });
            Ok(())
        })
        .invoke_handler(tauri::generate_handler![
            commands::trace::listen_to_trace,
            commands::trace::unlisten_from_trace,
            commands::trace::sort_trace_by,
            commands::trace::filter_trace_by,
            network_information::network_information,
            network_information::node_information,
            network_information::object_entry_information,
            network_information::command_information,
            object_entry_commands::listen_to_latest_object_entry_value,
            object_entry_commands::unlisten_from_latest_object_entry_value,
            object_entry_commands::listen_to_history_of_object_entry,
            object_entry_commands::unlisten_from_history_of_object_entry,
            object_entry_commands::request_object_entry_value,
            object_entry_commands::set_object_entry_value,
            object_entry_commands::get_floating_window_info,
            object_entry_commands::open_floating_object_entry_window,
            connection_status::get_connection_status,
            connection_status::heartbeat,
            connection_status::unregister_from_heartbeat,
            connection_status::reregister_to_heartbeat,
            connection_status::restart,
            connection_status::close,
            connection_status::create_deadlock,
            commands::node_commands::listen_to_node_latest,
            commands::node_commands::unlisten_from_node_latest,
            commands::node_commands::get_heartbeat_status,
            commands::node_commands::listen_to_heartbeat,
            commands::node_commands::unlisten_from_heartbeat,
            commands::export::export,
            commands::startup::download_network_configuration,
            commands::startup::discover_servers,
            commands::startup::try_connect,
            commands::startup::complete_setup,
            commands::startup::close_startup,
            commands::settings::open_settings,
            commands::settings::close_settings,
            commands::settings::select_network_configuration,
            commands::settings::get_settings,
            commands::settings::set_frontend_lvl,
            commands::settings::set_deadlock_lvl,
            commands::search_string_storage::get_stored_search_string,
            commands::search_string_storage::store_search_string,
        ])
        .run(tauri::generate_context!())
        .expect("Error while running tauri application");
}
