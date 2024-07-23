use core::sync::atomic::Ordering;

use defmt::error;
use defmt::warn;
use embassy_time::Timer;

use crate::core::communication::CommunicationLayer;
use crate::core::fsm_status::CONNECTED;

#[embassy_executor::task]
pub async fn external_communication_task(mut comm: impl CommunicationLayer + 'static) -> ! {
    comm.init().await;

    'netstack: loop {
        match comm.connect().await {
            Ok(_) => CONNECTED.store(true, Ordering::Relaxed),
            Err(_) => continue 'netstack,
        };
        comm.handshake().await;
        warn!("hand shaked");

        'connection: loop {
            if !comm.try_send_data().await {
                error!("[connection] could not send data");
                break 'connection;
            }
            if !comm.try_receive_data().await {
                error!("[connection] could not receive data");
                break 'connection;
            }
            // thread_delay(50).await;
            Timer::after_micros(1).await;
        }
        CONNECTED.store(false, Ordering::Relaxed);
        comm.disconnect().await;
    }
}
