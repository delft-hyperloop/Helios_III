use tokio::io::AsyncWriteExt;
use tokio::net::tcp::OwnedWriteHalf;

pub async fn transmit_commands_to_tcp(
    mut command_receiver: tokio::sync::broadcast::Receiver<crate::Command>,
    stats_transmitter: tokio::sync::broadcast::Sender<crate::api::Message>,
    mut writer: OwnedWriteHalf,
) {
    tokio::spawn(async move {
        loop {
            match command_receiver.recv().await {
                Ok(command) => {
                    let bytes = command.as_bytes();
                    match writer.write_all(&bytes).await {
                        Ok(_) => {
                            stats_transmitter
                                .send(crate::api::Message::Info(format!(
                                    "[tcp] Sent command: {:?}",
                                    command
                                )))
                                .unwrap();
                        }
                        Err(e) => {
                            eprintln!("Error sending command over tcp: {:?}", e);
                        }
                    }
                }
                Err(e) => {
                    eprintln!("Error receiving command from broadcast: {:?}", e);
                    break;
                }
            }
        }
    });
}
