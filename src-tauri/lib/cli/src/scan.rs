use std::time::Duration;

use canzero_udp::scanner::UdpNetworkScanner;

use crate::errors::Result;


pub async fn command_scan() -> Result<()> {
    let scanner = UdpNetworkScanner::create().await?;
    scanner.start();
    let mut networks = vec![];
    loop {
        match scanner.next_timeout(Duration::from_millis(1000)).await {
            Some(Ok(network)) => {
                networks.push(network);
                continue;
            }
            Some(Err(err)) => {
                eprintln!("{err:?}");
                break;
            }
            None => break,
        }
    }
    drop(scanner);
    if networks.is_empty() {
        println!("No connections found");
    } else {
        println!("Found TCP servers at:");
        for nd in networks {
            println!(
                "- {} at {}:{}",
                nd.server_name, nd.server_addr, nd.service_port
            );
        }
    }
    Ok(())
}
