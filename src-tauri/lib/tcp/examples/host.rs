use canzero_tcp::tcpcan::TcpCan;
use tokio::net::{TcpListener, TcpSocket};



#[tokio::main]
async fn main() {
    let host = TcpListener::bind("127.0.0.1:9000").await.unwrap();

    let (socket, _) = host.accept().await.unwrap();
    let tcpcan = TcpCan::new(socket);

    loop  {
        match tcpcan.recv().await {
            Some(_) => (),
            None => panic!(),
        }
    }
}
