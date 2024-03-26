use defmt::{info, unwrap};
use embassy_executor::Spawner;
use embassy_stm32::gpio::{Input, Level, Output, Pull, Speed};
use embassy_stm32::{Peripherals, peripherals};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::Sender;
use embassy_time::{Duration, Instant, Timer};
use heapless::binary_heap::Max;
use crate::core::finite_state_machine::Event;

static mut BRAKE: bool = false;

pub struct BrakingController {
    pub braking_rearm: Output<'static>,
    pub braking_communication: Input<'static>,
    pub brake_retraction:bool,
}

#[embassy_executor::task]
pub async fn run(sender: Sender<'static,NoopRawMutex,Event,Max,16>, mut braking_heartbeat: Output<'static>) {
    info!("------------ Start Braking Heartbeat! ------------");
    let mut booting =  true;
    loop {
        if unsafe {!BRAKE} {
            braking_heartbeat.set_high();
            // info!("------------ Start Braking Heartbeat! ------------");
            Timer::after_micros(100).await;
            braking_heartbeat.set_low();
            // info!("Test");
            Timer::after_micros(100).await;
        }
        else {
            braking_heartbeat.set_low();
        }
        if booting {
            sender.send(Event::BootingCompleteEvent).await;
            //   sender.send(Event::EmergencyBrakeCommand).await;
            booting = false;
        }

    }
    // let mut event_queue: PriorityChannel<NoopRawMutex,Event,Max,16>=PriorityChannel::new()
    info!("------------ Braking ended; someone fucked up... ------------");
}

impl BrakingController {
    pub fn new(x: &Spawner, braking_sender: Sender<'static,NoopRawMutex,Event,Max, { crate::EVENT_QUEUE_SIZE }>, pb8: peripherals::PB8, pg1: peripherals::PG1, pf12: peripherals::PF12) -> Self {
        let braking_heartbeat : Output = Output::new(pb8, Level::High, Speed::Low); // <--- If we want to break we set this to low
        // If we want to keep it alive we send a 10khz digital clock signal
        let mut braking_rearm : Output = Output::new(pg1, Level::High, Speed::Low); // <--- To keep the breaks not rearmed we send a 1, if we want to arm the breaks we send a 0

        let mut braking_communication : Input = Input::new(pf12,Pull::None); // <--- If its HIGH it means that breaks are rearmed, if its low it , means we are breaking
        // Finally if we set the heartbeat to LOW, and we still receive a 1 is basically means we are crashing so lets actually make use of the crashing state

        let mut braking_controller = BrakingController {
            braking_rearm,
            braking_communication,
            brake_retraction: false,
        };

        unwrap!(x.spawn(run(braking_sender,braking_heartbeat)));

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
}


