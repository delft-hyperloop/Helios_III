use embassy_stm32::dac::Value;
use embassy_stm32::gpio::Output;
use embassy_stm32::peripherals::{DAC1, PA4, PA5, PA6};
use crate::DataSender;

#[allow(dead_code)]
pub struct PropulsionController {
    pub speed_set_pin: embassy_stm32::dac::DacCh1<'static, DAC1>,
    // pub enable_pin: Output<'static>,

}

/// Functions related to controlling the propulsion subsystem
/// TODO
/// - fn to convert desired speed to analog out voltage
/// - something to store which direction we're going in ?
/// -
impl PropulsionController {

    /// Create a new instance of the PropulsionController
    ///
    /// related pins:
    /// - PA4: DAC1 - write desired speed to propulsion
    /// - PA5: ADC - read propulsion voltage
    /// - PA6: ADC - read propulsion current
    /// - PE5: GPIO - enable/disable propulsion
    pub fn new(data_sender: DataSender, pa4: PA4, dac1: DAC1, pa5: PA5, pa6: PA6, /* some gpio */) -> Self {
        let mut speed_set_pin = embassy_stm32::dac::DacCh1::new(dac1, embassy_stm32::dma::NoDma, pa4);

        Self {
            speed_set_pin
        }
    }

    /// Write to the DAC to set the desired speed
    pub fn set_speed(&self, speed: u64) {

        // self.speed_set_pin.set_value();
    }
    pub fn stop(&self) {
        // self.speed_set_pin.set_value();
    }

    pub fn turn_off(&self) {
        // self.enable_pin.set_low();
    }

    // #[embassy_executor::task]
    // pub async fn read_prop_voltage(data_sender: DataSender, ) {
    //     loop {
    //
    //     }
    //     todo!()
    // }

    // #[embassy_executor::task]
    // pub async fn read_prop_current(data_sender: DataSender) {
    //     todo!();
    // }
}
