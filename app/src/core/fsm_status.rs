
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

// pub trait RouteUse {
//     fn next_position(&mut self) -> Location;
//     fn current_position(&self) -> Location;
//     fn speed_at(&self, location: Location) -> u8;
//     fn from_plan(plan: &impl RoutePlan) -> Self;
// }
//
// pub struct Route {
//     pub positions: heapless::Vec<Location, 8>,
//     pub current_position: usize,
//     pub speeds: heapless::LinearMap<Location, u8, 5>
// }
//
// impl From<u64> for Route {
//     fn from(value: u64) -> Self {
//         let mut speeds = heapless::LinearMap::new();
//         let mut positions = heapless::Vec::new();
//
//         let bytes: [u8; 8] = value.to_be_bytes();
//
//         let _ = speeds.insert(Location::StraightStart, bytes[3]);
//         let _ = speeds.insert(Location::LaneSwitchStraight, bytes[4]);
//         let _ = speeds.insert(Location::LaneSwitchCurved, bytes[5]);
//         let _ = speeds.insert(Location::StraightEndTrack, bytes[6]);
//         let _ = speeds.insert(Location::LaneSwitchEndTrack, bytes[7]);
//
//         Route {
//             positions,
//             current_position: 0,
//             speeds
//         }
//     }
// }
//
// // pub trait State {
// //     fn entry(&mut self);
// //
// //     fn check_conditions(&mut self) -> bool;
// //
// //     async fn react(&mut self, event: crate::Event);
// // }
