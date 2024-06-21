use crate::builder::MessageBuilder;

use super::set_minimization::set_identifier::SetIdentifier;

#[derive(Clone)]
pub struct FixedMessage {
    message: MessageBuilder,
    id: u32,
    ide: bool,
}

impl FixedMessage {
    pub fn message(&self) -> &MessageBuilder {
        &self.message
    }
    pub fn same_receivers_as_set(&self, set_identifier : &SetIdentifier) -> bool {
        let mut rx = self.message.0.borrow().receivers.clone();
        rx.sort_by_key(|n| n.0.borrow().name.clone());
        for (na, nb) in std::iter::zip(rx, set_identifier.receivers()) {
            let nn = na.0.borrow().name.clone();
            if nn != nb.0.borrow().name {
                return false;
            }
        }
        true
    }
    pub fn id(&self) -> u32 {
        self.id
    }
    pub fn ide(&self) -> bool {
        self.ide
    }
}

pub struct MessageSplit {
    fixed_messages: Vec<FixedMessage>,
    prio_messages: Vec<MessageBuilder>,
}

impl MessageSplit {
    pub fn fixed_messages(&self) -> &Vec<FixedMessage> {
        &self.fixed_messages
    }
    pub fn prio_messages(&self) -> &Vec<MessageBuilder> {
        &self.prio_messages
    }
}

impl MessageSplit {
    pub fn from(messages: &Vec<MessageBuilder>) -> MessageSplit {
        let mut fixed_messages = vec![];
        let mut prio_messages = vec![];

        for message in messages {
            match message.0.borrow().id {
                crate::builder::message_builder::MessageIdTemplate::StdId(id) => {
                    fixed_messages.push(FixedMessage {
                        message: message.clone(),
                        id,
                        ide: false,
                    });
                }
                crate::builder::message_builder::MessageIdTemplate::ExtId(id) => {
                    fixed_messages.push(FixedMessage {
                        message: message.clone(),
                        id,
                        ide: true,
                    });
                }
                crate::builder::message_builder::MessageIdTemplate::AnyStd(_)
                | crate::builder::message_builder::MessageIdTemplate::AnyExt(_) => {
                    prio_messages.push(message.clone())
                }
                crate::builder::message_builder::MessageIdTemplate::AnyAny(_) => {
                    panic!("ANY ANY Id Template is deprecated and not supported")
                }
            }
        }
        MessageSplit {
            fixed_messages,
            prio_messages,
        }
    }
}
