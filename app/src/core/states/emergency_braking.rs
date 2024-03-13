use defmt::info;
use crate::core::finite_state_machine::{Event, FSM, State};

impl FSM{

    pub fn emergency_braking_entry(&mut self) {

        todo!();

        self.transit(State::Exit)
    }
}