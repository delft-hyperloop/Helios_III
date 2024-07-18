use defmt::error;
use defmt::info;
use defmt::warn;
use embassy_time::Instant;
use embassy_time::Timer;

use crate::core::controllers::hv_controller::timeout_finish_pre_charge;
use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::pconfig::send_event;
use crate::transit;
use crate::Command;
use crate::Event;
use crate::Info;

impl Fsm {
    pub fn entry_pre_charge(&mut self) {
        match self.fsm_spawner.spawn(timeout_finish_pre_charge(
            self.event_sender,
            self.peripherals.hv_peripherals.pre_charge_min,
        )) {
            Ok(_) => {
                self.peripherals.hv_peripherals.pre_charge_start = Instant::now();
            },
            Err(e) => {
                error!("spawn error: {:?}", e);
                send_event(self.event_sender, Event::BootingFailedEvent);
                send_event(self.event_sender, Event::EmergencyBraking);
                return;
            },
        }

        self.peripherals.led_controller.hv_led.set_high();
        // 1. Turn on negative relay.
        warn!("1. Turn on negative relay.");
        self.peripherals.hv_peripherals.pin_6.set_high();
        // 2. turn on pre-charge relay
        warn!("2. turn on pre-charge relay");
        self.peripherals.hv_peripherals.pin_7.set_high();
    }

    pub async fn react_pre_charge(&mut self, event: Event) {
        match event {
            Event::HvLevitationBelowBms => {
                self.peripherals.hv_peripherals.pre_charge_successful = false
            },
            Event::HvLevitationAboveBms => {
                self.peripherals.hv_peripherals.pre_charge_successful = true
            },

            Event::PrechargeAbort | Event::TurnOffHVCommand => {
                self.peripherals.hv_peripherals.power_hv_off();
                #[cfg(debug_assertions)]
                info!("HV Relays turned off");
                // self.peripherals.led_controller.hv_relay_led(false).await;
                self.pod_safe().await;
                transit!(self, State::EmergencyBraking);
                self.send_levi_cmd(Command::EmergencyBrake(4)).await;
            },
            Event::FinishPrecharge => {
                if !self.peripherals.hv_peripherals.pre_charge_successful {
                    self.log(Info::PrechargeAborted).await;
                    transit!(self, State::EmergencyBraking);
                    self.send_levi_cmd(Command::EmergencyBrake(4)).await;
                    return;
                }

                self.peripherals.led_controller.hv_led.set_high();
                // 3. make sure pre-charge relay is off
                warn!("3. pre-charge relay is off");
                self.peripherals.hv_peripherals.pin_7.set_low();
                Timer::after_micros(100).await;
                // 4. turn on positive relay
                warn!("4. turn on positive relay");
                self.peripherals.hv_peripherals.pin_4.set_high();
                transit!(self, State::HVOn);
            },
            _ => info!("[fsm] State precharging ignores event {:?}", event),
        }
    }
}
