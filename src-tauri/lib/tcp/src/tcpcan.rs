use std::{net::SocketAddr, ops::DerefMut, sync::Arc, time::Duration};

use color_print::cprintln;
use tokio::{
    io::{AsyncReadExt, AsyncWriteExt},
    net::{
        tcp::{OwnedReadHalf, OwnedWriteHalf},
        TcpStream,
    },
    sync::{oneshot, Mutex},
};

use canzero_common::TNetworkFrame;

use crate::{
    frame::{ConnectionHandshakeFrame, TcpFrame},
    wdg::Watchdog,
};

#[derive(Debug)]
pub struct ConnectionIdHost {
    free_list: std::sync::Mutex<Vec<u8>>,
}

impl ConnectionIdHost {
    pub fn new(max_id: u8) -> Self {
        let mut free_list = vec![];
        for id in 0..=max_id {
            free_list.push(id);
        }
        free_list.reverse();
        Self {
            free_list: std::sync::Mutex::new(free_list),
        }
    }

    pub fn alloc_id(&self) -> Option<u8> {
        self.free_list
            .lock()
            .expect("Failed to acquire ConnectionIdHost lock")
            .pop()
    }

    pub fn alloc_specific_id(&self, id: u8) -> Option<u8> {
        let mut lck = self
            .free_list
            .lock()
            .expect("Failed to acquire ConnectionIdHost lock");
        let pos = lck.iter().position(|i| i == &id);
        match pos {
            Some(pos) => {
                lck.remove(pos);
                Some(id)
            }
            None => None,
        }
    }

    pub fn free_id(&self, id: u8) {
        let mut lck = self
            .free_list
            .lock()
            .expect("Failed to acquire ConnectionIdHost lock");
        if !lck.iter().any(|i| i == &id) {
            lck.push(id);
        }
    }
}

#[derive(Debug)]
pub enum ConnectionId {
    Client {
        request_id: bool,
        sync_history: bool,
    },
    Host {
        id_host: Arc<ConnectionIdHost>,
        sync_history: Option<Vec<TNetworkFrame>>,
    },
}

#[derive(Debug)]
pub struct TcpCan {
    tx_stream: Arc<Mutex<OwnedWriteHalf>>,
    rx_stream: Mutex<OwnedReadHalf>,
    wdg: Watchdog,
    node_id: Option<u8>,
    id_host: Option<Arc<ConnectionIdHost>>,
    sync_complete: Mutex<Option<oneshot::Receiver<()>>>,
    sync_complete_signal: Mutex<Option<oneshot::Sender<()>>>,
}

impl TcpCan {
    pub async fn connect(
        socketaddr: SocketAddr,
        connection_id: ConnectionId,
    ) -> std::io::Result<Self> {
        let tcp_stream = tokio::net::TcpStream::connect(socketaddr).await?;
        Ok(Self::new(tcp_stream, connection_id).await?)
    }

    pub async fn new(tcp_stream: TcpStream, connection_id: ConnectionId) -> std::io::Result<Self> {

        tcp_stream.set_nodelay(true).unwrap();
        let (mut rx, mut tx) = tcp_stream.into_split();

        let (sync_tx, sync_rx) = oneshot::channel();

        let (node_id, sync_signal) = match &connection_id {
            ConnectionId::Client {
                request_id,
                sync_history,
            } => {
                let mut request = [0; 2];
                ConnectionHandshakeFrame::ClientServer {
                    request: *request_id,
                    sync: *sync_history,
                }
                .into_bin(&mut request);

                tx.write_all(&request).await.unwrap();

                if *request_id || *sync_history {
                    let mut rx_buffer = [0; 2usize];
                    match rx.read_exact(&mut rx_buffer).await {
                        Ok(_) => {
                            match ConnectionHandshakeFrame::from_bin(&rx_buffer) {
                                Ok(handshake_frame) => match handshake_frame {
                                    ConnectionHandshakeFrame::ServerClient { success, node_id } => {
                                        if success {
                                            if *sync_history {
                                                (Some(node_id), Some(sync_tx))
                                            } else {
                                                sync_tx.send(()).unwrap();
                                                (Some(node_id), None)
                                            }
                                        } else {
                                            panic!("Server rejected connection")
                                        }
                                    }
                                    ConnectionHandshakeFrame::ClientServer {
                                        request: _,
                                        sync: _,
                                    } => {
                                        panic!("Illegal request: This tcpcan doesn't act as a id server")
                                    }
                                },
                                Err(_) => panic!("Received ill formed TCP frame"),
                            }
                        }
                        Err(_) => {
                            panic!("Failed to read ConnectionHandshake TCP frame from socket")
                        }
                    }
                }else {
                    (None,None)
                }
            }
            ConnectionId::Host {
                id_host,
                sync_history,
            } => {
                let mut rx_buffer = [0; 2];
                match rx.read_exact(&mut rx_buffer).await {
                    Ok(_) => match ConnectionHandshakeFrame::from_bin(&rx_buffer) {
                        Ok(tcp_frame) => match tcp_frame {
                            ConnectionHandshakeFrame::ServerClient {
                                success: _,
                                node_id: _,
                            } => {
                                panic!("Unexpected response: Host received connection id response during handshake");
                            }
                            ConnectionHandshakeFrame::ClientServer { request, sync } => {
                                let node_id = if request {
                                    match id_host.alloc_id() {
                                        Some(node_id) => {
                                            let mut response = [0; 2];
                                            ConnectionHandshakeFrame::ServerClient {
                                                success: true,
                                                node_id,
                                            }
                                            .into_bin(&mut response);
                                            tx.write_all(&response).await.unwrap();
                                            Some(node_id)
                                        }
                                        None => {
                                            let mut response = [0; 2];
                                            ConnectionHandshakeFrame::ServerClient {
                                                success: true,
                                                node_id: 0,
                                            }
                                            .into_bin(&mut response);
                                            tx.write_all(&response).await.unwrap();
                                            None
                                        }
                                    }
                                } else {
                                    None
                                };

                                if sync {
                                    if let Some(sync_history) = sync_history {
                                        for frame in sync_history {
                                            let mut bytes = [0; 24];
                                            TcpFrame::NetworkFrame(frame.clone())
                                                .into_bin(&mut bytes);
                                            if let Err(_) = tx.write_all(&bytes).await {
                                                cprintln!("<yellow>Failed to transmit HistorySyncFrame.</yellow>")
                                            };
                                        }
                                        let mut bytes = [0; 24];
                                        TcpFrame::SyncEnd.into_bin(&mut bytes);
                                        if let Err(_) = tx.write_all(&bytes).await {
                                            cprintln!("<red>Failed to send SYNC_END frame.</red>");
                                            return Err(std::io::Error::new(
                                                std::io::ErrorKind::UnexpectedEof,
                                                "Failed to send SYNC_END frame.".to_owned(),
                                            ));
                                        };
                                    }
                                }
                                sync_tx.send(()).unwrap();
                                (node_id, None)
                            }
                        },
                        Err(_) => panic!("Received ill formed TCP frame"),
                    },
                    Err(_) => panic!("Failed to receive ConnectionHandshake TCP frame from socket"),
                }
            }
        };

        let tx = Arc::new(Mutex::new(tx));

        let keep_alive_sock = tx.clone();
        tokio::spawn(async move {
            let mut keep_alive_frame = [0u8; 24];
            TcpFrame::KeepAlive.into_bin(&mut keep_alive_frame);
            let mut interval = tokio::time::interval(Duration::from_millis(100));
            loop {
                interval.tick().await;
                if let Err(_) = keep_alive_sock
                    .lock()
                    .await
                    .write_all(&keep_alive_frame)
                    .await
                {
                    break; // Failed to send once -> stop sending keep alive completel! will
                           // eventually lead to none beeing returned from the recv() function!
                };
                // failed to send keep alive!
            }
        });

        let wdg = Watchdog::create(Duration::from_millis(3000));

        Ok(Self {
            sync_complete: Mutex::new(Some(sync_rx)),
            sync_complete_signal: Mutex::new(sync_signal),
            tx_stream: tx,
            rx_stream: Mutex::new(rx),
            wdg,
            node_id,
            id_host: match connection_id {
                ConnectionId::Client {
                    request_id: _,
                    sync_history: _,
                } => None,
                ConnectionId::Host {
                    id_host,
                    sync_history: _,
                } => Some(id_host),
            },
        })
    }

    pub async fn sync_complete(&self) {
        let mut sync_swap: Option<oneshot::Receiver<()>> = None;
        let mut sync_complete_guard = self.sync_complete.lock().await;
        let sync_complete = sync_complete_guard.deref_mut();
        std::mem::swap(sync_complete, &mut sync_swap);

        drop(sync_complete_guard);
        match sync_swap {
            Some(sync_complete) => {
                let _ = sync_complete.await;
            }
            None => (),
        };
    }

    pub async fn send(&self, frame: &TNetworkFrame) -> std::io::Result<()> {
        let mut bytes = [0; 24];
        TcpFrame::NetworkFrame(frame.clone()).into_bin(&mut bytes);
        self.tx_stream.lock().await.write_all(&bytes).await
    }

    pub async fn recv(&self) -> Option<TNetworkFrame> {
        let mut rx_lock = self.rx_stream.lock().await;
        let rx_stream = rx_lock.deref_mut();
        let mut rx_buffer = [0; 24];
        loop {
            tokio::select! {
                rx_res = rx_stream.read_exact(&mut rx_buffer) => {
                    match rx_res {
                        Ok(_) => match TcpFrame::from_bin(&rx_buffer).unwrap() {
                            TcpFrame::NetworkFrame(network_frame) => return Some(network_frame),
                            TcpFrame::KeepAlive => {
                                self.wdg.reset().await;
                            },
                            TcpFrame::SyncEnd => {
                                // what a clusterfuck
                                let mut sync_swap : Option<oneshot::Sender<()>>= None;
                                let mut sync_complete_signal_guard = self.sync_complete_signal.lock().await;
                                let sync_complete_signal = sync_complete_signal_guard.deref_mut();
                                std::mem::swap(sync_complete_signal, &mut sync_swap);
                                if let Some(sync_signal) = sync_swap {
                                    if let Err(_) = sync_signal.send(()) {
                                        cprintln!("<yellow>Received unexpected SYNC_DONE frame.</yellow>");
                                    }
                                };




                            },
                        },
                        Err(_) => {
                            cprintln!("<red>TCP connection closed</red>");
                            if let Some(host) = &self.id_host{
                                if let Some(node_id) = &self.node_id {
                                    host.free_id(*node_id);
                                }
                            }
                            return None;
                        }
                    }
                },
                _wdg_timeout = self.wdg.timeout() =>  {
                    cprintln!("<red>TCP connection watchdog timed out</red>");
                    if let Some(host) = &self.id_host{
                        if let Some(node_id) = &self.node_id {
                            host.free_id(*node_id);
                        }
                    }
                    return None;
                },
            }
        }
    }
    pub async fn addr(&self) -> std::io::Result<SocketAddr> {
        self.tx_stream.lock().await.peer_addr()
    }

    pub fn connection_id(&self) -> Option<u8> {
        return self.node_id;
    }
}
