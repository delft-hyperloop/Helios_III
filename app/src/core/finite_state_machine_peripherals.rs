use defmt::{info, unwrap};
use embassy_executor::Spawner;
use embassy_stm32::flash::Error::Size;
use embassy_stm32::gpio::{Level, Output, Speed, Input, Pull};
use embassy_stm32::{bind_interrupts, can, Peripheral, Peripherals, peripherals};
use embassy_stm32::gpio::low_level::Pin;
use embassy_stm32::peripherals::{FDCAN1, FDCAN2};
use embassy_sync::blocking_mutex::raw::{NoopRawMutex, RawMutex, ThreadModeRawMutex};
use embassy_sync::mutex::Mutex;
use embassy_sync::priority_channel::Sender;
use embassy_time::{Duration, Instant, Timer};
use heapless::binary_heap::Max;
use crate::core::finite_state_machine::{Event, FSM};
static mut BRAKE: bool = false;
pub struct FSMPeripherals {
    // pub braking_heartbeat: Output<'static>,
    pub braking_rearm: Output<'static>,
   pub braking_communication: Input<'static>,
    pub brake_retraction:bool,
    pub hvcontroller: HVController,
    // pub peripherals: Peripherals,
}

/// Kiko: Im assuming this is needed and ill not worry about it
bind_interrupts!(struct CanOneInterrupts {
    FDCAN1_IT0 => can::IT0InterruptHandler<FDCAN1>;
    FDCAN1_IT1 => can::IT1InterruptHandler<FDCAN1>;
});
bind_interrupts!(struct CanTwoInterrupts {
    FDCAN2_IT0 => can::IT0InterruptHandler<FDCAN2>;
    FDCAN2_IT1 => can::IT1InterruptHandler<FDCAN2>;
});
impl FSMPeripherals{
    pub fn new(p : Peripherals, x: &Spawner, s : Sender<'static,NoopRawMutex,Event,Max,16>) -> Self {

        //CAN configuration
        //After this we will pass each one to their own task
        let mut can1 = can::FdcanConfigurator::new(p.FDCAN1, p.PD0, p.PD1,CanOneInterrupts);

        let mut can2 = can::FdcanConfigurator::new(p.FDCAN2, p.PB5, p.PB6,CanTwoInterrupts); // <--- Im not really sure if this are the correct pins

        can1.set_bitrate(1_000_000);
        can2.set_bitrate(1_000_000);

        let mut can1 = can1.into_normal_mode();
        let mut can2 = can2.into_normal_mode();

        let mut braking_heartbeat : Output = Output::new(p.PB8, Level::High, Speed::Low); // <--- If we want to break we set this to to low
                                                                                 // If we want to keep it alive we send a 10khz digital clock signal
        let mut braking_rearm : Output = Output::new(p.PG1, Level::High, Speed::Low); // <--- To keep the breaks not rearmed we send a 1, if we want to arm the breaks we send a 0

        let mut braking_communication : Input = Input::new(p.PF12,Pull::None); // <--- If its HIGH it means that breaks are rearmed, if its low it , means we are breaking
        // Finally if we set the heartbeat to LOW, and we still recieve a 1 is basically means we are crashing so lets actually make use of the crashing state

        unwrap!(x.spawn(braking_pcb_heartbeat(s,braking_heartbeat)));

        let mut brake_retraction = false;

        let mut hvcontroller = HVController::new();



        Self {
            // braking_heartbeat,
            braking_rearm,
            braking_communication,
            brake_retraction,
            hvcontroller,

        }
    }
    pub fn rearm_breaks(&mut self) -> bool{
        self.braking_rearm.set_high();
        let time_stamp = Instant::now();
        while (Instant::now() - time_stamp) < Duration::from_millis(100) {
            if (self.braking_communication.is_high()){
                self.brake_retraction = true;
                return true;
            }
        }
        return false;

    }
    pub fn unarm_breaks(&mut self){
        self.braking_rearm.set_low();
        self.brake_retraction = true;
    }

}
#[embassy_executor::task]
pub async fn braking_pcb_heartbeat(sender: Sender<'static,NoopRawMutex,Event,Max,16>, mut braking_heartbeat: Output<'static>) {
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
        if (booting){
            sender.send(Event::BootingCompleteEvent).await;
         //   sender.send(Event::EmergencyBrakeCommand).await;
            booting = false;
        }

    }
    // let mut event_queue: PriorityChannel<NoopRawMutex,Event,Max,16>=PriorityChannel::new()
    info!("------------ Test Task Ended! ------------");
}

pub struct HVController{
    pub propulsion_ready : bool,
    pub levitation_ready : bool,
    pub powertrain_ready : bool,
}

impl HVController {

    pub fn new() -> Self {
        Self {
            propulsion_ready : false,
            levitation_ready : false,
            powertrain_ready : false,
        }
    }
    pub fn check_propulsion(&mut self) -> bool {
        self.propulsion_ready = true;
        return true;
    }
    pub fn check_levitation(&mut self) -> bool {
        self.levitation_ready = true;
        return true;
    }
    pub fn check_powertrain(&mut self) -> bool {
        self.powertrain_ready = true;
        return true;
    }
    pub fn check_all(&mut self) -> bool {
        if (self.propulsion_ready && self.levitation_ready && self.powertrain_ready){
            return true;
        }
        else {
            return false;
        }
    }
    pub fn reset(&mut self){
        self.propulsion_ready = false;
        self.levitation_ready = false;
        self.powertrain_ready = false;
    }
}