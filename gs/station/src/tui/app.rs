use crate::api::{state_to_string, Datapoint, Message};
use crate::backend::Backend;
use crate::tui::render::CmdRow;
use crate::tui::{timestamp, Tui};
use crate::{Datatype, Event, Info, COMMANDS_LIST};
use ratatui::Frame;
use std::collections::BTreeMap;

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
    pub special_data: BTreeMap<Datatype, u64>,
    pub backend: Backend,
    pub safe: bool,
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
            cmds: COMMANDS_LIST
                .iter()
                .map(|x| CmdRow {
                    name: x.to_string(),
                    value: 0,
                })
                .collect(),
            cur_state: "None Yet".to_string(),
            last_heartbeat: "None Yet".to_string(),
            special_data: BTreeMap::from([
                (Datatype::InsulationNegative, 0),
                (Datatype::InsulationPositive, 0),
                (Datatype::BatteryCurrentHigh, 0),
                (Datatype::BatteryTemperatureHigh, 0),
                (Datatype::TotalBatteryVoltageLow, 0),
                (Datatype::TotalBatteryVoltageHigh, 0),
                (Datatype::SingleCellVoltageLow, 0),
                (Datatype::BatteryMaxBalancingLow, 0),
                (Datatype::Localisation, 0),
                (Datatype::PropulsionCurrent, 0),
                (Datatype::PropulsionVoltage, 0),
                (Datatype::PropulsionSpeed, 0),
                (Datatype::PropulsionVRefInt, 0),
            ]),
            backend,
            safe: true,
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

    fn render_frame(&self, frame: &mut Frame) {
        frame.render_widget(self, frame.size());
    }

    fn receive_data(&mut self) {
        while let Ok(msg) = self.backend.message_receiver.try_recv() {
            match msg {
                Message::Data(datapoint) => match datapoint.datatype {
                    Datatype::Info => match Info::from_id(datapoint.value as u16) {
                        Info::Safe => {
                            self.safe = true;
                        }
                        Info::Unsafe => {
                            self.safe = false;
                        }
                        _ => {}
                    },
                    Datatype::FSMState => {
                        self.cur_state = state_to_string(datapoint.value).to_string();
                        self.logs.push((
                            Message::Warning(format!(
                                "State changed to: {:?}",
                                datapoint.value.to_be_bytes()
                            )),
                            timestamp(),
                        ));
                        self.logs.push((Message::Data(datapoint), timestamp()));
                        if self.logs.len() > 42 {
                            self.scroll += 1;
                        }
                    }
                    Datatype::FSMEvent => {
                        if datapoint.value == Event::Heartbeat.to_id() as u64 {
                            self.last_heartbeat = timestamp();
                        } else if self
                            .special_data
                            .keys()
                            .collect::<Vec<&Datatype>>()
                            .contains(&&datapoint.datatype)
                        {
                            self.special_data
                                .insert(datapoint.datatype, datapoint.value);
                        } else {
                            self.logs.push((Message::Data(datapoint), timestamp()));
                            if self.logs.len() > 42 {
                                self.scroll += 1;
                            }
                        }
                    }
                    Datatype::PropulsionCurrent => {
                        self.special_data
                            .insert(Datatype::PropulsionCurrent, datapoint.value / 680);
                    }
                    Datatype::PropulsionVoltage => {
                        self.special_data
                            .insert(Datatype::PropulsionVoltage, datapoint.value / 340);
                    }
                    x if self
                        .special_data
                        .keys()
                        .collect::<Vec<&Datatype>>()
                        .contains(&&x) =>
                    {
                        self.special_data.insert(x, datapoint.value);
                    }
                    _ => {
                        self.logs.push((Message::Data(datapoint), timestamp()));
                        if self.logs.len() > 42 {
                            self.scroll += 1;
                        }
                    }
                },
                msg => {
                    self.logs.push((msg, timestamp()));
                    if self.logs.len() > 42 {
                        self.scroll += 1;
                    }
                }
            }
        }
    }

    pub fn quit(&mut self) {
        self.exit = true;
        self.backend.quit_levi();
        self.backend.quit_server();
    }
}
