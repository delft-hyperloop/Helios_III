mod gui;
mod station;
mod api;
mod util;

use std::thread;
use rayon::prelude::*;
use colored::Colorize;


fn main() {

    // Create communication channels between backend and frontend threads
    let (data_tx, data_rx) = std::sync::mpsc::channel();
    let (command_tx, command_rx) = std::sync::mpsc::channel();

    thread::spawn(|| {
        station::launch(data_tx, command_rx);
    });

    // parse command line arguments to see if we should run the TUI or just the backend
    let args: Vec<String> = std::env::args().collect();
    if args.len() > 1 && args[1] == "ui" {
        gui::main::gui_main(command_tx, data_rx).unwrap();
    } else {
        loop {}
    }
}