use ratatui::{
    prelude::*,
    symbols::border,
    widgets::{block::*, *},
};
use crate::api::Message;
use crate::tui::app::App;
use crate::tui::timestamp;

fn border_select(app: &App, idx: usize) -> Color {
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
                    Constraint::Percentage(50), // top side for text stream
                    Constraint::Percentage(50), // bottom side for the table
                ]
                    .as_ref(),
            )
            .split(main_chunks[1]);

        let text_block = Block::default().title("Text Stream")
            .title_style(Style::default().fg(Color::LightBlue).bold()) // Styling the title
            .border_style(Style::default().fg(Color::Blue))
            .borders(Borders::ALL);

        // Create the text stream
        let styled_logs: Vec<Line> = self.logs.iter().map(|(msg, t)| {
            match msg {
                Message::Data(d) => Line::styled(format!("[{}] {:?}={} at {}", t, d.datatype, d.value, d.timestamp), Style::default().bg(Color::Cyan)),
                Message::Status(s) => Line::styled(format!("[{}] {:?}", t, s), Style::default().fg(s.colour())),
                Message::Info(x) => Line::styled(format!("[{}] {}", t, x), Style::default().fg(Color::White)),
                Message::Warning(x) => Line::styled(format!("[{}] {}", t, x), Style::default().fg(Color::Yellow)),
                Message::Error(x) => Line::styled(format!("[{}] {}", t, x), Style::default().fg(Color::Red)),
            }
        }).collect();
        // Render the text stream
        let paragraph = Paragraph::new(styled_logs)
            .wrap(Wrap { trim: false })
            .scroll((self.scroll, 0))
            .style(Style::new().fg(Color::White).bg(Color::Black))
            .block(text_block);
        // text stream goes top left
        paragraph.render(main_chunks[0], buf);

        let values = vec![
            self.cmd_values[0].to_string(),
            self.cmd_values[1].to_string(),
            self.cmd_values[2].to_string(),
            self.cmd_values[3].to_string(),
            self.cmd_values[4].to_string(),
            self.cmd_values[5].to_string(),
            self.cmd_values[6].to_string(),
            self.cmd_values[7].to_string(),
            self.cmd_values[8].to_string(),
            self.cmd_values[9].to_string(),
        ];

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
        let rows = vec![
            Row::new(vec!["Command", "Value"])
                .style(Style::default().fg(Color::Blue).bg(Color::Black).add_modifier(Modifier::BOLD)),
            Row::new(vec!["DefaultCommand", &values[0]])
                .style(Style::default().bg(Color::Black).fg(border_select(self, 0))),
            Row::new(vec!["Levitate", &values[1]])
                .style(Style::default().bg(Color::Black).fg(border_select(self, 1))),
            Row::new(vec!["StopLevitating", &values[2]])
                .style(Style::default().bg(Color::Black).fg(border_select(self, 2))),
            Row::new(vec!["Configure", &values[3]])
                .style(Style::default().bg(Color::Black).fg(border_select(self, 3))),
            Row::new(vec!["StartRun", &values[4]])
                .style(Style::default().bg(Color::Black).fg(border_select(self, 4))),
            Row::new(vec!["EmergencyBrake", &values[5]])
                .style(Style::default().bg(Color::Black).fg(border_select(self, 5))),
            Row::new(vec!["Shutdown", &values[6]])
                .style(Style::default().bg(Color::Black).fg(border_select(self, 6))),
            Row::new(vec!["StartHV", &values[7]])
                .style(Style::default().bg(Color::Black).fg(border_select(self, 7))),
            Row::new(vec!["StopHV", &values[8]])
                .style(Style::default().bg(Color::Black).fg(border_select(self, 8))),
            Row::new(vec!["EmitEvent", &values[9]])
                .style(Style::default().bg(Color::Black).fg(border_select(self, 9))),
        ];

        let table = Table::new(rows, vec![Constraint::Fill(1), Constraint::Length(10)])
            .block(Block::default().borders(Borders::ALL).title(Title::from("Commands Panel".light_blue().bold()))
                .border_style(Style::default().fg(Color::Blue)));

        // Render the table
        ratatui::widgets::Widget::render(table, right_chunks[0], buf);

        // A paragraph to display data (bottom right)
        let data_block = Block::default().title("Other Info")
            .title_style(Style::default().fg(Color::LightBlue).bold()) // Styling the title
            .border_style(Style::default().fg(Color::Blue))
            .borders(Borders::ALL);

        let data = vec![
            Line::styled(format!("Current State: {}", self.cur_state), Style::default().fg(Color::White).bg(Color::Blue)),
            Line::styled(format!("Selected Row: {}", self.selected_row), Style::default().fg(Color::White)),

        ];

        let data_paragraph = Paragraph::new(data)
            .wrap(Wrap { trim: false })
            .style(Style::new().fg(Color::White).bg(Color::Black))
            .block(data_block);
        data_paragraph.render(right_chunks[1], buf);
    }
}
