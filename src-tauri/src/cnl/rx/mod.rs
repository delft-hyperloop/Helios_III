use std::sync::Arc;

use canzero_config::config::NetworkRef;

use self::can_receiver::CanReceiver;

use super::{can_adapter::CanAdapter, connection::ConnectionObject, network::NetworkObject, trace::TraceObject};

mod can_receiver;
mod handler_lookup;

pub struct RxCom {

    // NOTE this is only is the spirit of RAII
    // to hold them somewhere and hopyfully make the 
    // code a bit easier to read doesn't actually do 
    // anything! because CanReceiver is a zero sized struct
    #[allow(dead_code)]
    can_receivers: Vec<CanReceiver>,
}

impl RxCom {
    pub fn create(
        network_config: &NetworkRef,
        trace: &Arc<TraceObject>,
        network_object: &Arc<NetworkObject>,
        app_handle: &tauri::AppHandle,
        can_adapters: &Vec<Arc<CanAdapter>>,
        connection_object : &Arc<ConnectionObject>,
        node_id : u8,
    ) -> Self {
        Self {
            can_receivers: can_adapters
                .iter()
                .map(|can_adapter| {
                    CanReceiver::create(
                        can_adapter,
                        network_config.messages(),
                        trace,
                        network_object,
                        app_handle,
                        connection_object.clone(),
                        node_id,
                    )
                })
                .collect(),
        }
    }
}
