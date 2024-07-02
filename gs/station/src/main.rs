// Prevents an additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use std::io::{BufRead};
#[cfg(feature = "backend")]
use crate::frontend::tauri_main;
#[cfg(feature = "tui")]
use crate::tui::gui_main;

#[cfg(feature = "tui")]
pub mod tui;
pub mod connect;
pub mod api;
#[cfg(feature = "backend")]
mod frontend;
mod levi;

include!(concat!(env!("OUT_DIR"), "/config.rs"));


fn main() {
    // parse command line arguments to see if we should run the TUI or just the backend
    let args: Vec<String> = std::env::args().collect();
    if args.len() > 1 && args[1] == "levi" {
        let (r, s) = levi::start_levi_process();
        std::thread::spawn(move || {
            loop {
                match r.recv() {
                    Ok(msg) => println!("received: {:?}", msg),
                    Err(_) => {}
                }
            }
        });
        loop {
            let stdin = std::io::stdin();
            let mut handle = stdin.lock();
            let mut line = String::new();
            match handle.read_line(&mut line) {
                Ok(_) => {
                    match line.as_str() {
                        "levitate\n" => s.send(Command::Levitate(0)).unwrap(),
                        "stop_levitating\n" => s.send(Command::StopLevitating(0)).unwrap(),
                        _ => {}
                    }
                },
                Err(error) => {
                    println!("Error reading from stdin: {}", error);
                }
            }
        }
    } else if cfg!(feature = "tui") {
        #[cfg(feature = "tui")]
        gui_main().unwrap();
    } else if cfg!(feature = "backend") {
        #[cfg(feature = "backend")]
        tauri_main();
    } else {
        println!("No features enabled, exiting");
    }
}
