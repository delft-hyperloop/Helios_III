use defmt::{debug, error, info, trace, warn};
use embassy_time::Instant;
use heapless::Deque;
use crate::core::communication::{HardwareLayer};
use crate::{Command, DataSender, Datatype, Event, EventSender, Info, NETWORK_BUFFER_SIZE, send_data};
use crate::core::communication::data::Datapoint;
use crate::core::communication::uart::UartCommunicationLayer;
use crate::pconfig::{queue_event, send_event, ticks};

pub struct ExternalCommunicationHandler<I: HardwareLayer> {
    pub inner: I,
    pub ds: DataSender,
    pub es: EventSender,
    pub parsing_buffer: Deque::<u8, { NETWORK_BUFFER_SIZE }>,
}

impl<I: HardwareLayer> ExternalCommunicationHandler<I: HardwareLayer> {

    async fn receive_bytes(&mut self, buf: &mut [u8], n: usize, event_sender: EventSender, data_sender: DataSender) {
        buf[0..n].iter().for_each(|x| {
           self.parsing_buffer.push_back(*x).unwrap();
        });
        while let Some(p) = self.parsing_buffer.front() {
            if *p == 0xFF {
                if self.parsing_buffer.len() < 20 {
                    break;
                } else {
                    // we actually have 20 bytes in the buffer, we can create a command from them
                    let mut x = [0u8; 20];
                    for i in &mut x {
                        *i = self.parsing_buffer.pop_front().unwrap();
                    }

                    let cmd = Command::from_bytes(&x);
                    trace!("[tcp] Command received: {:?}", cmd);
                    match cmd {
                        Command::EmergencyBrake(_) => {
                            send_event(event_sender, Event::EmergencyBraking);
                            self.inner.write_blocking(&Datapoint::new(
                                Datatype::Info,
                                Info::EmergencyBrakeReceived.to_idx(),
                                ticks(),
                            )
                                .as_bytes());
                        },
                        Command::launch(_) => {
                            debug!("[tcp] Levitate command received");
                            send_event(event_sender, Event::LeviLaunchingEvent);
                        },
                        Command::land(_) => {
                            debug!("[tcp] StopLevitating command received");
                            send_event(event_sender, Event::LeviLandingEvent);
                        },
                        Command::SetRoute(x) => {
                            debug!("[tcp] Configure command received");
                            send_event(event_sender, Event::SettingRoute(x));
                        },
                        Command::SetSpeeds(x) => {
                            debug!("[tcp] Configure command received");
                            send_event(event_sender, Event::SettingSpeeds(x));
                        },
                        Command::SetOverrides(x) => {
                            send_event(event_sender, Event::SettingOverrides(x));
                        },
                        Command::SetCurrentSpeed(x) => {
                            debug!("[tcp] SetCurrentSpeed command received");
                            send_event(event_sender, Event::SetCurrentSpeedCommand(x));
                        },
                        Command::StartRun(_) => {
                            debug!("[tcp] Start Run command received");
                            send_event(event_sender, Event::RunStarting);
                        },
                        Command::ContinueRun(_) => {
                            debug!("[tcp] Start Run command received");
                            send_event(event_sender, Event::ContinueRunEvent);
                        },
                        Command::Shutdown(_) => {
                            debug!("[tcp] Shutdown command received");
                            send_event(event_sender, Event::ExitEvent);
                        },
                        Command::StartHV(_) => {
                            debug!("[tcp] StartHV command received");
                            send_event(event_sender, Event::TurnOnHVCommand);
                        },
                        Command::StopHV(_) => {
                            debug!("[tcp] StopHV command received");
                            send_event(event_sender, Event::TurnOffHVCommand);
                        },
                        Command::DcOn(_) => {
                            debug!("[tcp] DcOn command received");
                            send_event(event_sender, Event::DcTurnedOn);
                        },
                        Command::DcOff(_) => {
                            debug!("[tcp] DcOff command received");
                            send_event(event_sender, Event::DcTurnedOff);
                        },
                        Command::EmitEvent(e) => {
                            info!("[tcp] EmitEvent command received");
                            send_event(
                                event_sender,
                                Event::from_id((e & 0xFFFF) as u16, Some(69420)),
                            );
                        },
                        Command::CreateDatapoint(x) => {
                            send_data!(data_sender, Datatype::from_id(x as u16), x);
                        },
                        Command::SystemReset(_) => {
                            debug!("[tcp] SystemReset command received");
                            send_event(event_sender, Event::SystemResetCommand);
                        },
                        Command::FinishRunConfig(_) => {
                            debug!("[tcp] FinishRunConfig command received");
                            send_event(event_sender, Event::RunConfigCompleteEvent);
                        },
                        Command::Heartbeat(x) => {
                            trace!("[tcp] Heartbeat command received {} :)", x);
                            self.inner.write_blocking(&Datapoint::new(
                                Datatype::ResponseHeartbeat,
                                x,
                                Instant::now().as_ticks(),
                            )
                                .as_bytes());
                        },
                        Command::FrontendHeartbeat(x) => {
                            send_data!(data_sender, Datatype::FrontendHeartbeating, x);
                        },
                        Command::ArmBrakes(_) => {
                            debug!("[tcp] ArmBrakesCommand command received");
                            queue_event(event_sender, Event::ArmBrakesCommand).await;
                        },
                        _ => {},
                    }
                }
            } else {
                self.parsing_buffer.pop_front();
            }
        }
    }

    async fn handshake() {
        todo!()
    }

    async fn connect(&mut self) {
        todo!()
    }
}