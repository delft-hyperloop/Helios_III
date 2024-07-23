use core::sync::atomic::Ordering;

use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::BRAKE;
use crate::core::fsm_status::POD_IS_MOVING;
use crate::transit;
use crate::Datatype;
use crate::Event;

impl Fsm {
    pub fn entry_exit(&mut self) {
        unsafe {
            BRAKE = true;
        }
        self.peripherals.hv_peripherals.power_hv_off();
        self.peripherals.propulsion_controller.disable();
        self.status.brakes_armed = false;
        self.status.route_set = false;
        self.status.speeds_set = false;
        self.status.levitating = false;
        info!("In exit state...");
        POD_IS_MOVING.store(false, Ordering::Relaxed);
    }

    pub async fn react_exit(&mut self, event: Event) {
        match event {
            Event::ArmBrakesCommand => {
                #[cfg(debug_assertions)]
                info!("Arming brakes");
                self.peripherals.braking_controller.arm_breaks().await;
            },
            Event::SystemResetCommand => {
                self.send_data(Datatype::BrakingRearmDebug, 1).await;
                transit!(self, State::RunConfig);
            },

            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
