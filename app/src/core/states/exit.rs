use crate::core::controllers::breaking_controller::BRAKE;
use crate::core::finite_state_machine::{State, Fsm};
use crate::{transit, Event};
use defmt::info;

impl Fsm {
    pub fn entry_exit(&mut self) {
        unsafe {
            BRAKE = true;
        }
        info!("In exit state...");
    }

    pub async fn react_exit(&mut self, event: Event) {
        match event {
            Event::ArmBrakesCommand => {
                todo!();
            }
            Event::SystemResetCommand => {
                todo!();

                transit!(self, State::RunConfig);
            }

            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
