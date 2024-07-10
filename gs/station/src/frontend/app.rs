use std::path::PathBuf;
use std::sync::Mutex;

use tauri::GlobalShortcutManager;
use tauri::Manager;
use tauri::WindowEvent;

use crate::api::Message;
use crate::backend::Backend;
use crate::frontend::commands::*;
use crate::frontend::BackendState;
use crate::frontend::BACKEND;
use crate::ERROR_CHANNEL;
use crate::INFO_CHANNEL;
use crate::SHORTCUT_CHANNEL;
use crate::STATUS_CHANNEL;
use crate::WARNING_CHANNEL;

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
            let window = app_handle.get_window("main").unwrap();

            let mut message_rcv = backend.message_receiver.resubscribe();
            unsafe {
                BACKEND.replace(Mutex::new(backend));
            }

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
                            ss.emit_all(SHORTCUT_CHANNEL, "emergency_brake").unwrap();
                        })
                        .expect("Could not register shortcut");

                        let ss = s.clone();
                        sh.register("Esc", move || {
                            send_command("EmergencyBrake".into(), 0);
                            ss.emit_all(SHORTCUT_CHANNEL, "emergency_brake").unwrap();
                        })
                        .expect("Could not register shortcut");

                        (0..10).for_each(|i| {
                            let sss = s.clone();
                            sh.register(&format!("{i}"), move || {
                                sss.emit_all(SHORTCUT_CHANNEL, &format!("tab_{i}")).unwrap();
                            })
                            .unwrap_or_else(|_| panic!("Could not register shortcut tab_{i}"));
                        });
                    },
                    WindowEvent::Focused(false) => {
                        // Unregister shortcuts when window loses focus
                        sh.unregister("Esc").expect("Could not unregister shortcut");
                        sh.unregister("Space").expect("Could not unregister shortcut");
                        let mut shh = sh.clone();
                        (0..10).for_each(|i| {
                            shh.unregister(&format!("{i}"))
                                .unwrap_or_else(|_| panic!("Could not unregister shortcut tab_{i}"));
                        });
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
