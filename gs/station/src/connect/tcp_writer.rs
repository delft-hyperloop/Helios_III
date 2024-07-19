use gslib::Message;
use gslib::Message::Error;
use gslib::HEARTBEAT;
use tokio::io::AsyncWriteExt;
use tokio::net::tcp::OwnedWriteHalf;

use crate::Command;
use crate::CommandReceiver;
use crate::MessageSender;

pub async fn transmit_commands_to_tcp(
    mut command_receiver: CommandReceiver,
    status_transmitter: MessageSender,
    mut writer: OwnedWriteHalf,
) -> anyhow::Result<()> {
    let mut last_send_timestamp = std::time::Instant::now();
    loop {
        if last_send_timestamp.elapsed().as_millis() > (HEARTBEAT as u128) {
            last_send_timestamp = std::time::Instant::now();
            match writer.write_all(&Command::as_bytes(&Command::Heartbeat(42))).await {
                Ok(_) => {
                    // status_transmitter
                    //     .send(Message::Info(
                    //         "[TRACE][tcp] Sent keepalive".to_string(),
                    //     ))
                    //     .expect("messaging channel closed, cannot recover");
                },
                Err(e) => {
                    //eprintln!("Error sending keepalive over tcp: {:?}", e);
                    status_transmitter
                        .send(Error(format!("Error sending keepalive over tcp: {:?}", e)))
                        .unwrap();
                    break;
                },
            }
        }
        #[allow(clippy::single_match)]
        match command_receiver.try_recv() {
            Ok(command) => {
                if matches!(command, Command::Shutdown(_)) {
                    status_transmitter
                        .send(Message::Warning("Closing connection...".into()))
                        .unwrap();
                    writer.shutdown().await.unwrap();
                    break;
                }
                let bytes = command.as_bytes();
                match writer.write_all(&bytes).await {
                    Ok(_) => {
                        last_send_timestamp = std::time::Instant::now();
                        // status_transmitter
                        //     .send(Message::Info(format!(
                        //         "[tcp] Sent command: {:?}",
                        //         command
                        //     )))
                        //     .expect("messaging channel closed, cannot recover");
                    },
                    Err(e) => {
                        // eprintln!("Error sending command over tcp: {:?}", e);
                        status_transmitter
                            .send(Error(format!("Error sending command over tcp: {:?}", e)))
                            .expect("message channel closed");
                        break;
                    },
                }
            },
            // Err(e) if !matches!(e, tokio::sync::broadcast::error::TryRecvError(_)) => {
            //     eprintln!("Error receiving command from broadcast: {:?}", e);
            //     break;
            // }
            _ => {},
        }
    }
    Ok(())
}
