use crate::builder::{MessageBuilder, MessagePriority, NodeBuilder};

use super::{
    fixed_messages::FixedMessage,
    set_minimization::{MinimizedNetwork, MinimizedSet},
};

#[derive(Clone)]
struct AssignedSet {
    receivers: Vec<NodeBuilder>,
    fixed_messages: Vec<MessageBuilder>,
    fixed_ids: Vec<u32>,
    ide: bool,
    setcode: u32,
}

struct SetCodeAllocator {
    avaiable_setcodes: Vec<u32>,
}

impl SetCodeAllocator {
    pub fn new(setcode_len: u32) -> Self {
        Self {
            avaiable_setcodes: Vec::from_iter(0..(2u32).pow(setcode_len)),
        }
    }
    pub fn is_avaiable(&self, setcode: u32) -> bool {
        self.avaiable_setcodes.contains(&setcode)
    }
    pub fn allocate_setcode(&mut self, setcode: u32) -> bool {
        match self.avaiable_setcodes.iter().position(|x| *x == setcode) {
            Some(pos) => {
                self.avaiable_setcodes.remove(pos);
                true
            }
            None => {
                false
            }
        }
    }
    pub fn allocate_any(&mut self) -> Option<u32> {
        self.avaiable_setcodes.pop()
    }
}

pub enum FilterInfo {
    Setcode {
        setcode: u32,
        setcode_len: u32,
        ide: bool,
    },
    Single {
        id: u32,
        ide: bool,
    },
}

pub struct NodeFilterInfo {
    node: NodeBuilder,
    filters: Vec<FilterInfo>,
}

impl NodeFilterInfo {
    pub fn node(&self) -> &NodeBuilder {
        &self.node
    }
    pub fn filter_infos(&self) -> &Vec<FilterInfo> {
        &self.filters
    }
}

pub fn assign_messages_ids(
    fixed_messages: &Vec<FixedMessage>,
    minimized_network: MinimizedNetwork,
    nodes: &Vec<NodeBuilder>,
) -> Vec<NodeFilterInfo> {
    let setcode_len = (minimized_network.sets().len() as f64).log2().ceil() as u32;
    let mut setcode_allocator = SetCodeAllocator::new(setcode_len);
    let mut fixed_messages = fixed_messages.clone();

    let max_messages_per_set = (2u32).pow(
        (minimized_network.bucket_layout().total_bucket_size() as f64)
            .log2()
            .ceil() as u32,
    ) as usize;

    let mut set_pair: Vec<(Option<AssignedSet>, &MinimizedSet)> =
        std::iter::zip(std::iter::repeat(None), minimized_network.sets()).collect();

    // assign fixed ids
    for (assigned_set, set) in set_pair.iter_mut() {
        let message_count: usize = (0..MessagePriority::count())
            .into_iter()
            .map(|prio| set.messages_with_priority(prio).len())
            .sum();
        let mut free_space = max_messages_per_set - message_count;

        // find all fixed ids that could be inserted into the set!
        let tmp = fixed_messages.clone();
        let allowed_fixed_messages: Vec<&FixedMessage> = tmp
            .iter()
            .filter(|fixed| fixed.ide() == set.id().ide() && fixed.same_receivers_as_set(set.id()))
            .collect();
        let mut setcode: Option<u32> = None;
        let mut assigned_fixed_messages = vec![];
        for fixed_message in allowed_fixed_messages {
            if free_space == 0 {
                break;
            }
            let id = fixed_message.id();
            let code = id & 0xFFFFFFFFu32.checked_shr(32 - setcode_len as u32).unwrap_or(0);
            let ok = match setcode {
                Some(setcode) => setcode == code,
                None => setcode_allocator.allocate_setcode(code),
            };
            if ok {
                setcode = Some(code);
                free_space -= 1;
                assigned_fixed_messages.push(fixed_message.clone());
                fixed_messages.remove(
                    fixed_messages
                        .iter()
                        .position(|f| {
                            f.ide() == fixed_message.ide() && f.id() == fixed_message.id()
                        })
                        .expect("wtf"),
                );
            }
        }
        let Some(setcode) = setcode else {
            continue;
        };

        *assigned_set = Some(AssignedSet {
            setcode,
            fixed_ids: assigned_fixed_messages.iter().map(|f| f.id()).collect(),
            fixed_messages: assigned_fixed_messages
                .iter()
                .map(|f| f.message().clone())
                .collect(),
            ide: set.id().ide(),
            receivers: set.id().receivers().clone(),
        });
    }

    // assign other ids.
    for (assigned_set, set) in set_pair.iter_mut() {
        let assigned_set = match assigned_set {
            Some(set) => set,
            None => {
                let setcode = setcode_allocator
                    .allocate_any()
                    .expect("ran out of setcodes to allocate");
                *assigned_set = Some(AssignedSet {
                    setcode,
                    fixed_ids: vec![],
                    fixed_messages: vec![],
                    ide: set.id().ide(),
                    receivers: set.id().receivers().clone(),
                });
                assigned_set.as_mut().unwrap()
            }
        };
        let setcode = assigned_set.setcode;
        let mut reserved_ids: Vec<u32> =
            Vec::from_iter(assigned_set.fixed_ids.clone().into_iter());

        let bucket_layout = minimized_network.bucket_layout();

        let mut bucket_offset = 0;
        for prio in 0..MessagePriority::count() {
            for msg in set.messages_with_priority(prio) {
                let prio_offset = (0..max_messages_per_set - bucket_offset).find(|prio_offset| {
                    let priority = (bucket_offset + *prio_offset) as u32;
                    let id = (priority << setcode_len) | setcode;
                    !reserved_ids.contains(&id)
                });
                let prio_offset: i32 = match prio_offset {
                    Some(offset) => offset as i32,
                    None => (-1..-(bucket_offset as i32) - 1)
                        .find(|prio_offset| {
                            let priority = (bucket_offset as i32 + *prio_offset) as u32;
                            let id = (priority << setcode_len) | setcode;
                            !reserved_ids.contains(&id)
                        })
                        .expect(
                            "fixed message was probably inserted in a set where there wasn't space for it",
                        ),
                };
                let priority = (bucket_offset as i32 + prio_offset) as u32;
                let id = (priority << setcode_len) | setcode;
                assert!(!reserved_ids.contains(&id));
                reserved_ids.push(id);
                if assigned_set.ide {
                    msg.set_ext_id(id);
                } else {
                    msg.set_std_id(id);
                }
                assigned_set.fixed_messages.push(msg.clone());
                assigned_set.fixed_ids.push(id);
                assert!(assigned_set.ide == set.id().ide());
            }
            bucket_offset += bucket_layout.bucket_size(prio);
        }
    }

    nodes
        .iter()
        .map(|node| {
            let node_name = node.0.borrow().name.clone();
            NodeFilterInfo {
                node: node.clone(),
                filters: set_pair
                    .iter()
                    .map(|(a, _)| a)
                    .flatten()
                    .filter(|x| x.receivers.iter().any(|n| n.0.borrow().name == node_name))
                    .map(|x| FilterInfo::Setcode {
                        setcode: x.setcode,
                        setcode_len,
                        ide: x.ide,
                    })
                    .collect(),
            }
        })
        .collect()
}
