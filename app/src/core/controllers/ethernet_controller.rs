use defmt_rtt as _;
use defmt::info;
use embassy_executor::Spawner;
use embassy_net::Stack;
use embassy_net::StackResources;
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::Ethernet;
use embassy_stm32::eth::PacketQueue;
use embassy_stm32::peripherals;
use embassy_stm32::peripherals::ETH;
use embassy_stm32::rng::Rng;
use panic_probe as _;
use rand_core::RngCore;
use static_cell::StaticCell;

use crate::core::communication::tcp::tcp_connection_handler;
use crate::try_spawn;
use crate::DataReceiver;
use crate::Event;
use crate::EventSender;
use crate::Irqs;
use crate::POD_MAC_ADDRESS;

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

info!("eth 6");
        let device: Device = Ethernet::new(
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

info!("eth 7");
        let eth_config: embassy_net::Config = embassy_net::Config::dhcpv4(Default::default());
        //        let eth_config: embassy_net::Config = embassy_net::Config::ipv4_static(
info!("eth 8");
        //            StaticConfigV4 {
        //                address: ip_cidr_from_config(POD_IP_ADDRESS),
        //                gateway: None,
        //                dns_servers: Default::default(),
        //            }
        //        );

        static STACK: StaticCell<Stack<Device>> = StaticCell::new();

info!("eth 9");
        static RESOURCES: StaticCell<StackResources<3>> = StaticCell::new();
info!("eth 10");
        let stack: &Stack<Device> = &*STACK.init(Stack::new(
            device,
            eth_config,
            RESOURCES.init(StackResources::<3>::new()),
            seed,
        ));

info!("eth 11");
        let ethernet_controller = Self {};

       try_spawn!(sender, x.spawn(net_task(stack)));

        try_spawn!(
            sender,
            x.spawn(tcp_connection_handler(x, stack, sender, receiver))
        );
        // unwrap!(x.spawn(udp_connection_handler(stack)));

        ethernet_controller
    }
}
