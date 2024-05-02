use embassy_net::Stack;
use embassy_stm32::eth::{Ethernet, PacketQueue};
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::gpio::Output;
use embassy_stm32::peripherals;
use embassy_stm32::peripherals::{ETH, PB5, PB6, PD0, PD1, PD5, PD6, RNG};
use embassy_stm32::rng::Rng;
use rand_core::RngCore;
use static_cell::StaticCell;
use crate::{CanOneInterrupts, CanReceiver, CanSender, CanTwoInterrupts, DataReceiver, DataSender, EventSender, POD_MAC_ADDRESS};

use core::arch::asm;
use defmt::*;
use embassy_executor::Spawner;
use embassy_net::tcp::client::{TcpClient, TcpClientState};
use embassy_net::{StackResources};
use embassy_stm32::eth::{PHY};
use embassy_stm32::{bind_interrupts, eth, rng, Config};
use embedded_io_async::Write;
use embedded_nal_async::{Ipv4Addr, SocketAddr, SocketAddrV4, TcpConnect};
use {defmt_rtt as _, panic_probe as _};
use embassy_net::{Ipv4Cidr, Ipv4Address};
use embassy_stm32::gpio::{Level, Speed};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::Sender;
use heapless::binary_heap::Max;
use heapless::Vec;
use crate::core::communication::tcp::tcp_connection_handler;
use crate::core::communication::udp::udp_connection_handler;
use embassy_stm32::flash::Error::Size;
use embassy_stm32::gpio::{Input, Pull};
use embassy_stm32::{can, Peripheral, Peripherals};
use embassy_stm32::gpio::low_level::Pin;
use embassy_stm32::peripherals::{FDCAN1, FDCAN2};
use embassy_time::{Duration, Instant, Timer};
use crate::core::communication::can::{can_receiving_handler, can_transmitter};
use crate::core::controllers::battery_controller::{BatteryController, GroundFaultDetection};
use crate::core::controllers::ethernet_controller::EthernetPins;


pub struct CanPins {
    pub fdcan1 : FDCAN1,
    pub fdcan2 : FDCAN2,
    pub pd0_pin : PD0,
    pub pd1_pin : PD1,
    pub pb5_pin : PB5,
    pub pb6_pin : PB6,
}

pub struct CanTwoUtils {
    pub can_sender: CanSender,
    pub hv_controller: BatteryController,
    pub lv_controller: BatteryController,
    pub gfd_controller: GroundFaultDetection,
}

pub struct CanController {

}

impl CanController {
    pub fn new(
        x: Spawner,
        event_sender: EventSender,
        data_sender: DataSender,
        data_receiver: DataReceiver,
        can_one_sender: CanSender,
        can_one_receiver: CanReceiver,
        can_two_sender: CanSender,
        can_two_receiver: CanReceiver,
        pins: CanPins,
        hv_controller:  BatteryController,
        lv_controller:  BatteryController,
    ) -> Self {

        let mut can1 = can::FdcanConfigurator::new(pins.fdcan1, pins.pd0_pin, pins.pd1_pin, CanOneInterrupts);

        let mut can2 = can::FdcanConfigurator::new(pins.fdcan2, pins.pb5_pin, pins.pb6_pin, CanTwoInterrupts); // <--- Im not really sure if this are the correct pins

        can1.set_bitrate(1_000_000);
        can2.set_bitrate(1_000_000);

        let mut can1 = can1.into_normal_mode();
        let mut can2 = can2.into_normal_mode();

        let (mut c1_tx, mut c1_rx) = can1.split();
        let (mut c2_tx, mut c2_rx) = can2.split();
        c1_tx.write(&can::frame::ClassicFrame::new_standard(0x123, &[1, 2, 3, 4]).unwrap());

        unwrap!(x.spawn(can_receiving_handler(x, event_sender.clone(), can_one_receiver.clone(), data_sender.clone(), c1_rx, None)));
        unwrap!(x.spawn(can_receiving_handler(x, event_sender.clone(), can_two_receiver.clone(), data_sender.clone(), c2_rx,
        Some(CanTwoUtils {
                can_sender: can_two_sender.clone(),
                hv_controller,
                lv_controller,
                gfd_controller: GroundFaultDetection{},
        }))));

        unwrap!(x.spawn(can_transmitter(can_one_receiver.clone(), c1_tx)));
        unwrap!(x.spawn(can_transmitter(can_two_receiver.clone(), c2_tx)));

        Self {

        }
    }
}
