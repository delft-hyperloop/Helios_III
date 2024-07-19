use std::collections::VecDeque;

use gslib::Info;
use gslib::Message;
use gslib::NETWORK_BUFFER_SIZE;
use tokio::io::AsyncReadExt;
use tokio::net::tcp::OwnedReadHalf;

use crate::battery::DataSender;
use crate::CommandSender;
use crate::MessageSender;

pub async fn get_messages_from_tcp(
    mut reader: OwnedReadHalf,
    message_transmitter: MessageSender,
    command_transmitter: CommandSender,
    data_sender: DataSender,
) -> anyhow::Result<()> {
    let mut buffer = [0; { NETWORK_BUFFER_SIZE }];
    let mut byte_queue: VecDeque<u8> = VecDeque::new();
    loop {
        match reader.read(&mut buffer).await {
            Ok(0) => {
                message_transmitter.send(Message::Status(Info::ConnectionClosedByClient))?;
                message_transmitter
                    .send(Message::Warning("Connection closed by client".to_string()))?;
                message_transmitter
                    .send(Message::Error("Connection closed by client".to_string()))?;
                break;
            },
            Ok(n) => {
                #[cfg(debug_assertions)]
                // message_transmitter.send(Message::Info(format!("[TRACE] received {} bytes", n)))?;
                let _ = &buffer[..n].iter().for_each(|x| {
                    byte_queue.push_back(*x);
                });
                crate::connect::queueing::parse(
                    &mut byte_queue,
                    message_transmitter.clone(),
                    command_transmitter.clone(),
                    data_sender.clone(),
                )
                .await?;
            },
            Err(e) => {
                message_transmitter
                    .send(Message::Error(format!("Error reading from socket: {}", e)))?;
                break;
            },
        }
    }
    Ok(())
}
