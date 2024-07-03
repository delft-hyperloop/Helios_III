use defmt::info;
use embassy_executor::Spawner;
use embassy_stm32::adc::Adc;
use embassy_stm32::gpio::Level;
use embassy_stm32::gpio::Output;
use embassy_stm32::gpio::Speed;
use embassy_stm32::peripherals;
use embassy_stm32::peripherals::ADC1;
use embassy_stm32::peripherals::PF12;
use embassy_stm32::peripherals::TIM16;
use embassy_time::Duration;
use embassy_time::Instant;
use embassy_time::Timer;

use crate::core::communication::Datapoint;
use crate::try_spawn;
use crate::DataSender;
use crate::Datatype;
use crate::Event;
use crate::EventSender;

pub static mut BRAKE: bool = false;

pub static mut ENABLE_BRAKING_COMM: bool = true;

pub struct BrakingController {
    pub braking_rearm: Output<'static>,
    pub data_sender: DataSender,
    pub brakes_extended: bool,
}

#[embassy_executor::task]
pub async fn control_braking_heartbeat(
    sender: EventSender,
    data_sender: DataSender,
    mut braking_signal: Output<'static>,
) {
    // pub async fn control_braking_heartbeat(sender: EventSender, mut braking_heartbeat: SimplePwm<'static, TIM16>) {
    info!("----------------- Start Braking Heartbeat! -----------------");
    let mut booting = true;
    let mut last_timestamp = Instant::now();
    loop {
        Timer::after_micros(10).await;
        // if adc.read(&mut pf12) > 30000 {
        //     braking_signal.set_low();
        //     // info!("------------ BRAKE ! ------------");
        // } else
        if unsafe { !BRAKE } {
            braking_signal.set_high();
            // braking_heartbeat.set_duty(Channel::Ch1, braking_heartbeat.get_max_duty()/2);
        } else {
            braking_signal.set_low();

            // braking_heartbeat.set_duty(Channel::Ch1, 0);
            // sender.send(Event::EmergencyBrakeCommand).await;
            // info!("------------ BRAKE ! ------------");
        }
        if booting {
            sender.send(Event::BootingCompleteEvent).await;
            booting = false;
        }
        if Instant::now().duration_since(last_timestamp) > Duration::from_millis(1000) {
            match braking_signal.get_output_level() {
                Level::Low => {
                    data_sender
                        .send(Datapoint::new(
                            Datatype::BrakingSignalDebug,
                            0,
                            Instant::now().as_ticks(),
                        ))
                        .await;
                }
                Level::High => {
                    data_sender
                        .send(Datapoint::new(
                            Datatype::BrakingSignalDebug,
                            1,
                            Instant::now().as_ticks(),
                        ))
                        .await;
                }
            }
            match unsafe { BRAKE } {
                true => {
                    data_sender
                        .send(Datapoint::new(
                            Datatype::BrakingBoolDebug,
                            1,
                            Instant::now().as_ticks(),
                        ))
                        .await;
                }
                false => {
                    data_sender
                        .send(Datapoint::new(
                            Datatype::BrakingBoolDebug,
                            0,
                            Instant::now().as_ticks(),
                        ))
                        .await;
                }
            }
            last_timestamp = Instant::now();
        }
    }
}

#[embassy_executor::task]
async fn read_braking_communication(
    event_sender: EventSender,
    data_sender: DataSender,
    mut adc: Adc<'static, ADC1>,
    mut pf12: PF12,
) {
    let mut edge = true; // only trigger brakes on falling edge
    let mut last_timestamp = Instant::now();
    loop {
        let v = adc.read(&mut pf12);
        let is_activated = v < 25000; // when braking comm goes low, someone else triggered brakes (eg big red button)
        if edge && is_activated {
            edge = false; // braking comm value is low, so we don't brake until it goes high again
            if unsafe { ENABLE_BRAKING_COMM } {
                event_sender.send(Event::EmergencyBrakeCommand).await;
            }
            Timer::after_millis(1000).await;
        }
        if !edge && !is_activated {
            // braking comm went high again
            edge = true;
        }
        Timer::after_micros(10).await;
        if Instant::now().duration_since(last_timestamp) > Duration::from_millis(500) {
            data_sender
                .send(Datapoint::new(
                    Datatype::BrakingCommDebug,
                    v as u64,
                    Instant::now().as_ticks(),
                ))
                .await;
            last_timestamp = Instant::now();
        }
    }
}

impl BrakingController {
    pub async fn new(
        x: &Spawner,
        braking_sender: EventSender,
        data_sender: DataSender,
        pb8: peripherals::PB8,
        pg1: peripherals::PG1,
        pf12: peripherals::PF12,
        adc: Adc<'static, ADC1>,
        _pb0: peripherals::PB0,
        _pd5: peripherals::PD5,
        _ptime: TIM16,
    ) -> Self {
        info!("breaking controller started");
        // If we want to keep it alive we send a 10khz digital clock signal
        let braking_rearm: Output = Output::new(pg1, Level::High, Speed::Low); // <--- To keep the breaks not rearmed we send a 1, if we want to arm the breaks we send a 0

        //let mut led: Output = Output::new(pb0, Level::High, Speed::Low);
        // let mut led2 : Output = Output::new(pd5,Level::High,Speed::Low);
        //led.set_high();
        //info!("set led on pb0 to high");
        // let mut pwm = SimplePwm::new(
        //     ptime,
        //     Some(PwmPin::new_ch1(pb8, OutputType::PushPull)),
        //     None,
        //     None,
        //     None,
        //     khz(30),
        //     Default::default(),
        // );
        // let braking_communication = Input::new(pf12, Pull::None); // <--- If its HIGH it means that breaks are rearmed, if its low it , means we are breaking
        // Finally if we set the heartbeat to LOW, and we still receive a 1 is basically means we are crashing so lets actually make use of the crashing state

        // let mut braking_communication = Adc::new();
        // braking_communication

        let braking_signal = Output::new(pb8, Level::High, Speed::Low);
        // pwm.enable(Channel::Ch1);

        try_spawn!(
            braking_sender,
            x.spawn(control_braking_heartbeat(
                braking_sender,
                data_sender,
                braking_signal,
            ))
        );

        try_spawn!(
            braking_sender,
            x.spawn(read_braking_communication(
                braking_sender,
                data_sender,
                adc,
                pf12
            ))
        );

        BrakingController {
            braking_rearm,
            data_sender,
            brakes_extended: false,
        }
    }

    pub async fn arm_breaks(&mut self) {
        self.braking_rearm.set_low();
        self.data_sender
            .send(Datapoint::new(
                Datatype::BrakingRearmDebug,
                0,
                Instant::now().as_ticks(),
            ))
            .await;
        Timer::after_micros(10).await;
        self.braking_rearm.set_high();
        self.data_sender
            .send(Datapoint::new(
                Datatype::BrakingRearmDebug,
                1,
                Instant::now().as_ticks(),
            ))
            .await;

        // let time_stamp = Instant::now();
        // while (Instant::now() - time_stamp) < Duration::from_millis(100) {
        //     if self.braking_communication.is_high() {
        //         self.brakes_extended = true;
        //         return true;
        //     }
        // }
        // false
    }

    #[allow(dead_code)]
    pub fn start_run_brake_precondition(&mut self) {
        // todo run this before any run
        self.braking_rearm.set_high();
        self.brakes_extended = false;
        unsafe { BRAKE = false };
    }
}
