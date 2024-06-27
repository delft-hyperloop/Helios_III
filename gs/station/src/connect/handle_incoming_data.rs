#![allow(clippy::single_match)]
use crate::api::{Datapoint, Message};
use crate::{Command, Datatype};
use tokio::sync::broadcast::Sender;

pub async fn handle_incoming_data(
    data: Datapoint,
    msg_sender: Sender<Message>,
    cmd_sender: Sender<Command>,
) -> anyhow::Result<()> {
    msg_sender.send(Message::Data(data.clone()))?;

    match data.datatype {
        Datatype::LeviInstruction => {
            cmd_sender.send(Command::from_id(data.value as u16, 0))?;
        }
        _ => {}
    }

    Ok(())
}
