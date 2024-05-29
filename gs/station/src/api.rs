use std::sync::mpsc::{Receiver, Sender};
#[cfg(feature = "tui")]
use ratatui::prelude::Color;
use crate::Command;
use crate::connect::Datapoint;
use crate::GS_IP_ADDRESS;


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
    #[cfg(feature = "tui")]
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
        6 => "MovingST".to_string(),
        7 => "MovingLSST".to_string(),
        8 => "MovingLSCV".to_string(),
        9 => "EndST".to_string(),
        10 => "EmergencyBraking".to_string(),
        11 => "Exit".to_string(),
        12 => "Crashing".to_string(),
        _ => "Unknown!!".to_string(),
    }
}

pub fn gs_socket() -> std::net::SocketAddr {
    std::net::SocketAddr::new(std::net::IpAddr::from(GS_IP_ADDRESS.0), GS_IP_ADDRESS.1)
}