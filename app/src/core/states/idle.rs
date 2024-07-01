use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;
use crate::Info;

impl Fsm {
    pub fn entry_idle(&mut self) {
        info!("Entering Idle State")
    }

    pub async fn react_idle(&mut self, event: Event) {
        match event {
            Event::DisablePropulsionCommand => {
                self.peripherals.propulsion_controller.disable();
                self.log(Info::DisablePropulsionGpio).await;
                self.send_data(crate::Datatype::PropGPIODebug, 0).await;
            }
            Event::EnablePropulsionCommand => {
                self.peripherals.propulsion_controller.enable();
                self.log(Info::EnablePropulsionGpio).await;
                self.send_data(crate::Datatype::PropGPIODebug, 1).await;
            }
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
                self.peripherals.led_controller.hv_relay_led(true).await;
                transit!(self, State::HVOn);
            }
            Event::ArmBrakesCommand => {
                #[cfg(debug_assertions)]
                info!("[fsm] arming brakes");
                self.peripherals.braking_controller.arm_breaks().await;
            }
            Event::ReConfigureCommand => {
                transit!(self, State::RunConfig);
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
