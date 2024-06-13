use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::Location;
use crate::core::fsm_status::RouteUse;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_ls_cv(&mut self) {
        todo!();
    }

    pub async fn react_mv_ls_cv(&mut self, event: Event) {
        match event {
            Event::LaneSwitchEnded => match self.route.next_position() {
                Location::LaneSwitchEndTrack => {
                    info!("Entering straight track after curved lane-switch!");
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
                    transit!(self, State::EndST);
                }
            },
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
