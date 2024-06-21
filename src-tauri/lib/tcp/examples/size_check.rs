use std::time::Duration;

use canzero_common::{CanFrame, NetworkFrame, TNetworkFrame};
use canzero_tcp::tcpcan::TcpFrame;

#[tokio::main]
async fn main() {
    let network_frame_size = bincode::serialized_size(&TcpFrame::NetworkFrame(TNetworkFrame::new(
        Duration::from_secs(0),
        NetworkFrame {
            bus_id: 0,
            can_frame: CanFrame::new(0, false, false, 0, 0),
        },
    )))
    .unwrap();

    let keep_alive_frame_size =
        bincode::serialized_size(&TcpFrame::KeepAlive { _padding: [0;29] }).unwrap();
    println!("{keep_alive_frame_size} == {network_frame_size}");
    assert_eq!(keep_alive_frame_size, network_frame_size);
}
