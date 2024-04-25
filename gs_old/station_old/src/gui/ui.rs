use std::cmp::{max, min};
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
use ratatui::widgets::calendar::{CalendarEventStore, Monthly};
use time::Date;

impl App {
    /// runs the application's main loop until the user quits
    pub fn run(&mut self, terminal: &mut tui::Tui) -> io::Result<()> {
        while !self.exit {
            terminal.draw(|frame| self.render_frame(frame))?;
            self.handle_events();
            self.receive_data();
            self.time_elapsed = self.time_elapsed.wrapping_add(1);
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
                    self.logs.push((LogType::Info, format!("{}{}{}",Util::Now(),":  ", msg).parse().unwrap()));
                }
                Datapoint::Error(msg) => {
                    self.logs.push((LogType::Error, format!("{}{}{}",Util::Now(),":  ", msg).parse().unwrap()));
                }
                Datapoint::Info(msg) => {
                    self.logs.push((LogType::Success, format!("{}{}{}",Util::Now(),":  ", msg).parse().unwrap()));
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

    fn send_command(&mut self, command: Command) {
        self.tx.send(command).unwrap();
    }

    fn scroll_up(&mut self, val: u16) {
        self.scroll = self.scroll.saturating_sub(val);
    }
    fn scroll_down(&mut self, val: u16) {
        self.scroll = min(self.scroll.saturating_add(val), self.logs.len() as u16 - 1u16);
    }

    fn handle_key_event(&mut self, key_event: KeyEvent) {
        match key_event.code {
            KeyCode::Char('q') => self.exit(),
            KeyCode::Esc => self.send_command(EmergencyBrake),
            KeyCode::Char('w') => self.send_command(Levitate),
            KeyCode::Up => self.scroll_up(1),
            KeyCode::Down => self.scroll_down(1),
            KeyCode::Char('k') | KeyCode::Char('j') => self.scroll_down(10),
            KeyCode::Char('m') => self.scroll_down(10000),
            KeyCode::Char('u') => self.scroll_up(10000),
            KeyCode::Char('i') => self.scroll_up(10),
            KeyCode::Char('t') => self.logs.push((LogType::Warning, format!("{}:  this is a testing goose",Util::Now()).parse().unwrap())),
            KeyCode::Tab => {
                self.selected = (self.selected + 1) % 4;
            }
            KeyCode::BackTab => {
                self.selected = (self.selected + 3) % 4;
            }
            _ => {}
        }
    }
}

fn border_select(app: &App, idx: usize) -> Color {
    match app.selected == idx {
        true => Color::Cyan,
        false => Color::Blue
    }
}

impl Widget for &App {
    fn render(self, area: Rect, buf: &mut Buffer) {
        // Outer block with titles and instructions
        let title = Title::from(" Goose™ Ground Station ultimate ".light_green().bold());
        let instructions = Title::from(Line::from(vec![
            " Levitate ".light_blue().into(),
            "<W>".light_cyan().bold(),
            " Emergency Brake ".red().into(),
            "<Esc>".light_red().bold(),
            " Quit ".magenta().into(),
            "<Q> ".light_magenta().bold(),
        ]));
        let outer_block = Block::default()
            .title(title.alignment(Alignment::Center))
            .title(
                instructions
                    .alignment(Alignment::Center)
                    .position(Position::Bottom),
            )
            .borders(Borders::ALL)
            .style(Style::default().fg(Color::Blue).bg(Color::Black))
            .border_set(border::THICK);

        // Calculate inner area by subtracting the border
        let inner_area = outer_block.inner(area);
        outer_block.render(area, buf);

        // Create the main layout with two rows
        let main_chunks = Layout::default()
            .direction(Direction::Vertical)
            .constraints(
                [
                    Constraint::Percentage(75), // Top half for text stream and scatter plot
                    Constraint::Percentage(25), // Bottom half for bar graph and line graph
                ]
                    .as_ref(),
            )
            .split(inner_area);

        // Split the top half horizontally for text stream and plots
        let top_chunks = Layout::default()
            .direction(Direction::Horizontal)
            .constraints(
                [
                    Constraint::Percentage(50), // Left side for text stream
                    Constraint::Percentage(50), // Right side for the plots
                ]
                    .as_ref(),
            )
            .split(main_chunks[0]);

        let right_chunks = Layout::default()
            .direction(Direction::Vertical)
            .constraints(
                [
                    Constraint::Percentage(50), // Top half for the scatter plot
                    Constraint::Percentage(50), // Bottom half for the line graph
                ]
                    .as_ref(),
            )
            .split(top_chunks[1]);

        let right_pair = Layout::default()
            .direction(Direction::Horizontal)
            .constraints([Constraint::Percentage(30),Constraint::Percentage(70), ].as_ref(),)
            .split(right_chunks[1]);

        let text_block = Block::default().title("Text Stream")
            .title_style(Style::default().fg(Color::LightBlue).bold()) // Styling the title
            .border_style(Style::default().fg(border_select(self, 0)))
            .borders(Borders::ALL);

        // Create the text stream
        let styled_logs: Vec<Line> = self.logs.iter().map(|(level, message)| {
            let color = match *level {
                LogType::Error => Color::LightRed,
                LogType::Warning => Color::LightYellow,
                LogType::Info => Color::White,
                LogType::Success => Color::Green,
                // _ => Color::White, // Default color
            };
            Line::styled(message, Style::default().fg(color))
        }).collect();
        // Render the text stream
        let paragraph = Paragraph::new(styled_logs)
            .wrap(Wrap { trim: false })
            .scroll((self.scroll, 0))
            .style(Style::new().fg(Color::White).bg(Color::Black))
            .block(text_block);
        // text stream goes in top left
        paragraph.render(top_chunks[0], buf);

        // Create the scatter plot
        // 1. data set
        let datasets = vec![
            Dataset::default()
                .name("safety score")
                .marker(Marker::Dot)
                .style(Style::default().cyan())
                .data(&self.safety_score),
            Dataset::default()
                .name("unsafety score")
                .marker(Marker::Dot)
                .style(Style::default().light_yellow())
                .data(&self.unsafety_score)
        ];
        // 2. Create the X axis and define its properties
        let x_axis = Axis::default()
            .title("time".light_magenta())
            .style(Style::default().light_magenta())
            .bounds([0.0, 10.0])
            .labels(vec!["0.0".into(), "5.0".into(), "10.0".into()]);

        // 3. Create the Y axis and define its properties
        let y_axis = Axis::default()
            .title("daan".light_magenta())
            .style(Style::default().light_magenta())
            .bounds([0.0, 10.0])
            .labels(vec!["0.0".into(), "5.0".into(), "10.0".into()]);

        // 4. Create the chart and link all the parts together
        let chart = Chart::new(datasets)
            .block(Block::default()
                .title("Safety Officer".light_blue().bold())
                .borders(Borders::ALL).border_style(Style::default().fg(border_select(self, 1))
            ))
            .x_axis(x_axis)
            .y_axis(y_axis);
        chart.render(right_chunks[0], buf);


        // second graph on the right side

        // calendar (left)
        let mut ds = CalendarEventStore::default();
        ds.add(Date::from_calendar_date(2024, time::Month::April, 1).unwrap(), Style::default().bg(Color::Red));
        ds.add(Date::from_calendar_date(2024, time::Month::April, 4).unwrap(), Style::default().fg(Color::LightBlue));
        (15..=19).for_each(|i| ds.add(Date::from_calendar_date(2024, time::Month::April, i).unwrap(), Style::default().fg(Color::LightRed)));
        let calendar = Monthly::new(Date::from_calendar_date(2024, time::Month::April, 1).unwrap(), ds)
            .default_style(Style::default().fg(Color::White).bg(Color::Black))
            .show_weekdays_header(Style::default().bg(Color::Black).fg(Color::LightBlue))
            .show_month_header(Style::default().bg(Color::Blue).fg(Color::White))
            .block(Block::default().title("SenseCon Plan".light_blue()).borders(Borders::ALL).border_style(Style::default().fg(border_select(self, 2))));

        calendar.render(right_pair[0], buf);


        // Make a table




        // bar chart for the bottom of the page:
        // 1. convert the dataset
        let mut bv: [(&str, u64); 39] = [("B1", 0); 39];
        let nv = App::battery_voltages(self.time_elapsed);
        for i in 0..39 {
            bv[i] = (&nv[i].0, nv[i].1);
        }
        let bar_chart = BarChart::default()
            .block(Block::default().title("Battery Voltage Levels".light_blue().bold()).borders(Borders::ALL).border_style(Style::default().fg(border_select(self, 3)))
            )
            .data(&bv)
            .max(100)
            // .data(BarGroup::default().bars(&[Bar::default().value(10), Bar::default().value(20)]))
            .bar_width(4)
            .bar_gap(0)
            .bar_style(Style::default().fg(Color::Yellow))
            .value_style(Style::default().bg(Color::Black).fg(Color::White));

        // render the chart on the bottom of the page
        bar_chart.render(main_chunks[1], buf);
    }
}
/*
// Render the text stream in the left half
        let text_block = Block::default().title("Text Stream")
            .title_style(Style::default().fg(Color::LightBlue).bold()) // Styling the title
            .border_style(Style::default().fg(Color::Cyan))
            .borders(Borders::ALL);
        let styled_logs: Vec<Line> = self.logs.iter().map(|(level, message)| {
            let color = match *level {
                LogType::Error => Color::LightRed,
                LogType::Warning => Color::LightYellow,
                LogType::Info => Color::White,
                LogType::Success => Color::Green,
                // _ => Color::White, // Default color
            };
            Line::styled(message, Style::default().fg(color))
        }).collect();
        // let text = Text::from(styled_logs);
        let paragraph = Paragraph::new(styled_logs)
            .wrap(Wrap { trim: false })
            .scroll((self.scroll, 0))
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
*/