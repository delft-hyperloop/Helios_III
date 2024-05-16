use std::fmt::{Debug};
use std::sync::mpsc::Sender;
use crate::api::{Message};
use crate::{Command, ERROR_CHANNEL, INFO_CHANNEL, STATUS_CHANNEL, WARNING_CHANNEL, Datatype};
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
        .invoke_handler(tauri::generate_handler![unload_buffer, send_command, generate_test_data])
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
                                app_handle.emit_all(STATUS_CHANNEL, &*format!("{:?}", s)).unwrap()
                            }
                            Message::Info(i) => {
                                app_handle.emit_all(INFO_CHANNEL, &*format!("{}", i)).unwrap()
                            }
                            Message::Warning(w) => {
                                app_handle.emit_all(WARNING_CHANNEL, &*format!("{}", w)).unwrap()
                            }
                            Message::Error(e) => {
                                app_handle.emit_all(ERROR_CHANNEL, &*format!("{}", e)).unwrap()
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

use rand::Rng;

#[allow(unused)]
#[tauri::command]
pub fn generate_test_data() -> Vec<Datapoint> {
    let mut rng = rand::thread_rng();
    let mut datapoints = Vec::new();

    let value: u64 = rng.gen_range(0..101);
    let value2: u64 = rng.gen_range(0..101);
    let value3: u64 = rng.gen_range(0..101);

    let datapoint = Datapoint { value, datatype:Datatype::from_id(0x3A3), timestamp:0 };
    let datapoint2 = Datapoint { value:value2, datatype:Datatype::from_id(0x19F), timestamp:0 };
    let datapoint3 = Datapoint { value:1, datatype:Datatype::from_id(0x3AA), timestamp:0 };
    let datapoint4 = Datapoint { value:2, datatype:Datatype::from_id(0x3AA), timestamp:0 };
    let datapoint5 = Datapoint { value:3, datatype:Datatype::from_id(0x3AA), timestamp:0 };

    datapoints.push(datapoint);
    datapoints.push(datapoint2);
    datapoints.push(datapoint3);
    datapoints.push(datapoint4);
    datapoints.push(datapoint5);

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
