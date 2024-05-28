use std::io::Write;
use std::sync::mpsc::{Receiver};
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
                    Command::ls0(_) => {
                        stdin.write_all(b"ls0\n").expect("Failed to write to levi");
                    }
                    Command::ls1(_) => {
                        stdin.write_all(b"ls1\n").expect("Failed to write to levi");
                    }
                    Command::ls2(_) => {
                        stdin.write_all(b"ls2\n").expect("Failed to write to levi");
                    }

                    Command::enable_axis(_) => {
                        stdin.write_all(b"enable_axis\n").expect("Failed to write to levi");
                    }
                    Command::disable_axis(_) => {
                        stdin.write_all(b"disable_axis\n").expect("Failed to write to levi");
                    }
                    Command::init(_) => {
                        stdin.write_all(b"init\n").expect("Failed to write to levi");
                    }


                    Command::reboot(_) => {
                        stdin.write_all(b"reboot\n").expect("Failed to write to levi");
                    }
                    Command::launch(_) => {
                        stdin.write_all(b"launch\n").expect("Failed to write to levi");
                    }
                    Command::vert0(_) => {
                        stdin.write_all(b"vert0\n").expect("Failed to write to levi");
                    }

                    Command::lat0(_) => {
                        stdin.write_all(b"lat0\n").expect("Failed to write to levi");
                    }
                    Command::land(_) => {
                        stdin.write_all(b"land\n").expect("Failed to write to levi");
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
            Err(_e) => {
                // eprintln!("Error receiving command: {:?}", e);
            }
        }
    }
}
