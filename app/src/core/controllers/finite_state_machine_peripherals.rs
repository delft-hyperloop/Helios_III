use defmt::{info, unwrap};
use embassy_executor::Spawner;
use embassy_stm32::flash::Error::Size;
use embassy_stm32::gpio::{Level, Output, Speed, Input, Pull};
use embassy_stm32::{Peripheral, Peripherals, peripherals};
use embassy_stm32::gpio::low_level::Pin;
use embassy_sync::blocking_mutex::raw::{NoopRawMutex, RawMutex, ThreadModeRawMutex};
use embassy_sync::mutex::Mutex;
use embassy_sync::priority_channel::{PriorityChannel, Sender};
use embassy_time::{Duration, Instant, Timer};
use heapless::binary_heap::Max;
use crate::core::controllers::breaking_controller::BrakingController;
use crate::core::controllers::ethernet_controller::{EthernetController, EthernetPins};
use crate::core::controllers::hv_controller::HVController;
use crate::core::finite_state_machine::{Event, FSM};
use crate::{DataReceiver, EventSender};


pub struct FSMPeripherals {
    pub braking_controller: BrakingController,
    pub hv_controller: HVController,
    pub eth_controller: EthernetController,
}

// pub(crate) struct PInit {
//     pub p: Peripherals,
//     pub x: &'static Spawner,
//     pub q: &'static PriorityChannel<NoopRawMutex, Event, Max, 16>
// }

impl FSMPeripherals{
    // pub fn new(p : Peripherals, x: &Spawner, q : &PriorityChannel<NoopRawMutex, Event, Max, 16>) -> Self {
    pub fn new(p : Peripherals, x: &Spawner, s : EventSender, r: DataReceiver) -> Self {
        // let mut init = PInit{p,x,q};
        // let (braking_controller, init) = BrakingController::new(init);
        let braking_controller = BrakingController::new(x, s.clone(), p.PB8, p.PG1, p.PF12);

        let mut hv_controller = HVController::new(x, s.clone());

        let mut eth_controller = EthernetController::new(*x, s.clone(), r.clone(),EthernetPins{
            p_rng: p.RNG,
            eth_pin: p.ETH,
            pg11_pin: p.PG11,
            pb13_pin: p.PB13,
            pg13_pin: p.PG13,
            pc5_pin: p.PC5,
            pc4_pin: p.PC4,
            pa7_pin: p.PA7,
            pc1_pin: p.PC1,
            pa2_pin: p.PA2,
            pa1_pin: p.PA1,
        });

        let mut can_controller = CanController::new(*x,
                                                    i.event_sender.clone(),
                                                    i.data_sender.clone(),
                                                    i.data_receiver.clone(),
                                                    i.can_one_sender.clone(),
                                                    i.can_one_receiver.clone(),
                                                    i.can_two_sender.clone(),
                                                    i.can_two_receiver.clone(),
        CanPins {
            fdcan1: p.FDCAN1,
            fdcan2: p.FDCAN2,
            pd0_pin: p.PD0,
            pd1_pin: p.PD1,
            pb5_pin: p.PB5,
            pb6_pin: p.PB6,
        });

        let mut battery_controller = BatteryController::new(*x, i.event_sender.clone());

        Self {
            braking_controller,
            hv_controller,
            eth_controller,
        }
    }


}
