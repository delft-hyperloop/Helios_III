use defmt::debug;
use defmt::error;
use defmt::info;
use crate::core::controllers::breaking_controller::BRAKE;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_run_config(&mut self) {
        // unsafe { BRAKE = false; }
        // if !self.peripherals.braking_controller.brake_retraction {
        //     transit!(self, State::Exit);
        //     //LOG BECAUSE BRAKES WERE NOT ALIVE
        // }
        self.peripherals.braking_controller.start_run_brake_precondition();

        //ASK THE GROUND STATION FOR THE CONFIGURATION FILE
        // self.data_queue
        //     .send(Datapoint::new(
        //         Datatype::Info,
        //         12345,
        //         embassy_time::Instant::now().as_ticks(),
        //     ))
        //     .await;
    }
    pub async fn react_run_config(&mut self, event: Event) {
        match event {
            Event::SetRoute(x) => {
                #[cfg(debug_assertions)]
                debug!("Setting run config: {:?}", x);
                self.route.positions_from(x);
                self.route.current_position = 0;
            }
            Event::SetRunConfigSpeed(x) => {
                #[cfg(debug_assertions)]
                debug!("Setting run config speed: {:?}", x);
                self.route.speeds_from(x);
            }
            Event::ArmBrakesCommand => {
                self.peripherals.braking_controller.arm_breaks().await; // without this you cant turn on hv
                #[cfg(debug_assertions)]
                info!("[runconf] Rearmed braked!")
            }
            Event::RunConfigCompleteEvent => {
                // todo!(); // TODO: receive reply from propulsion that desired speed has been set
                transit!(self, State::Idle);
            }
            Event::RunConfigFailedEvent => {
                error!("Run config failed");

                transit!(self, State::Exit);
                todo!();
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
