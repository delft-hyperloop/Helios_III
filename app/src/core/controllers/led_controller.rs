use defmt::info;
use embassy_stm32::gpio::Output;

pub struct LedController {
    pub led_1: Output<'static>,
    pub led_2: Output<'static>,
    pub led_3: Output<'static>,
    pub led_4: Output<'static>,
    pub hv_relay_1: Output<'static>,
    pub hv_relay_2: Output<'static>,
}

impl LedController {
    pub async fn new(
        pe7: Output<'static>,
        pe8: Output<'static>,
        pe9: Output<'static>,
        pe10: Output<'static>,
        pe13: Output<'static>,
        pe14: Output<'static>,
    ) -> Self {
        info!("Led PCB ON");
        LedController {
            led_1: pe7,
            led_2: pe8,
            led_3: pe9,
            led_4: pe10,
            hv_relay_1: pe13,
            hv_relay_2: pe14,
        }
    }

    pub async fn state_led(&mut self, mut id : u8){
        id += 1;
        if id & 1 == 0 {self.led_1.set_low()} else {self.led_1.set_high()};
        if id & 2 == 0 {self.led_2.set_low()} else {self.led_2.set_high()};
        if id & 4 == 0 {self.led_3.set_low()} else {self.led_3.set_high()};
        if id & 8 == 0 {self.led_4.set_low()} else {self.led_4.set_high()};
    }

    pub async fn hv_relay_led(&mut self, on : bool){
        if on {
            self.hv_relay_1.set_high();
            self.hv_relay_2.set_high();
        } else {
            self.hv_relay_1.set_low();
            self.hv_relay_2.set_low();
        }
    }
}