use std::sync::mpsc::{Receiver, Sender};
use crate::api::{Command, Datapoint};

use crate::gui::main::{App, LogType};

impl App {
    pub fn new(tx:Sender<Command>, rx: Receiver<Datapoint>) -> Self {
        let mut safety_data: Vec<(f64, f64)> = vec![];
        for i in 0..200 {
            safety_data.push((i as f64 / 20.0, 5.0 + 3.0*f64::sin((i as f64)*0.1)));
        }
        Self {
            logs: vec![(LogType::Info, "Started GUI".to_string())],
            exit: false,
            tx,
            rx,
            safety_score: safety_data,
        }
    }
    pub fn exit(&mut self) {
        self.exit = true;
    }


}