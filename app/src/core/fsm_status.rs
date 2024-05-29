#[derive(Debug, Default)]
pub struct Status {
    pub propulsion_ready: bool,
    pub levitation_ready: bool,
    pub hv_ready: bool,
    pub gs_connected: bool,
    pub hv_connected: bool,
    pub propulsion_connected: bool,
    pub levitation_connected: bool,
    pub hub_connected: bool,
    pub brakes_armed: bool,
    pub brakes_retracted: bool,
}

impl Status {}
