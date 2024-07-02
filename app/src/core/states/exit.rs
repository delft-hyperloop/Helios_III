use defmt::info;
use crate::core::finite_state_machine::{FSM, State};
use crate::Event;

impl FSM {


    pub fn entry_exit(&mut self) {

        todo!();

    }

    pub fn react_exit(&mut self, event: Event) {
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