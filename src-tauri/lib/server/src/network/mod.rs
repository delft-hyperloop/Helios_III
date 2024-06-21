use std::sync::{atomic::AtomicU32, Arc};

use canzero_common::TNetworkFrame;
use color_print::cprintln;
use tokio::sync::{Mutex, RwLock};

use self::node::NetworkNode;

pub mod node;

pub struct Network {
    nodes: Arc<RwLock<Vec<(u32, Arc<NetworkNode>)>>>,
    history: Arc<Mutex<Vec<TNetworkFrame>>>,
    id_acc: AtomicU32,
}

impl Network {
    pub fn new() -> Self {
        Self {
            nodes: Arc::new(RwLock::new(vec![])),
            id_acc: AtomicU32::new(0),
            history: Arc::new(Mutex::new(vec![])),
        }
    }

    pub async fn sync_history(&self) -> Vec<TNetworkFrame> {
        return self.history.lock().await.clone() //hopefully fast enough
    }

    pub async fn start(&self, node: NetworkNode) {
        match &node {
            #[cfg(feature = "socket-can")]
            NetworkNode::SocketCanNode(_) => {
                cprintln!("<green>Establish socketcan connection</green>");
            }
            NetworkNode::TcpCanNode(tcpcan) => {
                let addr = match tcpcan.addr().await {
                    Ok(addr) => addr,
                    Err(_) => {
                        cprintln!("<red>Can't resolve connection addr [rejected connection]</red>");
                        return;
                    }
                };
                cprintln!("<green>Establish tcp connection {}</green>", addr);
            }
        }
        let nodes = self.nodes.clone();
        let node_id = self
            .id_acc
            .fetch_add(1, std::sync::atomic::Ordering::SeqCst);
        let node = Arc::new(node);
        nodes.write().await.push((node_id, node.clone()));
        let history = self.history.clone();
        tokio::spawn(async move {
            loop {
                let Some(frame) = node.recv().await else {
                    break;
                };
                for (id, node) in nodes.read().await.iter() {
                    if *id != node_id {
                        // ignore loop back!
                        if let Err(err) = node.send(&frame).await {
                            eprintln!("{err:?}");
                        };
                    }
                }
                history.lock().await.push(frame);
            }
            // remove node
            let mut nodes_lock = nodes.write().await;
            let Some(node_pos) = nodes_lock.iter().position(|(id, _)| *id == node_id) else {
                return;
            };
            nodes_lock.remove(node_pos);
            match node.as_ref() {
                #[cfg(feature = "socket-can")]
                NetworkNode::SocketCanNode(_) => {
                    cprintln!("<red>Shutdown socketcan connection</red>")
                }
                NetworkNode::TcpCanNode(tcp) => {
                    let addr = match tcp.addr().await {
                        Ok(addr) => addr,
                        Err(_) => {
                            cprintln!(
                                "???"
                            );
                            return;
                        }
                    };
                    cprintln!("<red>Shutdown tcp connection {}</red>", addr)
                }
            };
        });
    }
}
