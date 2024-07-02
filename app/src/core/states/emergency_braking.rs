use defmt::info;
use embassy_time::Timer;
use crate::core::finite_state_machine::{FSM, State};
use crate::Event;

impl FSM{

    pub fn entry_emergency_braking(&mut self) {

        // todo!();

        self.transit(State::Exit)
    }
}