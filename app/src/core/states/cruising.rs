use crate::core::finite_state_machine::{State, FSM};
use crate::Event;
use defmt::info;

impl FSM {
    pub async fn entry_cruising(&mut self) {
        todo!();
    }

    pub async fn react_cruising(&mut self, event: Event) {
        match event {
            Event::BrakingPointReachedEvent => {
                todo!();

                self.transit(State::Braking);
            }
            Event::LaneSwitchingPointReachedEvent => {
                todo!();

                self.transit(State::LaneSwitch);
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
