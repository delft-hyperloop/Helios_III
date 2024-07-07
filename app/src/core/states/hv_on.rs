use defmt::info;
use defmt::warn;

use crate::core::finite_state_machine::*;
use crate::core::fsm_status::Location;
use crate::core::fsm_status::RouteUse;
use crate::transit;
use crate::Event;
use crate::Info;

impl Fsm {
    pub fn entry_hv_on(&mut self) {
        #[cfg(debug_assertions)]
        info!("Entering HV System Checking");
        warn!("HV SYSTEM IS ON!");
    }

    pub async fn react_hv_on(&mut self, event: Event) {
        match event {
            Event::TurnOffHVCommand => {
                self.peripherals.hv_peripherals.power_hv_off();
                #[cfg(debug_assertions)]
                info!("HV Relays turned off");
                self.peripherals.led_controller.hv_relay_led(false).await;
                self.pod_safe().await;
                transit!(self, State::Idle);
            },
            Event::LeviLaunchingEvent => {
                // no preconditions allowed since GS is in charge here
                #[cfg(debug_assertions)]
                info!("Starting Levitation");

                transit!(self, State::Levitating);
            },

            Event::RunStarting => {
                if !self.status.levitating && !self.status.overrides.propulsion_without_levitation {
                    self.log(Info::LevitationNotStarted).await;
                    return;
                }

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

            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
