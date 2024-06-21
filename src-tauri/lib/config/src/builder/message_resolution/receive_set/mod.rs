use std::rc::Rc;
use std::time::Duration;

use crate::builder::message_resolution::set_minimization::MinimizedSet;
use crate::builder::{MessageBuilder, MessagePriority, NetworkBuilder, NodeBuilder};
use crate::config::{Type, TypeRef};

use self::node_receive_set::NodeReceiveSet;

use super::set_minimization::bucket_layout::{BucketLayout, BucketLayoutCommit};
use super::set_minimization::priority_bucket::PriorityBucket;
use super::set_minimization::set_identifier::SetIdentifier;

pub mod node_receive_set;

pub type ReceiverSetRef = Rc<ReceiverSet>;


pub struct ReceiverSet {
    id: SetIdentifier,
    priority_buckets: [PriorityBucket; MessagePriority::count()],
}

pub struct NetworkInfo {
    receive_sets: Vec<ReceiverSetRef>,
    node_receive_sets : Vec<NodeReceiveSet>,
    nodes: Vec<NodeBuilder>,
}

impl NetworkInfo {
    pub fn receive_sets(&self) -> &Vec<ReceiverSetRef> {
        &self.receive_sets
    }
    pub fn nodes(&self) -> &Vec<NodeBuilder> {
        &self.nodes
    }
    pub fn node_receive_sets(&self) -> &Vec<NodeReceiveSet> {
        &self.node_receive_sets
    }
}

impl ReceiverSet {
    pub fn new(id: SetIdentifier) -> Self {
        Self {
            id,
            priority_buckets: std::array::from_fn(|_| PriorityBucket::new()),
        }
    }
    pub fn identifier(&self) -> &SetIdentifier {
        &self.id
    }
    pub fn insert_message(&mut self, message: &MessageBuilder) {
        match message.0.borrow().id {
            crate::builder::message_builder::MessageIdTemplate::StdId(_)
            | crate::builder::message_builder::MessageIdTemplate::ExtId(_) => {
                panic!("receive sets do not support fixed ids")
            }
            crate::builder::message_builder::MessageIdTemplate::AnyStd(prio)
            | crate::builder::message_builder::MessageIdTemplate::AnyExt(prio)
            | crate::builder::message_builder::MessageIdTemplate::AnyAny(prio) => {
                self.priority_buckets[prio.to_u32() as usize].insert_message(message);
            }
        }
    }
    pub fn set_count(&self, bucket_layout: &BucketLayout) -> usize {
        self.priority_buckets
            .iter()
            .enumerate()
            .map(|(p, b)| b.required_sets(bucket_layout.bucket_size(p)))
            .max()
            .expect("priority_buckets should not be empty!")
    }

    pub fn priorioty_bucket(&self, priority: usize) -> &PriorityBucket {
        &self.priority_buckets[priority]
    }

    pub fn min_commit_to_merge(&self, bucket_layout: &BucketLayout) -> Option<BucketLayoutCommit> {
        let mut inc = [0usize; MessagePriority::count()];
        let set_count = self.set_count(bucket_layout);
        for prio in 0..MessagePriority::count() {
            // check if the priority bucket is limiting the merge
            if self.priority_buckets[prio].required_sets(bucket_layout.bucket_size(prio))
                == set_count
            {
                inc[prio] = self.priority_buckets[prio]
                    .required_inc_for_merge(bucket_layout.bucket_size(prio))
                    .unwrap_or(0);
            }
        }
        if inc.iter().sum::<usize>() == 0 {
            None
        } else {
            Some(BucketLayoutCommit::new(inc))
        }
    }

    pub fn to_minimized_sets(&self, bucket_layout: &BucketLayout) -> Vec<MinimizedSet> {
        let mut min_sets_priority_buckets: Vec<[Vec<MessageBuilder>; MessagePriority::count()]> =
            vec![];
        for _ in 0..self.set_count(bucket_layout) {
            min_sets_priority_buckets.push(std::array::from_fn(|_| vec![]));
        }

        for priority in 0..MessagePriority::count() {
            let bucket_messages = self.priority_buckets[priority].messages();
            let mut insert_set_id = 0;
            for bucket_message in bucket_messages {
                let min_set_priority_bucket =
                    &mut min_sets_priority_buckets[insert_set_id][priority];
                min_set_priority_bucket.push(bucket_message.clone());
                if min_set_priority_bucket.len() == bucket_layout.bucket_size(priority) {
                    insert_set_id += 1;
                }
            }
        }

        let minimized_sets: Vec<MinimizedSet> = min_sets_priority_buckets
            .into_iter()
            .map(|min_set| MinimizedSet::new(min_set, self.id.clone()))
            .collect();
        assert_eq!(minimized_sets.len(), self.set_count(bucket_layout));

        minimized_sets
    }

    pub fn bus_load(&self, types: &Vec<TypeRef>) -> f64 {
        let mut bus_load = 0.0f64;
        for priority in 0..MessagePriority::count() {
            for message in self.priority_buckets[priority].messages() {
                let message_data = message.0.borrow();
                let dlc = match &message_data.format {
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
                                crate::config::Type::Primitive(signal_type) => {
                                    signal_type.size() as usize
                                }
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
                    crate::builder::MessageFormat::Empty => 0usize,
                };
                let max_bitlen: usize;
                if self.identifier().ide() {
                    max_bitlen = 8 * dlc + 64 + (54 + 8 * dlc - 1) / 4;
                } else {
                    max_bitlen = 8 * dlc + 44 + (34 + 8 * dlc - 1) / 4;
                }
                let interval = match &message.0.borrow().usage {
                    crate::builder::message_builder::MessageBuilderUsage::Stream(
                        stream_builder,
                    ) => stream_builder.0.borrow().interval.1,
                    crate::builder::message_builder::MessageBuilderUsage::CommandResp(
                        command_builder,
                    )
                    | crate::builder::message_builder::MessageBuilderUsage::CommandReq(
                        command_builder,
                    ) => command_builder.0.borrow().expected_interval,
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
                bus_load += max_bitlen as f64 / interval.as_secs() as f64;
            }
        }
        bus_load
    }
}

pub fn generate_receive_sets_from_messages(nodes : &Vec<NodeBuilder>, messages: &Vec<MessageBuilder>) -> NetworkInfo {
    let mut receiver_sets: Vec<ReceiverSet> = vec![];
    let mut rx_nodes: Vec<NodeBuilder> = vec![];
    for message in messages {
        let bus = message.0.borrow().bus.clone().map(|bus| bus.0.borrow().id);
        let ide = match message.0.borrow().id {
            crate::builder::message_builder::MessageIdTemplate::StdId(_) |
            crate::builder::message_builder::MessageIdTemplate::ExtId(_) => {
                panic!("receive sets do not support fixed ids")
            }
            crate::builder::message_builder::MessageIdTemplate::AnyStd(_) => false,
            crate::builder::message_builder::MessageIdTemplate::AnyExt(_) => true,
            crate::builder::message_builder::MessageIdTemplate::AnyAny(_) => panic!("receive sets do not support AnyAny id templates"),
        };
        let set_identifier = SetIdentifier::new(&message.0.borrow().receivers, bus, ide);
        for rx in &message.0.borrow().receivers {
            let rx_name: String = rx.0.borrow().name.clone();
            if !rx_nodes.iter().any(|node| node.0.borrow().name == rx_name) {
                rx_nodes.push(rx.clone());
            }
        }
        let set_position = receiver_sets
            .iter()
            .position(|rx_set| rx_set.identifier().eq(&set_identifier));
        match set_position {
            Some(set_position) => receiver_sets[set_position].insert_message(message),
            None => {
                let mut new_receiver_set = ReceiverSet::new(set_identifier);
                new_receiver_set.insert_message(message);
                receiver_sets.push(new_receiver_set);
            }
        }
    }

    let receiver_sets: Vec<Rc<ReceiverSet>> = receiver_sets
        .into_iter()
        .map(|rx_set| Rc::new(rx_set))
        .collect();

    let node_receive_sets = 
                nodes
                .iter()
                .map(|node| {
                    let node_name = node.0.borrow().name.clone();
                    let rx_sets: Vec<ReceiverSetRef> = receiver_sets
                        .iter()
                        .map(|rx_set| rx_set.clone())
                        .filter(|rx_set| {
                            rx_set
                                .identifier()
                                .receivers()
                                .iter()
                                .any(|rx| rx.0.borrow().name == node_name)
                        })
                        .collect();
                    NodeReceiveSet::new(node_name, rx_sets)
                })
                .collect();

    NetworkInfo {
        receive_sets: receiver_sets,
        nodes : nodes.clone(),
        node_receive_sets
    }
}
