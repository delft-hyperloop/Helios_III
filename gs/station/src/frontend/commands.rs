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


#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn generate_test_data() -> Vec<Datapoint> {
    let mut rng = rand::thread_rng();
    let mut datapoints = Vec::new();

    let value: u64 = rng.gen_range(0..101);
    let value2: u64 = rng.gen_range(0..101);
    let value3: u64 = rng.gen_range(0..101);
    let value4: u64 = rng.gen_range(0..300);

    let datapoint = Datapoint { value, datatype: Datatype::from_id(0x3A3), timestamp: 0 };
    let datapoint2 = Datapoint { value: value2, datatype: Datatype::from_id(0x19F), timestamp: 0 };
    let datapoint3 = Datapoint { value: 1, datatype: Datatype::from_id(0x3AA), timestamp: 0 };
    let datapoint4 = Datapoint { value: 2, datatype: Datatype::from_id(0x3AA), timestamp: 0 };
    let datapoint5 = Datapoint { value: 3, datatype: Datatype::from_id(0x3AA), timestamp: 0 };
    let datapoint6 =
        Datapoint { value: value4, datatype: Datatype::Module1AvgVoltage, timestamp: 0 };
    let datapoint7 =
        Datapoint { value: value4, datatype: Datatype::Module3AvgTemperature, timestamp: 0 };

    datapoints.push(datapoint);
    datapoints.push(datapoint2);
    datapoints.push(datapoint3);
    datapoints.push(datapoint4);
    datapoints.push(datapoint5);
    datapoints.push(datapoint6);
    datapoints.push(datapoint7);

    datapoints
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn unload_buffer(state: State<BackendState>) -> Vec<Datapoint> {
    let mut data_buffer = state.data_buffer.lock().unwrap();
    let mut datapoints = Vec::new();
    for msg in data_buffer.iter() {
        if let Message::Data(datapoint) = msg {
            datapoints.push(datapoint.clone());
        }
    }
    data_buffer.clear();
    datapoints
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn send_command(cmd_name: String, val: u64) {
    eprintln!("Received command {} {}", cmd_name, val);
    let c = Command::from_string(&cmd_name, val);
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.get_mut().unwrap().send_command(c);
    }
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn start_server() -> bool {
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.get_mut().unwrap().start_server()
    } else {
        false
    }
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn start_levi() {
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.get_mut().unwrap().start_levi();
    }
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn quit_levi() {
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.get_mut().unwrap().quit_levi();
    }
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn quit_server() {
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.get_mut().unwrap().quit_server();
    }
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn procedures() -> Vec<[String; 6]> {
    let res =
        Backend::load_procedures(PathBuf::from_str("../../../../config/procedures/").unwrap());
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        if let Ok(x) = res {
            backend_mutex.get_mut().unwrap().log_msg(&Message::Info("Loading procedures".into()));
            x
        } else {
            backend_mutex
                .get_mut()
                .unwrap()
                .log_msg(&Message::Error("Failed to load procedures".into()));
            Vec::new()
        }
    } else {
        res.unwrap()
    }
}


#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn save_to_file(path: &str) -> bool {
    if let Some(backend_mutex) = unsafe { BACKEND.as_ref() } {
        let log = &backend_mutex.lock().unwrap().log;
        if let Ok(x) = PathBuf::from_str(path) {
            Backend::save_to_path(log, x).is_ok()
        } else {
            false
        }
    } else {
        false
    }
}
