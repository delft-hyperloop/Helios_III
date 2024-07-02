use crate::core::finite_state_machine::{State, FSM};
use crate::Event;
use defmt::info;

impl FSM {
    pub async fn entry_lane_switch(&mut self) {
        todo!();
    }

    pub async fn react_lane_switch(&mut self, event: Event) {
        match event {
            Event::LaneSwitchingCompleteEvent => {
                todo!();

                self.transit(State::Cruising).await;
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
