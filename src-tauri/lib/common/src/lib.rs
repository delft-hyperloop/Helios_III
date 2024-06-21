use serde::{Deserialize, Serialize};
use std::{
    ops::Deref,
    time::{Duration, Instant},
};

#[derive(Serialize, Deserialize, Debug)]
pub struct Timestamped<T> {
    pub timestamp: Duration,
    pub value: T,
}

impl<T> Clone for Timestamped<T>
where
    T: Clone,
{
    fn clone(&self) -> Self {
        Timestamped {
            timestamp: self.timestamp,
            value: self.value.clone(),
        }
    }
}

// TODO serialize implementation for Timestamped<T : Serialize>
// impl<T> Serialize for Timestamped<T>
// where
//     T: Serialize,
// {
//     fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
//     where
//         S: serde::Serializer,
//     {
//         let mut stru = serializer.serialize_struct("Timestamped", 2)?;
//         stru.serialize_field("timestamp", &self.timestamp)?;
//         stru.serialize_field("value", &self.value)?;
//         stru.end()
//     }
// }
//TODO deserialize implementation for Timestamped<T : Deserialize>

impl<T> Deref for Timestamped<T> {
    type Target = T;

    fn deref(&self) -> &Self::Target {
        &self.value
    }
}

impl<T> Timestamped<T> {
    pub fn new(timestamp: Duration, value: T) -> Self {
        Self { timestamp, value }
    }

    pub fn now(base_time: Instant, value: T) -> Self {
        Self {
            timestamp: Instant::now().duration_since(base_time),
            value,
        }
    }

    pub fn destruct(self) -> (Duration, T) {
        (self.timestamp, self.value)
    }

    pub fn new_value<R>(&self, value: R) -> Timestamped<R> {
        Timestamped::new(self.timestamp, value)
    }
}

pub type TCanFrame = Timestamped<CanFrame>;

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct CanFrame {
    id: u32,
    dlc: u8,
    data: u64,
}

#[repr(u32)]
enum CanFrameIdFlags {
    IdeMask = 0x80000000,
    RtrMask = 0x40000000,
    ExtMask = 0x1FFFFFFF,
}

impl CanFrame {
    /// Least significant byte of data attribute corresponds to first byte of data field in CAN message.
    /// Just think about it as a char-array.
    /// Bit order within each byte should not be a concern
    /// (bits not really addressable in a byte-addressable system).
    /// Just think about it as least significant bit in each byte is also
    /// least significant bit in CAN message and at receiver.
    pub fn new(id: u32, ide: bool, rtr: bool, dlc: u8, data: u64) -> Self {
        Self {
            id: id
                | (if ide {
                    CanFrameIdFlags::IdeMask as u32
                } else {
                    0x0u32
                })
                | (if rtr {
                    CanFrameIdFlags::RtrMask as u32
                } else {
                    0x0u32
                }),
            dlc,
            data,
        }
    }

    pub fn new_raw(id_key : u32, dlc : u8, data : u64) -> Self {
        Self {
            id : id_key,
            dlc,
            data
        }
    }

    pub fn key(&self) -> u32 {
        self.id
    }

    #[allow(unused)]
    pub fn get_id(&self) -> u32 {
        self.id & CanFrameIdFlags::ExtMask as u32
    }
    #[allow(unused)]
    pub fn get_ide_flag(&self) -> bool {
        (self.id & CanFrameIdFlags::IdeMask as u32) != 0
    }
    #[allow(unused)]
    pub fn get_rtr_flag(&self) -> bool {
        (self.id & CanFrameIdFlags::RtrMask as u32) != 0
    }
    #[allow(unused)]
    pub fn get_dlc(&self) -> u8 {
        self.dlc
    }
    pub fn get_data_u64(&self) -> u64 {
        self.data
    }
    #[allow(dead_code)]
    pub fn get_data_8u8(&self) -> [u8; 8] {
        unsafe { std::mem::transmute::<u64, [u8; 8]>(self.data) }
    }
}

pub type TCanError = Timestamped<CanError>;

#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct CanError(pub u64);

impl CanError {
    pub fn erno(&self) -> u64 {
        self.0
    }
}

#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct NetworkFrame {
    pub bus_id: u32,
    pub can_frame: CanFrame,
}

pub type TNetworkFrame = Timestamped<NetworkFrame>;
