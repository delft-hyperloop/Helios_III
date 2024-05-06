// Prevents additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

pub mod tui;
pub mod connect;
pub mod api;

include!(concat!(env!("OUT_DIR"), "/config.rs"));


fn main() {
  tauri::Builder::default()
    .run(tauri::generate_context!())
    .expect("error while running tauri application");


}
