#![no_std]
#![no_main]
// #![allow(incomplete_features)]
#![allow(unused_imports, unused_variables, unused_mut,dead_code, unreachable_code,unused, unused_doc_comments,)]

// Import absolutely EVERYTHING

use ::core::borrow::Borrow;
use defmt::*;
use embassy_executor::Spawner;
use embassy_net::tcp::client::{TcpClient, TcpClientState};
use embassy_net::{Stack, StackResources};
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::{Ethernet, PacketQueue, PHY};
use embassy_stm32::peripherals::*;
use embassy_stm32::rng::Rng;
use embassy_stm32::{bind_interrupts, eth, peripherals, rng, Config, rcc};
use embassy_stm32::rcc::*;
use embassy_time::Timer;
use embedded_io_async::Write;
use embedded_nal_async::{Ipv4Addr, SocketAddr, SocketAddrV4, TcpConnect};
use rand_core::RngCore;
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};
use embassy_net::{Ipv4Cidr, Ipv4Address};
use embassy_stm32::gpio::{Level, Output, Speed};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::channel::Channel;
use embassy_sync::priority_channel::*;
use futures::task::SpawnExt;
use heapless::Vec;
use heapless::Deque;
mod core;
mod pconfig;

use core::finite_state_machine::*;
use core::controllers::finite_state_machine_peripherals::*;
use crate::core::communication::{Datapoint, Datatype};
use crate::pconfig::default_configuration;

type DataSender = embassy_sync::channel::Sender<'static,NoopRawMutex,Datapoint, { DATA_QUEUE_SIZE }>;
type DataReceiver = embassy_sync::channel::Receiver<'static,NoopRawMutex,Datapoint, { DATA_QUEUE_SIZE }>;
type EventSender = embassy_sync::priority_channel::Sender<'static,NoopRawMutex,Event,Max, { EVENT_QUEUE_SIZE }>;
type EventReceiver = embassy_sync::priority_channel::Receiver<'static,NoopRawMutex,Event,Max, { EVENT_QUEUE_SIZE }>;

/// We need to include the external variables imported from build.rs
/// Imports:
/// - GS_IP_ADDRESS: ([u16;4], u16)
/// ++++ (check config.toml and build.rs for more info, this may not be updated)
include!(concat!(env!("OUT_DIR"), "/config.rs"));

bind_interrupts!(struct Irqs {
    ETH => eth::InterruptHandler;
    RNG => rng::InterruptHandler<peripherals::RNG>;
});

static EVENT_QUEUE: StaticCell<PriorityChannel<NoopRawMutex,Event,Max,16>> = StaticCell::new();
static DATA_QUEUE: StaticCell<Channel<NoopRawMutex,Datapoint, { DATA_QUEUE_SIZE }>> = StaticCell::new();

/// Main Function: program entry point
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
	let event_queue : &'static mut PriorityChannel<NoopRawMutex,Event,Max, { EVENT_QUEUE_SIZE }>  = EVENT_QUEUE.init(PriorityChannel::new());

	let event_sender: EventSender = event_queue.sender();
	let event_receiver: Receiver<'static,NoopRawMutex,Event,Max, { EVENT_QUEUE_SIZE }> = event_queue.receiver();

	let data_queue : &'static mut Channel<NoopRawMutex,Datapoint, { DATA_QUEUE_SIZE }>  = DATA_QUEUE.init(Channel::new());

	let data_sender: DataSender = data_queue.sender();
	let data_receiver: DataReceiver = data_queue.receiver();
	// Begin peripheral configuration


	let mut per: FSMPeripherals = FSMPeripherals::new(p, spawner.borrow(), event_sender, data_receiver);
	//let mut nucleo_green_led = Output::new(p.PB14, Level::High, Speed::Low); // <- TODO - Initialize all the peripherals in FSMPeripheral
	
	// End peripheral configuration

	/// Create FSM


	let mut fsm = FSM::new(per, event_receiver, data_sender);
	fsm.entry();

	///
	
	// Begin Spawn Tasks
	
	// End Spawn Tasks

	// let mut spawner = Spawner::new(&raw::Executor::new());
	//Spawner::must_spawn(test_task(sender_one));
	// Main Loop
	loop {
		info!("in da loop");
		let curr_event = fsm.event_queue.receive().await;
		info!("in da loop");
		fsm.react(curr_event);
	}
}


#[embassy_executor::task]
async fn test_task(sender: Sender<'static,NoopRawMutex,Event,Max,16>) {
	info!("------------ Test Task Starte! ------------");

	// let mut event_queue: PriorityChannel<NoopRawMutex,Event,Max,16>=PriorityChannel::new();

		sender.send(Event::BootingCompleteEvent).await;
	sender.send(Event::EmergencyBrakeCommand).await;


	info!("------------ Test Task Ended! ------------");
}
