use std::{time::Duration, cmp::Ordering};

use crate::{
    builder::{bus::BusBuilder, MessageBuilder, NetworkBuilder},
    config::{TypeRef, Type},
};

struct AssignedMessage {
    message: MessageWithLoad,
    bus: String,
}

struct MessageBusSplit {
    assigned: Vec<AssignedMessage>,
    unassigned: Vec<MessageWithLoad>,
}

impl MessageBusSplit {
    pub fn from(messages: &Vec<MessageWithLoad>) -> Self {
        let mut assigned = vec![];
        let mut unassigned = vec![];

        for message in messages {
            match &message.message.0.borrow().bus {
                Some(bus) => assigned.push(AssignedMessage {
                    message: message.clone(),
                    bus: bus.0.borrow().name.clone(),
                }),
                None => unassigned.push(message.clone()),
            }
        }

        Self {
            assigned,
            unassigned,
        }
    }
}

#[derive(PartialEq)]
struct BusInfo {
    bus_id: u32,
    bus_name: String,
    load: f64,
}

impl BusInfo {
    pub fn new(bus_id: u32, bus_name: &str) -> Self {
        Self {
            bus_id,
            bus_name: bus_name.to_owned(),
            load: 0f64,
        }
    }
}

impl PartialOrd for BusInfo {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        if self.load.is_nan() || other.load.is_nan() {
            return Some(Ordering::Equal)
        }
        if self.load < other.load {
            return Some(Ordering::Less)
        }else if self.load > other.load{
            return Some(Ordering::Greater)
        }else {
            return Some(Ordering::Equal)
        }
    }
}

impl Eq for BusInfo { }
impl Ord for BusInfo {

    fn cmp(&self, other: &Self) -> Ordering {
        if self.load.is_nan() || other.load.is_nan() {
            return Ordering::Equal
        }
        if self.load < other.load {
            return Ordering::Less
        }else if self.load > other.load{
            return Ordering::Greater
        }else {
            return Ordering::Equal
        }
    }
}

struct Buses {
    buses: Vec<BusInfo>,
}

impl Buses {
    pub fn from(buses: &Vec<BusBuilder>) -> Self {
        Self {
            buses: buses
                .iter()
                .enumerate()
                .map(|(bus_id, builder)| BusInfo::new(bus_id as u32, &builder.0.borrow().name))
                .collect(),
        }
    }

    pub fn add_message(&mut self, message : AssignedMessage) { 
        let bus = self.buses.iter_mut().find(|b| b.bus_name == message.bus).expect("invalid bus");
        bus.load += message.message.load;
    }
    pub fn add_message_to_min_load(&mut self, message : MessageWithLoad) {
        let bus = self.buses.iter_mut().min().unwrap();
        message.message.assign_bus(&bus.bus_name);
        bus.load += message.load;
    }
}

#[derive(Clone)]
struct MessageWithLoad {
    message: MessageBuilder,
    load: f64,
}

impl MessageWithLoad {
    pub fn from(types : &Vec<TypeRef>, msg: &MessageBuilder) -> Self {
        let ide = match msg.0.borrow().id {
            crate::builder::message_builder::MessageIdTemplate::StdId(_) => false,
            crate::builder::message_builder::MessageIdTemplate::ExtId(_) => true,
            crate::builder::message_builder::MessageIdTemplate::AnyStd(_)
            | crate::builder::message_builder::MessageIdTemplate::AnyExt(_)
            | crate::builder::message_builder::MessageIdTemplate::AnyAny(_) => {
                panic!("unresolved id")
            }
        };
        let dlc = match &msg.0.borrow().format {
            crate::builder::MessageFormat::Signals(signal_format) => signal_format
                .0
                .borrow()
                .0
                .iter()
                .map(|s| s.byte_offset() + s.size() as usize)
                .max()
                .unwrap(),
            crate::builder::MessageFormat::Types(type_format) => {
                fn acc_dlc(ty: &Type) -> usize {
                    match ty {
                        crate::config::Type::Primitive(signal_type) => signal_type.size() as usize,
                        crate::config::Type::Struct {
                            name: _,
                            description: _,
                            attribs,
                            visibility: _,
                        } => attribs.iter().map(|(_, ty)| acc_dlc(ty)).sum(),
                        crate::config::Type::Enum {
                            name: _,
                            description: _,
                            size,
                            entries: _,
                            visibility: _,
                        } => *size as usize,
                        crate::config::Type::Array { len: _, ty: _ } => todo!(),
                    }
                }
                let mut dlc = 0usize;
                for (attr_ty, _) in &type_format.0.borrow().0 {
                    let ty = NetworkBuilder::resolve_type(types, attr_ty)
                        .expect("failed to resolve type");
                    dlc += acc_dlc(&ty);
                }
                dlc
            }
            crate::builder::MessageFormat::Empty => 0,
        };

        let max_bitlen: usize;
        if ide {
            max_bitlen = 8 * dlc + 64 + (54 + 8 * dlc - 1) / 4;
        } else {
            max_bitlen = 8 * dlc + 44 + (34 + 8 * dlc - 1) / 4;
        }
        let interval = match &msg.0.borrow().usage {
            crate::builder::message_builder::MessageBuilderUsage::Stream(stream_builder) => {
                stream_builder.0.borrow().interval.1
            }
            crate::builder::message_builder::MessageBuilderUsage::CommandResp(command_builder)
            | crate::builder::message_builder::MessageBuilderUsage::CommandReq(command_builder) => {
                command_builder.0.borrow().expected_interval
            }
            crate::builder::message_builder::MessageBuilderUsage::Configuration => {
                Duration::from_millis(100)
            }
            crate::builder::message_builder::MessageBuilderUsage::Heartbeat => {
                Duration::from_millis(100)
            }
            crate::builder::message_builder::MessageBuilderUsage::External { interval } => {
                interval.unwrap_or(Duration::from_millis(50))
            }
        };
        let load = (max_bitlen as f64 / interval.as_millis() as f64) * 1e3f64;
        Self {
            message : msg.clone(),
            load,
        }
    }
}

impl PartialEq for MessageWithLoad {
    fn eq(&self, other: &Self) -> bool {
        self.load == other.load
    }
}

impl PartialOrd for MessageWithLoad {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        if self.load.is_nan() || other.load.is_nan() {
            return Some(Ordering::Equal)
        }
        if self.load < other.load {
            return Some(Ordering::Less)
        }else if self.load > other.load{
            return Some(Ordering::Greater)
        }else {
            return Some(Ordering::Equal)
        }
    }
}

impl Eq for MessageWithLoad { }
impl Ord for MessageWithLoad {

    fn cmp(&self, other: &Self) -> Ordering {
        if self.load.is_nan() || other.load.is_nan() {
            return Ordering::Equal
        }
        if self.load < other.load {
            return Ordering::Less
        }else if self.load > other.load{
            return Ordering::Greater
        }else {
            return Ordering::Equal
        }
    }
}

pub fn balance_buses(
    messages: &Vec<MessageBuilder>,
    types: &Vec<TypeRef>,
    buses: &Vec<BusBuilder>,
) {
    let mut buses = Buses::from(buses);
    let messages : Vec<MessageWithLoad> = messages.iter().map(|msg| MessageWithLoad::from(types, msg)).collect();
    let message_split = MessageBusSplit::from(&messages);
    
    for msg in message_split.assigned {
        buses.add_message(msg);
    }
    let mut unassigned = message_split.unassigned.clone();
    unassigned.sort();
    for msg in unassigned {
        buses.add_message_to_min_load(msg);
    }

}
