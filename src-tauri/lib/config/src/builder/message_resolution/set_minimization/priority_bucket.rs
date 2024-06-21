use crate::builder::MessageBuilder;

use super::bucket_layout::BucketLayout;

pub struct PriorityBucket {
    messages: Vec<MessageBuilder>,
}

impl PriorityBucket {
    pub fn new() -> Self {
        Self { messages: vec![] }
    }
    pub fn insert_message(&mut self, message: &MessageBuilder) {
        self.messages.push(message.clone());
    }
    pub fn message_count(&self) -> usize {
        self.messages.len()
    }
    pub fn required_sets(&self, bucket_size: usize) -> usize {
        self.message_count().div_ceil(bucket_size)
    }
    pub fn required_inc_for_merge(&self, bucket_size: usize) -> Option<usize> {
        if bucket_size >= self.message_count() {
            None
        } else {
            let rest = self.message_count() % bucket_size;
            if rest == 0 {
                Some(bucket_size.div_ceil(self.message_count() / bucket_size - 1))
            } else {
                Some(rest.div_ceil(self.message_count() / bucket_size))
            }
        }
    }
    pub fn messages(&self) -> &Vec<MessageBuilder> {
        &self.messages
    }
}
