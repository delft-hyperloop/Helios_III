use serde::Serialize;

use crate::cnl::network::object_entry_object::latest::event::OwnedObjectEntryEvent;



#[derive(Serialize, Clone)]
pub struct NodeEvent {
    pub object_entry_values : Vec<Option<OwnedObjectEntryEvent>>
}

