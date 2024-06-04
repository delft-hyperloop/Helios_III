use crate::api::{Datapoint, Message};
use crate::{Command, Datatype};
use tokio::sync::broadcast::Sender;

pub fn handle_line_from_levi(
    line: &String,
    msg_send: Sender<Message>,
    cmd_send: Sender<Command>,
) -> anyhow::Result<()> {
    let params = line.split(':').collect::<Vec<&str>>();

    match params[0] {
        "INFO" => {
            msg_send.send(Message::Info(format!("Levi: {}", params[1..].join(","))))?;
        }
        "WARNING" => {
            msg_send.send(Message::Warning(format!(
                "Levi Warning: {}",
                params[1..].join(",")
            )))?;
        }
        "ERROR" => {
            // cmd_send.send(Command::EmergencyBrake(3))?;
            msg_send.send(Message::Error(format!(
                "Levi Error: {}",
                params[1..].join(",")
            )))?;
        }
        "CRITICAL" => {
            cmd_send.send(Command::EmergencyBrake(3))?;
            msg_send.send(Message::Error(format!(
                "LEVI CRITICAL: {}",
                params[1..].join(",")
            )))?;
        }
        "DATA" if params.len() > 2 => {
            if let Ok(x) = params[2].trim().parse::<f64>() {
                msg_send.send(Message::Data(Datapoint::new(
                    Datatype::from_str(params[1]),
                    x.to_bits(),
                    chrono::offset::Local::now().timestamp() as u64,
                )))?;
            } else {
                msg_send.send(Message::Warning(format!(
                    "Levi data not a number: {:?}",
                    params[2].trim()
                )))?;
            }
        }
        _ => {
            msg_send.send(Message::Warning(format!("Unknown levi msg: {:?}", line)))?;
            return Ok(());
        }
    }
    msg_send.send(Message::Info(format!("[TRACE] Levi: {:?}", line)))?;
    Ok(())
}
