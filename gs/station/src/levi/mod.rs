mod handler;
mod writer;
mod parser;

use std::sync::mpsc::{Receiver, Sender};
use crate::api::Message;
use crate::api::Status::LeviProgramStarted;
use crate::Command;

pub fn start_levi_process() -> (Receiver<Message>, Sender<Command>) {
    let (data_sender, data_receiver) = std::sync::mpsc::channel();
    let (command_sender, command_receiver) = std::sync::mpsc::channel();
    data_sender.send(Message::Status(LeviProgramStarted)).unwrap();
    std::thread::spawn(move ||
        handler::run_levi_software(data_sender, command_receiver)
    );
    (data_receiver, command_sender)
}