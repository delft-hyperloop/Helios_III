use ratatui::{
    prelude::*,
    symbols::border,
    widgets::{block::*, *},
};
use crate::api::Message;
use crate::tui::app::App;
use crate::tui::timestamp;

fn border_select(app: &App, idx: usize) -> Color {
    match app.selected == idx {
        true => Color::Cyan,
        false => Color::Blue
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
                    Constraint::Percentage(65), // left half for text stream
                    Constraint::Percentage(35), // right half for table and data out
                ]
                    .as_ref(),
            )
            .split(inner_area);

        // Split the top half horizontally for text stream and plots
        // let right_chunks = Layout::default()
        //     .direction(Direction::Vertical)
        //     .constraints(
        //         [
        //             Constraint::Percentage(50), // top side for text stream
        //             Constraint::Percentage(50), // bottom side for the table
        //         ]
        //             .as_ref(),
        //     )
        //     .split(main_chunks[1]);

        let text_block = Block::default().title("Text Stream")
            .title_style(Style::default().fg(Color::LightBlue).bold()) // Styling the title
            .border_style(Style::default().fg(border_select(self, 0)))
            .borders(Borders::ALL);

        // Create the text stream
        let styled_logs: Vec<Line> = self.logs.iter().map(|(msg, t)| {
            match msg {
                Message::Data(d) => Line::styled(format!("[{}] {:?}={} at {}", timestamp(), d.datatype, d.value, d.timestamp), Style::default().fg(Color::White)),
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

        // Create the table block

    }
}