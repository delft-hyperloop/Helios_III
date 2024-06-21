use std::time::Duration;

use canzero_common::{CanFrame, NetworkFrame, TNetworkFrame};
use color_print::cprintln;


#[derive(Clone)]
pub enum ConnectionHandshakeFrame {
    ClientServer { request: bool, sync : bool },
    ServerClient { success: bool, node_id: u8 },
}

impl ConnectionHandshakeFrame {

    pub fn bin_size() -> usize {
        return 2;
    }

    pub fn into_bin(&self, buf : &mut [u8;2]) {
        match &self {
            ConnectionHandshakeFrame::ClientServer { request, sync } => {
                buf[0] = 0x0;
                if *request {
                    buf[0] |= 0x80;
                }
                if *sync {
                    buf[0] |= 0x40;
                }
                buf[1] = 0x0; //could be uninitalized
            }
            ConnectionHandshakeFrame::ServerClient { success, node_id } => {
                buf[0] = 0x1;
                if *success {
                    buf[0] |= 0x80;
                }
                buf[1] = *node_id;
            }
        }
    }

    pub fn from_bin(buf : &[u8;2]) -> Result<Self,()> {
        let tag = buf[0] & 0xF;
        if tag == 0x0 {
            let request = buf[0] & 0x80 != 0;
            let sync = buf[0] & 0x40 != 0;
            Ok(Self::ClientServer { request, sync})
        }else if tag == 0x1 {
            let success = buf[0] & 0x80 != 0;
            let node_id = buf[1];
            Ok(Self::ServerClient { success, node_id })
        }else {
            cprintln!("<red>Invalid ConnectionHandshake tag : {tag} </red>");
            Err(())
        }
    }
}


#[derive(Clone)]
pub enum TcpFrame {
    NetworkFrame(TNetworkFrame),
    SyncEnd,
    KeepAlive,
}

impl TcpFrame {

    pub fn bin_size() -> usize {
        return 24;
    }

    pub fn into_bin(&self, buf8 : &mut [u8;24]) {
        match &self {
            TcpFrame::NetworkFrame(timestamped) => {
                let frame = &timestamped.value;
                let timestamp = timestamped.timestamp.as_micros() as u64;
                let bus_id = &frame.bus_id;
                let can_id = frame.can_frame.key();
                let data = frame.can_frame.get_data_u64();
                let dlc = frame.can_frame.get_dlc();
                
                buf8[0] = 0x1;
                buf8[1] = *bus_id as u8;
                buf8[2] = dlc;
                let buf32 : &mut [u32;6] = unsafe {std::mem::transmute(buf8)};
                buf32[1] = can_id;
                let buf64 : &mut [u64;3] = unsafe {std::mem::transmute(buf32)};
                buf64[1] = timestamp;
                buf64[2] = data;


            }
            TcpFrame::KeepAlive => {
                buf8[0] = 0x0;
            }
            TcpFrame::SyncEnd => {
                buf8[0] = 0x2;
            },
        }
    }

    pub fn from_bin(buf : &[u8;24]) -> Result<Self, ()> {
        let tag = buf[0];
        if tag == 0x0 {
            Ok(TcpFrame::KeepAlive)
        }else if tag == 0x1 {
            let bus_id = buf[1] as u32;
            let dlc = buf[2];
            let buf : &[u32;6] = unsafe {std::mem::transmute(buf)};
            let can_id = buf[1];
            let buf : &[u64;3] = unsafe {std::mem::transmute(buf)};
            let timestamp = Duration::from_micros(buf[1]);
            let data = buf[2];
            Ok(TcpFrame::NetworkFrame(TNetworkFrame::new(timestamp, NetworkFrame { bus_id, can_frame: CanFrame::new_raw(can_id, dlc, data) })))
        }else if tag == 0x2 {
            Ok(TcpFrame::SyncEnd)
        } else {
            Err(())
        }
    }
}
