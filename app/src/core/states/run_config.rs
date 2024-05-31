use defmt::error;
use defmt::info;

use crate::core::controllers::breaking_controller::BRAKE;
use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;

//use crate::core::finite_state_machine_peripherals::ARMED;

impl Fsm {
    pub fn entry_run_config(&mut self) {
        unsafe {
            BRAKE = false;
        }
        // if !self.peripherals.braking_controller.brake_retraction {
        //     transit!(self, State::Exit);
        //     //LOG BECAUSE BRAKES WERE NOT ALIVE
        // }

        // self.peripherals.braking_controller.arm_breaks();

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
            Event::SetRunConfig(x) => {
                let _bytes: [u8; 8] = x.to_be_bytes();
                todo!();
                //todo!(); // TODO: send message to propulsion to set desired speed ?
                //self.peripherals.propulsion_controller.set_run_config(x);
                // self.transit(State::Idle).await;
            }
            Event::ArmBrakesCommand => {
                self.peripherals.braking_controller.arm_breaks(); // without this you cant turn on hv
                #[cfg(debug_assertions)]
                info!("[runconf] Rearmed braked!")
            }
            Event::RunConfigCompleteEvent => {
                // todo!(); // TODO: receive reply from propulsion that desired speed has been set
                transit!(self, State::Idle); // todo make this a command on gs
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
