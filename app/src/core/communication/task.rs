use crate::core::communication::comm::ExternalCommunicationHandler;
use crate::core::communication::CommunicationLayer;

#[embassy_executor::task]
async fn external_communication_task(comm: impl CommunicationLayer) -> ! {

}