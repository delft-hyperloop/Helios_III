use crate::core::communication::Datapoint;
use crate::core::finite_state_machine::*;
use crate::{transit, Datatype, Event};
use defmt::{info, warn};
use embassy_stm32::gpio::Level::High;
use embassy_stm32::gpio::Output;

impl Fsm {
    pub fn entry_hv_system_checking(&mut self) {
        #[cfg(debug_assertions)]
        info!("Entering HV System Checking");
        // self.peripherals.hv_peripherals.enable_pin.set_high();
        warn!("HV SYSTEM IS ON!");
        warn!("HV SYSTEM IS ON!");
        warn!("HV SYSTEM IS ON!");
    }

    pub async fn react_hv_system_checking(&mut self, event: Event) {
        match event {
            Event::TurnOffHVCommand => {
                self.peripherals.hv_peripherals.power_hv_off();
                #[cfg(debug_assertions)]
                info!("HV Relays turned off");
                // transit!(self, State::Exit);
            }
            Event::StartLevitatingCommand => {
                todo!();

                transit!(self, State::Levitating);
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
