use std::sync::mpsc::{Receiver, Sender};
use ratatui::prelude::Color;
use crate::Command;
use crate::connect::Datapoint;

#[derive(Debug, Clone, serde::Serialize, serde::Deserialize)]
pub enum Status {
    ServerStarted,
    ServerFailedToStart,
    UnknownClient,
    ConnectionEstablished,
    ConnectionClosedByClient,
    ConnectionClosedByServer,
    ConnectionDropped,
    FailedToReadFromConnection,
}

#[derive(Debug, Clone, serde::Serialize, serde::Deserialize)]
pub enum Message {
    Data(Datapoint),
    Status(Status),
    Info(String),
    Warning(String),
    Error(String),
}

impl Status {
    pub fn colour(&self) -> Color {
        match self {
            Status::ServerStarted => Color::Green,
            Status::ServerFailedToStart => Color::Red,
            Status::UnknownClient => Color::Yellow,
            Status::ConnectionEstablished => Color::Green,
            Status::ConnectionClosedByClient => Color::Yellow,
            Status::ConnectionClosedByServer => Color::Yellow,
            Status::ConnectionDropped => Color::Red,
            Status::FailedToReadFromConnection => Color::Red,
        }
    }
}

pub struct ApiStruct {
    pub command_sender: Sender<Command>,
    pub command_receiver: Receiver<Command>,
    pub message_sender: Sender<Message>,
    pub message_receiver: Receiver<Message>,
}