use std::sync::mpsc::{Receiver, Sender};
use crate::api::{ApiStruct, Message};
use crate::Command;
use crate::connect::Station;
use tauri::{App, State};
use std::sync::Mutex;
use tauri::Manager;

// static mut sender_mutex : Mutex<Option<Sender<Command>>> = Mutex::new(None);
// static mut receiver_mutex : Mutex<Option<Receiver<Message>>> = Mutex::new(None);


#[derive(Debug, Clone, serde::Serialize, serde::Deserialize)]
struct BackendState {
    pub running: Mutex<bool>,
    pub data_buffer: Mutex<Vec<Message>>,
}

impl Default for BackendState {
    fn default() -> Self {
        Self {
            running: Mutex::new(false),
            data_buffer: Mutex::new(Vec::new()),
        }
    }
}


pub fn tauri_main() {
    tauri::Builder::default()
        // .manage(BackendState::default())
        .invoke_handler(tauri::generate_handler![])
        .setup(|app| {
            let (data_sender, data_receiver) = std::sync::mpsc::channel();
            let (command_sender, command_receiver) = std::sync::mpsc::channel();
            data_sender.send(Message::Info("Station started".to_string())).unwrap();
            std::thread::spawn(move ||
                Station::new().launch(data_sender, command_receiver)
            );
            tauri::async_runtime::spawn(async move {
                channel_listener(app, data_receiver, command_sender);
            });
            Ok(())
        })
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}

pub fn channel_listener(app: &mut App, message_receiver: Receiver<Message>, command_sender: Sender<Command>) -> ! {
    loop {
        if let Ok(msg) = message_receiver.recv() {
            // the include goes here

        }
    }
}