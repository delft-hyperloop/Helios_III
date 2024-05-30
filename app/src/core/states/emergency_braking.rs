use crate::core::controllers::breaking_controller::BRAKE;
use crate::core::finite_state_machine::{State, Fsm};
use crate::{transit, Event};
use defmt::{error, info, warn};
use embassy_time::Timer;

impl Fsm {
    pub fn entry_emergency_braking(&mut self) {
        unsafe {
            BRAKE = true;
        }

        self.peripherals.hv_peripherals.power_hv_off();
        self.peripherals.red_led.set_high();
        error!("Emergency Braking!!");
        warn!("Emergency Braking!!!");
        error!("Emergency Braking!!");
        warn!("Emergency Braking!!!");
        error!("Emergency Braking!!");

        // transit!(self, State::Exit);
    }

    pub async fn react_emergency_braking(&mut self, event: Event) {
        match event {
            Event::SystemResetCommand => {
                transit!(self, State::RunConfig);
            }
            _ => {}
        }
    }
}
