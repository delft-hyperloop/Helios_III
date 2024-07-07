use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::Location;
use crate::core::fsm_status::RouteUse;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_cruising(&mut self) {
        todo!();
    }

    pub async fn react_mv_ls_st(&mut self, event: Event) {
        match event {
            Event::BrakingPointReachedB => {
                transit!(self, State::EndST);
                todo!();
            },
            Event::LaneSwitchEndedB => {
                match self.route.next_position() {
                    Location::LaneSwitchEndTrack => {
                        info!("Entering a lane switch!");
                        self.send_levi_cmd(crate::Command::ls0(0)).await;
                        transit!(self, State::EndST);
                    },

                    _ => {
                        info!("Invalid configuration1!");
                        transit!(self, State::Exit);
                    },
                }

                self.send_levi_cmd(crate::Command::ls0(0)).await;
                self.route.next_position();
                transit!(self, State::EndST);
            },
            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
