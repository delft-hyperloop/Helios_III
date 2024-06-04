use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_accelerating(&mut self) {
        todo!();
    }

    pub async fn react_mv_st(&mut self, event: Event) {
        match event {
            Event::DesiredSpeedReachedEvent => {
                transit!(self, State::MovingLSST);
                todo!();
            }
            Event::LaneSwitchingPointReachedEvent => {
                transit!(self, State::MovingLSCV);
                todo!();
            }
            Event::BrakingPointReachedEvent => {
                transit!(self, State::EndST);
                todo!();
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
