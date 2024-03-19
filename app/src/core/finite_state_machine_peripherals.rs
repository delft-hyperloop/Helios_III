use defmt::{info, unwrap};
use embassy_executor::Spawner;
use embassy_stm32::flash::Error::Size;
use embassy_stm32::gpio::{Level, Output, Speed, Input, Pull};
use embassy_stm32::{Peripheral, Peripherals,peripherals};
use embassy_stm32::gpio::low_level::Pin;
use embassy_sync::blocking_mutex::raw::{NoopRawMutex, RawMutex, ThreadModeRawMutex};
use embassy_sync::mutex::Mutex;
use embassy_sync::priority_channel::Sender;
use embassy_time::{Duration, Timer};
use heapless::binary_heap::Max;
use crate::core::finite_state_machine::{Event, FSM};
static mut BRAKE: bool = false;
pub struct FSMPeripherals {
    // pub braking_heartbeat: Output<'static>,
    pub braking_rearm: Output<'static>,
    pub braking_communication: Input<'static>,
    // pub brake_retraction:bool,
    // pub peripherals: Peripherals,
}


impl FSMPeripherals{
    pub fn new(p : Peripherals, x: &Spawner, s : Sender<'static,NoopRawMutex,Event,Max,16>) -> Self {



        let mut braking_heartbeat : Output = Output::new(p.PB8, Level::High, Speed::Low); // <--- If we want to break we set this to to low
                                                                                 // If we want to keep it alive we send a 10khz digital clock signal
        let mut braking_rearm : Output = Output::new(p.PG1, Level::High, Speed::Low); // <--- To keep the breaks not rearmed we send a 1, if we want to arm the breaks we send a 0

        let mut braking_communication : Input = Input::new(p.PF12,Pull::None); // <--- If its HIGH it means that breaks are rearmed, if its low it , means we are breaking
        // Finally if we set the heartbeat to LOW, and we still recieve a 1 is basically means we are crashing so lets actually make use of the crashing state

        unwrap!(x.spawn(braking_pcb_heartbeat(s,braking_heartbeat)));

        let mut brake_retraction = false;
        Self {
            // braking_heartbeat,
            braking_rearm,
            braking_communication,

        }
    }
    pub fn rearm_breaks(&mut self) -> bool{
        self.braking_rearm.set_high();
        return if self.braking_communication.is_high() {
            true
        } else {
            false
        }
    }

    // pub fn spawn_heartbeat(&self, sender: Sender<'static,NoopRawMutex,Event,Max,16>, spawner: &Spawner) {
    //     let mut b = self.
    //     unwrap!(spawner.spawn(braking_pcb_heartbeat(sender,self.braking_heartbeat, self.braking_communication)));
    // }


}
#[embassy_executor::task]
pub async fn braking_pcb_heartbeat(sender: Sender<'static,NoopRawMutex,Event,Max,16>, mut braking_heartbeat: Output<'static>) {
    info!("------------ Start Braking Heartbeat! ------------");
    let mut booting =  false;
    loop {
        if unsafe {!BRAKE} {
            braking_heartbeat.set_high();
            Timer::after(Duration::from_micros(100)).await;
            braking_heartbeat.set_low();
            Timer::after(Duration::from_micros(100)).await;
        }
        else {
            braking_heartbeat.set_low();
            // if p.braking_communication.is_high() {
            //     unsafe {BRAKE = false;
            //     }
            //     sender.send(Event::DefaultEvent).await;  // <--- We are fucked here because it means the breaks decided not to break
            // }
        }
        if (booting){
            sender.send(Event::BootingCompleteEvent).await;
            booting = false;
        }

    }
    // let mut event_queue: PriorityChannel<NoopRawMutex,Event,Max,16>=PriorityChannel::new()
    info!("------------ Test Task Ended! ------------");
}

