use crate::core::finite_state_machine::{State, FSM};
use crate::Event;
use defmt::{error, info, warn};
use embassy_time::Timer;
use crate::core::controllers::breaking_controller::BRAKE;

impl FSM {
    pub async fn entry_emergency_braking(&mut self) {
        unsafe { BRAKE = true; }
        self.peripherals.hv_peripherals.enable_pin.set_low();

        error!("Emergency Braking!!");
        warn!("Emergency Braking!!!");
        error!("Emergency Braking!!");
        warn!("Emergency Braking!!!");
        error!("Emergency Braking!!");

        self.transit(State::Exit).await
    }
}
