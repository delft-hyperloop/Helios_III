use defmt::error;
use embassy_net::IpAddress::Ipv4;
use embassy_net::IpEndpoint;
use embassy_net::Ipv4Address;
use embassy_net::Ipv4Cidr;
use embassy_stm32::rcc;
use embassy_stm32::rcc::Pll;
use embassy_stm32::rcc::*;
use embassy_stm32::Config;
use embassy_time::Instant;
use embedded_can::ExtendedId;
use embedded_nal_async::Ipv4Addr;
use embedded_nal_async::SocketAddr;
use embedded_nal_async::SocketAddrV4;

use crate::core::communication::data::Datapoint;
use crate::DataSender;
use crate::Datatype;
use crate::Event;
use crate::EventSender;

#[inline]
pub fn default_configuration() -> Config {
    let mut config = Config::default();

    config.rcc.hse =
        Some(rcc::Hse { freq: embassy_stm32::time::Hertz(8_000_000), mode: HseMode::Oscillator });
    config.rcc.pll1 = Some(Pll {
        source: PllSource::HSE,
        prediv: PllPreDiv::DIV2,
        mul: PllMul::MUL50,
        divp: Some(PllDiv::DIV8),
        divq: Some(PllDiv::DIV8),
        divr: Some(PllDiv::DIV8),
    });
    config.rcc.pll2 = Some(Pll {
        source: PllSource::HSE,
        prediv: PllPreDiv::DIV2,
        mul: PllMul::MUL50,
        divp: Some(PllDiv::DIV8),
        divq: Some(PllDiv::DIV8),
        divr: Some(PllDiv::DIV8),
    });

    config.rcc.hsi = Some(HSIPrescaler::DIV1);
    config.rcc.csi = true;
    config.rcc.hsi48 = Some(Default::default()); // needed for RNG

    config.rcc.sys = Sysclk::PLL1_P; // 400 Mhz
    config.rcc.ahb_pre = AHBPrescaler::DIV2; // 200 Mhz
    config.rcc.apb1_pre = APBPrescaler::DIV2; // 100 Mhz
    config.rcc.apb2_pre = APBPrescaler::DIV2; // 100 Mhz
    config.rcc.apb3_pre = APBPrescaler::DIV2; // 100 Mhz
    config.rcc.apb4_pre = APBPrescaler::DIV2; // 100 Mhz
    config.rcc.voltage_scale = VoltageScale::Scale1;
    config.rcc.mux.fdcansel = rcc::mux::Fdcansel::PLL1_Q;
    config
}

#[inline]
#[allow(dead_code)]
pub fn embassy_socket_from_config(t: ([u8; 4], u16)) -> IpEndpoint {
    IpEndpoint::new(Ipv4(Ipv4Address::new(t.0[0], t.0[1], t.0[2], t.0[3])), t.1)
}

/// Classless Inter-Domain Routing
///
/// a method used to allocate IP addresses and route IP packets more efficiently.
/// It's designed to slow the exhaustion of IPv4 addresses and simplify routing.
///
/// basically:
/// - a (cidr) IP address is now a.b.c.d/p where
/// - a,b,c,d are the address
/// - p is the prefix length, which is the number of bits in the address that are fixed per network.
/// - tl;dr you need ip address+prefix length to define a network
#[inline]
#[allow(dead_code)]
pub fn ip_cidr_from_config(t: ([u8; 4], u16)) -> Ipv4Cidr {
    Ipv4Cidr::new(Ipv4Address::new(t.0[0], t.0[1], t.0[2], t.0[3]), 24)
}

#[inline]
#[allow(dead_code)]
pub fn socket_from_config(t: ([u8; 4], u16)) -> SocketAddr {
    SocketAddr::V4(SocketAddrV4::new(Ipv4Addr::new(t.0[0], t.0[1], t.0[2], t.0[3]), t.1))
}

#[inline]
pub fn bytes_to_u64(b: &[u8]) -> u64 {
    let mut x = 0u64;
    for i in (0..7).rev() {
        x |= (b[i] as u64) << (i * 8);
    }
    x
}

pub fn id_as_value(id: &embedded_can::Id) -> u16 {
    match id {
        embedded_can::Id::Extended(y) => extended_as_value(y),
        embedded_can::Id::Standard(x) => x.as_raw(),
    }
}

pub fn extended_as_value(id: &ExtendedId) -> u16 {
    if id.as_raw() == 0x18FF01F4 {
        return 0x37;
    }
    if id.as_raw() == 0x18FF02F4 {
        return 0x38;
    }
    if id.as_raw() == 0x18FF03F4 {
        return 0x39;
    }
    let temp = id.as_raw();
    let big_id = (temp & (0xFFFF000)) >> 16;
    let mut small_id = temp & 0xFF;
    let dt = temp & 0x0000F00;
    #[allow(clippy::self_assignment)]
    match dt {
        0x000 => small_id += 0,    // Normal Messages
        0x100 => small_id += 0x20, // Voltage Messages
        0x200 => small_id += 256,  // Temp messages
        0x300 => small_id += 0,    //  I wonder what are these
        0x500 => small_id = 0x5,   // Current messages
        0x800 => small_id += 96,   // Balance messages
        _ => {},                   // small_id = small_id | 0x000,
    }
    (big_id + small_id) as u16
}

#[macro_export]
macro_rules! try_spawn {
    ($event_sender:expr, $e:expr) => {
        match $e {
            Ok(_) => {},
            Err(embassy_executor::SpawnError::Busy) => {
                defmt::error!("Failed to spawn task because of SpawnError::Busy");
                defmt::error!("->> Try increasing the pool_size for the task you're trying to spawn");
                $event_sender.send($crate::Event::BootingFailedEvent).await;
            }
        }
    };
}

pub fn ticks() -> u64 { Instant::now().as_ticks() }
pub fn millis() -> u64 { Instant::now().as_millis() }

/// Instantly sends an event through the MPMC queue.
/// * If the queue is full, the event will be discarded.
/// * This function will *not* block
pub fn send_event(event_sender: EventSender, event: Event) {
    match event_sender.try_send(event) {
        Ok(_) => {},
        Err(e) => {
            error!("[send] event channel full: {:?}", e)
        },
    }
}

// /// Instantly sends a datapoint through the MPMC queue.
// /// * If the queue is full, the event will be discarded.
// /// * This function will *not* block.
// /// * The current timestamp will be used.
// /// * If a specific value for timestamp is needed, use [`send_dp`] instead.
// pub fn send_data(data_sender: DataSender, t: Datatype, data: u64) {
//     match data_sender.try_send(Datapoint::new(t, data, ticks())) {
//         Ok(_) => {}
//         Err(e) => {
//             error!("[send] data channel full: {:?}", e)
//         }
//     }
// }

#[macro_export]
macro_rules! send_data {
    ($data_sender:expr, $dtype:expr, $data:expr) => {
        {
            if ! unsafe { $crate::CONNECTED.load(core::sync::atomic::Ordering::Relaxed) } {
                defmt::warn!("[send] Not connected, dropping {:?} {:?}", $dtype, $data);
            } else {
                if let Err(e) = $data_sender.try_send(
                    $crate::Datapoint::new($dtype, $data, $crate::pconfig::ticks())
                ) {
                    defmt::error!("[send] data channel full: {:?}", e);
                }
            }
        }
    };
    ($data_sender:expr, $dtype:expr, $data:expr, $timestamp:expr) => {
        {
            if ! unsafe { $crate::CONNECTED.load(core::sync::atomic::Ordering::Relaxed) } {
                defmt::warn!("[send] Not connected, dropping {:?} {:?} {:?}", $dtype, $data, $timestamp);
            } else {
                if let Err(e) = $data_sender.try_send(
                    $crate::Datapoint::new($dtype, $data, $timestamp)
                ) {
                    defmt::error!("[send] data channel full: {:?}", e);
                }
            }
        }
    };
    ($data_sender:expr, $dtype:expr, $data:expr; $timeout:expr) => {
        {
            if ! unsafe { $crate::CONNECTED.load(core::sync::atomic::Ordering::Relaxed) } {
                defmt::warn!("[send] Not connected, dropping {:?} {:?}", $dtype, $data);
            } else {
                if let Err(e) = $data_sender.try_send(
                    $crate::Datapoint::new($dtype, $data, $crate::pconfig::ticks())
                ) {
                    defmt::error!("[send] data channel full: {:?}", e);
                    embassy_time::Timer::after_millis($timeout).await;
                }
            }
        }
    };
    ($data_sender:expr, $dtype:expr, $data:expr, $timestamp:expr; $timeout:expr) => {
        {
            if ! unsafe { $crate::CONNECTED.load(core::sync::atomic::Ordering::Relaxed) } {
                defmt::warn!("[send] Not connected, dropping {:?} {:?} {:?}", $dtype, $data, $timestamp);
            } else {
                if let Err(e) = $data_sender.try_send(
                    $crate::core::communication::Datapoint::new($dtype, $data, $timestamp)
                ) {
                    defmt::error!("[send] data channel full: {:?}", e);
                    embassy_time::Timer::after_millis($timeout).await;
                }
            }
        }
    };
}

// /// Instantly sends a datapoint through the MPMC queue.
// /// * If the queue is full, the event will be discarded.
// /// * This function will *not* block.
// /// * You need to specify a value for the timestamp (doesn't have to be a timestamp)
// /// * If you just want a timestamp as the timestamp, use [`send_data`] instead.
// pub fn send_dp(data_sender: DataSender, t: Datatype, d: u64, p: u64) {
//     match data_sender.try_send(Datapoint::new(t, d, p)) {
//         Ok(_) => {}
//         Err(e) => {
//             error!("[send] data channel full: {:?}", e)
//         }
//     }
// }

/// Block the current task in order to send an event through the MPMC queue.
/// * If there's space in the event queue, this will complete instantly
/// * Otherwise it will `await` until there's space.
/// * *If the event isn't critical and the current task
///   shouldn't block, please use [`send_event`] instead*
pub async fn queue_event(event_sender: EventSender, event: Event) { event_sender.send(event).await }

/// Block the current task in order to send a datapoint through the MPMC queue.
/// * If there's space in the event queue, this will complete instantly
/// * Otherwise it will `await` until there's space.
/// * *If the event isn't critical and the current task
///   shouldn't block, please use [`send_event`] instead*
pub async fn queue_data(data_sender: DataSender, t: Datatype, data: u64) {
    data_sender.send(Datapoint::new(t, data, ticks())).await
}

/// Block the current task in order to send a datapoint through the MPMC queue.
/// * If there's space in the event queue, this will complete instantly
/// * Otherwise it will `await` until there's space.
/// * *If the event isn't critical and the current task
///   shouldn't block, please use [`send_event`] instead*
/// * If you don't need to specify a specific timestamp, use [`queue_data`] instead
pub async fn queue_dp(data_sender: DataSender, t: Datatype, d: u64, p: u64) {
    data_sender.send(Datapoint::new(t, d, p)).await
}
