use std::{net::SocketAddr, sync::Arc, time::Instant};

use crate::notification::notify_warning;

use canzero_common::{NetworkFrame, TCanError, TCanFrame, TNetworkFrame, Timestamped};
use canzero_tcp::tcpcan::{ConnectionId, TcpCan};
use canzero_udp::frame::NetworkDescription;

pub struct TcpClient {
    tcpcan: Arc<TcpCan>,
    timebase: Instant,
}

impl TcpClient {
    pub async fn create(
        network_description: &NetworkDescription,
        app_handle: &tauri::AppHandle,
        can_rx_adapters: Vec<tokio::sync::mpsc::Sender<Option<Result<TCanFrame, TCanError>>>>,
    ) -> std::io::Result<Self> {
        let app_handle = app_handle.clone();
        let address = SocketAddr::new(
            network_description.server_addr,
            network_description.service_port,
        );
        let stream = tokio::net::TcpStream::connect(address).await?;

        let tcpcan = Arc::new(
            TcpCan::new(
                stream,
                ConnectionId::Client {
                    request_id: true,
                    sync_history: true,
                },
            )
            .await
            .unwrap(),
        );
        let tcpcan_rx = tcpcan.clone();
        tokio::spawn(async move {
            loop {
                let Some(tnetwork_frame) = tcpcan_rx.recv().await else {
                    for adapter in can_rx_adapters {
                        adapter.send(None).await.expect("Failed to forward error can frame");
                    }
                    break;
                };

                let network_frame = tnetwork_frame.value;
                let timestamp = tnetwork_frame.timestamp;
                let bus_id = network_frame.bus_id;
                let can_frame = network_frame.can_frame;

                let Some(can_rx_adapter) = can_rx_adapters.get(bus_id as usize) else {
                    eprintln!("Received invalid NetworkFrame with invalid bus id (dropped frame)");
                    continue;
                };

                let Ok(_) = can_rx_adapter
                    .send(Some(Ok(Timestamped::new(timestamp, can_frame))))
                    .await
                else {
                    notify_warning(
                        &app_handle,
                        "Failed to Send Frame",
                        "Error during sending on the TCP connection to the network",
                        chrono::offset::Local::now(),
                    );
                    continue;
                };
            }
        });
        Ok(Self {
            tcpcan,
            timebase: network_description.timebase,
        })
    }
    
    pub async fn sync_complete(&self) {
        self.tcpcan.sync_complete().await;
    }

    pub async fn send(&self, frame: NetworkFrame) -> std::io::Result<()> {
        self.tcpcan
            .send(&TNetworkFrame::now(self.timebase, frame))
            .await
    }

    pub fn node_id(&self) -> u8 {
        self.tcpcan
            .connection_id()
            .expect("Expected a connection_requested during handshake")
    }
}
