use defmt_rtt as _;
use embassy_executor::Spawner;
use embassy_stm32::can;
use embassy_stm32::peripherals::FDCAN1;
use embassy_stm32::peripherals::FDCAN2;
use embassy_stm32::peripherals::PB5;
use embassy_stm32::peripherals::PB6;
use embassy_stm32::peripherals::PD0;
use embassy_stm32::peripherals::PD1;
use panic_probe as _;

use crate::core::communication::can::can_receiving_handler;
use crate::core::communication::can::can_transmitter;
use crate::core::controllers::battery_controller::BatteryController;
use crate::core::controllers::battery_controller::GroundFaultDetection;
use crate::try_spawn;
use crate::CanOneInterrupts;
use crate::CanReceiver;
use crate::CanSender;
use crate::CanTwoInterrupts;
use crate::DataSender;
use crate::EventSender;

pub struct CanPins {
    pub fdcan1: FDCAN1,
    pub fdcan2: FDCAN2,
    pub pd0_pin: PD0,
    pub pd1_pin: PD1,
    pub pb5_pin: PB5,
    pub pb6_pin: PB6,
}

#[allow(dead_code)]
pub struct CanTwoUtils {
    pub can_sender: CanSender,
    pub hv_controller: BatteryController,
    pub lv_controller: BatteryController,
    pub gfd_controller: GroundFaultDetection,
}

pub struct CanController {}

impl CanController {
    pub async fn new(
        x: Spawner,
        event_sender: EventSender,
        data_sender: DataSender,
        _can_one_sender: CanSender,
        can_one_receiver: CanReceiver,
        can_two_sender: CanSender,
        can_two_receiver: CanReceiver,
        pins: CanPins,
        hv_controller: BatteryController,
        lv_controller: BatteryController,
    ) -> Self {
        let mut can1 =
            can::CanConfigurator::new(pins.fdcan1, pins.pd0_pin, pins.pd1_pin, CanOneInterrupts);

        let mut can2 = can::CanConfigurator::new(
            pins.fdcan2,
            pins.pb5_pin, /* pb5=can2 RX */
            pins.pb6_pin, /* pb6=can2 TX */
            CanTwoInterrupts,
        );
        can1.config().protocol_exception_handling = true;
        can2.config().protocol_exception_handling = false;

        can1.set_bitrate(1_000_000);
        can2.set_bitrate(500_000);

        let can1 = can1.into_normal_mode();
        let can2 = can2.into_normal_mode();

        let (mut c1_tx, c1_rx, _p1) = can1.split();
        let (c2_tx, c2_rx, _p2) = can2.split();
        c1_tx.write(&can::frame::Frame::new_standard(0x123, &[1, 2, 3, 4]).unwrap()).await;
        try_spawn!(
            event_sender,
            x.spawn(can_receiving_handler(
                x,
                event_sender,
                _can_one_sender,
                data_sender,
                c1_rx,
                None
            ))
        );
        try_spawn!(
            event_sender,
            x.spawn(can_receiving_handler(
                x,
                event_sender,
                can_two_sender,
                data_sender,
                c2_rx,
                Some(CanTwoUtils {
                    can_sender: can_two_sender,
                    hv_controller,
                    lv_controller,
                    gfd_controller: GroundFaultDetection {},
                })
            ))
        );

        try_spawn!(event_sender, x.spawn(can_transmitter(can_one_receiver, c1_tx)));
        try_spawn!(event_sender, x.spawn(can_transmitter(can_two_receiver, c2_tx)));

        Self {}
    }
}
