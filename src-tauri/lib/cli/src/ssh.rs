use std::{net::IpAddr, path::PathBuf, str::FromStr, time::Duration};

use canzero_udp::{frame::NetworkDescription, scanner::UdpNetworkScanner};
use serde_yaml::from_str;

use crate::errors::{Error, Result};

pub async fn scan_ssh() -> Result<Option<NetworkDescription>> {
    loop {
        let scanner = UdpNetworkScanner::create().await?;

        scanner.start();
        let mut networks = vec![];
        loop {
            match scanner.next_timeout(Duration::from_millis(1000)).await {
                Some(Ok(network)) => {
                    networks.push(network);
                    continue;
                }
                Some(Err(_)) => panic!("Failed to discover networks"),
                None => (),
            }
            if !networks.is_empty() {
                break;
            }
        }

        if networks.is_empty() {
            println!("No connections found");
            return Ok(None);
        }
        if networks.len() == 1 {
            return Ok(Some(networks.first().unwrap().clone()));
        }
        println!("Found TCP servers at:");
        for (i, nd) in networks.iter().enumerate() {
            println!(
                "-{} : {} at  {}:{}",
                i + 1,
                nd.server_name,
                nd.server_addr,
                nd.service_port
            );
        }
        println!(
            "Select server {:?} or 'r' to rescan",
            (1..networks.len())
        );
        let mut resp = String::new();
        std::io::stdin().read_line(&mut resp).unwrap();
        if resp.starts_with("r") {
            continue;
        } else {
            let Ok(con_index) = from_str::<usize>(&resp) else {
                return Err(Error::InvalidResponse);
            };
            let Some(con) = networks.get(con_index.saturating_sub(1)) else {
                return Err(Error::InvalidResponse);
            };
            return Ok(Some(con.to_owned()));
        }
    }
}

pub async fn command_ssh(host: Option<String>) -> Result<()> {
    let ip_addr = if let Some(host) = host {
        IpAddr::from_str(&host).expect("Not a ip address!")
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
        .spawn().unwrap().wait().unwrap();

    Ok(())
}

pub async fn command_ssh_reboot(host: Option<String>) -> Result<()> {
    let ip_addr = if let Some(host) = host {
        IpAddr::from_str(&host).expect("Not a ip address!")
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
        .arg("sudo")
        .arg("reboot")
        .spawn().unwrap().wait().unwrap();

    Ok(())
}

pub async fn command_restart(host: Option<String>) -> Result<()> {
    let ip_addr = if let Some(host) = host {
        IpAddr::from_str(&host).expect("Not a ip address!")
    } else {
        let Some(nd) = scan_ssh().await? else {
            return Ok(());
        };
        nd.server_addr
    };
    println!("Restarting server");
    std::process::Command::new("ssh")
        .arg("-i")
        .arg("~/.ssh/mu-zero")
        .arg(format!("pi@{ip_addr:?}"))
        .arg("sudo pkill canzero")
        .spawn()
        .unwrap()
        .wait()
        .unwrap();
    std::process::Command::new("ssh")
            .arg("-i")
            .arg("~/.ssh/mu-zero")
            .arg(format!("pi@{ip_addr:?}"))
            .arg("sudo /home/pi/.canzero/canzero run server >> /home/pi/.canzero/canzero-server.log 2>&1 &")
            .spawn().unwrap().wait().unwrap();
    Ok(())
}

pub async fn command_scp(path_str: String, host: Option<String>) -> Result<()> {
    let ip_addr = if let Some(host) = host {
        IpAddr::from_str(&host).expect("Not a ip address!")
    } else {
        let Some(nd) = scan_ssh().await? else {
            return Ok(());
        };
        nd.server_addr
    };

    let path = PathBuf::from_str(&path_str).expect("FUCK YOU for using non utf8 filenames");
    if !path.exists() {
        return Err(Error::FileNotFound(path_str));
    }
    let filename = path.file_name().unwrap().to_str().unwrap();

    std::process::Command::new("scp")
        .arg("-i")
        .arg("~/.ssh/mu-zero")
        .arg(path.clone())
        .arg(&format!("pi@{ip_addr:?}:/home/pi/.canzero/{filename}"))
        .spawn()
        .unwrap()
        .wait()
        .unwrap();

    Ok(())
}
