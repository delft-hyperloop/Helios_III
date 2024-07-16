use crate::core::communication::data::Datapoint;

pub mod comm;
pub mod data;
pub mod low;
pub mod task;

pub trait CommunicationLayer {
    async fn init(&mut self);
    async fn handshake(&mut self);
    async fn connect(&mut self) -> Result<(), CommunicationError>;
    async fn disconnect(&mut self);
    async fn try_send_data(&mut self) -> bool;
    async fn try_receive_data(&mut self) -> bool;
    async fn receive_bytes(&mut self, buf: &mut [u8], n: usize);
}

#[allow(dead_code)]
pub trait HardwareLayer {
    async fn init(&mut self);
    async fn connect(&mut self) -> Result<(), CommunicationError>;
    async fn read_bytes(&mut self, buffer: &mut [u8]) -> Result<usize, CommunicationError>;
    async fn try_read_bytes(&mut self, buffer: &mut [u8]) -> Result<usize, CommunicationError>;
    async fn write_bytes(&mut self, bytes: &[u8]) -> Result<usize, CommunicationError>;
    async fn try_write_bytes(&mut self, bytes: &[u8]) -> Result<usize, CommunicationError>;
    fn readable(&mut self) -> bool;
    fn can_read_now(&mut self) -> bool;
    fn writeable(&mut self) -> bool;
    async fn close_connection(&mut self);
}

#[derive(Debug, defmt::Format)]
pub enum CommunicationError {
    // CannotReachTarget,
    CannotConnect,
    NoActiveConnection,
    ConnectionTimedOut,
    CannotRead,
    CannotWrite,
}
