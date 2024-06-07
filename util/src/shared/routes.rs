#[cfg(target_os = "none")]
use heapless::LinearMap;

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

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
pub enum Location {
    StraightStart = 0b001,
    LaneSwitchStraight = 0b010,
    LaneSwitchCurved = 0b011,
    StraightEndTrack = 0b100,
    LaneSwitchEndTrack = 0b101,
    StopHere = 0b110, // no next position, just stop here.
}

#[cfg(target_os = "none")]
pub struct Route {
    pub positions: [Location; 8],
    pub current_position: usize,
    pub speeds: heapless::LinearMap<Location, u8, 6>,
}

#[cfg(not(target_os = "none"))]
pub struct Route {
    pub positions: [Location; 8],
    pub current_position: usize,
    pub speeds: std::collections::BTreeMap<Location, u8>,
}

impl From<u64> for Route {
    fn from(value: u64) -> Self {
        #[cfg(target_os = "none")]
        let mut speeds = heapless::LinearMap::new();

        #[cfg(not(target_os = "none"))]
        let mut speeds = std::collections::BTreeMap::new();

        let bytes: [u8; 8] = value.to_be_bytes();

        let _ = (
            speeds.insert(Location::StraightStart, bytes[3]),
            speeds.insert(Location::LaneSwitchStraight, bytes[4]),
            speeds.insert(Location::LaneSwitchCurved, bytes[5]),
            speeds.insert(Location::StraightEndTrack, bytes[6]),
            speeds.insert(Location::LaneSwitchEndTrack, bytes[7]),
            speeds.insert(Location::StopHere, 0),
        );

        Route {
            positions: parse_locations([bytes[0], bytes[1], bytes[2]]),
            current_position: 0,
            speeds,
        }
    }
}

fn parse_locations(bytes: [u8; 3]) -> [Location; 8] {
    let mut locations = [Location::StopHere; 8];
    let mut bit_seq: u32 = ((bytes[2] as u32) << 16) | ((bytes[1] as u32) << 8) | (bytes[0] as u32);

    for i in 0..8 {
        let bits = (bit_seq & 0b111) as u8;
        bit_seq >>= 3;
        locations[7 - i] = match bits {
            0b001 => Location::StraightStart,
            0b010 => Location::LaneSwitchStraight,
            0b011 => Location::LaneSwitchCurved,
            0b100 => Location::StraightEndTrack,
            0b101 => Location::LaneSwitchEndTrack,
            0b110 => Location::StopHere,
            _ => Location::StopHere, // Handle invalid patterns
        };
    }

    locations
}

impl From<Route> for u64 {
    fn from(val: Route) -> Self {
        let mut bit_seq: u32 = 0;

        // Encode the positions as a 24-bit integer
        for (i, location) in val.positions.iter().enumerate() {
            let location_bits = *location as u32;
            bit_seq |= location_bits << (3 * (7 - i));
        }

        // Start with the bit sequence and shift it into the first three bytes
        let mut result: u64 = (bit_seq as u64) << 40;

        // Insert speed data into the remaining bytes
        result |= (val
            .speeds
            .get(&Location::StraightStart)
            .copied()
            .unwrap_or(0) as u64)
            << 32;
        result |= (val
            .speeds
            .get(&Location::LaneSwitchStraight)
            .copied()
            .unwrap_or(0) as u64)
            << 24;
        result |= (val
            .speeds
            .get(&Location::LaneSwitchCurved)
            .copied()
            .unwrap_or(0) as u64)
            << 16;
        result |= (val
            .speeds
            .get(&Location::StraightEndTrack)
            .copied()
            .unwrap_or(0) as u64)
            << 8;
        result |= val
            .speeds
            .get(&Location::LaneSwitchEndTrack)
            .copied()
            .unwrap_or(0) as u64;

        result
    }
}

impl RouteUse for Route {
    fn next_position(&mut self) -> Location {
        if self.current_position >= 7 {
            Location::StopHere
        } else {
            self.current_position += 1;
            self.positions[self.current_position]
        }
    }

    fn current_position(&self) -> Location {
        if self.current_position > 7 {
            Location::StopHere
        } else {
            self.positions[self.current_position]
        }
    }

    fn speed_at(&self, location: Location) -> u8 {
        if let Some(speed) = self.speeds.get(&location) {
            *speed
        } else {
            #[cfg(target_os = "none")]
            defmt::error!("Tried to get speed for invalid location");
            0
        }
    }

    fn current_speed(&self) -> u8 {
        self.speed_at(self.current_position())
    }

    fn peek_next_position(&mut self) -> Location {
        if self.current_position > 7 {
            Location::StopHere
        } else {
            self.positions[self.current_position + 1]
        }
    }
}

impl Default for Route {
    fn default() -> Self {
        #[cfg(target_os = "none")]
        let speeds = {
            let mut x = heapless::LinearMap::new();
            ([
                (Location::StraightStart, 0),
                (Location::LaneSwitchStraight, 0),
                (Location::LaneSwitchCurved, 0),
                (Location::StraightEndTrack, 0),
                (Location::LaneSwitchEndTrack, 0),
                (Location::StopHere, 0),
            ]).iter().for_each(|y| {
                let _ = x.insert(y.0, y.1);
            });
            x
        };
        #[cfg(not(target_os = "none"))]
        let speeds = [
            (Location::StraightStart, 0),
            (Location::LaneSwitchStraight, 0),
            (Location::LaneSwitchCurved, 0),
            (Location::StraightEndTrack, 0),
            (Location::LaneSwitchEndTrack, 0),
            (Location::StopHere, 0),
        ]
        .into();
        Self {
            positions: [Location::StopHere; 8],
            current_position: 0,
            speeds,
        }
    }
}