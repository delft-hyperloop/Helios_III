use embassy_stm32::gpio::Output;
use embassy_time::Duration;
use embassy_time::Instant;
use embassy_time::Timer;

use crate::Event;
use crate::EventSender;

pub struct HVPeripherals {
    pub pin_4: Output<'static>,
    pub pin_6: Output<'static>,
    pub pin_7: Output<'static>,
    pub dc_dc: Output<'static>,
    pub pre_charge_start: Instant,
    pub pre_charge_min: Duration,
    pub pre_charge_successful: bool,
}

impl HVPeripherals {
    // pub async fn power_on_hv_procedure(&mut self) {
    //     self.pin_6.set_high();
    //     info!("just set pin 6 high");
    //     self.pin_7.set_high();
    //     info!("just set pin 7 high");
    //     Timer::after_millis(5000).await;
    //     self.pin_7.set_low();
    //     info!("just set pin 7 low");
    //     self.pin_4.set_high();
    //     info!("just set pin 4 high");
    //     info!("HV Powered on");
    //     info!("HV Powered on");
    // }

    pub fn power_hv_off(&mut self) {
        self.pin_4.set_low();
        self.pin_6.set_low();
        self.pin_7.set_low();
    }
}

#[embassy_executor::task]
pub async fn timeout_abort_pre_charge(event_sender: EventSender, timeout: Duration) {
    Timer::after(timeout).await;
    event_sender.send(Event::PrechargeAbort).await;
}

#[embassy_executor::task]
pub async fn timeout_finish_pre_charge(event_sender: EventSender, timeout: Duration) {
    Timer::after(timeout).await;
    event_sender.send(Event::FinishPrecharge).await;
}
