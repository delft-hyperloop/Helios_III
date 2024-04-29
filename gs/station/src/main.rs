// Prevents an additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use tauri::{Manager, Window};
use std::time::{SystemTime, UNIX_EPOCH};
use tauri::http::header::DATE;
use chrono::{Local, Timelike};

/**
  * This is a generic tauri that does not invoke anything.
  * This would eventually be used to
  */
#[tauri::command]
async fn my_custom_command() {
    println!("I was invoked from JS!");

    // Preface - checks etc.
    // Initiate command to pod and/or...
    // return status code to front-end. (0 for error free?)
}

/**
  * This here is some generic payload struct that can be sent to frontend.
  * It must be clone-able and serialisable.
  */
#[derive(Clone, serde::Serialize)]
struct Payload {
    timestamp: SystemTime,
    value: u32,
    values: Vec<u32>
}

/**
  * This function spawns a threads that spams 500 u32s and generates a new one every 5 milliseconds.
  * It works fine when visualising in the frontend in debug mode, so it should be good.
  */
#[tauri::command]
async fn start_north_bridge(window: Window) {
    std::thread::spawn(move || {
        let mut values = Vec::new();
        for i in 0..500 { // Generate 500 values
            values.push(i); // Push the value into the Vec
        }
        let mut i:u32 = 50;
        let mut y:u32 = 0;
        loop {

            if y < 10 {
                i += 1;
            } else if y < 20 {
                if i <= 1 { i = 0 } else { i -= 1 }
            } else {
                y = 0;
            }
            y+=1;



            window.emit("north_bridge", Payload { timestamp: SystemTime::now() , value: i, values: values.clone()}).unwrap();
            std::thread::sleep(std::time::Duration::from_millis(5))
        }
    });
}

#[derive(Clone, serde::Serialize)]
struct Log {
    log_type: String,
    message: String,
    timestamp: String
}

#[tauri::command]
async fn start_logs(window: Window) {
    let mut i = 0;
    std::thread::spawn(move || {
        loop {
            let now = Local::now();
            let current_time = format!("{:02}:{:02}:{:02}", now.hour(), now.minute(), now.second());
            if (i < 3) {
                window.emit("logs_bridge", Log {log_type: String::from("fsm"), message: String::from("whoop whoop "), timestamp: current_time }).unwrap();
            } else if (i < 7) {
                window.emit("logs_bridge", Log {log_type: String::from("brake"), message: String::from("dead"), timestamp: current_time }).unwrap();
            } else if (i < 15) {
                window.emit("logs_bridge", Log {log_type: String::from("levi"), message: String::from("levitation"), timestamp: current_time }).unwrap();
            } else if (i < 30) {
                window.emit("logs_bridge", Log {log_type: String::from("prop"), message: String::from("propelling"), timestamp: current_time }).unwrap();
            } else {
                i = 0;
            }
            i+=1;

            std::thread::sleep(std::time::Duration::from_secs(1));
        }
    });
}

#[derive(Clone, serde::Serialize)]
struct Error {
    message: String
}
#[tauri::command]
async fn start_errors(window: Window) {
    let mut i = 0;
    std::thread::spawn(move || {
        loop {
            window.emit("error_bridge", Error {message: String::from("aaaa gg died")}).unwrap();
            std::thread::sleep(std::time::Duration::from_secs(10));
        }
    });
}

#[tauri::command]
async fn start_south_bridge(window: Window) {
    std::thread::spawn(move || {
        let mut values = Vec::new();
        for i in 0..500 { // Generate 500 values
            values.push(i); // Push the value into the Vec
        }
        let mut i:u32 = 50;
        let mut y:u32 = 0;
        loop {

            if y < 10 {
                i += 1;
            } else if y < 20 {
                if i <= 1 { i = 0 } else { i -= 1 }
            } else {
                y = 0;
            }
            y+=1;



            window.emit("south_bridge", Payload { timestamp: SystemTime::now() , value: i, values: values.clone()}).unwrap();
            std::thread::sleep(std::time::Duration::from_millis(100))
        }
    });
}

fn main() {
  tauri::Builder::default()
      // register the commands in tauri.
    .invoke_handler(tauri::generate_handler![my_custom_command, start_north_bridge, start_south_bridge, start_logs, start_errors])
      // init tauri
    .run(tauri::generate_context!())
    .expect("error while running tauri application");
}
