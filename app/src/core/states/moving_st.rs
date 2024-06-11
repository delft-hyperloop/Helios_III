use defmt::info;

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
            .set_speed(self.route.current_speed() as u64);
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
                        // self.peripherals.propulsion_controller.turn_off();
                        self.send_levi_cmd(crate::Command::ls2(0)).await;
                        transit!(self, State::MovingLSCV);
                    }
                    Location::StopHere => {
                        defmt::warn!("Stopping here.");
                        transit!(self, State::Exit);
                    }
                    _ => {
                        defmt::error!("Invalid configuration1!");

                        transit!(self, State::EmergencyBraking);
                    }
                }
            }
            Event::DirectionChangedEvent => match self.route.current_position() {
                Location::StopHere => {
                    info!("Stopping here.");
                    transit!(self, State::Exit);
                }
                _ => {
                    self.peripherals
                        .propulsion_controller
                        .set_speed(self.route.current_speed() as u64);
                }
            },
            Event::BrakingPointReachedEvent => {
                transit!(self, State::EndST);
                todo!();
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
