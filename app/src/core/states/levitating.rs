use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::{Location, RouteUse};
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_levitating(&mut self) {
        // self.peripherals.propulsion_controller.set_speed(0);
        // self.peripherals.propulsion_controller.enable();
    }

    pub async fn react_levitating(&mut self, event: Event) {
        match event {
            Event::StartAcceleratingCommand => {
                match self.route.next_position() {
                    Location::StraightStart => {
                        transit!(self, State::MovingST);
                    }
                    Location::StraightEndTrack => {
                        transit!(self, State::EndST);
                    }
                    Location::LaneSwitchEndTrack | Location::StraightBackwards => {
                        transit!(self, State::EndLS);
                    }
                    Location::StopAndWait => {
                        self.peripherals.propulsion_controller.set_speed(0);
                        self.peripherals.propulsion_controller.disable();
                    }
                    _ => {
                        transit!(self, State::Exit);
                    }
                }
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
