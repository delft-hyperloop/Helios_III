use defmt::*;
use defmt_rtt as _;
use embassy_executor::Spawner;
use embassy_net::tcp::TcpSocket;
use embassy_net::Stack;
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::Ethernet;
use embassy_stm32::peripherals::ETH;
use embassy_time::Instant;
use embassy_time::Timer;
use embedded_io_async::Write;
use embedded_io_async::WriteReady;
use heapless::Deque;
use panic_probe as _;

use crate::core::communication::Datapoint;
use crate::pconfig::embassy_socket_from_config;
use crate::pconfig::queue_data;
use crate::pconfig::queue_event;
use crate::pconfig::send_event;
use crate::pconfig::ticks;
use crate::send_data;
use crate::Command;
use crate::DataReceiver;
use crate::DataSender;
use crate::Datatype;
use crate::Event;
use crate::EventSender;
use crate::Info;
use crate::COMMAND_HASH;
use crate::CONFIG_HASH;
use crate::DATA_HASH;
use crate::EVENTS_HASH;
use crate::GS_IP_ADDRESS;
use crate::IP_TIMEOUT;
use crate::NETWORK_BUFFER_SIZE;

/// This is the task that:
/// 1. bugs the ground station to connect until it does
/// 2. assigns receiving messages over MPSC channel and sending them over eth to another task
/// 3. has the receiving from TCP internal loop, where it creates Events on the EventQueue
#[embassy_executor::task]
pub async fn tcp_connection_handler(
    _x: Spawner,
    stack: &'static Stack<Ethernet<'static, ETH, GenericSMI>>,
    event_sender: EventSender,
    data_receiver: DataReceiver,
    data_sender: DataSender,
) -> ! {
    let mut last_valid_timestamp = Instant::now().as_millis();
    // info!("------------------------------------------------ TCP Connection Handler Started! ------------------------------------------");
    stack.wait_config_up().await;

    // let state: TcpClientState<1, { NETWORK_BUFFER_SIZE }, { NETWORK_BUFFER_SIZE }> = TcpClientState::new();
    //
    // let client = TcpClient::new(&stack, &state);

    let gs_addr = unsafe { embassy_socket_from_config(GS_IP_ADDRESS) };

    // let mut socket: TcpSocket =
    //     TcpSocket::new(stack, unsafe { &mut rx_buffer }, unsafe { &mut tx_buffer });

    let mut buf = [0; { NETWORK_BUFFER_SIZE }];
    'netstack: loop {
        debug!("[netstack] loop starting");

        let mut rx_buffer: [u8; NETWORK_BUFFER_SIZE] = [0u8; { NETWORK_BUFFER_SIZE }];
        let mut tx_buffer: [u8; NETWORK_BUFFER_SIZE] = [0u8; { NETWORK_BUFFER_SIZE }];

        let mut socket: TcpSocket = TcpSocket::new(stack, &mut rx_buffer, &mut tx_buffer);

        match socket.connect(gs_addr).await {
            Ok(_) => {
                last_valid_timestamp = Instant::now().as_millis();
            },
            Err(e) => {
                let d = Instant::now().as_millis() - last_valid_timestamp;
                error!("[tcp:stack] error connecting to gs: {:?} (diff={})", e, d);
                if d > IP_TIMEOUT {
                    send_event(event_sender, Event::ConnectionLossEvent);
                    Timer::after_millis(900).await;
                }
                Timer::after_millis(100).await;
                continue 'netstack;
            },
        }


        // Begin relying on the frontend


        // loop to receive data from the TCP connection
        'connection: loop {
            Timer::after_millis(1).await;
            if !socket.may_recv()
                || !socket.may_send()
                || Instant::now().as_millis() - last_valid_timestamp > IP_TIMEOUT
            {
                error!("[tcp] may_recv: connection closed");
                break 'connection;
            }
            if socket.can_recv() {
                last_valid_timestamp = Instant::now().as_millis();
                let n = socket.read(&mut buf).await.unwrap_or(420000);
                if n == 42000 {
                    error!("[tcp] Failed to read from socket");
                    break 'connection;
                }
                if n == 0 {
                    info!("[tcp] Connection closed by ground station..");
                    send_event(event_sender, Event::ConnectionLossEvent);
                    break 'connection;
                }
                trace!("[tcp] !!!!!!!!!!!!!!! Received::  {:?}", &buf[..n]);


            }

            match socket.write_ready() {
                Ok(x) => {
                    if x {
                        
                    } else {
                        error!("[tcp] socket not writeable");
                        Timer::after_millis(500).await;
                    }
                },
                Err(y) => {
                    error!("[tcp] error getting socket write status: {:?}", y);
                    Timer::after_millis(500).await;
                },
            }
        }
        // if this is reached, it means that the connection was dropped
        error!("D:");
    }
}
