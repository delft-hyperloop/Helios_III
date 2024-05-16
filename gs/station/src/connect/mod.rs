mod handler;
mod parser;

use std::net::{IpAddr, TcpListener};
use std::sync::mpsc::{Receiver, Sender};
use crate::api::{Message, Status};
use crate::connect::handler::Handler;
use crate::{Command, Datatype, GS_SOCKET, POD_IP_ADDRESS};

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
            Datatype::from_id(u16::from_be_bytes([buf[2], buf[1]])),
            u64::from_be_bytes([buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9], buf[10]]),
            u64::from_be_bytes([buf[11], buf[12], buf[13], buf[14], buf[15], buf[16], buf[17], buf[18]]))
    }
}

pub struct Station {
    pub running : bool,
    pub connected: bool,
    pub listener : Option<TcpListener>,
}

impl Station {
    pub fn new() -> Self {
        Self {
            running: false,
            connected: false,
            listener: None,
        }
    }
    pub fn launch(&self, tx: Sender<Message>, rx: Receiver<Command>) {
        let server = TcpListener::bind(GS_SOCKET());

        if server.is_err() {
            tx.send(Message::Status(Status::ServerFailedToStart)).expect("[Station] Failed to send on msg tx");
            tx.send(Message::Error(format!("Failed to bind to {}", GS_SOCKET()))).expect("[Station] Failed to send on msg tx");
            return;
        }

        let listener = server.unwrap();
        tx.send(Message::Status(Status::ServerStarted)).expect("[Station] Failed to send on msg tx");
        tx.send(Message::Info(format!("Listening on {}", GS_SOCKET()))).expect("[Station] Failed to send on msg tx");
        match listener.accept() {
            Ok((stream, client_socket)) => {
                if client_socket.ip().ne(&IpAddr::from(POD_IP_ADDRESS.0)) {
                    tx.send(Message::Status(Status::UnknownClient)).expect("[Station] Failed to send on msg tx");
                    tx.send(Message::Error(format!("Unknown client tried to connect: {:?}", client_socket))).expect("[Station] Failed to send on msg tx");
                } else {
                    tx.send(Message::Status(Status::ConnectionEstablished)).expect("[Station] Failed to send on msg tx");
                    tx.send(Message::Info(format!("Client connected: {:?}", client_socket))).expect("[Station] Failed to send on msg tx");
                    let handler = Handler {};
                    handler.handle(stream, tx.clone(), rx);
                }
            }
            Err(e) => {
                tx.send(Message::Error(format!("Failed to accept connection: {}", e))).expect("[Station] Failed to send on msg tx");
            }
        }
        tx.send(Message::Status(Status::ConnectionDropped)).expect("[Station] Failed to send on msg tx");
        loop {}
    }
}
