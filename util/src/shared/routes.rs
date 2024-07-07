// use embassy_stm32::gpio::Speed;
#[cfg(target_os = "none")]
use heapless::LinearMap;

#[cfg(target_os = "none")]
#[derive(PartialEq, Eq, Debug, Clone)]
pub struct LocationSpeedMap(LinearMap<Location, u8, 10>);

#[cfg(not(target_os = "none"))]
#[derive(PartialEq, Eq, PartialOrd, Ord, Debug, Clone)]
pub struct LocationSpeedMap(std::collections::BTreeMap<Location, u8>);

#[derive(PartialEq, Eq, PartialOrd, Ord, Debug, Clone, Copy)]
pub struct LocationSequence([Location; 16]);

#[allow(dead_code)]
pub trait RouteUse {
    /// Transition to the next position from the plan
    fn next_position(&mut self) -> Location;

    /// Get what the current position is
    fn current_position(&self) -> Location;

    /// Get the speed for a specific location
    fn speed_at(&self, location: Location) -> u8;

    /// Get what the speed should be currently set to.
    fn current_speed(&self) -> u8;

    /// Get the next position without transitioning
    fn peek_next_position(&mut self) -> Location;
}

#[derive(Debug, Clone, PartialEq, Eq, PartialOrd, Copy, Ord)]
#[cfg_attr(target_os = "none", derive(defmt::Format))]
pub enum Location {
    ForwardA = 0b0001,
    BackwardsA = 0b0011,
    ForwardB = 0b0100,
    BackwardsB = 0b0101,
    ForwardC = 0b0111,
    BackwardsC = 0b1000,
    LaneSwitchStraight = 0b1001,
    LaneSwitchCurved = 0b1010,
    StopAndWait = 0b1011,
    BrakeHere = 0b0000, // no next position, just stop here.
}

#[derive(Debug, PartialEq, Eq, Default)]
pub struct Route {
    pub positions: LocationSequence,
    pub current_position: usize,
    pub speeds: LocationSpeedMap,
}

#[cfg(target_os = "none")]
impl defmt::Format for Route {
    fn format(&self, fmt: defmt::Formatter) {
        defmt::write!(fmt, "Route {{\n");
        for l in self.positions.into_iter() {
            defmt::write!(fmt, " -> {}", l);
        }
        defmt::write!(fmt, "\n currently at: {}\n", self.current_position);
        defmt::write!(fmt, " Speeds: \n");
        for (key, value) in self.speeds.0.into_iter() {
            defmt::write!(fmt, "  {}: {}\n", key, value);
        }
        defmt::write!(fmt, "}}");
    }
}

impl Route {
    pub fn speeds_from(&mut self, val: u64) { self.speeds = LocationSpeedMap::from(val); }

    pub fn positions_from(&mut self, val: u64) { self.positions = LocationSequence::from(val); }
}

impl From<Route> for (u64, u64) {
    fn from(_r: Route) -> Self { todo!() }
}

impl From<LocationSequence> for u64 {
    fn from(val: LocationSequence) -> Self {
        let mut bit_seq: u64 = 0;

        // Encode the positions as a 63-bit integer
        for (i, location) in val.0.iter().enumerate() {
            let location_bits = *location as u64;
            bit_seq |= location_bits << (3 * (20 - i));
        }

        bit_seq
    }
}

impl From<u64> for LocationSequence {
    fn from(val: u64) -> Self { LocationSequence(parse_locations(val)) }
}

impl From<u64> for LocationSpeedMap {
    fn from(val: u64) -> Self {
        let mut speeds = LocationSpeedMap::default();
        let bytes: [u8; 8] = val.to_be_bytes();

        let _ = (
            speeds.0.insert(Location::ForwardA, bytes[0]),
            speeds.0.insert(Location::BackwardsA, bytes[1]),
            speeds.0.insert(Location::ForwardB, bytes[2]),
            speeds.0.insert(Location::BackwardsB, bytes[3]),
            speeds.0.insert(Location::ForwardC, bytes[4]),
            speeds.0.insert(Location::BackwardsC, bytes[5]),
            speeds.0.insert(Location::LaneSwitchStraight, bytes[6]),
            speeds.0.insert(Location::LaneSwitchCurved, bytes[7]),
            speeds.0.insert(Location::StopAndWait, 0),
            speeds.0.insert(Location::BrakeHere, 0),
        );

        speeds
    }
}

impl From<LocationSpeedMap> for u64 {
    fn from(val: LocationSpeedMap) -> Self {
        let mut result: u64 = 0;

        // Insert speed data into the remaining bytes
        result |= *val.0.get(&Location::ForwardA).unwrap_or(&0) as u64;
        result <<= 8;
        result |= *val.0.get(&Location::BackwardsA).unwrap_or(&0) as u64;
        result <<= 8;
        result |= *val.0.get(&Location::ForwardB).unwrap_or(&0) as u64;
        result <<= 8;
        result |= *val.0.get(&Location::BackwardsB).unwrap_or(&0) as u64;
        result <<= 8;
        result |= *val.0.get(&Location::ForwardC).unwrap_or(&0) as u64;
        result <<= 8;
        result |= *val.0.get(&Location::BackwardsC).unwrap_or(&0) as u64;
        result <<= 8;
        result |= *val.0.get(&Location::LaneSwitchStraight).unwrap_or(&0) as u64;
        result <<= 8;
        result |= *val.0.get(&Location::LaneSwitchCurved).unwrap_or(&0) as u64;

        result
    }
}

fn parse_locations(bytes: u64) -> [Location; 16] {
    let mut locations = [Location::BrakeHere; 16];
    // let mut bit_seq: u32 = ((bytes[2] as u32) << 16) | ((bytes[1] as u32) << 8) | (bytes[0] as u32);
    let mut bit_seq = bytes;
    for i in 0..=20 {
        let bits = (bit_seq & 0b111) as u8;
        bit_seq >>= 3;
        locations[15 - i] = match bits {
            0b0001 => Location::ForwardA,
            0b0011 => Location::BackwardsA,
            0b0100 => Location::ForwardB,
            0b0101 => Location::BackwardsB,
            0b0111 => Location::ForwardC,
            0b1000 => Location::BackwardsC,
            0b1001 => Location::LaneSwitchStraight,
            0b1010 => Location::LaneSwitchCurved,
            0b1011 => Location::StopAndWait,
            _ => Location::BrakeHere,
        };
    }

    locations
}

impl RouteUse for Route {
    fn next_position(&mut self) -> Location {
        if self.current_position >= 15 {
            Location::BrakeHere
        } else {
            self.current_position += 1;
            self.positions.0[self.current_position]
        }
    }

    fn current_position(&self) -> Location {
        if self.current_position > 20 {
            Location::BrakeHere
        } else {
            self.positions.0[self.current_position]
        }
    }

    fn speed_at(&self, location: Location) -> u8 {
        if let Some(speed) = self.speeds.0.get(&location) {
            *speed
        } else {
            #[cfg(target_os = "none")]
            defmt::error!("Tried to get speed for invalid location");
            0
        }
    }

    fn current_speed(&self) -> u8 { self.speed_at(self.current_position()) }

    fn peek_next_position(&mut self) -> Location {
        if self.current_position > 20 {
            Location::BrakeHere
        } else {
            self.positions.0[self.current_position + 1]
        }
    }
}

impl Default for LocationSequence {
    fn default() -> Self { LocationSequence([Location::BrakeHere; 16]) }
}

impl Default for LocationSpeedMap {
    fn default() -> Self {
        #[cfg(target_os = "none")]
        let speeds = {
            let mut x = heapless::LinearMap::new();
            ([
                (Location::ForwardA, 0),
                (Location::BackwardsA, 0),
                (Location::ForwardB, 0),
                (Location::BackwardsB, 0),
                (Location::ForwardC, 0),
                (Location::BackwardsC, 0),
                (Location::LaneSwitchStraight, 0),
                (Location::LaneSwitchCurved, 0),
                (Location::StopAndWait, 0),
                (Location::BrakeHere, 0),
            ])
            .iter()
            .for_each(|y| {
                let _ = x.insert(y.0, y.1);
            });
            LocationSpeedMap(x)
        };
        #[cfg(not(target_os = "none"))]
        let speeds = LocationSpeedMap(
            [
                (Location::ForwardA, 0),
                (Location::BackwardsA, 0),
                (Location::ForwardB, 0),
                (Location::BackwardsB, 0),
                (Location::ForwardC, 0),
                (Location::BackwardsC, 0),
                (Location::LaneSwitchStraight, 0),
                (Location::LaneSwitchCurved, 0),
                (Location::StopAndWait, 0),
                (Location::BrakeHere, 0),
            ]
            .into(),
        );
        speeds
    }
}

impl IntoIterator for LocationSequence {
    type IntoIter = core::array::IntoIter<Location, 16>;
    type Item = Location;

    fn into_iter(self) -> Self::IntoIter { self.0.into_iter() }
}

#[cfg(all(test, not(target_os = "none")))]
mod tests {
    use super::*;

    #[test]
    fn test_speed_conversions_default() {
        let route = Route::default();
        let bytes: u64 = route.speeds.clone().into();
        let new_speed = LocationSpeedMap::from(bytes);
        assert_eq!(route.speeds, new_speed);
    }

    #[test]
    fn test_location_conversions_default() {
        let route = Route::default();
        let bytes: u64 = route.positions.into();
        let new_positions = bytes.into();
        assert_eq!(route.positions, new_positions);
    }

    #[test]
    fn test_location_conversions() {
        let route = Route {
            positions: LocationSequence([
                Location::StraightStart,
                Location::LaneSwitchStraight,
                Location::LaneSwitchCurved,
                Location::StraightEndTrack,
                Location::LaneSwitchEndTrack,
                Location::StraightBackwards,
                Location::StraightStart,
                Location::LaneSwitchStraight,
                Location::LaneSwitchCurved,
                Location::StraightEndTrack,
                Location::LaneSwitchEndTrack,
                Location::StraightBackwards,
                Location::StraightStart,
                Location::LaneSwitchStraight,
                Location::LaneSwitchCurved,
                Location::StraightStart,
                Location::LaneSwitchStraight,
                Location::LaneSwitchCurved,
                Location::StraightEndTrack,
                Location::LaneSwitchEndTrack,
                Location::StraightBackwards,
            ]),
            current_position: 0,
            speeds: LocationSpeedMap::default(),
        };
        let bytes: u64 = route.positions.into();
        let new_positions: LocationSequence = bytes.into();
        let other_bytes: u64 = new_positions.into();
        #[cfg(not(target_os = "none"))]
        println!("{:0>64b}\n{:0>64b}", bytes, other_bytes);
        assert_eq!(route.positions, new_positions);
    }

    #[test]
    fn test_speed_conversions() {
        let route = Route {
            positions: LocationSequence::default(),
            current_position: 0,
            speeds: LocationSpeedMap(
                [
                    (Location::StraightStart, 10),
                    (Location::StraightBackwards, 20),
                    (Location::LaneSwitchStraight, 30),
                    (Location::LaneSwitchCurved, 40),
                    (Location::StraightEndTrack, 50),
                    (Location::LaneSwitchEndTrack, 60),
                    (Location::StopAndWait, 0),
                    (Location::BrakeHere, 0),
                ]
                .into(),
            ),
        };
        let bytes: u64 = route.speeds.clone().into();
        let new_speeds = LocationSpeedMap::from(bytes);
        let other_bytes: u64 = new_speeds.clone().into();
        #[cfg(not(target_os = "none"))]
        println!("{:0>64b}\n{:0>64b}", bytes, other_bytes);
        assert_eq!(route.speeds, new_speeds);
    }

    #[test]
    fn printing_speed_values() {
        let route = Route {
            positions: LocationSequence([
                Location::StopAndWait,
                Location::StraightStart,
                Location::StopAndWait,
                Location::StraightBackwards,
                Location::StopAndWait,
                Location::StopAndWait,
                Location::StraightStart,
                Location::StopAndWait,
                Location::StraightBackwards,
                Location::StopAndWait,
                Location::StopAndWait,
                Location::StraightStart,
                Location::StopAndWait,
                Location::StraightBackwards,
                Location::StopAndWait,
                Location::StopAndWait,
                Location::StraightStart,
                Location::StopAndWait,
                Location::StraightBackwards,
                Location::StopAndWait,
                Location::StopAndWait,
            ]),
            current_position: 0,
            speeds: LocationSpeedMap(
                [
                    (Location::StraightStart, 195),
                    (Location::StraightBackwards, 185),
                    (Location::LaneSwitchStraight, 0),
                    (Location::LaneSwitchCurved, 0),
                    (Location::StraightEndTrack, 0),
                    (Location::LaneSwitchEndTrack, 0),
                    (Location::StopAndWait, 0),
                    (Location::BrakeHere, 0),
                ]
                .into(),
            ),
        };
        let s_bytes: u64 = route.speeds.clone().into();
        let r_bytes: u64 = route.positions.into();
        // panic!("Speeds: {}\nPositions: {}", s_bytes, r_bytes);
        assert!(s_bytes > 0);
        assert!(r_bytes > 0);
    }
}
