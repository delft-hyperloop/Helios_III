pub mod app;
pub mod commands;
use std::fmt::Debug;
use std::sync::Mutex;

use gslib::Message;

use crate::backend::Backend;

#[derive(Debug, serde::Serialize, serde::Deserialize)]
pub struct BackendState {
    pub running: Mutex<bool>,
    pub data_buffer: Mutex<Vec<Message>>,
}

static mut BACKEND: Option<Mutex<Backend>> = None;

impl Default for BackendState {
    fn default() -> Self {
        Self {
            running: Mutex::new(false),
            data_buffer: Mutex::new(Vec::new()),
            // command_sender: None,
        }
    }
}
