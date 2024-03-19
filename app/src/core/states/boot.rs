use defmt::info;
use crate::core::finite_state_machine::{Event, FSM, State};

impl FSM {
    pub fn boot_entry(&mut self) {

        info!("I like potatoes")


    }

    pub fn react_boot(&mut self, event: Event) {
        match event {
            Event::BootingCompleteEvent => {
                info!("Booting complete");
                todo!();

                self.transit(State::EstablishConnection);
            }
            Event::BootingFailedEvent => {


                todo!();

                self.transit(State::Exit)
            }
            _ => {
                info!("The current state ignores");
                event.fmt();
            }
        }
    }
}
