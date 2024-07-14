use defmt::*;
use defmt_rtt as _;
use embassy_executor::Spawner;
use embassy_net::tcp::TcpSocket;
use embassy_net::Stack;
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::Ethernet;
use embassy_stm32::peripherals::ETH;
use embassy_sync::channel::TrySendError;
use embassy_time::Instant;
use embassy_time::Timer;
use embedded_io_async::Write;
use embedded_io_async::WriteReady;
use heapless::Deque;
use panic_probe as _;

use crate::core::communication::Datapoint;
use crate::pconfig::{embassy_socket_from_config, queue_data, queue_event, send_event, ticks};
use crate::{Command, Info, send_data};
use crate::DataReceiver;
use crate::DataSender;
use crate::Datatype;
use crate::Event;
use crate::EventSender;
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

    let mut rx_buffer: [u8; NETWORK_BUFFER_SIZE] = [0u8; { NETWORK_BUFFER_SIZE }];
    let mut tx_buffer: [u8; NETWORK_BUFFER_SIZE] = [0u8; { NETWORK_BUFFER_SIZE }];

    let mut socket: TcpSocket = TcpSocket::new(stack, &mut rx_buffer, &mut tx_buffer);

    let mut buf = [0; { NETWORK_BUFFER_SIZE }];
    'netstack: loop {
        info!("[netstack] loop starting");

        match socket.connect(gs_addr).await {
            Ok(_) => {
                last_valid_timestamp = Instant::now().as_millis();
            },
            Err(e) => {
                let d = Instant::now().as_millis() - last_valid_timestamp;
                error!("[tcp:stack] error connecting to gs: {:?} (diff={})", e, d);
                if d > IP_TIMEOUT {
                    send_event(event_sender, Event::ConnectionLossEvent);
                }
                Timer::after_millis(100).await;
                continue 'netstack;
            },
        }
        send_event(event_sender, Event::ConnectionEstablishedEvent);

        // Handshake
        // Exchange hashes of the configuration files
        // in order to confirm that the exchanged ids are correct
        queue_data(data_sender, Datatype::CommandHash, COMMAND_HASH).await;
        queue_data(data_sender, Datatype::EventsHash, EVENTS_HASH).await;
        queue_data(data_sender, Datatype::DataHash, DATA_HASH).await;
        queue_data(data_sender, Datatype::ConfigHash, CONFIG_HASH).await;


        // Begin relying on the frontend
        queue_data(data_sender, Datatype::FrontendHeartbeating, 0).await;

        let mut parsing_buffer = Deque::<u8, { NETWORK_BUFFER_SIZE }>::new();

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
                #[cfg(debug_assertions)]
                info!("[tcp] !!!!!!!!!!!!!!! Received::  {:?}", &buf[..n]);

                buf[0..n].iter().for_each(|x| {
                    parsing_buffer.push_back(*x).unwrap();
                });
                while let Some(p) = parsing_buffer.front() {
                    if *p == 0xFF {
                        if parsing_buffer.len() < 20 {
                            break;
                        } else {
                            // we actually have 20 bytes in the buffer, we can create a command from them
                            let mut x = [0u8; 20];
                            for i in &mut x {
                                *i = parsing_buffer.pop_front().unwrap();
                            }
                            // parsing_buffer.iter().take(20).enumerate().for_each(|(i, y)| { x[i] = *y });

                            let cmd = Command::from_bytes(&x);
                            #[cfg(debug_assertions)]
                            info!("[tcp] Command received: {:?}", cmd);
                            match cmd {
                                Command::EmergencyBrake(_) => {
                                    send_event(event_sender, Event::EmergencyBraking);
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] EmergencyBrake command received!!");
                                    if let Err(e) = socket
                                        .write_all(
                                            &Datapoint::new(
                                                Datatype::Info,
                                                Info::EmergencyBrakeReceived.to_idx(),
                                                ticks(),
                                            )
                                            .as_bytes(),
                                        )
                                        .await
                                    {
                                        error!("Could confirm emergency braking by tcp: {:?}", e);
                                    }
                                    let _ = socket.flush().await;
                                },
                                Command::DefaultCommand(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] DefaultCommand received, unsure what to do with it...");
                                    let _ = socket.flush().await;
                                    let _ = socket
                                        .write_all(b"DefaultCommand received, unsure what to do with it...")
                                        .await;
                                    let _ = socket.flush().await;
                                },
                                Command::launch(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Levitate command received");
                                    send_event(event_sender, Event::LeviLaunchingEvent);
                                },
                                Command::land(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] StopLevitating command received");
                                    send_event(event_sender, Event::LeviLandingEvent);
                                },
                                Command::SetRoute(x) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Configure command received");
                                    send_event(event_sender, Event::SettingRoute(x));
                                },
                                Command::SetSpeeds(x) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Configure command received");
                                    send_event(event_sender, Event::SettingSpeeds(x));
                                },
                                Command::SetOverrides(x) => {
                                    send_event(event_sender, Event::SettingOverrides(x));
                                },
                                Command::SetCurrentSpeed(x) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] SetCurrentSpeed command received");
                                    send_event(event_sender, Event::SetCurrentSpeedCommand(x));
                                },
                                Command::StartRun(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Start Run command received");
                                    send_event(event_sender, Event::RunStarting);
                                },
                                Command::ContinueRun(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Start Run command received");
                                    send_event(event_sender, Event::ContinueRunEvent);
                                },
                                Command::Shutdown(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Shutdown command received");
                                    send_event(event_sender, Event::ExitEvent);
                                },
                                Command::StartHV(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] StartHV command received");
                                    send_event(event_sender, Event::TurnOnHVCommand);
                                },
                                Command::StopHV(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] StopHV command received");
                                    send_event(event_sender, Event::TurnOffHVCommand);
                                },
                                Command::DcOn(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] DcOn command received");
                                    send_event(event_sender, Event::DcTurnedOn);
                                },
                                Command::DcOff(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] DcOff command received");
                                    send_event(event_sender, Event::DcTurnedOff);
                                },
                                Command::EmitEvent(e) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] EmitEvent command received");
                                    send_event(event_sender, Event::from_id((e & 0xFFFF) as u16, Some(69420)));

                                },
                                Command::CreateDatapoint(x) => {
                                    send_data!(data_sender, Datatype::from_id(x as u16), x);
                                },
                                Command::SystemReset(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] SystemReset command received");
                                    send_event(event_sender, Event::SystemResetCommand);
                                },
                                Command::FinishRunConfig(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] FinishRunConfig command received");
                                    send_event(event_sender, Event::RunConfigCompleteEvent);
                                },
                                Command::Heartbeat(x) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Heartbeat command received {} :)", x);
                                    match socket
                                        .write_all(
                                            &Datapoint::new(
                                                Datatype::ResponseHeartbeat,
                                                x,
                                                Instant::now().as_ticks(),
                                            )
                                            .as_bytes(),
                                        )
                                        .await
                                    {
                                        Ok(_) => {},
                                        Err(e) => {
                                            error!("Couldn't respond to heartbeat: {}", e);
                                            // break 'connection;
                                        },
                                    }
                                },
                                Command::FrontendHeartbeat(x) => {
                                    send_data!(data_sender, Datatype::FrontendHeartbeating, x);
                                },
                                Command::ArmBrakes(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] ArmBrakesCommand command received");
                                    queue_event(event_sender, Event::ArmBrakesCommand).await;
                                },
                                _ => {}, // TODO: DELETE THIS
                            }
                        }
                    } else {
                        parsing_buffer.pop_front();
                    }
                }
            }

            match socket.write_ready() {
                Ok(x) => {
                    if x {
                        if let Ok(data) = data_receiver.try_receive() {
                            let data = data.as_bytes();
                            #[cfg(debug_assertions)]
                            info!("[tcp:mpmc] Sending data: {:?}", data);
                            match socket.write_all(&data).await {
                                Ok(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp:socket] Data written successfully");
                                },
                                Err(e) => {
                                    error!("[tcp:socket] Failed to write data: {:?}", e);
                                },
                            }
                        } // the else case is of empty MPMC channel queue,
                          // which triggers very often, so we ignore it.
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
        info!("D:");
    }
}
