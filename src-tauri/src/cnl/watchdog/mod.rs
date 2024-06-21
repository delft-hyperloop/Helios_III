use std::{
    sync::{Arc, Mutex},
    time::Duration,
};

use canzero_appdata::WdgLevel;
use canzero_config::config::NetworkRef;
use chrono::Local;
use color_print::cprintln;
use serde::Serialize;
use tokio::{
    select,
    sync::{mpsc, watch},
    task::AbortHandle,
    time::Instant,
};

use crate::{cnl::connection::ConnectionStatus, notification::notify_warning};

use super::{connection::ConnectionObject, tx::TxCom};

struct WatchdogSignal {
    unregister: bool,
    ticks_next: Option<u8>,
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum WdgTag {
    FrontendWdg,
    DeadlockWdg,
    Heartbeat { node_id: u8, bus_id: u32 },
}

#[derive(Copy, Clone, Serialize)]
pub enum WdgStatus {
    TimedOut,
    Good,
    InActive,
}

pub struct WatchdogTimeout {
    pub tag: WdgTag,
    pub error: WatchdogError,
}

#[derive(Debug, Clone)]
pub enum WatchdogError {
    Timeout,
    PoisonError, // channel dropped early
}

struct WatchdogInner {
    abort_handle: AbortHandle,
    reset_tx: mpsc::Sender<WatchdogSignal>,
    status_rx: watch::Receiver<WdgStatus>,
    overlord: Arc<WatchdogOverlordInner>,
    tag: WdgTag,
}

pub struct Watchdog(Arc<WatchdogInner>);

impl Watchdog {
    fn create(tag: WdgTag, timeout: Duration, overlord: Arc<WatchdogOverlordInner>) -> Self {
        let (reset_tx, reset_rx) = mpsc::channel(16);
        let (status_tx, status_rx) = watch::channel(WdgStatus::InActive);

        let abort_handle = tokio::spawn(Self::watchdog_task(
            reset_rx,
            status_tx,
            timeout,
            overlord.clone(),
            tag,
        ))
        .abort_handle();

        Watchdog(Arc::new(WatchdogInner {
            abort_handle,
            reset_tx,
            status_rx,
            overlord,
            tag,
        }))
    }

    pub fn tag(&self) -> &WdgTag {
        &self.0.tag
    }

    pub fn status_rx(&self) -> &watch::Receiver<WdgStatus> {
        &self.0.status_rx
    }

    async fn watchdog_task(
        mut reset_rx: mpsc::Receiver<WatchdogSignal>,
        status_tx: watch::Sender<WdgStatus>,
        timeout: Duration,
        overlord: Arc<WatchdogOverlordInner>,
        wdg_tag: WdgTag,
    ) {
        let sleep = tokio::time::sleep(timeout);
        tokio::pin!(sleep);
        let mut active = false;
        loop {
            tokio::select! {
                Some(WatchdogSignal{unregister, ticks_next}) = reset_rx.recv() => {
                    active = !unregister;
                    if active {
                        let _ = status_tx.send(WdgStatus::Good);
                    } else {
                        let _ = status_tx.send(WdgStatus::InActive);
                    }
                    match ticks_next {
                        Some(ticks) => sleep.as_mut().reset(Instant::now() + Duration::from_millis(50 * ticks as u64)),
                        None => sleep.as_mut().reset(Instant::now() + timeout),
                    };
                },
                () = sleep.as_mut(), if active => {
                    overlord.notify_timeout(WatchdogTimeout {
                        tag : wdg_tag,
                        error : WatchdogError::Timeout,
                    });
                    let _ = status_tx.send(WdgStatus::TimedOut);
                    sleep.as_mut().reset(Instant::now() + Duration::from_secs(10))
                },
            }
        }
    }

    pub async fn reset(&self, unregister: bool, ticks_next: Option<u8>) {
        if let Err(_) = self
            .0
            .reset_tx
            .send(WatchdogSignal {
                unregister,
                ticks_next,
            })
            .await
        {
            self.0.overlord.notify_timeout(WatchdogTimeout {
                tag: self.0.tag,
                error: WatchdogError::PoisonError,
            });
        }
    }

    pub fn status(&self) -> WdgStatus {
        *self.0.status_rx.borrow()
    }
}

impl Drop for Watchdog {
    fn drop(&mut self) {
        self.0.abort_handle.abort();
    }
}

#[derive(Clone, Copy)]
enum OverlordTimeoutSignal {
    Good,
    Bad,
    Unregister,
}

struct WatchdogOverlordInner {
    network_config: NetworkRef,
    watchdogs: Mutex<Vec<Watchdog>>,
    connection_object: Arc<ConnectionObject>,
    status_tx: watch::Sender<OverlordTimeoutSignal>,
    deadlock_lvl: WdgLevel,
    frontend_lvl: WdgLevel,
    app_handle: tauri::AppHandle,
}

impl WatchdogOverlordInner {
    fn notify_timeout(&self, timeout: WatchdogTimeout) {
        cprintln!("<red> Watchdog {:?} timeout</red>", timeout.tag);
        match timeout.tag {
            WdgTag::FrontendWdg => {
                if self.frontend_lvl == WdgLevel::Ignore {
                    notify_warning(
                        &self.app_handle,
                        "Frontend Watchdog Timeout",
                        "This can be the result of a frozen frontend, or a slow machine",
                        Local::now(),
                    );
                } else if self.frontend_lvl == WdgLevel::Active {
                    self.connection_object
                        .set_status(ConnectionStatus::FrontendWdgTimeout);
                    let _ = self.status_tx.send(OverlordTimeoutSignal::Bad);
                }
            }
            WdgTag::DeadlockWdg => {
                if self.deadlock_lvl == WdgLevel::Ignore {
                    notify_warning(
                        &self.app_handle,
                        "Deadlock Watchdog Timeout",
                        "This can be the result of a deadlock in the backend",
                        Local::now(),
                    );
                } else if self.frontend_lvl == WdgLevel::Active {
                    self.connection_object
                        .set_status(ConnectionStatus::DeadlockWdgTimeout);
                    let _ = self.status_tx.send(OverlordTimeoutSignal::Bad);
                }
            }
            WdgTag::Heartbeat { node_id, bus_id: _ } => {
                //self.connection_object
                //    .set_status(ConnectionStatus::HeartbeatMiss { node_id, bus_id });
                let node = self
                    .network_config
                    .nodes()
                    .iter()
                    .find(|n| n.id() == node_id)
                    .expect("Invalid Heartbeat Config Detected");
                notify_warning(
                    &self.app_handle,
                    &format!("Hearbeat Timeout"),
                    &format!("Heartbeat of {} timed out", node.name()),
                    Local::now(),
                );
            }
        }
    }
}

pub struct WatchdogOverlord(Arc<WatchdogOverlordInner>);

impl WatchdogOverlord {
    pub fn new(
        network_config: &NetworkRef,
        connection_object: &Arc<ConnectionObject>,
        tx_com: &Arc<TxCom>,
        deadlock_lvl: WdgLevel,
        frontend_lvl: WdgLevel,
        app_handle: &tauri::AppHandle,
    ) -> Self {
        let (over_status_tx, over_status_rx) = watch::channel(OverlordTimeoutSignal::Good);
        let _ = tokio::spawn(Self::over_timeout_task(
            over_status_rx,
            tx_com.clone(),
            Duration::from_millis(400),
            20
        ));

        Self(Arc::new(WatchdogOverlordInner {
            network_config: network_config.clone(),
            watchdogs: Mutex::new(vec![]),
            connection_object: connection_object.clone(),
            status_tx: over_status_tx,
            deadlock_lvl,
            frontend_lvl,
            app_handle: app_handle.clone(),
        }))
    }

    async fn over_timeout_task(
        mut status_rx: watch::Receiver<OverlordTimeoutSignal>,
        tx_com: Arc<TxCom>,
        timeout: Duration,
        ticks_next: u8,
    ) {
        let sleep = tokio::time::sleep(timeout);
        tokio::pin!(sleep);
        let mut active = true;
        loop {
            select! {
                _ = status_rx.changed() => {
                    let x = *status_rx.borrow_and_update();
                    match x {
                        OverlordTimeoutSignal::Good => {
                            tx_com.send_heartbeat(ticks_next, false).await;
                            sleep.as_mut().reset(Instant::now() + timeout);
                            active = true;
                        },
                        OverlordTimeoutSignal::Bad => {
                            // Send heartbeat with ticks_next = 0.
                            // Should react quicker than just letting
                            // heartbeats time out.
                            tx_com.send_heartbeat(0, false).await;
                            break;
                        }
                        OverlordTimeoutSignal::Unregister => {
                            tx_com.send_heartbeat(ticks_next, true).await;
                            active = false;
                        }
                    }
                }
                () = sleep.as_mut(), if active => {
                    tx_com.send_heartbeat(ticks_next, false).await;
                    sleep.as_mut().reset(Instant::now() + timeout);
                }
            }
        }
    }

    pub fn register(&self, tag: WdgTag, timeout: Duration) -> Watchdog {
        let watchdog = Watchdog::create(tag, timeout, self.0.clone());
        self.0
            .watchdogs
            .lock()
            .expect("Failed to acquire WatchdogOverlord lock")
            .push(Watchdog(watchdog.0.clone()));
        watchdog
    }

    pub fn unregister_from_heartbeat(&self) {
        let _ = self.0.status_tx.send(OverlordTimeoutSignal::Unregister);
    }

    pub fn reregister_to_heartbeat(&self) {
        let _ = self.0.status_tx.send(OverlordTimeoutSignal::Good);
    }

    // pub fn unregister(&self, watchdog: Watchdog) {
    //     let mut watchdog_lock = self.0.watchdogs.lock().expect("Failed to acquire WatchdogOverloard lock");
    //     let Some(pos) = watchdog_lock.iter().position(|w| w.0.tag == watchdog.0.tag) else {
    //         cprintln!("<yellow>Trying to unregister non registered watchdog</yellow>");
    //         return;
    //     };
    //     watchdog_lock.remove(pos);
    //     // afterwards the watchdog is destructured because the local ref
    //     // is gone and the ref in the vec. It's fair to assume that these two are the only once
    //     // because clone is not exposed.
    //     // note: destructing the watchdog also aborts it's watchdog task!
    // }
}
