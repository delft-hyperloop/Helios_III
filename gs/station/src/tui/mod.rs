mod app;
mod render;
mod interactions;

use std::io::{self, stdout, Stdout};
use std::sync::mpsc::{Receiver, Sender};

use crossterm::{execute, terminal::*};
use ratatui::prelude::*;
use crate::api::{ApiStruct, Message};
use crate::{Command};
use crate::connect::Datapoint;
use crate::tui::app::App;

/// A type alias for the terminal type used in this application
pub type Tui = Terminal<CrosstermBackend<Stdout>>;

/// Initialize the terminal
pub fn init() -> io::Result<Tui> {
    execute!(stdout(), EnterAlternateScreen)?;
    enable_raw_mode()?;
    Terminal::new(CrosstermBackend::new(stdout()))
}

/// Restore the terminal to its original state
pub fn restore() -> io::Result<()> {
    execute!(stdout(), LeaveAlternateScreen)?;
    disable_raw_mode()?;
    Ok(())
}

pub fn gui_main() -> io::Result<()> {
    let mut terminal = init()?; // initialise the crossterm magic
    let app_result = App::new().run(&mut terminal);
    restore()?; // restore the terminal, it gets messed up after the TUI
    app_result // if error, pass along, if ok, also pass along but do nothing about it
}

#[inline]
pub fn timestamp() -> String {
    chrono::offset::Local::now().format("%H:%M:%S.%3f").to_string()
}