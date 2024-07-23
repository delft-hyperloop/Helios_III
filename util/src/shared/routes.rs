// use embassy_stm32::gpio::Speed;
#[cfg(target_os = "none")]
use heapless::LinearMap;

/// A speed setting for every location on the track (see [Location](enum.Location.html))
///
/// * Part of the route configuration (see [Route](struct.Route.html))
/// * Each speed is a u8 value from 0 to 255,
///     the analog voltage (0V to 3.3V) that will be sent to the PLC.
/// * The implementation of this struct varies depending on the target OS
///     (ground station / embedded).
///
/// Currently in use is the *embedded* version, using a [`heapless::LinearMap`](https://docs.rs/heapless/latest/heapless/struct.LinearMap.html).
#[cfg(target_os = "none")]
#[derive(PartialEq, Eq, Debug, Clone)]
pub struct LocationSpeedMap(LinearMap<Location, u8, 10>);

/// A speed setting for every location on the track (see [Location](enum.Location.html))
///
/// * Part of the route configuration (see [Route](struct.Route.html))
/// * Each speed is a u8 value from 0 to 255,
///     the analog voltage (0V to 3.3V) that will be sent to the PLC.
/// * The implementation of this struct varies depending on the target OS
///     (ground station / embedded).
///
/// Currently in use is the *std* version, using a [`std::collections::BTreeMap`].
#[cfg(not(target_os = "none"))]
#[derive(PartialEq, Eq, PartialOrd, Ord, Debug, Clone)]
#[cfg_attr(not(target_os = "none"), derive(serde::Serialize, serde::Deserialize))]
pub struct LocationSpeedMap(pub std::collections::BTreeMap<Location, u8>);

/// A sequence of locations that the pod will travel through
///
/// Part of the route configuration (see [Route](struct.Route.html))
#[derive(PartialEq, Eq, PartialOrd, Ord, Clone, Copy, core::fmt::Debug)]
#[cfg_attr(not(target_os = "none"), derive(serde::Serialize, serde::Deserialize))]
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

/// Locations that the pod can be in
/// ```ignore
/// ------------  |            /   ---------
///  ForwardB  ↑  |          /     ↗ ForwardC
///            .  |        /    ↙ BackwardsC
///  BackwardB ↓  |      /   --- ----------
/// ------------  |     |   --------------
///            .  |    /   .
///            .  |   |   .
///            .  |   |   .
/// LaneSwitch    |  /      LaneSwitch
/// Straight      | |       Curved
///            .  | |   .
///            .  | |   .
/// ------------  |/   -------------------
/// ------------  |
///            .  |
///  ForwardA  ↑  |
///            .  |
///  BackwardA ↓  |
///            .  |
/// ------------  |
/// ```
/// The bits correspond to the encoding used for converting a LocationSequence to a u64 (see [LocationSequence](struct.LocationSequence.html))
#[derive(Debug, Clone, PartialEq, Eq, PartialOrd, Copy, Ord)]
#[cfg_attr(target_os = "none", derive(defmt::Format))]
#[cfg_attr(not(target_os = "none"), derive(serde::Serialize, serde::Deserialize))]
pub enum Location {
    ForwardA = 0b0001,           // 0x1
    BackwardsA = 0b0011,         // 0x2
    ForwardB = 0b0100,           // 0x3
    BackwardsB = 0b0101,         // 0x5
    ForwardC = 0b0111,           // 0x7
    BackwardsC = 0b1000,         // 0x8
    LaneSwitchStraight = 0b1001, // 0x9
    LaneSwitchCurved = 0b1010,   // 0xA
    StopAndWait = 0b1011,        // 0xB
    BrakeHere = 0b0000,          // no next position, just stop here.
}

/// A full configuration of the propulsion subsystem for a run.
///
/// * (Up to) 16 locations in a sequence, holds the current position.
///
/// * To transition, use [`route.next_position()`](trait.RouteUse.html#tymethod.next_position).
/// * See [Location](enum.Location.html).
///
/// * Speeds for each location on the track
/// * See [Speeds](enum.LocationSpeedMap.html).
/// * To get the speed for the current position, use [`route.current_speed()`](trait.RouteUse.html#tymethod.current_speed).
#[derive(core::fmt::Debug, PartialEq, Eq, Default)]
#[cfg_attr(not(target_os = "none"), derive(serde::Serialize, serde::Deserialize))]
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

#[cfg(not(target_os="none"))]
impl std::fmt::Display for Route {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> Result<(), std::fmt::Error> {
        
        std::writeln!(f, "Route {{")?;
        for l in self.positions.into_iter() {
            std::writeln!(f, " -> {:?}", l)?;
        }
        std::writeln!(f, "\n currently at: {:?}", self.current_position)?;
        std::writeln!(f, " Speeds: ")?;
        for (key, value) in self.speeds.0.iter() {
            std::writeln!(f, "  {:?}: {}", key, value)?;
        }
        std::writeln!(f, "}}")
    }
}

#[cfg(not(target_os = "none"))]
impl IntoIterator for LocationSpeedMap {
    type IntoIter = std::collections::btree_map::IntoIter<Location, u8>;
    type Item = (Location, u8);

    fn into_iter(self) -> Self::IntoIter { self.0.into_iter() }
}

#[allow(dead_code)]
impl Route {
    pub fn speeds_from(&mut self, val: u64) { self.speeds = LocationSpeedMap::from(val); }

    pub fn positions_from(&mut self, val: u64) { self.positions = LocationSequence::from(val); }
}

#[cfg(not(target_os = "none"))]
impl std::fmt::Display for LocationSequence {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        writeln!(f, "Route {{")?;
        for l in self.0.into_iter() {
            std::write!(f, " -> {:?} (0x{:x})", l, l as u64)?;
        }
        writeln!(f, "}}")
    }
}

impl From<LocationSequence> for u64 {
    fn from(val: LocationSequence) -> Self {
        let mut bit_seq: u64 = 0;

        // Encode the positions as a 63-bit integer
        for (i, location) in val.0.iter().enumerate() {
            let location_bits = *location as u64;
            bit_seq |= location_bits << (4 * (15 - i));
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
    for i in 0..=15 {
        let bits = (bit_seq & 0b1111) as u8;
        bit_seq >>= 4;
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
        if self.current_position > 15 {
            Location::BrakeHere
        } else {
            self.current_position += 1;
            self.positions.0[self.current_position - 1]
        }
    }

    fn current_position(&self) -> Location {
        if self.current_position > 16 {
            Location::BrakeHere
        } else {
            self.positions.0[self.current_position - 1]
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
        if self.current_position > 16 {
            Location::BrakeHere
        } else {
            self.positions.0[self.current_position]
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

    // ForwardA = 0b0001,
    //     BackwardsA = 0b0011,
    //     ForwardB = 0b0100,
    //     BackwardsB = 0b0101,
    //     ForwardC = 0b0111,
    //     BackwardsC = 0b1000,
    //     LaneSwitchStraight = 0b1001,
    //     LaneSwitchCurved = 0b1010,
    //     StopAndWait = 0b1011,
    //     BrakeHere = 0b0000, //

    #[test]
    fn test_location_conversions() {
        let route = Route {
            positions: LocationSequence([
                Location::ForwardA,
                Location::LaneSwitchStraight,
                Location::LaneSwitchCurved,
                Location::BackwardsC,
                Location::BackwardsB,
                Location::StopAndWait,
                Location::BackwardsA,
                Location::LaneSwitchStraight,
                Location::LaneSwitchCurved,
                Location::ForwardC,
                Location::BackwardsC,
                Location::ForwardB,
                Location::BackwardsA,
                Location::LaneSwitchStraight,
                Location::LaneSwitchCurved,
                Location::BackwardsC,
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
                    (Location::ForwardA, 195),
                    (Location::BackwardsA, 194),
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
            ),
        };
        let bytes: u64 = route.speeds.clone().into();
        let new_speeds = LocationSpeedMap::from(bytes);
        let other_bytes: u64 = new_speeds.clone().into();
        #[cfg(not(target_os = "none"))]
        println!("{:0>64b}\n{:0>64b}", bytes, other_bytes);
        assert_eq!(route.speeds, new_speeds);
    }

    // #[test]
    // fn printing_speed_values() {
    //     let route = Route {
    //         positions: LocationSequence([
    //             Location::ForwardA,
    //             Location::LaneSwitchStraight,
    //             Location::ForwardB,
    //             Location::StopAndWait,
    //             Location::BackwardsB,
    //             Location::LaneSwitchStraight,
    //             Location::BackwardsA,
    //             Location::BrakeHere,
    //             Location::StopAndWait,
    //             Location::ForwardA,
    //             Location::LaneSwitchCurved,
    //             Location::ForwardC,
    //             Location::BrakeHere,
    //             Location::BrakeHere,
    //             Location::BrakeHere,
    //             Location::BrakeHere,
    //         ]),
    //         current_position: 0,
    //         speeds: LocationSpeedMap(
    //             [
    //                 (Location::ForwardA, 195),
    //                 (Location::BackwardsA, 187),
    //                 (Location::ForwardB, 199),
    //                 (Location::BackwardsB, 184),
    //                 (Location::ForwardC, 199),
    //                 (Location::BackwardsC, 0),
    //                 (Location::LaneSwitchStraight, 0),
    //                 (Location::LaneSwitchCurved, 0),
    //                 (Location::StopAndWait, 0),
    //                 (Location::BrakeHere, 0),
    //             ]
    //             .into(),
    //         ),
    //     };
    //     let s_bytes: u64 = route.speeds.clone().into();
    //     let r_bytes: u64 = route.positions.into();
    //     panic!("Speeds: {}\nPositions: {}", s_bytes, r_bytes);
    //
    //     let mut r = Route::default();
    //     r.speeds_from(s_bytes);
    //     r.positions_from(r_bytes);
    //
    //     assert_eq!(r, route);
    // }

    // #[test]
    // fn import_speeds_from_kiril() {
    //     let x = 15256443658052882000u64;
    //     let y: LocationSpeedMap = x.into();
    //     let mut r = Route::default();
    //     r.speeds_from(x);
    //     panic!("{}\n\n{}", x, r);
    // }



    // #[test]
    // fn demonstration() {
    //     let route = Route {
    //         positions: LocationSequence([
    //             Location::ForwardA,
    //             Location::LaneSwitchStraight,
    //             Location::ForwardB,
    //             Location::StopAndWait,
    //             Location::BackwardsB,
    //             Location::LaneSwitchStraight,
    //             Location::BackwardsA,
    //             Location::BrakeHere,
    //             Location::StopAndWait,
    //             Location::ForwardA,
    //             Location::LaneSwitchCurved,
    //             Location::ForwardC,
    //             Location::BrakeHere,
    //             Location::BrakeHere,
    //             Location::BrakeHere,
    //             Location::BrakeHere,
    //         ]),
    //         current_position: 0,
    //         speeds: LocationSpeedMap(
    //             [
    //                 (Location::ForwardA, 195),
    //                 (Location::BackwardsA, 187),
    //                 (Location::ForwardB, 199),
    //                 (Location::BackwardsB, 184),
    //                 (Location::ForwardC, 199),
    //                 (Location::BackwardsC, 0),
    //                 (Location::LaneSwitchStraight, 0),
    //                 (Location::LaneSwitchCurved, 0),
    //                 (Location::StopAndWait, 0),
    //                 (Location::BrakeHere, 0),
    //             ]
    //             .into(),
    //         ),
    //     };
    //     let s_bytes: u64 = route.speeds.clone().into();
    //     let r_bytes: u64 = route.positions.into();
    //     panic!("Speeds: {}\nPositions: {}", s_bytes, r_bytes);
    //
    //     let mut r = Route::default();
    //     r.speeds_from(s_bytes);
    //     r.positions_from(r_bytes);
    //
    //     assert_eq!(r, route);
    // }

    #[test]
    fn demonstration_A() {
        let route = Route {
            positions: LocationSequence([
                Location::ForwardA,
                Location::LaneSwitchStraight,
                Location::ForwardB,
                Location::StopAndWait,
                Location::BackwardsB,
                Location::LaneSwitchStraight,
                Location::BackwardsA,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
            ]),
            current_position: 0,
            speeds: LocationSpeedMap( // 4m/s: 218  | 0.5m/s:  195 | -4: 166 | -0.5: 188
                [
                    (Location::ForwardA, 218),
                    (Location::BackwardsA, 188),
                    (Location::ForwardB, 195),
                    (Location::BackwardsB, 166),
                    (Location::ForwardC, 195),
                    (Location::BackwardsC, 0),
                    (Location::LaneSwitchStraight, 0),
                    (Location::LaneSwitchCurved, 0),
                    (Location::StopAndWait, 0),
                    (Location::BrakeHere, 0),
                ]
                .into(),
            ),
        };
        let s_bytes: u64 = route.speeds.clone().into();
        let r_bytes: u64 = route.positions.into();
        // panic!("Speeds: {}\nPositions: {}", s_bytes, r_bytes);

        let mut r = Route::default();
        r.speeds_from(s_bytes);
        r.positions_from(r_bytes);

        assert_eq!(r, route);
    }


    #[test]
    fn demonstration_B() {
        let route = Route {
            positions: LocationSequence([
                Location::ForwardA,
                Location::LaneSwitchCurved,
                Location::ForwardC,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
                Location::BrakeHere,
            ]),
            current_position: 0,
            speeds: LocationSpeedMap( // 4m/s: 218  | 0.5m/s:  195 | -4: 166 | -0.5: 188
                [
                    (Location::ForwardA, 218),
                    (Location::BackwardsA, 0),
                    (Location::ForwardB, 0),
                    (Location::BackwardsB, 0),
                    (Location::ForwardC, 195),
                    (Location::BackwardsC, 0),
                    (Location::LaneSwitchStraight, 0),
                    (Location::LaneSwitchCurved, 200),
                    (Location::StopAndWait, 0),
                    (Location::BrakeHere, 0),
                ]
                .into(),
            ),
        };
        let s_bytes: u64 = route.speeds.clone().into();
        let r_bytes: u64 = route.positions.into();
        // panic!("Speeds: {}\nPositions: {}", s_bytes, r_bytes);

        let mut r = Route::default();
        r.speeds_from(s_bytes);
        r.positions_from(r_bytes);

        assert_eq!(r, route);
    }

}

