use std::net::IpAddr;

use local_ip_address::local_ip;

pub fn configure_gs_ip(ip: [u8; 4], port: u16, force: bool) -> String {
    let mut ip = (ip[0], ip[1], ip[2], ip[3], port);
    if !force {
        match local_ip().unwrap() {
            IpAddr::V4(ipv4) => {
                ip = (
                    ipv4.octets()[0],
                    ipv4.octets()[1],
                    ipv4.octets()[2],
                    ipv4.octets()[3],
                    port,
                );
            }
            IpAddr::V6(_) => {}
        }
    }

    format!(
        "\npub static mut GS_IP_ADDRESS: ([u8;4],u16) = ([{},{},{},{}],{});\n",
        ip.0, ip.1, ip.2, ip.3, ip.4
    )
}
