pub(crate) mod main;

use crate::api::Message;
use crate::backend::Backend;
use std::fmt::Debug;
use std::sync::Mutex;

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
