use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::Location;
use crate::core::fsm_status::RouteUse;
use crate::transit;
use crate::Command;
use crate::Event;
use crate::Info;

impl Fsm {
    pub fn entry_levitating(&mut self) {
        // self.peripherals.propulsion_controller.set_speed(0);
        // self.peripherals.propulsion_controller.enable();
    }

    pub async fn react_levitating(&mut self, event: Event) {
        match event {
            Event::RunStarting => {
                self.send_levi_cmd(Command::LeviPropulsionStart(0)).await;
                match self.route.next_position() {
                    Location::StraightStart => transit!(self, State::MovingST),
                    Location::StraightEndTrack | Location::StraightBackwards => {
                        transit!(self, State::EndST)
                    },
                    Location::LaneSwitchEndTrack => transit!(self, State::EndLS),
                    Location::StopAndWait => self.peripherals.propulsion_controller.stop(),
                    _ => {
                        self.log(Info::InvalidRouteConfiguration).await;
                        transit!(self, State::Exit);
                    },
                }
            },

            Event::LeviLandingEvent => {
                transit!(self, State::Idle);
            },

            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
