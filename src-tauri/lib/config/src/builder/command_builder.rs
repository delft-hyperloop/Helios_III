use std::time::Duration;

use crate::config::Visibility;

use super::{BuilderRef, NodeBuilder, MessageBuilder, MessageTypeFormatBuilder, MessagePriority, make_builder_ref};


#[derive(Debug, Clone)]
pub struct CommandBuilder(pub BuilderRef<CommandData>);
#[derive(Debug)]
pub struct CommandData {
    pub tx_node: NodeBuilder,
    pub name: String,
    pub description: Option<String>,
    pub call_message: MessageBuilder,
    pub call_message_format: MessageTypeFormatBuilder,
    pub resp_message: MessageBuilder,
    pub visibility: Visibility,
    pub expected_interval : Duration,
}

impl CommandBuilder {
    pub fn new(name: &str, tx_node_builder: &NodeBuilder, expected_interval : Option<Duration>) -> CommandBuilder {
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Creating command {name}");
        let node_data = tx_node_builder.0.borrow();
        let network_builder = &node_data.network_builder;
        let tx_message =
            network_builder.create_message(&format!("{}_{}_command_req", node_data.name, name), expected_interval);
        tx_message.hide();
        tx_message.set_any_std_id(MessagePriority::High);
        let tx_message_format = tx_message.make_type_format();

        let rx_message =
            network_builder.create_message(&format!("{}_{}_command_resp", node_data.name, name), expected_interval);
        rx_message.hide();
        rx_message.set_any_std_id(MessagePriority::Low);
        let rx_message_format = rx_message.make_type_format();
        rx_message_format.add_type("command_resp_erno", "erno");

        let new = CommandBuilder(make_builder_ref(CommandData {
            name: name.to_owned(),
            description: None,
            call_message: tx_message.clone(),
            call_message_format: tx_message_format,
            resp_message: rx_message.clone(),
            tx_node: tx_node_builder.clone(),
            visibility: Visibility::Global,
            expected_interval : Duration::from_millis(1000),
        }));
        tx_message.__assign_to_command_req(&new);
        rx_message.__assign_to_command_resp(&new);
        new
    }
    pub fn expected_interval(&self, interval : Duration) {
        self.0.borrow_mut().expected_interval = interval;
    }
    pub fn hide(&self) {
        let mut command_data = self.0.borrow_mut();
        command_data.visibility = Visibility::Static;
    }
    pub fn set_priority(&self, priority: MessagePriority) {
        let command_data = self.0.borrow();
        command_data.call_message.set_any_std_id(priority);
    }
    pub fn add_description(&self, name: &str) {
        let mut command_data = self.0.borrow_mut();
        command_data.description = Some(name.to_owned());
    }
    pub fn add_argument(&self, name: &str, ty: &str) {
        let command_data = self.0.borrow();
        command_data.call_message_format.add_type(ty, name);
    }
    pub fn add_callee(&self, name: &str) {
        let network_builder = self.0.borrow().tx_node.0.borrow().network_builder.clone();
        let callee = network_builder.create_node(name);
        callee.add_extern_command(&self);
    }
}
