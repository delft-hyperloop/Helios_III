#![no_std]
#![no_main]


// Import absolutely EVERYTHING


use defmt::*;
use embassy_executor::Spawner;
use embassy_net::tcp::client::{TcpClient, TcpClientState};
use embassy_net::{Stack, StackResources};
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::{Ethernet, PacketQueue, PHY};
use embassy_stm32::peripherals::ETH;
use embassy_stm32::rng::Rng;
use embassy_stm32::{bind_interrupts, eth, peripherals, rng, Config};
use embassy_stm32::rcc::*;
use embassy_time::Timer;
use embedded_io_async::Write;
use embedded_nal_async::{Ipv4Addr, SocketAddr, SocketAddrV4, TcpConnect};
use rand_core::RngCore;
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};
use embassy_net::{Ipv4Cidr, Ipv4Address};
use embassy_stm32::gpio::{Level, Output, Speed};
use heapless::Vec;
use heapless::Deque;
mod core;

/// We need to include the external variables imported from build.rs

// Imports: 
// - GS_IP_ADDRESS: ([u16;4], u16)
include!(concat!(env!("OUT_DIR"), "/config.rs"));




/// Main Function: program entry point
/// 
#[embassy_executor::main]
async fn main(spawner: Spawner) -> ! {
	info!("------------ Main Application Started! ------------");
	
	// Configuration start
	let mut config = Config::default();


	// Configuration end. `p` is the most important object in our code; treat it with respect and caution
	let p = embassy_stm32::init(config);

	// Begin peripheral configuration
	let mut nucleo_green_led = Output::new(p.PB14, Level::High, Speed::Low);
	
	// End peripheral configuration
	
	
	/// Create FSM


	///
	
	// Begin Spawn Tasks
	
	// End Spawn Tasks

	// Main Loop
	loop {
		nucleo_green_led.set_high();
        	Timer::after_millis(500).await;	
		nucleo_green_led.set_low();
        	Timer::after_millis(500).await;



		// event = fsm.queue.pop_front();
		// fsm.react(event);
	}
}


