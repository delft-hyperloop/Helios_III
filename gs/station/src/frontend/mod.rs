use std::fmt::{Debug};
use std::sync::mpsc::Sender;
use crate::api::{Message};
use crate::{Command, ERROR_CHANNEL, INFO_CHANNEL, STATUS_CHANNEL, WARNING_CHANNEL};
use crate::connect::{Datapoint, Station};
use tauri::{State};
use std::sync::Mutex;
use tauri::Manager;

#[derive(Debug, serde::Serialize, serde::Deserialize)]
pub struct BackendState {
    pub running: Mutex<bool>,
    pub data_buffer: Mutex<Vec<Message>>,
}

static mut COMMAND_SENDER: Option<Sender<Command>> = None;


impl Default for BackendState {
    fn default() -> Self {
        Self {
            running: Mutex::new(false),
            data_buffer: Mutex::new(Vec::new()),
            // command_sender: None,
        }
    }
}


pub fn tauri_main() {
    tauri::Builder::default()
        .manage(BackendState::default())
        .invoke_handler(tauri::generate_handler![])
        .setup(|app| {
            let (data_sender, message_receiver) = std::sync::mpsc::channel();
            let (command_sender, command_receiver) = std::sync::mpsc::channel();
            data_sender.send(Message::Info("Station started".to_string())).unwrap();
            unsafe { COMMAND_SENDER.replace(command_sender); }
            std::thread::spawn(move ||
                Station::new().launch(data_sender, command_receiver)
            );
            let app_handle = app.handle();
            tauri::async_runtime::spawn(async move {
                loop {
                    if let Ok(msg) = message_receiver.recv() {
                        match msg {
                            Message::Data(dp) => {
                                app_handle.state::<BackendState>().data_buffer.lock().unwrap().push(Message::Data(dp));
                            }
                            Message::Status(s) => {
                                app_handle.emit_to(STATUS_CHANNEL, &*format!("{:?}", s), format!("{}",s.colour())).unwrap()
                            }
                            Message::Info(i) => {
                                app_handle.emit_to(INFO_CHANNEL, &*format!("{}", i), "your mom".to_string()).unwrap()
                            }
                            Message::Warning(w) => {
                                app_handle.emit_to(WARNING_CHANNEL, &*format!("{}", w), "your mom".to_string()).unwrap()
                            }
                            Message::Error(e) => {
                                app_handle.emit_to(ERROR_CHANNEL, &*format!("{}", e), "your mom".to_string()).unwrap()
                            }
                        }
                    }
                }
            });
            Ok(())
        })
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}

#[allow(unused)]
#[tauri::command]
pub fn unload_buffer(state: State<BackendState>) -> Vec<Datapoint> {
    let mut data_buffer = state.data_buffer.lock().unwrap();
    let mut datapoints = Vec::new();
    for msg in data_buffer.iter() {
        match msg {
            Message::Data(datapoint) => {
                datapoints.push(datapoint.clone());
            }
            _ => {}
        }
    }
    data_buffer.clear();
    datapoints
}

#[allow(unused)]
#[tauri::command]
pub fn send_command(cmd: String, val: u64) {
    let c = Command::from_string(&cmd, val);
    if let Some(sender) = unsafe { COMMAND_SENDER.as_ref().clone() } {
        sender.send(c).unwrap();
    }
}
