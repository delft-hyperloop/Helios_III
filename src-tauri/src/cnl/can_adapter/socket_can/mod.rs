use std::{time::Instant, sync::Arc};

use canzero_config::config::bus::BusRef;
use canzero_socketcan::can_socket::CanSocket;
use tokio::{
    runtime::Handle,
    sync::{
        mpsc::{Receiver, Sender},
        Mutex,
    },
};
use canzero_common::{TCanFrame, CanFrame, TCanError, Timestamped};

use crate::notification::notify_error;

pub struct SocketCanAdapter {
    rx: Mutex<Receiver<Result<TCanFrame, TCanError>>>,
    tx: Sender<CanFrame>,
    // start_of_run: Instant,
}

impl SocketCanAdapter {
    pub fn create(
        bus: &BusRef,
        start_of_run: Instant,
        app_handle: &tauri::AppHandle,
    ) -> Result<SocketCanAdapter, std::io::Error> {
        let ifname = bus.name();
        let socket = Arc::new(CanSocket::open(ifname).unwrap());
        let app_handle = app_handle.clone();

        let (tx, rx) = tokio::sync::mpsc::channel::<Result<TCanFrame, TCanError>>(16);

        let (txtx, mut txrx) = tokio::sync::mpsc::channel::<CanFrame>(16);

        let socket_ref = socket.clone();
        tokio::task::spawn_blocking(move || loop {
            let frame = match socket_ref.receive() {
                Ok(frame) => frame,
                Err(err) => {
                    notify_error(
                        &app_handle,
                        "Failed to receive on SocketCAN adapter",
                        &format!("{err:?}"),
                        chrono::offset::Local::now(),
                    );
                    continue;
                }
            };
            let time = Instant::now();
            let timestamp = time.duration_since(start_of_run);
            Handle::current().block_on(async {
                match frame {
                    Ok(can_frame) => {
                        tx.send(Ok(Timestamped::new(timestamp, can_frame)))
                            .await
                            .expect("failed to forward canframe receiver closed early");
                    }
                    Err(error_frame) => {
                        tx.send(Err(Timestamped::new(timestamp, error_frame)))
                            .await
                            .expect("failed to forward canerror receiver closed early");
                    }
                }
            });
        });

        let socket_ref = socket.clone();
        tokio::task::spawn_blocking(move || loop {
            let frame = Handle::current().block_on(async {
                txrx.recv()
                    .await
                    .expect("failed to transmit canframe sender closed early")
            });
            socket_ref
                .transmit(&frame)
                .expect("failed to write to socket");
        });

        Ok(SocketCanAdapter {
            tx: txtx,
            rx: Mutex::new(rx),
            // start_of_run,
        })
    }

    pub async fn send(&self, frame: CanFrame) -> std::io::Result<()> {
        self.tx.send(frame).await.map_err(|err| {
            std::io::Error::new(std::io::ErrorKind::ConnectionAborted, format!("{err:?}"))
        })
    }

    pub async fn receive(&self) -> std::io::Result<Result<TCanFrame, TCanError>> {
        let frame = self.rx.lock().await.recv().await;
        match frame {
            Some(frame) => Ok(frame),
            None => Err(std::io::Error::new(
                std::io::ErrorKind::ConnectionAborted,
                "SocketCAN connection aborted",
            )),
        }
    }
}
