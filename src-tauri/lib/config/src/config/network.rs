use std::{fmt::Display, hash::{self, Hash, Hasher}};

use super::{ConfigRef, NodeRef, MessageRef, TypeRef, Type, SignalType, bus::BusRef};


pub type NetworkRef = ConfigRef<Network>;

#[derive(Debug)]
pub struct Network {
    build_time: chrono::DateTime<chrono::Local>,
    nodes: Vec<NodeRef>,
    messages: Vec<MessageRef>,
    types: Vec<TypeRef>,
    get_resp_message : MessageRef,
    get_req_message : MessageRef,
    set_resp_message : MessageRef,
    set_req_message : MessageRef,
    heartbeat_messages : Vec<MessageRef>,
    buses : Vec<BusRef>,
}

impl hash::Hash for Network {
    fn hash<H: hash::Hasher>(&self, state: &mut H) {
        self.nodes.hash(state);
        self.messages().hash(state);
        self.buses().hash(state);
    }
}

impl Network {
    pub fn portable_hash(&self) -> u64 {
        let mut hasher = seahash::SeaHasher::new();
        for n in &self.nodes {
            n.hash(&mut hasher);
        }
        for m in &self.messages {
            m.hash(&mut hasher);
        }
        for b in &self.buses {
            b.hash(&mut hasher);
        }
        hasher.finish()
    }
}

impl Network {
    pub fn new(
        build_time: chrono::DateTime<chrono::Local>,
        nodes: Vec<NodeRef>,
        messages: Vec<MessageRef>,
        types: Vec<TypeRef>,
        get_req_message : MessageRef,
        get_resp_message : MessageRef,
        set_req_message : MessageRef,
        set_resp_message : MessageRef,
        heartbeat_messages : Vec<MessageRef>,
        buses : Vec<BusRef>,
    ) -> Network {
        Network {
            types,
            build_time,
            nodes,
            messages,
            get_req_message,
            get_resp_message,
            set_req_message,
            set_resp_message,
            heartbeat_messages,
            buses
        }
    }
    pub fn buses(&self) -> &Vec<BusRef> {
        &self.buses
    }
    pub fn nodes(&self) -> &Vec<NodeRef> {
        &self.nodes
    }
    pub fn messages(&self) -> &Vec<MessageRef> {
        &self.messages
    }
    pub fn build_time(&self) -> &chrono::DateTime<chrono::Local> {
        &self.build_time
    }
    pub fn types(&self) -> &Vec<TypeRef> {
        &self.types
    }
    pub fn get_resp_message(&self) -> &MessageRef {
        &self.get_resp_message
    }
    pub fn get_req_message(&self) -> &MessageRef {
        &self.get_req_message
    }
    pub fn set_resp_message(&self) -> &MessageRef {
        &self.set_resp_message
    }
    pub fn set_req_message(&self) -> &MessageRef {
        &self.set_req_message
    }
    pub fn heartbeat_messages(&self) -> &Vec<MessageRef> {
        &self.heartbeat_messages
    }
    /// The control panel ids start at 0.
    /// returns the node_id associated with the control_panel.
    pub fn control_panel_node_id(&self, control_panel_id : u8) -> u8{
        self.nodes().len() as u8 + control_panel_id
    }
}

impl Display for Network {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let s1 = "  ";
        let s2 = format!("{s1}{s1}");
        let s3 = format!("{s2}{s1}");
        let s4 = format!("{s2}{s2}");
        let s5 = format!("{s4}{s1}");
        writeln!(f, "Network:")?;
        writeln!(f, "{s1}build_time : {}", self.build_time)?;
        writeln!(f, "{s1}busses:")?;
        for bus in &self.buses {
            writeln!(f, "{s2}{}", bus.id())?;
            writeln!(f, "{s3}baudrate : {}", bus.baudrate())?;
        }
        writeln!(f, "{s1}types:")?;
        for ty in &self.types {
            let vis = match ty as &Type {
                Type::Primitive(_) => "Global".to_owned(),
                Type::Struct {
                    name: _,
                    description: _,
                    attribs: _,
                    visibility,
                } => format!("{visibility:?}"),
                Type::Enum {
                    name: _,
                    description: _,
                    size: _,
                    entries: _,
                    visibility,
                } => format!("{visibility:?}"),
                Type::Array { len: _, ty: _ } => "Static".to_owned(),
            };
            write!(f, "{s2}{} ({})", ty.name(), vis)?;
            match ty as &Type {
                Type::Primitive(_) => {
                    write!(f, "\n")?;
                }
                Type::Struct {
                    name: _,
                    description: _,
                    attribs,
                    visibility: _,
                } => {
                    writeln!(f, ": (struct)")?;
                    for (attrib_name, attrib_type) in attribs {
                        writeln!(f, "{s3}{} : {}", attrib_name, attrib_type.name())?;
                    }
                }
                Type::Enum {
                    name: _,
                    description: _,
                    size: _,
                    entries,
                    visibility: _,
                } => {
                    writeln!(f, ": (enum)")?;
                    for (entry_name, entry_value) in entries {
                        writeln!(f, "{s3}{} = {}", entry_name, entry_value)?;
                    }
                }
                Type::Array { len: _, ty: _ } => {
                    write!(f, "\n")?;
                }
            }
        }
        writeln!(f, "{s1}messages:")?;
        for message in &self.messages {
            writeln!(f, "{s2}{}:", message.name())?;
            if message.description().is_some() {
                writeln!(f, "{s3}description = {}", message.description().unwrap())?;
            }
            writeln!(f, "{s3}id = {}", message.id())?;
            if message.encoding().is_some() {
                let encodings = message.encoding().unwrap();
                writeln!(f, "{s3}map_to_types:")?;
                for encoding in encodings.attributes() {
                    write!(f, "{s4}{} : ", encoding.name())?;
                    match &encoding.ty() as &Type {
                        Type::Primitive(signal_type) => match signal_type {
                            SignalType::UnsignedInt { size } => write!(f, "u{size}")?,
                            SignalType::SignedInt { size } => {
                                write!(f, "i{size}")?;
                            }
                            SignalType::Decimal {
                                size,
                                offset,
                                scale,
                            } => {
                                write!(f, "d{size}<offset={offset}, scale={scale}>")?;
                            }
                        },
                        Type::Struct {
                            name,
                            description: _,
                            attribs: _,
                            visibility: _,
                        } => {
                            write!(f, "{name} (struct)")?;
                        }
                        Type::Enum {
                            name,
                            description: _,
                            size: _,
                            entries: _,
                            visibility: _,
                        } => {
                            write!(f, "{name} (enum)")?;
                        }
                        Type::Array { len, ty } => {
                            write!(f, "{}[{len}]", ty.name())?;
                        }
                    }
                    writeln!(f)?;
                }
            }
            if !message.signals().is_empty() {
                writeln!(f, "{s3}signals:")?;
                for signal in message.signals() {
                    writeln!(f, "{s4}{}:", signal.name())?;
                    if signal.description().is_some() {
                        writeln!(f, "{s5}description = {}", signal.description().unwrap())?;
                        writeln!(f, "{s5}size = {}", signal.size())?;
                        writeln!(f, "{s5}sign = {}", signal.sign())?;
                        writeln!(f, "{s5}scale = {}", signal.scale())?;
                        writeln!(f, "{s5}offset = {}", signal.offset())?;
                    }
                }
            }
        }
        writeln!(f, "{s1}nodes:")?;
        for node in &self.nodes {
            writeln!(f, "{s2}{}:", node.name())?;
            if node.description().is_some() {
                writeln!(f, "{s3}description : {}", node.description().unwrap())?;
            }
            writeln!(f, "{s3}tx_messages:")?;
            for tx_message in node.tx_messages() {
                writeln!(f, "{s4}{}", tx_message.name())?;
            }
            writeln!(f, "{s3}rx_messages:")?;
            for rx_message in node.rx_messages() {
                writeln!(f, "{s4}{}", rx_message.name())?;
            }
            writeln!(f, "{s3}commands:")?;
            for tx_commands in node.commands() {
                writeln!(f, "{s4}{}", tx_commands.name())?;
            }
            writeln!(f, "{s3}extern_commands:")?;
            for (node_name, rx_commands) in node.extern_commands() {
                writeln!(f, "{s4}{}::{}", node_name, rx_commands.name())?;
            }
            writeln!(f, "{s3}object_entries:")?;
            for entry in node.object_entries() {
                writeln!(f, "{s4}{:?} {} : {} ({:?})", entry.access(), entry.name(), entry.ty().name(), entry.unit())?;
            }
            writeln!(f, "{s3}tx_streams:")?;
            for stream in node.tx_streams() {
                writeln!(f, "{s4}{} [{}]", stream.name(), stream.message().name())?;
                for oe in stream.mapping() {
                    let oe_name = match oe {
                        Some(oe) => oe.name(),
                        None => "None",
                    };
                    let oe_ty = match oe {
                        Some(oe) => oe.ty().name(),
                        None => "?".to_owned(),
                    };
                    writeln!(f, "{s5}<-{} : {}", oe_name, oe_ty)?;
                }
            }
            writeln!(f, "{s3}rx_streams:")?;
            for stream in node.rx_streams() {
                writeln!(f, "{s4}{} [{}]", stream.name(), stream.message().name())?;
                for oe in stream.mapping() {
                    let oe_name = match oe {
                        Some(oe) => oe.name(),
                        None => "None",
                    };
                    let oe_ty = match oe {
                        Some(oe) => oe.ty().name(),
                        None => "?".to_owned(),
                    };
                    writeln!(f, "{s5}->{} : {}", oe_name, oe_ty)?;
                }
            }
            writeln!(f, "{s3}types:")?;
            for ty in node.types() {
                writeln!(f, "{s4}{}", ty.name())?;
            }
        }
        Ok(())
    }
}
