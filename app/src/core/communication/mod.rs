use defmt::Formatter;

use crate::{DataReceiver, DataSender, Datatype, EventSender};
use crate::core::communication::data::Datapoint;

pub mod can;
pub mod tcp;
pub mod data;
pub mod comm;
mod uart;
pub mod task;

pub trait CommunicationLayer {
    async fn init(&mut self);
    fn receive_bytes(&mut self, buf: &mut [u8], n: usize);
    async fn connect(&mut self) -> Result<(), CommunicationError>;
    async fn handshake(&mut self);
    fn try_send_data(&mut self) -> bool;
    async fn try_receive_data(&mut self) -> bool;
}

pub trait HardwareLayer {
    async fn init(&mut self);
    async fn connect(&mut self) -> Result<(), CommunicationError>;
    async fn read_bytes(&mut self, buffer: &mut [u8]) -> Result<usize, CommunicationError>;
    fn try_read_bytes(&mut self, buffer: &mut [u8]) -> Result<usize, CommunicationError>;
    fn can_read(&mut self) -> bool;
    async fn write_bytes(&mut self, bytes: &[u8]) -> Result<usize, CommunicationError>;
    fn try_write_bytes(&mut self, bytes: &[u8]) -> Result<usize, CommunicationError>;
    fn can_write(&mut self) -> bool;
}

#[derive(Debug, defmt::Format)]
pub enum CommunicationError {
    // CannotReachTarget,
    CannotConnect,
    NoActiveConnection,
    CannotRead,
    CannotWrite,
}