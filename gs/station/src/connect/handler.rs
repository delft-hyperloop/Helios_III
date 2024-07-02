use std::io::{Read, Write};
use std::net::TcpStream;
use std::sync::mpsc::{Receiver, Sender};
use crate::api::{Message, Status};
use crate::{Command, NETWORK_BUFFER_SIZE};


pub struct Handler {
    // pub socket: std::net::SocketAddr,
    // pub connection: std::net::TcpStream,
    // pub messenger: Sender<Message>,
    // pub commander: Receiver<Command>,
    // pub alive: bool,
}

impl<'h> Handler {
    pub fn handle(&self, stream: TcpStream, tx: Sender<Message>, rx: Receiver<Command>) {
        let read_stream;
        match stream.try_clone() {
            Ok(rs) => {
                read_stream = rs;
            }
            Err(e) => {
                tx.send(Message::Error(format!("Failed to clone stream: {}", e))).expect("[Handler] Failed to send on msg tx");
                return;
            }
        }
        let write_stream = stream;
        let tx_handle = std::thread::spawn(move || {Self::pod_incoming_handler(read_stream, tx);});
        let rx_handle = std::thread::spawn(move || {Self::pod_outgoing_handler(write_stream, rx);});

        tx_handle.join().expect("[Handler] TCP Receiver has panicked.");
        rx_handle.join().expect("[Handler] TCP Sender has panicked.");
        return;
    }

    fn pod_incoming_handler(mut read_stream: TcpStream, tx: Sender<Message>) {
        let mut buf = [0u8; { NETWORK_BUFFER_SIZE }];
        let mut byte_queue : Vec<u8> = vec![];
        'tcp_reading: loop {
            match read_stream.read(&mut buf) {
                Ok(0) => {
                    let _ = &tx.send(Message::Status(Status::ConnectionClosedByClient)).expect("[Handler] Failed to send on msg tx");
                    let _ = &tx.send(Message::Error("Connection closed by Main PCB!!".to_string())).expect("[Handler] Failed to send on msg tx");
                    break 'tcp_reading;
                }
                Ok(n) => {
                    byte_queue.append(&mut buf[..n].to_vec());
                }
                Err(e) => {
                    let _ = &tx.send(Message::Error(format!("Failed to read from connection: {}", e))).expect("[Handler] Failed to send on msg tx");
                    break 'tcp_reading;
                }
            }
            Handler::parse(&mut byte_queue, tx.clone());
        }
    }

    fn pod_outgoing_handler(mut write_stream: TcpStream, rx: Receiver<Command>) {
        'tcp_writing: loop {
            let command = rx.recv().expect("[Handler] Failed to receive on command rx");
            match write_stream.write_all(&command.as_bytes()) {
                Ok(_) => {}
                Err(e) => {
                    println!("Failed to write to connection: {}", e);
                    break 'tcp_writing;
                }
            }
        }
    }
}
