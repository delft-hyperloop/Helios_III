mod app;
mod interactions;
mod render;

use std::io::stdout;
use std::io::Stdout;
use std::io::{self};

use crossterm::execute;
use crossterm::terminal::*;
use ratatui::prelude::*;

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

pub fn tui_main(backend: crate::Backend) {
    let mut terminal = init().unwrap(); // initialise the crossterm magic
    App::new(backend).run(&mut terminal).unwrap();
    restore().unwrap(); // restore the terminal, it gets messed up after the TUI
}

#[inline]
pub fn timestamp() -> String { chrono::offset::Local::now().format("%H:%M:%S.%3f").to_string() }
