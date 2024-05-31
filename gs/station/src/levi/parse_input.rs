use crate::api::{Datapoint, Message};
use crate::{Command, Datatype};
use tokio::sync::broadcast::Sender;

pub fn handle_line_from_levi(line: &String, msg_send: Sender<Message>, cmd_send: Sender<Command>) {
    let params = line.split(':').collect::<Vec<&str>>();

    match params[0] {
        "INFO" => {
            msg_send
                .send(Message::Info(format!("Levi: {}", params[1..].join(","))))
                .unwrap();
        }
        "WARNING" => {
            msg_send
                .send(Message::Warning(format!(
                    "Levi Warning: {}",
                    params[1..].join(",")
                )))
                .unwrap();
        }
        "ERROR" => {
            // cmd_send.send(Command::EmergencyBrake(3)).unwrap();
            msg_send
                .send(Message::Error(format!(
                    "Levi Error: {}",
                    params[1..].join(",")
                )))
                .unwrap();
        }
        "CRITICAL" => {
            cmd_send.send(Command::EmergencyBrake(3)).unwrap();
            msg_send
                .send(Message::Error(format!(
                    "LEVI CRITICAL: {}",
                    params[1..].join(",")
                )))
                .unwrap();
        }
        "DATA" if params.len() > 2 => {
            if let Ok(x) = params[2].trim().parse::<f64>() {
                msg_send
                    .send(Message::Data(Datapoint::new(
                        Datatype::from_str(params[1]),
                        x.to_bits(),
                        chrono::offset::Local::now().timestamp() as u64,
                    )))
                    .unwrap();
            } else {
                msg_send
                    .send(Message::Warning(format!(
                        "Levi data not a number: {:?}",
                        params[2].trim()
                    )))
                    .unwrap();
            }
        }
        _ => {
            msg_send
                .send(Message::Warning(format!("Unknown levi msg: {:?}", line)))
                .unwrap();
            return;
        }
    }
    msg_send
        .send(Message::Info(format!("[TRACE] Levi: {:?}", line)))
        .unwrap();
}
