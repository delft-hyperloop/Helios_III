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
            Event::LaneSwitchEndedB => match self.route.next_position() {
                Location::LaneSwitchEndTrack => {
                    info!("Exiting a straight run LS!");
                    self.send_levi_cmd(crate::Command::ls0(0)).await;
                    transit!(self, State::EndST);
                },

                _ => {
                    info!("Invalid configuration!");
                    transit!(self, State::Exit);
                },
            },
            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
