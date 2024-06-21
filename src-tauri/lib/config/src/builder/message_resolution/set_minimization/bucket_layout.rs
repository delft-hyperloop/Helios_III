use crate::builder::MessagePriority;

pub struct BucketLayout {
    bucket_sizes: [usize; MessagePriority::count()],
}

impl BucketLayout {
    pub fn new() -> Self {
        Self {
            bucket_sizes: [1usize; MessagePriority::count()],
        }
    }
    pub fn apply_commit(&mut self, commit : BucketLayoutCommit) {
        for prio in 0..MessagePriority::count() {
            self.bucket_sizes[prio] += commit.inc[prio];
        }
    }

    pub fn bucket_size(&self, priority: usize) -> usize {
        self.bucket_sizes[priority]
    }
    pub fn total_bucket_size(&self) -> usize {
        self.bucket_sizes.iter().sum()
    }

    pub fn prio_bit_size(&self) -> u32 {
        let bucket_sum : usize = self.bucket_sizes.iter().sum();
        (bucket_sum as f64).log2().ceil() as u32
    }
}

pub struct BucketLayoutCommit {
    inc : [usize;MessagePriority::count()],
    count : usize,
}

impl BucketLayoutCommit{
    pub fn new(inc : [usize;MessagePriority::count()]) -> Self{
        let count : usize = inc.iter().sum();
        Self {
            inc,
            count,
        }
    }
    pub fn inc(&self) -> [usize;MessagePriority::count()] {
        self.inc
    }
    pub fn count(&self) -> usize {
        self.count
    }
}
