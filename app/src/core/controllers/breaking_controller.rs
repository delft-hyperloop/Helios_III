use crate::{try_spawn, Event, EventSender};
use defmt::export::timestamp;
use defmt::{info, unwrap};
use embassy_executor::Spawner;
use embassy_stm32::gpio::{Input, Level, Output, OutputType, Pull, Speed};
use embassy_stm32::peripherals::{PB0, PD5, TIM16};
use embassy_stm32::time::khz;
use embassy_stm32::timer::simple_pwm::{PwmPin, SimplePwm};
use embassy_stm32::timer::Channel;
use embassy_stm32::{peripherals, Peripherals};
use embassy_stm32::adc::Adc;
use embassy_stm32::gpio::OutputType::PushPull;
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::Sender;
use embassy_time::{Duration, Instant, Timer};
use heapless::binary_heap::Max;

pub static mut BRAKE: bool = false;

pub struct BrakingController {
    pub braking_rearm: Output<'static>,
    // pub braking_signal: Output<'static>,
    pub braking_communication: Input<'static>,
    pub brake_retraction: bool,
}

#[embassy_executor::task]
pub async fn control_braking_heartbeat(sender: EventSender, mut braking_signal: Output<'static>) {
    // pub async fn control_braking_heartbeat(sender: EventSender, mut braking_heartbeat: SimplePwm<'static, TIM16>) {
    info!("----------------- Start Braking Heartbeat! -----------------");
    let mut booting = true;
    let mut time_stamp = Instant::now();
    loop {
        Timer::after_micros(200).await;
        if (unsafe {!BRAKE}) {
            braking_signal.set_high();
            // braking_heartbeat.set_duty(Channel::Ch1, braking_heartbeat.get_max_duty()/2);
        }
        else {
            braking_signal.set_low();

            // braking_heartbeat.set_duty(Channel::Ch1, 0);
            sender.send(Event::EmergencyBrakeCommand).await;
            info!("------------ BRAKE ! ------------");
        }
        if booting {
            sender.send(Event::BootingCompleteEvent).await;
            booting = false;
        }
    }

    info!("------------ Braking ended; someone fucked up... ------------");
}

impl BrakingController {
    pub async fn new(
        x: &Spawner,
        braking_sender: EventSender,
        pb8: peripherals::PB8,
        pg1: peripherals::PG1,
        pf12: peripherals::PF12,
        pb0: peripherals::PB0,
        pd5: peripherals::PD5,
        ptime: TIM16,
    ) -> Self {
        // If we want to keep it alive we send a 10khz digital clock signal
        let mut braking_rearm: Output = Output::new(pg1, Level::High, Speed::Low); // <--- To keep the breaks not rearmed we send a 1, if we want to arm the breaks we send a 0

        let mut led : Output = Output::new(pb0,Level::High,Speed::Low);
        // let mut led2 : Output = Output::new(pd5,Level::High,Speed::Low);
        led.set_high();
        info!("set led on pb0 to high");
        // let mut pwm = SimplePwm::new(
        //     ptime,
        //     Some(PwmPin::new_ch1(pb8, OutputType::PushPull)),
        //     None,
        //     None,
        //     None,
        //     khz(30),
        //     Default::default(),
        // );
        let mut braking_communication = Input::new(pf12, Pull::None); // <--- If its HIGH it means that breaks are rearmed, if its low it , means we are breaking
                                                                             // Finally if we set the heartbeat to LOW, and we still receive a 1 is basically means we are crashing so lets actually make use of the crashing state

        // let mut braking_communication = Adc::new();
        // braking_communication

        let braking_signal = Output::new(pb8, Level::High, Speed::Low);
        // pwm.enable(Channel::Ch1);

        try_spawn!(braking_sender, x.spawn(control_braking_heartbeat(braking_sender, braking_signal)));

        BrakingController {
            braking_rearm,
            braking_communication,
            brake_retraction: false,
        }
    }

    pub fn arm_breaks(&mut self) -> bool {
        self.braking_rearm.set_high();
        let time_stamp = Instant::now();
        while (Instant::now() - time_stamp) < Duration::from_millis(100) {
            if self.braking_communication.is_high() {
                self.brake_retraction = true;
                return true;
            }
        }
        return false;
    }

    pub fn disarm_breaks(&mut self) {
        self.braking_rearm.set_low();
        self.brake_retraction = true;
        unsafe{BRAKE = false};
    }
    pub fn brake(&mut self) {
        unsafe { BRAKE = true };
    }
}
