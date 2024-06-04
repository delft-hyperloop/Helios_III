use defmt::*;
use defmt_rtt as _;
use embassy_executor::Spawner;
use embassy_net::tcp::TcpSocket;
use embassy_net::Stack;
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::Ethernet;
use embassy_stm32::peripherals::ETH;
use embassy_time::Timer;
use embedded_io_async::Write;
use heapless::Deque;
use panic_probe as _;

use crate::core::communication::Datapoint;
use crate::pconfig::embassy_socket_from_config;
use crate::Command;
use crate::DataReceiver;
use crate::Datatype;
use crate::Event;
use crate::EventSender;
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
            }
            Err(e) => {
                let d = embassy_time::Instant::now().as_millis() - last_valid_timestamp;
                error!("[tcp:stack] error connecting to gs: {:?} (diff={})", e, d);
                if d > IP_TIMEOUT {
                    event_sender.send(Event::EmergencyBrakeCommand).await;
                }
                Timer::after_millis(500).await;
                continue 'netstack;
            }
        }
        event_sender.send(Event::ConnectionEstablishedEvent).await;
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
            }
            Err(e) => info!(
                ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Failed to send data: {:?}",
                e
            ),
        }
        let mut parsing_buffer = Deque::<u8, { NETWORK_BUFFER_SIZE }>::new();

        // loop to receive data from the TCP connection
        'connection: loop {
            // info!("in the ethernet loop---------------------------");
            // socket.write(b"in da tcp loop!").await;

            //            if cfg!(debug_assertions) {
            //                event_sender.send(Event::DefaultEvent).await;
            //                info!("[tcp] Sent default event");
            //                Timer::after_millis(1000).await;
            //            } else {
            Timer::after_millis(1).await;
            //            }
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
                            #[cfg(debug_assertions)]
                            let _ = socket
                                .write_all(
                                    &Datapoint::new(
                                        Datatype::Info,
                                        cmd.to_id() as u64,
                                        embassy_time::Instant::now().as_ticks(),
                                    )
                                    .as_bytes(),
                                )
                                .await;
                            match cmd {
                                Command::EmergencyBrake(_) => {
                                    event_sender.send(Event::EmergencyBrakeCommand).await;
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] EmergencyBrake command received!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
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
                                    // socket.write_all(b"").await;
                                }
                                Command::DefaultCommand(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] DefaultCommand received, unsure what to do with it...");
                                    let _ = socket.flush().await;
                                    let _ = socket
                                        .write_all(b"DefaultCommand received, unsure what to do with it...")
                                        .await;
                                    let _ = socket.flush().await;
                                }
                                Command::Levitate(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Levitate command received");
                                    event_sender.send(Event::StartLevitatingCommand).await;
                                }
                                Command::StopLevitating(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] StopLevitating command received");
                                    // event_sender.send(Event::).await; // TODO: theres no stop levitating event??
                                }
                                Command::Configure(x) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Configure command received");
                                    event_sender.send(Event::SetRunConfig(x)).await;
                                }
                                Command::StartRun(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Start Run command received");
                                    event_sender.send(Event::StartLevitatingCommand).await;
                                    event_sender.send(Event::StartAcceleratingCommand).await;
                                }
                                Command::Shutdown(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Shutdown command received");
                                    event_sender.send(Event::ExitEvent).await;
                                }
                                Command::StartHV(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] StartHV command received");
                                    event_sender.send(Event::TurnOnHVCommand).await;
                                }
                                Command::StopHV(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] StopHV command received");
                                    event_sender.send(Event::TurnOffHVCommand).await;
                                    // TODO: no turn off HV exists??
                                }
                                Command::EmitEvent(e) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] EmitEvent command received");
                                    event_sender
                                        .send(Event::from_id((e & 0xFFFF) as u16, Some(69420)))
                                        .await;
                                }
                                Command::SystemReset(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] SystemReset command received");
                                    event_sender.send(Event::SystemResetCommand).await;
                                }
                                Command::FinishRunConfig(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] FinishRunConfig command received");
                                    event_sender.send(Event::RunConfigCompleteEvent).await;
                                }
                                Command::Heartbeat(x) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] Heartbeat command received {} :)", x);
                                    match socket.write_all(&Datapoint::new(Datatype::ResponseHeartbeat, x, embassy_time::Instant::now().as_ticks()).as_bytes()).await {
                                        Ok(_) => {}
                                        Err(e) => {
                                            error!("Couldn't respond to heartbeat: {}", e);
                                            // break 'connection;
                                        }
                                    }
                                }
                                Command::ArmBrakes(_) => {
                                    #[cfg(debug_assertions)]
                                    info!("[tcp] ArmBrakesCommand command received");
                                    event_sender.send(Event::ArmBrakesCommand).await;
                                }
                                // Command::TurnAllHVRelaysOnUNSAFE(_) => {
                                //     #[cfg(debug_assertions)]
                                //     info!("[tcp] TurnAllHVRelaysOn command received");
                                //     event_sender.send(Event::TurnAllHVRelaysOnEvent).await;
                                // }
                                _ => {} // TODO: DELETE THIS
                            }
                        }
                    } else {
                        parsing_buffer.pop_front();
                    }
                }
                // parsing_buffer.extend(buf[..n].iter().cloned());
                // if let Some(p) = parsing_buffer.first() {
                //     if p != 0xFF {
                //
                //     }
                // }
                // if parsing_buffer.len() < 20 {
                //     continue 'connection;
                // }

                // let id = (buf[0] as u16) << 8 | (buf[1] as u16);
                // let cmd = Command::from_id(id);
            }
            // socket.write_all(b"trying to receive on data mpmc").await;
            // if let Err(e) = socket.flush().await {
            //     error!("Could not flush TCP buffer! {:?}", e);
            // }
            match data_receiver.try_receive() {
                Ok(data) => {
                    // socket.write(b"received on data mpmc").await;
                    let data = data.as_bytes();
                    #[cfg(debug_assertions)]
                    info!("[tcp:mpmc] Sending data: {:?}", data);
                    match socket.write_all(&data).await {
                        Ok(_) => {
                            #[cfg(debug_assertions)]
                            info!("[tcp:socket] Data written successfully");
                        }
                        Err(_e) => {
                            #[cfg(debug_assertions)]
                            error!("[tcp:socket] Failed to write data: {:?}", _e);
                        }
                    }
                    // socket.
                }
                Err(_e) => {
                    // socket.write(b"took an L on data mpmc").await;
                    // #[cfg(debug_assertions)]
                    // info!("[tcp:mpmc] try receive error: {:?}", e);
                }
            }
        }
        // if this is reached, it means that the connection was dropped
        info!("SOMETHING FUCKED UP! D:");
    }
}
