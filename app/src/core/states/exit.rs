use crate::core::finite_state_machine::{State, FSM};
use crate::Event;
use defmt::info;

impl FSM {
    pub async fn entry_exit(&mut self) {
        todo!();
    }

    pub async fn react_exit(&mut self, event: Event) {
        match event {
            Event::ArmBrakesCommand => {
                todo!();
            }
            Event::SystemResetCommand => {
                todo!();

                self.transit(State::RunConfig);
            }

            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
