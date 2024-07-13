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
use heapless::Deque;
use panic_probe as _;

use crate::core::communication::Datapoint;
use crate::pconfig::embassy_socket_from_config;
use crate::Command;
use crate::DataReceiver;
use crate::DataSender;
use crate::Datatype;
use crate::Event;
use crate::EventSender;
use crate::COMMAND_HASH;
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
    let mut last_valid_timestamp = embassy_time::Instant::now().as_millis();
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
        // info!("====================================================Connecting to ground station______________________________");
        let mut rx_buffer: [u8; NETWORK_BUFFER_SIZE] = [0u8; { NETWORK_BUFFER_SIZE }];
        let mut tx_buffer: [u8; NETWORK_BUFFER_SIZE] = [0u8; { NETWORK_BUFFER_SIZE }];

        let mut socket: TcpSocket = TcpSocket::new(stack, &mut rx_buffer, &mut tx_buffer);

        match socket.connect(gs_addr).await {
            Ok(_) => {
                last_valid_timestamp = embassy_time::Instant::now().as_millis();
            },
            Err(e) => {
                let d = embassy_time::Instant::now().as_millis() - last_valid_timestamp;
                error!("[tcp:stack] error connecting to gs: {:?} (diff={})", e, d);
                if d > IP_TIMEOUT {
                    event_sender.send(Event::ConnectionLossEvent).await;
                }
                Timer::after_millis(500).await;
                continue 'netstack;
            },
        }
        event_sender.send(Event::ConnectionEstablishedEvent).await;
        data_sender
            .send(Datapoint::new(Datatype::CommandHash, COMMAND_HASH, Instant::now().as_ticks()))
            .await;
        data_sender
            .send(Datapoint::new(Datatype::DataHash, DATA_HASH, Instant::now().as_ticks()))
            .await;
        data_sender
            .send(Datapoint::new(Datatype::EventsHash, EVENTS_HASH, Instant::now().as_ticks()))
            .await;
        // let mut connection = client.connect(gs_addr).await.unwrap();
        // info!("----------------------------------------------------------------Connected to ground station==========================");

        // socket.set_keep_alive(Some(Duration::from_millis(KEEP_ALIVE)));
        // socket.set_timeout(Some(Duration::from_millis(IP_TIMEOUT)));

        /*// let (mut tcp_reader,mut tcp_writer) = unsafe { socket.split() };
        // spawn the writer task: it will take messages from the channel and send them over the TCP connection
        // x.spawn(ground_station_message_dispatcher(tcp_writer, data_receiver.clone())).unwrap();*/

        #[cfg(debug_assertions)]
        match socket.write(b"aaaaaaaaaaaaaaa0").await {
            Ok(_) => {
                info!("]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]Data sent successfully")
            },
            Err(e) => {
                info!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Failed to send data: {:?}", e)
            },
        }
        let mut parsing_buffer = Deque::<u8, { NETWORK_BUFFER_SIZE }>::new();

        // loop to receive data from the TCP connection
        'connection: loop {
            Timer::after_millis(1).await;
            if !socket.may_recv() || !socket.may_send() {
                error!("[tcp] may_recv: connection closed");
                break 'connection;
            }
            if socket.can_recv() {
                last_valid_timestamp = embassy_time::Instant::now().as_millis();
                let n = socket.read(&mut buf).await.unwrap_or(420000);
                if n == 42000 {
                    error!("[tcp] Failed to read from socket");
                    break 'connection;
                }
                if n == 0 {
                    info!("[tcp] Connection closed by ground station..");
                    event_sender.send(Event::ConnectionLossEvent).await;
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
                                    event_sender.send(Event::EmergencyBraking).await;
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] EmergencyBrake command received!!");
                                    if let Err(e) = socket
                                        .write_all(
                                            &Datapoint::new(
                                                Datatype::Info,
                                                crate::Info::EmergencyBrakeReceived.to_idx(),
                                                embassy_time::Instant::now().as_ticks(),
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
                                    event_sender.send(Event::LeviLaunchingEvent).await;
                                },
                                Command::land(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] StopLevitating command received");
                                    event_sender.send(Event::LeviLandingEvent).await;
                                },
                                Command::SetRoute(x) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Configure command received");
                                    event_sender.send(Event::SettingRoute(x)).await;
                                },
                                Command::SetSpeeds(x) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Configure command received");
                                    event_sender.send(Event::SettingSpeeds(x)).await;
                                },
                                Command::SetOverrides(x) => {
                                    event_sender.send(Event::SettingOverrides(x)).await;
                                },
                                Command::SetCurrentSpeed(x) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] SetCurrentSpeed command received");
                                    event_sender.send(Event::SetCurrentSpeedCommand(x)).await;
                                },
                                Command::StartRun(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Start Run command received");
                                    event_sender.send(Event::RunStarting).await;
                                },
                                Command::ContinueRun(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Start Run command received");
                                    event_sender.send(Event::ContinueRunEvent).await;
                                },
                                Command::Shutdown(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Shutdown command received");
                                    event_sender.send(Event::ExitEvent).await;
                                },
                                Command::StartHV(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] StartHV command received");
                                    event_sender.send(Event::TurnOnHVCommand).await;
                                },
                                Command::StopHV(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] StopHV command received");
                                    event_sender.send(Event::TurnOffHVCommand).await;
                                    // TODO: no turn off HV exists??
                                },
                                Command::DcOn(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] DcOn command received");
                                    event_sender.send(Event::DcTurnedOn).await;
                                },
                                Command::DcOff(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] DcOff command received");
                                    event_sender.send(Event::DcTurnedOff).await;
                                },
                                Command::EmitEvent(e) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] EmitEvent command received");
                                    event_sender
                                        .send(Event::from_id((e & 0xFFFF) as u16, Some(69420)))
                                        .await;
                                },
                                Command::CreateDatapoint(x) => {
                                    data_sender.send(Datapoint::new(Datatype::from_id(x as u16), x, Instant::now().as_ticks())).await;
                                }
                                Command::SystemReset(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] SystemReset command received");
                                    event_sender.send(Event::SystemResetCommand).await;
                                },
                                Command::FinishRunConfig(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] FinishRunConfig command received");
                                    event_sender.send(Event::RunConfigCompleteEvent).await;
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
                                Command::ArmBrakes(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] ArmBrakesCommand command received");
                                    event_sender.send(Event::ArmBrakesCommand).await;
                                },
                                _ => {}, // TODO: DELETE THIS
                            }
                        }
                    } else {
                        parsing_buffer.pop_front();
                    }
                }
            }

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
        }
        // if this is reached, it means that the connection was dropped
        info!("D:");
    }
}
