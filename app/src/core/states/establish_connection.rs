use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_establish_connection(&mut self) {
        info!("Entering Establish Connection State");
        // self.peripherals.braking_controller.brake();
        // TODO -> Start connection with the ground station, with levi and propulsion
    }

    pub async fn react_establish_connection(&mut self, event: Event) {
        match event {
            Event::ConnectionEstablishedEvent => {
                transit!(self, State::RunConfig);
            }
            Event::ConnectionEstablishmentFailedEvent => {
                transit!(self, State::Exit);
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
