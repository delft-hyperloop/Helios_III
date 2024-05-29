use crate::NETWORK_BUFFER_SIZE;
use std::collections::VecDeque;
use tokio::io::AsyncReadExt;
use tokio::net::tcp::OwnedReadHalf;
use crate::api::Message;

pub async fn get_messages_from_tcp(
    mut reader: OwnedReadHalf,
    message_transmitter: tokio::sync::broadcast::Sender<crate::api::Message>,
) {
    let mut buffer = [0; { NETWORK_BUFFER_SIZE }];
    let mut byte_queue: VecDeque<u8> = VecDeque::new();
    loop {
        match reader.read(&mut buffer).await {
            Ok(0) => {
                message_transmitter
                    .send(crate::api::Message::Status(
                        crate::api::Status::ConnectionClosedByClient,
                    ))
                    .unwrap();
                message_transmitter
                    .send(crate::api::Message::Warning(
                        "Connection closed by client".to_string(),
                    ))
                    .unwrap();
                message_transmitter
                    .send(crate::api::Message::Error(
                        "Connection closed by client".to_string(),
                    ))
                    .unwrap();
                break;
            }
            Ok(n) => {
                message_transmitter.send(Message::Info(format!("[TRACE] received {} bytes", n))).unwrap();
                let _ = &buffer[..n].iter().for_each(|x| {
                    byte_queue.push_back(*x);
                });
                crate::connect::queueing::parse(&mut byte_queue, message_transmitter.clone()).await;
            }
            Err(e) => {
                message_transmitter
                    .send(crate::api::Message::Error(format!(
                        "Error reading from socket: {}",
                        e
                    )))
                    .unwrap();
                break;
            }
        }
    }
}