use std::{
    sync::{Arc, Mutex},
    time::Instant,
};

use build_time::build_time_local;
use canzero_config::config::NetworkRef;
use tokio::net::UdpSocket;

use crate::frame::{NetworkDescriptionFrame, UdpFrame};

use crate::service_id::{BROADCAST_PORT, SERVICE_NAME};

pub struct UdpNetworkBeacon {
    beacon_name: String,
    tcp_service_port: u16,
    timebase: Instant,
    socket: Arc<UdpSocket>,
    task_handle: Arc<Mutex<Option<tokio::task::AbortHandle>>>,
    config_hash: u64,
}

impl UdpNetworkBeacon {
    pub async fn create(
        tcp_service_port: u16,
        timebase: Instant,
        beacon_name: &str,
        config: NetworkRef,
    ) -> std::io::Result<UdpNetworkBeacon> {
        let socket = tokio::net::UdpSocket::bind(&format!("0.0.0.0:{BROADCAST_PORT}"))
            .await
            .map_err(|_| {
                std::io::Error::new(
                    std::io::ErrorKind::AddrInUse,
                    "UdpNetworkBeacon already hosted on the system!".to_owned(),
                )
            })?;
        socket.set_broadcast(true)?; //<- Check if actually required

        let config_hash = config.portable_hash();

        Ok(UdpNetworkBeacon {
            beacon_name: beacon_name.to_owned(),
            tcp_service_port,
            timebase,
            socket: Arc::new(socket),
            task_handle: Arc::new(Mutex::new(None)),
            config_hash,
        })
    }

    pub fn start(&self) {
        let mut task_handle_lock = self
            .task_handle
            .lock()
            .expect("Failed to acquire task_handle lock at UdpNetworkBeacon");
        if task_handle_lock.is_none() {
            *task_handle_lock = Some(
                tokio::task::spawn(Self::beacon_task(
                    self.beacon_name.clone(),
                    self.tcp_service_port,
                    self.socket.clone(),
                    self.timebase,
                    self.config_hash,
                ))
                .abort_handle(),
            );
        }
    }
    pub fn stop(&self) {
        let mut task_handle_lock = self
            .task_handle
            .lock()
            .expect("Failed to acquire task_handle lock at UdpNetowkrBeacon");
        let Some(abort_handle) = task_handle_lock.as_ref() else {
            return;
        };
        abort_handle.abort();
        *task_handle_lock = None;
    }

    async fn beacon_task(
        beacon_name: String,
        service_port: u16,
        socket: Arc<UdpSocket>,
        timebase: Instant,
        config_hash: u64,
    ) {
        let addr = socket.peer_addr().unwrap_or(socket.local_addr().unwrap());
        loop {
            loop {
                let mut rx_buffer = [0; 216];
                println!("\u{1b}[34mUDP-Beacon: listening {}\u{1b}[0m", addr);
                let (bytes_received, source_addr) = socket
                    .recv_from(&mut rx_buffer)
                    .await
                    .expect("Failed to receive from UDP socket");
                assert_eq!(bytes_received, 216);
                let time_since_sor = Instant::now() - timebase;
                println!("\u{1b}[34mUDP-Reflector: received hello from {source_addr}\u{1b}[0m");
                let service_name = SERVICE_NAME.to_owned();
                let server_name = beacon_name.to_owned();
                let socket = socket.clone();
                tokio::spawn(async move {
                    let Ok(frame) = UdpFrame::from_bin(&rx_buffer) else {
                        println!(
                            "\u{1b}[34mUDP-Beacon: Received ill formed frame [ignored]\u{1b}[0m"
                        );
                        return;
                    };
                    let UdpFrame::Hello(hello_frame) = frame else {
                        return;
                    };
                    if hello_frame.service_name != service_name {
                        println!("\u{1b}[34mUDP-Beacon: Received hello from service {:?}. Expecting {:?} [ignored]\u{1b}[0m",
                        hello_frame.service_name,
                        service_name);
                    }
                    let ndf = NetworkDescriptionFrame {
                        service_name,
                        service_port,
                        config_hash,
                        build_time: build_time_local!().to_owned(),
                        time_since_sor,
                        server_name,
                    };
                    println!("\u{1b}[34mUDP-Beacon: responding to {source_addr}\u{1b}[33m");
                    let mut ndf_buf = [0; 216];
                    UdpFrame::NDF(ndf).into_bin(&mut ndf_buf);
                    let Ok(bytes_send) = socket.send_to(&ndf_buf, &source_addr).await else {
                        println!(
                            "\u{1b}[34mUDP-Beacon: Failed to respond {source_addr}\u{1b}[33m"
                        );
                        return;
                    };
                    assert_eq!(bytes_send, 216);
                });
            }
        }
    }
}

impl Drop for UdpNetworkBeacon {
    fn drop(&mut self) {
        self.stop();
    }
}
