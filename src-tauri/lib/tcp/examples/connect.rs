use std::{net::SocketAddr, str::FromStr};

use canzero_tcp::tcpcan::TcpCan;

#[tokio::main]
async fn main() {
    let tcpcan = TcpCan::connect(SocketAddr::from_str("127.0.0.1:9000").unwrap())
        .await
        .unwrap();

    loop {
        match tcpcan.recv().await {
            Some(_) => (),
            None => panic!(),
        }
    }
}
