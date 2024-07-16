#![allow(clippy::single_match)]

use crate::api::Datapoint;
use crate::api::Message;
use crate::battery::DataSender;
use crate::battery::HV_DATATYPES;
use crate::data::process::process;
use crate::Command;
use crate::CommandSender;
use crate::Datatype;
use crate::Info;
use crate::MessageSender;
use crate::COMMAND_HASH;
use crate::CONFIG_HASH;
use crate::DATA_HASH;
use crate::EVENTS_HASH;

pub async fn handle_incoming_data(
    data: Datapoint,
    msg_sender: MessageSender,
    cmd_sender: CommandSender,
    data_sender: DataSender,
) -> anyhow::Result<()> {
    msg_sender.send(Message::Data(process(&data)))?;

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
        Datatype::ConfigHash => {
            if data.value != CONFIG_HASH {
                msg_sender.send(Message::Error("Config hash mismatch".to_string()))?;
            } else {
                msg_sender.send(Message::Status(Info::ConfigHashPassed))?;
            }
        },
        x if HV_DATATYPES.contains(&x) => {
            data_sender.send(process(&data))?;
        },
        _ => {},
    }

    Ok(())
}
