use crate::api::Message;
use tokio::io::AsyncBufReadExt;

/// # Read from levi child stdout
/// reads from the stdout of the levi child process, and sends the messages to the message_transmitter.
pub async fn read_from_levi_child_stdout(
    stdout: tokio::process::ChildStdout,
    message_transmitter: tokio::sync::broadcast::Sender<Message>,
) {
    let mut reader = tokio::io::BufReader::new(stdout);
    let mut line = String::new();
    loop {
        match reader.read_line(&mut line).await {
            Ok(0) => {
                message_transmitter
                    .send(Message::Error("Levi stdout closed.".to_string()))
                    .unwrap();
                break;
            }
            Ok(n) => {
                message_transmitter
                    .send(Message::Info(format!("RECEIVED LEVI: ({}), {:?}", n, line)))
                    .unwrap();
            }
            Err(e) => {
                message_transmitter
                    .send(Message::Error(format!("Levi stdout closed: {:?}", e)))
                    .unwrap();
                break;
            }
        }
        line.clear();
    }
}
