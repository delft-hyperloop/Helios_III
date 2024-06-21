use std::collections::HashSet;

use can_config_rs::{
    builder::{MessagePriority, NetworkBuilder},
    config::MessageId,
};

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
    for it in 1..CHECK_DET_ITERATIONS {
        let cmp = det()
            .build()
            .expect(&format!("failed to build on the {it} iteration"));
        for m in cmp.messages() {
            // find in base case!
            let base_m = base
                .messages()
                .iter()
                .find(|x| x.name() == m.name())
                .expect("message only exists sometimes => BAD");
            println!(
                "comparing messages {} and {} in det iter {it}",
                base_m.name(),
                m.name()
            );
            assert_eq!(base_m.id(), m.id(), "ID assignment is not deterministic");
            assert_eq!(
                base_m.bus().id(),
                m.bus().id(),
                "BUS assignmetn is not deterministic"
            );
        }
    }

    // Check for message collisions
    let mut id_set: HashSet<MessageId> = HashSet::new();
    for m in base.messages() {
        if id_set.contains(m.id()) {
            panic!("message collision");
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

fn perf1(node_count: u32, message_count: u32, _: Vec<MessagePriority>) {
    check_builder(|| {
        let mut node_gen = MessageNameGen::new();
        let mut name_gen = MessageNameGen::new();

        let network_builder = can_config_rs::builder::NetworkBuilder::new();
        for _ in 0..node_count {
            let node_name = node_gen.next();
            network_builder.create_node(&node_name);
            for _ in 0..message_count {
                let message = network_builder.create_message(&name_gen.next(), None);
                message.set_any_std_id(MessagePriority::Normal);
                message.add_receiver(&node_name);
            }
        }
        network_builder
    });
}

#[test]
fn message_resolution_1x1000_normal_prio() {
    perf1(1, 1000, vec![MessagePriority::Normal]);
}

#[test]
fn message_resolution_1x1000_super_low() {
    perf1(1, 1000, vec![MessagePriority::SuperLow]);
}

#[test]
fn message_resolution_1x1000_realtime() {
    perf1(1, 1000, vec![MessagePriority::Realtime]);
}

// tests that take a long time

#[test]
fn message_resolution_1x2000_normal() {
    perf1(1, 2000, vec![MessagePriority::Normal]);
}

#[test]
fn message_resolution_1x2000_superlow() {
    perf1(1, 2000, vec![MessagePriority::SuperLow]);
}

#[test]
fn message_resolution_1x2000_realtime() {
    perf1(1, 2000, vec![MessagePriority::Realtime]);
}

#[test]
fn message_resolution_2x500_normal() {
    perf1(2, 500, vec![MessagePriority::Normal]);
}

#[test]
fn message_resolution_2x500_superlow() {
    perf1(2, 500, vec![MessagePriority::SuperLow]);
}

#[test]
fn message_resolution_2x500_realtime() {
    perf1(2, 500, vec![MessagePriority::Realtime]);
}

#[test]
fn message_resolution_2x1000_normal() {
    perf1(2, 1000, vec![MessagePriority::Normal]);
}

#[test]
fn message_resolution_2x1000_superlow() {
    perf1(2, 1000, vec![MessagePriority::SuperLow]);
}

#[test]
fn message_resolution_2x1000_realtime() {
    perf1(2, 1000, vec![MessagePriority::Realtime]);
}

#[test]
fn message_resolution_4x500_normal() {
    perf1(4, 500, vec![MessagePriority::Normal]);
}

#[test]
fn message_resolution_4x500_superlow() {
    perf1(4, 500, vec![MessagePriority::SuperLow]);
}

#[test]
fn message_resolution_4x500_realtime() {
    perf1(4, 500, vec![MessagePriority::Realtime]);
}


#[test]
fn message_resolution_8x250_normal() {
    perf1(8, 250, vec![MessagePriority::Normal]);
}

#[test]
fn message_resolution_8x250_superlow() {
    perf1(8, 250, vec![MessagePriority::SuperLow]);
}

#[test]
fn message_resolution_8x250_realtime() {
    perf1(8, 250, vec![MessagePriority::Realtime]);
}


#[test]
fn message_resolution_16x125_normal() {
    perf1(16, 125, vec![MessagePriority::Normal]);
}

#[test]
fn message_resolution_16x125_superlow() {
    perf1(16, 125, vec![MessagePriority::SuperLow]);
}

#[test]
fn message_resolution_16x125_realtime() {
    perf1(16, 125, vec![MessagePriority::Realtime]);
}

#[test]
fn message_resolution_32x75_normal() {
    perf1(32, 75, vec![MessagePriority::Normal]);
}

#[test]
fn message_resolution_32x75_superlow() {
    perf1(32, 75, vec![MessagePriority::SuperLow]);
}

#[test]
fn message_resolution_32x75_realtime() {
    perf1(32, 75, vec![MessagePriority::Realtime]);
}

