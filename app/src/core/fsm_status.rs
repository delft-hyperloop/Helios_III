use core::sync::atomic::AtomicBool;
use core::sync::atomic::Ordering;

use embassy_time::Instant;

use crate::core::finite_state_machine::Fsm;
use crate::send_data;
use crate::Datatype;

// AtomicBool(s) for statuses
/// Whether we should extend the brakes
pub static mut BRAKE: bool = false;
/// Is main pcb and ground station connected
pub static CONNECTED: AtomicBool = AtomicBool::new(false);
/// Override for disabling whether braking_comm triggers emergency brake
pub static DISABLE_BRAKING_COMMUNICATION: AtomicBool = AtomicBool::new(false);
/// Whether the brakes are extended
pub static BRAKES_EXTENDED: AtomicBool = AtomicBool::new(true);
/// Levitation-read DC bus voltage > 50V, pod is not safe to touch (HV LED on)
pub static VOLTAGE_OVER_50: AtomicBool = AtomicBool::new(false);
/// If the sensor hub is connected (we are receiving values)
pub static HUB_CONNECTED: AtomicBool = AtomicBool::new(false);
/// Is propulsion connected? basically are we reading values cuz we've no other way of knowing
pub static PROPULSION_CONNECTED: AtomicBool = AtomicBool::new(false);
/// Is levitation connected (received from ground station)
pub static LEVITATION_CONNECTED: AtomicBool = AtomicBool::new(false);
/// Is the LV BMS alive and well, are we receiving values.
pub static LV_BATTERIES_CONNECTED: AtomicBool = AtomicBool::new(false);
/// Is the HV BMS alive and well, are we receiving values.
pub static HV_BATTERIES_CONNECTED: AtomicBool = AtomicBool::new(false);
/// Disable braking because of out-of-range values
pub static OUT_OF_RANGE_DISABLED: AtomicBool = AtomicBool::new(false);
/// frontend highlight the ls track
pub static IN_A_LANE_SWITCH: AtomicBool = AtomicBool::new(false);
pub static DISABLE_BRAKE_MOVING_NO_LOCALISATION: AtomicBool = AtomicBool::new(false);

pub static POD_IS_MOVING: AtomicBool = AtomicBool::new(false);

pub static mut LOCALISATION_LAST_SEEN: Instant = Instant::from_millis(0);

#[derive(Debug, Default)]
pub struct Status {
    pub overrides: Overrides,
    pub speeds_set: bool,
    pub route_set: bool,
    // pub hv_ready: bool, // todo: set this on from BMS data + check before turning on HV
    // pub hub_connected: bool, // todo: set this on from hub data + check before leaving idle
    pub brakes_armed: bool,
    pub levitating: bool,
    pub levi_connected: bool,
}

fn n(b: bool, p: u64) -> u64 {
    if b {
        1 << p
    } else {
        0
    }
}

impl Fsm {
    pub fn periodic_checks(&mut self) {
        if VOLTAGE_OVER_50.load(Ordering::Relaxed) {
            self.peripherals.led_controller.hv_led.set_high()
        } else {
            self.peripherals.led_controller.hv_led.set_low()
        }

        let mut value = 0;
        value |= n(CONNECTED.load(Ordering::Relaxed), 0);
        value |= n(PROPULSION_CONNECTED.load(Ordering::Relaxed), 1);
        value |= n(LEVITATION_CONNECTED.load(Ordering::Relaxed), 2);
        value |= n(HUB_CONNECTED.load(Ordering::Relaxed), 3);
        value |= n(LV_BATTERIES_CONNECTED.load(Ordering::Relaxed), 4);
        value |= n(HV_BATTERIES_CONNECTED.load(Ordering::Relaxed), 5);
        value |= n(BRAKES_EXTENDED.load(Ordering::Relaxed), 6);
        value |= n(VOLTAGE_OVER_50.load(Ordering::Relaxed), 7);
        value |= n(IN_A_LANE_SWITCH.load(Ordering::Relaxed), 8);
        send_data!(self.data_queue, Datatype::ConnectionStatus, value);
        PROPULSION_CONNECTED.store(false, Ordering::Relaxed);
        HUB_CONNECTED.store(false, Ordering::Relaxed);
        LV_BATTERIES_CONNECTED.store(false, Ordering::Relaxed);
        HV_BATTERIES_CONNECTED.store(false, Ordering::Relaxed);
    }
}

/// Some overrides that can be set to change the behavior of the fsm
/// # Values
/// since this is a sequence of booleans, for easy setting from the ground station,
/// the values are stored in u64. The bits are as follows:
/// * [0] propulsion_without_levitation
/// * [1] prevent_braking_communication
#[derive(Debug, Default)]
pub struct Overrides {
    pub values: u64,
}

impl Overrides {
    pub fn set(&mut self, value: u64) {
        self.values = value;
        DISABLE_BRAKING_COMMUNICATION
            .store(self.prevent_braking_communication(), Ordering::Relaxed);
        OUT_OF_RANGE_DISABLED.store(self.out_of_range_disabled(), Ordering::Relaxed);
        DISABLE_BRAKE_MOVING_NO_LOCALISATION
            .store(self.disable_brake_moving_without_location(), Ordering::Relaxed);
    }

    /// Allow propulsion to start while not levitating
    pub fn propulsion_without_levitation(&self) -> bool { self.values & 0b1 != 0 }

    /// Enable or disable braking from a falling edge of the braking communication signal
    pub fn prevent_braking_communication(&self) -> bool { self.values & 0b10 != 0 }

    /// Allow HV ON without brakes armed
    pub fn hv_without_brakes_armed(&self) -> bool { self.values & 0b100 != 0 }

    pub fn run_without_configure(&self) -> bool { self.values & 0b1000 != 0 }

    pub fn hv_without_levi(&self) -> bool { self.values & 0b10000 != 0 }

    pub fn out_of_range_disabled(&self) -> bool { self.values & 0b100000 != 0 }

    pub fn disable_brake_moving_without_location(&self) -> bool { self.values & 0b1000000 != 0 }
}

include!("../../../util/src/shared/routes.rs");
