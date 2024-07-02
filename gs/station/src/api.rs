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
    LeviProgramStarted,
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
            Status::LeviProgramStarted => Color::Green,
        }
    }
}

pub struct ApiStruct {
    pub command_sender: Sender<Command>,
    pub command_receiver: Receiver<Command>,
    pub message_sender: Sender<Message>,
    pub message_receiver: Receiver<Message>,
}

///
/// pub enum State {
/// 00    Boot,
/// 01    EstablishConnection,
/// 02    RunConfig,
/// 03    Idle,
/// 04    HVSystemChecking,
/// 05    Levitating,
/// 06    Accelerating,
/// 07    Cruising,
/// 08    LaneSwitch,
/// 09    Braking,
/// 10    EmergencyBraking,
/// 11    Exit,
/// 12    Crashing,
/// }
pub fn state_to_string(state: u64) -> String {
    match state {
        0 => "Boot".to_string(),
        1 => "EstablishConnection".to_string(),
        2 => "RunConfig".to_string(),
        3 => "Idle".to_string(),
        4 => "HVSystemChecking".to_string(),
        5 => "Levitating".to_string(),
        6 => "Accelerating".to_string(),
        7 => "Cruising".to_string(),
        8 => "LaneSwitch".to_string(),
        9 => "Braking".to_string(),
        10 => "EmergencyBraking".to_string(),
        11 => "Exit".to_string(),
        12 => "Crashing".to_string(),
        _ => "Unknown!!".to_string(),
    }
}