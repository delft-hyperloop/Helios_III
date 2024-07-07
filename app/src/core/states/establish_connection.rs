use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Datatype;
use crate::Event;

impl Fsm {
    pub fn entry_establish_connection(&mut self) {
        info!("Entering Establish Connection State");
    }

    pub async fn react_establish_connection(&mut self, event: Event) {
        match event {
            Event::ConnectionEstablishedEvent => {
                self.send_data(Datatype::BrakingRearmDebug, 1).await;
                transit!(self, State::RunConfig);
            },
            Event::ConnectionEstablishFailed => {
                transit!(self, State::Exit);
            },
            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
