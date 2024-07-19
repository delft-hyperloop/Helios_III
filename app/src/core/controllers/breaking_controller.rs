use core::sync::atomic::Ordering;

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

use crate::core::fsm_status::BRAKE;
use crate::core::fsm_status::BRAKES_EXTENDED;
use crate::core::fsm_status::DISABLE_BRAKING_COMMUNICATION;
use crate::pconfig::queue_event;
use crate::send_data;
use crate::try_spawn;
use crate::DataSender;
use crate::Datatype;
use crate::Event;
use crate::EventSender;
use crate::Info;

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
    info!("----------------- Start Braking Heartbeat! -----------------");
    let mut booting = true;
    let mut last_timestamp = Instant::now();
    loop {
        Timer::after_micros(10).await;
        if unsafe { !BRAKE } {
            braking_signal.set_high();
        } else {
            braking_signal.set_low();
        }
        if booting {
            sender.send(Event::BootingCompleteEvent).await;
            booting = false;
        }
        if Instant::now().duration_since(last_timestamp) > Duration::from_millis(1000) {
            match braking_signal.get_output_level() {
                Level::Low => send_data!(data_sender, Datatype::BrakingSignalDebug, 0; 5000),
                Level::High => send_data!(data_sender, Datatype::BrakingSignalDebug, 1; 5000),
            }
            match unsafe { BRAKE } {
                true => send_data!(data_sender, Datatype::BrakingBoolDebug, 1; 5000),
                false => send_data!(data_sender, Datatype::BrakingBoolDebug, 0; 5000),
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
            if !DISABLE_BRAKING_COMMUNICATION.load(Ordering::Relaxed) {
                queue_event(event_sender, Event::EmergencyBraking).await;
                send_data!(data_sender, Datatype::Info, Info::BrakingCommunicationTriggered as u64);
            }
            BRAKES_EXTENDED.store(true, Ordering::Relaxed);
            Timer::after_millis(1000).await;
        }
        if !edge && !is_activated {
            // braking comm went high again
            edge = true;
            BRAKES_EXTENDED.store(false, Ordering::Relaxed);
        }
        Timer::after_micros(100).await;
        if Instant::now().duration_since(last_timestamp) > Duration::from_millis(500) {
            send_data!(data_sender, Datatype::BrakingCommDebug, v as u64);
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
        pd5: peripherals::PD5,
        _ptime: TIM16,
    ) -> Self {
        info!("breaking controller started");
        // If we want to keep it alive we send a 10khz digital clock signal
        let braking_rearm: Output = Output::new(pg1, Level::High, Speed::Low); // <--- To keep the breaks not rearmed we send a 1, if we want to arm the breaks we send a 0

        let braking_signal = Output::new(pb8, Level::High, Speed::Low);

        // VGA ground
        let _ = Output::new(pd5, Level::Low, Speed::Low);

        try_spawn!(
            braking_sender,
            x.spawn(control_braking_heartbeat(braking_sender, data_sender, braking_signal,))
        );

        try_spawn!(
            braking_sender,
            x.spawn(read_braking_communication(braking_sender, data_sender, adc, pf12))
        );

        BrakingController { braking_rearm, data_sender, brakes_extended: false }
    }

    pub async fn arm_breaks(&mut self) {
        self.braking_rearm.set_low();
        send_data!(self.data_sender, Datatype::BrakingRearmDebug, 0);
        Timer::after_micros(50).await; // braking pcb only takes an instant to rearm the brakes
        self.braking_rearm.set_high();
        send_data!(self.data_sender, Datatype::BrakingRearmDebug, 1);
    }

    #[allow(dead_code)]
    pub fn start_run_brake_precondition(&mut self) {
        // todo run this before any run
        self.braking_rearm.set_high();
        self.brakes_extended = false;
        unsafe { BRAKE = false };
    }
}
