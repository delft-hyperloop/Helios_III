use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::{Location, RouteUse};
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_end_st(&mut self) {
        // match self.route.next_position() {
        //     Location::StopHere => {
        //         info!("Entering a lane switch!");
        //         self.send_levi_cmd(crate::Command::ls0(0)).await;
        //         transit!(self, State::EndST);
        //     }
        //     Location::LaneSwitchCurved => {
        //
        //     }
        // }
       // "self.peripherals.propulsion_controller.stop();"
        // todo!()


    }

    pub async fn react_end_st(&mut self, event: Event) {
        match event {
            Event::DirectionChangedEvent => {
                self.peripherals.propulsion_controller.set_speed(self.route.current_speed() as u64);
            }
            Event::RunFinishedEvent => {
                #[cfg(debug_assertions)]
                info!("Run finished");

                transit!(self, State::Exit);
            }
            Event::LaneSwitchBackwardsB => {
                // transit!(self, State::);
            }
            Event::LaneSwitchBackwardsC => {
                todo!();
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }



        }
    }
}
