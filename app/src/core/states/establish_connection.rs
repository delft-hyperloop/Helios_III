use defmt::info;
use crate::core::finite_state_machine::{Event, FSM, State};

impl FSM{
    pub fn entry_establish_connection(&mut self) {

        todo!();

    }

    pub fn react_establish_connection(&mut self, event: Event) {
        match event {
            Event::ConnectionEstablishedEvent => {

                todo!();

                self.transit(State::RunConfig);
            }
            Event::ConnectionEstablishmentFailedEvent => {

                todo!();

                self.transit(State::Exit);
            }

            _ => {
                info!("The current state ignores");
                event.fmt();
            }
        }
    }


}