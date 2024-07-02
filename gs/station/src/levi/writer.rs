use std::io::Write;
use std::sync::mpsc::{Receiver, RecvError};
use crate::Command;

pub fn send_commands_to_levi(cmds: Receiver<Command>, mut stdin: std::process::ChildStdin) {
    loop {
        match cmds.recv() {
            Ok(cmd) => {
                match cmd {
                    Command::DefaultCommand(_) => {}
                    Command::Levitate(_) => {
                        stdin.write_all(b"levitate\n").expect("Failed to write to levi");
                    }
                    Command::StopLevitating(_) => {
                        stdin.write_all(b"stop_levitating\n").expect("Failed to write to levi");
                    }
                    Command::Configure(_) => {}
                    Command::StartRun(_) => {}
                    Command::EmergencyBrake(_) => {}
                    Command::Shutdown(_) => {}
                    Command::StartHV(_) => {}
                    Command::StopHV(_) => {}
                    Command::EmitEvent(_) => {}
                }
            }
            Err(e) => {
                eprintln!("Error receiving command: {:?}", e);
            }
        }
    }
}