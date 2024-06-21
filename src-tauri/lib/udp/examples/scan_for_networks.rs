use canzero_udp::scanner::UdpNetworkScanner;



#[tokio::main]
async fn main() {
    let scanner = UdpNetworkScanner::create().await.unwrap();

    scanner.start();
    loop {
        let network = scanner.next().await.unwrap();
        println!("{network:?}");
    }

}
