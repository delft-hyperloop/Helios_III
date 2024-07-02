use crate::core::finite_state_machine::{State, FSM};
use crate::Event;
use defmt::info;

impl FSM {
    pub fn entry_levitating(&mut self) {
        todo!();
    }

    pub fn react_levitating(&mut self, event: Event) {
        match event {
            Event::StartAcceleratingCommand => {
                todo!();

                self.transit(State::Accelerating);
            }
            Event::HVPropulsionReadyEvent => {
                todo!();
            }
            /// This is commented out because it was refactored to be handled by the default react ///
            // Event::LevitationErrorEvent|Event::PropulsionErrorEvent|Event::PowertrainErrorEvent |Event::ConnectionLossEvent|Event::EmergencyBrakeCommand=> {
            //
            //     todo!();
            //
            //     self.transit(State::EmergencyBraking)
            // }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
