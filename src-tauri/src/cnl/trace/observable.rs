use std::{sync::{
    atomic::{AtomicUsize, Ordering},
    Arc,
}, time::Duration};

use tauri::Manager;
use tokio::time::interval;

use super::database::TraceDatabase;

pub struct TraceObservable {
    database: Arc<TraceDatabase>,
    event_name: &'static str,
    listen_count: Arc<AtomicUsize>,
    app_handle : tauri::AppHandle,
}

impl TraceObservable {
    pub fn new(app_handle : &tauri::AppHandle,event_name: &'static str, database: &Arc<TraceDatabase>) -> Self {
        Self {
            app_handle : app_handle.clone(),
            event_name,
            database: database.clone(),
            listen_count: Arc::new(AtomicUsize::new(0)),
        }
    }

    pub async fn listen(&self) -> &'static str {
        let prev_listen_count = self.listen_count.fetch_add(1, Ordering::SeqCst);
        if prev_listen_count == 0 {
            // start listening task
            tokio::spawn(notify_task(
                self.database.clone(),
                self.event_name,
                self.listen_count.clone(),
                self.app_handle.clone(),
            ));
        }
        self.event_name
    }

    pub async fn unlisten(&self) {
        let prev_listen_count = self.listen_count.fetch_sub(1, Ordering::SeqCst);
        if prev_listen_count == 1 {
            //  stop listening task
        }
    }
}

async fn notify_task(
    database: Arc<TraceDatabase>,
    event_name: &'static str,
    listen_count: Arc<AtomicUsize>,
    app_handle : tauri::AppHandle,
) {
    let mut interval = interval(Duration::from_millis(500));

    loop {
        interval.tick().await;
        if listen_count.load(Ordering::SeqCst) == 0 {
            break;
        }
        let sorted_and_filtered_frames = database.get_sorted_and_filtered_frames().await;
        app_handle.emit_all(event_name, sorted_and_filtered_frames).expect("Failed to emit trace event");
    }

}
