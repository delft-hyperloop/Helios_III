use embassy_net::IpAddress::Ipv4;
use embassy_net::Ipv4Address;
use embassy_net::{IpEndpoint, Ipv4Cidr};
use embassy_stm32::can::config;
use embassy_stm32::rcc::Pll;
use embassy_stm32::rcc::*;
use embassy_stm32::{rcc, Config};
use embedded_nal_async::{Ipv4Addr, SocketAddr, SocketAddrV4, TcpConnect};
// use embedded_hal::can::Id;
use crate::Event;
use embedded_can::{ExtendedId, Id};
use embedded_nal_async::AddrType::IPv4;

#[inline]
pub fn default_configuration() -> Config {
    let mut config = Config::default();

    // config.rcc.hse = Some(rcc::Hse { // THESE ARE THE CONFIGURATIONS FOR TIRTH's MAIN PCB
    //     freq: embassy_stm32::time::Hertz(24_000_000),
    //     mode: rcc::HseMode::Oscillator
    // });
    config.rcc.hse = Some(rcc::Hse {
        // THESE ARE THE CONFIGURATIONS FOR RUNNING ON NUCLEO'S
        freq: embassy_stm32::time::Hertz(24_000_000),
        mode: rcc::HseMode::Oscillator,
    });
    config.rcc.pll1 = Some(Pll {
        source: PllSource::HSE,
        prediv: PllPreDiv::DIV2,
        mul: PllMul::MUL50,
        divp: Some(PllDiv::DIV8),
        divq: Some(PllDiv::DIV8),
        divr: Some(PllDiv::DIV8),
    });
    // config.rcc.pll1 = Some(Pll {
    //     source: PllSource::HSI,
    //     prediv: PllPreDiv::DIV4,
    //     mul: PllMul::MUL50,
    //     divp: Some(PllDiv::DIV2),
    //     divq: None,
    //     divr: None,
    // });

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
pub fn ip_cidr_from_config(t: ([u8; 4], u16)) -> Ipv4Cidr {
    Ipv4Cidr::new(Ipv4Address::new(t.0[0], t.0[1], t.0[2], t.0[3]), 24)
}

#[inline]
pub fn socket_from_config(t: ([u8; 4], u16)) -> SocketAddr {
    SocketAddr::V4(SocketAddrV4::new(
        Ipv4Addr::new(t.0[0], t.0[1], t.0[2], t.0[3]),
        t.1,
    ))
}

#[inline]
pub fn bytes_to_u64(b: &[u8]) -> u64 {
    let mut x = 0u64;
    for i in 7..0 {
        x |= (b[i] as u64) << i;
    }
    x
}

pub fn id_as_value(id: &embedded_can::Id) -> u16 {
    match id {
        Id::Standard(x) => x.as_raw(),
        Id::Extended(y) => y.as_raw() as u16,
    }
}

pub fn extended_as_value(id: &ExtendedId) -> u16 {
    let temp = id.as_raw();
    let big_id = temp & (0xFFF0000)>>20;
    let mut small_id = temp & 0x00000FF;
    let dt = temp & 0x0000F00>>8;
    match dt {
        0x0 => small_id = small_id, // Normal Messages
        0x1 => small_id = small_id + 32, // Voltage Messages
        0x2 => small_id = small_id + 256, // Temp messages
        0x3 => small_id = small_id + 0, //  I wonder what are these
        0x5 => small_id = 0x5, // Current messages
        0x8 => small_id = small_id + 96, // Balance messages
        _ => small_id = small_id | 0x000,
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
                $event_sender.send(Event::BootingFailedEvent).await;
            }
            Err(err) => {
                defmt::error!("Failed to spawn task: {:?}", err);
                $event_sender.send(Event::BootingFailedEvent).await;
            }
        }
    };
}
