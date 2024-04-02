use defmt::*;
use embassy_executor::Spawner;
use embassy_net::tcp::client::{TcpClient, TcpClientState};
use embassy_net::{Stack, StackResources};
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::{Ethernet, PacketQueue, PHY};
use embassy_stm32::peripherals::ETH;
use embassy_stm32::rng::Rng;
use embassy_stm32::{bind_interrupts, eth, peripherals, rng, Config};
use embassy_time::{Duration, Timer};
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
use crate::{DataReceiver, EventSender, GS_IP_ADDRESS, GS_UPD_IP_ADDRESS, NETWORK_BUFFER_SIZE, KEEP_ALIVE, IP_TIMEOUT};
use crate::core::finite_state_machine::Event;
use crate::pconfig::{embassy_socket_from_config, socket_from_config};


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
    // info!("------------------------------------------------ TCP Connection Handler Started! ------------------------------------------");
    stack.wait_config_up().await;

    // let state: TcpClientState<1, { NETWORK_BUFFER_SIZE }, { NETWORK_BUFFER_SIZE }> = TcpClientState::new();
    //
    // let client = TcpClient::new(&stack, &state);

    let gs_addr = embassy_socket_from_config(GS_IP_ADDRESS);
    let mut rx_buffer: [u8; { NETWORK_BUFFER_SIZE }] = [0u8; { NETWORK_BUFFER_SIZE }];
    let mut tx_buffer: [u8; { NETWORK_BUFFER_SIZE }] = [0u8; { NETWORK_BUFFER_SIZE }];

    let mut socket: TcpSocket = TcpSocket::new(stack, unsafe { &mut rx_buffer }, unsafe { &mut tx_buffer });

    let mut buf = [0; 1024];
    loop {
        // info!("====================================================Connecting to ground station______________________________");
        socket.connect(gs_addr).await;
        // let mut connection = client.connect(gs_addr).await.unwrap();
        // info!("----------------------------------------------------------------Connected to ground station==========================");

        // socket.set_keep_alive(Some(Duration::from_millis(KEEP_ALIVE)));
        // socket.set_timeout(Some(Duration::from_millis(IP_TIMEOUT)));

        /*// let (mut tcp_reader,mut tcp_writer) = unsafe { socket.split() };
        // spawn the writer task: it will take messages from the channel and send them over the TCP connection
        // x.spawn(ground_station_message_dispatcher(tcp_writer, data_receiver.clone())).unwrap();*/

        match socket.write(b"aaaaaaaaaaaaaaa0").await {
            Ok(_) => info!("]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]Data sent successfully"),
            Err(e) => info!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Failed to send data: {:?}", e),
        }
        // info!("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@THIS LINE NEVER GETS EXECUTED :(((((");
        // loop to receive data from the TCP connection
        loop {
            // info!("in the ethernet loop---------------------------");
            // socket.write(b"in da tcp loop!").await;

            if cfg!(debug_assertions) {
                event_sender.send(Event::DefaultEvent).await;
                info!("[tcp] Sent default event");
                Timer::after_millis(1000).await;
            } else {
                Timer::after_micros(1).await;
            }
            if socket.can_recv() {
                let n = socket.read(&mut buf).await.unwrap();
                if n == 0 {
                    break;
                }
                #[cfg(debug_assertions)]
                info!("[tcp] !!!!!!!!!!!!!!! Received::  {:?}", &buf[..n]);
            }
            // socket.write_all(b"trying to receive on data mpmc").await;
            socket.flush().await;
            match data_receiver.try_receive() {
                Ok(data) => {
                    // socket.write(b"received on data mpmc").await;
                    let mut data = data.as_bytes();
                    #[cfg(debug_assertions)]
                    info!("[tcp:mpmc] Sending data: {:?}", data);
                    socket.write_all(&mut data).await.unwrap();
                    // socket.
                }
                Err(_) => {
                    // socket.write(b"took an L on data mpmc").await;
                    #[cfg(debug_assertions)]
                    info!("[tcp:mpmc] No data on mpmc channel to send");
                }
            }
        }
        // if this is reached, it means that the connection was dropped
        info!("SOMETHING FUCKED UP! D:");
    }
}