mod station;

use std::net::{SocketAddr, TcpListener, TcpStream};
use std::process::exit;
use std::sync::mpsc::{Receiver, Sender};
use std::sync::{Mutex, RwLock};
use colored::Colorize;
use crate::api::{Command, Datapoint};
use crate::gui::main::LogType;
use crate::log;

/// The connection manager of the application. This module is responsible for
/// managing the connection to the main PCB.
///
/// It offers a few interface functions:
/// - `launch` to start the connection
/// - `stop` to gracefully stop the connection
/// - `send(command)` to send a command to the main PCB
/// - `get_state()` to get the main PCB's FSM state
/// - ...
include!(concat!(env!("OUT_DIR"), "/config.rs"));

// pub enum Event {
//     ConnectionClosed,
//
// }

#[derive(Debug)]
pub struct Station {
    pub running : bool,
    pub connected: bool,
    pub gs_socket : SocketAddr,
    pub listener : TcpListener,
    pub tx: Sender<Datapoint>,
    pub rx: Mutex<Receiver<Command>>,
    // pub event_tx: Sender<Event>,
    // pub event_rx: Receiver<Event>
}

impl Station {
    pub fn print(msg: String, tx: Sender<Datapoint>) {
        tx.send(Datapoint::Status(msg)).unwrap()
    }
    pub fn eprint(msg: &str, tx: Sender<Datapoint>) {
        tx.send(Datapoint::Error(msg.parse().unwrap())).unwrap()
    }
}

/// The main function of the connection handler,
/// it will open a socket and wait for the pod to connect,
/// then create a connection object and handle it
pub fn launch(tx : Sender<Datapoint>, rx : Receiver<Command>) {
    let server = TcpListener::bind(GS_SOCKET());

    if server.is_err() {
        println!("{}\n  IP={}\n  timestamp={}\n", "Server failed to start".on_bright_red(), GS_SOCKET().ip().to_string(),chrono::Utc::now().timestamp().to_string());
        println!("{}", "Try changing ../config/config.toml".bright_yellow());
        exit(1);
    }

    let mut station: Station = Station::new(GS_SOCKET(), server.unwrap(), tx, rx);

    while station.running {
        log!(station.tx.clone(), LogType::Info, format!("Waiting for connection on {}", station.gs_socket.to_string()));
        match station.listener.accept() {
            Ok((stream, addr)) => {
                station.connected = true;
                station.run(stream, addr); // this will be run from the server main thread since a) we dont want it to die and b) we will only ever accept one connection: the main pcb
            },
            Err(e) => log!(station.tx.clone(), LogType::Error, format!("couldn't get client: {e:?}")),
        }

        if station.running {// if we get here the station disconnected from the main pcb.
            log!(station.tx.clone(), LogType::Error, "Connection terminated");
            log!(station.tx.clone(), LogType::Warning, "Connection was terminated! Trying to reconnect automatically.");
        }
    }
    println!("Shutting down ground station");
}

/// TODO: implement receiving shit from the pod.
/// for this we need to use the file of data types corresponding to message ids
pub fn receive(buffer: [u8;IP_BUFFER_SIZE], n: usize, tx_channel : Sender<Datapoint> ) {
    // Process the received data.
    // let data = String::from_utf8(Vec::from(&buffer[..n])).expect("failed to convert buffer to string");
    tx_channel.send(Datapoint::Status(format!("received {:?}", &buffer[..n]))).expect("TODO: panic message");
}