use defmt::info;
use crate::core::finite_state_machine::*;

impl FSM{
    pub fn entry_hv_system_checking(&mut self) {
        todo!();
    }

    pub fn react_hv_system_checking(&mut self, event: Event) {
        match event {
            Event::HVLevitationReadyEvent => {

                self.peripherals.hvcontroller.check_levitation();


            }
            Event::HVPowertrainReadyEvent => {

                self.peripherals.hvcontroller.check_powertrain();


            }
            Event::HVPropulsionReadyEvent => {

            self.peripherals.hvcontroller.check_propulsion();


            }
            Event::StartLevitatingCommand => {

                if (self.peripherals.hvcontroller.check_all()) {

                    
                    self.transit(State::Levitating);
                }
                todo!();

                self.transit(State::Levitating)
            }
            /// This is commented out because it was refactored to be handled by the default react ///
            // /// Error Events that are core from all states that HV is on
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