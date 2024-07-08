use crate::Datatype;

pub mod can;
pub mod tcp;

#[derive(Debug, PartialEq, Eq)]
pub struct Datapoint {
    pub datatype: Datatype,
    pub value: u64,
    pub timestamp: u64,
}

impl Datapoint {
    pub fn new(datatype: Datatype, value: u64, timestamp: u64) -> Self {
        Self { datatype, value, timestamp }
    }

    /// ### Encode a datapoint as bytes
    /// | index | meaning |
    /// | --- | --- |
    /// | 0 | 0xFF : flag byte |
    /// | 1, 2 | 11 bit datatype id |
    /// | 3..=10 | 8 byte value |
    /// | 11..=18 | 8 byte timestamp |
    /// | 19 | 0xFF : flag byte |
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
