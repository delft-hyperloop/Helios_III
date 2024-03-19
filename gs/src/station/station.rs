use std::io::{Read, Write};
use std::net::{SocketAddr, TcpListener, TcpStream};
use std::sync::{Arc, Mutex, RwLock};
use std::sync::mpsc::{Receiver, Sender};
use std::thread;
use colored::Colorize;
use crossterm::style::Stylize;
use crate::{Command, Datapoint};
use crate::station::{receive, Station};
// use crate::station::Event;
include!(concat!(env!("OUT_DIR"), "/config.rs"));

impl Station {
    pub fn new(socket: SocketAddr, listener: TcpListener, tx: Sender<Datapoint>, rx: Receiver<Command>) -> Station {
        // let (etx, erx) = std::sync::mpsc::channel();
        Station {
            running: true,
            connected: false,
            gs_socket: socket,
            listener,
            tx,
            rx: Mutex::new(rx),
            // event_rx: erx,
            // event_tx: etx,
        }
    }

    pub fn run(&mut self, mut stream: TcpStream, client_socket: SocketAddr) {
        // We have a connection, now we ball
        println!("{} {}", "Accepted connection from".bright_green(), format!("{:?}", client_socket).on_bright_blue());

        // Split the TcpStream into read and write parts
        let mut read_stream = stream.try_clone().expect("Failed to clone stream");
        let mut write_stream = stream;

        let (disconnect_send, disconnect_receive) = std::sync::mpsc::channel();

        let tx_clone = self.tx.clone();
        thread::spawn(move || {
            let mut buffer = [0; IP_BUFFER_SIZE];
            loop {
                 match read_stream.read(&mut buffer) {
                     Ok(0) => {
                         println!("{}", "Connection closed by Main PCB!!".on_bright_red());
                         disconnect_send.send(()).unwrap();
                         break;
                     }
                     Ok(n) => {
                         receive(buffer, n, tx_clone.clone());
                     }
                     Err(e) => {
                         eprintln!("Failed to read from connection: {}", e);
                         disconnect_send.send(()).unwrap();
                     }
                }
            }
        });


        // (main thread) sending data in response to events
        loop {
            let received_event = self.rx.lock().unwrap().try_recv();
            match received_event {
                Ok(cmd) => match cmd {
                    Command::Levitate => {
                        // Example: Send the data from the event
                        let data = "LEVITATE";
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            eprintln!("Failed to send data: {}", e);
                            break;
                        }
                    }

                    Command::StopLevitating => {
                        // Example: Send the data from the event
                        let data = "STOP LEVITATING";
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            eprintln!("Failed to send data: {}", e);
                            break;
                        }
                    }

                    Command::Configure(config) => {
                        // Example: Send the data from the event
                        let data = format!("CONFIGURE {:?}", config);
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            eprintln!("Failed to send data: {}", e);
                            break;
                        }
                    }

                    Command::Shutdown => {
                        // Example: Send the data from the event
                        let data = "SHUTDOWN";
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            eprintln!("Failed to send data: {}", e);
                            break;
                        }
                        println!("Shutting down the connection.");
                        // .shutdown(std::net::Shutdown::Both).expect("Failed to shutdown connection");
                        break;
                    }

                    Command::EmergencyBrake => {
                        // Example: Send the data from the event
                        let data = "EMERGENCY BRAKE";
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            eprintln!("Failed to send data: {}", e);
                            break;
                        }
                    }

                    Command::StartRun => {
                        // Example: Send the data from the event
                        let data = "START RUN";
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            eprintln!("Failed to send data: {}", e);
                            break;
                        }
                    }
                }
                Err(std::sync::mpsc::TryRecvError::Empty) => {
                    // No command received
                }
                Err(std::sync::mpsc::TryRecvError::Disconnected) => {
                    eprintln!("Failed to receive command: channel disconnected");
                    break;
                }
            }
            // check if the sender has disconnected
            if disconnect_receive.try_recv().is_ok() {
                println!("Closing receiver: sender disconnected");
                break;
            }
        }
    }



}