use crate::Command;
use tokio::io::AsyncWriteExt;
use tokio::net::tcp::OwnedWriteHalf;

pub async fn transmit_commands_to_tcp(
    mut command_receiver: tokio::sync::broadcast::Receiver<crate::Command>,
    status_transmitter: tokio::sync::broadcast::Sender<crate::api::Message>,
    mut writer: OwnedWriteHalf,
) -> anyhow::Result<()> {
    tokio::spawn(async move {
        let mut last_send_timestamp = std::time::Instant::now();
        loop {
            if last_send_timestamp.elapsed().as_millis() > (crate::HEARTBEAT as u128) {
                last_send_timestamp = std::time::Instant::now();
                match writer
                    .write_all(&Command::as_bytes(&Command::Heartbeat(42)))
                    .await
                {
                    Ok(_) => {
                        status_transmitter.send(crate::api::Message::Info(
                            "[TRACE][tcp] Sent keepalive".to_string(),
                        )).expect("messaging channel closed, cannot recover");
                    }
                    Err(e) => {
                        eprintln!("Error sending keepalive over tcp: {:?}", e);
                        break;
                    }
                }
            }
            #[allow(clippy::single_match)]
            match command_receiver.try_recv() {
                Ok(command) => {
                    let bytes = command.as_bytes();
                    match writer.write_all(&bytes).await {
                        Ok(_) => {
                            last_send_timestamp = std::time::Instant::now();
                            status_transmitter.send(crate::api::Message::Info(format!(
                                "[tcp] Sent command: {:?}",
                                command
                            ))).expect("messaging channel closed, cannot recover");
                        }
                        Err(e) => {
                            eprintln!("Error sending command over tcp: {:?}", e);
                            break;
                        }
                    }
                }
                // Err(e) if !matches!(e, tokio::sync::broadcast::error::TryRecvError(_)) => {
                //     eprintln!("Error receiving command from broadcast: {:?}", e);
                //     break;
                // }
                _ => {}
            }
        }
    });
    Ok(())
}
