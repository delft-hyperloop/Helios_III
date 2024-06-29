use defmt::info;
use defmt::warn;

use crate::core::finite_state_machine::*;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_hv_on(&mut self) {
        #[cfg(debug_assertions)]
        info!("Entering HV System Checking");
        // self.peripherals.hv_peripherals.enable_pin.set_high();
        warn!("HV SYSTEM IS ON!");
        warn!("HV SYSTEM IS ON!");
    }

    pub async fn react_hv_on(&mut self, event: Event) {
        match event {
            Event::TurnOffHVCommand => {
                self.peripherals.hv_peripherals.power_hv_off();
                #[cfg(debug_assertions)]
                info!("HV Relays turned off");
                self.pod_safe().await;
                transit!(self, State::Idle);
            }
            Event::StartLevitatingCommand => {
                #[cfg(debug_assertions)]
                info!("Starting Levitation");

                transit!(self, State::Levitating);
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
