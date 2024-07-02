use crate::api::Message;

pub fn levi_str_to_message(input: &str) -> Message {
    let msg = input.split(" ").collect::<Vec<&str>>();
    match msg[0] {
        "INFO" => Message::Info(msg[1..].join(" ")),
        "ERROR" => Message::Error(msg[1..].join(" ")),
        _ => Message::Warning(format!("Unknown levi message: {}", input.to_string()))
    }
}