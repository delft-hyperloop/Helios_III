use std::time::{Duration, Instant};

use canzero_udp::beacon::UdpNetworkBeacon;

#[tokio::main]
async fn main() {
    let beacon = UdpNetworkBeacon::create(100, Instant::now(), "test-beacon", config)
        .await
        .unwrap();

    beacon.start();

    // beacon.stop(); is also avaiable!

    loop {
        tokio::time::sleep(Duration::from_secs(10000)).await;
    }
}
