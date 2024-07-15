use embassy_stm32::mode::Async;
use embassy_stm32::peripherals::UART7;
use embassy_stm32::usart::{Config, Uart};
use crate::core::communication::HardwareLayer;

pub struct UartCommunicationLayer<T, M> {
    pub uart: Uart<'static, T, M>,
    pub config: Config,
}

impl HardwareLayer for UartCommunicationLayer<UART7, Async> {
    fn new() -> Self {
        HardwareLayer {

        }
    }

    async fn connect() {
        todo!()
    }

    async fn read_bytes(&mut self, buffer: &mut [u8]) {
        todo!()
    }

    async fn write_bytes(&mut self, bytes: &[u8]) {
        todo!()
    }
}