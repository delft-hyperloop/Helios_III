use defmt::{info, unwrap};
use defmt::export::timestamp;
use embassy_executor::Spawner;
use embassy_stm32::gpio::{Input, Level, Output, OutputType, Pull, Speed};
use embassy_stm32::{Peripherals, peripherals};
use embassy_stm32::peripherals::TIM16;
use embassy_stm32::time::khz;
use embassy_stm32::timer::Channel;
use embassy_stm32::timer::simple_pwm::{PwmPin, SimplePwm};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::Sender;
use embassy_time::{Duration, Instant, Timer};
use heapless::binary_heap::Max;
use crate::Event;

static mut BRAKE: bool = false;

pub struct BrakingController {
    pub braking_rearm: Output<'static>,
    pub braking_communication: Input<'static>,
    pub brake_retraction:bool,
}

#[embassy_executor::task]
pub async fn run(sender: Sender<'static,NoopRawMutex,Event,Max,16>, mut braking_heartbeat:SimplePwm<'static, TIM16>) {
    info!("------------ Start Braking Heartbeat! ------------");
    let mut booting =  true;
    let mut time_stamp = Instant::now();
    loop {
        Timer::after_micros(200).await;
        if (unsafe {!BRAKE} && (Instant::now() - time_stamp) < Duration::from_secs(10)) {
            braking_heartbeat.set_duty(Channel::Ch1, braking_heartbeat.get_max_duty()/2);
        }
        else {
            braking_heartbeat.set_duty(Channel::Ch1, 0);
            info!("------------ BRAKE !-----");
            time_stamp = Instant::now();
        }
        if booting {
            sender.send(Event::BootingCompleteEvent).await;
            booting = false;
        }
    }




    info!("------------ Braking ended; someone fucked up... ------------");
}

impl BrakingController {
    pub fn new(x: &Spawner, braking_sender: Sender<'static,NoopRawMutex,Event,Max, { crate::EVENT_QUEUE_SIZE }>, pb8: peripherals::PB8, pg1: peripherals::PG1, pf12: peripherals::PF12, ptime : TIM16) -> Self {
        // If we want to keep it alive we send a 10khz digital clock signal
        let mut braking_rearm : Output = Output::new(pg1, Level::High, Speed::Low); // <--- To keep the breaks not rearmed we send a 1, if we want to arm the breaks we send a 0
        let ch1 = PwmPin::new_ch1(pb8, OutputType::PushPull);
        let mut pwm = SimplePwm::new(ptime, Some(ch1), None, None, None, khz(30), Default::default());
        let mut braking_communication : Input = Input::new(pf12,Pull::None); // <--- If its HIGH it means that breaks are rearmed, if its low it , means we are breaking
        // Finally if we set the heartbeat to LOW, and we still receive a 1 is basically means we are crashing so lets actually make use of the crashing state
        pwm.enable(Channel::Ch1);
        let mut braking_controller = BrakingController {
            braking_rearm,
            braking_communication,
            brake_retraction: false,
        };

        unwrap!(x.spawn(run(braking_sender,pwm)));

        braking_controller
    }

    pub fn rearm_breaks(&mut self) -> bool{
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

    pub fn disarm_breaks(&mut self){
        self.braking_rearm.set_low();
        self.brake_retraction = true;
    }
    pub fn brake(&mut self){
        unsafe {BRAKE = true};
    }
}


