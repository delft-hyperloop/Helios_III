use defmt::info;
use defmt::warn;
use embassy_time::Timer;

use crate::core::finite_state_machine::Fsm;
use crate::core::finite_state_machine::State;
use crate::transit;
use crate::Event;
use crate::EventSender;

impl Fsm {
    pub fn entry_pre_charge(&mut self) {
        // 1. Turn on negative relay.
        warn!("1. Turn on negative relay.");
        self.peripherals.hv_peripherals.pin_6.set_high();
        // 2. turn on pre-charge relay
        warn!("2. turn on pre-charge relay");
        self.peripherals.hv_peripherals.pin_7.set_high();
    }

    pub async fn react_pre_charge(&mut self, event: Event) {
        match event {
            Event::PrechargeAbort | Event::TurnOffHVCommand => {
                self.peripherals.hv_peripherals.power_hv_off();
                #[cfg(debug_assertions)]
                info!("HV Relays turned off");
                self.peripherals.led_controller.hv_relay_led(false).await;
                self.pod_safe().await;
                transit!(self, State::Idle);
            },
            Event::HvLevitationAboveBms | Event::FinishPrecharge => {
                // 3. make sure pre-charge relay is off
                warn!("3. pre-charge relay is off");
                self.peripherals.hv_peripherals.pin_7.set_low();
                // 4. turn on positive relay
                warn!("4. turn on positive relay");
                self.peripherals.hv_peripherals.pin_4.set_high();
                transit!(self, State::HVOn);
            },
            _ => info!("[fsm] State precharging ignores event {:?}", event),
        }
    }
}

pub async fn timeout_abort_pre_charge(es: EventSender) {
    Timer::after_millis(4700).await;
    es.send(Event::PrechargeAbort).await;
}
