
#[allow(unused, dead_code)]
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

include!("../../../util/src/shared/routes.rs");

//
// // pub trait State {
// //     fn entry(&mut self);
// //
// //     fn check_conditions(&mut self) -> bool;
// //
// //     async fn react(&mut self, event: crate::Event);
// // }
