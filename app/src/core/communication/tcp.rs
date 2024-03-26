use defmt::*;
use embassy_executor::Spawner;
use embassy_net::tcp::client::{TcpClient, TcpClientState};
use embassy_net::{Stack, StackResources};
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::{Ethernet, PacketQueue, PHY};
use embassy_stm32::peripherals::ETH;
use embassy_stm32::rng::Rng;
use embassy_stm32::{bind_interrupts, eth, peripherals, rng, Config};
use embassy_time::Timer;
use embedded_io_async::{Read, Write};
use embedded_nal_async::{Ipv4Addr, SocketAddr, SocketAddrV4, TcpConnect};
use rand_core::RngCore;
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};
use embassy_net::{Ipv4Cidr, Ipv4Address};
use embassy_net::tcp::TcpSocket;
use embassy_stm32::gpio::{Level, Output, Speed};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::{Receiver, Sender};
use heapless::binary_heap::Max;
use heapless::Vec;
use crate::{DataReceiver, EventSender, GS_IP_ADDRESS, GS_UPD_IP_ADDRESS, NETWORK_BUFFER_SIZE};
use crate::core::communication::dispatcher::ground_station_message_dispatcher;
use crate::core::finite_state_machine::Event;
use crate::pconfig::socket_from_config;


/// This is the task that:
/// 1. bugs the ground station to connect until it does
/// 2. assigns receiving messages over MPSC channel and sending them over eth to another task
/// 3. has the receiving from TCP internal loop, where it creates Events on the EventQueue
#[embassy_executor::task]
pub async fn tcp_connection_handler(
    x: Spawner,
    stack: &'static Stack<Ethernet<'static, ETH, GenericSMI>>,
    event_sender : EventSender,
    data_receiver : DataReceiver,
) -> ! {
    stack.wait_config_up().await;

    // let state: TcpClientState<1, 1024, 1024> = TcpClientState::new();
    //
    // let client = TcpClient::new(&stack, &state);

    let gs_addr = socket_from_config(GS_IP_ADDRESS);
    let mut rx_buffer = [0u8; { NETWORK_BUFFER_SIZE }];
    let mut tx_buffer = [0u8; { NETWORK_BUFFER_SIZE }];
    let mut socket = TcpSocket::new(stack, &mut rx_buffer, &mut tx_buffer);

    let mut buf = [0; 1024];
    loop {
        socket.connect(gs_addr).await.unwrap();
        info!("Connected to ground station");

        let (mut tcp_reader,mut tcp_writer) = socket.split();

        // spawn the writer task: it will take messages from the channel and send them over the TCP connection
        x.spawn(ground_station_message_dispatcher(tcp_writer, data_receiver.clone())).unwrap();

        // loop to receive data from the TCP connection
        loop {

            let n = tcp_reader.read(&mut buf).await.unwrap();
            if n == 0 {
                break;
            }
            info!("Received: {:?}", &buf[..n]);
        }
        socket = TcpSocket::new(stack, &mut rx_buffer, &mut tx_buffer);
        // if this is reached, it means that the connection was dropped
    }
}