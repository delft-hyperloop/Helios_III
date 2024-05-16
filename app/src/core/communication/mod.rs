use crate::Datatype;
use core::cmp::Ordering;

pub mod can;
pub mod tcp;
pub mod udp;
mod dispatcher;
mod parse;
pub mod can;

// IF YOU UPDATE THIS, ALSO LOOK AT config/config.toml
// pub enum Datatype {
//     PropulsionTemperature,
//     LevitationTemperature,
//     BatteryVoltage,
//     BatteryCurrent,
//     BatteryTemperature,
//     BrakeTemperature,
//     PropulsionSpeed,
//     BrakePressure,
//     GroundVoltage,
//     FSMState,
//     FSMEvent,
// }

// #[derive(Debug, PartialEq, Eq)]
pub struct Datapoint {
    pub datatype: Datatype,
    pub value: u64,
    pub timestamp: u64,
}

impl Datapoint {
    pub fn new(datatype: Datatype, value: u64, timestamp: u64) -> Self {
        Self {
            datatype,
            value,
            timestamp,
        }
    }

    pub fn as_bytes(&self) -> [u8; 20] {
        let mut bytes = [0; 20];
        bytes[0] = 0xFF;
        bytes[1..3].copy_from_slice(&self.datatype.to_id().to_be_bytes());
        bytes[3..11].copy_from_slice(&self.value.to_le_bytes());
        bytes[11..19].copy_from_slice(&self.timestamp.to_le_bytes());
        bytes[19] = 0xFF;
        bytes
    }
}
