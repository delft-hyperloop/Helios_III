use defmt::*;
use embassy_executor::Spawner;
use embassy_stm32::{bind_interrupts, peripherals, rng, Config};
use embassy_time::{Duration, Timer};
use embedded_io_async::{Read, Write};
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};
use embassy_stm32::gpio::{Level, Output, Speed};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::{Receiver, Sender};
use heapless::binary_heap::Max;
use heapless::Vec;
use crate::{DataReceiver, EventSender};
use crate::core::finite_state_machine::Event;



#[embassy_executor::task]
pub async fn can_connection_handler(
    x: Spawner,
    event_sender : EventSender,
) -> ! {

    loop {

    }
}
