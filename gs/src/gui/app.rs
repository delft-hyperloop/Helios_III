use std::sync::mpsc::{Receiver, Sender};
use crate::{Command, Datapoint};
use crate::gui::main::App;

impl App {
    pub fn new(tx:Sender<Command>, rx: Receiver<Datapoint>) -> Self {
        Self {
            logs: vec!["Started GUI".to_string()],
            exit: false,
            tx,
            rx,
        }
    }
    pub fn exit(&mut self) {
        self.exit = true;
    }


}