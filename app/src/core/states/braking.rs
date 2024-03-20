use defmt::info;
use crate::core::finite_state_machine::{Event, FSM, State};


impl FSM{

    pub fn entry_braking(&mut self) {

        todo!();

    }

    pub fn react_braking(&mut self, event: Event) {
        match event {
            Event::DirectionChangedEvent => {

                todo!();

            }
            Event::RunFinishedEvent => {

                todo!();

                self.transit(State::Exit);
            }
            /// This is commented out because it was refactored to be handled by the default react ///
            // Event::LevitationErrorEvent|Event::PropulsionErrorEvent|Event::PowertrainErrorEvent |Event::ConnectionLossEvent|Event::EmergencyBrakeCommand=> {
            //
            //     todo!();
            //
            //     self.transit(State::EmergencyBraking)
            // }
            _ => {
                info!("The current state ignores");
                event.fmt();
            }
        }
    }
}