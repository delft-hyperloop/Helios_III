
use canzero_appdata::AppData;
use canzero_server::Server;

use crate::errors::Result;

pub async fn command_server() -> Result<()> {

    let appdata = AppData::read()?;
    let network_config = appdata.config()?;
    let server = Server::create(network_config).await?;

    server.start();
    loop {
        tokio::task::yield_now().await;
    }
}
