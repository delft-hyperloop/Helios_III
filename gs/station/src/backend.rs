use crate::api::Message;
use crate::Command;
use std::path::PathBuf;
use tokio::task::AbortHandle;

// /// Any frontend that interfaces with this backend needs to comply to this trait
// pub trait Frontend {
//     /// This is called from main.rs, can be used for any initialisation
//     fn start();
//     /// When the backend has data available, it will call this function
//     fn receive_data(&mut self, data: Vec<Message>);
//     ///
//     fn send_command(&self, cmd: Command);
// }

pub struct Backend {
    pub server_handle: Option<AbortHandle>,
    pub levi_handle: Option<(AbortHandle, AbortHandle)>,
    pub message_transmitter: tokio::sync::broadcast::Sender<Message>,
    pub message_receiver: tokio::sync::broadcast::Receiver<Message>,
    pub command_transmitter: tokio::sync::broadcast::Sender<Command>,
    pub command_receiver: tokio::sync::broadcast::Receiver<Command>,
    pub log: Log,
}

#[derive(serde::Serialize)]
pub struct Log {
    messages: Vec<Message>,
    commands: Vec<Command>,
}

impl Default for Backend {
    fn default() -> Self {
        Self::new()
    }
}

impl Backend {
    /// # Create a backend instance
    /// this creates two new broadcast channels, one for messages and one for commands.
    ///
    /// this function should only be called once, in main.rs::main()
    pub fn new() -> Self {
        let (message_transmitter, message_receiver) =
            tokio::sync::broadcast::channel::<Message>(128);
        let (command_transmitter, command_receiver) =
            tokio::sync::broadcast::channel::<Command>(128);
        Self {
            server_handle: None,
            levi_handle: None,
            message_transmitter,
            message_receiver,
            command_transmitter,
            command_receiver,
            log: Log {
                messages: vec![],
                commands: vec![],
            },
        }
    }

    /// # Start a TCP server
    /// ### Uses the backend's existing broadcast channels
    pub fn start_server(&mut self) -> bool {
        if self.server_handle.is_none() {
            let m = self.message_transmitter.clone();
            let c = self.command_receiver.resubscribe();
            let t = self.command_transmitter.clone();
            self.server_handle = Some(
                tokio::spawn(async move { crate::connect::connect_main(m, c, t).await })
                    .abort_handle(),
            );
            // self.status(crate::api::Status::ServerStarted);
            self.info(format!("Server handle: {:?}", self.server_handle));
            true
        } else {
            self.warn("Server already running".to_string());
            false
        }
    }

    pub fn start_levi(&mut self) {
        if self.levi_handle.is_none() {
            match crate::levi::levi_main(
                self.message_transmitter.clone(),
                self.command_transmitter.clone(),
                self.command_receiver.resubscribe(),
            ) {
                Ok(lh) => {
                    self.levi_handle = Some(lh);
                    self.status(crate::Info::LeviProgramStarted);
                    self.info("Levi process started".to_string());
                }
                Err(e) => {
                    self.err(format!("Error starting levi: {}", e));
                }
            }
        } else {
            self.warn("Levi already running".to_string());
        }
    }

    pub fn send_command(&mut self, cmd: Command) {
        self.info(format!("[TRACE] enqueuing command {:?}", cmd));
        self.command_transmitter.send(cmd).unwrap();
        self.log_cmd(&cmd);
    }
    pub fn info(&mut self, msg: String) {
        self.message_transmitter.send(Message::Info(msg)).unwrap();
    }
    pub fn warn(&mut self, msg: String) {
        self.message_transmitter
            .send(Message::Warning(msg))
            .unwrap();
    }
    pub fn err(&mut self, msg: String) {
        self.message_transmitter.send(Message::Error(msg)).unwrap();
    }
    pub fn status(&mut self, status: crate::Info) {
        self.message_transmitter
            .send(Message::Status(status))
            .unwrap();
    }
    pub fn quit_levi(&mut self) {
        if let Some((lh1, lh2)) = self.levi_handle.take() {
            self.info("Quitting levi_handle_1".into());
            lh1.abort();
            self.info("Quitting levi_handle_2".into());
            lh2.abort();
        }
    }
    pub fn quit_server(&mut self) {
        if let Some(sh) = self.server_handle.take() {
            self.info("Quitting server_handle".into());
            self.command_transmitter.send(Command::Shutdown(0)).unwrap();
            sh.abort();
        }
    }

    pub fn save(&self, path: PathBuf) -> anyhow::Result<()> {
        let json = serde_json::to_string(&self.log)?;
        std::fs::write(path, json)?;
        Ok(())
    }

    pub fn log_msg(&mut self, msg: Message) {
        self.log.messages.push(msg);
    }
    pub fn log_cmd(&mut self, cmd: &Command) {
        self.log.commands.push(*cmd);
    }

    pub fn load_procedures(folder: PathBuf) -> anyhow::Result<Vec<[String; 5]>> {
        let mut r = vec![];

        for entry in std::fs::read_dir(folder)? {
            let f = entry?;

            if f.file_name().to_str()?.ends_with(".procedure") {
                let contents = std::fs::read_to_string(f.path())?;
                let mut lines = contents.lines();
                let name = f
                    .file_name()
                    .to_str()?
                    .trim_end_matches(".procedure")
                    .to_string();
                let title = lines.next()?.trim_start_matches([' ', '#']).to_string();
                let people = lines
                    .next()?
                    .trim_start()
                    .trim_start_matches("people")
                    .trim_start_matches("People")
                    .trim_start_matches("PEOPLE")
                    .trim_start_matches(":")
                    .trim_start()
                    .to_string();
                let equipment = lines
                    .next()?
                    .trim_start()
                    .trim_start_matches("equipment")
                    .trim_start_matches("Equipment")
                    .trim_start_matches("EQUIPMENT")
                    .trim_start_matches(":")
                    .trim_start()
                    .to_string();
                let content = lines.collect::<Vec<&str>>().join("\n").trim().to_string();
                r.push([name, title, people, equipment, content]);
            }
        }

        Ok(r)
    }
}
