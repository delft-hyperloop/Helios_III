use std::sync::atomic::AtomicUsize;

use tauri::Manager;
use tokio::{
    sync::{watch, RwLock},
    task::AbortHandle,
};

use crate::cnl::watchdog::WdgStatus;

pub struct HeartbeatObservable {
    event_name: String,
    listen_count: AtomicUsize,
    app_handle: tauri::AppHandle,
    rx_status: watch::Receiver<WdgStatus>,
    abort_handle: RwLock<Option<AbortHandle>>,
    bus_id: u32
}

impl HeartbeatObservable {
    pub fn new(
        event_name: &str,
        app_handle: &tauri::AppHandle,
        rx_status: watch::Receiver<WdgStatus>,
        bus_id: u32
    ) -> Self {
        Self {
            event_name: event_name.to_owned(),
            listen_count: AtomicUsize::new(0),
            app_handle: app_handle.clone(),
            rx_status,
            abort_handle: RwLock::new(None),
            bus_id,
        }
    }

    pub fn bus_id(&self) -> u32 {
        self.bus_id
    }

    pub async fn listen(&self) -> String {
        let prev_count = self
            .listen_count
            .fetch_add(1, std::sync::atomic::Ordering::SeqCst);
        if prev_count == 0 {
            self.start_notify_task().await;
        }
        self.event_name.clone()
    }

    pub async fn unlisten(&self) {
        let prev_count = self
            .listen_count
            .fetch_sub(1, std::sync::atomic::Ordering::SeqCst);
        if prev_count == 1 {
            self.stop_notify_task().await;
        }
    }

    pub async fn start_notify_task(&self) {
        *self.abort_handle.write().await = Some(
            tokio::spawn(Self::notify_task(
                self.event_name.clone(),
                self.app_handle.clone(),
                self.rx_status.clone(),
            ))
            .abort_handle(),
        );
    }

    pub async fn stop_notify_task(&self) {
        match &(*self.abort_handle.read().await) {
            Some(h) => h.abort(),
            None => todo!(),
        };
    }

    async fn notify_task(
        event_name: String,
        app_handle: tauri::AppHandle,
        mut rx_status: watch::Receiver<WdgStatus>,
    ) {
        loop {
            let _ = rx_status.changed().await;
            app_handle
                .emit_all(event_name.as_str(), *rx_status.borrow_and_update())
                .expect("Failed to emit heartbeat status");
        }
    }
}

