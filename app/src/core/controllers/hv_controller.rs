use defmt::info;
use embassy_stm32::gpio::Output;
use embassy_time::Timer;

pub struct HVPeripherals {
    pub pin_4: Output<'static>,
    pub pin_6: Output<'static>,
    pub pin_7: Output<'static>,
}

impl HVPeripherals {
    pub async fn power_on_hv_procedure(&mut self) {
        self.pin_6.set_high();
        #[cfg(debug_assertions)]
        info!("just set pin 6 high");
        self.pin_7.set_high();
        #[cfg(debug_assertions)]
        info!("just set pin 7 high");
        Timer::after_millis(5000).await;
        self.pin_7.set_low();
        #[cfg(debug_assertions)]
        info!("just set pin 7 low");
        self.pin_4.set_high();
        #[cfg(debug_assertions)]
        info!("just set pin 4 high");
        #[cfg(debug_assertions)]
        info!("HV Powered on");
        info!("HV Powered on");
        info!("HV Powered on");
        info!("HV Powered on");
    }

    pub fn power_hv_off(&mut self) {
        self.pin_4.set_low();
        self.pin_6.set_low();
        self.pin_7.set_low();
    }
}
