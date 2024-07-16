use tokio::sync::broadcast::error::RecvError;

use crate::api::Message;
use crate::api::ProcessedData;
use crate::Command;
use crate::CommandSender;
use crate::Datatype;
use crate::Event;
use crate::MessageSender;

const CYGNUS_MAX_DIFFERENCE: f64 = 8.0; // Volts

pub const HV_DATATYPES: [Datatype; 4] = [
    Datatype::levi_volt_avg,
    Datatype::levi_volt_min,
    Datatype::levi_volt_max,
    Datatype::TotalBatteryVoltageHigh,
];

pub type DataReceiver = tokio::sync::broadcast::Receiver<ProcessedData>;
pub type DataSender = tokio::sync::broadcast::Sender<ProcessedData>;

#[derive(Default)]
struct Backlog {
    levi_avg: f64,
    levi_min: f64,
    levi_max: f64,
    bms_avg: f64,
}

impl Backlog {
    fn is_ready(&self) -> bool {
        self.levi_min.ne(&0.0)
            && self.levi_max.ne(&0.0)
            && self.levi_avg.ne(&0.0)
            && self.bms_avg.ne(&0.0)
    }

    fn cygnus_varying(&self) -> bool {
        (self.levi_max - self.levi_min).abs() > CYGNUS_MAX_DIFFERENCE
    }
}

pub async fn aggregate_voltage_readings(
    mut data_in: DataReceiver,
    cmd_out: CommandSender,
    status: MessageSender,
) {
    let send = |event: Event| {
        cmd_out
            .send(Command::EmitEvent(event.to_id() as u64))
            .expect("Batteries couldn't send command");
    };

    let mut backlog = Backlog::default();

    loop {
        match data_in.recv().await {
            Ok(data) => match data.datatype {
                Datatype::levi_volt_avg => backlog.levi_avg = data.value,
                Datatype::levi_volt_min => backlog.levi_avg = data.value,
                Datatype::levi_volt_max => backlog.levi_avg = data.value,
                Datatype::TotalBatteryVoltageHigh => backlog.bms_avg = data.value,
                _ => {},
            },
            Err(RecvError::Closed) => {
                status.send(Message::Error("Data parser closed".into())).expect("unrecoverable");
            },
            _ => {},
        }

        if !backlog.is_ready() {
            continue;
        }

        // Run checks:
        if backlog.cygnus_varying() {
            send(Event::CygnusesVaryingVoltages);
        }
    }
}
