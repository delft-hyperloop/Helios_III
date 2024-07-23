use std::cmp::min;

use crossterm::event::Event;
use crossterm::event::KeyCode;
use crossterm::event::KeyEvent;
use crossterm::event::KeyEventKind;
use crossterm::event::{self};

use crate::tui::app::App;
use crate::tui::timestamp;
use crate::Command;

impl App {
    /// updates the application's state based on user input
    pub(crate) fn handle_events(&mut self) -> anyhow::Result<()> {
        match event::poll(std::time::Duration::from_micros(500)) {
            Ok(true) => {
                match event::read()? {
                    // it's important to check that the event is a key press event as
                    // crossterm also emits key release and repeat events on Windows.
                    Event::Key(key_event) if key_event.kind == KeyEventKind::Press => {
                        self.handle_key_event(key_event);
                    },
                    _ => {},
                }
            },
            Ok(false) => {}, // no event exists
            Err(e) => {
                eprintln!("error processing events?? {:?}", e)
            }, // error reading event
        };
        Ok(())
    }

    fn scroll_up(&mut self, val: u16) { self.scroll = self.scroll.saturating_sub(val); }

    fn scroll_down(&mut self, val: u16) {
        self.scroll = min(self.scroll.saturating_add(val), self.logs.len() as u16 + 1);
    }

    /// Keyboard shortcuts!
    fn handle_key_event(&mut self, key_event: KeyEvent) {
        match key_event.code {
            KeyCode::Char('q') => self.quit(),
            KeyCode::Esc => {
                self.backend.send_command(crate::Command::EmergencyBrake(0));
            },
            KeyCode::Up => self.scroll_up(1),
            KeyCode::Down => self.scroll_down(1),
            KeyCode::Char('j') => self.scroll_down(10),
            KeyCode::Char('h') => self.scroll_down(10000),
            KeyCode::Char('l') => self.scroll_up(10000),
            KeyCode::Char('k') => self.scroll_up(10),
            KeyCode::Char('s') => {
                self.backend.start_server();
            },
            KeyCode::Char('a') => {
                self.backend.quit_server();
            },
            KeyCode::Char('o') => self.backend.start_levi(),
            KeyCode::Char('i') => self.backend.quit_levi(),
            // KeyCode::Char('t') => self.logs.push((LogType::Warning, format!("{}:  this is a testing goose",Util::Now()).parse()?)),
            KeyCode::Tab => {
                self.selected_row = (self.selected_row + 1) % self.cmds.len();
            },
            KeyCode::BackTab => {
                self.selected_row = (self.selected_row + self.cmds.len() - 1) % self.cmds.len();
            },
            KeyCode::Enter => {
                self.backend.send_command(self.cmds[self.selected_row].as_cmd());
                self.backend.warn(format!("interpreting {:?}", self.cmds[self.selected_row]));
            },
            KeyCode::Char('1') => {
                self.cmds[self.selected_row].value = self.cmds[self.selected_row].value * 10 + 1;
            },
            KeyCode::Char('2') => {
                self.cmds[self.selected_row].value = self.cmds[self.selected_row].value * 10 + 2;
            },
            KeyCode::Char('3') => {
                self.cmds[self.selected_row].value = self.cmds[self.selected_row].value * 10 + 3;
            },
            KeyCode::Char('4') => {
                self.cmds[self.selected_row].value = self.cmds[self.selected_row].value * 10 + 4;
            },
            KeyCode::Char('5') => {
                self.cmds[self.selected_row].value = self.cmds[self.selected_row].value * 10 + 5;
            },
            KeyCode::Char('6') => {
                self.cmds[self.selected_row].value = self.cmds[self.selected_row].value * 10 + 6;
            },
            KeyCode::Char('7') => {
                self.cmds[self.selected_row].value = self.cmds[self.selected_row].value * 10 + 7;
            },
            KeyCode::Char('8') => {
                self.cmds[self.selected_row].value = self.cmds[self.selected_row].value * 10 + 8;
            },
            KeyCode::Char('9') => {
                self.cmds[self.selected_row].value = self.cmds[self.selected_row].value * 10 + 9;
            },
            KeyCode::Char('0') => {
                self.cmds[self.selected_row].value *= 10;
            },
            KeyCode::Backspace => {
                self.cmds[self.selected_row].value /= 10;
            },
            KeyCode::Char('p') => {
                self.backend.send_command(Command::SetRoute(1822648539875311616));
                self.backend.send_command(Command::SetSpeeds(14106055789030410752));
            },
            // KeyCode::Char('o') => {
            //     self.backend.send_command(Command::SetRoute(8328165916070586159));
            //     self.backend.send_command(Command::SetSpeeds(46542390612732));
            // },
            KeyCode::Char('w') => {
                self.logs.push((self.backend.save().unwrap(), timestamp()));
            },
            _ => {},
        }
    }
}
