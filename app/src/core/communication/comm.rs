use defmt::debug;
use defmt::error;
use defmt::info;
use defmt::trace;
use heapless::Deque;

use crate::core::communication::data::Datapoint;
use crate::core::communication::CommunicationError;
use crate::core::communication::CommunicationLayer;
use crate::core::communication::HardwareLayer;
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
use crate::NETWORK_BUFFER_SIZE;

pub struct ExternalCommunicationHandler<I: HardwareLayer> {
    pub inner: I,
    pub ds: DataSender,
    pub dr: DataReceiver,
    pub es: EventSender,
    pub parsing_buffer: Deque<u8, { NETWORK_BUFFER_SIZE }>,
}

impl<I: HardwareLayer> CommunicationLayer for ExternalCommunicationHandler<I> {
    async fn init(&mut self) { self.inner.init().await; }

    async fn handshake(&mut self) {
        // Exchange hashes of the configuration files
        // in order to confirm that the exchanged ids are correct
        queue_data(self.ds, Datatype::CommandHash, COMMAND_HASH).await;
        queue_data(self.ds, Datatype::EventsHash, EVENTS_HASH).await;
        queue_data(self.ds, Datatype::DataHash, DATA_HASH).await;
        queue_data(self.ds, Datatype::ConfigHash, CONFIG_HASH).await;

        queue_data(self.ds, Datatype::FrontendHeartbeating, 0).await;
    }

    async fn connect(&mut self) -> Result<(), CommunicationError> {
        match self.inner.connect().await {
            Ok(_) => {
                send_event(self.es, Event::ConnectionEstablishedEvent);
                Ok(())
            },
            Err(e) => {
                error!("[connecting] error: {:?}", e);
                Err(e)
            },
        }
    }

    async fn disconnect(&mut self) { self.inner.close_connection().await; }

    async fn try_send_data(&mut self) -> bool {
        if self.inner.writeable() {
            if let Ok(data) = self.dr.try_receive() {
                let data = data.as_bytes();
                trace!("[tcp:mpmc] Sending data: {:?}", data);
                return self.inner.try_write_bytes(&data).await.is_ok();
            } // the else case is of empty MPMC channel queue,
              // which triggers very often, so we ignore it.
            true
        } else {
            false
        }
    }

    async fn try_receive_data(&mut self) -> bool {
        if self.inner.can_read_now() {
            let mut buf = [0u8; { NETWORK_BUFFER_SIZE }];
            match self.inner.read_bytes(&mut buf).await {
                Ok(n) => {
                    self.receive_bytes(&mut buf, n).await;
                    true
                },
                Err(e) => {
                    error!("[comm] try_receive_data error: {:?}", e);
                    false
                },
            }
        } else {
            self.inner.readable()
        }
    }

    async fn receive_bytes(&mut self, buf: &mut [u8], n: usize) {
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
                            match self
                                .inner
                                .try_write_bytes(
                                    &Datapoint::new(
                                        Datatype::Info,
                                        Info::EmergencyBrakeReceived.to_idx(),
                                        ticks(),
                                    )
                                    .as_bytes(),
                                )
                                .await
                            {
                                Ok(_) => {},
                                Err(e) => error!("[receive bytes] communication error: {:?}", e),
                            }
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
                        Command::EnablePropulsion(_) => {
                            send_event(self.es, Event::EnablePropulsionCommand);
                        },
                        Command::DisablePropulsion(_) => {
                            send_event(self.es, Event::DisablePropulsionCommand);
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
                        Command::EndRun(_) => {
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
                            send_event(self.es, Event::from_id((e & 0xFFFF) as u16, Some(69420)));
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
                            match self
                                .inner
                                .try_write_bytes(
                                    &Datapoint::new(Datatype::ResponseHeartbeat, x, ticks())
                                        .as_bytes(),
                                )
                                .await
                            {
                                Ok(_) => {},
                                Err(e) => error!("[receive bytes] communication error: {:?}", e),
                            }
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
}
