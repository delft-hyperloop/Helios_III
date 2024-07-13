#![allow(clippy::single_match)]
use tokio::sync::broadcast::Sender;

use crate::api::Datapoint;
use crate::api::Message;
use crate::Command;
use crate::Datatype;
use crate::Info;
use crate::COMMAND_HASH;
use crate::DATA_HASH;
use crate::EVENTS_HASH;

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
        Datatype::CommandHash => {
            if data.value != COMMAND_HASH {
                msg_sender.send(Message::Error("Command hash mismatch".to_string()))?;
            } else {
                msg_sender.send(Message::Status(Info::CommandHashPassed))?;
            }
        },
        Datatype::DataHash => {
            if data.value != DATA_HASH {
                msg_sender.send(Message::Error("Data hash mismatch".to_string()))?;
            } else {
                msg_sender.send(Message::Status(Info::DataHashPassed))?;
            }
        },
        Datatype::EventsHash => {
            if data.value != EVENTS_HASH {
                msg_sender.send(Message::Error("Event hash mismatch".to_string()))?;
            } else {
                msg_sender.send(Message::Status(Info::EventsHashPassed))?;
            }
        },
        _ => {},
    }

    Ok(())
}
