#![no_std]
#![no_main]
// #![allow(incomplete_features)]
#![allow(
    unused_imports,
    unused_variables,
    unused_mut,
    dead_code,
    unreachable_code,
    unused,
    unused_doc_comments,
    clippy::too_many_arguments
)]
#![deny(clippy::async_yields_async)]
#[warn(unused_must_use)]

// Import absolutely EVERYTHING

use ::core::borrow::Borrow;
use defmt::*;
use embassy_executor::Spawner;
use embassy_net::tcp::client::{TcpClient, TcpClientState};
use embassy_net::{Ipv4Address, Ipv4Cidr};
use embassy_net::{Stack, StackResources};
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::{Ethernet, PacketQueue, PHY};
use embassy_stm32::gpio::{Level, Output, Speed};
use embassy_stm32::peripherals::*;
use embassy_stm32::rcc::*;
use embassy_stm32::rng::Rng;
use embassy_stm32::{bind_interrupts, can, eth, peripherals, rcc, rng, Config};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::channel::Channel;
use embassy_sync::priority_channel::*;
use embassy_time::{Instant, Timer};
use embedded_io_async::Write;
use embedded_nal_async::{Ipv4Addr, SocketAddr, SocketAddrV4, TcpConnect};
use futures::task::SpawnExt;
use heapless::Deque;
use heapless::Vec;
use rand_core::RngCore;
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};
mod core;
mod pconfig;

use crate::core::communication::Datapoint;
use crate::pconfig::default_configuration;
use core::controllers::finite_state_machine_peripherals::*;
use core::finite_state_machine::*;

/// We need to include the external variables imported from build.rs
/// Imports:
/// - GS_IP_ADDRESS: ([u16;4], u16)
/// ++++ (check config.toml and build.rs for more info, this may not be updated)
include!(concat!(env!("OUT_DIR"), "/config.rs"));

bind_interrupts!(struct Irqs {
    ETH => eth::InterruptHandler;
    RNG => rng::InterruptHandler<peripherals::RNG>;
});

/// Custom Data types-----------------------
type DataSender =
    embassy_sync::channel::Sender<'static, NoopRawMutex, Datapoint, { DATA_QUEUE_SIZE }>;
type DataReceiver =
    embassy_sync::channel::Receiver<'static, NoopRawMutex, Datapoint, { DATA_QUEUE_SIZE }>;
type EventSender =
    embassy_sync::priority_channel::Sender<'static, NoopRawMutex, Event, Max, { EVENT_QUEUE_SIZE }>;
type EventReceiver = embassy_sync::priority_channel::Receiver<
    'static,
    NoopRawMutex,
    Event,
    Max,
    { EVENT_QUEUE_SIZE },
>;
type CanSender =
    embassy_sync::channel::Sender<'static, NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }>;
type CanReceiver =
    embassy_sync::channel::Receiver<'static, NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }>;

/// Static Allocations - just the MPMC queues for now (?)
static EVENT_QUEUE: StaticCell<PriorityChannel<NoopRawMutex, Event, Max, { EVENT_QUEUE_SIZE }>> =
    StaticCell::new();
static DATA_QUEUE: StaticCell<Channel<NoopRawMutex, Datapoint, { DATA_QUEUE_SIZE }>> =
    StaticCell::new();
static CAN_ONE_QUEUE: StaticCell<Channel<NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }>> =
    StaticCell::new();
static CAN_TWO_QUEUE: StaticCell<Channel<NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }>> =
    StaticCell::new();

pub struct InternalMessaging {
    event_sender: EventSender,
    data_sender: DataSender,
    data_receiver: DataReceiver,
    can_one_sender: CanSender,
    can_one_receiver: CanReceiver,
    can_two_sender: CanSender,
    can_two_receiver: CanReceiver,
}

/// # Main Function: program entry point
#[embassy_executor::main]
async fn main(spawner: Spawner) -> ! {
    info!("------------ Main Application Started! ------------");

    /// Configuration
    /// `p` is the most important object in our code; treat it with respect and caution
    let mut config = default_configuration();
    let p = embassy_stm32::init(config);

    /// # Communication:
    /// 1. first initialise the event queue,
    /// 2. then the datapoint queue,
    /// 0. (the sizes are defined in config.toml)
    ///
    /// Briefly:
    /// - EventQueue: each task gets a sender instance, it can create events that the fsm reacts to in the main loop
    /// - DataQueue:
    /// 	+ each task gets a sender instance, it can send data to the communication dispatcher, which will send it to the ground station
    /// 	+ the dispatcher will get a receiver instance of the DataQueue
    ///
    let event_queue: &'static mut PriorityChannel<
        NoopRawMutex,
        Event,
        Max,
        { EVENT_QUEUE_SIZE },
    > = EVENT_QUEUE.init(PriorityChannel::new());

    let event_sender: EventSender = event_queue.sender();
    let event_receiver: Receiver<'static, NoopRawMutex, Event, Max, { EVENT_QUEUE_SIZE }> =
        event_queue.receiver();

    let data_queue: &'static mut Channel<NoopRawMutex, Datapoint, { DATA_QUEUE_SIZE }> =
        DATA_QUEUE.init(Channel::new());

    let data_sender: DataSender = data_queue.sender();
    let data_receiver: DataReceiver = data_queue.receiver();

    let can_one_queue: &'static mut Channel<NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }> =
        CAN_ONE_QUEUE.init(Channel::new());
    let can_one_sender: CanSender = can_one_queue.sender();
    let can_one_receiver: CanReceiver = can_one_queue.receiver();

    let can_two_queue: &'static mut Channel<NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }> =
        CAN_TWO_QUEUE.init(Channel::new());
    let can_two_sender: CanSender = can_two_queue.sender();
    let can_two_receiver: CanReceiver = can_two_queue.receiver();

    /// Begin peripheral configuration
    let mut per: FSMPeripherals = FSMPeripherals::new(
        p,
        spawner.borrow(),
        InternalMessaging {
            event_sender,
            data_sender,
            data_receiver,
            can_one_sender,
            can_one_receiver,
            can_two_sender,
            can_two_receiver,
        },
    )
    .await;
    /// End peripheral configuration

    /// Create FSM
    let mut fsm = Fsm::new(per, event_receiver, data_sender);
    fsm.entry().await;
    ///

    // Begin Spawn Tasks
    try_spawn!(
        event_sender,
        spawner.spawn(your_mom(data_sender, event_sender))
    );
    // End Spawn Tasks

    /// # Main Loop
    loop {
        info!("in da loop");
        let curr_event = fsm.event_queue.receive().await;
        info!("[main] received event: {:?}", curr_event.to_id());
        fsm.react(curr_event).await;
    }
}

/// # Your Mom
/// she fixes everything
#[embassy_executor::task]
pub async fn your_mom(ds: DataSender, es: EventSender) {
    let mut idx = 10;
    loop {
        info!("Your mom");
        Timer::after_secs(5).await;
        es.send(Event::Heartbeat).await;
        // ds.send(Datapoint::new(
        //     Datatype::BatteryVoltageHigh,
        //     42,
        //     Instant::now().as_ticks(),
        // ))
        // .await;
        // ds.send(Datapoint::new(
        //     Datatype::BatteryBalanceHigh,
        //     69,
        //     Instant::now().as_ticks(),
        // ))
        // .await;
        // ds.send(Datapoint::new(
        //     Datatype::BatteryCurrentHigh,
        //     idx,
        //     Instant::now().as_ticks(),
        // ))
        // .await;
        // ds.send(Datapoint::new(Datatype::BatteryVoltageHigh, 6543, Instant::now().as_ticks())).await;
        idx = (idx + 9) % 50;
    }
}
