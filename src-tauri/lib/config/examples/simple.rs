use can_config_rs::builder::MessagePriority;


extern crate can_config_rs;

fn main() {
    let network_builder = can_config_rs::builder::NetworkBuilder::new();
    network_builder.create_bus("can0", Some(1000000));
    let secu = network_builder.create_node("secu");
    let xyz = secu.create_stream("xyz");

    xyz.set_priority(MessagePriority::Normal);
    xyz.add_entry("X");


    let network_config = network_builder.build().unwrap();
    println!("{network_config}");
    // let secu = network_config.nodes().iter().find(|n| n.name() == "secu").unwrap();
    // let messages = secu.tx_messages();
    
    // let get_resp_message = messages.iter().find(|m| m.name() == "get_resp").unwrap();
    // println!("dlc = {}", get_resp_message.dlc());
    // println!("signals = {:?}", get_resp_message.signals());


}
