use std::io;
use std::sync::mpsc::{Receiver, Sender, TryRecvError};
use ratatui::Frame;
use crate::api::{Message, state_to_string};
use crate::{Command, COMMANDS_LIST};
use crate::connect::{Datapoint, Station};
use crate::tui::{timestamp, Tui};


pub struct CmdRow {
    pub name: String,
    pub value: u64,
}

impl CmdRow {
    pub fn to_row(&self) -> ratatui::widgets::Row {
        ratatui::widgets::Row::new(vec![self.name.clone(), self.value.to_string()])
    }
    pub fn as_cmd(&self) -> Command {
        Command::from_string(&self.name, self.value)
    }
}

#[allow(dead_code)]
pub struct App {
    pub logs: Vec<(Message, String)>,
    pub data: Vec<Datapoint>,
    pub exit: bool,
    pub scroll: u16,
    pub time_elapsed: u64,
    pub selected: usize,
    pub selected_row: usize,
    pub cmds: Vec<CmdRow>,
    pub cur_state: String,
    message_sender: Option<Sender<Message>>,
    message_receiver: Option<Receiver<Message>>,
    command_sender: Option<Sender<Command>>,
    levi_command_sender: Option<Sender<Command>>,
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
            selected_row: 0,
            cmds: COMMANDS_LIST.iter().map(|x| CmdRow { name: format!("{:?}", x), value: 0 }).collect(),
            cur_state: "None Yet".to_string(),
            message_sender: None,
            message_receiver: None,
            command_sender: None,
            command_receiver: None,
            station_running: false,
            levi_command_sender: None,
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
        self.message_sender = Some(data_sender.clone());
        std::thread::spawn(move ||
            Station::new().launch(data_sender, command_receiver)
        );
    }

    pub fn run(&mut self, terminal: &mut Tui) -> io::Result<()> {
        while !self.exit {
            terminal.draw(|frame| self.render_frame(frame))?;
            self.handle_events();
            self.receive_data();
            self.time_elapsed = self.time_elapsed.wrapping_add(1);
        }
        Ok(())
    }

    fn render_frame(&self, frame: &mut Frame) {
        frame.render_widget(self, frame.size());
    }

    pub fn receive_data(&mut self) {
        if self.message_receiver.is_none() {
            return;
        }
        let x = std::mem::replace(&mut self.message_receiver, None).unwrap();
        match x.try_recv() {
            Ok(msg) => {
                self.message_receiver = Some(x);
                match msg {
                    Message::Data(datapoint) => {
                        if datapoint.datatype == crate::Datatype::FSMState {
                            self.cur_state = format!("{}", state_to_string(datapoint.value));
                            self.logs.push((Message::Warning(format!("State changed to: {:?}", datapoint.value.to_be_bytes())), timestamp()));
                        }
                        self.logs.push((Message::Data(datapoint), timestamp()))
                    }
                    _ => {
                        self.logs.push((msg, timestamp()))
                    }
                }
            }
            Err(TryRecvError::Empty) => {
                self.message_receiver = Some(x);
            }
            Err(TryRecvError::Disconnected) => {
                self.exit = true;
            }
        }
    }

    pub fn exit(&mut self) {
        self.exit = true;
    }

    pub fn launch_levi_software(&mut self) {
        let (r, s) = crate::levi::start_levi_process();
        let m = self.message_sender.clone();
        std::thread::spawn(move || {
            loop {
                match r.recv() {
                    Ok(msg) => {
                        if let Some(ms) = &m {
                            ms.send(msg).unwrap();
                        } else {
                            eprintln!("Failed to send message: {:?}", msg);
                        }
                    },
                    Err(_) => {}
                }
            }
        });
        // replace self.levi_command_sender with s
        self.levi_command_sender = Some(s);
    }

    pub(crate) fn send_command(&mut self, command: Command) {
        if let Some(s) = self.command_sender.as_ref() {
            self.logs.push((Message::Info(format!("Trying to send command: {:?}", command)), timestamp()));
            s.send(command).unwrap();
            if let Some(s) = self.levi_command_sender.as_ref() {
                self.logs.push((Message::Info(format!("Trying to send command to levi: {:?}", command)), timestamp()));
                s.send(command).unwrap();
            } else {
                self.logs.push((Message::Error(format!("Tried to send command `{:?}` with no connection to levi", command)), timestamp()));
            }
        } else {
            self.logs.push((Message::Error(format!("Tried to send command `{:?}` with no connection to station", command)), timestamp()));
        }
    }


}
