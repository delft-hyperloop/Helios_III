use defmt::info;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::core::fsm_status::Location;
use crate::core::fsm_status::RouteUse;
use crate::transit;
use crate::Event;
use crate::Info;

impl Fsm {
    pub fn entry_end_ls(&mut self) { self.peripherals.propulsion_controller.stop(); }

    pub async fn react_end_ls(&mut self, event: Event) {
        match event {
            Event::HvLevitationBelowBms => {
                transit!(self, State::EmergencyBraking);
            }
            Event::BrakingPointReachedC => match self.route.next_position() {
                Location::BackwardsC => {
                    transit!(self, State::EndLS);
                },
                Location::StopAndWait => {
                    info!("Braking point reached");
                    self.peripherals.propulsion_controller.stop();
                    transit!(self, State::Levitating);
                },
                _ => {
                    info!("Invalid configuration!");
                    transit!(self, State::Exit);
                },
            },
            Event::LaneSwitchBackwardsC => match self.route.next_position() {
                Location::LaneSwitchCurved => {
                    transit!(self, State::MovingLSCV);
                },
                Location::StopAndWait => {
                    self.peripherals.propulsion_controller.stop();
                    transit!(self, State::Levitating);
                },
                _ => {
                    info!("Invalid configuration!");
                    self.log(Info::InvalidRouteConfigurationAbortingRun).await;
                    transit!(self, State::Exit);
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
