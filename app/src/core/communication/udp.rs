use defmt::*;
use embassy_executor::Spawner;
use embassy_net::tcp::client::{TcpClient, TcpClientState};
use embassy_net::{Stack, StackResources};
use embassy_stm32::eth::generic_smi::GenericSMI;
use embassy_stm32::eth::{Ethernet, PacketQueue, PHY};
use embassy_stm32::peripherals::ETH;
use embassy_stm32::rng::Rng;
use embassy_stm32::{bind_interrupts, eth, peripherals, rng, Config};
use embassy_time::Timer;
use embedded_io_async::Write;
use embedded_nal_async::{Ipv4Addr, SocketAddr, SocketAddrV4, TcpConnect};
use rand_core::RngCore;
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};
use embassy_net::{Ipv4Cidr, Ipv4Address};
use embassy_stm32::gpio::{Level, Output, Speed};
use heapless::Vec;
use crate::{GS_IP_ADDRESS, GS_UPD_IP_ADDRESS};
use crate::pconfig::socket_from_config;

#[embassy_executor::task]
pub async fn udp_connection_handler(stack: &'static Stack<Ethernet<'static, ETH, GenericSMI>>) -> ! {
    stack.wait_config_up().await;

    let state: TcpClientState<1, 1024, 1024> = TcpClientState::new();

    let client = TcpClient::new(&stack, &state);

    let gs_addr_udp = socket_from_config(GS_UPD_IP_ADDRESS);
    loop {
        Timer::after_millis(1000).await;
        debug!("udp bing chilling");
    }
}