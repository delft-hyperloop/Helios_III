use defmt::error;
use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn boot_entry(&mut self) {
        info!("Entering Boot State");
    }

    pub async fn react_boot(&mut self, event: Event) {
        match event {
            Event::BootingCompleteEvent => {
                info!("Booting complete");

                transit!(self, State::EstablishConnection);
            }
            Event::BootingFailedEvent => {
                error!("Booting failed!!");

                transit!(self, State::Exit);
            }
            _ => {
                info!("Booting state ignores {}", event.to_str());
            }
        }
    }
}
