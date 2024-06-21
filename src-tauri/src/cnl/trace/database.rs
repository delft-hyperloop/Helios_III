use std::{cmp::Reverse, collections::HashMap, time::Duration};

use canzero_config::config;
use tokio::sync::Mutex;

use super::{
    event::TraceEvent,
    frame::{TraceFrame, TraceFrameKey},
};

#[derive(Debug)]
pub enum SortCriteria {
    None,
    ByAbsoluteTime,
    ByDeltaTime,
    ById,
    ByName,
    ByBus,
    ByDlc,
}

#[derive(Debug)]
pub enum SortOrder {
    Asc,
    Desc,
}

pub struct TraceDatabaseData {
    lookup: HashMap<TraceFrameKey, usize>,
    trace: Vec<TraceEvent>,
    trace_id_strings: Vec<String>,
    sort_criteria: SortCriteria,
    sort_order: SortOrder,
    filter_string: Option<String>,
    sorted_filter: Vec<usize>,
}

impl TraceDatabaseData {
    pub fn update(&mut self) {
        self.update_filter();
        self.update_sorting();
    }

    pub fn update_filter(&mut self) {
        assert_eq!(self.trace.len(), self.trace_id_strings.len());
        self.sorted_filter.clear();
        match &self.filter_string {
            Some(filter_string) => {
                for i in 0..self.trace.len() {
                    if self.trace[i].name().to_lowercase().contains(&filter_string.to_lowercase())
                        | self.trace_id_strings[i].starts_with(filter_string)
                    {
                        self.sorted_filter.push(i);
                    }
                }
            }
            None => {
                // NOTE no filtering!
                self.sorted_filter.clear();
                for i in 0..self.trace.len() {
                    self.sorted_filter.push(i);
                }
            }
        }
    }

    pub fn update_sorting(&mut self) {
        match &self.sort_criteria {
            SortCriteria::None => (),
            SortCriteria::ByAbsoluteTime => self.sort_by_absolute_time(),
            SortCriteria::ByDeltaTime => self.sort_by_delta_time(),
            SortCriteria::ById => self.sort_by_id(),
            SortCriteria::ByName => self.sort_by_name(),
            SortCriteria::ByDlc => self.sort_by_dlc(),
            SortCriteria::ByBus => self.sort_by_bus(),
        }
    }


    pub fn sort_by_absolute_time(&mut self) {
        match self.sort_order {
            SortOrder::Asc => self
                .sorted_filter
                .sort_by_key(|i| Reverse(self.trace[*i].timestamp().as_millis())),
            SortOrder::Desc => self
                .sorted_filter
                .sort_by_key(|i| self.trace[*i].timestamp().as_millis()),
        }
    }

    pub fn sort_by_delta_time(&mut self) {
        match self.sort_order {
            SortOrder::Asc => self
                .sorted_filter
                .sort_by_key(|i| Reverse(self.trace[*i].delta_time().as_millis())),
            SortOrder::Desc => self
                .sorted_filter
                .sort_by_key(|i| self.trace[*i].delta_time().as_millis()),
        }
    }

    pub fn sort_by_id(&mut self) {
        match self.sort_order {
            SortOrder::Asc => self
                .sorted_filter
                .sort_by_key(|i| Reverse(self.trace[*i].id())),
            SortOrder::Desc => self.sorted_filter.sort_by_key(|i| self.trace[*i].id()),
        }
    }

    pub fn sort_by_name(&mut self) {
        match self.sort_order {
            SortOrder::Asc => self
                .sorted_filter
                .sort_by_key(|i| Reverse(self.trace[*i].name())),
            SortOrder::Desc => self.sorted_filter.sort_by_key(|i| self.trace[*i].name()),
        }
    }

    pub fn sort_by_bus(&mut self) {
        match self.sort_order {
            SortOrder::Asc => self
                .sorted_filter
                .sort_by_key(|i| Reverse(self.trace[*i].bus())),
            SortOrder::Desc => self
                .sorted_filter
                .sort_by_key(|i| self.trace[*i].bus()),
        }
    }
    pub fn sort_by_dlc(&mut self) {
        match self.sort_order {
            SortOrder::Asc => self
                .sorted_filter
                .sort_by_key(|i| Reverse(self.trace[*i].dlc())),
            SortOrder::Desc => self.sorted_filter.sort_by_key(|i| self.trace[*i].dlc()),
        }
    }
}

pub struct TraceDatabase {
    data: Mutex<TraceDatabaseData>,
}

impl TraceDatabase {
    pub fn new() -> Self {
        Self {
            data: Mutex::new(TraceDatabaseData {
                lookup: HashMap::new(),
                trace: vec![],
                trace_id_strings: vec![],
                filter_string: None,
                sort_order: SortOrder::Desc,
                sort_criteria: SortCriteria::None,
                sorted_filter: vec![],
            }),
        }
    }

    pub async fn update(&self, frame: TraceFrame, arrive: Duration, bus_name : &str, bus_id : u32) {
        let mut unlocked_data = self.data.lock().await;
        let trace_lookup_entry = unlocked_data.lookup.get(&frame.key()).cloned();
        match trace_lookup_entry {
            Some(trace_lookup_index) => {
                // NOTE overwrite previous trace event! }
                unlocked_data.trace[trace_lookup_index] = TraceEvent::new_relative(
                    bus_name,
                    bus_id,
                    frame,
                    Some(
                        unlocked_data.trace[trace_lookup_index]
                            .timestamp()
                            .clone(),
                    ),
                    arrive,
                );
            }
            None => {
                let frame_index = unlocked_data.trace.len();
                unlocked_data.lookup.insert(frame.key(), frame_index);
                unlocked_data.trace_id_strings.push(match &frame {
                    TraceFrame::Undefined(can_frame) => {
                        if can_frame.get_ide_flag() {
                            format!("0x{:X}x", can_frame.get_id())
                        } else {
                            format!("0x{:X}", can_frame.get_id())
                        }
                    }
                    TraceFrame::Error(err) => err.name().to_owned(),
                    TraceFrame::Frame(frame) => match frame.id() {
                        config::MessageId::StandardId(id) => format!("0x{id:X}"),
                        config::MessageId::ExtendedId(id) => format!("0x{id:X}x"),
                    },
                });
                unlocked_data.trace.push(TraceEvent::new_relative(
                    bus_name,
                    bus_id,
                    frame,
                    None,
                    arrive,
                ));
            }
        }
    }

    pub async fn sort_by(&self, sort_by: SortCriteria, order: SortOrder) {
        let mut unlocked_data = self.data.lock().await;
        unlocked_data.sort_criteria = sort_by;
        unlocked_data.sort_order = order;
    }

    pub async fn filter_by(&self, filter_string : Option<String>) {
        let mut unlocked_data = self.data.lock().await;
        unlocked_data.filter_string = filter_string;
    }

    pub async fn get_sorted_and_filtered_frames(&self) -> Vec<TraceEvent> {
        let mut unlocked_data = self.data.lock().await;
        unlocked_data.update();
        unlocked_data
            .sorted_filter
            .iter()
            .map(|index| unlocked_data.trace[*index].clone())
            .collect()
    }

    pub async fn deadlock_watchdog(&self) {
        let _ = self.data.lock().await;
    }
}
