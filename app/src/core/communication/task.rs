use core::sync::atomic::Ordering;
use defmt::error;
use embassy_time::Timer;
use crate::CONNECTED;

use crate::core::communication::CommunicationLayer;

#[embassy_executor::task]
pub async fn external_communication_task(mut comm: impl CommunicationLayer + 'static) -> ! {
    comm.init().await;

    'netstack: loop {
        match comm.connect().await {
            Ok(_) => unsafe { CONNECTED.store(true, Ordering::SeqCst) },
            Err(_) => continue 'netstack,
        };
        comm.handshake().await;

        'connection: loop {
            if !comm.try_send_data().await {
                error!("[connection] could not send data");
                break 'connection;
            }
            if !comm.try_receive_data().await {
                error!("[connection] could not receive data");
                break 'connection;
            }
            Timer::after_millis(1).await;
        }
        unsafe { CONNECTED.store(false, Ordering::SeqCst) }
        comm.disconnect().await;
    }
}
