use std::io;
use std::sync::mpsc::{Receiver, Sender, TryRecvError};
use ratatui::Frame;
use crate::api::{ApiStruct, Message};
use crate::Command;
use crate::connect::{Datapoint, Station};
use crate::tui::{timestamp, Tui};

pub struct App {
    pub logs: Vec<(Message, String)>,
    pub data: Vec<Datapoint>,
    pub exit: bool,
    pub scroll: u16,
    pub time_elapsed: u64,
    pub selected: usize,
    message_sender: Option<Sender<Message>>,
    message_receiver: Option<Receiver<Message>>,
    command_sender: Option<Sender<Command>>,
    command_receiver: Option<Receiver<Command>>,
    pub station_running: bool,
}

impl App {
    pub fn new() -> Self {
        Self {
            logs: vec![],
            data: vec![],
            exit: false,
            scroll: 0,
            time_elapsed: 0,
            selected: 0,
            message_sender: None,
            message_receiver: None,
            command_sender: None,
            command_receiver: None,
            station_running: false,
        }
    }

    pub fn launch_station(&mut self) {
        if self.station_running {
            return;
        }
        let (data_sender, data_receiver) = std::sync::mpsc::channel();
        let (command_sender, command_receiver) = std::sync::mpsc::channel();
        data_sender.send(Message::Info("Station started".to_string())).unwrap();
        self.message_receiver = Some(data_receiver);
        self.command_sender = Some(command_sender);
        self.station_running = true;
        std::thread::spawn(move ||
            Station::new().launch(data_sender, command_receiver)
        );
    }

    pub fn run(&mut self, terminal: &mut Tui) -> io::Result<()> {
        while !self.exit {
            terminal.draw(|frame| self.render_frame(frame))?;
            self.handle_events();
            self.receive_data()?;
            self.time_elapsed = self.time_elapsed.wrapping_add(1);
        }
        Ok(())
    }

    fn render_frame(&self, frame: &mut Frame) {
        frame.render_widget(self, frame.size());
    }

    pub fn receive_data(&mut self) -> io::Result<()> {
        if self.message_receiver.is_none() {
            return Ok(());
        }
        let x = std::mem::replace(&mut self.message_receiver, None).unwrap();
        match x.try_recv() {
            Ok(msg) => {
                self.message_receiver = Some(x);
                match msg {
                    Message::Data(datapoint) => {
                        Ok(self.data.push(datapoint))
                    }
                    _ => {
                        Ok(self.logs.push((msg, timestamp())))
                    }
                }
            }
            Err(TryRecvError::Empty) => {
                self.message_receiver = Some(x);
                Ok(())
            }
            Err(TryRecvError::Disconnected) => {
                self.exit = true;
                Err(io::Error::new(io::ErrorKind::Other, "Disconnected"))
            }
        }
    }

    pub fn exit(&mut self) {
        self.exit = true;
    }

    pub(crate) fn send_command(&mut self, command: Command) {
        let x = self.command_sender.clone();
        x.unwrap().send(command).unwrap();
    }
}