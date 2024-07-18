use defmt::info;
use embassy_stm32::gpio::Level;
use embassy_stm32::gpio::Output;
use embassy_stm32::gpio::Speed;
use embassy_stm32::peripherals::PE10;
use embassy_stm32::peripherals::PE11;
use embassy_stm32::peripherals::PE13;
use embassy_stm32::peripherals::PE14;
use embassy_stm32::peripherals::PE7;
use embassy_stm32::peripherals::PE8;
use embassy_stm32::peripherals::PE9;

pub struct LedController {
    pub led_1: Output<'static>,
    pub led_2: Output<'static>,
    pub led_3: Output<'static>,
    pub led_4: Output<'static>,
    pub hv_led: Output<'static>,
    pub hv_relay_1: Output<'static>,
    pub hv_relay_2: Output<'static>,
}

impl LedController {
    pub async fn new(
        pe7: PE7,
        pe8: PE8,
        pe9: PE9,
        pe10: PE10,
        pe11: PE11,
        pe13: PE13,
        pe14: PE14,
    ) -> Self {
        info!("Led PCB ON");
        LedController {
            led_1: Output::new(pe7, Level::Low, Speed::Low),
            led_2: Output::new(pe8, Level::Low, Speed::Low),
            led_3: Output::new(pe9, Level::Low, Speed::Low),
            led_4: Output::new(pe10, Level::Low, Speed::Low),
            hv_led: Output::new(pe11, Level::Low, Speed::Low),
            hv_relay_1: Output::new(pe13, Level::Low, Speed::Low),
            hv_relay_2: Output::new(pe14, Level::Low, Speed::Low),
        }
    }

    pub async fn state_led(&mut self, mut id: u8) {
        id += 1;
        if id & 1 == 0 {
            self.led_1.set_low()
        } else {
            self.led_1.set_high()
        };
        if id & 2 == 0 {
            self.led_2.set_low()
        } else {
            self.led_2.set_high()
        };
        if id & 4 == 0 {
            self.led_3.set_low()
        } else {
            self.led_3.set_high()
        };
        if id & 8 == 0 {
            self.led_4.set_low()
        } else {
            self.led_4.set_high()
        };
    }

    pub async fn hv_relay_led(&mut self, on: bool) {
        if on {
            self.hv_relay_1.set_high();
            self.hv_relay_2.set_high();
        } else {
            self.hv_relay_1.set_low();
            self.hv_relay_2.set_low();
        }
    }
}
