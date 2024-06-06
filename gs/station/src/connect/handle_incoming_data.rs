use tokio::sync::broadcast::Sender;
use crate::api::{Datapoint, Message};
use crate::{Command, Datatype};

pub async fn handle_incoming_data(data: Datapoint, msg_sender: Sender<Message>, cmd_sender: Sender<Command>) -> anyhow::Result<()> {
    msg_sender.send(Message::Data(data))?;

    match data.datatype {
        Datatype::FSMEvent => match &data.value {
            0x505 => {
                cmd_sender.send(Command::ls0(0))?;
            }
            _ => {}
        }
        _ => {}
    }

    Ok(())
}