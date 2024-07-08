use std::path::PathBuf;
use std::str::FromStr;
use std::sync::Mutex;

use rand::Rng;
use tauri::Manager;
use tauri::State;

use crate::api::Datapoint;
use crate::api::Message;
use crate::backend::Backend;
use crate::frontend::BackendState;
use crate::frontend::BACKEND;
use crate::Command;
use crate::Datatype;
use crate::ERROR_CHANNEL;
use crate::INFO_CHANNEL;
use crate::STATUS_CHANNEL;
use crate::WARNING_CHANNEL;
use crate::frontend::commands::*;

pub fn tauri_main(backend: Backend) {
    println!("Starting tauri application");
    println!("Starting tauri application");
    println!("Starting tauri application");
    println!("Starting tauri application");
    tauri::Builder::default()
        .manage(BackendState::default())
        .invoke_handler(tauri::generate_handler![
            unload_buffer,
            send_command,
            generate_test_data,
            start_server,
            start_levi,
            quit_server,
            quit_levi,
            procedures
        ])
        .setup(move |app| {
            let app_handle = app.handle();
            let mut message_rcv = backend.message_receiver.resubscribe();
            unsafe {
                BACKEND.replace(Mutex::new(backend));
            }
            tokio::spawn(async move {
                loop {
                    match message_rcv.try_recv() {
                        Ok(msg) => {
                            if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
                                backend_mutex.get_mut().unwrap().log_msg(&msg);
                            }

                            match msg {
                                Message::Data(dp) => {
                                    println!("Received datapoint: {:?}", dp);
                                    app_handle
                                        .state::<BackendState>()
                                        .data_buffer
                                        .lock()
                                        .unwrap()
                                        .push(Message::Data(dp));
                                },
                                Message::Status(s) => app_handle
                                    .emit_all(STATUS_CHANNEL, &*format!("{:?}", s))
                                    .unwrap(),
                                Message::Info(i) => {
                                    app_handle.emit_all(INFO_CHANNEL, i.to_string()).unwrap()
                                },
                                Message::Warning(w) => {
                                    app_handle.emit_all(WARNING_CHANNEL, w.to_string()).unwrap()
                                },
                                Message::Error(e) => {
                                    app_handle.emit_all(ERROR_CHANNEL, e.to_string()).unwrap()
                                },
                            }
                        },
                        Err(_e) => {
                            // eprintln!("Error receiving message: {:?}", e);
                        },
                    }
                }
            });
            Ok(())
        })
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}

