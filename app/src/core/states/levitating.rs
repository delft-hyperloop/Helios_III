use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_levitating(&mut self) {
        todo!();
    }

    pub async fn react_levitating(&mut self, event: Event) {
        match event {
            Event::StartAcceleratingCommand => {
                transit!(self, State::MovingST);
            }
            Event::HVPropulsionReadyEvent => {
                todo!();
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
