use std::sync::mpsc::{Receiver, Sender};
use crate::api::Message;
use crate::connect::handler::Handler;

impl Handler {
    pub(crate) fn parse(buf: &mut Vec<u8>, tx: Sender<Message>) -> Sender<Message> {

    }
}