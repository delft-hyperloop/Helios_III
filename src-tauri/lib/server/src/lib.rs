use std::{
    sync::{Arc, Mutex},
    time::Instant,
};

use canzero_config::config::NetworkRef;
use canzero_tcp::tcpcan::{ConnectionId, ConnectionIdHost, TcpCan};
use canzero_udp::beacon::UdpNetworkBeacon;
use color_print::cprintln;
use tokio::{net::TcpListener, task::AbortHandle};

use self::network::{node::NetworkNode, Network};

pub mod network;

pub struct Server {
    network: Arc<Network>,
    timebase: Instant,
    welcome: Arc<TcpListener>,
    tcp_service_port: u16,
    task_handle: Arc<Mutex<Option<AbortHandle>>>,
    config: NetworkRef,
    id_host: Arc<ConnectionIdHost>,
}

impl Server {
    pub async fn create(config: NetworkRef) -> std::io::Result<Self> {
        let timebase = Instant::now();

        let id_host = ConnectionIdHost::new((config.nodes().len() + 16) as u8);
        for n in config.nodes() {
            id_host.alloc_specific_id(n.id());
        }

        let network = Network::new();

        #[cfg(feature = "socket-can")]
        {
            network
                .start(NetworkNode::SocketCanNode(
                    canzero_socketcan::socket_can::SocketCan::connect().await?,
                ))
                .await
        }

        let tcp_listener = TcpListener::bind("0.0.0.0:0").await?;
        let tcp_service_port = tcp_listener.local_addr().unwrap().port();
        cprintln!("<green>Successfully bound TCP welcome socket at {tcp_service_port}</green>");

        Ok(Self {
            network: Arc::new(network),
            timebase,
            welcome: Arc::new(tcp_listener),
            tcp_service_port,
            task_handle: Arc::new(Mutex::new(None)),
            config,
            id_host: Arc::new(id_host),
        })
    }

    pub fn start(&self) {
        cprintln!("<green>Starting Server</green>");
        let mut task_lock = self
            .task_handle
            .lock()
            .expect("Failed to acquire task lock at Server");
        if task_lock.is_none() {
            *task_lock = Some(
                tokio::spawn(Self::server_task(
                    self.network.clone(),
                    self.timebase,
                    self.welcome.clone(),
                    self.tcp_service_port,
                    self.config.clone(),
                    self.id_host.clone(),
                ))
                .abort_handle(),
            );
        }
    }

    pub fn stop(&self) {
        let mut task_lock = self
            .task_handle
            .lock()
            .expect("Failed to acquire task lock at Server");
        let Some(abort_handle) = task_lock.as_ref() else {
            return;
        };
        abort_handle.abort();
        *task_lock = None;
        cprintln!("<red>Server Stopped</red>");
    }

    async fn server_task(
        network: Arc<Network>,
        timebase: Instant,
        welcome: Arc<TcpListener>,
        tcp_service_port: u16,
        config: NetworkRef,
        id_host: Arc<ConnectionIdHost>,
    ) {
        async fn pserver_task(
            network: &Network,
            timebase: Instant,
            welcome: &TcpListener,
            tcp_service_port: u16,
            config: NetworkRef,
            id_host: Arc<ConnectionIdHost>,
        ) -> std::io::Result<()> {
            let server_name = format!("{}@{}", whoami::devicename(), whoami::username());
            let beacon =
                UdpNetworkBeacon::create(tcp_service_port, timebase, &server_name, config).await?;
            beacon.start();
            cprintln!("<green>Successfully started UDP Beacon</green>");

            loop {
                let (stream, addr) = welcome.accept().await.unwrap();
                println!("\u{1b}[32mConnection from {addr:?}\u{1b}[0m");
                network
                    .start(NetworkNode::TcpCanNode(
                        TcpCan::new(
                            stream,
                            ConnectionId::Host {
                                id_host: id_host.clone(),
                                sync_history: Some(network.sync_history().await),
                            },
                        )
                        .await?,
                    ))
                    .await;
            }
        }
        loop {
            let Err(err) = pserver_task(
                &network,
                timebase,
                &welcome,
                tcp_service_port,
                config.clone(),
                id_host.clone(),
            )
            .await
            else {
                continue;
            };
            cprintln!("<red>ServerError : {err:?} </red>");
            cprintln!("<red>ServerError : Stopped </red>");
        }
    }
}

impl Drop for Server {
    fn drop(&mut self) {
        self.stop();
    }
}
