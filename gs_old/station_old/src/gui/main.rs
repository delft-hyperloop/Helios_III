
use std::any::Any;
use std::io;
use std::backtrace::Backtrace;
use std::sync::mpsc::{Receiver, Sender};
use crossterm::event::{self, Event, KeyCode, KeyEvent, KeyEventKind};
use ratatui::{
    prelude::*,
    symbols::border,
    widgets::{block::*, *},
};
use crate::api::{Command, Datapoint};
use crate::gui::tui;
use crate::gui::tui::restore;


pub enum LogType {
    Info,
    Warning,
    Error,
    Success,
}
/// This struct holds everything the TUI needs
/// this includes:
/// - communication channels
/// - vectors of datapoints, specifically one for each graph that we display
///                                                 (NOT Vec<Datapoint>, this means nothing!!)
/// - vector of TCP messages that we display
pub struct App {
    pub logs: Vec<(LogType, String)>,
    pub tx: Sender<Command>,
    pub rx: Receiver<Datapoint>,
    pub safety_score: Vec<(f64,f64)>,
    pub unsafety_score: Vec<(f64,f64)>,
    pub battery_voltages: Vec<(String,u64)>,
    pub exit: bool,
    pub scroll: u16,
    pub time_elapsed: u64,
    pub selected: usize,
}


pub fn gui_main(tx : Sender<Command>, rx: Receiver<Datapoint>) -> io::Result<()> {
    // set_panic_hook(); // custom panic hook to restore the terminal before panicking

    let mut terminal = tui::init()?; // initialise the crossterm magic
    let app_result = App::new(tx, rx).run(&mut terminal);
    restore()?; // restore the terminal, it gets messed up after the TUI
    app_result // if error, pass along, if ok, also pass along but do nothing about it
}

/// fn set_panic_hook() sets a custom panic hook that pauses for a moment to restore the terminal
/// before continuing to panic like normal.
fn set_panic_hook() {
    std::env::set_var("RUST_BACKTRACE", "1");
    std::panic::set_hook(Box::new(|panic_info| {
        // Attempt to call restore. Since restore() returns a Result,
        if let Err(e) = restore() {
            // Log the error, print it out, or handle it as necessary
            println!("Failed to restore terminal state: {:?}", e);
        }
        // Print panic info message if available
        if let Some(location) = panic_info.location() {
            println!("Panic occurred in file '{}' at line {}", location.file(), location.line());
        } else {
            println!("Panic occurred but can't get location information...");
        }
        // Capture and print the stack trace
        let backtrace = Backtrace::capture();
        println!("Stack trace:\n{:?}", backtrace);
    }));
}

