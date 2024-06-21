use std::{net::SocketAddr, time::Duration};

use canzero_appdata::AppData;
use canzero_config::config::MessageId;
use canzero_tcp::tcpcan::ConnectionId;
use canzero_udp::{frame::NetworkDescription, scanner::UdpNetworkScanner};
use color_print::cprintln;

use crate::errors::{Error, Result};

pub async fn discover() -> Result<NetworkDescription> {
    let scanner = UdpNetworkScanner::create().await?;
    scanner.start();
    match scanner.next_timeout(Duration::from_millis(1000)).await {
        Some(Ok(con)) => Ok(con),
        _ => Err(Error::NoServerFound),
    }
}

pub async fn command_dump(filter_msg_names: Vec<String>, filter_ids: Vec<String>) -> Result<()> {
    if !filter_ids.is_empty() {
        return Err(Error::NotYetImplemented);
    }
    let filter_ids: Vec<MessageId> = vec![];
    let appdata = AppData::read()?;
    let network_config = appdata.config()?;

    let network = discover().await?;

    let connection =
        tokio::net::TcpStream::connect(SocketAddr::new(network.server_addr, network.service_port))
            .await
            .unwrap();

    cprintln!(
        "<green>Successfully connected to {} at {}:{}</green>",
        network.server_name,
        network.server_addr,
        network.service_port
    );

    let tcpcan = canzero_tcp::tcpcan::TcpCan::new(
        connection,
        ConnectionId::Client {
            request_id: false,
            sync_history: false,
        },
    )
    .await.unwrap();

    loop {
        let Some(frame) = tcpcan.recv().await else {
            println!("Connection closed");
            return Ok(());
        };
        let timestamp = &frame.timestamp;
        let tsec = timestamp.as_secs_f32();
        let bus_id = &frame.bus_id;
        let bus = network_config
            .buses()
            .iter()
            .find(|b| b.id() == *bus_id)
            .map_or("can?", |b| b.name());
        let can_frame = &frame.can_frame;
        let id = if can_frame.get_ide_flag() {
            MessageId::ExtendedId(can_frame.get_id())
        } else {
            MessageId::StandardId(can_frame.get_id())
        };
        let msg_name = network_config
            .messages()
            .iter()
            .find(|m| m.id() == &id)
            .map_or("???", |m| m.name());
        let pass = if !filter_msg_names.is_empty() {
            filter_msg_names.iter().any(|msg| msg == msg_name)
        } else {
            true
        };
        let pass = pass
            || if !filter_ids.is_empty() {
                filter_ids.iter().any(|x| x == &id)
            } else {
                false
            };
        if pass {
            let dlc = can_frame.get_dlc();
            let mask = 0xFFFFFFFFFFFFFFFFu64
                .checked_shr(64u32 - dlc as u32 * 8u32).unwrap_or(0);
            let data = can_frame.get_data_u64() & mask;
            println!("{tsec:08.2}s : {bus:4} {id:5} [{dlc:1}] {data:016X}  ({msg_name})");
        }
    }
}
