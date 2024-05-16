use std::collections::VecDeque;
use std::io::Read;
use std::sync::mpsc::{Sender};
use crate::api::Message;
use crate::connect::Datapoint;
use crate::connect::handler::Handler;
use crate::DATA_IDS;
use crate::Datatype;

impl Handler {
    pub(crate) fn parse(parsing_buffer: &mut VecDeque<u8>, tx: Sender<Message>) {
        // tx.send(Message::Warning(format!("Parsing buffer: {:?}", parsing_buffer))).expect("[Parser] Failed to send on msg tx");
        while let Some(p) = parsing_buffer.front() {
            // tx.send(Message::Warning(format!("Front is: {:?}", p))).expect("[Parser] Failed to send on msg tx");
            if *p == 0xFF {
                if parsing_buffer.len() < 20 {
                    // tx.send(Message::Error(format!("Buffer too short: {}, {:?}", parsing_buffer.len(), parsing_buffer))).expect("[Parser] Failed to send on msg tx");
                    break;
                } else {
                    tx.send(Message::Info(format!("parsing: {:?}", parsing_buffer.take(20).bytes()))).expect("[Parser] Failed to send on msg tx");
                    // we actually have 20 bytes in the buffer, we can create a command from them
                    let mut x = [0u8; 20];
                    parsing_buffer.drain(..20).enumerate().for_each(|(i, y)| { x[i] = y });
                    tx.send(Message::Info(format!("Parsed: {:?}", &x))).expect("[Parser] Failed to send on msg tx");
                    tx.send(Message::Data(Datapoint::from_bytes(&x))).expect("[Parser] Failed to send on msg tx");
                    // let id = (x[1] as u16) << 8 | x[2] as u16;
                    // let value = u64::from_be_bytes(x[3..11].to_vec().try_into().unwrap());
                    // let timestamp = u64::from_be_bytes(x[11..19].to_vec().try_into().unwrap());
                    // if DATA_IDS.contains(&id) {
                    //     tx.send(Message::Data(Datapoint::new(Datatype::from_id(id), value, timestamp))).expect("[Parser] Failed to send on msg tx");
                    // } else {
                    //     tx.send(Message::Error(format!("Unknown data ID: {}. value={}, timestamp={}", id, value, timestamp))).expect("[Parser] Failed to send on msg tx");
                    // }
                }
            } else {
                parsing_buffer.pop_front();
            }
        }
        // // buf values:
        // // 0: 0xFF flag byte
        // // 1-2: ID
        // // 3-10: Value
        // // 11-18: Timestamp
        // // 19: 0xFF flag byte
        // let mut bf = [0u8; 20];
        // for (i, x) in buf.iter().take(20).enumerate() {
        //     bf[i] = *x;
        // }
        // let id = (bf[1] as u16) << 8 | bf[2] as u16;
        // let value = u64::from_be_bytes(bf[3..11].to_vec().try_into().unwrap());
        // let timestamp = u64::from_be_bytes(bf[11..19].to_vec().try_into().unwrap());
        // buf.drain(..20);
        // if DATA_IDS.contains(&id) {
        //     tx.send(Message::Data(Datapoint::new(Datatype::from_id(id), value, timestamp))).expect("[Parser] Failed to send on msg tx");
        // } else {
        //     tx.send(Message::Error(format!("Unknown data ID: {}. value={}, timestamp={}", id, value, timestamp))).expect("[Parser] Failed to send on msg tx");
        // }
    }
}
