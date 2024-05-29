use std::sync::Mutex;
use crate::api::{Datapoint, Message};
use crate::backend::Backend;
use crate::frontend::{BackendState, BACKEND};
use crate::{Command, ERROR_CHANNEL, INFO_CHANNEL, STATUS_CHANNEL, WARNING_CHANNEL};
use tauri::{Manager, State};

pub fn tauri_main(backend: Backend) {
    println!("Starting tauri application");
    println!("Starting tauri application");
    println!("Starting tauri application");
    println!("Starting tauri application");
    tauri::Builder::default()
        .manage(BackendState::default())
        .invoke_handler(tauri::generate_handler![unload_buffer, send_command,])
        .setup(move |app| {
            let app_handle = app.handle();
            let mut message_rcv = backend.message_receiver.resubscribe();
            unsafe {
                BACKEND.replace(Mutex::new(backend));
            }
            tokio::spawn(async move {
                loop {
                    match message_rcv.recv().await {
                        Ok(msg) => match msg {
                            Message::Data(dp) => {
                                println!("Received datapoint: {:?}", dp);
                                app_handle
                                    .state::<BackendState>()
                                    .data_buffer
                                    .lock()
                                    .unwrap()
                                    .push(Message::Data(dp));
                            }
                            Message::Status(s) => app_handle
                                .emit_all(STATUS_CHANNEL, &*format!("{:?}", s))
                                .unwrap(),
                            Message::Info(i) => app_handle
                                .emit_all(INFO_CHANNEL, &*format!("{}", i))
                                .unwrap(),
                            Message::Warning(w) => app_handle
                                .emit_all(WARNING_CHANNEL, &*format!("{}", w))
                                .unwrap(),
                            Message::Error(e) => app_handle
                                .emit_all(ERROR_CHANNEL, &*format!("{}", e))
                                .unwrap(),
                        },
                        Err(e) => {
                            eprintln!("Error receiving message: {:?}", e);
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
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.lock().unwrap().send_command(c);
    }
}

#[allow(unused)]
#[tauri::command]
pub fn start_server() {
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.lock().unwrap().start_server();
    }
}

#[allow(unused)]
#[tauri::command]
pub fn start_levi() {
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.lock().unwrap().start_levi();
    }
}

#[allow(unused)]
#[tauri::command]
pub fn quit_levi() {
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.lock().unwrap().quit_levi();
    }
}

#[allow(unused)]
#[tauri::command]
pub fn quit_server() {
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.lock().unwrap().quit_server();
    }
}