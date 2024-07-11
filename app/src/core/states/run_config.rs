use defmt::debug;
use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;
use crate::Info;

impl Fsm {
    pub fn entry_run_config(&mut self) {
        self.peripherals.braking_controller.start_run_brake_precondition();
    }

    pub async fn react_run_config(&mut self, event: Event) {
        match event {
            Event::SetRoute(x) => {
                #[cfg(debug_assertions)]
                debug!("Setting run config: {:?}", x);
                self.route.positions_from(x);
                self.route.current_position = 0;
                self.status.route_set = true;
            },
            Event::SetRunConfigSpeed(x) => {
                debug!("Setting run config speed: {:?}", x);
                self.route.speeds_from(x);
                self.status.speeds_set = true;
            },
            Event::ArmBrakesCommand => {
                self.peripherals.braking_controller.arm_breaks().await; // without this you cant turn on hv
                self.status.brakes_armed = true;
                #[cfg(debug_assertions)]
                info!("[fsm] Rearmed brakes!");
            },
            Event::RunConfigCompleteEvent => {
                if self.status.route_set && self.status.speeds_set {
                    transit!(self, State::Idle);
                } else {
                    #[cfg(debug_assertions)]
                    info!("[fsm] Route or Speeds not set");
                    self.log(Info::IncompleteConfiguration).await;
                }
            },
            Event::SystemResetCommand => {
                self.send_data(crate::Datatype::FSMState, self.state as u64).await;
                transit!(self, State::RunConfig);
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
