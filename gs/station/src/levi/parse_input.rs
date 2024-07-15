use crate::api::Message;
use crate::api::ProcessedData;
use crate::Command;
use crate::CommandSender;
use crate::Datatype;
use crate::MessageSender;

pub fn handle_line_from_levi(
    line: &String,
    msg_send: MessageSender,
    cmd_send: CommandSender,
) -> anyhow::Result<()> {
    let params = line.split(':').collect::<Vec<&str>>();

    match params[0] {
        "INFO" => {
            msg_send.send(Message::Info(format!("Levi: {}", params[1..].join(","))))?;
        },
        "WARNING" => {
            msg_send.send(Message::Warning(format!("Levi Warning: {}", params[1..].join(","))))?;
        },
        "ERROR" => {
            // cmd_send.send(Command::EmergencyBrake(3))?;
            msg_send.send(Message::Error(format!("Levi Error: {}", params[1..].join(","))))?;
        },
        "CRITICAL" => {
            cmd_send.send(Command::EmergencyBrake(3))?;
            msg_send.send(Message::Error(format!("LEVI CRITICAL: {}", params[1..].join(","))))?;
        },
        "DATA" if params.len() > 2 => {
            if let Ok(x) = params[2].trim().replace(',', ".").parse::<f64>() {
                msg_send
                    .send(Message::Data(process_levi_data(x, Datatype::from_str(params[1]))))?;
            } else {
                msg_send.send(Message::Warning(format!(
                    "Levi data not a number: {:?}",
                    params[2].trim()
                )))?;
            }
        },
        _ => {
            msg_send.send(Message::Warning(format!("Unknown levi msg: {:?}", line)))?;
            return Ok(());
        },
    }
    // msg_send.send(Message::Info(format!("[TRACE] Levi: {:?}", line)))?;
    Ok(())
}

fn process_levi_data(x: f64, dtype: Datatype) -> ProcessedData {
    ProcessedData {
        datatype: dtype,
        value: x,
        timestamp: chrono::offset::Local::now().timestamp() as u64,
        style: "".to_string(),
        units: dtype.unit(),
    }
}
