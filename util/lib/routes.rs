/// The 5 locations on the track.
pub enum Location {
    StraightStart = 0b001,
    LaneSwitchStraight = 0b010,
    LaneSwitchCurved = 0b011,
    StraightEndTrack = 0b100,
    LaneSwitchEndTrack = 0b101,
}

pub trait RoutePlan {
    fn from_u64(value: u64) -> Self;
    fn as_u64(&self) -> u64;
}