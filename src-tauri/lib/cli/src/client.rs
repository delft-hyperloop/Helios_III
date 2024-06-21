
use canzero_tcp::tcpcan::ConnectionId;

use crate::errors::Result;

pub async fn command_client() -> Result<()> {
    if cfg!(feature = "socket-can") {
        #[cfg(feature = "socket-can")]
        {
            let scanner = canzero_udp::scanner::UdpNetworkScanner::create().await?;
            scanner.start();
            let connection = scanner.next().await?;
            drop(scanner);

            let socketcan = std::sync::Arc::new(canzero_socketcan::socket_can::SocketCan::connect().await?);

            let tcpcan = std::sync::Arc::new(
                canzero_tcp::tcpcan::TcpCan::connect(std::net::SocketAddr::new(
                    connection.server_addr,
                    connection.service_port,
                ), ConnectionId::Client { request_id: false, sync_history: false }).await?
            );
            color_print::cprintln!("<green>Established connection to {} at {}:{}</green>", connection.server_name, connection.server_addr, connection.service_port);

            let socketcan_rx = socketcan.clone();
            let tcpcan_tx = tcpcan.clone();
            let abort_handle = tokio::spawn(async move {
                loop {
                    let frame = socketcan_rx.recv().await.unwrap();
                    let Ok(_) = tcpcan_tx.send(&frame).await else {
                        break;
                    };
                }
            }).abort_handle();

            loop {
                let Some(frame) = tcpcan.recv().await else {
                    break;
                };
                socketcan.send(&frame).await.unwrap();
            }
            abort_handle.abort();
            color_print::cprintln!("<red>Connection closed</red>");
        }
    } else {
        eprintln!("client command not avaiable. client only avaiable if compiled with the socket-can feature");
    }

    Ok(())
}
