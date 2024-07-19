use gslib::Datatype;
use gslib::Event;
use gslib::Message;
use gslib::ProcessedData;
use tokio::sync::broadcast::error::RecvError;

use crate::Command;
use crate::CommandSender;
use crate::MessageSender;

// const CYGNUS_MAX_DIFFERENCE: f64 = 9.0; // Volts
const LEVI_LED_THRESHOLD: f64 = 50.0;

pub const HV_DATATYPES: [Datatype; 5] = [
    Datatype::levi_volt_avg,
    Datatype::levi_volt_min,
    Datatype::levi_volt_max,
    Datatype::TotalBatteryVoltageHigh,
    Datatype::FSMState,
];

pub type DataReceiver = tokio::sync::broadcast::Receiver<ProcessedData>;
pub type DataSender = tokio::sync::broadcast::Sender<ProcessedData>;

#[derive(Default)]
struct Backlog {
    levi_avg: f64,
    levi_min: f64,
    levi_max: f64,
    bms_avg: f64,
    state: f64,
}

impl Backlog {
    fn is_ready(&self) -> bool {
        self.levi_min.ne(&0.0)
            && self.levi_max.ne(&0.0)
            && self.levi_avg.ne(&0.0)
            && self.bms_avg.ne(&0.0)
    }

    // fn cygnus_varying(&self) -> bool {
    //     (self.levi_max - self.levi_min).abs() > CYGNUS_MAX_DIFFERENCE
    // }

    fn compare_voltages(&self) -> Event {
        if self.levi_min <= 0.9 * self.bms_avg {
            Event::HvLevitationBelowBms
        } else {
            Event::HvLevitationAboveBms
        }
    }

    fn levi_rising_edge(&self) -> bool { self.levi_max > LEVI_LED_THRESHOLD }

    fn levi_falling_edge(&self) -> bool { self.levi_max < LEVI_LED_THRESHOLD }

    fn is_pre_charging(&self) -> bool { (self.state - 4.0) < f64::EPSILON * 4.0 }
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

    let mut edge = false;

    let mut backlog = Backlog::default();

    loop {
        match data_in.recv().await {
            Ok(data) => match data.datatype {
                Datatype::levi_volt_avg => {
                    // backlog.prev_levi_avg = backlog.levi_avg;
                    backlog.levi_avg = data.value;
                    if !backlog.is_pre_charging() {
                        continue;
                    }
                },
                Datatype::levi_volt_min => {
                    backlog.levi_min = data.value;
                    if !backlog.is_pre_charging() {
                        continue;
                    }
                },
                Datatype::levi_volt_max => {
                    backlog.levi_max = data.value;
                    if !backlog.is_pre_charging() {
                        continue;
                    }
                },
                Datatype::TotalBatteryVoltageHigh => backlog.bms_avg = data.value,
                Datatype::FSMState => backlog.state = data.value,
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

        if !edge {
            edge = true;
            send(Event::LeviConnected);
        }

        // Run checks:
        // if backlog.cygnus_varying() {
        //     send(Event::CygnusesVaryingVoltages);
        // }

        if backlog.levi_rising_edge() {
            send(Event::LeviLedOn);
        }

        if backlog.levi_falling_edge() {
            send(Event::LeviLedOff);
        }

        send(backlog.compare_voltages());
    }
}
