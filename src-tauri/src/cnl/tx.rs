use std::{
    sync::Arc,
    time::{Duration, Instant},
};

use canzero_config::config::{self, MessageRef};
use color_print::cprintln;
use tokio::time;

use crate::cnl::connection::ConnectionStatus;

use super::{
    connection::ConnectionObject, deserialize::FrameDeserializer, frame::Frame, trace::TraceObject,
    CanAdapter,
};

use canzero_common::CanFrame;

pub struct TxCom {
    network_ref: config::NetworkRef,
    set_req_can_adapter: Arc<CanAdapter>,
    get_req_frame_deserializer: FrameDeserializer,
    get_req_can_adapter: Arc<CanAdapter>,
    can_adapters: Vec<Arc<CanAdapter>>,
    my_node_id: u8,
    frag_time_ms: u64,
    timebase: Instant,
    trace: Arc<TraceObject>,
    connection_object: Arc<ConnectionObject>,
}

impl TxCom {
    pub fn create(
        network_ref: &config::NetworkRef,
        can_adapters: &Vec<Arc<CanAdapter>>,
        trace: &Arc<TraceObject>,
        basetime: Instant,
        connection_object: &Arc<ConnectionObject>,
        node_id: u8,
    ) -> TxCom {
        let set_req_can_adapter = can_adapters
            .iter()
            .find(|adapter| adapter.bus().id() == network_ref.set_req_message().bus().id())
            .expect("DETECTED INVALID CONFIG: no set_req message in the config")
            .clone();

        let get_req_can_adapter = can_adapters
            .iter()
            .find(|adapter| adapter.bus().id() == network_ref.get_req_message().bus().id())
            .expect("DETECTED INVALID CONFIG: no get_req message in the config")
            .clone();

        TxCom {
            network_ref: network_ref.clone(),
            my_node_id: node_id,
            set_req_can_adapter,
            get_req_frame_deserializer: FrameDeserializer::new(network_ref.get_req_message()),
            get_req_can_adapter,
            can_adapters : can_adapters.to_owned(),
            frag_time_ms: 200,
            timebase: basetime,
            trace: trace.clone(),
            connection_object: connection_object.clone(),
        }
    }

    pub async fn send_set_request(&self, server_id: u8, oe_id: u32, val: Vec<u32>, last_fill: u8) {
        let (set_request_id, ide) = match self.network_ref.set_req_message().id() {
            config::MessageId::StandardId(id) => (*id, false),
            config::MessageId::ExtendedId(id) => (*id, true),
        };
        let mut frame_data: Vec<CanFrame> = vec![];
        let frames_to_send = val.len();

        for i in 0..frames_to_send {
            // SOF
            let mut data_curr = if i == 0 { 1u64 } else { 0u64 };
            // EOF
            data_curr |= if i == frames_to_send - 1 {
                1u64 << 1
            } else {
                0u64
            };
            // toggle
            data_curr |= ((i % 2) as u64) << 2;
            // oe-id
            data_curr |= (oe_id as u64) << 3;
            // client-id
            data_curr |= (self.my_node_id as u64) << 16;
            // server-id
            data_curr |= (server_id as u64) << 24;
            // data
            data_curr |= (val[i] as u64) << 32;

            let dlc = if i == (frames_to_send - 1) {
                4 + last_fill
            } else {
                8
            };
            frame_data.push(CanFrame::new(set_request_id, ide, false, dlc, data_curr));
        }

        fragmented_can_send(
            frame_data,
            self.set_req_can_adapter.clone(),
            self.frag_time_ms,
            self.connection_object.clone(),
        )
        .await;
    }

    pub async fn send_native(&self, msg : &MessageRef, data : u64) {
        let adapter = self.can_adapters.iter().find(|adap| adap.bus().id() == msg.bus().id()).unwrap();
        let _ = adapter.send(CanFrame::new(msg.id().as_u32(), msg.id().ide(), false, msg.dlc(), data), true).await;
    }

    pub async fn send_get_req(&self, server_id: u8, object_entry_id: u16) {
        let mut data: u64 = 0;
        data |= object_entry_id as u64;
        data |= (self.network_ref.nodes().len() as u64) << 13;
        data |= (server_id as u64) << 21;

        let get_req_frame = CanFrame::new(
            self.network_ref.get_req_message().id().as_u32(),
            self.network_ref.get_req_message().id().ide(),
            false,
            self.network_ref.get_req_message().dlc(),
            data,
        );

        if let Err(err) = self.get_req_can_adapter.send(get_req_frame, true).await {
            println!("<red>Failed to send get req </red>: {err:?}");
            self.connection_object
                .set_status(ConnectionStatus::NetworkDisconnected);
        }
    }

    pub async fn send_heartbeat(&self, ticks_next: u8, unregister: bool) {
        let mut msg_data = self.my_node_id as u64;
        if ticks_next >> 7 != 0 {
            panic!("Invalid ticks_next value for heartbeat");
        }
        msg_data |= (ticks_next as u64) << 9;
        if unregister {
            msg_data |= 1 << 8;
        }

        for can_adapter in self.can_adapters.iter() {
            let msg = self
                .network_ref
                .heartbeat_messages()
                .iter()
                .find(|&m| m.bus().id() == can_adapter.bus().id())
                .expect(&format!(
                    "Invalid network object! No heartbeat for {}",
                    can_adapter.bus().name()
                ));

            let heartbeat_frame =
                CanFrame::new(msg.id().as_u32(), msg.id().ide(), false, 2, msg_data);

            if let Err(err) = can_adapter.send(heartbeat_frame, true).await {
                println!("<red>Failed to send heartbeat </red>: {err:?}");
                self.connection_object
                    .set_status(ConnectionStatus::NetworkDisconnected);
            }
        }
    }
}

async fn fragmented_can_send(
    frames: Vec<CanFrame>,
    can_adapter: Arc<CanAdapter>,
    frag_time_ms: u64,
    connection_object : Arc<ConnectionObject>,
) {
    let mut interval = time::interval(Duration::from_millis(frag_time_ms));

    for frame in frames {
        // first tick completes instantaniously
        interval.tick().await;

        if let Err(err) = can_adapter.send(frame, true).await {
            cprintln!("<red>Failed to send set req </red>: {err:?}");
            connection_object.set_status(ConnectionStatus::NetworkDisconnected);
        }
    }
}
