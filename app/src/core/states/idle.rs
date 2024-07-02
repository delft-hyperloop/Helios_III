use crate::core::finite_state_machine::{State, Fsm};
use crate::{transit, Event};
use defmt::info;

impl Fsm {
    pub fn entry_idle(&mut self) {
        info!("Entering Idle State")
    }

    pub async fn react_idle(&mut self, event: Event) {
        match event {
            // Event::LVLevitationReadyEvent => {
            //
            //     todo!();
            //
            // }
            // Event::LVPowertrainReadyEvent => {
            //
            //     todo!();
            //
            // }
            // Event::LVPropulsionReadyEvent => {
            //
            //     todo!();
            //
            // }
            Event::TurnOnHVCommand => {
                #[cfg(debug_assertions)]
                info!("Starting HV System");
                transit!(self, State::HVSystemChecking);
            }
            Event::ArmBrakesCommand => {
                todo!();
            }
            /// This is commented out because it was refactored to be handled by the default react ///
            // /// Here this events can be triggered for the first time, but they'll transit to Exit State instead of emergency breaking as HV is off
            // Event::LevitationErrorEvent|Event::PropulsionErrorEvent|Event::PowertrainErrorEvent|Event::ConnectionLossEvent=> {
            //
            //     todo!();
            //
            //     self.transit(State::Exit)
            // }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
