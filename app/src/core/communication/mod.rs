use crate::core::communication::data::Datapoint;

pub mod comm;
pub mod data;
pub mod task;
pub mod low;

pub trait CommunicationLayer {
    async fn init(&mut self);
    async fn receive_bytes(&mut self, buf: &mut [u8], n: usize);
    async fn connect(&mut self) -> Result<(), CommunicationError>;
    async fn handshake(&mut self);
    async fn try_send_data(&mut self) -> bool;
    async fn try_receive_data(&mut self) -> bool;
}

#[allow(dead_code)]
pub trait HardwareLayer {
    async fn init(&mut self);
    async fn connect(&mut self) -> Result<(), CommunicationError>;
    async fn read_bytes(&mut self, buffer: &mut [u8]) -> Result<usize, CommunicationError>;
    async fn try_read_bytes(&mut self, buffer: &mut [u8]) -> Result<usize, CommunicationError>;
    fn can_read(&mut self) -> bool;
    async fn write_bytes(&mut self, bytes: &[u8]) -> Result<usize, CommunicationError>;
    async fn try_write_bytes(&mut self, bytes: &[u8]) -> Result<usize, CommunicationError>;
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
