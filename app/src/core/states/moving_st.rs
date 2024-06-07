use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::{Location, RouteUse};
use crate::transit;
use crate::Event;
use crate::Datatype;

impl Fsm {
    pub fn entry_accelerating(&mut self) {
        todo!();
    }

    pub async fn react_mv_st(&mut self, event: Event) {
        match event {
            Event::LaneSwitchingPointReachedEvent => {
                match self.route.next_position() {
                    Location::LaneSwitchStraight => {
                        #[cfg(debug_assertions)]
                        info!("Entering a lane switch!");

                        self.send_levi_cmd(crate::Command::ls1(0)).await;
                        transit!(self, State::MovingLSST);
                    }
                    Location::LaneSwitchCurved => {
                        #[cfg(debug_assertions)]
                        info!("Entering a lane switch!");

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
            Event::BrakingPointReachedEvent => {
                transit!(self, State::Exit);
                todo!();
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
