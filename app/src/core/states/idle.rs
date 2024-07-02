use defmt::info;
use crate::core::finite_state_machine::{FSM, State};
use crate::Event;

impl FSM {

    pub fn entry_idle(&mut self) {
        info!("Entering Idle State")
    }

    pub fn react_idle(&mut self, event: Event) {
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

                todo!();

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