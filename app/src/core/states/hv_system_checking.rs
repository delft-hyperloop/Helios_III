use defmt::info;
use crate::core::finite_state_machine::*;

impl FSM{
    pub fn entry_hv_system_checking(&mut self) {
        todo!();
    }

    pub fn react_hv_system_checking(&mut self, event: Event) {
        match event {
            Event::HVLevitationReadyEvent => {

                todo!();


            }
            Event::HVPowertrainReadyEvent => {

                todo!();


            }
            Event::HVPropulsionReadyEvent => {

                todo!();


            }
            Event::StartLevitatingCommand => {

                todo!();

                self.transit(State::Levitating)
            }

            /// Error Events that are core from all states that HV is on
            Event::LevitationErrorEvent|Event::PropulsionErrorEvent|Event::PowertrainErrorEvent |Event::ConnectionLossEvent|Event::EmergencyBrakeCommand=> {

                todo!();

                self.transit(State::EmergencyBraking)
            }
            _ => {
                info!("The current state ignores");
                event.fmt();
            }
        }
    }
}