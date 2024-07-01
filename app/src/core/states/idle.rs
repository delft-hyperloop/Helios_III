use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_idle(&mut self) {
        info!("Entering Idle State")
    }

    pub async fn react_idle(&mut self, event: Event) {
        match event {
            Event::TurnOnHVCommand => {
                self.pod_unsafe().await;
                //todo check for preconditions
                #[cfg(debug_assertions)] // todo actually turn on hv
                info!("Starting HV System");
                // self.peripherals
                //     .braking_controller
                //     .start_run_brake_precondition();
                self.peripherals
                    .hv_peripherals
                    .power_on_hv_procedure()
                    .await;
                transit!(self, State::HVSystemChecking);
            }
            Event::ArmBrakesCommand => {
                #[cfg(debug_assertions)]
                info!("[fsm] arming brakes");
                self.peripherals.braking_controller.arm_breaks();
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
