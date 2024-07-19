use core::cmp::Ordering;

use defmt::Formatter;

use crate::Datatype;

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

impl defmt::Format for Datapoint {
    fn format(&self, fmt: Formatter) {
        defmt::write!(
            fmt,
            "Datapoint {{ datatype: {:?}, value: {:?}, timestamp: {:?} }}",
            self.datatype,
            self.value,
            self.timestamp
        )
    }
}

impl PartialOrd for Datapoint {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> { Some(self.cmp(other)) }
}

impl Ord for Datapoint {
    fn cmp(&self, other: &Self) -> Ordering {
        // First compare by priority
        let priority_cmp = self.datatype.priority().cmp(&other.datatype.priority());
        if priority_cmp != Ordering::Equal {
            return priority_cmp;
        }

        // Because we can't have Eq if not all fields are the same,

        // if priorities are equal, compare by timestamp
        let timestamp_cmp = self.timestamp.cmp(&other.timestamp);
        if timestamp_cmp != Ordering::Equal {
            return timestamp_cmp;
        }

        // if timestamps are equal, compare by id
        let type_cmp = self.datatype.to_id().cmp(&other.datatype.to_id());
        if type_cmp != Ordering::Equal {
            return type_cmp;
        }

        // if the datatype is the same,
        // then getting an equality on value means total equality
        self.value.cmp(&other.value)
    }
}
