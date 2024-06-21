use std::{fmt::Display, hash::Hash, sync::OnceLock, time::Duration};

use super::{ConfigRef, MessageEncoding, SignalRef, Visibility, bus::BusRef, stream::StreamRef, CommandRef};


#[derive(Debug)]
pub enum MessageUsage {
    Stream(StreamRef),
    CommandReq(CommandRef),
    CommandResp(CommandRef),
    GetResp,
    GetReq,
    SetResp,
    SetReq,
    Heartbeat,
    External{interval : Duration},
}

#[derive(Debug, Eq, PartialEq, Copy, Clone)]
pub enum MessageId {
    StandardId(u32),
    ExtendedId(u32),
}

impl Hash for MessageId {

    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        match &self {
            MessageId::StandardId(id) => {
                state.write_u8(0);
                state.write_u32(*id);
            }
            MessageId::ExtendedId(id) => {
                state.write_u8(1);
                state.write_u32(*id);
            }
        }
    }
}

impl MessageId {
    pub fn ide(&self) -> bool {
        match &self {
            MessageId::StandardId(_) => false,
            MessageId::ExtendedId(_) => true,
        }
    }
    pub fn as_u32(&self) -> u32 {
        match &self {
            MessageId::StandardId(id) => *id,
            MessageId::ExtendedId(id) => *id,
        }
    }
}

pub type MessageRef = ConfigRef<Message>;

#[derive(Debug)]
pub struct Message {
    name: String,
    description: Option<String>,
    id: MessageId,
    encoding: Option<MessageEncoding>,
    signals: Vec<SignalRef>,
    visibility: Visibility,
    dlc : u8,
    bus : BusRef,
    usage : OnceLock<MessageUsage>,
}

impl Hash for Message {
    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        for b in self.name.bytes() {
            state.write_u8(b);
        }
        self.id.hash(state);
        match &self.encoding {
            Some(encoding) => {
                state.write_u8(0);
                encoding.hash(state);
            },
            None => {
                state.write_u8(1);
                for s in &self.signals {
                    s.hash(state);
                }
            }
        }
        self.visibility.hash(state);
        state.write_u8(self.dlc);
        state.write_u32(self.bus.id());
    }
}


impl Message {
    pub fn new(name : String,
               description : Option<String>,
               id : MessageId,
               encoding : Option<MessageEncoding>,
               signals : Vec<SignalRef>,
               visibility : Visibility, dlc : u8,
               bus : BusRef) -> Self {
        Self {
            name,
            description,
            id,
            encoding,
            signals,
            visibility,
            dlc,
            bus,
            usage : OnceLock::new(),
        }
    }
    pub fn usage(&self) -> &MessageUsage {
        self.usage.get().expect("Karl fucked up big time (message usage was not set property while building!)")
    }
    pub fn __set_usage(&self, usage : MessageUsage) {
        self.usage.set(usage).expect("__set_usage can only be called once (when calling NetworkBuilder::build(&self))");
    }
    pub fn __get_usage(&self) -> &OnceLock<MessageUsage> {
        &self.usage
    }

    pub fn id(&self) -> &MessageId {
        &self.id
    }
    pub fn name(&self) -> &str {
        &self.name
    }
    pub fn description(&self) -> Option<&str> {
        match &self.description {
            Some(some) => Some(&some),
            None => None,
        }
    }
    pub fn encoding(&self) -> Option<&MessageEncoding> {
        self.encoding.as_ref()
    }
    pub fn signals(&self) -> &Vec<SignalRef> {
        &self.signals
    }
    pub fn dlc(&self) -> u8 { 
        self.dlc
    }
    pub fn visibility(&self) -> &Visibility {
        &self.visibility
    }
    pub fn bus(&self) -> &BusRef {
        &self.bus
    }
}


impl Display for MessageId {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match &self {
            MessageId::StandardId(id) => write!(f, "0x{:03X} ", id),
            MessageId::ExtendedId(id) => write!(f, "{:05X}x", id),
        }
    }
}
