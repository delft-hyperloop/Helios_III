use defmt::warn;
use embassy_sync::channel::TrySendError;
use embassy_time::Timer;

use crate::core::communication::data::Datapoint;
use crate::DataReceiver;
use crate::DataSender;
use crate::Datatype;

const DISCARD_NUMBER: usize = 10;

#[embassy_executor::task(pool_size = 2)]
pub async fn overflow(data_sender: DataSender, data_receiver: DataReceiver) {
    loop {
        match data_sender.try_send(Datapoint::new(Datatype::OverflowUnit, 0, 0)) {
            Ok(_) => {
                Timer::after_secs(3).await;
            },
            Err(TrySendError::Full(_)) => {
                for _ in 0..DISCARD_NUMBER {
                    match data_receiver.try_receive() {
                        Ok(x) => {
                            warn!("data channel full, discarding {:?}", x);
                        },
                        Err(_) => {
                            Timer::after_secs(5).await;
                        },
                    }
                }
            },
        }
    }
}
