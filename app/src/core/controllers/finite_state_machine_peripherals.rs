use defmt::debug;
use embassy_executor::Spawner;
use embassy_stm32::adc::Adc;
use embassy_stm32::gpio::Input;
use embassy_stm32::gpio::Level;
use embassy_stm32::gpio::Output;
use embassy_stm32::gpio::Pull;
use embassy_stm32::gpio::Speed;
use embassy_stm32::Peripherals;
use embassy_time::Duration;
use embassy_time::Instant;

use crate::core::communication::low::tcp::EthernetPins;
use crate::core::controllers::battery_controller::BatteryController;
use crate::core::controllers::breaking_controller::BrakingController;
use crate::core::controllers::can_controller::CanController;
use crate::core::controllers::can_controller::CanPins;
use crate::core::controllers::external_communication::ExternalController;
use crate::core::controllers::hv_controller::HVPeripherals;
use crate::core::controllers::led_controller::LedController;
use crate::core::controllers::propulsion_controller::PropulsionController;
use crate::DataSender;
use crate::InternalMessaging;

#[allow(dead_code)]
pub struct FSMPeripherals {
    pub braking_controller: BrakingController,
    pub eth_controller: ExternalController,
    pub can_controller: CanController,
    pub hv_peripherals: HVPeripherals,
    pub propulsion_controller: PropulsionController,
    pub data_send_line: DataSender,
    pub red_led: Output<'static>,
    pub led_controller: LedController,
}

impl FSMPeripherals {
    pub async fn new(p: Peripherals, x: &Spawner, i: InternalMessaging) -> Self {
        // set to high impedance, since there's a 24V signal being given and this would fry the PCB
        let _ = Input::new(p.PD4, Pull::None);

        // The braking controller is responsible for rearming the braked
        let braking_controller = BrakingController::new(
            x,
            i.event_sender,
            i.data_sender,
            p.PB8,
            p.PG1,
            p.PF12,
            Adc::new(p.ADC1),
            p.PB0,
            p.PD5,
            p.TIM16,
        )
        .await;

        debug!("creating hv controller");
        // the battery controllers contain functions related to interpreting the `BMS CAN` messages
        let hv_controller = BatteryController::new(i.data_sender, true);
        debug!("creating lv controller");
        let lv_controller = BatteryController::new(i.data_sender, false);

        debug!("creating ethernet controller");
        // The ethernet controller configures IP and then spawns the ethernet task
        let eth_controller = ExternalController::new(
            *x,
            i.event_sender,
            i.data_receiver,
            i.data_sender,
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
        )
        .await;

        debug!("creating can controller");
        // the can controller configures both buses and then spawns all 4 read/write tasks.
        let can_controller = CanController::new(
            *x,
            i.event_sender,
            i.data_sender,
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
        let led_controller =
            LedController::new(p.PE7, p.PE8, p.PE9, p.PE10, p.PE11, p.PE13, p.PE14).await;

        // the propulsion controller spawns tasks for reading current and voltage, and holds functions for setting the speed through the DAC
        let propulsion_controller = PropulsionController::new(
            *x,
            i.data_sender,
            i.event_sender,
            p.PA4,
            p.DAC1,
            p.ADC2,
            p.PA5,
            p.PA6,
            p.PB1,
        )
        .await;

        debug!("peripherals initialised.");
        // return this struct back to the FSM
        Self {
            data_send_line: i.data_sender,
            braking_controller,
            eth_controller,
            can_controller,
            hv_peripherals: HVPeripherals {
                pin_4: Output::new(p.PD3, Level::Low, Speed::Low),
                pin_6: Output::new(p.PG9, Level::Low, Speed::Low),
                pin_7: Output::new(p.PG10, Level::Low, Speed::Low),
                dc_dc: Output::new(p.PD2, Level::Low, Speed::Low),
                pre_charge_start: Instant::now(),
                pre_charge_min: Duration::from_millis(3500),
                // pre_charge_timeout: Duration::from_millis(5000),
                // event_sender: i.event_sender,
                pre_charge_successful: false,
            },
            red_led: Output::new(p.PB14, Level::Low, Speed::High),
            propulsion_controller,
            led_controller,
        }
    }
}
