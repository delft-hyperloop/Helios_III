use self::set_identifier::SetIdentifier;
use crate::builder::MessagePriority;
use crate::builder::{
    message_resolution::set_minimization::bucket_layout::BucketLayout, MessageBuilder,
};

use super::receive_set::NetworkInfo;

pub mod bucket_layout;
pub mod priority_bucket;
pub mod set_identifier;

const MAX_FILTERS_PER_NODE: usize = 8;
const STD_ID_LENGTH: u32 = 11;

const LOGGING: bool = false;

pub struct MinimizedSet {
    messages: [Vec<MessageBuilder>; MessagePriority::count()],
    id: SetIdentifier,
}

impl MinimizedSet {
    pub fn new(
        messages: [Vec<MessageBuilder>; MessagePriority::count()],
        id: SetIdentifier,
    ) -> Self {
        Self { messages, id }
    }
    pub fn messages_with_priority(&self, priority: usize) -> &Vec<MessageBuilder> {
        &self.messages[priority]
    }
    pub fn message_buckets(&self) -> &[Vec<MessageBuilder>; MessagePriority::count()] {
        &self.messages
    }
    pub fn id(&self) -> &SetIdentifier {
        &self.id
    }
}

pub struct MinimizedNetwork {
    sets: Vec<MinimizedSet>,
    bucket_layout: BucketLayout,
}

impl MinimizedNetwork {
    pub fn new(sets: Vec<MinimizedSet>, bucket_layout: BucketLayout) -> Self {
        Self {
            sets,
            bucket_layout,
        }
    }
    pub fn bucket_layout(&self) -> &BucketLayout {
        &self.bucket_layout
    }
    pub fn into_bucket_layout(self) -> BucketLayout {
        self.bucket_layout
    }
    pub fn sets(&self) -> &Vec<MinimizedSet> {
        &self.sets
    }
}

/**
 * messages is not allowed to contain messages with fixed id assignments!
 */

pub fn minimize_sets(network_info: NetworkInfo) -> MinimizedNetwork {
    if network_info.node_receive_sets().is_empty() {
        assert_eq!(network_info.receive_sets().len(), 1, "It is assumed that if no receiver exists in 
                   the network that all messages are defined by the config itself are are std and non fixed");
        let set = network_info.receive_sets().first().unwrap();
        let mut bucket_layout = BucketLayout::new();

        loop {
            let Some(commit) = set.min_commit_to_merge(&bucket_layout) else {
                break;
            };
            bucket_layout.apply_commit(commit);
        }
        assert!(
            bucket_layout.prio_bit_size() + 1 < STD_ID_LENGTH,
            "Failed to find message id configuration"
        );
        let minimized_sets = set.to_minimized_sets(&bucket_layout);
        return MinimizedNetwork {
            sets: minimized_sets,
            bucket_layout,
        };
    }
    if LOGGING {
        println!("receive set count: {}", network_info.receive_sets().len());
    }

    let mut bucket_layout = BucketLayout::new();

    let mut it = 0;
    loop {
        if LOGGING {
            println!("\nBegin Iteration {it}");
        }
        it += 1;

        if LOGGING {
            println!("Bucket Stats:");
            println!("-realtime    : {}", bucket_layout.bucket_size(0));
            println!("-high        : {}", bucket_layout.bucket_size(1));
            println!("-normal      : {}", bucket_layout.bucket_size(2));
            println!("-low         : {}", bucket_layout.bucket_size(3));
            println!("-super-low   : {}", bucket_layout.bucket_size(4));
        }

        let reducable_node = network_info
            .node_receive_sets()
            .iter()
            .max_by_key(|node_rx_set| node_rx_set.receive_set_count(&bucket_layout))
            .expect("It was asserted that there exist at least one node receiver set");

        let set_count: usize = network_info
            .receive_sets()
            .iter()
            .map(|rx_set| rx_set.set_count(&bucket_layout))
            .sum();

        for rx_set in network_info.receive_sets() {
            if LOGGING {
                println!("RxSet {:?}:", rx_set.identifier());
                println!("-set-count : {}", rx_set.set_count(&bucket_layout));
                println!(
                    "-realtime  : {} -> {}",
                    rx_set.priorioty_bucket(0).message_count(),
                    rx_set
                        .priorioty_bucket(0)
                        .required_sets(bucket_layout.bucket_size(0))
                );
                println!(
                    "--required-inc = {}",
                    rx_set
                        .priorioty_bucket(0)
                        .required_inc_for_merge(bucket_layout.bucket_size(0))
                        .unwrap_or_default()
                );
                println!(
                    "-high      : {} -> {}",
                    rx_set.priorioty_bucket(1).message_count(),
                    rx_set
                        .priorioty_bucket(1)
                        .required_sets(bucket_layout.bucket_size(1))
                );
                println!(
                    "--required-inc = {}",
                    rx_set
                        .priorioty_bucket(1)
                        .required_inc_for_merge(bucket_layout.bucket_size(1))
                        .unwrap_or_default()
                );
                println!(
                    "-normal    : {} -> {}",
                    rx_set.priorioty_bucket(2).message_count(),
                    rx_set
                        .priorioty_bucket(2)
                        .required_sets(bucket_layout.bucket_size(2))
                );
                println!(
                    "--required-inc = {}",
                    rx_set
                        .priorioty_bucket(2)
                        .required_inc_for_merge(bucket_layout.bucket_size(2))
                        .unwrap_or_default()
                );
                println!(
                    "-low       : {} -> {}",
                    rx_set.priorioty_bucket(3).message_count(),
                    rx_set
                        .priorioty_bucket(3)
                        .required_sets(bucket_layout.bucket_size(3))
                );
                println!(
                    "--required-inc = {}",
                    rx_set
                        .priorioty_bucket(3)
                        .required_inc_for_merge(bucket_layout.bucket_size(3))
                        .unwrap_or_default()
                );
                println!(
                    "-superlow  : {} -> {}",
                    rx_set.priorioty_bucket(4).message_count(),
                    rx_set
                        .priorioty_bucket(4)
                        .required_sets(bucket_layout.bucket_size(4))
                );
                println!(
                    "--required-inc = {}",
                    rx_set
                        .priorioty_bucket(4)
                        .required_inc_for_merge(bucket_layout.bucket_size(4))
                        .unwrap_or_default()
                );
            }
        }

        assert!(set_count != 0, "required for usize::ilog2");
        let setcode_len = (set_count as f64).log2().ceil() as u32;
        let prio_len = bucket_layout.prio_bit_size();
        let id_len = setcode_len + prio_len;
        let max_filters = reducable_node.receive_set_count(&bucket_layout);

        if LOGGING {
            println!("Result:");
            println!("-set-count   : {set_count}");
            println!("-setcode_len : {setcode_len}");
            println!("-prio_len    : {prio_len}");
            println!("-unused-bits : {}", 11 as i32 - id_len as i32);
            println!("-max_filters : {max_filters}");
        }

        if id_len <= STD_ID_LENGTH && max_filters <= MAX_FILTERS_PER_NODE {
            break;
        }

        let best_commit = reducable_node
            .receive_sets()
            .iter()
            .map(|rx_set| rx_set.min_commit_to_merge(&bucket_layout))
            .flatten()
            .min_by_key(|commit| commit.count());
        match best_commit {
            Some(best_commit) => {
                if LOGGING {
                    println!("APPLY_COMMIT:");
                    println!("-realtime-inc : {}", best_commit.inc()[0]);
                    println!("-high-inc     : {}", best_commit.inc()[1]);
                    println!("-normal-inc   : {}", best_commit.inc()[2]);
                    println!("-low-inc      : {}", best_commit.inc()[3]);
                    println!("-superlow-inc : {}", best_commit.inc()[4]);
                }
                bucket_layout.apply_commit(best_commit)
            }
            None => {
                println!("WARNING : exit without finding valid id assignment");
                break;
            }
        }
    }

    let total_set_count: usize = network_info
        .receive_sets()
        .iter()
        .map(|rx_set| rx_set.set_count(&bucket_layout))
        .sum();
    let setcode_len = (total_set_count as f64).log2().ceil() as u32;
    if LOGGING {
        println!("");
        println!("Bucket Stats:");
        println!("-realtime    : {}", bucket_layout.bucket_size(0));
        println!("-high        : {}", bucket_layout.bucket_size(1));
        println!("-normal      : {}", bucket_layout.bucket_size(2));
        println!("-low         : {}", bucket_layout.bucket_size(3));
        println!("-super-low   : {}", bucket_layout.bucket_size(4));
    }

    let total_priority_count = bucket_layout.total_bucket_size();
    let total_priority_bits = (total_priority_count as f64).log2().ceil() as u32;
    let reducable_node = network_info
        .node_receive_sets()
        .iter()
        .max_by_key(|node_rx_set| node_rx_set.receive_set_count(&bucket_layout))
        .expect("It was asserted that there exist at least one node receiver set");
    let max_filters = reducable_node.receive_set_count(&bucket_layout);
    if LOGGING {
        println!("Combined bucket count : {total_priority_count}");
        println!("Priority bit count    : {total_priority_bits}");
        println!("Total setcount : {total_set_count}");
        println!("setcode-len    : {setcode_len}");
        println!("Max filters: {max_filters}");
        println!("");
    }

    let minimized_sets: Vec<MinimizedSet> = network_info
        .receive_sets()
        .iter()
        .map(|rx_set| rx_set.to_minimized_sets(&bucket_layout))
        .flatten()
        .collect();

    MinimizedNetwork::new(minimized_sets, bucket_layout)
}
