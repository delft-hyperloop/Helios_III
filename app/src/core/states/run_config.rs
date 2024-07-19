use core::sync::atomic::Ordering;

use defmt::debug;
use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::POD_IS_MOVING;
use crate::transit;
use crate::Event;
use crate::Info;

impl Fsm {
    pub fn entry_run_config(&mut self) {
        self.status.speeds_set = false;
        self.status.route_set = false;
        self.peripherals.braking_controller.start_run_brake_precondition();
        POD_IS_MOVING.store(false, Ordering::Relaxed);
    }

    pub async fn react_run_config(&mut self, event: Event) {
        match event {
            Event::SettingRoute(x) => {
                #[cfg(debug_assertions)]
                debug!("Setting run config: 0x{:x}", x);
                self.route.positions_from(x);
                self.route.current_position = 0;
                self.status.route_set = true;
                self.log(Info::RouteSet).await;
            },
            Event::SettingSpeeds(x) => {
                debug!("Setting run config speed: 0x{:x}", x);
                self.route.speeds_from(x);
                self.status.speeds_set = true;
                self.log(Info::SpeedsSet).await;
            },
            Event::ArmBrakesCommand => {
                self.peripherals.braking_controller.arm_breaks().await; // without this you cant turn on hv
                self.status.brakes_armed = true;
                debug!("[fsm] Rearmed brakes!");
                self.log(Info::BrakesArmed).await;
            },
            Event::RunConfigCompleteEvent => {
                if self.status.overrides.run_without_configure()
                    || (self.status.route_set && self.status.speeds_set)
                {
                    self.log(Info::ConfigurationCompleted).await;
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
