use defmt::Formatter;

use crate::{DataReceiver, DataSender, Datatype, EventSender};
use crate::core::communication::data::Datapoint;

pub mod can;
pub mod tcp;
pub mod data;
mod comm;
mod uart;
mod task;

pub trait CommunicationLayer {
    fn receive_bytes(&mut self, buf: &mut [u8], n: usize);
    async fn connect(&mut self);
    fn handshake(&mut self);
    fn send_data(&mut self);
}

pub trait HardwareLayer {
    fn new() -> Self;
    async fn connect(&mut self);
    fn try_read_bytes(&mut self, buffer: &mut [u8]) -> ;
    async fn write_bytes(&mut self, bytes: &[u8]);
    fn write_blocking(&mut self, bytes: &[u8]);
    fn can_write(&mut self) -> bool;
}