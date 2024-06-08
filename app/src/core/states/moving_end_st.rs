use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::{Location, RouteUse};
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_end_st(&mut self) {
       // "self.peripherals.propulsion_controller.stop();"


    }

    pub async fn react_end_st(&mut self, event: Event) {
        match event {
            Event::DirectionChangedEvent => {
                match self.route.current_position(){
                    Location::StopHere => {
                        info!("Stopping here.");
                        transit!(self, State::Exit);
                    }
                    _ => {
                        self.peripherals.propulsion_controller.set_speed(self.route.current_speed() as u64);
                    }
                }
            }
            Event::RunFinishedEvent => {
                #[cfg(debug_assertions)]
                info!("Run finished");
                transit!(self, State::Exit);
            }
            Event::LaneSwitchBackwardsB => {
                self.send_levi_cmd(crate::Command::ls1(0)).await;
                // self.peripherals.propulsion_controller.turn_off();
                transit!(self, State::MovingLSST);
            }
            Event::LaneSwitchBackwardsC => {
                self.send_levi_cmd(crate::Command::ls2(0)).await;
                // self.peripherals.propulsion_controller.turn_off();
                transit!(self, State::MovingLSCV);
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }



        }
    }
}
