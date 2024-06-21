
use std::mem;

use libc::{c_int, c_void, can_frame, read, sa_family_t, sockaddr_can, write};
pub use libc::{
    AF_CAN, CAN_EFF_FLAG, CAN_EFF_MASK, CAN_ERR_FLAG, CAN_RAW, CAN_RTR_FLAG, CAN_SFF_MASK, PF_CAN,
    SOCK_RAW,
};

use canzero_common::{CanError, CanFrame};

#[derive(Clone, Debug)]
pub struct CanSocket {
    fd: c_int,
}

impl CanSocket {
    pub fn open(ifname: &str) -> Result<CanSocket, std::io::Error> {
        let ifindex = nix::net::if_::if_nametoindex(ifname)?;
        let mut addr: sockaddr_can = unsafe { mem::zeroed() };
        addr.can_family = AF_CAN as sa_family_t;
        addr.can_ifindex = ifindex as c_int;
        let addr: *const sockaddr_can = &addr;

        let fd = unsafe { libc::socket(PF_CAN, SOCK_RAW, CAN_RAW) };

        if fd == -1 {
            return Err(std::io::Error::last_os_error());
        }

        let ret = unsafe { libc::bind(fd, addr.cast(), mem::size_of::<sockaddr_can>() as u32) };

        if ret == -1 {
            let err = std::io::Error::last_os_error();
            unsafe { libc::close(fd) };
            Err(err)
        } else {
            Ok(CanSocket { fd })
        }
    }
    pub fn close(&mut self) {
        unsafe {
            libc::close(self.fd);
        }
    }
    pub fn receive(&self) -> Result<Result<CanFrame, CanError>, std::io::Error> {
        let mut frame: can_frame = unsafe { mem::zeroed() };
        let n = mem::size_of::<can_frame>();

        let rd = unsafe { read(self.fd, &mut frame as *mut _ as *mut c_void, n) };

        if rd as usize == n {
            // parse can_frame into CanFrame
            if frame.can_id & CAN_ERR_FLAG != 0 {
                return Ok(Err(unsafe { std::mem::transmute(frame.data) }));
            } else {
                Ok(Ok(frame_from_socket_can_frame(&frame)))
            }
        } else {
            Err(std::io::Error::last_os_error())
        }
    }

    pub fn transmit(&self, frame: &CanFrame) -> Result<(), std::io::Error> {
        let fd = self.fd;
        let canframe = frame_to_socket_can_frame(frame);

        let ret = unsafe {
            write(
                fd,
                (&canframe as *const can_frame).cast(),
                mem::size_of::<can_frame>(),
            )
        };

        if ret as usize == mem::size_of::<can_frame>() {
            Ok(())
        } else {
            Err(std::io::Error::last_os_error())
        }
    }
}

pub fn frame_from_socket_can_frame(frame: &can_frame) -> CanFrame {
    let ide = (frame.can_id & CAN_EFF_FLAG) != 0;
    let id = if ide {
        frame.can_id & CAN_EFF_MASK
    } else {
        frame.can_id & CAN_SFF_MASK
    };
    CanFrame::new(
        id,
        false,
        // (frame.can_id & CAN_RTR_FLAG) != 0,
        ide,
        frame.can_dlc,
        u64::from_le_bytes(frame.data),
    )
}

pub fn frame_to_socket_can_frame(frame: &CanFrame) -> can_frame {
    let mut canframe: can_frame = unsafe { std::mem::zeroed() };
    if frame.get_ide_flag() {
        canframe.can_id |= CAN_EFF_FLAG;
        canframe.can_id |= frame.get_id() & CAN_SFF_MASK;
    } else {
        canframe.can_id |= frame.get_id() & CAN_EFF_MASK;
    }
    // if frame.get_rtr_flag() {
    //     canframe.can_id |= CAN_RTR_FLAG;
    // }
    canframe.can_dlc = frame.get_dlc();
    canframe.data = frame.get_data_8u8();
    canframe
}
