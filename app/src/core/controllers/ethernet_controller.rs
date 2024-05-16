use crate::core::communication::tcp::tcp_connection_handler;
use crate::core::communication::udp::udp_connection_handler;
use crate::{Event, POD_IP_ADDRESS};
use crate::{try_spawn, DataReceiver, EventSender, Irqs, POD_MAC_ADDRESS};
use core::arch::asm;
use defmt::*;
use embassy_executor::Spawner;
use embassy_net::tcp::client::{TcpClient, TcpClientState};
use embassy_net::{Stack, StaticConfigV4};
use embassy_net::StackResources;
use embassy_net::{Ipv4Address, Ipv4Cidr};
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::PHY;
use embassy_stm32::eth::{Ethernet, PacketQueue};
use embassy_stm32::gpio::Output;
use embassy_stm32::gpio::{Level, Speed};
use embassy_stm32::peripherals;
use embassy_stm32::peripherals::{ETH, RNG};
use embassy_stm32::rng::Rng;
use embassy_stm32::{bind_interrupts, eth, rng, Config};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::Sender;
use embassy_time::Timer;
use embedded_io_async::Write;
use embedded_nal_async::{Ipv4Addr, SocketAddr, SocketAddrV4, TcpConnect};
use heapless::binary_heap::Max;
use heapless::Vec;
use rand_core::RngCore;
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};
use crate::pconfig::ip_cidr_from_config;

type Device = Ethernet<'static, ETH, GenericSMI>;

pub struct EthernetPins {
    pub p_rng: peripherals::RNG,
    pub eth_pin: peripherals::ETH,
    pub pa1_pin: peripherals::PA1,
    pub pa2_pin: peripherals::PA2,
    pub pc1_pin: peripherals::PC1,
    pub pa7_pin: peripherals::PA7,
    pub pc4_pin: peripherals::PC4,
    pub pc5_pin: peripherals::PC5,
    pub pg13_pin: peripherals::PG13,
    pub pb13_pin: peripherals::PB13,
    pub pg11_pin: peripherals::PG11,
}

pub struct EthernetController {}

#[embassy_executor::task]
async fn net_task(stack: &'static Stack<Device>) -> ! {
    stack.run().await
}

impl EthernetController {
    pub async fn new(
        x: Spawner,
        sender: EventSender,
        receiver: DataReceiver,
        pins: EthernetPins,
    ) -> Self {
        let mut rng = Rng::new(pins.p_rng, Irqs);
        let mut seed = [0; 8];
        rng.fill_bytes(&mut seed);
        let seed = u64::from_le_bytes(seed);

        let mac_addr = POD_MAC_ADDRESS;

        static PACKETS: StaticCell<PacketQueue<16, 16>> = StaticCell::new();

        let mut device: Device = Ethernet::new(
            PACKETS.init(PacketQueue::<16, 16>::new()),
            pins.eth_pin,
            Irqs,
            pins.pa1_pin,
            pins.pa2_pin,
            pins.pc1_pin,
            pins.pa7_pin,
            pins.pc4_pin,
            pins.pc5_pin,
            pins.pg13_pin,
            pins.pb13_pin,
            pins.pg11_pin,
            GenericSMI::new(0),
            mac_addr,
        );

        let eth_config: embassy_net::Config = embassy_net::Config::dhcpv4(Default::default());
        // let eth_config: embassy_net::Config = embassy_net::Config::ipv4_static(
        //     StaticConfigV4 {
        //         address: ip_cidr_from_config(POD_IP_ADDRESS),
        //         gateway: None,
        //         dns_servers: Default::default(),
        //     }
        // );

        static STACK: StaticCell<Stack<Device>> = StaticCell::new();

        static RESOURCES: StaticCell<StackResources<3>> = StaticCell::new();
        let stack: &Stack<Device> = &*STACK.init(Stack::new(
            device,
            eth_config,
            RESOURCES.init(StackResources::<3>::new()),
            seed,
        ));

        let mut ethernet_controller = Self {};

        try_spawn!(sender, x.spawn(net_task(stack)));

        try_spawn!(
            sender,
            x.spawn(tcp_connection_handler(x, stack, sender, receiver))
        );
        // unwrap!(x.spawn(udp_connection_handler(stack)));

        ethernet_controller
    }
}
