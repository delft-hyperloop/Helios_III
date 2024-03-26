use crate::api::Datapoint;

pub struct Util {

}

impl Util {
    pub fn Now() -> String {
        chrono::offset::Local::now().to_string()
    }

    pub fn Instant() -> f64 {
        let now = chrono::offset::Local::now();
        now.timestamp() as f64 + now.timestamp_subsec_micros() as f64 / 1_000_000.0
    }
}


#[macro_export]
macro_rules! log {
    ($sender:expr, $log_type:expr, $message:expr) => {
        match $log_type {
            LogType::Info => $sender.send(Datapoint::Status($message.to_string())).unwrap(),
            LogType::Error => $sender.send(Datapoint::Error($message.to_string())).unwrap(),
            LogType::Success => $sender.send(Datapoint::Info($message.to_string())).unwrap(),
            _ => {}
        }
    };
}