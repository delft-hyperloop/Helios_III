use std::sync::mpsc::{Sender};
use crate::api::Message;
use crate::connect::Datapoint;
use crate::connect::handler::Handler;
use crate::DATA_IDS;
use crate::Datatype;

impl Handler {
    pub(crate) fn parse(buf: &mut Vec<u8>, tx: Sender<Message>) {
        if buf.len() < 20 {
            return;
        }
        while buf[0] != 0xFF {
            buf.remove(0);
            if buf.len() < 20 {
                return;
            }
        }
        // buf values:
        // 0: 0xFF flag byte
        // 1-2: ID
        // 3-10: Value
        // 11-18: Timestamp
        // 19: 0xFF flag byte
        let id = (buf[1] as u16) << 8 | buf[2] as u16;
        let value = u64::from_be_bytes(buf[3..11].try_into().unwrap());
        let timestamp = u64::from_be_bytes(buf[11..19].try_into().unwrap());
        if DATA_IDS.contains(&id) {
            tx.send(Message::Data(Datapoint::new(Datatype::from_id(id), value, timestamp))).expect("[Parser] Failed to send on msg tx");
        } else {
            tx.send(Message::Error(format!("Unknown data ID: {}. value={}, timestamp={}", id, value, timestamp))).expect("[Parser] Failed to send on msg tx");
        }
    }
}