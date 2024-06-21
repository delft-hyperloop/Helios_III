use std::{
    collections::HashSet, net::SocketAddr, sync::Arc, time::{Duration, Instant}
};

use color_print::cprintln;
use tokio::{
    net::UdpSocket,
    sync::{mpsc, Mutex},
    task::AbortHandle,
};

use crate::frame::{HelloFrame, NetworkDescription, UdpFrame};
use crate::service_id::{BROADCAST_PORT, SERVICE_NAME};

pub struct UdpNetworkScanner {
    socket: Arc<UdpSocket>,
    rx: Mutex<mpsc::Receiver<NetworkDescription>>,
    tx: mpsc::Sender<NetworkDescription>,
    task_handle: Arc<std::sync::Mutex<Option<AbortHandle>>>,
}

impl UdpNetworkScanner {
    pub async fn create() -> std::io::Result<UdpNetworkScanner> {
        let socket = tokio::net::UdpSocket::bind(&format!("0.0.0.0:0"))
            .await
            .map_err(|_| {
                std::io::Error::new(
                    std::io::ErrorKind::AddrInUse,
                    "UdpNetworkScanner already running on the system!".to_owned(),
                )
            })?;
        socket.set_broadcast(true)?;
        let (tx, rx) = mpsc::channel(16);

        Ok(UdpNetworkScanner {
            socket: Arc::new(socket),
            rx: Mutex::new(rx),
            tx,
            task_handle: Arc::new(std::sync::Mutex::new(None)),
        })
    }

    pub fn start(&self) {
        let mut task_handle_lock = self
            .task_handle
            .lock()
            .expect("Failed to acquire task_handle lock for UdpNetworkScanner");
        if task_handle_lock.is_none() {
            *task_handle_lock = Some(tokio::spawn(Self::broadcast_scanner_task(
                self.socket.clone(),
                self.tx.clone(),
            )).abort_handle());
        }
    }

    pub fn stop(&self) {
        let mut task_handle_lock = self.task_handle.lock().expect("Failed to acquire task_handle lock for UdpNetworkScanner");
        if let Some(abort_handle) = task_handle_lock.as_ref() {
            abort_handle.abort();
            *task_handle_lock = None;
        }
    }

    pub async fn next(&self) -> std::io::Result<NetworkDescription> {
        self.rx.lock().await.recv().await.ok_or(std::io::Error::new(
            std::io::ErrorKind::BrokenPipe,
            "UdpNetworkScanner task closed early".to_owned(),
        ))
    }

    pub async fn next_timeout(
        &self,
        timeout: Duration,
    ) -> Option<std::io::Result<NetworkDescription>> {
        match tokio::time::timeout(timeout, self.rx.lock().await.recv()).await {
            Ok(nd) => Some(nd.ok_or(std::io::Error::new(
                std::io::ErrorKind::BrokenPipe,
                "UdpNetworkScanner task closed early".to_owned(),
            ))),
            Err(_timeout) => None,
        }
    }


    async fn broadcast_scanner_task(socket: Arc<UdpSocket>, tx: mpsc::Sender<NetworkDescription>) {
        let mut rx_buffer = [0u8; 216];
        let mut interval = tokio::time::interval(Duration::from_millis(1000));

        let broadcast_addr = format!("255.255.255.255:{BROADCAST_PORT}");

        let mut hello_frame = [0;216];
        UdpFrame::Hello(HelloFrame {
            service_name: SERVICE_NAME.to_owned(),
        }).into_bin(&mut hello_frame);


        let mut discovered_networks: HashSet<SocketAddr> = HashSet::new();
        loop {
            interval.tick().await;
            let Ok(bytes_send) = socket.send_to(&hello_frame, &broadcast_addr).await else {
                cprintln!("<red>UdpNetworkScanner: Failed to send hello packet [retrying]</red>");
                continue;
            };
            assert_eq!(bytes_send, 216);

            let Ok(Ok((received_bytes, udp_server_addr))) = tokio::time::timeout(
                Duration::from_millis(1000),
                socket.recv_from(&mut rx_buffer),
            )
            .await
            else {
                continue;
            };
            assert_eq!(received_bytes, 216);

            let local_timebase = Instant::now();
            let Ok(frame) = UdpFrame::from_bin(&rx_buffer) else {
                cprintln!("<yellow>UdpNetworkScanner: Received ill formed frame from {} [ignored]</yellow>", {udp_server_addr});
                continue;
            };
            let UdpFrame::NDF(ndf) = frame else {
                continue;
            };
            if ndf.service_name != SERVICE_NAME {
                continue;
            }
            let socket_addr = SocketAddr::new(udp_server_addr.ip(), ndf.service_port);
            if !discovered_networks.contains(&socket_addr) {
                discovered_networks.insert(socket_addr);
                let nd = NetworkDescription {
                    server_addr: udp_server_addr.ip(),
                    server_name: ndf.server_name,
                    config_hash : ndf.config_hash,
                    build_time : ndf.build_time,
                    service_port: ndf.service_port,
                    timebase: local_timebase - ndf.time_since_sor,
                };
                let Ok(_) = tx.send(nd).await else {
                    cprintln!("<red>UdpNetworkScanner: Failed to forward network description over mpsc [aborted scan task]</red>");
                    break;
                };
            }
        }
    }
}

impl Drop for UdpNetworkScanner {
    fn drop(&mut self) {
        self.stop();
    }
}
