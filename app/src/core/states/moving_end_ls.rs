use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::Location;
use crate::core::fsm_status::RouteUse;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_end_ls(&mut self) { self.peripherals.propulsion_controller.stop(); }

    pub async fn react_end_ls(&mut self, event: Event) {
        match event {
            Event::RunFinishedEvent => {
                #[cfg(debug_assertions)]
                info!("Run finished");
                transit!(self, State::Exit);
            },
            Event::LaneSwitchBackwardsB => {
                #[allow(clippy::single_match)]
                match self.route.next_position() {
                    Location::StraightBackwards => {
                        self.send_levi_cmd(crate::Command::ls1(0)).await;
                        // self.peripherals.propulsion_controller.turn_off();
                        transit!(self, State::MovingLSST);
                    },
                    _ => {},
                }
            },
            Event::LaneSwitchBackwardsC => {
                self.send_levi_cmd(crate::Command::ls2(0)).await;
                // self.peripherals.propulsion_controller.turn_off();
                transit!(self, State::MovingLSCV);
            },
            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
