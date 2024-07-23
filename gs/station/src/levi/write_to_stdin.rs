use gslib::Message;
use gslib::LEVI_REQUESTED_DATA;
use tokio::io::AsyncWriteExt;
use tokio::sync::broadcast::error::TryRecvError;

use crate::CommandReceiver;
use crate::MessageReceiver;
use crate::MessageSender;

/// # Writing to levi's stdin
/// when a command is sent to the broadcast channel, it is sent to levi's stdin.
pub async fn write_to_levi_child_stdin(
    mut stdin: tokio::process::ChildStdin,
    status_sender: MessageSender,
    mut command_receiver: CommandReceiver,
    mut message_receiver: MessageReceiver,
) -> anyhow::Result<()> {
    loop {
        match command_receiver.try_recv() {
            Ok(cmd) => {
                stdin.write_all(format!("{}\n", cmd.to_str()).as_bytes()).await?;
                stdin.flush().await?;
            },

            Err(TryRecvError::Closed) => {
                status_sender.send(Message::Error("command_receiver channel closed".into()))?;
                break;
            },
            _ => {},
        }
        match message_receiver.try_recv() {
            Ok(msg) => match msg {
                Message::Data(d) if LEVI_REQUESTED_DATA.contains(&d.datatype) => {
                    stdin
                        .write_all(format!("data:{:?}:{}\n", d.datatype, d.value).as_bytes())
                        .await?;
                    stdin.flush().await?;
                },
                _ => {},
            },
            Err(TryRecvError::Closed) => {
                status_sender.send(Message::Error("message_receiver channel closed".into()))?;
                break;
            },
            _ => {},
        }
    }
    Ok(())
}
