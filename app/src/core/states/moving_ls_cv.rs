use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_ls_cv(&mut self) {
        todo!();
    }

    pub async fn react_mv_ls_cv(&mut self, event: Event) {
        match event {
            Event::LaneSwitchingCompleteEvent => {
                transit!(self, State::MovingLSST);
                todo!();
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
