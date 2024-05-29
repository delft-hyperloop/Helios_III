use std::io::{BufRead, BufReader};
use std::process::{Stdio};
use std::sync::mpsc::{Receiver, Sender};
use crate::api::Message;
use crate::levi::parser::levi_str_to_message;
use crate::levi::writer::send_commands_to_levi;
use crate::{Command, LEVI_EXEC_PATH};

pub fn run_levi_software(sender: Sender<Message>, receiver: Receiver<Command>) -> std::io::Result<()> {
    let mut child = std::process::Command::new(LEVI_EXEC_PATH)
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .spawn()
        .map_err(|e| {
            sender.send(Message::Error(format!("Failed to start levi: {}", e)))
                .expect("Failed to send error message");
            e
        })?;

    match child.stdin.take() {
        Some(stdin) => {
            let _ = &sender.send(Message::Info("Took child's stdin".to_string())).expect("Failed to send status message");
            let s_test = sender.clone();
            let _handle = std::thread::spawn(move || {
                send_commands_to_levi(receiver,stdin);
                s_test.send(Message::Info("loop that's sending commands to levi stopped".to_string())).expect("Failed to send status message");
            });
        }
        None => {
            sender.send(Message::Error("Failed to open stdin".to_string())).expect("Failed to send error message");
        }
    }

    if let Some(stdout) = child.stdout.take() {
        let reader = BufReader::new(stdout);
        for line in reader.lines() {
            let line = line.expect("Failed to read line");
            sender.send(levi_str_to_message(line.as_str().trim())).expect("Failed to send message");
            // #[cfg(debug_assertions)]
            // println!("Received: {}", line);
        }
    } else {
        sender.send(Message::Error("Failed to open stdout".to_string())).expect("Failed to send error message");
    }
    Ok(())
}