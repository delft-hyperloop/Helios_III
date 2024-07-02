use crate::core::finite_state_machine::{State, FSM};
use crate::Event;
use defmt::info;

//use crate::core::finite_state_machine_peripherals::ARMED;

impl FSM {
    pub async fn entry_run_config(&mut self) {
        if !self.peripherals.braking_controller.brake_retraction {
            self.transit(State::Exit).await;
            //LOG BECAUSE BRAKES WERE NOT ALIVE
        }

        //ASK THE GROUND STATION FOR THE CONFIGURATION FILE
    }
    pub async fn react_run_config(&mut self, event: Event) {
        match event {
            Event::SetRunConfig(x) => {
                todo!();
                //self.peripherals.propulsion_controller.set_run_config(x);
                self.transit(State::Idle).await;
            }
            Event::RunConfigCompleteEvent => {
                todo!();

                self.transit(State::Idle).await;
            }
            Event::RunConfigFailedEvent => {
                todo!();

                self.transit(State::Exit).await;
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
