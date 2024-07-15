use defmt::{debug, error, info, trace, warn};
use embassy_time::{Instant, Timer};
use heapless::Deque;
use crate::core::communication::{CommunicationLayer, HardwareLayer};
use crate::{Command, COMMAND_HASH, CONFIG_HASH, DATA_HASH, DataSender, Datatype, Event, EVENTS_HASH, EventSender, Info, NETWORK_BUFFER_SIZE, send_data};
use crate::core::communication::data::Datapoint;
use crate::core::communication::uart::UartCommunicationLayer;
use crate::pconfig::{queue_data, queue_event, send_event, ticks};

pub struct ExternalCommunicationHandler<I: HardwareLayer> {
    pub inner: I,
    pub ds: DataSender,
    pub es: EventSender,
    pub parsing_buffer: Deque::<u8, { NETWORK_BUFFER_SIZE }>,
}

impl<I: HardwareLayer> CommunicationLayer for ExternalCommunicationHandler<I> {

    fn receive_bytes(&mut self, buf: &mut [u8], n: usize) {
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
                            send_event(self.es, Event::EmergencyBraking);
                            self.inner.write_blocking(&Datapoint::new(
                                Datatype::Info,
                                Info::EmergencyBrakeReceived.to_idx(),
                                ticks(),
                            )
                                .as_bytes());
                        },
                        Command::launch(_) => {
                            debug!("[tcp] Levitate command received");
                            send_event(self.es, Event::LeviLaunchingEvent);
                        },
                        Command::land(_) => {
                            debug!("[tcp] StopLevitating command received");
                            send_event(self.es, Event::LeviLandingEvent);
                        },
                        Command::SetRoute(x) => {
                            debug!("[tcp] Configure command received");
                            send_event(self.es, Event::SettingRoute(x));
                        },
                        Command::SetSpeeds(x) => {
                            debug!("[tcp] Configure command received");
                            send_event(self.es, Event::SettingSpeeds(x));
                        },
                        Command::SetOverrides(x) => {
                            send_event(self.es, Event::SettingOverrides(x));
                        },
                        Command::SetCurrentSpeed(x) => {
                            debug!("[tcp] SetCurrentSpeed command received");
                            send_event(self.es, Event::SetCurrentSpeedCommand(x));
                        },
                        Command::StartRun(_) => {
                            debug!("[tcp] Start Run command received");
                            send_event(self.es, Event::RunStarting);
                        },
                        Command::ContinueRun(_) => {
                            debug!("[tcp] Start Run command received");
                            send_event(self.es, Event::ContinueRunEvent);
                        },
                        Command::Shutdown(_) => {
                            debug!("[tcp] Shutdown command received");
                            send_event(self.es, Event::ExitEvent);
                        },
                        Command::StartHV(_) => {
                            debug!("[tcp] StartHV command received");
                            send_event(self.es, Event::TurnOnHVCommand);
                        },
                        Command::StopHV(_) => {
                            debug!("[tcp] StopHV command received");
                            send_event(self.es, Event::TurnOffHVCommand);
                        },
                        Command::DcOn(_) => {
                            debug!("[tcp] DcOn command received");
                            send_event(self.es, Event::DcTurnedOn);
                        },
                        Command::DcOff(_) => {
                            debug!("[tcp] DcOff command received");
                            send_event(self.es, Event::DcTurnedOff);
                        },
                        Command::EmitEvent(e) => {
                            info!("[tcp] EmitEvent command received");
                            send_event(
                                self.es,
                                Event::from_id((e & 0xFFFF) as u16, Some(69420)),
                            );
                        },
                        Command::CreateDatapoint(x) => {
                            send_data!(self.ds, Datatype::from_id(x as u16), x);
                        },
                        Command::SystemReset(_) => {
                            debug!("[tcp] SystemReset command received");
                            send_event(self.es, Event::SystemResetCommand);
                        },
                        Command::FinishRunConfig(_) => {
                            debug!("[tcp] FinishRunConfig command received");
                            send_event(self.es, Event::RunConfigCompleteEvent);
                        },
                        Command::Heartbeat(x) => {
                            trace!("[tcp] Heartbeat command received {} :)", x);
                            self.inner.write_blocking(&Datapoint::new(
                                Datatype::ResponseHeartbeat,
                                x,
                                ticks(),
                            )
                                .as_bytes());
                        },
                        Command::FrontendHeartbeat(x) => {
                            send_data!(self.ds, Datatype::FrontendHeartbeating, x);
                        },
                        Command::ArmBrakes(_) => {
                            debug!("[tcp] ArmBrakesCommand command received");
                            queue_event(self.es, Event::ArmBrakesCommand).await;
                        },
                        _ => {},
                    }
                }
            } else {
                self.parsing_buffer.pop_front();
            }
        }
    }

    async fn connect(&mut self) {
        self.inner.connect().await;
        send_event(self.es, Event::ConnectionEstablishedEvent);
    }

    async fn handshake(&mut self) {
        // Exchange hashes of the configuration files
        // in order to confirm that the exchanged ids are correct
        queue_data(self.ds, Datatype::CommandHash, COMMAND_HASH).await;
        queue_data(self.ds, Datatype::EventsHash, EVENTS_HASH).await;
        queue_data(self.ds, Datatype::DataHash, DATA_HASH).await;
        queue_data(self.ds, Datatype::ConfigHash, CONFIG_HASH).await;

        queue_data(self.ds, Datatype::FrontendHeartbeating, 0).await;
    }

    fn send_data(&mut self) {
        if self.inner.can_write() {
            if let Ok(data) = self.ds.try_receive() {
                let data = data.as_bytes();
                trace!("[tcp:mpmc] Sending data: {:?}", data);
                self.inner.write_blocking(data);
            } // the else case is of empty MPMC channel queue,
              // which triggers very often, so we ignore it.
        }
    }
}