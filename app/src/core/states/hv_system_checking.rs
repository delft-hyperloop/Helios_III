use crate::core::finite_state_machine::*;
use crate::{Datatype, Event};
use defmt::{info, warn};
use embassy_stm32::gpio::Level::High;
use embassy_stm32::gpio::Output;
use crate::core::communication::Datapoint;

impl FSM {
    pub async fn entry_hv_system_checking(&mut self) {
        #[cfg(debug_assertions)]
        info!("Entering HV System Checking");
        self.status.reset();
        self.peripherals.hv_peripherals.enable_pin.set_high();
        warn!("HV SYSTEM IS ON!");
        warn!("HV SYSTEM IS ON!");
        warn!("HV SYSTEM IS ON!");
    }

    pub async fn react_hv_system_checking(&mut self, event: Event) {
        match event {
            Event::TurnOffHVCommand => {
                self.transit(State::Exit).await;
            }
            Event::HVLevitationReadyEvent => {
                self.status.check_levitation();
            }
            Event::HVPowertrainReadyEvent => {
                self.status.check_powertrain();
            }
            Event::HVPropulsionReadyEvent => {
                self.status.check_propulsion();
            }
            Event::StartLevitatingCommand => {
                if (self.status.check_all()) {
                    self.transit(State::Levitating).await;
                }
                todo!();

                self.transit(State::Levitating).await
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
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
