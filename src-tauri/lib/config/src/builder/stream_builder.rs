use std::time::Duration;

use crate::config::Visibility;

use super::{
    make_builder_ref, BuilderRef, MessageBuilder, MessagePriority, MessageTypeFormatBuilder,
    NodeBuilder, ObjectEntryBuilder,
};

#[derive(Debug, Clone)]
pub struct StreamBuilder(pub BuilderRef<StreamData>);
#[derive(Debug)]
pub struct StreamData {
    pub name: String,
    pub description: Option<String>,
    pub message: MessageBuilder,
    pub format: MessageTypeFormatBuilder,
    pub tx_node: NodeBuilder,
    pub object_entries: Vec<ObjectEntryBuilder>,
    pub visbility: Visibility,
    pub interval: (Duration, Duration),
}

#[derive(Debug, Clone)]
pub struct ReceiveStreamBuilder(pub BuilderRef<ReceiveStreamData>);
#[derive(Debug)]
pub struct ReceiveStreamData {
    pub stream_builder: StreamBuilder,
    pub rx_node: NodeBuilder,
    pub object_entries: Vec<(usize, ObjectEntryBuilder)>,
    pub visibility: Visibility,
}

impl StreamBuilder {
    pub fn new(name: &str, node_builder: NodeBuilder) -> StreamBuilder {
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Creating (tx)-Stream {name} for node {}", node_builder.0.borrow().name);
        let node_data = node_builder.0.borrow();
        let message = node_data.network_builder.create_message(
            &format!("{}_stream_{name}", node_builder.0.borrow().name),
            None,
        );
        drop(node_data);
        node_builder.add_tx_message(&message);
        message.hide();
        message.set_any_std_id(MessagePriority::Normal);
        let format = message.make_type_format();

        let new = StreamBuilder(make_builder_ref(StreamData {
            name: name.to_owned(),
            description: None,
            message: message.clone(),
            format,
            tx_node: node_builder,
            object_entries: vec![],
            visbility: Visibility::Global,
            interval: (Duration::from_millis(50), Duration::from_millis(500)),
        }));
        message.__assign_to_stream(&new);
        new
    }
    // max : max time between two messages
    // min : min time between two messages
    pub fn set_interval(&self, min: Duration, max: Duration) {
        assert!(min.as_micros() <= max.as_micros());
        self.0.borrow_mut().interval = (min, max);
    }
    pub fn hide(&self) {
        let mut stream_data = self.0.borrow_mut();
        stream_data.visbility = Visibility::Static;
    }
    pub fn add_description(&self, description: &str) {
        let mut stream_data = self.0.borrow_mut();
        stream_data.description = Some(description.to_owned());
    }
    pub fn add_entry(&self, name: &str) {
        let mut stream_data = self.0.borrow_mut();
        // CHECK if entry already exists
        if stream_data.object_entries.iter().any(|oe| &oe.0.borrow().name == name) {
            // Skip if the object entry is already mapped!
            return;
        }
        let node = stream_data.tx_node.clone();
        let node_data = node.0.borrow();
        let oe = match node_data
            .object_entries
            .iter()
            .find(|oe| oe.0.borrow().name == name)
            .cloned()
        {
            Some(oe) => oe,
            None => {
                let node_name = &node_data.name;
                panic!("Failed to create stream entry. Object entry {node_name}:{name} does not exist");
            }
        };
        // .unwrap_or_else(|| node.create_object_entry(name, "u1"));
        stream_data.object_entries.push(oe.clone());
        let oe_data = oe.0.borrow();
        stream_data.format.add_type(&oe_data.ty, &oe_data.name);
    }
    pub fn set_priority(&self, priority: MessagePriority) {
        self.0.borrow().message.set_any_std_id(priority);
    }
    pub fn set_priority_with_extended_id(&self, priority: MessagePriority) {
        self.0.borrow().message.set_any_ext_id(priority);
    }
}

impl ReceiveStreamBuilder {
    pub fn new(stream_builder: StreamBuilder, rx_node: NodeBuilder) -> ReceiveStreamBuilder {
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Creating (rx)-Stream {}::{}", rx_node.0.borrow().name, stream_builder.0.borrow().name);
        let rx_node_name = rx_node.0.borrow().name.clone();
        drop(rx_node_name);
        ReceiveStreamBuilder(make_builder_ref(ReceiveStreamData {
            stream_builder,
            rx_node,
            object_entries: vec![],
            visibility: Visibility::Global,
        }))
    }
    pub fn hide(&self) {
        let mut rx_stream_data = self.0.borrow_mut();
        rx_stream_data.visibility = Visibility::Static;
    }
    pub fn map(&self, from: &str, to: &str) {
        // resolve from
        let tx_stream_builder = self.0.borrow().stream_builder.clone();

        let tx_oe = tx_stream_builder
            .0
            .borrow()
            .object_entries
            .iter()
            .find(|oe| oe.0.borrow().name == from)
            .cloned();
        let rx_oe = self
            .0
            .borrow()
            .rx_node
            .0
            .borrow()
            .object_entries
            .iter()
            .find(|oe| oe.0.borrow().name == to)
            .cloned();

        let (tx_oe, rx_oe) = match (tx_oe.clone(), rx_oe) {
            (None, None) => {
                // NOTE: no type information avaiable (theretically this should be
                // allowed because the type information might be added later to.
                // For now this will not be allowed
                panic!("Not possible to create a rx_stream without forward defined types. 
                       Please add a object entry with one of the types used in the mapping before defining the rx_stream mapping. [from = {from:?}, to = {to:?}]");
            }
            (None, Some(rx_oe)) => {
                // NOTE: create tx_oe
                let tx_oe = tx_stream_builder
                    .0
                    .borrow()
                    .tx_node
                    .create_object_entry(from, &rx_oe.0.borrow().ty);
                (tx_oe, rx_oe)
            }
            (Some(tx_oe), None) => {
                let rx_oe = self
                    .0
                    .borrow()
                    .rx_node
                    .create_object_entry(to, &tx_oe.0.borrow().ty);
                (tx_oe, rx_oe)
            }
            (Some(tx_oe), Some(rx_oe)) => {
                assert_eq!(&tx_oe.0.borrow().ty, &rx_oe.0.borrow().ty, "Stream mapping types don't match");
                (tx_oe, rx_oe)
            }
        };
        let tx_oe_name = tx_oe.0.borrow().name.clone();
        let tx_oe_map_position = tx_stream_builder
            .0
            .borrow()
            .object_entries
            .iter()
            .position(|oe| &oe.0.borrow().name == &tx_oe_name);
        let tx_oe_map_position = match tx_oe_map_position {
            Some(pos) => pos,
            None => {
                // NOTE: add to stream object!
                tx_stream_builder.add_entry(&tx_oe_name);
                tx_stream_builder
                    .0
                    .borrow()
                    .object_entries
                    .iter()
                    .position(|oe| &oe.0.borrow().name == &tx_oe_name).expect("Mapping should really really exist by now xD.")
            }
        };
        self.0
            .borrow_mut()
            .object_entries
            .push((tx_oe_map_position, rx_oe));
    }
}
