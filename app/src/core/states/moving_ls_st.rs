use crate::core::finite_state_machine::{State, Fsm};
use crate::{transit, Event};
use defmt::info;

impl Fsm {
    pub fn entry_cruising(&mut self) {
        todo!();
    }

    pub async fn react_mv_ls_st(&mut self, event: Event) {
        match event {
            Event::BrakingPointReachedEvent => {
                todo!();

                transit!(self, State::EndST);
            }
            Event::LaneSwitchingPointReachedEvent => {
                todo!();

                transit!(self, State::MovingLSCV);
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
