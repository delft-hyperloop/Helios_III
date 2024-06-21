use std::{
    collections::{hash_map::DefaultHasher, hash_set, HashSet},
    hash::{Hash, Hasher},
};

use can_config_rs::{
    builder::{MessagePriority, NetworkBuilder},
    config::MessageId,
};
use regex::Replacer;

const CHECK_DET_ITERATIONS: u32 = 3;

struct MessageNameGen {
    acc: u32,
}
impl MessageNameGen {
    pub fn new() -> Self {
        Self { acc: 0 }
    }
    pub fn next(&mut self) -> String {
        let next = format!("test_msg_{}", self.acc);
        self.acc += 1;
        next
    }
}

fn check_builder(det: impl Fn() -> NetworkBuilder) {
    // Check for determinism
    let base = det().build().expect("failed the check the base case");
    // for it in 1..CHECK_DET_ITERATIONS {
    //     let cmp = det()
    //         .build()
    //         .expect(&format!("failed to build on the {it} iteration"));
    //     for m in cmp.messages() {
    //         // find in base case!
    //         let base_m = base
    //             .messages()
    //             .iter()
    //             .find(|x| x.name() == m.name())
    //             .expect("message only exists sometimes => BAD");
    //         println!(
    //             "comparing messages {} and {} in det iter {it}",
    //             base_m.name(),
    //             m.name()
    //         );
    //         assert_eq!(base_m.id(), m.id(), "ID assignment is not deterministic");
    //         assert_eq!(
    //             base_m.bus().id(),
    //             m.bus().id(),
    //             "BUS assignmetn is not deterministic"
    //         );
    //     }
    // }

    // Check for message collisions
    let mut id_set: HashSet<MessageId> = HashSet::new();
    for m in base.messages() {
        if id_set.contains(m.id()) {
            panic!("message collision {}", m.name());
        }
        id_set.insert(m.id().clone());
    }
}

#[test]
fn message_resolution_empty_config() {
    check_builder(|| {
        let network_builder = can_config_rs::builder::NetworkBuilder::new();

        network_builder
    });
}

fn perf1(node_count: u32, non_message_count: u32, fixed_message_count: u32, ide: bool) {
    check_builder(|| {
        let mut node_gen = MessageNameGen::new();
        let mut name_gen = MessageNameGen::new();

        let network_builder = can_config_rs::builder::NetworkBuilder::new();
        let mut message_ids_used: HashSet<u32> = HashSet::new();
        for _ in 0..node_count {
            let node_name = node_gen.next();
            network_builder.create_node(&node_name);
            for _ in 0..non_message_count {
                let name = name_gen.next();
                let message = network_builder.create_message(&name, None);
                let mut hasher = DefaultHasher::new();
                name.hash(&mut hasher);
                let hash = hasher.finish();
                message.set_any_std_id(MessagePriority::from_u32(
                    (hash as usize % MessagePriority::count()) as u32,
                ));
                message.add_receiver(&node_name);
            }
            for _ in 0..fixed_message_count {
                let mut name = name_gen.next();
                let message = network_builder.create_message(&name, None);
                message.add_receiver(&node_name);

                let mut hasher = DefaultHasher::new();
                loop {
                    name.hash(&mut hasher);
                    let hashed_id = if ide {
                        (hasher.finish() & 0x1FFFFFFF) as u32
                    } else {
                        (hasher.finish() & 0x7FF) as u32
                    };
                    if !message_ids_used.contains(&hashed_id) {
                        message_ids_used.insert(hashed_id);
                        println!("assign id {hashed_id}");
                        if ide {
                            message.set_ext_id(hashed_id);
                        } else {
                            message.set_std_id(hashed_id);
                        }
                        break;
                    }
                    name = name_gen.next();
                }
            }
        }
        network_builder
    });
}

#[test]
fn message_resolution_1x10_any_1x_std_fixed() {
    const FIXED_COUNT: u32 = 1;
    const MSG_COUNT: u32 = 10;
    const NODE_COUNT: u32 = 1;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        false,
    );
}

#[test]
fn message_resolution_1x10_any_2x_std_fixed() {
    const FIXED_COUNT: u32 = 2;
    const MSG_COUNT: u32 = 10;
    const NODE_COUNT: u32 = 1;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        false,
    );
}

#[test]
fn message_resolution_1x10_any_4x_std_fixed() {
    const FIXED_COUNT: u32 = 4;
    const MSG_COUNT: u32 = 10;
    const NODE_COUNT: u32 = 1;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        false,
    );
}

#[test]
fn message_resolution_1x10_any_8x_std_fixed() {
    const FIXED_COUNT: u32 = 8;
    const MSG_COUNT: u32 = 10;
    const NODE_COUNT: u32 = 1;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        false,
    );
}

#[test]
fn message_resolution_1x100_any_1x_std_fixed() {
    const FIXED_COUNT: u32 = 1;
    const MSG_COUNT: u32 = 100;
    const NODE_COUNT: u32 = 1;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        false,
    );
}

#[test]
fn message_resolution_1x100_any_10x_std_fixed() {
    const FIXED_COUNT: u32 = 10;
    const MSG_COUNT: u32 = 100;
    const NODE_COUNT: u32 = 1;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        false,
    );
}

#[test]
fn message_resolution_2x100_any_10x_std_fixed() {
    const FIXED_COUNT: u32 = 10;
    const MSG_COUNT: u32 = 100;
    const NODE_COUNT: u32 = 2;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        false,
    );
}

#[test]
fn message_resolution_2x200_any_20x_std_fixed() {
    const FIXED_COUNT: u32 = 20;
    const MSG_COUNT: u32 = 200;
    const NODE_COUNT: u32 = 2;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        false,
    );
}

#[test]
fn message_resolution_1x10_any_2x_ext_fixed() {
    const FIXED_COUNT: u32 = 2;
    const MSG_COUNT: u32 = 10;
    const NODE_COUNT: u32 = 1;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        true,
    );
}

#[test]
fn message_resolution_1x10_any_4x_ext_fixed() {
    const FIXED_COUNT: u32 = 4;
    const MSG_COUNT: u32 = 10;
    const NODE_COUNT: u32 = 1;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        true,
    );
}

#[test]
fn message_resolution_1x10_any_8x_ext_fixed() {
    const FIXED_COUNT: u32 = 8;
    const MSG_COUNT: u32 = 10;
    const NODE_COUNT: u32 = 1;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        true,
    );
}

#[test]
fn message_resolution_1x100_any_1x_ext_fixed() {
    const FIXED_COUNT: u32 = 1;
    const MSG_COUNT: u32 = 100;
    const NODE_COUNT: u32 = 1;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        true,
    );
}

#[test]
fn message_resolution_1x100_any_10x_ext_fixed() {
    const FIXED_COUNT: u32 = 10;
    const MSG_COUNT: u32 = 100;
    const NODE_COUNT: u32 = 1;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        true,
    );
}

#[test]
fn message_resolution_2x100_any_10x_ext_fixed() {
    const FIXED_COUNT: u32 = 10;
    const MSG_COUNT: u32 = 100;
    const NODE_COUNT: u32 = 2;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        true,
    );
}

#[test]
fn message_resolution_2x200_any_20x_ext_fixed() {
    const FIXED_COUNT: u32 = 20;
    const MSG_COUNT: u32 = 300;
    const NODE_COUNT: u32 = 2;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        true,
    );
}

#[test]
fn message_resolution_2x300_any_30x_ext_fixed() {
    const FIXED_COUNT: u32 = 30;
    const MSG_COUNT: u32 = 300;
    const NODE_COUNT: u32 = 2;
    perf1(
        NODE_COUNT,
        (MSG_COUNT - FIXED_COUNT) / NODE_COUNT,
        FIXED_COUNT / NODE_COUNT,
        true,
    );
}




#[test]
fn message_resolution_001_fixed_1to16x0to200() {
    for node_count in 1..16 {
        let max_msg_count = (200f64 / (node_count as f64)) as u32;
        for msg_count in 1..max_msg_count {
            perf1(
                node_count,
                (msg_count as f64 * (99f64 / 100f64)) as u32,
                (msg_count as f64 * (1f64 / 100f64)) as u32,
                false,
            );
        }
        for msg_count in 1..max_msg_count {
            perf1(
                node_count,
                (msg_count as f64 * (99f64 / 100f64)) as u32,
                (msg_count as f64 * (1f64 / 100f64)) as u32,
                true,
            );
        }
    }
}

#[test]
fn message_resolution_001_fixed_1to16x0to300() {
    for node_count in 1..16 {
        let max_msg_count = (300f64 / (node_count as f64)) as u32;
        for msg_count in 1..max_msg_count {
            perf1(
                node_count,
                (msg_count as f64 * (99f64 / 100f64)) as u32,
                (msg_count as f64 * (1f64 / 100f64)) as u32,
                false,
            );
        }
        for msg_count in 1..max_msg_count {
            perf1(
                node_count,
                (msg_count as f64 * (99f64 / 100f64)) as u32,
                (msg_count as f64 * (1f64 / 100f64)) as u32,
                true,
            );
        }
    }
}

#[test]
fn message_resolution_001_fixed_1to16x0to400() {
    for node_count in 1..16 {
        let max_msg_count = (400f64 / (node_count as f64)) as u32;
        for msg_count in 1..max_msg_count {
            perf1(
                node_count,
                (msg_count as f64 * (99f64 / 100f64)) as u32,
                (msg_count as f64 * (1f64 / 100f64)) as u32,
                false,
            );
        }
        for msg_count in 1..max_msg_count {
            perf1(
                node_count,
                (msg_count as f64 * (99f64 / 100f64)) as u32,
                (msg_count as f64 * (1f64 / 100f64)) as u32,
                true,
            );
        }
    }
}


#[test]
fn message_resolution_002_fixed_1to16x0to200() {
    for node_count in 1..16 {
        let max_msg_count = (200f64 / (node_count as f64)) as u32;
        for msg_count in 1..max_msg_count {
            perf1(
                node_count,
                (msg_count as f64 * (98f64 / 100f64)) as u32,
                (msg_count as f64 * (2f64 / 100f64)) as u32,
                false,
            );
        }
        for msg_count in 1..max_msg_count {
            perf1(
                node_count,
                (msg_count as f64 * (98f64 / 100f64)) as u32,
                (msg_count as f64 * (2f64 / 100f64)) as u32,
                true,
            );
        }
    }
}

// TODO i would like this to work!
// #[test]
// fn message_resolution_002_fixed_1to16x0to300() {
//     for node_count in 1..16 {
//         let max_msg_count = (300f64 / (node_count as f64)) as u32;
//         for msg_count in 1..max_msg_count {
//             perf1(
//                 node_count,
//                 (msg_count as f64 * (98f64 / 100f64)) as u32,
//                 (msg_count as f64 * (2f64 / 100f64)) as u32,
//                 false,
//             );
//         }
//         for msg_count in 1..max_msg_count {
//             perf1(
//                 node_count,
//                 (msg_count as f64 * (98f64 / 100f64)) as u32,
//                 (msg_count as f64 * (2f64 / 100f64)) as u32,
//                 true,
//             );
//         }
//     }
// }

// #[test]
// fn message_resolution_002_fixed_1to16x0to400() {
//     for node_count in 1..16 {
//         let max_msg_count = (400f64 / (node_count as f64)) as u32;
//         for msg_count in 1..max_msg_count {
//             perf1(
//                 node_count,
//                 (msg_count as f64 * (98f64 / 100f64)) as u32,
//                 (msg_count as f64 * (2f64 / 100f64)) as u32,
//                 false,
//             );
//         }
//         for msg_count in 1..max_msg_count {
//             perf1(
//                 node_count,
//                 (msg_count as f64 * (98f64 / 100f64)) as u32,
//                 (msg_count as f64 * (2f64 / 100f64)) as u32,
//                 true,
//             );
//         }
//     }
// }
