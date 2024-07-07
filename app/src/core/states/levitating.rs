use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Command;
use crate::Event;

impl Fsm {
    pub fn entry_levitating(&mut self) {

    }

    pub async fn react_levitating(&mut self, event: Event) {
        match event {
            Event::RunStarting => {
                self.send_levi_cmd(Command::LeviPropulsionStart(0)).await;
                self.enter_moving().await;
            },

            Event::LeviLandingEvent => {
                transit!(self, State::Idle);
            },

            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
