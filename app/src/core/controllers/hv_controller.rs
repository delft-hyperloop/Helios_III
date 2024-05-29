use crate::Event;
use embassy_executor::Spawner;
use embassy_stm32::gpio::Output;
use embassy_stm32::peripherals;
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::Sender;
use heapless::binary_heap::Max;

pub struct HVPeripherals {
    pub(crate) enable_pin: Output<'static>,
}

impl HVPeripherals {
    pub async fn new(pb4_pin: peripherals::PB4) -> Self {
        Self {
            enable_pin: Output::new(
                pb4_pin,
                embassy_stm32::gpio::Level::Low,
                embassy_stm32::gpio::Speed::Low,
            ),
        }
    }
}
