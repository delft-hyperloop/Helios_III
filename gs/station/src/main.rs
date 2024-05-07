// Prevents additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use std::thread;
use crate::api::ApiStruct;
use crate::frontend::tauri_main;
use crate::tui::gui_main;

pub mod tui;
pub mod connect;
pub mod api;
mod frontend;

include!(concat!(env!("OUT_DIR"), "/config.rs"));


fn main() {
  // parse command line arguments to see if we should run the TUI or just the backend
  let args: Vec<String> = std::env::args().collect();
  if args.len() > 1 && args[1] == "ui" {
      gui_main().unwrap();
  } else {
      tauri::Builder::default()
          .run(tauri::generate_context!())
          .expect("error while running tauri application");
      tauri_main();
  }
}
