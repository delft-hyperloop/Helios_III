use crate::api::Message;
use crate::tui::app::App;
use crate::Command;
use ratatui::{
    prelude::*,
    symbols::border,
    widgets::{block::*, *},
};

#[derive(Debug)]
pub struct CmdRow {
    pub name: String,
    pub value: u64,
}

impl CmdRow {
    pub fn to_row(&self) -> ratatui::widgets::Row {
        ratatui::widgets::Row::new(vec![self.name.clone(), self.value.to_string()])
    }
    pub fn as_cmd(&self) -> Command {
        Command::from_string(&self.name.trim(), self.value)
    }
}

pub(crate) fn border_select(app: &App, idx: usize) -> Color {
    match app.selected_row == idx {
        true => Color::LightGreen,
        false => Color::LightCyan,
    }
}

impl Widget for &App {
    fn render(self, area: Rect, buf: &mut Buffer) {
        let title = Title::from(" Goose™ Ground Station ultimate ".light_green().bold());
        let instructions = Title::from(Line::from(vec![
            "Scroll Up".light_blue().into(),
            " <I> ".light_cyan().bold(),
            " –– ".blue().into(),
            "Scroll Down".light_blue().into(),
            " <J> ".light_cyan().bold(),
            " –– ".blue().into(),
            "Scroll to End".light_blue().into(),
            " <M, U> ".light_cyan().bold(),
            " –– ".blue().into(),
            "Emergency Brake".red().into(),
            " <Esc> ".light_red().bold(),
            " –– ".blue().into(),
            "Launch Station".light_green().into(),
            " <S> ".light_green().bold(),
            " –– ".blue().into(),
            "Quit".magenta().into(),
            " <Q> ".light_magenta().bold(),
            " ––––––– ".blue().into(),
            "timestamp: ".light_blue().into(),
            format!(" <{}> ", self.time_elapsed).light_blue().into(),
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
            .direction(Direction::Horizontal)
            .constraints(
                [
                    Constraint::Percentage(58), // left half for text stream
                    Constraint::Percentage(42), // right half for table and data out
                ]
                .as_ref(),
            )
            .split(inner_area);

        // Split the top half horizontally for text stream and info paragraph
        let right_chunks = Layout::default()
            .direction(Direction::Vertical)
            .constraints(
                [
                    Constraint::Percentage(65), // top side for text stream
                    Constraint::Percentage(35), // bottom side for the table
                ]
                .as_ref(),
            )
            .split(main_chunks[1]);

        let text_block = Block::default()
            .title("Text Stream")
            .title_style(Style::default().fg(Color::LightBlue).bold()) // Styling the title
            .border_style(Style::default().fg(Color::Blue))
            .borders(Borders::ALL);

        // Create the text stream
        let styled_logs: Vec<Line> = self
            .logs
            .iter()
            .map(|(msg, t)| match msg {
                Message::Data(d) => Line::styled(
                    format!("[{}] {:?}={} at {}", t, d.datatype, d.value, d.timestamp),
                    Style::default().bg(Color::Cyan),
                ),
                Message::Status(s) => {
                    Line::styled(format!("[{}] {:?}", t, s), Style::default().fg(s.colour()))
                }
                Message::Info(x) => Line::styled(format!("[{}] {}", t, x), {
                    if x.contains("[TRACE]") {
                        Style::default().fg(Color::Gray)
                    } else {
                        Style::default().fg(Color::White)
                    }
                }),
                Message::Warning(x) => {
                    Line::styled(format!("[{}] {}", t, x), Style::default().fg(Color::Yellow))
                }
                Message::Error(x) => {
                    Line::styled(format!("[{}] {}", t, x), Style::default().fg(Color::Red))
                }
            })
            .collect();
        // Render the text stream
        let paragraph = Paragraph::new(styled_logs)
            .wrap(Wrap { trim: false })
            .scroll((self.scroll, 0))
            .style(Style::new().fg(Color::White).bg(Color::Black))
            .block(text_block);
        // text stream goes top left
        paragraph.render(main_chunks[0], buf);

        /*
        pub enum Command {
            DefaultCommand(u64),
            Levitate(u64),
            StopLevitating(u64),
            Configure(u64),
            StartRun(u64),
            EmergencyBrake(u64),
            Shutdown(u64),
            StartHV(u64),
            StopHV(u64),
            EmitEvent(u64),
        }*/

        // Create the table block
        let mut rows = vec![Row::new(vec!["Command", "Value"]).style(
            Style::default()
                .fg(Color::Blue)
                .bg(Color::Black)
                .add_modifier(Modifier::BOLD),
        )];
        self.cmds.iter().enumerate().for_each(|(i, x)| {
            rows.push(
                x.to_row()
                    .style(Style::default().bg(Color::Black).fg(border_select(self, i))),
            )
        });

        let table = Table::new(rows, vec![Constraint::Fill(1), Constraint::Length(10)]).block(
            Block::default()
                .borders(Borders::ALL)
                .title(Title::from("Commands Panel".light_blue().bold()))
                .border_style(Style::default().fg(Color::Blue)),
        );

        // Render the table
        ratatui::widgets::Widget::render(table, right_chunks[0], buf);

        // A paragraph to display data (bottom right)
        let data_block = Block::default()
            .title("Other Info")
            .title_style(Style::default().fg(Color::LightBlue).bold()) // Styling the title
            .border_style(Style::default().fg(Color::Blue))
            .borders(Borders::ALL);

        let mut data = vec![
            Line::styled(
                format!("Current State: {}", self.cur_state),
                Style::default().fg(Color::White).bg(Color::Blue),
            ),
            Line::styled(
                format!("Selected Row: {}", self.selected_row),
                Style::default().fg(Color::White),
            ),
            Line::styled(
                format!("Last heartbeat: {}", self.last_heartbeat),
                Style::default().fg(Color::White),
            ),
            Line::styled(
                format!("Lines printed: {}", self.logs.len()),
                Style::default().fg(Color::White),
            ),
            Line::styled(
                "Powertrain data:",
                Style::default().fg(Color::White).bg(Color::Blue),
            ),
        ];
        for (k, v) in &self.special_data {
            data.push(
                Line::styled(
                    format!("{:?}: {}", k, v),
                    Style::default().fg(Color::White),
                )
            );
        }

        let data_paragraph = Paragraph::new(data)
            .wrap(Wrap { trim: false })
            .style(Style::new().fg(Color::White).bg(Color::Black))
            .block(data_block);
        data_paragraph.render(right_chunks[1], buf);
    }
}
