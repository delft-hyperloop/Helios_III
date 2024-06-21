use std::{
    net::SocketAddr,
    sync::Arc,
    time::{Duration, Instant},
};

use canzero_appdata::AppData;
use canzero_common::{CanFrame, NetworkFrame, TNetworkFrame};
use canzero_config::config;
use canzero_tcp::tcpcan::{ConnectionId, TcpCan};
use chrono::{DateTime, Datelike, NaiveDate, NaiveDateTime, NaiveTime, Timelike};
use color_print::cprintln;

use crate::{dump::discover, errors::Result};

async fn rx_get_req_hash_code(
    tcpcan: Arc<TcpCan>,
    resp_id: u32,
    resp_ide: bool,
    node_id: u8,
    my_id: u8,
) -> u64 {
    let mut hash: u64 = 0;
    let mut rx_count = 0;
    loop {
        let tnf = tcpcan.recv().await;
        let can_frame = tnf.unwrap().value.can_frame;
        if can_frame.get_id() == resp_id && can_frame.get_ide_flag() == resp_ide {
            let data = can_frame.get_data_u64();
            let client_id = ((data & (0xFFu64 << 16)) >> 16) as u8;
            let server_id = ((data & (0xFFu64 << 24)) >> 24) as u8;

            if client_id != my_id {
                continue;
            }
            if server_id != node_id {
                continue;
            }
            if rx_count == 0 {
                hash |= data >> 32;
                rx_count = 1;
            } else if rx_count == 1 {
                hash |= data & (0xFFFFFFFFu64 << 32);
                break;
            }
        }
    }
    return hash;
}

async fn rx_get_req_build_time(
    tcpcan: Arc<TcpCan>,
    resp_id: u32,
    resp_ide: bool,
    node_id: u8,
    my_id: u8,
) -> Option<NaiveDateTime> {
    let mut build_time_data: u64 = 0;
    let mut rx_count = 0;
    loop {
        let tnf = tcpcan.recv().await;
        let can_frame = tnf.unwrap().value.can_frame;
        if can_frame.get_id() == resp_id && can_frame.get_ide_flag() == resp_ide {
            let data = can_frame.get_data_u64();
            let client_id = ((data & (0xFFu64 << 16)) >> 16) as u8;
            let server_id = ((data & (0xFFu64 << 24)) >> 24) as u8;

            if client_id != my_id {
                continue;
            }
            if server_id != node_id {
                continue;
            }
            if rx_count == 0 {
                build_time_data |= data >> 32;
                rx_count = 1;
            } else if rx_count == 1 {
                build_time_data |= data & (0xFFFFFFFFu64 << 32);
                break;
            }
        }
    }
    let year = build_time_data & 0xFFFF;
    let month = (build_time_data >> 16) & 0xFF;
    let day = (build_time_data >> 24) & 0xFF;
    let hour = (build_time_data >> 32) & 0xFF;
    let min = (build_time_data >> 40) & 0xFF;
    let sec = (build_time_data >> 48) & 0xFF;
    Some(NaiveDateTime::new(
        NaiveDate::from_ymd_opt(year as i32, month as u32, day as u32)?,
        NaiveTime::from_hms_opt(hour as u32, min as u32, sec as u32)?,
    ))
}

pub async fn command_status() -> Result<()> {
    let appdata = AppData::read()?;
    let network_config = appdata.config()?;
    let network_hash = network_config.portable_hash();

    let now = Instant::now();
    let network = discover().await?;
    let timebase = network.timebase;

    let stream =
        tokio::net::TcpStream::connect(SocketAddr::new(network.server_addr, network.service_port))
            .await
            .unwrap();

    let tcpcan = Arc::new(
        canzero_tcp::tcpcan::TcpCan::new(
            stream,
            ConnectionId::Client {
                request_id: true,
                sync_history: false,
            },
        )
        .await.unwrap(),
    );

    let my_id = tcpcan.connection_id().unwrap();

    let get_req = network_config.get_req_message();

    let (req_id, req_ide) = match get_req.id() {
        config::MessageId::StandardId(id) => (id, false),
        config::MessageId::ExtendedId(id) => (id, true),
    };
    let get_req_bus_id = network_config.get_req_message().bus().id();

    let server_build_time = DateTime::parse_from_rfc3339(&network.build_time).unwrap();

    println!("network hash = {}", network.config_hash);
    if network.config_hash == network_hash {
        cprintln!(
            "{:25} : <green> {:7}</green> ({:0>4}-{:0>2}-{:0>2} {:0>2}:{:0>2}:{:0>2})",
            "SERVER",
            "ONLINE",
            server_build_time.year(),
            server_build_time.month(),
            server_build_time.day(),
            server_build_time.hour(),
            server_build_time.minute(),
            server_build_time.second()
        );
    } else {
        cprintln!(
            "{:25} : <yellow> {:7}</yellow> ({:0>4}-{:0>2}-{:0>2} {:0>2}:{:0>2}:{:0>2})",
            "SERVER",
            "DESYNC",
            server_build_time.year(),
            server_build_time.month(),
            server_build_time.day(),
            server_build_time.hour(),
            server_build_time.minute(),
            server_build_time.second()
        );
    }

    for node in network_config.nodes() {
        let config_hash_oe = node
            .object_entries()
            .iter()
            .find(|oe| oe.name() == "config_hash")
            .unwrap();
        let mut req_hash_data: u64 = 0;
        req_hash_data |= config_hash_oe.id() as u64;
        req_hash_data |= (my_id as u64) << 13;
        req_hash_data |= (node.id() as u64) << (13 + 8);

        let get_req_hash_frame =
            CanFrame::new(*req_id, req_ide, false, get_req.dlc(), req_hash_data);

        let build_time_oe = node
            .object_entries()
            .iter()
            .find(|oe| oe.name() == "build_time")
            .unwrap();

        let mut req_build_time_data: u64 = 0;
        req_build_time_data |= build_time_oe.id() as u64;
        req_build_time_data |= (my_id as u64) << 13;
        req_build_time_data |= (node.id() as u64) << (13 + 8);

        let req_build_time_frame =
            CanFrame::new(*req_id, req_ide, false, get_req.dlc(), req_build_time_data);

        // spawn receiver
        let rxcan = tcpcan.clone();

        let timestamp = Instant::now().duration_since(timebase);
        tcpcan
            .send(&TNetworkFrame::new(
                timestamp,
                NetworkFrame {
                    bus_id: get_req_bus_id,
                    can_frame: get_req_hash_frame,
                },
            ))
            .await
            .unwrap();

        if let Ok(hash) = tokio::time::timeout(
            Duration::from_millis(250),
            rx_get_req_hash_code(
                rxcan.clone(),
                network_config.get_resp_message().id().as_u32(),
                network_config.get_resp_message().id().ide(),
                node.id(),
                my_id,
            ),
        )
        .await
        {
            tokio::time::sleep(Duration::from_millis(100)).await;
            let timestamp = Instant::now().duration_since(timebase);
            tcpcan
                .send(&TNetworkFrame::new(
                    timestamp,
                    NetworkFrame {
                        bus_id: get_req_bus_id,
                        can_frame: req_build_time_frame,
                    },
                ))
                .await
                .unwrap();

            if let Ok(Some(build_time)) = tokio::time::timeout(
                Duration::from_millis(250),
                rx_get_req_build_time(
                    rxcan,
                    network_config.get_resp_message().id().as_u32(),
                    network_config.get_resp_message().id().ide(),
                    node.id(),
                    my_id,
                ),
            )
            .await
            {
                if hash == network_hash {
                    cprintln!(
                        "{:25} : <green> {:7}</green> ({:0>4}-{:0>2}-{:0>2} {:0>2}:{:0>2}:{:0>2})",
                        node.name(),
                        "ONLINE",
                        build_time.year(),
                        build_time.month(),
                        build_time.day(),
                        build_time.hour(),
                        build_time.minute(),
                        build_time.second()
                    );
                } else {
                    cprintln!(
                    "{:25} : <yellow> {:7}</yellow> ({:0>4}-{:0>2}-{:0>2} {:0>2}:{:0>2}:{:0>2}) [{}]",
                    node.name(),
                    "DESYNC",
                    build_time.year(),
                    build_time.month(),
                    build_time.day(),
                    build_time.hour(),
                    build_time.minute(),
                    build_time.second(),
                    hash,
                );
                }
            } else {
                cprintln!("{:25} : <red> {:7}</red>", node.name(), "FUCKED");
            }
        } else {
            cprintln!("{:25} : <red> {:7}</red>", node.name(), "OFFLINE");
        }
    }

    Ok(())
}
