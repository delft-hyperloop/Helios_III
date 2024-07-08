#![allow(clippy::single_match)]
use tokio::sync::broadcast::Sender;

use crate::api::Datapoint;
use crate::api::Message;
use crate::Command;
use crate::Datatype;

pub async fn handle_incoming_data(
    data: Datapoint,
    msg_sender: Sender<Message>,
    cmd_sender: Sender<Command>,
) -> anyhow::Result<()> {
    msg_sender.send(Message::Data(data.clone()))?;

    match data.datatype {
        Datatype::LeviInstruction => {
            cmd_sender.send(Command::from_id(data.value as u16, 0))?;
        },
        _ => {},
    }

    Ok(())
}
