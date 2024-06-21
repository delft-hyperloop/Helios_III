use std::{rc::Rc, cell::RefCell};

pub use self::command_builder::CommandBuilder;
pub use self::message_builder::MessageBuilder;
pub use self::message_builder::MessageFormat;
pub use self::message_builder::MessagePriority;
pub use self::message_builder::MessageTypeFormatBuilder;
pub use self::message_builder::MessageSignalFormatBuilder;
pub use self::network_builder::NetworkBuilder;
pub use self::node::NodeBuilder;
pub use self::object_entry_builder::ObjectEntryBuilder;
pub use self::type_builder::TypeBuilder;
pub use self::type_builder::EnumBuilder;
pub use self::type_builder::StructBuilder;

pub mod command_builder;
pub mod message_builder;
pub mod network_builder;
pub mod node;
pub mod object_entry_builder;
pub mod stream_builder;
pub mod type_builder;
pub mod bus;
mod message_resolution;
mod import_dbc;

type BuilderRef<T> = Rc<RefCell<T>>;

fn make_builder_ref<T>(value: T) -> BuilderRef<T> {
    Rc::new(RefCell::new(value))
}
