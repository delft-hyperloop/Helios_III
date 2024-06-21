pub mod connection;
mod deserialize;
pub mod errors;
pub mod frame;
mod gamepad;
mod handler;
pub mod network;
mod rx;
pub mod trace;
mod tx;
pub mod watchdog;

pub mod can_adapter;

use std::{
    sync::Arc,
    time::{Duration, Instant},
};

use self::{
    can_adapter::CanAdapter,
    connection::{ConnectionObject, ConnectionStatus},
    gamepad::Gamepad,
    network::{node_object::NodeObject, NetworkObject},
    rx::RxCom,
    trace::TraceObject,
    tx::TxCom,
    watchdog::{Watchdog, WatchdogOverlord, WdgTag},
};

use canzero_appdata::{AppData, WdgLevel};
use canzero_config::config;
use color_print::cprintln;

// Can Network Layer (CNL)
pub struct CNL {
    trace: Arc<TraceObject>,

    // NOTE RxCom is a zero sized struct just here for
    // easier understanding of the hierarchie of the CNL!
    #[allow(dead_code)]
    rx: RxCom,

    // TODO remove allow dead_code before release!
    #[allow(dead_code)]
    tx: Arc<TxCom>,
    network: Arc<NetworkObject>,
    connection_object: Arc<ConnectionObject>,

    _watchdog_overlord: WatchdogOverlord,
    external_watchdog: Option<Watchdog>,
}

impl CNL {
    pub async fn create(
        network_config: &config::NetworkRef,
        app_handle: &tauri::AppHandle,
        can_adapters: Vec<Arc<CanAdapter>>,
        timebase: Instant,
        node_id: Option<u8>,
        sync_complete: Option<tokio::sync::oneshot::Receiver<()>>,
    ) -> Self {


        let connection_object = Arc::new(ConnectionObject::new(
            ConnectionStatus::NetworkConnected,
            app_handle,
        ));

        let node_id = node_id.unwrap_or(network_config.nodes().len() as u8);

        let trace = Arc::new(TraceObject::create(app_handle));

        let tx = Arc::new(TxCom::create(
            &network_config,
            &can_adapters,
            &trace,
            timebase,
            &connection_object,
            node_id,
        ));

        let (deadlock_lvl, frontend_lvl) = match AppData::read() {
            Ok(app_data) => (
                app_data.get_deadlock_wdg_lvl(),
                app_data.get_frontend_wdg_lvl(),
            ),
            Err(_) => (WdgLevel::Active, WdgLevel::Active),
        };
        let watchdog_overlord = WatchdogOverlord::new(
            network_config,
            &connection_object,
            &tx,
            deadlock_lvl,
            frontend_lvl,
            &app_handle,
        );
        let gamepad = Gamepad::create(&tx, network_config);

        let network = Arc::new(NetworkObject::create(
            network_config,
            app_handle,
            tx.clone(),
            timebase,
            &watchdog_overlord,
        ));

        let rx = RxCom::create(
            network_config,
            &trace,
            &network,
            app_handle,
            &can_adapters,
            &connection_object,
            node_id,
        );

        // disable the frontend heartbeat only for release
        let mut external_watchdog = None;
        if frontend_lvl != WdgLevel::Disable {
            external_watchdog =
                Some(watchdog_overlord.register(WdgTag::FrontendWdg, Duration::from_millis(1000)));
        }

        if deadlock_lvl != WdgLevel::Disable {
            let deadlock_watchdog =
                watchdog_overlord.register(WdgTag::DeadlockWdg, Duration::from_millis(1000));
            let network_dead = network.clone();
            let trace_dead = trace.clone();
            let connection_object_dead = connection_object.clone();
            tokio::spawn(async move {
                let mut deadlock_interval = tokio::time::interval(Duration::from_millis(500));
                loop {
                    deadlock_interval.tick().await;
                    network_dead.deadlock_watchdog().await;
                    trace_dead.deadlock_watchdog().await;
                    connection_object_dead.deadlock_watchdog().await;
                    deadlock_watchdog.reset(false, None).await;
                }
            });
        }


        let connection_object_sync = connection_object.clone();
        match sync_complete{
            Some(sync_complete_signal) => {
                tokio::spawn(async move {
                    sync_complete_signal.await.expect("Failed to receive sync_complete signal");
                    connection_object_sync.set_status(ConnectionStatus::SyncDone);
                });
            }
            None => connection_object_sync.set_status(ConnectionStatus::SyncDone),
        }

        Self {
            rx,
            tx,
            trace,
            network,
            connection_object,
            _watchdog_overlord: watchdog_overlord,
            external_watchdog,
        }
    }

    pub fn trace(&self) -> &Arc<TraceObject> {
        &self.trace
    }

    pub fn nodes(&self) -> &Vec<Arc<NodeObject>> {
        self.network.nodes()
    }

    pub fn connection_object(&self) -> &Arc<ConnectionObject> {
        &self.connection_object
    }

    pub async fn reset_watchdog(&self) {
        if let Some(wdg) = &self.external_watchdog {
            wdg.reset(false, None).await;
        }
    }

    pub fn unregister_from_heartbeat(&self) {
        self._watchdog_overlord.unregister_from_heartbeat();
    }

    pub fn reregister_to_heartbeat(&self) {
        self._watchdog_overlord.reregister_to_heartbeat();
    }
}
