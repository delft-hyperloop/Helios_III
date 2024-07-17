// use embassy_sync::blocking_mutex::raw::NoopRawMutex;
// use embassy_sync::channel::Channel;
// use crate::{DATA_QUEUE_SIZE, DataReceiver, DataSender};
// use crate::core::communication::data::Datapoint;
//
//
// #[embassy_executor::task]
// pub async fn overflow(dq: &'static mut Channel<NoopRawMutex, Datapoint, DATA_QUEUE_SIZE>, pdq: &'static mut Channel<NoopRawMutex, Datapoint, DATA_QUEUE_SIZE>) {
//     loop {
//         if dq.is_full() {
//
//         }
//     }
// }
//
// trait EmptyAble {
//     fn remove_last(&mut self);
// }