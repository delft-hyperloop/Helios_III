
use crate::builder::message_resolution::{receive_set::ReceiverSetRef, set_minimization::bucket_layout::BucketLayout};


pub struct NodeReceiveSet {
    node_name : String,
    receiver_sets : Vec<ReceiverSetRef>
}

impl NodeReceiveSet {
    pub fn new(node_name : String, receiver_sets : Vec<ReceiverSetRef>) -> Self{
        Self {
            node_name,
            receiver_sets,
        }
    }
    pub fn node_name(&self) -> &str {
        &self.node_name
    }
    pub fn receive_sets(&self) -> &Vec<ReceiverSetRef> {
        &self.receiver_sets
    }
    pub fn receive_set_count(&self, bucket_layout : &BucketLayout) -> usize {
        self.receiver_sets.iter().map(|rx_set| rx_set.set_count(bucket_layout)).sum()
    }
}
