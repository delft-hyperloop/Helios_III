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
    pub fn entry_ls_st(&mut self) {
        self.peripherals.propulsion_controller.set_speed(self.route.current_speed());
    }

    pub async fn react_mv_ls_st(&mut self, event: Event) {
        // self.send_levi_cmd(Command::ls0(0)).await;

        match event {
            Event::HvLevitationBelowBms => {
                transit!(self, State::EmergencyBraking);
                self.send_levi_cmd(Command::EmergencyBrake(4)).await;
            },
            Event::LaneSwitchEnded => match self.route.next_position() {
                Location::BackwardsA => {
                    info!("Exiting a straight run LS!");
                    transit!(self, State::MovingST);
                },

                Location::ForwardB => {
                    info!("Exiting a straight run LS!");
                    transit!(self, State::EndST);
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
