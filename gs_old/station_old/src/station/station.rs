use std::fmt::format;
use std::io::{Read, Write};
use std::net::{SocketAddr, TcpListener, TcpStream};
use std::sync::{Arc, Mutex, RwLock};
use std::sync::mpsc::{Receiver, Sender};
use std::thread;
use colored::Colorize;
use crossterm::style::Stylize;
use crate::api::{Command, Datapoint};
use crate::gui::main::LogType;
use crate::log;
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
        log!(self.tx.clone(), LogType::Success,format!("{} {}", "Accepted connection from", format!("{:?}", client_socket)));

        // Split the TcpStream into read and write parts
        let mut read_stream = stream.try_clone().expect("Failed to clone stream");
        let mut write_stream = stream;

        let (disconnect_send, disconnect_receive) = std::sync::mpsc::channel();

        let tx_clone = self.tx.clone();
        thread::spawn(move || {
            let mut buffer = [0; IP_BUFFER_SIZE];
            let mut last_read_timestamp = std::time::Instant::now();
            read_stream.set_read_timeout(Some(std::time::Duration::from_millis(IP_TIMEOUT))).unwrap();
            loop {
                 match read_stream.read(&mut buffer) {
                     Ok(0) => {
                         log!(tx_clone.clone(), LogType::Error, "Connection closed by Main PCB!!");
                         disconnect_send.send(0).unwrap();
                         break;
                     }
                     Ok(n) => {
                         last_read_timestamp = std::time::Instant::now();
                         receive(buffer, n, tx_clone.clone());
                     }
                     Err(e) => {
                         log!(tx_clone.clone(), LogType::Error, format!("Failed to read from connection: {}", e));
                         disconnect_send.send(0).unwrap();
                         break;
                     }
                }
                // if last_read_timestamp.elapsed().as_secs() > 5 {
                //     log!(tx_clone.clone(), LogType::Error, "Connection timed out!!");
                //     disconnect_send.send(0).unwrap();
                //     break;
                // }
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
                        log!(self.tx.clone(), LogType::Info, format!("Sending command: {}", data));
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            log!(self.tx.clone(), LogType::Error, &format!("Failed to send data: {}", e));
                            break;
                        }
                    }

                    Command::StopLevitating => {
                        // Example: Send the data from the event
                        let data = "STOP LEVITATING";
                        log!(self.tx.clone(), LogType::Info, format!("Sending command: {}", data));
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            log!(self.tx.clone(), LogType::Error, format!("Failed to send data: {}", e));
                            break;
                        }
                    }

                    Command::Configure(config) => {
                        // Example: Send the data from the event
                        let data = format!("CONFIGURE {:?}", config);
                        log!(self.tx.clone(), LogType::Info, format!("Sending command: {}", data));
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            log!(self.tx.clone(), LogType::Error, format!("Failed to send data: {}", e));
                            break;
                        }
                    }

                    Command::Shutdown => {
                        // Example: Send the data from the event
                        let data = "SHUTDOWN";
                        log!(self.tx.clone(), LogType::Info, format!("Sending command: {}", data));
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            log!(self.tx.clone(), LogType::Error, format!("Failed to send data: {}", e));
                            break;
                        }
                        log!(self.tx.clone(), LogType::Info, "Shutting down the connection.");
                        break;
                    }

                    Command::EmergencyBrake => {
                        // Example: Send the data from the event
                        let data = "EMERGENCY BRAKE";
                        log!(self.tx.clone(), LogType::Info, format!("Sending command: {}", data));
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            log!(self.tx.clone(), LogType::Error, format!("Failed to send data: {}", e));
                            break;
                        }
                    }

                    Command::StartRun => {
                        // Example: Send the data from the event
                        let data = "START RUN";
                        log!(self.tx.clone(), LogType::Info, format!("Sending command: {}", data));
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            log!(self.tx.clone(), LogType::Error, format!("Failed to send data: {}", e));
                            break;
                        }
                    }

                    Command::EmitEvent(e) => {
                        let mut data = [0u8; 4];

                        data[2..4] = *e.to_id().to_be_bytes();

                        log!(self.tx.clone(), LogType::Info, format!("Sending command: {}", data));
                        if let Err(e) = write_stream.write_all(data.as_bytes()) {
                            log!(self.tx.clone(), LogType::Error, format!("Failed to send data: {}", e));
                            break;
                        }
                    }
                }
                Err(std::sync::mpsc::TryRecvError::Empty) => {
                    // No command received
                }
                Err(std::sync::mpsc::TryRecvError::Disconnected) => {
                    log!(self.tx.clone(), LogType::Error, format!("Failed to receive command: channel disconnected"));
                    break;
                }
            }
            // check if the sender has disconnected
            if disconnect_receive.try_recv().is_ok() {
                log!(self.tx.clone(), LogType::Warning, "Closing receiver: sender disconnected");
                break;
            }
        }
    }



}