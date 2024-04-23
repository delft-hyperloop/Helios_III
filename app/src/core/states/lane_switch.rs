use defmt::info;
use crate::core::finite_state_machine::{FSM, State};
use crate::Event;

impl FSM{

    pub fn entry_lane_switch(&mut self) {
        todo!();
    }

    pub fn react_lane_switch(&mut self, event: Event) {
        match event {
            Event::LaneSwitchingCompleteEvent => {

                todo!();

                self.transit(State::Cruising);
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