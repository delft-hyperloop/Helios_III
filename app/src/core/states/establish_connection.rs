use defmt::info;
use crate::core::finite_state_machine::{FSM, State};
use crate::Event;

impl FSM{
    pub fn entry_establish_connection(&mut self) {

        info!("Entering Establish Connection State");

        // TODO -> Start connection with the ground station, with levi and propulsion

    }

    pub fn react_establish_connection(&mut self, event: Event) {
        match event {
            Event::ConnectionEstablishedEvent => {

                self.transit(State::RunConfig);
            }
            Event::ConnectionEstablishmentFailedEvent => {

                self.transit(State::Exit);
            }

            _ => {
                info!("The current state ignores {}", event.to_str());

            }
        }
    }


}