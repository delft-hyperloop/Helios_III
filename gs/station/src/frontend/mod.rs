use std::sync::mpsc::{Receiver, Sender};
use std::sync::Mutex;
use crate::api::{ApiStruct, Message};
use crate::Command;
use crate::connect::Station;

static mut sender_mutex : Mutex<Option<Sender<Command>>> = Mutex::new(None);
static mut receiver_mutex : Mutex<Option<Receiver<Message>>> = Mutex::new(None);

pub fn tauri_main() {
    tauri::Builder::default()
        .invoke_handler(tauri::generate_handler![])
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}

#[tauri::command]
async fn launch_station() {
    let (data_sender, data_receiver) = std::sync::mpsc::channel();
    let (command_sender, command_receiver) = std::sync::mpsc::channel();
    data_sender.send(Message::Info("Station started".to_string())).unwrap();
    unsafe {
        *sender_mutex.lock().unwrap() = Some(command_sender);
        *receiver_mutex.lock().unwrap() = Some(data_receiver);
    }
    self.station_running = true;
    std::thread::spawn(move ||
        Station::new().launch(data_sender, command_receiver)
    );
}