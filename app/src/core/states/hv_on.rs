use defmt::info;
use defmt::warn;

use crate::core::finite_state_machine::*;
use crate::{Datatype, transit};
use crate::Command;
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
            Event::HvLevitationBelowBms => {
                transit!(self, State::EmergencyBraking);
                self.send_levi_cmd(Command::EmergencyBrake(4)).await;
            },
            Event::CygnusesVaryingVoltages | Event::TurnOffHVCommand => {
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

            Event::EnablePropulsionCommand => {
                self.peripherals.propulsion_controller.enable();
                self.peripherals.propulsion_controller.set_speed(0);
                self.log(Info::EnablePropulsionGpio).await;
                self.send_data(Datatype::PropGPIODebug, 1).await;
            },

            Event::RunStarting => {
                if !self.status.levitating && !self.status.overrides.propulsion_without_levitation()
                {
                    self.log(Info::LevitationNotStarted).await;
                    return;
                }

                self.enter_moving().await;
                self.set_ls_mode().await;
            },

            _ => {
                info!("The current state ignores {}", event.to_str());
            },
        }
    }
}
