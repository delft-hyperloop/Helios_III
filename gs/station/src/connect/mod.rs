mod handler;
mod parser;

use std::net::{IpAddr, TcpListener};
use std::sync::mpsc::{Receiver, Sender};
use std::sync::Mutex;
use crate::api::{Message, Status};
use crate::connect::handler::Handler;
use crate::{Command, Datatype, GS_SOCKET, POD_IP_ADDRESS};

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
}

pub struct Station {
    pub running : bool,
    pub connected: bool,
    pub listener : TcpListener,
    pub tx: Sender<Message>,
    pub rx: Mutex<Receiver<Command>>,
}

impl Station {
    pub fn launch(tx: Sender<Message>, rx: Receiver<Command>) -> (Sender<Message>, Receiver<Command>) {
        let server = TcpListener::bind(GS_SOCKET());

        if server.is_err() {
            tx.send(Message::Status(Status::ServerFailedToStart)).expect("[Station] Failed to send on msg tx");
            tx.send(Message::Error(format!("Failed to bind to {}", GS_SOCKET()))).expect("[Station] Failed to send on msg tx");
            return (tx, rx);
        }

        let listener = server.unwrap();
        return match listener.accept() {
            Ok((stream, client_socket)) => {
                if client_socket.ip().ne(&IpAddr::from(POD_IP_ADDRESS.0)) {
                    tx.send(Message::Status(Status::UnknownClient)).expect("[Station] Failed to send on msg tx");
                    tx.send(Message::Error(format!("Unknown client tried to connect: {:?}", client_socket))).expect("[Station] Failed to send on msg tx");
                    (tx, rx)
                } else {
                    let handler = Handler {};
                    handler.handle(stream, tx, rx)
                }
            }
            Err(e) => {
                tx.send(Message::Error(format!("Failed to accept connection: {}", e))).expect("[Station] Failed to send on msg tx");
                (tx, rx)
            }
        }
    }
}