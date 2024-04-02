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
use embedded_io_async::{Read, Write};
use embedded_nal_async::{Ipv4Addr, SocketAddr, SocketAddrV4, TcpConnect};
use rand_core::RngCore;
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};
use embassy_net::{Ipv4Cidr, Ipv4Address};
use embassy_net::tcp::TcpWriter;
use embassy_stm32::gpio::{Level, Output, Speed};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::Sender;
use heapless::binary_heap::Max;
use heapless::Vec;
use crate::{DataReceiver, GS_IP_ADDRESS, GS_UPD_IP_ADDRESS, NETWORK_BUFFER_SIZE};
use crate::core::finite_state_machine::Event;
use crate::pconfig::socket_from_config;


#[embassy_executor::task]
pub async fn ground_station_message_dispatcher(mut writer: TcpWriter<'static>, data_receiver: DataReceiver) -> ! {
    loop {
        let data = data_receiver.receive().await;
        let mut data = data.as_bytes();
        writer.write_all(&mut data).await.unwrap();
    }
}