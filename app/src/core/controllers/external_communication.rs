use defmt_rtt as _;
use embassy_executor::Spawner;
use heapless::Deque;
use panic_probe as _;

use crate::core::communication::comm::ExternalCommunicationHandler;
use crate::core::communication::low::tcp::EthernetInit;
use crate::core::communication::low::tcp::EthernetPins;
use crate::core::communication::low::tcp::TcpCommunication;
use crate::core::communication::task::external_communication_task;
use crate::try_spawn;
use crate::DataReceiver;
use crate::DataSender;
use crate::EventSender;
use crate::NETWORK_BUFFER_SIZE;

pub struct ExternalController {}

impl ExternalController {
    pub async fn new(
        x: Spawner,
        event_sender: EventSender,
        data_receiver: DataReceiver,
        data_sender: DataSender,
        pins: EthernetPins,
    ) -> Self {
        let tcp = TcpCommunication::new(EthernetInit { x, sender: event_sender, pins }).await;

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
