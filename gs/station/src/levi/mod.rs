mod parse_input;
mod read_from_stdout;
mod write_to_stdin;

use anyhow::anyhow;
use gslib::Message;
use gslib::LEVI_EXEC_PATH;
use tokio::task::AbortHandle;

use crate::battery::DataSender;
use crate::CommandReceiver;
use crate::CommandSender;
use crate::MessageReceiver;
use crate::MessageSender;

pub fn levi_main(
    message_transmitter: MessageSender,
    command_transmitter: CommandSender,
    command_receiver: CommandReceiver,
    message_receiver: MessageReceiver,
    data_sender: DataSender,
) -> anyhow::Result<(AbortHandle, AbortHandle)> {
    let mut lcmd = tokio::process::Command::new(LEVI_EXEC_PATH);
    message_transmitter.send(Message::Info(format!("starting levi at {}", LEVI_EXEC_PATH)))?;
    lcmd.stdin(std::process::Stdio::piped())
        .stdout(std::process::Stdio::piped())
        .stderr(std::process::Stdio::piped());

    let mut levi_child = lcmd.spawn()?;

    let stdin = levi_child.stdin.ok_or(anyhow!("couldn't take the child's stdin"))?;
    let stdout = levi_child.stdout.take().ok_or(anyhow!("couldn't take the child's stdout"))?;

    let transmitter = message_transmitter.clone();
    let lh1 = tokio::spawn(async move {
        match write_to_stdin::write_to_levi_child_stdin(
            stdin,
            transmitter.clone(),
            command_receiver,
            message_receiver,
        )
        .await
        {
            Ok(_) => {
                transmitter
                    .send(Message::Warning(
                        "[write_to_levi_child_stdin] closed without any errors.".to_string(),
                    ))
                    .expect("messaging channel closed... this is irrecoverable");
            },
            Err(e) => {
                transmitter
                    .send(Message::Error(format!(
                        "[write_to_levi_child_stdin] finished with errors: {:?}",
                        e
                    )))
                    .expect("messaging channel closed... this is irrecoverable");
            },
        }
        // todo: send emergency brake command if levi connection is lost?
    })
    .abort_handle();

    let msg_transmitter = message_transmitter.clone();
    let cmd_transmitter = command_transmitter.clone();
    let lh2 = tokio::spawn(async move {
        match read_from_stdout::read_from_levi_child_stdout(
            stdout,
            msg_transmitter.clone(),
            cmd_transmitter,
            data_sender.clone(),
        )
        .await
        {
            Ok(_) => {
                msg_transmitter
                    .send(Message::Warning(
                        "[read_from_levi_child_stdout] closed without any errors.".to_string(),
                    ))
                    .expect("messaging channel closed... this is irrecoverable");
            },
            Err(e) => {
                msg_transmitter
                    .send(Message::Error(format!(
                        "[read_from_levi_child_stdout] finished with errors: {:?}",
                        e
                    )))
                    .expect("messaging channel closed... this is irrecoverable");
            },
        }
        // todo: send emergency brake command if levi connection is lost?
    })
    .abort_handle();

    Ok((lh1, lh2))
}
