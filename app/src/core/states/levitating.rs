use crate::core::finite_state_machine::{State, FSM};
use crate::Event;
use defmt::info;

impl FSM {
    pub async fn entry_levitating(&mut self) {
        todo!();
    }

    pub async fn react_levitating(&mut self, event: Event) {
        match event {
            Event::StartAcceleratingCommand => {
                todo!(); // TODO: send message to propulsion to start

                self.transit(State::Accelerating).await;
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
