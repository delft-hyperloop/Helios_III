use defmt::debug;
use defmt::trace;
use defmt_rtt as _;
use embassy_executor::Spawner;
use embassy_net::Stack;
use embassy_net::StackResources;
use embassy_net::StaticConfigV4;
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::Ethernet;
use embassy_stm32::eth::PacketQueue;
use embassy_stm32::peripherals;
use embassy_stm32::peripherals::ETH;
use embassy_stm32::rng::Rng;
use heapless::Deque;
use panic_probe as _;
use rand_core::RngCore;
use static_cell::StaticCell;
use crate::core::communication::comm::ExternalCommunicationHandler;
use crate::core::communication::tcp::{EthernetInit, EthernetPins, TcpCommunication};

use crate::pconfig::ip_cidr_from_config;
use crate::{NETWORK_BUFFER_SIZE, try_spawn};
use crate::core::communication::task::external_communication_task;
use crate::DataReceiver;
use crate::DataSender;
use crate::EventSender;
use crate::Irqs;
use crate::POD_IP_ADDRESS;
use crate::POD_MAC_ADDRESS;
use crate::USE_DHCP;




pub struct ExternalController {}

impl ExternalController {
    pub async fn new(
        x: Spawner,
        event_sender: EventSender,
        data_receiver: DataReceiver,
        data_sender: DataSender,
        pins: EthernetPins,
    ) -> Self {
        let tcp = TcpCommunication::new(EthernetInit {
            x,
            sender: event_sender,
            pins
        }).await;

        let comm = ExternalCommunicationHandler::<TcpCommunication> {
            inner: tcp,
            ds: data_sender,
            dr: data_receiver,
            es: event_sender,
            parsing_buffer: Deque::<u8, { NETWORK_BUFFER_SIZE }>::new(),
        };

        try_spawn!(event_sender, x.spawn(external_communication_task(comm)));

        Self {}
    }
}
