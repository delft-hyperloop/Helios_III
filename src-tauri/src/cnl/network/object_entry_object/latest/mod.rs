use std::{
    sync::{atomic::AtomicUsize, Arc},
    time::Duration,
};

use color_print::cprintln;
use tauri::Manager;
use tokio::sync::{mpsc, Mutex};

use crate::cnl::network::object_entry_object::latest::event::ObjectEntryEvent;

use super::database::ObjectEntryDatabase;

pub mod event;

enum ObserverCommand {
    Value,
    Poison,
}

pub struct ObjectEntryLatestObservable {
    min_interval: Duration,
    event_name: String,
    listen_count: AtomicUsize,
    app_handle: tauri::AppHandle,

    tx: mpsc::Sender<ObserverCommand>,
    rx: Arc<Mutex<mpsc::Receiver<ObserverCommand>>>,
}

impl ObjectEntryLatestObservable {
    pub fn new(event_name: &str, min_interval: Duration, app_handle: &tauri::AppHandle) -> Self {
        let (tx, rx) = mpsc::channel(128);
        Self {
            event_name: event_name.to_owned(),
            listen_count: AtomicUsize::new(0),
            min_interval,
            app_handle: app_handle.clone(),
            rx: Arc::new(Mutex::new(rx)),
            tx,
        }
    }

    pub async fn notify(&self) {
        if self.listen_count.load(std::sync::atomic::Ordering::SeqCst) != 0 {
            if let Err(_) = self.tx.send_timeout(ObserverCommand::Value, Duration::from_millis(1000)).await {
                cprintln!("<red> Failed to notify latest observable. MPCS capacity is full, dropping the value </red>");
            }
        }
    }

    pub fn listen(&self, store: &Arc<Mutex<ObjectEntryDatabase>>) {
        let prev_count = self
            .listen_count
            .fetch_add(1, std::sync::atomic::Ordering::SeqCst);
        if prev_count == 0 {
            // this indicates that the batching task should be started
            self.start_notify_task(store);
        }
    }

    pub async fn unlisten(&self) {
        let prev_count = self
            .listen_count
            .fetch_sub(1, std::sync::atomic::Ordering::SeqCst);
        if prev_count == 1 {
            // this indicates that the batching task should be stoped
            self.stop_notify_task().await;
        }
    }

    pub fn start_notify_task(&self, store: &Arc<Mutex<ObjectEntryDatabase>>) {
        tokio::spawn(Self::notify_task(
            self.event_name.clone(),
            self.min_interval.clone(),
            self.app_handle.clone(),
            self.rx.clone(),
            store.clone(),
        ));
    }

    pub async fn stop_notify_task(&self) {
        self.tx
            .send_timeout(ObserverCommand::Poison, Duration::from_millis(1000))
            .await
            .expect("Failed to send posion message to latest observable");
    }

    async fn notify_task(
        event_name: String,
        min_interval: Duration,
        app_handle: tauri::AppHandle,
        rx: Arc<Mutex<mpsc::Receiver<ObserverCommand>>>,
        store: Arc<Mutex<ObjectEntryDatabase>>,
    ) {
        let mut rx = rx.lock().await;
        let mut next_batch_time = tokio::time::Instant::now();
        let mut timeout = tokio::time::Instant::now() + Duration::from_secs(0xFFFF);
        loop {
            match tokio::time::timeout_at(timeout, rx.recv()).await {
                Ok(opt) => {
                    match opt {
                        Some(ObserverCommand::Poison) => {
                            match store.lock().await.latest_value() {
                                Some(latest) => {
                                    app_handle
                                        .emit_all(
                                            &event_name,
                                            ObjectEntryEvent::new(latest),
                                        )
                                        .unwrap();
                                }
                                None => (),
                            };
                            break;
                        }
                        Some(ObserverCommand::Value) => {
                            // only send batch if the last interval is min_interval in the past!
                            if next_batch_time <= tokio::time::Instant::now() {
                                app_handle
                                    .emit_all(
                                        &event_name,
                                        // TODO try to refactor object entry event to not require a
                                        // clone here (lifetimes)
                                        ObjectEntryEvent::new(
                                            store
                                                .lock()
                                                .await
                                                .latest_value()
                                                .expect("no latest value avaiable"),
                                        ),
                                    )
                                    .unwrap();
                                next_batch_time = tokio::time::Instant::now() + min_interval;
                                timeout = next_batch_time;
                            }
                        }
                        None => {
                            panic!("rx_receiver closed early");
                        }
                    };
                }
                Err(_elapsed) => {
                    match store.lock().await.latest_value() {
                        Some(latest) => {
                            app_handle.emit_all(&event_name, ObjectEntryEvent::new(latest)).unwrap();
                            next_batch_time = tokio::time::Instant::now() + min_interval;
                        }
                        None => (),
                    };
                    timeout += Duration::from_secs(0xFFFF); //wait for ever!
                }
            }
        }
    }
}
