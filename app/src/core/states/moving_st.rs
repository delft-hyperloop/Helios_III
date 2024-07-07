use defmt::error;
use defmt::info;
use defmt::warn;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::Location;
use crate::core::fsm_status::RouteUse;
use crate::{Command, transit};
use crate::Event;
use crate::Info;

impl Fsm {
    pub fn entry_mv_st(&mut self) {
        self.peripherals.propulsion_controller.set_speed(self.route.current_speed());
        //We have to put a strip on the track that would define a braking point here
    }

    pub async fn react_mv_st(&mut self, event: Event) {
        match event {
            Event::LaneSwitchForward => {
                match self.route.next_position() {
                    Location::LaneSwitchStraight => {
                        #[cfg(debug_assertions)]
                        info!("Entering a lane switch!");
                        // self.peripherals.propulsion_controller.turn_off();
                        self.send_levi_cmd(crate::Command::ls1(0)).await;
                        transit!(self, State::MovingLSST);
                    },
                    Location::LaneSwitchCurved => {
                        #[cfg(debug_assertions)]
                        info!("Entering a lane switch!");
                        self.send_levi_cmd(crate::Command::ls2(0)).await;
                        transit!(self, State::MovingLSCV);
                    },
                    Location::StopAndWait => {
                        #[cfg(debug_assertions)]
                        info!("Stopping and waiting");
                        self.peripherals.propulsion_controller.stop();
                        self.send_levi_cmd(Command::ls0(0)).await;
                        self.send_levi_cmd(Command::LeviPropulsionStop(0)).await;
                        transit!(self, State::Levitating);
                    },
                    Location::BrakeHere => {
                        warn!("Stopping here.");
                        self.send_levi_cmd(Command::LeviPropulsionStop(0)).await;
                        transit!(self, State::Exit);
                    },
                    _ => {
                        error!("Invalid configuration!");
                        self.log(Info::InvalidRouteConfiguration).await;
                        transit!(self, State::EmergencyBraking);
                    },
                }
            },

            Event::BrakingPointReachedA => {
                #[cfg(debug_assertions)]
                info!("Braking point reached");
                self.peripherals.propulsion_controller.stop();
                self.send_levi_cmd(crate::Command::ls0(0)).await;
                self.send_levi_cmd(crate::Command::LeviPropulsionStop(0)).await;
                transit!(self, State::Levitating);
            },

            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
