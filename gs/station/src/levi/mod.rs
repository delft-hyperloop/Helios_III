mod parse_input;
mod read_from_stdout;
mod write_to_stdin;

use crate::LEVI_EXEC_PATH;
use tokio::task::AbortHandle;

pub fn levi_main(
    message_transmitter: tokio::sync::broadcast::Sender<crate::api::Message>,
    command_transmitter: tokio::sync::broadcast::Sender<crate::Command>,
    command_receiver: tokio::sync::broadcast::Receiver<crate::Command>,
) -> anyhow::Result<(AbortHandle, AbortHandle)> {
    let mut lcmd = tokio::process::Command::new(LEVI_EXEC_PATH);
    lcmd.stdin(std::process::Stdio::piped())
        .stdout(std::process::Stdio::piped())
        .stderr(std::process::Stdio::piped());

    let mut levi_child = lcmd.spawn()?;

    let stdin = levi_child.stdin.unwrap();
    let stdout = levi_child.stdout.take().unwrap();

    let transmitter = message_transmitter.clone();
    let lh1 = tokio::spawn(async move {
        write_to_stdin::write_to_levi_child_stdin(stdin, transmitter, command_receiver).await
    })
    .abort_handle();

    let msg_transmitter = message_transmitter.clone();
    let cmd_transmitter = command_transmitter.clone();
    let lh2 = tokio::spawn(async move {
        read_from_stdout::read_from_levi_child_stdout(stdout, msg_transmitter, cmd_transmitter)
            .await
    })
    .abort_handle();

    Ok((lh1, lh2))
}
