use tokio::io::AsyncWriteExt;

use crate::CommandReceiver;
use crate::MessageSender;

/// # Writing to levi's stdin
/// when a command is sent to the broadcast channel, it is sent to levi's stdin.
pub async fn write_to_levi_child_stdin(
    mut stdin: tokio::process::ChildStdin,
    status_sender: MessageSender,
    mut command_receiver: CommandReceiver,
) -> anyhow::Result<()> {
    loop {
        let cmd = command_receiver.recv().await?;
        stdin.write_all(format!("{}\n", cmd.to_str()).as_bytes()).await?;
        stdin.flush().await?;
        status_sender.send(crate::api::Message::Info(format!(
            "wrote command {:?} to levi stdin: <{:?}>",
            cmd,
            cmd.to_str().as_bytes()
        )))?;
    }
}
