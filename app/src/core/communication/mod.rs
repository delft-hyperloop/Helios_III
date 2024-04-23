use core::cmp::Ordering;
use crate::Datatype;

pub mod tcp;
pub mod udp;
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

    pub fn as_bytes(&self) -> [u8; 13] {
        let mut bytes = [0; 13];
        bytes[0] = (self.datatype.to_id() & 0x00FF) as u8;
        bytes[1] = (self.datatype.to_id() & 0xFF00) as u8;
        bytes[2..10].copy_from_slice(&self.value.to_le_bytes());
        bytes[10..14].copy_from_slice(&self.timestamp.to_le_bytes());
        bytes
    }
}
