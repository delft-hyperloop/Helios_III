#![no_std]
#![no_main]
#![allow(incomplete_features, unused_imports, unused_variables, unused_mut,dead_code)]

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
use embassy_stm32::{bind_interrupts, eth, peripherals, rng, Config, rcc, can};
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
use embassy_sync::priority_channel::*;
use futures::task::SpawnExt;
use heapless::Vec;
use heapless::Deque;
mod core;
use core::finite_state_machine::*;
use core::finite_state_machine_peripherals::*;

/// We need to include the external variables imported from build.rs

// Imports: 
// - GS_IP_ADDRESS: ([u16;4], u16)
include!(concat!(env!("OUT_DIR"), "/config.rs"));




/// Main Function: program entry point

static EVENT_QUEUE: StaticCell<PriorityChannel<NoopRawMutex,Event,Max,16>> = StaticCell::new();
#[embassy_executor::main]
async fn main(spawner: Spawner) -> ! {
	info!("------------ Main Application Started! ------------");
	
	// Configuration start
	let mut config = Config::default();

	config.rcc.hse = Some(rcc::Hse {
		freq: embassy_stm32::time::Hertz(24_000_000),
		mode: rcc::HseMode::Oscillator,
	});
	config.rcc.pll1 = Some(Pll {
		source: PllSource::HSE,
		prediv: PllPreDiv::DIV6,
		mul: PllMul::MUL50,
		divp: Some(PllDiv::DIV8),
		divq: Some(PllDiv::DIV8),
		divr: Some(PllDiv::DIV8),
	});
	config.rcc.mux.fdcansel = rcc::mux::Fdcansel::PLL1_Q;
	// Configuration end. `p` is the most important object in our code; treat it with respect and caution
	let p = embassy_stm32::init(config);


	let event_queue = EVENT_QUEUE.init(PriorityChannel::new());
	//let mut sender_one = event_queue.();
	// static  SENDER_TWO : Sender<NoopRawMutex,Event,Max,16> = event_queue.sender();
	let  sender: Sender<'static,NoopRawMutex,Event,Max,16> = event_queue.sender();
	let  brake_sender: Sender<'static,NoopRawMutex,Event,Max,16> = event_queue.sender();
	let  reciever: Receiver<'static,NoopRawMutex,Event,Max,16> = event_queue.receiver();




	// test_task();
	// test_task().spawn()
	// Begin peripheral configuration


	let mut per: FSMPeripherals = FSMPeripherals::new(p,spawner.borrow(),brake_sender);
	//let mut nucleo_green_led = Output::new(p.PB14, Level::High, Speed::Low); // <- TODO - Initialize all the peripherals in FSMPeripheral
	
	// End peripheral configuration

	/// Create FSM


	let mut fsm = FSM::new(per, reciever);
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
