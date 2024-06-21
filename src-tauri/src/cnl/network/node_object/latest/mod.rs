use std::{sync::Arc, time::Duration};

use tauri::Manager;
use tokio::sync::Mutex;

use crate::cnl::network::object_entry_object::ObjectEntryObject;

use self::event::NodeEvent;

pub mod event;

const INTERVAL_MS: u64 = 500;

pub struct NodeLatestObservable {
    object_entries: Vec<Arc<ObjectEntryObject>>,
    event_name: String,
    listen_count: Arc<Mutex<usize>>,
    app_handle: tauri::AppHandle,
    rx: Mutex<tokio::sync::mpsc::Receiver<Msg>>,
    tx: tokio::sync::mpsc::Sender<Msg>,
}

enum Msg {
    Exit,
}

impl NodeLatestObservable {
    pub fn new(
        object_entries: &Vec<Arc<ObjectEntryObject>>,
        event_name: &str,
        app_handle: &tauri::AppHandle,
    ) -> Self {
        let (tx, rx) = tokio::sync::mpsc::channel(1);
        let tx_init = tx.clone();
        tokio::spawn(async move {
            tx_init
                .send(Msg::Exit)
                .await
                .expect("Failed to send on NodeLatestObserver channel")
        });
        Self {
            object_entries: object_entries.clone(),
            event_name: event_name.to_owned(),
            listen_count: Arc::new(Mutex::new(0)),
            app_handle: app_handle.clone(),
            tx,
            rx: Mutex::new(rx),
        }
    }

    pub async fn listen(&self) -> String {
        let mut listen_count = self.listen_count.lock().await;
        if *listen_count == 0 {
            // NOTE wait for previous task to be finished!
            drop(listen_count);
            self.rx
                .lock()
                .await
                .recv()
                .await
                .expect("Failed to receive from NodeLatestObserver channel");
            let mut listen_count = self.listen_count.lock().await;
            *listen_count += 1;

            tokio::spawn(notify_task(
                self.app_handle.clone(),
                self.event_name.clone(),
                self.object_entries.clone(),
                self.tx.clone(),
                self.listen_count.clone(),
            ));
        } else {
            *listen_count += 1;
        }
        return self.event_name.clone();
    }

    pub async fn unlisten(&self) {
        let mut listen_count = self.listen_count.lock().await;
        *listen_count = listen_count.saturating_sub(1);
    }
    
    pub async fn deadlock_watchdog(&self) {
        let _ = self.listen_count.lock().await;
        let _ = self.rx.lock().await;
    }
}

async fn notify_task(
    app_handle: tauri::AppHandle,
    event_name: String,
    object_entries: Vec<Arc<ObjectEntryObject>>,
    exit_channel: tokio::sync::mpsc::Sender<Msg>,
    listen_count: Arc<Mutex<usize>>,
) {
    let mut interval = tokio::time::interval(Duration::from_millis(INTERVAL_MS));

    let mut values = vec![];

    while *listen_count.lock().await > 0 {
        interval.tick().await;
        values.clear();
        for oeo in &object_entries {
            values.push(oeo.latest_event().await)
        }
        let event = NodeEvent {
            object_entry_values: values.clone(),
        };
        app_handle
            .emit_all(&event_name, event)
            .expect(&format!("Failed to emit tauri event : {event_name}."));
    }


    exit_channel
        .send(Msg::Exit)
        .await
        .expect("Faild to send Exit Msg of NodeObjectObservable::notify_task")
}
