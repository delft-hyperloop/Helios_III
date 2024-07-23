// Prevents an additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
#![warn(clippy::absolute_paths)]

use gslib::Command;
use gslib::Message;
use gslib::GS_IP_ADDRESS;

use crate::backend::Backend;
#[cfg(feature = "backend")]
use crate::frontend::app::tauri_main;
#[cfg(feature = "tui")]
use crate::tui::tui_main;

mod backend;
pub mod battery;
pub mod connect;
mod data;
#[cfg(feature = "backend")]
mod frontend;
mod levi;
#[cfg(feature = "tui")]
pub mod tui;

pub type CommandSender = tokio::sync::broadcast::Sender<Command>;
pub type CommandReceiver = tokio::sync::broadcast::Receiver<Command>;
pub type MessageSender = tokio::sync::broadcast::Sender<Message>;
pub type MessageReceiver = tokio::sync::broadcast::Receiver<Message>;

/// Entry point of the application
#[tokio::main]
async fn main() {
    let args = std::env::args().collect::<Vec<String>>();
    if args.len() > 1 {
        let x = args[1].trim().split('.').map(|x| x.parse().unwrap()).collect::<Vec<u8>>();
        unsafe {
            GS_IP_ADDRESS = ([x[0], x[1], x[2], x[3]], GS_IP_ADDRESS.1);
        }
    }
    let backend = Backend::new();

    if cfg!(feature = "tui") {
        #[cfg(feature = "tui")]
        tui_main(backend); // the frontend can transmit commands and subscribe to receive messages
    } else if cfg!(feature = "backend") {
        #[cfg(feature = "backend")]
        tauri_main(backend);
    } else {
        println!("No features enabled, exiting");
    }
}
