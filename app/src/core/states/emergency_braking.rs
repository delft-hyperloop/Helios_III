use crate::core::finite_state_machine::{State, FSM};
use crate::Event;
use defmt::info;
use embassy_time::Timer;

impl FSM {
    pub async fn entry_emergency_braking(&mut self) {
        // todo!();

        self.transit(State::Exit)
    }
}
