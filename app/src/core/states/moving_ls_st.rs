use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::Location;
use crate::core::fsm_status::RouteUse;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_ls_st(&mut self) {
        self.peripherals.propulsion_controller.set_speed(self.route.current_speed());
    }

    pub async fn react_mv_ls_st(&mut self, event: Event) {
        self.send_levi_cmd(crate::Command::ls0(0)).await;

        match event {
            Event::LaneSwitchEndedB => match self.route.next_position() {
                Location::ForwardB => {
                    info!("Exiting a straight run LS!");
                    transit!(self, State::EndST);
                },

                Location::StopAndWait => {
                    self.peripherals.propulsion_controller.stop();
                    transit!(self, State::Levitating);
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
