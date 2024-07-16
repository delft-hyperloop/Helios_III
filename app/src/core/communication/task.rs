use crate::core::communication::comm::ExternalCommunicationHandler;
use crate::core::communication::CommunicationLayer;

#[embassy_executor::task]
pub async fn external_communication_task(mut comm: impl CommunicationLayer + 'static) -> ! {
    comm.init().await;

    'netstack: loop {
        match comm.connect().await {
            Ok(_) => {}
            Err(_) => continue 'netstack
        };
        comm.handshake().await;

        'connection: loop {
            if !comm.try_send_data() || !comm.try_receive_data().await {
                break 'connection;
            }
        }
    }
}
