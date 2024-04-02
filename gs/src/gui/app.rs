use std::sync::mpsc::{Receiver, Sender};
use crate::api::{Command, Datapoint};

use crate::gui::main::{App, LogType};

fn f(x: u64, offset: u64) -> u64 {
    let y = x as f64 + 16.0*(offset as f64 / 6500.0).sin();
    (50.0 + (y * 1.2 * f64::cos(y)) + 10.0*f64::sin(y)) as u64
}


impl App {
    pub fn battery_voltages(offset: u64) -> Vec<(String, u64)> {
        (1..=112).map(|x| (format!("B{}", x), f(x, offset))).collect()
    }
    pub fn new(tx:Sender<Command>, rx: Receiver<Datapoint>) -> Self {
        let mut safety_data: Vec<(f64, f64)> = vec![];
        let mut unsafety_data: Vec<(f64, f64)> = vec![];
        for i in 0..200 {
            safety_data.push((i as f64 / 20.0, 5.0 + 3.0*f64::sin((i as f64)*0.1)));
            unsafety_data.push((i as f64 / 20.0, 5.5 - (i/32) as f64));
        }
        Self {
            logs: vec![(LogType::Info, "Started GUI".to_string())],
            exit: false,
            tx,
            rx,
            safety_score: safety_data,
            unsafety_score: unsafety_data,
            battery_voltages: App::battery_voltages(0),
            scroll: 0,
            time_elapsed: 0,
            selected: 0,
        }
    }
    pub fn exit(&mut self) {
        self.exit = true;
    }


}