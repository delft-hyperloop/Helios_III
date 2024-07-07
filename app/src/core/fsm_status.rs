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

#[derive(Debug, Default)]
pub struct Overrides {
    pub propulsion_without_levitation: bool,
}

include!("../../../util/src/shared/routes.rs");
