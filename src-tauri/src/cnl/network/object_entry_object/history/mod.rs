use std::{sync::Arc, time::Duration};

use color_print::cprintln;
use tauri::Manager;
use tokio::sync::{mpsc, Mutex};

use crate::cnl::network::object_entry_object::history::event::ObjectEntryHistoryEvent;

use super::database::ObjectEntryDatabase;

pub mod event;

enum ObserverCommand {
    Value,
    Poison,
}

pub struct ObjectEntryHistroyObservable {
    min_interval: Duration,
    frame_size: Duration,
    event_name: String,
    app_handle: tauri::AppHandle,

    tx: mpsc::Sender<ObserverCommand>,
    rx: Arc<Mutex<mpsc::Receiver<ObserverCommand>>>,

    start_index: usize,
    start_time: std::time::Instant,
}

impl ObjectEntryHistroyObservable {
    pub fn new(
        event_name: &str,
        min_interval: Duration,
        frame_size: Duration,
        app_handle: &tauri::AppHandle,
        start_index: usize,
        start_time: std::time::Instant,
    ) -> Self {
        let (tx, rx) = mpsc::channel(10);
        Self {
            event_name: event_name.to_owned(),
            min_interval,
            frame_size,
            app_handle: app_handle.clone(),
            tx,
            rx: Arc::new(Mutex::new(rx)),
            start_index,
            start_time,
        }
    }

    pub async fn notify(&self) {
        // intentionally ignore the result!
        if let Err(_) = self.tx.send_timeout(ObserverCommand::Value, Duration::from_millis(1000)).await {
            cprintln!("<red> Failed to notify history observable. MPCS capacity is full, dropping the value </red>");
        };
    }

    pub async fn start_notify_task(&self, store: &Arc<Mutex<ObjectEntryDatabase>>) {
        tokio::spawn(Self::notify_task(
            self.event_name.clone(),
            self.min_interval,
            self.frame_size,
            self.app_handle.clone(),
            self.rx.clone(),
            store.clone(),
            store.lock().await.history().len(),
            self.start_index,
            self.start_time,
        ));
    }

    pub async fn stop_notify_task(&self) {
        self.tx
            .send_timeout(ObserverCommand::Poison, Duration::from_millis(1000))
            .await
            .expect("Failed to send poison to object entry history notify task");
    }

    async fn notify_task(
        event_name: String,
        min_interval: Duration,
        frame_size: Duration,
        app_handle: tauri::AppHandle,
        rx: Arc<Mutex<mpsc::Receiver<ObserverCommand>>>,
        store: Arc<Mutex<ObjectEntryDatabase>>,
        latest_index: usize,
        start_index: usize,
        start_time: std::time::Instant,
    ) {
        // println!("start notify task {event_name}");
        let mut start_index = start_index;
        let mut latest_index = latest_index;
        let mut rx = rx.lock().await;
        let mut next_batch_time = tokio::time::Instant::now();
        let mut timeout = tokio::time::Instant::now() + Duration::from_secs(0xFFFF);
        loop {
            match tokio::time::timeout_at(timeout, rx.recv()).await {
                Ok(opt) => {
                    match opt {
                        Some(ObserverCommand::Poison) => {
                            let store_lock = store.lock().await;
                            if store_lock.history().len() < latest_index {
                                let mut deprecated_count = 0;

                                let now = std::time::Instant::now().duration_since(start_time);
                                let breakpoint = now.saturating_sub(frame_size);
                                for event in store_lock.history()[start_index..].iter() {
                                    if event.timestamp >= breakpoint {
                                        break;
                                    }
                                    deprecated_count += 1;
                                }

                                let payload = &store_lock.history()[latest_index..];
                                app_handle
                                    .emit_all(
                                        &event_name,
                                        ObjectEntryHistoryEvent::new(payload, deprecated_count),
                                    )
                                    .unwrap();
                            }
                            break;
                        }
                        Some(ObserverCommand::Value) => {
                            // only send batch if the last interval is min_interval in the past!

                            if next_batch_time <= tokio::time::Instant::now() {
                                let store_lock = store.lock().await;
                                // should never be false because the store should be updated before
                                // the notify (otherwise notify should not be called)
                                if store_lock.history().len() > latest_index {
                                    // go up from start_index and count how many messages are
                                    // deprecated afterwards update start_index

                                    let mut deprecated_count = 0;

                                    let now = std::time::Instant::now().duration_since(start_time);
                                    let breakpoint = now.saturating_sub(frame_size);
                                    for event in store_lock.history()[start_index..].iter() {
                                        if event.timestamp >= breakpoint {
                                            break;
                                        }
                                        deprecated_count += 1;
                                    }
                                    start_index += deprecated_count;

                                    let payload = &store_lock.history()[latest_index..];
                                    latest_index = store_lock.history().len();
                                    app_handle
                                        .emit_all(
                                            &event_name,
                                            ObjectEntryHistoryEvent::new(payload, deprecated_count),
                                        )
                                        .unwrap();
                                    next_batch_time = tokio::time::Instant::now() + min_interval;
                                    timeout = next_batch_time;
                                } else {
                                    //panic!("I assumed this should not be called, just checking here!");
                                }
                            }
                        }
                        None => {
                            panic!("rx_receiver closed early");
                        }
                    };
                }
                Err(_elapsed) => {
                    let store_lock = store.lock().await;
                    if store_lock.history().len() < latest_index {
                        let mut deprecated_count = 0;

                        let now = std::time::Instant::now().duration_since(start_time);
                        let breakpoint = now.saturating_sub(frame_size);
                        for event in store_lock.history()[start_index..].iter() {
                            if event.timestamp >= breakpoint {
                                break;
                            }
                            deprecated_count += 1;
                        }
                        start_index += deprecated_count;

                        let payload = &store_lock.history()[latest_index..];
                        latest_index = store_lock.history().len();
                        app_handle
                            .emit_all(
                                &event_name,
                                ObjectEntryHistoryEvent::new(payload, deprecated_count),
                            )
                            .unwrap();
                        next_batch_time = tokio::time::Instant::now() + min_interval;
                    }
                    timeout += Duration::from_secs(0xFFFF); //wait for ever!
                }
            }
        }
        // println!("start notify task {event_name}");
    }

    pub fn event_name(&self) -> &str {
        &self.event_name
    }
}
