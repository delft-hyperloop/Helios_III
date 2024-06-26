use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::RouteUse;
use crate::transit;
use crate::Event;

impl Fsm {
    pub fn entry_end_st(&mut self) {
        self.peripherals
            .propulsion_controller
            .set_speed(self.route.current_speed());
    }

    pub async fn react_end_st(&mut self, event: Event) {
        match event {
            Event::RunFinishedEvent => {
                #[cfg(debug_assertions)]
                info!("Run finished");
                transit!(self, State::Exit);
            }
            Event::BrakingPointReachedB => {
                info!("Braking point reached");
                self.peripherals.propulsion_controller.stop();
                transit!(self, State::Levitating);
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
