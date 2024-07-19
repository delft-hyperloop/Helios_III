use std::collections::BTreeMap;
use std::time::Duration;
use std::time::Instant;

use gslib::state_to_string;
use gslib::Datapoint;
use gslib::Datatype;
use gslib::Event;
use gslib::Info;
use gslib::LocationSequence;
use gslib::Message;
use gslib::COMMANDS_LIST;
use gslib::HEARTBEAT;
use ratatui::Frame;

use crate::backend::Backend;
use crate::tui::render::CmdRow;
use crate::tui::timestamp;
use crate::tui::Tui;
use crate::Command;

#[allow(dead_code)]
pub struct App {
    pub logs: Vec<(Message, String)>,
    pub data: Vec<Datapoint>,
    pub exit: bool,
    pub scroll: u16,
    pub time_elapsed: u64,
    pub selected: usize,
    pub selected_row: usize,
    pub cmds: Vec<CmdRow>,
    pub cur_state: String,
    pub last_heartbeat: String,
    pub special_data: BTreeMap<Datatype, f64>,
    pub backend: Backend,
    pub safe: bool,
    pub last_sent_heartbeat: Instant,
    pub received_bytes: u64,
    pub throughput: f64,
}

impl App {
    pub fn new(backend: Backend) -> Self {
        Self {
            logs: vec![],
            data: vec![],
            exit: false,
            scroll: 0,
            time_elapsed: 0,
            selected: 0,
            selected_row: 0,
            cmds: COMMANDS_LIST.iter().map(|x| CmdRow { name: x.to_string(), value: 0 }).collect(),
            cur_state: "None Yet".to_string(),
            last_heartbeat: "None Yet".to_string(),
            special_data: BTreeMap::from([
                (Datatype::FrontendHeartbeating, 0.0),
                (Datatype::InsulationNegative, 0.0),
                (Datatype::InsulationPositive, 0.0),
                (Datatype::InsulationOriginal, 0.0),
                (Datatype::IMDVoltageDetails, 0.0),
                (Datatype::IMDIsolationDetails, 0.0),
                (Datatype::IMDGeneralInfo, 0.0),
                (Datatype::Average_Temp_VB_top, 0.0),
                (Datatype::GyroscopeX, 0.0),
                (Datatype::GyroscopeY, 0.0),
                (Datatype::GyroscopeZ, 0.0),
                (Datatype::LowPressureSensor, 0.0),
                (Datatype::BatteryCurrentHigh, 0.0),
                (Datatype::BatteryTemperatureHigh, 0.0),
                (Datatype::TotalBatteryVoltageLow, 0.0),
                (Datatype::TotalBatteryVoltageHigh, 0.0),
                (Datatype::SingleCellVoltageLow, 0.0),
                (Datatype::BatteryMaxBalancingLow, 0.0),
                (Datatype::Localisation, 0.0),
                (Datatype::Velocity, 0.0),
                (Datatype::LowPressureSensor, 0.0),
                (Datatype::HighPressureSensor, 0.0),
                (Datatype::PropulsionCurrent, 0.0),
                (Datatype::PropulsionVoltage, 0.0),
                (Datatype::PropulsionSpeed, 0.0),
                (Datatype::PropulsionVRefInt, 0.0),
                (Datatype::BrakingCommDebug, 0.0),
                (Datatype::BrakingSignalDebug, 42.0),
                (Datatype::BrakingBoolDebug, 42.0),
                (Datatype::BrakingRearmDebug, 42.0),
                (Datatype::PropGPIODebug, 42.0),
            ]),
            backend,
            safe: true,
            last_sent_heartbeat: Instant::now(),
            received_bytes: 0,
            throughput: 0.0,
        }
    }

    pub fn run(&mut self, terminal: &mut Tui) -> anyhow::Result<()> {
        while !self.exit {
            terminal.draw(|frame| self.render_frame(frame))?;
            self.handle_events()?;
            self.receive_data();
            self.time_elapsed = self.time_elapsed.wrapping_add(1);
        }
        Ok(())
    }

    fn render_frame(&self, frame: &mut Frame) { frame.render_widget(self, frame.size()); }

    fn receive_data(&mut self) {
        while let Ok(msg) = self.backend.message_receiver.try_recv() {
            self.received_bytes = self.received_bytes.wrapping_add(20);
            self.backend.log_msg(&msg);
            match msg {
                Message::Data(datapoint) => match datapoint.datatype {
                    Datatype::Info => match Info::from_id(datapoint.value as u16) {
                        Info::Safe => {
                            self.safe = true;
                        },
                        Info::Unsafe => {
                            self.safe = false;
                        },
                        x => {
                            self.logs.push((
                                Message::Status(x),
                                format!("[info: {} at {}]", datapoint.value, datapoint.timestamp),
                            ));
                        },
                    },
                    Datatype::RoutePlan => {
                        self.logs.push((
                            Message::Info(format!(
                                "Route: \n{}\ncurrently at {}",
                                LocationSequence::from(datapoint.value.round() as u64),
                                datapoint.timestamp,
                            )),
                            timestamp(),
                        ));
                    },
                    Datatype::FSMState => {
                        self.cur_state =
                            state_to_string(datapoint.value.round() as u64).to_string();
                        self.logs.push((
                            Message::Warning(format!(
                                "State is now: {:?}",
                                datapoint.value.to_be_bytes()
                            )),
                            timestamp(),
                        ));
                        self.logs.push((Message::Data(datapoint), timestamp()))
                    },
                    Datatype::FSMEvent => {
                        if (datapoint.value - Event::Heartbeating.to_id() as f64).abs()
                            <= f64::EPSILON * 2.0
                        {
                            self.last_heartbeat = timestamp();
                        } else if self
                            .special_data
                            .keys()
                            .collect::<Vec<&Datatype>>()
                            .contains(&&datapoint.datatype)
                        {
                            self.special_data.insert(datapoint.datatype, datapoint.value);
                        } else {
                            self.logs.push((Message::Data(datapoint), timestamp()))
                        }
                    },
                    Datatype::ResponseHeartbeat => {
                        self.special_data
                            .insert(Datatype::ResponseHeartbeat, datapoint.timestamp as f64);
                    },
                    x if self.special_data.keys().collect::<Vec<&Datatype>>().contains(&&x) => {
                        self.special_data.insert(x, datapoint.value);
                    },
                    _ => {
                        self.logs.push((Message::Data(datapoint), timestamp()));
                    },
                },
                msg => {
                    self.logs.push((msg, timestamp()));
                },
            }
        }
        if self.last_sent_heartbeat.elapsed() > Duration::from_millis(HEARTBEAT) {
            self.backend
                .command_transmitter
                .send(Command::FrontendHeartbeat(10))
                .expect("backend failed");
            self.last_sent_heartbeat = Instant::now();
            self.received_bytes = 0;
        }
    }

    pub fn quit(&mut self) {
        self.exit = true;
        self.backend.quit_levi();
        self.backend.quit_server();
    }
}
