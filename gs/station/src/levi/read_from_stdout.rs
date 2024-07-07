use tokio::io::AsyncBufReadExt;

use crate::api::Message;
use crate::levi::parse_input::handle_line_from_levi;
use crate::Command;

/// # Read from levi child stdout
/// reads from the stdout of the levi child process, and sends the messages to the message_transmitter.
pub async fn read_from_levi_child_stdout(
    stdout: tokio::process::ChildStdout,
    message_transmitter: tokio::sync::broadcast::Sender<Message>,
    command_transmitter: tokio::sync::broadcast::Sender<Command>,
) -> anyhow::Result<()> {
    let mut reader = tokio::io::BufReader::new(stdout);
    let mut line = String::new();
    loop {
        match reader.read_line(&mut line).await {
            Ok(0) => {
                message_transmitter.send(Message::Error("Levi stdout closed.".to_string()))?;
                break;
            },
            Ok(_n) => {
                // message_transmitter.send(Message::Info(format!(
                //     "[TRACE] RECEIVED LEVI: ({}), {:?}",
                //     n, &line
                // )))?;
                handle_line_from_levi(
                    &line,
                    message_transmitter.clone(),
                    command_transmitter.clone(),
                )?;
            },
            Err(e) => {
                message_transmitter.send(Message::Error(format!("Levi stdout closed: {:?}", e)))?;
                break;
            },
        }
        line.clear();
    }
    Ok(())
}
