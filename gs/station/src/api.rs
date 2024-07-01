use crate::GS_IP_ADDRESS;
use crate::{Command, Datatype, Info};
#[cfg(feature = "tui")]
use ratatui::prelude::Color;
#[cfg(feature = "tui")]
use std::str::FromStr;
use std::sync::mpsc::{Receiver, Sender};

include!("../../../util/src/shared/routes.rs");

#[derive(Debug, Clone, serde::Serialize, serde::Deserialize)]
pub struct Datapoint {
    pub datatype: Datatype,
    pub value: u64,
    pub timestamp: u64,
}

impl Datapoint {
    pub fn new(datatype: Datatype, value: u64, timestamp: u64) -> Self {
        Self {
            datatype,
            value,
            timestamp,
        }
    }
    pub fn from_bytes(buf: &[u8; 20]) -> Self {
        Datapoint::new(
            Datatype::from_id(u16::from_be_bytes([buf[1], buf[2]])),
            u64::from_le_bytes([
                buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9], buf[10],
            ]),
            u64::from_le_bytes([
                buf[11], buf[12], buf[13], buf[14], buf[15], buf[16], buf[17], buf[18],
            ]),
        )
    }
}

#[derive(Debug, Clone, serde::Serialize, serde::Deserialize)]
pub enum Message {
    Data(Datapoint),
    Status(Info),
    Info(String),
    Warning(String),
    Error(String),
}

impl Info {
    #[cfg(feature = "tui")]
    pub fn colour(&self) -> Color {
        Color::from_str(self.to_colour_str()).unwrap()
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
    unsafe { std::net::SocketAddr::new(std::net::IpAddr::from(GS_IP_ADDRESS.0), GS_IP_ADDRESS.1) }
}
