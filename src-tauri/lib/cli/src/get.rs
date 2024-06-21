

use std::{net::IpAddr, str::FromStr};

use crate::{errors::Result, ssh::scan_ssh};

pub async fn command_get_server_log(host : Option<&String>) -> Result<()> {

    let ip_addr = if let Some(host) = host {
        IpAddr::from_str(host).expect("Not a ip address!")
    } else {
        let Some(nd) = scan_ssh().await? else {
            return Ok(());
        };
        nd.server_addr
    };

    std::process::Command::new("ssh")
        .arg("-i")
        .arg("~/.ssh/mu-zero")
        .arg(format!("pi@{ip_addr:?}"))
        .arg("cat")
        .arg("/home/pi/.canzero/canzero-server.log")
        .spawn().unwrap().wait().unwrap();
    
    Ok(())
}
