use defmt::info;
use crate::core::finite_state_machine::{FSM, State};
use crate::Event;

impl FSM{
    pub fn entry_accelerating(&mut self) {
        todo!();
    }

    pub fn react_accelerating(&mut self, event: Event) {
        match event {
            Event::DesiredSpeedReachedEvent => {

                todo!();

                self.transit(State::Cruising);
            }
            Event::LaneSwitchingPointReachedEvent => {

                todo!();

                self.transit(State::LaneSwitch);
            }
            Event::BrakingPointReachedEvent => {

                todo!();

                self.transit(State::Braking);
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