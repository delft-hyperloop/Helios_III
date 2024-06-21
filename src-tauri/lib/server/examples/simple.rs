use canzero_server::Server;

#[tokio::main]
async fn main() {
    let server = Server::create().await.unwrap();
    server.start();

    loop {
        tokio::task::yield_now().await;
    }
}
