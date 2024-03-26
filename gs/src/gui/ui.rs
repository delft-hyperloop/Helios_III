use std::io;
use ratatui::Frame;
use crossterm::event::{self, Event, KeyCode, KeyEvent, KeyEventKind};
use ratatui::{
    prelude::*,
    symbols::border,
    widgets::{block::*, *},
};
use crate::api::{Command, Datapoint};
use crate::api::Command::{EmergencyBrake, Levitate};
use crate::api::Datapoint::{Error, SafetyScore, Status};
use crate::gui::main::{App, LogType};
use crate::gui::tui;
use crate::util::Util;

impl App {
    /// runs the application's main loop until the user quits
    pub fn run(&mut self, terminal: &mut tui::Tui) -> io::Result<()> {
        while !self.exit {
            terminal.draw(|frame| self.render_frame(frame))?;
            self.handle_events();
            self.receive_data();
        }
        Ok(())
    }

    fn receive_data(&mut self) {
        match self.rx.try_recv() {
            Ok(datapoint) => match datapoint {
                SafetyScore(score) => {
                    self.safety_score.push((Util::Instant(), score));
                }
                Datapoint::Status(msg) => {
                    self.logs.push((LogType::Info, msg));
                }
                Datapoint::Error(msg) => {
                    self.logs.push((LogType::Error, msg));
                }
                Datapoint::Info(msg) => {
                    self.logs.push((LogType::Success, msg));
                }
                _ => {}
            }
            Err(_) => {}
        }
    }

    fn render_frame(&self, frame: &mut Frame) {
        frame.render_widget(self, frame.size());
    }

    /// updates the application's state based on user input
    fn handle_events(&mut self) {
        match event::poll(std::time::Duration::from_millis(200)) {
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

    fn send_command(&mut self, command: Command) {
        self.tx.send(command).unwrap();
    }

    fn handle_key_event(&mut self, key_event: KeyEvent) {
        match key_event.code {
            KeyCode::Char('q') => self.exit(),
            KeyCode::Esc => self.send_command(EmergencyBrake),
            KeyCode::Char('w') => self.send_command(Levitate),
            _ => {}
        }
    }
}

impl Widget for &App {
    fn render(self, area: Rect, buf: &mut Buffer) {
        // Outer block with titles and instructions
        let title = Title::from(" Goose™ Ground Station ultimate ".bold());
        let instructions = Title::from(Line::from(vec![
            " Levitate ".into(),
            "<W>".blue().bold(),
            " Emergency Brake ".into(),
            "<Esc>".red().bold(),
            " Quit ".into(),
            "<Q> ".blue().bold(),
        ]));
        let outer_block = Block::default()
            .title(title.alignment(Alignment::Center))
            .title(
                instructions
                    .alignment(Alignment::Center)
                    .position(Position::Bottom),
            )
            .borders(Borders::ALL)
            .border_set(border::THICK);

        // Calculate inner area by subtracting the border
        let inner_area = outer_block.inner(area);

        outer_block.render(area, buf);

        // Split the inner area into two halves
        let layout = Layout::default()
            .direction(Direction::Horizontal)
            .constraints([Constraint::Percentage(40), Constraint::Percentage(60)].as_ref())
            .split(inner_area);

        // Render the text stream in the left half
        let text_block = Block::default().title("Text Stream")
            .title_style(Style::default().fg(Color::Cyan).bold()) // Styling the title
            .border_style(Style::default().fg(Color::Cyan))
            .borders(Borders::ALL);
        let styled_logs: Vec<Line> = self.logs.iter().map(|(level, message)| {
            let color = match *level {
                LogType::Error => Color::LightRed,
                LogType::Warning => Color::Yellow,
                LogType::Info => Color::White,
                LogType::Success => Color::Green,
                // _ => Color::White, // Default color
            };
            Line::styled(message, Style::default().fg(color))
        }).collect();
        // let text = Text::from(styled_logs);
        let paragraph = Paragraph::new(styled_logs)
            .style(Style::new().fg(Color::White).bg(Color::Black))
            .block(text_block);
        paragraph.render(layout[0], buf);

        // Render the line graph in the right half
        let datasets = vec![
            Dataset::default()
                .name("safety score")
                .marker(Marker::Dot)
                .style(Style::default().cyan())
                .data(&self.safety_score)
        ];

        // Create the X axis and define its properties
        let x_axis = Axis::default()
            .title("time".red())
            .style(Style::default().white())
            .bounds([0.0, 10.0])
            .labels(vec!["0.0".into(), "5.0".into(), "10.0".into()]);

        // Create the Y axis and define its properties
        let y_axis = Axis::default()
            .title("daan".red())
            .style(Style::default().white())
            .bounds([0.0, 10.0])
            .labels(vec!["0.0".into(), "5.0".into(), "10.0".into()]);

        // Create the chart and link all the parts together
        let chart = Chart::new(datasets)
            .block(Block::default().title("Chart"))
            .x_axis(x_axis)
            .y_axis(y_axis);
        chart.render(layout[1], buf);
    }
}