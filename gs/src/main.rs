mod gui;
mod station;

use std::thread;
use rayon::prelude::*;
use colored::Colorize;

/// In order for the GUI to display any sort of graphs, it needs to get the data from the backend.
/// this is done through the mpsc channel, where the backend sends one of the enum variants to the
/// frontend, depending on the last received data from the pod.
/// TODO!!!!!!!!!!!!!!
/// replace the enum values with the correct data types that we get from the main pcb
#[derive(Debug)]
pub enum Datapoint {
    Temperature((f32, f32)), // the idea of tuples is that they are (value, timestamp),
    Voltage((f32, f32)),     // in order to be graphed correctly and easily
    Error(String),           // if the main pcb sends an error message
    Info(String),            // if the main pcb sends an info/log message
    Status(String),          // status message from the backend, NOT main pcb
}

/// Going the other way round, the frontend will have some buttons that need to be converted to
/// commands the ground station sends to the main pcb.
/// TODO!!!!!!!!!!!!!!
/// replace the enum values with the correct commands that we send to the main pcb
#[derive(Debug)]
pub enum Command {
    Levitate,
    StopLevitating,
    Configure(RunConfig),
    StartRun,
    EmergencyBrake,
    Shutdown,
}

/// It's best to explicitly state these types, even though they are trivial.
/// - they can be changed easily
/// - there will be no fuck-ups because we passed the wrong value somewhere
pub type Position = f32;
pub type Velocity = f32;
#[derive(Debug)]
pub struct RunConfig {
    max_velocity: Velocity,
    lane_switch: bool, // false: go straight, true: switch to the right lane
    braking_point: Position,
}

fn main() {

    // Create communication channels between backend and frontend threads
    let (data_tx, data_rx) = std::sync::mpsc::channel();
    let (command_tx, command_rx) = std::sync::mpsc::channel();

    thread::spawn(|| {
        station::launch(data_tx, command_rx);
    });

    // parse command line arguments to see if we should run the TUI or just the backend
    let args: Vec<String> = std::env::args().collect();
    if args.len() > 1 && args[1] == "ui" {
        gui::main::gui_main(command_tx, data_rx).unwrap();
    } else {
        loop {}
    }
}