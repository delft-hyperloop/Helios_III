use core::sync::atomic::Ordering;

use defmt::trace;
use embassy_executor::Spawner;
use embassy_stm32::adc::Adc;
use embassy_stm32::adc::SampleTime;
use embassy_stm32::adc::VrefInt;
use embassy_stm32::dac::Value;
use embassy_stm32::gpio::Level;
use embassy_stm32::gpio::Output;
use embassy_stm32::gpio::Speed;
use embassy_stm32::peripherals::ADC2;
use embassy_stm32::peripherals::DAC1;
use embassy_stm32::peripherals::PA4;
use embassy_stm32::peripherals::PA5;
use embassy_stm32::peripherals::PA6;
use embassy_stm32::peripherals::PB1;
use embassy_time::Timer;

use crate::core::fsm_status::CONNECTED;
use crate::send_data;
use crate::try_spawn;
use crate::DataSender;
use crate::Datatype;
use crate::Event;
use crate::EventSender;

pub struct PropulsionController {
    pub speed_set_pin: embassy_stm32::dac::DacCh1<'static, DAC1>,
    pub enable_pin: Output<'static>,
}

/// Functions related to controlling the propulsion subsystem
/// TODO
/// - fn to convert desired speed to analog out voltage
/// - something to store which direction we're going in ?
/// -
#[allow(dead_code)]
impl PropulsionController {
    /// Create a new instance of the PropulsionController
    ///
    /// related pins:
    /// - PA4: DAC1 - write desired speed to propulsion
    /// - PA5: ADC - read propulsion voltage
    /// - PA6: ADC - read propulsion current
    /// - PB1: GPIO - enable/disable propulsion
    pub async fn new(
        x: Spawner,
        data_sender: DataSender,
        event_sender: EventSender,
        pa4: PA4,
        dac1: DAC1,
        adc2: ADC2,
        pa5: PA5,
        pa6: PA6,
        gpio_enable: PB1,
    ) -> Self {
        let speed_set_pin = embassy_stm32::dac::DacCh1::new(dac1, embassy_stm32::dma::NoDma, pa4);

        let mut adc = Adc::new(adc2);
        adc.set_sample_time(SampleTime::CYCLES32_5);
        let v_ref_int_channel = adc.enable_vrefint();

        try_spawn!(
            event_sender,
            x.spawn(read_prop_adc(data_sender, v_ref_int_channel, adc, pa5, pa6))
        );

        event_sender.send(Event::LVPropulsionReadyEvent).await;

        Self { speed_set_pin, enable_pin: Output::new(gpio_enable, Level::Low, Speed::Low) }
    }

    /// Write to the DAC to set the desired speed
    pub fn set_speed(&mut self, speed: u8) {
        trace!("Setting speed to {}", speed);
        self.speed_set_pin.set(Value::Bit8(speed));
    }

    pub fn stop(&mut self) {
        trace!("Stopping propulsion by setting speed to 0");
        self.speed_set_pin.set(Value::Bit8(0));
        self.disable();
    }

    pub fn disable(&mut self) { self.enable_pin.set_low(); }

    pub fn enable(&mut self) { self.enable_pin.set_high(); }
}

#[embassy_executor::task]
pub async fn read_prop_adc(
    data_sender: DataSender,
    mut v_ref_int_channel: VrefInt,
    mut adc: Adc<'static, ADC2>,
    mut pa5: PA5,
    mut pa6: PA6,
) {
    Timer::after_millis(1000).await;
    loop {
        Timer::after_millis(50).await;
        if !CONNECTED.load(Ordering::Relaxed) {
            continue;
        }
        for _ in 0..3 {
            let i = adc.read(&mut pa6) as u64;
            send_data!(data_sender, Datatype::PropulsionCurrent, i; 5000);
            Timer::after_millis(100).await;
        }
        let v_ref_int = adc.read_internal(&mut v_ref_int_channel);
        let v = adc.read(&mut pa5) as u64;
        send_data!(data_sender, Datatype::PropulsionVoltage, v; 5000);
        send_data!(data_sender, Datatype::PropulsionVRefInt, v_ref_int as u64; 5000);
    }
}
