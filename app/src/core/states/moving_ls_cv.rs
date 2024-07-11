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
            Event::LaneSwitchEndedC => match self.route.next_position() {
                Location::ForwardC => {
                    info!("Entering straight track after curved lane-switch!");
                    self.send_levi_cmd(crate::Command::ls0(0)).await;
                    transit!(self, State::EndST);
                },
                Location::StopAndWait => {
                    self.peripherals.propulsion_controller.stop();
                    self.send_levi_cmd(crate::Command::ls0(0)).await;
                    transit!(self, State::Levitating);
                },
                _ => {
                    info!("Invalid configuration!");
                    transit!(self, State::EndST);
                },
            },
            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
