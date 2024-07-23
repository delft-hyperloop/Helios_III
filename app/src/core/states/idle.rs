use core::sync::atomic::Ordering;

use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::BRAKES_EXTENDED;
use crate::core::fsm_status::POD_IS_MOVING;
use crate::transit;
use crate::Event;
use crate::Info;

impl Fsm {
    pub fn entry_idle(&mut self) {
        info!("Entering Idle State");
        POD_IS_MOVING.store(false, Ordering::Relaxed);
        // self.peripherals.led_controller.hv_led.set_high();
    }

    pub async fn react_idle(&mut self, event: Event) {
        match event {
            Event::LeviLaunchingEvent => {
                if self.status.overrides.fake_hv() {
                    transit!(self, State::Levitating);
                }
            },
            Event::TurnOnHVCommand => {
                // check for preconditions
                if (BRAKES_EXTENDED.load(Ordering::Acquire) || !self.status.brakes_armed)
                    && !self.status.overrides.hv_without_brakes_armed()
                {
                    self.log(Info::BrakesNotArmed).await;
                    return;
                }

                if !self.status.levi_connected && !self.status.overrides.hv_without_levi() {
                    self.log(Info::LevitationNotStarted).await;
                    return;
                }

                self.pod_unsafe().await;

                #[cfg(debug_assertions)]
                info!("Starting HV System");
                // self.peripherals.hv_peripherals.power_on_hv_procedure().await;

                self.peripherals.led_controller.hv_relay_led(true).await;
                transit!(self, State::Precharging);
            },

            Event::ArmBrakesCommand => {
                #[cfg(debug_assertions)]
                info!("[fsm] arming brakes");
                self.peripherals.braking_controller.arm_breaks().await;
                self.status.brakes_armed = true;
            },

            Event::ReConfigureCommand => {
                transit!(self, State::RunConfig);
            },

            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
