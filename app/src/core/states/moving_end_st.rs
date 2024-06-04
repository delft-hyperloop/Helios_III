use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_end_st(&mut self) {
        todo!();
    }

    pub async fn react_end_st(&mut self, event: Event) {
        match event {
            Event::DirectionChangedEvent => {
                todo!();
            }
            Event::RunFinishedEvent => {
                #[cfg(debug_assertions)]
                info!("Run finished");

                transit!(self, State::Exit);
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
