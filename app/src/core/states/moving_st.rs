use core::sync::atomic::Ordering;
use defmt::error;
use defmt::info;
use defmt::warn;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::{Location, POD_IS_MOVING};
use crate::core::fsm_status::RouteUse;
use crate::transit;
use crate::Command;
use crate::Event;
use crate::Info;

impl Fsm {
    pub fn entry_mv_st(&mut self) {
        self.peripherals.propulsion_controller.set_speed(self.route.current_speed());
        //We have to put a strip on the track that would define a braking point here
        POD_IS_MOVING.store(true, Ordering::Relaxed);
    }

    pub async fn react_mv_st(&mut self, event: Event) {
        match event {
            Event::HvLevitationBelowBms => {
                transit!(self, State::EmergencyBraking);
                self.send_levi_cmd(Command::EmergencyBrake(4)).await;
            },

            Event::LaneSwitchForward => {
                match self.route.next_position() {
                    Location::LaneSwitchStraight => {
                        #[cfg(debug_assertions)]
                        info!("Entering a lane switch!");
                        // self.peripherals.propulsion_controller.turn_off();
                        transit!(self, State::MovingLSST);
                    },
                    Location::LaneSwitchCurved => {
                        #[cfg(debug_assertions)]
                        info!("Entering a lane switch!");
                        transit!(self, State::MovingLSCV);
                    },
                    Location::StopAndWait => {
                        #[cfg(debug_assertions)]
                        info!("Stopping and waiting");
                        self.peripherals.propulsion_controller.stop();
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
                        self.log(Info::InvalidRouteConfigurationAbortingRun).await;
                        transit!(self, State::EmergencyBraking);
                        self.send_levi_cmd(Command::EmergencyBrake(4)).await;
                    },
                }
            },

            Event::BrakingPointReachedA => {
                #[cfg(debug_assertions)]
                info!("Braking point reached");
                self.peripherals.propulsion_controller.stop();
                self.send_levi_cmd(Command::ls0(0)).await;
                self.send_levi_cmd(Command::LeviPropulsionStop(0)).await;
                transit!(self, State::Levitating);
            },

            Event::LeviLandingEvent => {
                transit!(self, State::HVOn);
            },

            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
