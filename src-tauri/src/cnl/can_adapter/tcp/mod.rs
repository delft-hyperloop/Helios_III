use std::{sync::Arc, time::Instant};

use canzero_common::{CanFrame, NetworkFrame, TCanError, TCanFrame};
use color_print::cprintln;

use self::client::TcpClient;

pub mod client;

pub struct TcpCanAdapter {
    tcp_client: Arc<TcpClient>,
    bus_id: u32,
    rx: tokio::sync::Mutex<tokio::sync::mpsc::Receiver<Option<Result<TCanFrame, TCanError>>>>,
    tx: tokio::sync::Mutex<tokio::sync::mpsc::Sender<Option<Result<TCanFrame, TCanError>>>>,
    timebase : Instant,
}

impl TcpCanAdapter {
    pub fn create(
        tcp_client: Arc<TcpClient>,
        bus_id: u32,
        rx: tokio::sync::mpsc::Receiver<Option<Result<TCanFrame, TCanError>>>,
        tx: tokio::sync::mpsc::Sender<Option<Result<TCanFrame, TCanError>>>,
        timebase : Instant,
    ) -> Self {
        Self {
            tcp_client,
            bus_id,
            rx: tokio::sync::Mutex::new(rx),
            tx : tokio::sync::Mutex::new(tx),
            timebase,
        }
    }

    pub async fn receive(&self) -> std::io::Result<Result<TCanFrame, TCanError>> {
        let Some(frame) = self.rx.lock().await.recv().await else {
            return Err(std::io::Error::new(
                std::io::ErrorKind::ConnectionAborted,
                "TCP connection closed early".to_owned(),
            ));
        };
        let Some(frame) = frame else {
            println!("detected error");
            return Err(std::io::Error::new(std::io::ErrorKind::ConnectionAborted, "TCP connection closed".to_owned()));
        };
        Ok(frame)
    }

    pub async fn send(&self, frame: CanFrame, loopback : bool) -> std::io::Result<()> {
        if loopback {
            if let Err(_) = self.tx.lock().await.send(Some(Ok(TCanFrame::now(self.timebase, frame.clone())))).await {
                cprintln!("<red> Failed to loopback frame</red>");
            }
        }
        self.tcp_client
            .send(NetworkFrame {
                can_frame: frame,
                bus_id: self.bus_id,
            })
            .await
    }
}
