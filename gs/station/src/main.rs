// Prevents an additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use tauri::{Manager, Window};
use std::time::{SystemTime, UNIX_EPOCH};

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
async fn north_bridge(window: Window) {
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

#[tauri::command]
async fn south_bridge(window: Window) {
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
    .invoke_handler(tauri::generate_handler![my_custom_command, north_bridge, south_bridge])
      // init tauri
    .run(tauri::generate_context!())
    .expect("error while running tauri application");
}
