use crate::api::{state_to_string, Datapoint, Message};
use crate::backend::Backend;
use crate::tui::render::CmdRow;
use crate::tui::{timestamp, Tui};
use crate::Datatype::FSMEvent;
use crate::{Datatype, Event, COMMANDS_LIST};
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
                    name: format!("{}", x),
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
            ]),
            backend,
        }
    }

    pub fn run(&mut self, terminal: &mut Tui) -> std::io::Result<()> {
        while !self.exit {
            terminal.draw(|frame| self.render_frame(frame))?;
            self.handle_events();
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
                Message::Data(datapoint) => {
                    if self.scroll > 50 {
                        self.scroll += 1;
                    }
                    if datapoint.datatype == crate::Datatype::FSMState {
                        self.cur_state = format!("{}", state_to_string(datapoint.value));
                        self.logs.push((
                            Message::Warning(format!(
                                "State changed to: {:?}",
                                datapoint.value.to_be_bytes()
                            )),
                            timestamp(),
                        ));
                        self.logs.push((Message::Data(datapoint), timestamp()))
                    } else if datapoint.datatype == FSMEvent {
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
                            self.logs.push((Message::Data(datapoint), timestamp()))
                        }
                    } else {
                        self.logs.push((Message::Data(datapoint), timestamp()))
                    }
                }
                msg => {
                    self.logs.push((msg, timestamp()));
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
