use tauri::Manager;
use chrono::{DateTime, Local};

// TODO remove allow dead_code before release!
#[derive(Clone)]
pub enum NotificationLevel {
    #[allow(dead_code)]
    Info,

    #[allow(dead_code)]
    Debug,

    #[allow(dead_code)]
    Warning,

    Error,
}

impl serde::Serialize for NotificationLevel {
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: serde::Serializer,
    {
        match &self {
            NotificationLevel::Info => serializer.serialize_str("info"),
            NotificationLevel::Debug => serializer.serialize_str("debug"),
            NotificationLevel::Warning => serializer.serialize_str("warning"),
            NotificationLevel::Error => serializer.serialize_str("error"),
        }
    }
}

#[derive(serde::Serialize, Clone)]
pub struct Notification {
    level: NotificationLevel,
    title: String,
    message: String,
}

impl Notification {
    pub fn new(level: NotificationLevel, title: &str, msg: &str, time_stamp: DateTime<Local>) -> Notification {
        Notification {
            level,
            title: title.to_owned(),
            message: time_stamp.format("%H:%M -- ").to_string() + msg,
        }
    }
}


pub fn notify_error(app_handle : &tauri::AppHandle, reason: &str, description: &str, time_stamp: DateTime<Local>) {
    app_handle
        .emit_all(
            "notification",
            Notification::new(NotificationLevel::Error, reason, description, time_stamp),
        )
        .expect("failed to emit notification");
}

pub fn notify_warning(app_handle : &tauri::AppHandle, reason: &str, description: &str, time_stamp: DateTime<Local>) {
    app_handle
        .emit_all(
            "notification",
            Notification::new(NotificationLevel::Warning, reason, description, time_stamp),
        )
        .expect("failed to emit notification");
}

pub fn notify_info(app_handle : &tauri::AppHandle, reason: &str, description: &str, time_stamp: DateTime<Local>) {
    app_handle
        .emit_all(
            "notification",
            Notification::new(NotificationLevel::Info, reason, description, time_stamp),
        )
        .expect("failed to emit notification");
}
