use std::sync::Arc;

pub use self::command::Command;
pub use self::command::CommandRef;
pub use self::encoding::MessageEncoding;
pub use self::encoding::TypeSignalEncoding;
pub use self::message::MessageId;
pub use self::message::Message;
pub use self::message::MessageRef;
pub use self::network::Network;
pub use self::network::NetworkRef;
pub use self::node::Node;
pub use self::node::NodeRef;
pub use self::object_entry::ObjectEntryAccess;
pub use self::object_entry::ObjectEntry;
pub use self::object_entry::ObjectEntryRef;
pub use self::signal::SignalSign;
pub use self::signal::SignalType;
pub use self::signal::SignalRef;
pub use self::signal::ValueTable;
pub use self::signal::ValueTableRef;
pub use self::types::Type;
pub use self::types::TypeRef;
pub use self::visibility::Visibility;

pub mod command;
pub mod encoding;
pub mod message;
pub mod network;
pub mod node;
pub mod object_entry;
pub mod signal;
pub mod stream;
pub mod types;
pub mod visibility;
pub mod bus;

pub type ConfigRef<T> = Arc<T>;

pub fn make_config_ref<T>(value: T) -> ConfigRef<T> {
    Arc::new(value)
}
