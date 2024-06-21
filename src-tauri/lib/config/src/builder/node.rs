use std::time::Duration;

use crate::config::ObjectEntryAccess;

use super::{stream_builder::{ReceiveStreamBuilder, StreamBuilder}, ObjectEntryBuilder, MessageBuilder, NetworkBuilder, CommandBuilder, BuilderRef, MessagePriority, make_builder_ref, bus::BusBuilder};


#[derive(Debug, Clone)]
pub struct NodeBuilder(pub BuilderRef<NodeData>);
#[derive(Debug)]
pub struct NodeData {
    pub name: String,
    pub description: Option<String>,
    pub commands: Vec<CommandBuilder>,
    pub extern_commands: Vec<CommandBuilder>,
    pub network_builder: NetworkBuilder,
    pub rx_messages: Vec<MessageBuilder>,
    pub tx_messages: Vec<MessageBuilder>,
    pub object_entries: Vec<ObjectEntryBuilder>,
    pub tx_streams: Vec<StreamBuilder>,
    pub rx_streams: Vec<ReceiveStreamBuilder>,
    pub buses : Vec<BusBuilder>,
}


impl NodeBuilder {
    pub fn new(name: &str, network_builder: &NetworkBuilder) -> NodeBuilder {
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Creating node {name}");
        let node_builder = NodeBuilder(make_builder_ref(NodeData {
            name: name.to_owned(),
            description: None,
            network_builder: network_builder.clone(),
            commands: vec![],
            extern_commands: vec![],
            tx_messages: vec![],
            rx_messages: vec![],
            object_entries: vec![],
            tx_streams: vec![],
            rx_streams: vec![],
            buses : vec![],
        }));
        node_builder.add_rx_message(&network_builder._get_req_message());
        node_builder.add_tx_message(&network_builder._get_resp_message());
        node_builder.add_rx_message(&network_builder._set_req_message());
        node_builder.add_tx_message(&network_builder._set_resp_message());

        let config_hash = node_builder.create_object_entry("config_hash", "u64");
        config_hash.add_description("Hash of the local network configuration");
        config_hash.set_access(ObjectEntryAccess::Const);

        let build_time = node_builder.create_object_entry("build_time", "date_time");
        build_time.add_description("Time the node was last build from source");
        build_time.set_access(ObjectEntryAccess::Const);

        node_builder
    }
    pub fn assign_bus(&self, bus_name : &str) -> BusBuilder{
        let mut node_data = self.0.borrow_mut();       
        let network_data = node_data.network_builder.0.borrow_mut();
        let bus = network_data.buses.borrow().iter().find(|bus| &bus.0.borrow().name == bus_name).cloned();
        drop(network_data);
        match bus {
            Some(bus) => {
                node_data.buses.push(bus.clone());
                bus
            }
            None => {
                let bus = node_data.network_builder.create_bus(bus_name, None);
                node_data.buses.push(bus.clone());
                bus
            }
        }
    }
    pub fn add_description(&self, description: &str) {
        let mut node_data = self.0.borrow_mut();
        node_data.description = Some(description.to_owned());
    }
    pub fn add_tx_message(&self, message_builder: &MessageBuilder) {
        let node_name = self.0.borrow().name.clone();
        if !message_builder.0.borrow().transmitters.iter().any(|n| &n.0.borrow().name == &node_name) {
            message_builder.0.borrow_mut().transmitters.push(self.clone());
        }
        self.0.borrow_mut().tx_messages.push(message_builder.clone());
    }
    pub fn add_rx_message(&self, message_builder: &MessageBuilder) {
        let node_name = self.0.borrow().name.clone();
        if !message_builder.0.borrow().receivers.iter().any(|n| &n.0.borrow().name == &node_name) {
            message_builder.0.borrow_mut().receivers.push(self.clone());
        }
        self.0.borrow_mut().rx_messages.push(message_builder.clone());
    }
    pub fn create_command(&self, name: &str, expected_interval : Option<Duration>) -> CommandBuilder {
        let command_builder = CommandBuilder::new(name, &self, expected_interval);
        let mut node_data = self.0.borrow_mut();
        node_data.commands.push(command_builder.clone());
        node_data
            .rx_messages
            .push(command_builder.0.borrow().call_message.clone());
        node_data
            .tx_messages
            .push(command_builder.0.borrow().resp_message.clone());
        command_builder
    }
    pub fn add_extern_command(&self, message_builder: &CommandBuilder) {
        let mut node_data = self.0.borrow_mut();
        node_data.extern_commands.push(message_builder.clone());
        node_data
            .rx_messages
            .push(message_builder.0.borrow().resp_message.clone());
        node_data
            .tx_messages
            .push(message_builder.0.borrow().call_message.clone());
    }
    pub fn create_object_entry(&self, name: &str, ty: &str) -> ObjectEntryBuilder {
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Require ObjectEntry {}::{name}", self.0.borrow().name);
        let existing_oe = self.0.borrow().object_entries.iter().find(|oe| oe.0.borrow().name == name).cloned();
        match existing_oe {
            Some(oe) => {
                assert_eq!(&oe.0.borrow().ty, ty);
                return oe;
            }
            None => (),
        };
        let object_entry_builder = ObjectEntryBuilder::new(name, ty, &self.0.borrow().name);
        let mut node_data = self.0.borrow_mut();
        node_data.object_entries.push(object_entry_builder.clone());
        object_entry_builder
    }
    pub fn create_stream(&self, name: &str) -> StreamBuilder {
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Require Stream {}::{name}", self.0.borrow().name);
        match self.0.borrow().tx_streams.iter().find(|stream| stream.0.borrow().name == name).cloned() {
            Some(stream) => return stream,
            None => (),
        };
        let stream_builder = StreamBuilder::new(name, self.clone());
        let mut node_data = self.0.borrow_mut();
        node_data.tx_streams.push(stream_builder.clone());
        stream_builder
    }

    pub fn receive_stream(&self, tx_node_name: &str, tx_stream_name: &str) -> ReceiveStreamBuilder {
        let node_data = self.0.borrow();
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Creating dependencies of receive stream {tx_node_name}::{tx_stream_name} -> {}", node_data.name);
        if tx_node_name == node_data.name {
            panic!("can't receive local stream");
        }
        let network_builder = &node_data.network_builder;
        let tx_node_opt = network_builder
            .0
            .borrow()
            .nodes
            .borrow()
            .iter()
            .find(|n| n.0.borrow().name == tx_node_name)
            .cloned();
        let tx_node = match tx_node_opt {
            Some(tx_node) => tx_node,
            None => network_builder.create_node(tx_node_name),
        };
        let tx_node_data = tx_node.0.borrow();
        let tx_stream_opt = tx_node_data
            .tx_streams
            .iter()
            .find(|s| s.0.borrow().name == tx_stream_name)
            .cloned();
        drop(node_data);
        drop(tx_node_data);
        let tx_stream = match tx_stream_opt {
            Some(tx_stream) => tx_stream,
            None => tx_node.create_stream(tx_stream_name),
        };

        let tx_stream_data = tx_stream.0.borrow();
        self.add_rx_message(&tx_stream_data.message);
        drop(tx_stream_data);

        let rx_stream_builder = ReceiveStreamBuilder::new(tx_stream, self.clone());
        let mut node_data = self.0.borrow_mut();
        node_data.rx_streams.push(rx_stream_builder.clone());


        rx_stream_builder
    }
}
