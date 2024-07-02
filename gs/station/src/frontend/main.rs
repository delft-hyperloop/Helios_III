use crate::api::{Datapoint, Message};
use crate::backend::Backend;
use crate::frontend::{BackendState, BACKEND};
use crate::{Command, ERROR_CHANNEL, INFO_CHANNEL, STATUS_CHANNEL, WARNING_CHANNEL};
use std::sync::Mutex;
use tauri::{Manager, State};
use rand::Rng;
use crate::Datatype;

pub fn tauri_main(backend: Backend) {
    println!("Starting tauri application");
    println!("Starting tauri application");
    println!("Starting tauri application");
    println!("Starting tauri application");
    tauri::Builder::default()
        .manage(BackendState::default())
        .invoke_handler(tauri::generate_handler![unload_buffer, send_command, generate_test_data, start_server, start_levi, quit_server, quit_levi])
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
pub fn generate_test_data() -> Vec<Datapoint> {
    let mut rng = rand::thread_rng();
    let mut datapoints = Vec::new();

    let value: u64 = rng.gen_range(0..101);
    let value2: u64 = rng.gen_range(0..101);
    let value3: u64 = rng.gen_range(0..101);
    let value4: u64 = rng.gen_range(0..300);

    let datapoint = Datapoint { value, datatype:Datatype::from_id(0x3A3), timestamp:0 };
    let datapoint2 = Datapoint { value:value2, datatype:Datatype::from_id(0x19F), timestamp:0 };
    let datapoint3 = Datapoint { value:1, datatype:Datatype::from_id(0x3AA), timestamp:0 };
    let datapoint4 = Datapoint { value:2, datatype:Datatype::from_id(0x3AA), timestamp:0 };
    let datapoint5 = Datapoint { value:3, datatype:Datatype::from_id(0x3AA), timestamp:0 };
    let datapoint6 = Datapoint { value:value4, datatype:Datatype::Module1AvgVoltage, timestamp:0 };
    let datapoint7 = Datapoint { value:value4, datatype:Datatype::Module3AvgTemperature, timestamp:0 };

    datapoints.push(datapoint);
    datapoints.push(datapoint2);
    datapoints.push(datapoint3);
    datapoints.push(datapoint4);
    datapoints.push(datapoint5);
    datapoints.push(datapoint6);
    datapoints.push(datapoint7);

    datapoints
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
pub fn send_command(cmd_name: String, val: u64) {
    eprintln!("Received command {} {}", cmd_name, val);
    let c = Command::from_string(&cmd_name, val);
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
