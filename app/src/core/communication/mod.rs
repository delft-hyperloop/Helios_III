use core::cmp::Ordering;
use crate::core::finite_state_machine::Event;
use crate::encode_datatype;
pub mod tcp;
pub mod udp;
mod parse;
pub mod can;


// IF YOU UPDATE THIS, ALSO LOOK AT config/config.toml
pub enum Datatype {
    PropulsionTemperature,
    LevitationTemperature,
    BatteryVoltage,
    BatteryCurrent,
    BatteryTemperature,
    BrakeTemperature,
    PropulsionSpeed,
    BrakePressure,
    GroundVoltage,
    FSMState,
    FSMEvent,
}

// #[derive(Debug, PartialEq, Eq)]
pub struct Datapoint {
    pub datatype: Datatype,
    pub value: u64,
    pub timestamp: u32,
}

impl Datapoint {
    pub fn new(datatype: Datatype, value: u64, timestamp: u32) -> Self {
        Self {
            datatype,
            value,
            timestamp,
        }
    }

    pub fn as_bytes(&self) -> [u8; 13] {
        let mut bytes = [0; 13];
        bytes[0] = encode_datatype(&self.datatype);
        bytes[1..9].copy_from_slice(&self.value.to_le_bytes());
        bytes[9..13].copy_from_slice(&self.timestamp.to_le_bytes());
        bytes
    }
}
