use std::ops::DerefMut;
use std::sync::Mutex;
use std::time::Duration;

use gslib::Message;
use gslib::ERROR_CHANNEL;
use gslib::HEARTBEAT;
use gslib::INFO_CHANNEL;
use gslib::SHORTCUT_CHANNEL;
use gslib::STATUS_CHANNEL;
use gslib::WARNING_CHANNEL;
use tauri::AppHandle;
use tauri::GlobalShortcutManager;
use tauri::Manager;
use tauri::WindowEvent;
use tokio::time::sleep;

use crate::backend::Backend;
use crate::frontend::commands::*;
use crate::frontend::BackendState;
use crate::frontend::BACKEND;

pub static APP_HANDLE: Mutex<Option<AppHandle>> = Mutex::new(None);

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
            connect_to_pod,
            start_levi,
            disconnect,
            quit_levi,
            procedures,
            test_panic,
            save_logs,
            test_route,
            validate_route,
            speeds_to_u64,
            speeds_from_u64,
            positions_to_u64,
            positions_from_u64,
            set_route,
            demonstration_a,
            demonstration_b,
        ])
        .setup(move |app| {
            let app_handle = app.handle();
            let window = app_handle.get_window("main").unwrap();

            let mut message_rcv = backend.message_receiver.resubscribe();
            unsafe {
                BACKEND.replace(Mutex::new(backend));
            }

            let s = app_handle.clone();
            // this is unsafe, don't do it anywhere else
            APP_HANDLE
                .lock()
                .map(|mut x| x.deref_mut().replace(s.clone()))
                .expect("Error replacing app handle mutex");

            // set up heartbeat
            tokio::spawn(async move {
                loop {
                    s.emit_all(SHORTCUT_CHANNEL, "heartbeat").unwrap();
                    sleep(Duration::from_millis(HEARTBEAT)).await;
                }
            });

            // set up shortcuts
            let s = app_handle.clone();
            let shortcuts = app_handle.global_shortcut_manager();

            window.on_window_event(move |event| {
                let mut sh = shortcuts.clone();
                match event {
                    WindowEvent::Focused(true) => {
                        // Register shortcuts when window is focused
                        let ss = s.clone();
                        sh.register("Space", move || {
                            send_command("EmergencyBrake".into(), 0);
                            // ss.emit_all(SHORTCUT_CHANNEL, "emergency_brake").unwrap();
                            ss.emit_all(STATUS_CHANNEL, "Emergency Brake triggered!;red").unwrap();
                            ss.emit_all(ERROR_CHANNEL, "Emergency Brake triggered!").unwrap()
                        })
                        .expect("Could not register shortcut");

                        let ss = s.clone();
                        sh.register("Esc", move || {
                            send_command("EmergencyBrake".into(), 0);
                            // ss.emit_all(SHORTCUT_CHANNEL, "emergency_brake").unwrap();
                            ss.emit_all(ERROR_CHANNEL, "Emergency Brake triggered!").unwrap();
                            ss.emit_all(STATUS_CHANNEL, "Emergency Brake triggered!;red").unwrap();
                        })
                        .expect("Could not register shortcut");
                    },
                    WindowEvent::Focused(false) => {
                        // Unregister shortcuts when window loses focus
                        sh.unregister("Esc").expect("Could not unregister shortcut");
                        sh.unregister("Space").expect("Could not unregister shortcut");
                    },
                    _ => {},
                }
            });

            // --

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
                                    .emit_all(
                                        STATUS_CHANNEL,
                                        &*format!("Status: {:?};{}", s, s.to_colour_str()),
                                    )
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
