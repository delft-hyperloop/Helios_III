use std::fmt::Debug;
use std::{sync::Arc, time::Duration};

use tokio::sync::Mutex;
use tokio::{sync::mpsc, task::AbortHandle};
use tokio::time::Instant;

struct WatchdogSignal;

struct TimeoutSignal;

#[derive(Debug)]
struct WatchdogInner {
    abort_handle: AbortHandle,
    reset_tx: mpsc::Sender<WatchdogSignal>,
    timeout_rx: Mutex<mpsc::Receiver<TimeoutSignal>>,
}

#[derive(Debug)]
pub struct Watchdog(Arc<WatchdogInner>);

impl Watchdog {
    pub fn create(
        timeout: Duration,
    ) -> Self {
        let (reset_tx, reset_rx) = mpsc::channel(16);

        let (timeout_tx, timeout_rx) = mpsc::channel(1);

        let abort_handle = tokio::spawn(Self::watchdog_task(
            reset_rx,
            timeout,
            timeout_tx,
            
        ))
        .abort_handle();

        Watchdog(Arc::new(WatchdogInner {
            abort_handle,
            reset_tx,
            timeout_rx : Mutex::new(timeout_rx),
        }))
    }

    async fn watchdog_task(
        mut reset_rx: mpsc::Receiver<WatchdogSignal>,
        timeout: Duration,
        timeout_tx : mpsc::Sender<TimeoutSignal>,
    ) {
        let sleep = tokio::time::sleep(timeout);
        tokio::pin!(sleep);
        let mut active = false;
        loop {
            tokio::select! {
                msg = reset_rx.recv() => {
                    match msg {
                        Some(_) => {
                            active = true;
                            sleep.as_mut().reset(Instant::now() + timeout)
                        }
                        None => break,
                    }
                },
                () = sleep.as_mut(), if active => {
                    timeout_tx.send(TimeoutSignal{}).await.unwrap();
                    sleep.as_mut().reset(Instant::now() + timeout)
                },
            }
        }
    }

    pub async fn timeout(&self) {
        // lock is held a long ass time, but that should be fine!
        self.0.timeout_rx.lock().await.recv().await;
    }

    pub async fn reset(&self) {
        if let Err(_) = self.0.reset_tx.send(WatchdogSignal).await {
            unreachable!();
        }
    }
}

impl Drop for Watchdog {
    fn drop(&mut self) {
        self.0.abort_handle.abort();
    }
}

