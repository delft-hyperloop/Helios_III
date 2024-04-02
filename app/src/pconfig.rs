use embassy_net::IpAddress::Ipv4;
use embassy_net::Ipv4Address;
use embassy_net::IpEndpoint;
use embassy_stm32::{Config, rcc};
use embassy_stm32::can::config;
use embassy_stm32::rcc::Pll;
use embedded_nal_async::{Ipv4Addr, SocketAddr, SocketAddrV4, TcpConnect};
use embassy_stm32::rcc::*;

use embedded_nal_async::AddrType::IPv4;

#[inline]
pub fn default_configuration() -> Config {
    let mut config = Config::default();

    config.rcc.hse = Some(rcc::Hse {
        freq: embassy_stm32::time::Hertz(24_000_000),
        mode: rcc::HseMode::Oscillator,
    });
    config.rcc.pll1 = Some(Pll {
        source: PllSource::HSE,
        prediv: PllPreDiv::DIV6,
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

    config
}

#[inline]
pub fn embassy_socket_from_config(t: ([u8;4],u16)) -> IpEndpoint {
    IpEndpoint::new(Ipv4(Ipv4Address::new(t.0[0],t.0[1],t.0[2],t.0[3])), t.1)
}

#[inline]
pub fn socket_from_config(t: ([u8;4],u16)) -> SocketAddr {
    SocketAddr::V4(SocketAddrV4::new(Ipv4Addr::new(t.0[0],t.0[1],t.0[2],t.0[3]), t.1))
}