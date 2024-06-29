use defmt::error;
use defmt::info;
use defmt::warn;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::Location;
use crate::core::fsm_status::RouteUse;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_accelerating(&mut self) {
        self.peripherals
            .propulsion_controller
            .set_speed(self.route.current_speed());
        //We have to put a stip on the track that would define a braking point here
    }

    pub async fn react_mv_st(&mut self, event: Event) {
        match event {
            Event::LaneSwitchForward => {
                match self.route.next_position() {
                    Location::LaneSwitchStraight => {
                        #[cfg(debug_assertions)]
                        info!("Entering a lane switch!");
                        // self.peripherals.propulsion_controller.turn_off();
                        self.send_levi_cmd(crate::Command::ls1(0)).await;
                        transit!(self, State::MovingLSST);
                    }
                    Location::LaneSwitchCurved => {
                        #[cfg(debug_assertions)]
                        info!("Entering a lane switch!");
                        self.send_levi_cmd(crate::Command::ls2(0)).await;
                        transit!(self, State::MovingLSCV);
                    }
                    Location::StopAndWait => {
                        #[cfg(debug_assertions)]
                        info!("Stopping and waiting");
                        self.peripherals.propulsion_controller.stop();
                        self.send_levi_cmd(crate::Command::ls0(0)).await;
                        self.send_levi_cmd(crate::Command::LeviPropulsionStop(0))
                            .await;
                        transit!(self, State::Levitating);
                    }
                    Location::BrakeHere => {
                        warn!("Stopping here.");
                        transit!(self, State::Exit);
                    }
                    _ => {
                        error!("Invalid configuration!");

                        transit!(self, State::EmergencyBraking);
                    }
                }
            }
            Event::DirectionChangedEvent => match self.route.current_position() {
                Location::BrakeHere => {
                    info!("Stopping here.");
                    transit!(self, State::Exit);
                }
                _ => {
                    self.peripherals
                        .propulsion_controller
                        .set_speed(self.route.current_speed());
                }
            },
            Event::BrakingPointReachedA => {
                // TODO: ask if we need to prop brake or emergency brake
                transit!(self, State::EndST);
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
