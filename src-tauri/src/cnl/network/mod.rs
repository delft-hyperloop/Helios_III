use std::{sync::Arc, time::Instant};

use self::node_object::NodeObject;
use canzero_config::config;

use super::{tx::TxCom, watchdog::WatchdogOverlord};

pub mod command_object;
pub mod node_object;
pub mod object_entry_object;

pub struct NetworkObject {
    nodes: Vec<Arc<NodeObject>>,
}

impl NetworkObject {
    pub fn create(
        network_config: &config::NetworkRef,
        app_handle: &tauri::AppHandle,
        tx_com: Arc<TxCom>,
        timebase: Instant,
        watchdog_overloard: &WatchdogOverlord,
    ) -> Self {
        Self {
            nodes: network_config
                .nodes()
                .iter()
                .map(|node_config| {
                    Arc::new(NodeObject::create(
                        network_config,
                        node_config,
                        app_handle,
                        tx_com.clone(),
                        timebase,
                        watchdog_overloard,
                    ))
                })
                .collect(),
        }
    }
    pub fn nodes(&self) -> &Vec<Arc<NodeObject>> {
        &self.nodes
    }
    pub async fn deadlock_watchdog(&self) {
        for n in &self.nodes {
            n.deadlock_watchdog().await;
        }
    }
}
