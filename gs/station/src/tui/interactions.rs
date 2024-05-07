use std::cmp::min;
use crate::tui::app::App;
use crossterm::event::{self, Event, KeyCode, KeyEvent, KeyEventKind};
use crate::Command::EmergencyBrake;

impl App {
    /// updates the application's state based on user input
    pub(crate) fn handle_events(&mut self) {
        match event::poll(std::time::Duration::from_micros(500)) {
            Ok(true) => {
                match event::read().unwrap() {
                    // it's important to check that the event is a key press event as
                    // crossterm also emits key release and repeat events on Windows.
                    Event::Key(key_event) if key_event.kind == KeyEventKind::Press => {
                        self.handle_key_event(key_event);
                    }
                    _ => {}
                }
            }
            Ok(false) => {} // no event exists
            Err(e) => {eprintln!("error processing events?? {:?}", e)} // error reading event
        };
    }

    fn scroll_up(&mut self, val: u16) {
        self.scroll = self.scroll.saturating_sub(val);
    }
    fn scroll_down(&mut self, val: u16) {
        self.scroll = min(self.scroll.saturating_add(val), 2 * self.logs.len() as u16);
    }

    /// Keyboard shortcuts!
    fn handle_key_event(&mut self, key_event: KeyEvent) {
        match key_event.code {
            KeyCode::Char('q') => self.exit(),
            KeyCode::Esc => self.send_command(EmergencyBrake(0)),
            KeyCode::Up => self.scroll_up(1),
            KeyCode::Down => self.scroll_down(1),
            KeyCode::Char('k') | KeyCode::Char('j') => self.scroll_down(10),
            KeyCode::Char('m') => self.scroll_down(10000),
            KeyCode::Char('u') => self.scroll_up(10000),
            KeyCode::Char('i') => self.scroll_up(10),
            KeyCode::Char('s') => self.launch_station(),
            // KeyCode::Char('t') => self.logs.push((LogType::Warning, format!("{}:  this is a testing goose",Util::Now()).parse().unwrap())),
            // KeyCode::Tab => {
            //     self.selected = (self.selected + 1) % 4;
            // }
            // KeyCode::BackTab => {
            //     self.selected = (self.selected + 3) % 4;
            // }
            _ => {}
        }
    }
}