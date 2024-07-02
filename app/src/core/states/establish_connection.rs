use crate::core::communication::Datapoint;
use crate::core::finite_state_machine::{State, Fsm};
use crate::{transit, Datatype, Event};
use defmt::info;

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
