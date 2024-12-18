use defmt::debug;
use defmt::error;
use defmt::info;
use defmt::trace;
use defmt_rtt as _;
use embassy_executor::Spawner;
use embassy_net::tcp::TcpSocket;
use embassy_net::IpEndpoint;
use embassy_net::Stack;
use embassy_net::StackResources;
use embassy_net::StaticConfigV4;
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::Ethernet;
use embassy_stm32::eth::PacketQueue;
use embassy_stm32::peripherals;
use embassy_stm32::peripherals::ETH;
use embassy_stm32::rng::Rng;
use embassy_time::Instant;
use embassy_time::Timer;
use embedded_io_async::ReadReady;
use embedded_io_async::Write;
use embedded_io_async::WriteReady;
use panic_probe as _;
use rand_core::RngCore;
use static_cell::StaticCell;

use crate::core::communication::CommunicationError;
use crate::core::communication::CommunicationError::CannotConnect;
use crate::core::communication::CommunicationError::CannotRead;
use crate::core::communication::CommunicationError::CannotWrite;
use crate::core::communication::CommunicationError::ConnectionTimedOut;
use crate::core::communication::CommunicationError::NoActiveConnection;
use crate::core::communication::HardwareLayer;
use crate::pconfig::embassy_socket_from_config;
use crate::pconfig::ip_cidr_from_config;
use crate::pconfig::millis;
use crate::pconfig::send_event;
use crate::try_spawn;
use crate::Event;
use crate::EventSender;
use crate::Irqs;
use crate::GS_IP_ADDRESS;
use crate::IP_TIMEOUT;
use crate::NETWORK_BUFFER_SIZE;
use crate::POD_IP_ADDRESS;
use crate::POD_MAC_ADDRESS;
use crate::USE_DHCP;

static mut TCP_RX_BUFFER: [u8; NETWORK_BUFFER_SIZE] = [0u8; NETWORK_BUFFER_SIZE];
static mut TCP_TX_BUFFER: [u8; NETWORK_BUFFER_SIZE] = [0u8; NETWORK_BUFFER_SIZE];

pub struct TcpCommunication<'a> {
    stack: &'static Stack<Ethernet<'static, ETH, GenericSMI>>,
    es: EventSender,
    last_valid_timestamp: u64, // in milliseconds
    pub socket: Option<TcpSocket<'a>>,
    addr: IpEndpoint,
}

pub struct EthernetInit {
    pub(crate) x: Spawner,
    pub(crate) sender: EventSender,
    pub(crate) pins: EthernetPins,
}

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

type Device = Ethernet<'static, ETH, GenericSMI>;

#[embassy_executor::task]
async fn net_task(stack: &'static Stack<Device>) -> ! { stack.run().await }

impl HardwareLayer for TcpCommunication<'static> {
    async fn init(&mut self) {
        self.stack.wait_config_up().await;
        self.last_valid_timestamp = Instant::now().as_millis();
    }

    async fn connect(&mut self) -> Result<(), CommunicationError> {
        let mut socket: TcpSocket = unsafe {
            let a = TCP_RX_BUFFER.as_mut();
            a.iter_mut().for_each(|x| *x = 0);
            let b = TCP_TX_BUFFER.as_mut();
            b.iter_mut().for_each(|x| *x = 0);
            TcpSocket::new(self.stack, a, b)
        };

        match socket.connect(self.addr).await {
            // match socket.accept(self.addr).await {
            Ok(_) => {
                self.last_valid_timestamp = Instant::now().as_millis();
                self.socket = Some(socket);
                Ok(())
            },
            Err(e) => {
                let d = Instant::now().as_millis() - self.last_valid_timestamp;
                error!("[tcp:stack] error connecting to gs: {:?} (diff={})", e, d);
                if d > IP_TIMEOUT {
                    send_event(self.es, Event::ConnectionLossEvent);
                    Timer::after_millis(900).await;
                }
                Timer::after_millis(100).await;
                Err(CannotConnect)
            },
        }
    }

    async fn read_bytes(&mut self, buffer: &mut [u8]) -> Result<usize, CommunicationError> {
        // debug!("reading bytes");
        if let Some(s) = &mut self.socket {
            let d = millis() - self.last_valid_timestamp;
            if !s.may_recv() || !s.may_send() {
                error!("[tcp] may_recv: connection closed");
                Err(NoActiveConnection)
            } else if d > IP_TIMEOUT {
                error!("[tcp] may_recv: connection timed out (d={:?})", d);
                Err(ConnectionTimedOut)
            } else if s.can_recv() {
                self.last_valid_timestamp = millis();
                match s.read(buffer).await.unwrap_or(420000) {
                    0 => {
                        info!("[tcp] Connection closed by ground station..");
                        send_event(self.es, Event::ConnectionLossEvent);
                        return Err(NoActiveConnection);
                    },
                    420000 => {
                        error!("[tcp] Failed to read from socket");
                        return Err(CannotRead);
                    },
                    n => Ok(n),
                }
            } else {
                // buffer empty
                // warn!("[tcp read_bytes] buffer empty");
                Ok(0)
            }
        } else {
            Err(NoActiveConnection)
        }
    }

    async fn try_read_bytes(&mut self, buffer: &mut [u8]) -> Result<usize, CommunicationError> {
        if self.can_read_now() {
            self.read_bytes(buffer).await
        } else {
            Err(CannotRead)
        }
    }

    async fn write_bytes(&mut self, bytes: &[u8]) -> Result<usize, CommunicationError> {
        if let Some(s) = &mut self.socket {
            match s.write_all(bytes).await {
                Ok(_) => Ok(bytes.len()),
                Err(e) => {
                    error!("[tcp] Error writing to tcp socket: {:?}", e);
                    Err(CannotWrite)
                },
            }
        } else {
            Err(NoActiveConnection)
        }
    }

    async fn try_write_bytes(&mut self, bytes: &[u8]) -> Result<usize, CommunicationError> {
        if self.writeable() {
            self.write_bytes(bytes).await
        } else {
            Err(CannotWrite)
        }
    }

    fn readable(&mut self) -> bool {
        if let Some(s) = &self.socket {
            s.may_recv()
        } else {
            false
        }
    }

    fn can_read_now(&mut self) -> bool {
        if let Some(s) = &mut self.socket {
            s.read_ready().unwrap_or_else(|e| {
                error!("[tcp] error getting socket read status: {:?}", e);
                false
            })
        } else {
            false
        }
    }

    fn writeable(&mut self) -> bool {
        if let Some(s) = &mut self.socket {
            s.write_ready().unwrap_or_else(|y| {
                error!("[tcp] error getting socket write status: {:?}", y);
                false
            })
        } else {
            false
        }
    }

    async fn close_connection(&mut self) {
        if let Some(s) = &mut self.socket {
            s.abort();
            self.socket = None;
        }
    }
}

impl TcpCommunication<'_> {
    pub(crate) async fn new(init: EthernetInit) -> Self {
        let mut rng = Rng::new(init.pins.p_rng, Irqs);
        let mut seed = [0; 8];
        rng.fill_bytes(&mut seed);
        let seed = u64::from_le_bytes(seed);
        debug!("Seed: {:?}", seed);
        let mac_addr = POD_MAC_ADDRESS;
        debug!("MAC Address: {:?}", mac_addr);
        static PACKETS: StaticCell<PacketQueue<16, 16>> = StaticCell::new();

        let device: Device = Ethernet::new(
            PACKETS.init(PacketQueue::<16, 16>::new()),
            init.pins.eth_pin,
            Irqs,
            init.pins.pa1_pin,
            init.pins.pa2_pin,
            init.pins.pc1_pin,
            init.pins.pa7_pin,
            init.pins.pc4_pin,
            init.pins.pc5_pin,
            init.pins.pg13_pin,
            init.pins.pb13_pin,
            init.pins.pg11_pin,
            GenericSMI::new(0),
            mac_addr,
        );
        trace!("MAC Address: {:?}", mac_addr);

        let eth_config: embassy_net::Config = if USE_DHCP {
            embassy_net::Config::dhcpv4(Default::default())
        } else {
            embassy_net::Config::ipv4_static(StaticConfigV4 {
                address: ip_cidr_from_config(POD_IP_ADDRESS),
                gateway: None,
                dns_servers: Default::default(),
            })
        };
        trace!("MAC Address: {:?}", mac_addr);

        static STACK: StaticCell<Stack<Device>> = StaticCell::new();

        static RESOURCES: StaticCell<StackResources<3>> = StaticCell::new();
        let stack: &Stack<Device> = &*STACK.init(Stack::new(
            device,
            eth_config,
            RESOURCES.init(StackResources::<3>::new()),
            seed,
        ));

        try_spawn!(init.sender, init.x.spawn(net_task(stack)));

        Self {
            stack,
            es: init.sender,
            socket: None,
            last_valid_timestamp: 0,
            addr: unsafe { embassy_socket_from_config(GS_IP_ADDRESS) },
        }
    }
}
