use canzero_common::TNetworkFrame;
use canzero_socketcan::socket_can::SocketCan;


#[tokio::main]
async fn main() {
    let socketcan = SocketCan::connect().await.unwrap();

    loop {
        let frame : TNetworkFrame = socketcan.recv().await.unwrap();
        println!("{frame:?}");
    }
}
