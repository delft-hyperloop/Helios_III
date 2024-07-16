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
    pub fn entry_ls_cv(&mut self) {
        self.peripherals.propulsion_controller.set_speed(self.route.current_speed());
    }

    pub async fn react_mv_ls_cv(&mut self, event: Event) {
        match event {
            Event::HvLevitationBelowBms => {
                transit!(self, State::EmergencyBraking);
            }
            Event::LaneSwitchEnded => match self.route.next_position() {
                Location::ForwardC => {
                    info!("Entering straight track after curved lane-switch!");
                    transit!(self, State::EndST);
                },

                Location::BackwardsA => {
                    info!("Entering straight track after curved lane-switch!");
                    transit!(self, State::MovingST);
                },

                Location::StopAndWait => {
                    self.peripherals.propulsion_controller.stop();
                    self.send_levi_cmd(Command::LeviPropulsionStop(0)).await;
                    transit!(self, State::Levitating);
                },

                _ => {
                    info!("Invalid configuration!");
                    self.log(Info::InvalidRouteConfigurationAbortingRun).await;
                    transit!(self, State::EndST);
                },
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
