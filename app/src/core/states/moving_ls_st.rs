use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::{Location, RouteUse};
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_cruising(&mut self) {
        todo!();
    }

    pub async fn react_mv_ls_st(&mut self, event: Event) {
        match event {
            Event::BrakingPointReachedEvent => {
                transit!(self, State::EndST);
                todo!();
            }
            Event::LaneSwitchEnded => {
                match self.route.next_position() {
                    Location::LaneSwitchEndTrack => {
                        info!("Entering a lane switch!");
                        self.send_levi_cmd(crate::Command::ls0(0)).await;
                        transit!(self, State::EndST);
                    }
                    Location::StraightBackwards => {
                        info!("Entering straight track backwards");
                        self.send_levi_cmd(crate::Command::ls0(0)).await;
                        transit!(self, State::MovingST);

                    }
                    _ => {
                        info!("Invalid configuration1!");
                        transit!(self, State::Exit);
                    }
                }

                self.send_levi_cmd(crate::Command::ls0(0)).await;
                self.route.next_position();
                transit!(self, State::EndST);
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
