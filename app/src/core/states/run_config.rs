use crate::core::finite_state_machine::{State, FSM};
use crate::{Datatype, Event};
use defmt::{error, info};
use crate::core::communication::Datapoint;

//use crate::core::finite_state_machine_peripherals::ARMED;

impl FSM {
    pub async fn entry_run_config(&mut self) {
        if !self.peripherals.braking_controller.brake_retraction {
            self.transit(State::Exit).await;
            //LOG BECAUSE BRAKES WERE NOT ALIVE
        }

        //ASK THE GROUND STATION FOR THE CONFIGURATION FILE
        self.data_queue.send(Datapoint::new(Datatype::Info, 12345, embassy_time::Instant::now().as_ticks())).await;
    }
    pub async fn react_run_config(&mut self, event: Event) {
        match event {
            Event::SetRunConfig(x) => {
                todo!(); // TODO: send message to propulsion to set desired speed ?
                //self.peripherals.propulsion_controller.set_run_config(x);
                // self.transit(State::Idle).await;
            }
            Event::ArmBrakesCommand => {
                self.peripherals.braking_controller.arm_breaks();

            }
            Event::RunConfigCompleteEvent => {
                todo!(); // TODO: receive reply from propulsion that desired speed has been set
                self.transit(State::Idle).await;
            }
            Event::RunConfigFailedEvent => {
                todo!();
                #[cfg(debug_assertions)]
                error!("Run config failed");

                self.transit(State::Exit).await;
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
