use defmt::error;
#[cfg(debug_assertions)]
use defmt::info;
use defmt::warn;

use crate::core::controllers::breaking_controller::BRAKE;
use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::send_data;
use crate::transit;
use crate::Datatype;
use crate::Event;
use crate::Info;

impl Fsm {
    pub fn entry_emergency_braking(&mut self) {
        unsafe {
            BRAKE = true;
        }

        self.peripherals.hv_peripherals.power_hv_off();
        self.peripherals.propulsion_controller.disable();
        self.peripherals.red_led.set_high();
        self.status.brakes_armed = false;
        self.status.route_set = false;
        self.status.speeds_set = false;
        self.status.levitating = false;

        error!("------ Emergency Braking!! ------");
        warn!("Emergency Braking!!!");
        error!("Emergency Braking!!");
        warn!("Emergency Braking!!!");
        error!("------ Emergency Braking!! ------");

        send_data!(self.data_queue, Datatype::Info, Info::EmergencyBraking as u64);
    }

    pub async fn react_emergency_braking(&mut self, event: Event) {
        match event {
            Event::SystemResetCommand => {
                self.send_data(Datatype::BrakingRearmDebug, 1).await;
                transit!(self, State::RunConfig);
            },
            Event::ConnectionEstablishedEvent => {
                self.send_data(Datatype::FSMState, self.state as u64).await;
            },
            _ => {
                #[cfg(debug_assertions)]
                info!("[fsm] EmergencyBrake state ignores {:?}", event);
            },
        }
    }
}
