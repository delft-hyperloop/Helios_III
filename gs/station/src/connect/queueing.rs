use crate::api::{Datapoint, Message};
use std::collections::VecDeque;
use tokio::sync::broadcast::Sender;

/// # Unloads from the buffer and transmits any messages found
/// ```
/// buf values:
/// 0: 0xFF flag byte
/// 1-2: ID
/// 3-10: Value
/// 11-18: Timestamp
/// 19: 0xFF flag byte
/// ```
pub async fn parse(parsing_buffer: &mut VecDeque<u8>, tx: Sender<Message>) {
    while let Some(p) = parsing_buffer.front() {
        if *p == 0xFF {
            if parsing_buffer.len() < 20 {
                break;
            } else {
                // we actually have 20 bytes in the buffer, we can create a command from them
                let mut x = [0u8; 20];
                parsing_buffer
                    .drain(..20)
                    .enumerate()
                    .for_each(|(i, y)| x[i] = y);
                tx.send(Message::Data(Datapoint::from_bytes(&x)))
                    .expect("[Parser] Failed to send on msg tx");
            }
        } else {
            parsing_buffer.pop_front();
        }
    }
}
