use crate::core::communication::can::{can_receiving_handler, can_transmitter};
use crate::core::communication::tcp::tcp_connection_handler;
use crate::core::controllers::battery_controller::{BatteryController, GroundFaultDetection};
use crate::core::controllers::ethernet_controller::EthernetPins;
use crate::Event;
use crate::{
    try_spawn, CanOneInterrupts, CanReceiver, CanSender, CanTwoInterrupts, DataReceiver,
    DataSender, EventSender, POD_MAC_ADDRESS,
};
use core::arch::asm;
use defmt::*;
use embassy_executor::Spawner;
use embassy_net::tcp::client::{TcpClient, TcpClientState};
use embassy_net::Stack;
use embassy_net::StackResources;
use embassy_net::{Ipv4Address, Ipv4Cidr};
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::PHY;
use embassy_stm32::eth::{Ethernet, PacketQueue};
use embassy_stm32::flash::Error::Size;
use embassy_stm32::gpio::Output;
use embassy_stm32::gpio::{Input, Pull};
use embassy_stm32::gpio::{Level, Speed};
use embassy_stm32::peripherals;
use embassy_stm32::peripherals::{ETH, PB5, PB6, PD0, PD1, PD5, PD6, RNG};
use embassy_stm32::peripherals::{FDCAN1, FDCAN2};
use embassy_stm32::rng::Rng;
use embassy_stm32::{bind_interrupts, eth, rng, Config};
use embassy_stm32::{can, Peripheral, Peripherals};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::Sender;
use embassy_time::{Duration, Instant, Timer};
use embedded_io_async::Write;
use embedded_nal_async::{Ipv4Addr, SocketAddr, SocketAddrV4, TcpConnect};
use heapless::binary_heap::Max;
use heapless::Vec;
use rand_core::RngCore;
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};

pub struct CanPins {
    pub fdcan1: FDCAN1,
    pub fdcan2: FDCAN2,
    pub pd0_pin: PD0,
    pub pd1_pin: PD1,
    pub pb5_pin: PB5,
    pub pb6_pin: PB6,
}

pub struct CanTwoUtils {
    pub can_sender: CanSender,
    pub hv_controller: BatteryController,
    pub lv_controller: BatteryController,
    pub gfd_controller: GroundFaultDetection,
}

pub struct CanController {}

impl CanController {
    pub async fn new(
        x: Spawner,
        event_sender: EventSender,
        data_sender: DataSender,
        data_receiver: DataReceiver,
        can_one_sender: CanSender,
        can_one_receiver: CanReceiver,
        can_two_sender: CanSender,
        can_two_receiver: CanReceiver,
        pins: CanPins,
        hv_controller: BatteryController,
        lv_controller: BatteryController,
    ) -> Self {
        let mut can1 =
            can::CanConfigurator::new(pins.fdcan1, pins.pd0_pin, pins.pd1_pin, CanOneInterrupts);

        let mut can2 =
            can::CanConfigurator::new(pins.fdcan2, pins.pb5_pin /* pb5=can2 RX */, pins.pb6_pin /* pb6=can2 TX */, CanTwoInterrupts); 
        can1.config().protocol_exception_handling = false;
        can2.config().protocol_exception_handling = false;

        can1.set_bitrate(1_000_000);
        can2.set_bitrate(1_000_000);

        let mut can1 = can1.into_normal_mode();
        let mut can2 = can2.into_normal_mode();

        let (mut c1_tx, mut c1_rx,p1) = can1.split();
        let (mut c2_tx, mut c2_rx,p2) = can2.split();
        c1_tx.write(&can::frame::Frame::new_standard(0x123, &[1, 2, 3, 4]).unwrap()).await;

        // try_spawn!(
        //     event_sender,
        //     x.spawn(can_receiving_handler(
        //         x,
        //         event_sender.clone(),
        //         can_one_receiver.clone(),
        //         data_sender.clone(),
        //         c1_rx,
        //         None
        //     ))
        // );
        try_spawn!(
            event_sender,
            x.spawn(can_receiving_handler(
                x,
                event_sender.clone(),
                can_two_receiver.clone(),
                data_sender.clone(),
                c2_rx,
                Some(CanTwoUtils {
                    can_sender: can_two_sender.clone(),
                    hv_controller,
                    lv_controller,
                    gfd_controller: GroundFaultDetection {},
                })
            ))
        );

        try_spawn!(
            event_sender,
            x.spawn(can_transmitter(can_one_receiver.clone(), c1_tx))
        );
        try_spawn!(
            event_sender,
            x.spawn(can_transmitter(can_two_receiver.clone(), c2_tx))
        );

        Self {}
    }
}
