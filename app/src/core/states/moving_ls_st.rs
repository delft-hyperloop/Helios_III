use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_cruising(&mut self) {
        todo!();
    }

    pub async fn react_mv_ls_st(&mut self, event: Event) {
        match event {
            Event::BrakingPointReachedEvent => {
                transit!(self, State::EndST);
                todo!();
            }
            Event::LaneSwitchingPointReachedEvent => {
                transit!(self, State::MovingLSCV);
                todo!();
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
