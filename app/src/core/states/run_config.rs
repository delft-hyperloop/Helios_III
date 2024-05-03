use crate::core::finite_state_machine::{State, FSM};
use crate::Event;
use defmt::info;

//use crate::core::finite_state_machine_peripherals::ARMED;

impl FSM {
    pub fn entry_run_config(&mut self) {
        if !self.peripherals.braking_controller.brake_retraction {
            self.transit(State::Exit);
            //LOG BECAUSE BRAKES WERE NOT ALIVE
        }

        //ASK THE GROUND STATION FOR THE CONFIGURATION FILE
    }
    pub fn react_run_config(&mut self, event: Event) {
        match event {
            Event::RunConfigCompleteEvent => {
                todo!();

                self.transit(State::Idle);
            }
            Event::RunConfigFailedEvent => {
                todo!();

                self.transit(State::Exit);
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
