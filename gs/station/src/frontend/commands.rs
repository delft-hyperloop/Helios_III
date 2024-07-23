use std::path::PathBuf;
use std::str::FromStr;

use chrono::Local;
use gslib::Datapoint;
use gslib::Datatype;
use gslib::LocationSequence;
use gslib::LocationSpeedMap;
use gslib::Message;
use gslib::ProcessedData;
use gslib::Route;
use rand::Rng;
use tauri::Manager;
use tauri::State;

use crate::backend::Backend;
use crate::data::validate::validate_route_internal;
use crate::frontend::app::APP_HANDLE;
use crate::frontend::BackendState;
use crate::frontend::BACKEND;
use crate::Command;

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
pub fn unload_buffer(state: State<BackendState>) -> Vec<ProcessedData> {
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
pub fn send_command(cmd_name: String, val: u64) -> bool {
    eprintln!("Received command {} {} [{}]", cmd_name, val, Local::now());
    let c = Command::from_string(&cmd_name, val);
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.get_mut().unwrap().send_command(c)
    } else {
        panic!("kys");
    }
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn connect_to_pod() -> bool {
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
pub fn disconnect() {
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        backend_mutex.get_mut().unwrap().quit_server();
    }
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn save_logs() -> bool {
    if let Some(backend_mutex) = unsafe { BACKEND.as_ref() } {
        let log = &backend_mutex.lock().unwrap().log;
        let now = Local::now().naive_local();
        let formatted_time = now.format("%d_%m_%Y at %H_%M_%S").to_string();
        if let Ok(x) = PathBuf::from_str(&format!("../../ehw/logs/log-{}.txt", formatted_time)) {
            if Backend::save_to_path(log, x).is_ok() {
                APP_HANDLE
                    .try_lock()
                    .map(|x| x.as_ref().map(|y| y.emit_all("a", "b").is_ok()).is_some())
                    .is_ok()
                // APP_HANDLE.try_borrow().map(|x| x.emit_all("clear_logs", "kiko").is_ok()).is_ok()
            } else {
                false
            }
        } else {
            false
        }
    } else {
        false
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

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn procedures() -> Vec<[String; 6]> {
    let res = Backend::load_procedures(PathBuf::from("../../config/procedures/"));
    if let Some(backend_mutex) = unsafe { BACKEND.as_mut() } {
        if let Ok(x) = res {
            backend_mutex.get_mut().unwrap().log_msg(&Message::Info("Loading procedures".into()));
            x
        } else {
            backend_mutex
                .get_mut()
                .unwrap()
                .log_msg(&Message::Error("Failed to load procedures".into()));
            vec![[
                "Failed".into(),
                "Failed to parse some procedures".into(),
                "".into(),
                "".into(),
                "".into(),
                format!("{:?}", res),
            ]]
        }
    } else {
        res.unwrap()
    }
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn test_panic() {
    panic!("kill yourself");
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn test_route() -> Route { Route::default() }

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn validate_route(route: Route) -> bool { validate_route_internal(route) }

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn speeds_to_u64(speeds: LocationSpeedMap) -> u64 { speeds.into() }

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn speeds_from_u64(speeds: String) -> Result<LocationSpeedMap, String> {
    match u64::from_str(&speeds) {
        Ok(parsed_speeds) => Ok(parsed_speeds.into()),
        Err(e) => Err(format!("Failed to parse speeds from string: {}", e)),
    }
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn positions_to_u64(positions: LocationSequence) -> String {
    let positions_u64: u64 = positions.into();
    positions_u64.to_string()
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn positions_from_u64(positions: String) -> Result<LocationSequence, String> {
    match u64::from_str(&positions) {
        Ok(parsed_positions) => Ok(parsed_positions.into()),
        Err(e) => Err(format!("Failed to parse positions from string: {}", e)),
    }
}

// #[macro_export]
// #[allow(unused)]
// #[tauri::command]
// pub fn set_route(route: Route) -> bool {
//     send_command("SetRoute".into(), 1822648539875311616)
//         && send_command("SetSpeeds".into(), 14104086254467416064)
// }

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn set_route(route: Route) -> bool {
    send_command("SetRoute".into(), route.positions.into())
        && send_command("SetSpeeds".into(), route.speeds.into())
}


#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn demonstration_a() -> bool {
    send_command("SetRoute".into(), 1822648536894799872)
        && send_command("SetSpeeds".into(), 15761687916893437952)
}

#[macro_export]
#[allow(unused)]
#[tauri::command]
pub fn demonstration_b() -> bool {
    send_command("SetRoute".into(), 1905022642377719808)
        && send_command("SetSpeeds".into(), 15708555503539847368)
}
