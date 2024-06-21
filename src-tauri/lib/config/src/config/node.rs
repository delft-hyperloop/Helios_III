use std::hash::Hash;

use super::{
    bus::BusRef, stream::StreamRef, CommandRef, ConfigRef, MessageRef, ObjectEntryRef, TypeRef,
};

pub type NodeRef = ConfigRef<Node>;

#[derive(Debug)]
pub struct Node {
    name: String,
    description: Option<String>,
    id: u8,

    types: Vec<TypeRef>,

    commands: Vec<CommandRef>,
    extern_commands: Vec<(String, CommandRef)>,

    tx_streams: Vec<StreamRef>,
    rx_streams: Vec<StreamRef>,

    rx_messages: Vec<MessageRef>,
    tx_messages: Vec<MessageRef>,

    object_entries: Vec<ObjectEntryRef>,
    buses: Vec<BusRef>,
}

impl Hash for Node {
    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        for b in self.name.bytes() {
            state.write_u8(b);
        }
        state.write_u8(self.id);
        for c in &self.commands {
            c.hash(state);
        }
        for (n, c) in &self.extern_commands {
            c.hash(state);
            for b in n.bytes() {
                state.write_u8(b);
            }
        }
        for s in &self.tx_streams {
            s.hash(state);
        }
        for s in &self.rx_streams {
            s.hash(state);
        }
        for oe in &self.object_entries {
            oe.hash(state);
        }
    }
}

impl Node {
    pub fn new(
        name: String,
        description: Option<String>,
        id: u8,
        types: Vec<TypeRef>,
        commands: Vec<CommandRef>,
        extern_commands: Vec<(String, CommandRef)>,
        tx_streams: Vec<StreamRef>,
        rx_streams: Vec<StreamRef>,
        rx_messages: Vec<MessageRef>,
        tx_messages: Vec<MessageRef>,
        object_entries: Vec<ObjectEntryRef>,
        buses: Vec<BusRef>,
    ) -> Self {
        Self {
            name,
            description,
            id,
            types,
            commands,
            extern_commands,
            tx_streams,
            rx_streams,
            rx_messages,
            tx_messages,
            object_entries,
            buses,
        }
    }

    pub fn name(&self) -> &str {
        &self.name
    }
    pub fn types(&self) -> &Vec<TypeRef> {
        &self.types
    }
    pub fn commands(&self) -> &Vec<CommandRef> {
        &self.commands
    }
    pub fn extern_commands(&self) -> &Vec<(String, CommandRef)> {
        &self.extern_commands
    }
    pub fn extern_commands_mut(&mut self) -> &mut Vec<(String, CommandRef)> {
        &mut self.extern_commands
    }
    pub fn tx_streams(&self) -> &Vec<StreamRef> {
        &self.tx_streams
    }
    pub fn rx_streams(&self) -> &Vec<StreamRef> {
        &self.rx_streams
    }
    pub fn rx_streams_mut(&mut self) -> &mut Vec<StreamRef> {
        &mut self.rx_streams
    }
    pub fn tx_messages(&self) -> &Vec<MessageRef> {
        &self.tx_messages
    }
    pub fn rx_messages(&self) -> &Vec<MessageRef> {
        &self.rx_messages
    }
    pub fn object_entries(&self) -> &Vec<ObjectEntryRef> {
        &self.object_entries
    }
    pub fn description(&self) -> Option<&String> {
        match &self.description {
            Some(some) => Some(&some),
            None => None,
        }
    }
    pub fn id(&self) -> u8 {
        self.id
    }
    pub fn buses(&self) -> &Vec<BusRef> {
        &self.buses
    }
}
