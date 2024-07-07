use crate::core::controllers::breaking_controller::DISABLE_BRAKING_COMMUNICATION;

#[derive(Debug, Default)]
pub struct Status {
    pub overrides: Overrides,
    pub speeds_set: bool,
    pub route_set: bool,
    pub hv_ready: bool,
    pub hv_on: bool,
    pub hub_connected: bool,
    pub brakes_armed: bool,
    pub levitating: bool,
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
        unsafe {
            DISABLE_BRAKING_COMMUNICATION = self.prevent_braking_communication();
        }
    }

    /// Allow propulsion to start while not levitating
    pub fn propulsion_without_levitation(&self) -> bool { self.values & 0b1 != 0 }

    /// Enable or disable braking from a falling edge of the braking communication signal
    pub fn prevent_braking_communication(&self) -> bool { self.values & 0b10 != 0 }
}

include!("../../../util/src/shared/routes.rs");
