#![no_std]
#![no_main]
#![allow(clippy::too_many_arguments)]
#![deny(clippy::async_yields_async)]
#![deny(rustdoc::broken_intra_doc_links)]
use ::core::borrow::Borrow;
use defmt::*;
use defmt_rtt as _;
use embassy_executor::Spawner;
use embassy_stm32::bind_interrupts;
use embassy_stm32::can;
use embassy_stm32::eth;
use embassy_stm32::peripherals;
use embassy_stm32::peripherals::*;
use embassy_stm32::rng;
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::channel::Channel;
use embassy_sync::priority_channel::PriorityChannel;
use embassy_time::Timer;
use heapless::binary_heap::Max;
use panic_probe as _;
use static_cell::StaticCell;
mod core;
mod pconfig;

use core::controllers::finite_state_machine_peripherals::*;
use core::finite_state_machine::*;

use crate::core::communication::Datapoint;
use crate::core::data::data_middle_step;
use crate::pconfig::default_configuration;

// We need to include the external variables imported from build.rs
// Imports: check config.toml and build.rs for more info
include!(concat!(env!("OUT_DIR"), "/config.rs"));

bind_interrupts!(struct Irqs {
    ETH => eth::InterruptHandler;
    RNG => rng::InterruptHandler<peripherals::RNG>;
});
bind_interrupts!(struct CanOneInterrupts {
    FDCAN1_IT0 => can::IT0InterruptHandler<FDCAN1>;
    FDCAN1_IT1 => can::IT1InterruptHandler<FDCAN1>;
});
bind_interrupts!(struct CanTwoInterrupts {
    FDCAN2_IT0 => can::IT0InterruptHandler<FDCAN2>;
    FDCAN2_IT1 => can::IT1InterruptHandler<FDCAN2>;
});

// Custom Data types-----------------------

/// A transmitter for the [`Datapoint`] MPMC [`DATA_QUEUE`]
type DataSender =
    embassy_sync::channel::Sender<'static, NoopRawMutex, Datapoint, { DATA_QUEUE_SIZE }>;
/// A receiver for the [`Datapoint`] MPMC [`DATA_QUEUE`]
type DataReceiver =
    embassy_sync::channel::Receiver<'static, NoopRawMutex, Datapoint, { DATA_QUEUE_SIZE }>;
/// A transmitter for the [`Event`] MPMC [`EVENT_QUEUE`]
type EventSender =
    embassy_sync::priority_channel::Sender<'static, NoopRawMutex, Event, Max, { EVENT_QUEUE_SIZE }>;
/// A receiver for the [`Event`] MPMC [`EVENT_QUEUE`]
type EventReceiver = embassy_sync::priority_channel::Receiver<
    'static,
    NoopRawMutex,
    Event,
    Max,
    { EVENT_QUEUE_SIZE },
>;
/// A transmitter for the [`can::frame::Frame`] MPMC [`CAN_ONE_QUEUE`]/[`CAN_TWO_QUEUE`]
type CanSender =
    embassy_sync::channel::Sender<'static, NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }>;
/// A receiver for the [`can::frame::Frame`] MPMC [`CAN_ONE_QUEUE`]/[`CAN_TWO_QUEUE`]
type CanReceiver =
    embassy_sync::channel::Receiver<'static, NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }>;

// Static Allocations - MPMC queues
/// The allocation for [`Event`]-[`embassy_sync::channel`]
static EVENT_QUEUE: StaticCell<PriorityChannel<NoopRawMutex, Event, Max, { EVENT_QUEUE_SIZE }>> =
    StaticCell::new();

/// The allocation for [`Datapoint`]-[`embassy_sync::channel`]
static DATA_QUEUE: StaticCell<Channel<NoopRawMutex, Datapoint, { DATA_QUEUE_SIZE }>> =
    StaticCell::new();
/// The allocation for a [`Datapoint`]-[`embassy_sync::channel`]
static PARSED_DATA_QUEUE: StaticCell<Channel<NoopRawMutex, Datapoint, { DATA_QUEUE_SIZE }>> =
    StaticCell::new();

/// The allocation for [`can::frame::Frame`]-[`embassy_sync::channel`]
static CAN_ONE_QUEUE: StaticCell<Channel<NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }>> =
    StaticCell::new();
/// The allocation for [`can::frame::Frame`]-[`embassy_sync::channel`]
static CAN_TWO_QUEUE: StaticCell<Channel<NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }>> =
    StaticCell::new();

/// Util struct for initialising [`FSMPeripherals`]
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

    // Configuration
    // `p` is the most important object in our code; treat it with respect and caution
    let config = default_configuration();
    let p = embassy_stm32::init(config);

    // -- Static allocations
    // The communication channels get initialized and their endpoints are passed
    // on to the FSM and other tasks

    // Event queue carries events from all tasks to the FSM main loop
    let event_queue: &'static mut PriorityChannel<NoopRawMutex, Event, Max, { EVENT_QUEUE_SIZE }> =
        EVENT_QUEUE.init(PriorityChannel::new());
    let event_sender: EventSender = event_queue.sender();

    // The data queue carries data points from all tasks to the data middle step
    let data_queue: &'static mut Channel<NoopRawMutex, Datapoint, { DATA_QUEUE_SIZE }> =
        DATA_QUEUE.init(Channel::new());

    // The parsed data queue carries data points from the data middle step to the ground station
    let parsed_data_queue: &'static mut Channel<NoopRawMutex, Datapoint, { DATA_QUEUE_SIZE }> =
        PARSED_DATA_QUEUE.init(Channel::new());

    // Send data to the middle step
    let data_sender: DataSender = data_queue.sender();

    // `CAN` queues carry `CAN` frames to the `CAN` busses
    let can_one_queue: &'static mut Channel<NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }> =
        CAN_ONE_QUEUE.init(Channel::new());
    let can_two_queue: &'static mut Channel<NoopRawMutex, can::frame::Frame, { CAN_QUEUE_SIZE }> =
        CAN_TWO_QUEUE.init(Channel::new());

    //-- Begin peripheral configuration
    let per: FSMPeripherals = FSMPeripherals::new(
        p,
        spawner.borrow(),
        InternalMessaging {
            event_sender,
            data_sender,
            data_receiver: parsed_data_queue.receiver(),
            can_one_sender: can_one_queue.sender(),
            can_one_receiver: can_one_queue.receiver(),
            can_two_sender: can_two_queue.sender(),
            can_two_receiver: can_two_queue.receiver(),
        },
    )
    .await;
    // -- End peripheral configuration

    // Create FSM
    let mut fsm = Fsm::new(per, event_queue.receiver(), data_sender);
    fsm.entry().await;
    // --

    // Begin Spawn Tasks
    try_spawn!(event_sender, spawner.spawn(your_mom(data_sender, event_sender)));

    try_spawn!(
        event_sender,
        spawner.spawn(data_middle_step(
            data_queue.receiver(),
            parsed_data_queue.sender(),
            event_sender
        ))
    );
    // End Spawn Tasks

    // # Main Loop
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
pub async fn your_mom(_ds: DataSender, es: EventSender) {
    let mut idx = 10;
    loop {
        info!("Your mom");
        Timer::after_secs(10).await;
        es.send(Event::Heartbeating).await;
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
