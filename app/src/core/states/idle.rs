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
            Event::TurnOnHVCommand => { //todo check for preconditions
                #[cfg(debug_assertions)] // todo actually turn on hv
                info!("Starting HV System");
                info!("Starting HV System");
                self.peripherals.braking_controller.start_run_brake_precondition();
                self.peripherals.hv_peripherals.power_on_hv_procedure().await;
                transit!(self, State::HVSystemChecking);
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
