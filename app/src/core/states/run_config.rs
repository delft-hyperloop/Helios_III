use defmt::info;
use crate::core::finite_state_machine::{Event, FSM, State};

impl FSM{
    pub fn entry_run_config(&mut self) {

    }
    pub fn react_run_config(&mut self, event: Event) {
        match event {
            Event::RunConfigCompleteEvent => {

                todo!();

                self.transit(State::Idle);
            }
            Event::RunConfigFailedEvent => {

                todo!();

                self.transit(State::Exit);
            }
            _ => {
                info!("The current state ignores");
                event.fmt();
            }
        }
    }
}