use embassy_executor::Spawner;
use embassy_stm32::gpio::Level;
use embassy_stm32::gpio::Output;
use embassy_stm32::gpio::Speed;
use embassy_stm32::Peripherals;
use crate::core::controllers::battery_controller::BatteryController;
use crate::core::controllers::breaking_controller::BrakingController;
use crate::core::controllers::can_controller::CanController;
use crate::core::controllers::can_controller::CanPins;
use crate::core::controllers::ethernet_controller::EthernetController;
use crate::core::controllers::ethernet_controller::EthernetPins;
use crate::core::controllers::hv_controller::HVPeripherals;
use crate::core::controllers::propulsion_controller::PropulsionController;
use crate::InternalMessaging;

#[allow(dead_code)]
pub struct FSMPeripherals {
    pub braking_controller: BrakingController,
    pub eth_controller: EthernetController,
    pub can_controller: CanController,
    pub hv_peripherals: HVPeripherals,
    //  pub lv_controller: BatteryController,
    pub red_led: Output<'static>,
}

impl FSMPeripherals {
    // pub fn new(p : Peripherals, x: &Spawner, q : &PriorityChannel<NoopRawMutex, Event, Max, 16>) -> Self {
    pub async fn new(p: Peripherals, x: &Spawner, i: InternalMessaging) -> Self {
        // let mut init = PInit{p,x,q};
        // let (braking_controller, init) = BrakingController::new(init);

        // The braking controller is responsible for rearming the braked
        let braking_controller = BrakingController::new(
            x,
            i.event_sender,
            p.PB8,
            p.PG1,
            p.PF12,
            p.PB0,
            p.PD5,
            p.TIM16,
        )
        .await;


        defmt::debug!("creating hv controller");
        // the battery controllers contain functions related to interpreting the BMS CAN messages
        let hv_controller =
            BatteryController::new(i.event_sender, 0, 0, 0, 0, 0, i.data_sender, true); //TODO <------ This is just to make it build
        defmt::debug!("creating lv controller");
        let lv_controller =
            BatteryController::new(i.event_sender, 0, 0, 0, 0, 0, i.data_sender, false); //TODO <------ This is just to make it build


        defmt::debug!("creating ethernet controller");
        // The ethernet controller configures IP and then spawns the ethernet task
        let eth_controller = EthernetController::new(
            *x,
            i.event_sender,
            i.data_receiver,
            EthernetPins {
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
            },
        ).await;

        // let mut b = Output::new(p.PB0, Level::High, Speed::High);
        // b.set_high();

        defmt::debug!("creating can controller");
        // the can controller configures both buses and then spawns all 4 read/write tasks.
        let can_controller = CanController::new(
            *x,
            i.event_sender,
            i.data_sender,
            i.data_receiver,
            i.can_one_sender,
            i.can_one_receiver,
            i.can_two_sender,
            i.can_two_receiver,
            CanPins {
                fdcan1: p.FDCAN1,
                fdcan2: p.FDCAN2,
                pd0_pin: p.PD0,
                pd1_pin: p.PD1,
                pb5_pin: p.PB5,
                pb6_pin: p.PB6,
            },
            hv_controller,
            lv_controller,
        )
        .await;


        // the propulsion controller spawns tasks for reading current and voltage, and holds functions for setting the speed through the DAC
        // let propulsion_controller = PropulsionController::new();

        defmt::debug!("peripherals initialised.");
        // return this struct back to the FSM
        Self {
            braking_controller,
            eth_controller,
            can_controller,
            hv_peripherals: HVPeripherals {
                pin_4: Output::new(p.PD3, Level::Low, Speed::Low),
                pin_6: Output::new(p.PG9, Level::Low, Speed::Low),
                pin_7: Output::new(p.PG10, Level::Low, Speed::Low),
            },
            red_led: Output::new(p.PB14, Level::Low, Speed::High),
        }
    }
}
