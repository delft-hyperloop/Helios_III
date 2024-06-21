use std::time::Duration;

use crate::{
    builder::{MessageBuilder, NetworkBuilder},
    config::{Type, TypeRef},
};


#[allow(unused)]
struct MessageInfo {
    assigned_priority: String,
    assigned_bus: String,
    message: MessageBuilder,
}

pub struct LogInfo {
    messages: Vec<MessageInfo>,
    types: Vec<TypeRef>,
}

#[allow(unused)]
pub fn cache_logging_info(types: &Vec<TypeRef>, messages: &Vec<MessageBuilder>) -> LogInfo {
    LogInfo {
        types: types.clone(),
        messages: messages
            .iter()
            .map(|msg| {
                let data = msg.0.borrow();
                let prio = match &data.id {
                    crate::builder::message_builder::MessageIdTemplate::StdId(id) => {
                        format!("0x{id:X}")
                    }
                    crate::builder::message_builder::MessageIdTemplate::ExtId(id) => {
                        format!("0x{id:X}x")
                    }
                    crate::builder::message_builder::MessageIdTemplate::AnyStd(prio) => {
                        format!("{prio:?}")
                    }
                    crate::builder::message_builder::MessageIdTemplate::AnyExt(prio) => {
                        format!("{prio:?}x")
                    }
                    crate::builder::message_builder::MessageIdTemplate::AnyAny(_) => panic!(),
                };
                let bus = match &data.bus {
                    Some(bus) => bus.0.borrow().name.clone(),
                    None => "any".to_owned(),
                };
                MessageInfo {
                    assigned_priority: prio,
                    assigned_bus: bus,
                    message: msg.clone(),
                }
            })
            .collect(),
    }
}

fn load_estimation(types: &Vec<TypeRef>, msg: &MessageBuilder) -> f64 {
    let ide = match msg.0.borrow().id {
        crate::builder::message_builder::MessageIdTemplate::StdId(_) => false,
        crate::builder::message_builder::MessageIdTemplate::ExtId(_) => true,
        crate::builder::message_builder::MessageIdTemplate::AnyStd(_)
        | crate::builder::message_builder::MessageIdTemplate::AnyExt(_)
        | crate::builder::message_builder::MessageIdTemplate::AnyAny(_) => panic!("unresolved id"),
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
                let ty =
                    NetworkBuilder::resolve_type(types, attr_ty).expect("failed to resolve type");
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
    (max_bitlen as f64 / interval.as_millis() as f64) * 1e3f64
}

#[allow(unused)]
pub fn log_info(log_info: LogInfo) {
    let mut messages = log_info.messages;
    messages.sort_by_key(|msg_info| match msg_info.message.0.borrow().id {
        crate::builder::message_builder::MessageIdTemplate::StdId(id) => id,
        crate::builder::message_builder::MessageIdTemplate::ExtId(id) => id,
        crate::builder::message_builder::MessageIdTemplate::AnyStd(_)
        | crate::builder::message_builder::MessageIdTemplate::AnyExt(_)
        | crate::builder::message_builder::MessageIdTemplate::AnyAny(_) => panic!("unassigned id"),
    });

    let mut bus_messages: Vec<(String, Vec<MessageInfo>)> = vec![];
    for msg in messages {
        let bus_name = msg
            .message
            .0
            .borrow()
            .bus
            .clone()
            .expect("unresolved bus")
            .0
            .borrow()
            .name
            .clone();
        match bus_messages.iter().position(|b| b.0 == bus_name) {
            Some(pos) => bus_messages[pos].1.push(msg),
            None => bus_messages.push((bus_name, vec![msg])),
        }
    }
    for (bus_name, messages) in &mut bus_messages {
        println!("BUS : {bus_name}");
        // sort messages by id!
        messages.sort_by_key(|m| match m.message.0.borrow().id {
            crate::builder::message_builder::MessageIdTemplate::StdId(id) => id,
            crate::builder::message_builder::MessageIdTemplate::ExtId(id) => id,
            crate::builder::message_builder::MessageIdTemplate::AnyStd(_)
            | crate::builder::message_builder::MessageIdTemplate::AnyExt(_)
            | crate::builder::message_builder::MessageIdTemplate::AnyAny(_) => {
                panic!("unresolved id")
            }
        });
        let mut bus_load = 0f64;
        for msg in messages {
            bus_load += load_estimation(&log_info.types, &msg.message);

            let prev_prio = &msg.assigned_priority;
            // let prev_bus = &msg.assigned_bus;
            let msg_name = msg.message.0.borrow().name.clone();
            let id = match msg.message.0.borrow().id {
                crate::builder::message_builder::MessageIdTemplate::StdId(id) => {
                    format!("0x{id:X}")
                }
                crate::builder::message_builder::MessageIdTemplate::ExtId(id) => {
                    format!("0x{id:X}x")
                }
                crate::builder::message_builder::MessageIdTemplate::AnyStd(_)
                | crate::builder::message_builder::MessageIdTemplate::AnyExt(_)
                | crate::builder::message_builder::MessageIdTemplate::AnyAny(_) => {
                    panic!("unresolved id")
                }
            };
            println!("{msg_name} : [{prev_prio}] -> {id}");
        }
        println!("BusLoad = {bus_load}");
    }
}
