use std::{collections::HashMap, sync::Arc};

use canzero_config::config::{message, MessageId, MessageRef};

use crate::cnl::{
    handler::{
        get_req_frame_handler::GetReqFrameHandler, get_resp_frame_handler::GetRespFrameHandler,
        heartbeat_frame_handler::HeartbeatFrameHandler, set_req_frame_handler::SetReqFrameHandler,
        set_resp_frame_handler::SetRespFrameHandler, stream_frame_handler::StreamFrameHandler,
        MessageHandler,
    },
    network::NetworkObject,
};

pub struct HandlerLookup(HashMap<u32, MessageHandler>);

impl HandlerLookup {
    pub fn create(
        messages: &Vec<MessageRef>,
        network_object: &Arc<NetworkObject>,
        node_id: u8,
    ) -> Self {
        let map = messages
            .iter()
            .map(|msg| {
                let key = match msg.id() {
                    MessageId::StandardId(id) => *id,
                    MessageId::ExtendedId(id) => *id | 0x80000000, // ide flag
                };
                match msg.usage() {
                    message::MessageUsage::Stream(stream) => Some((
                        key,
                        MessageHandler::StreamFrameHandler(StreamFrameHandler::create(
                            stream,
                            &stream
                                .mapping()
                                .iter()
                                .map(|opt| opt.as_ref().expect("should be set for tx stream"))
                                .map(|oe| {
                                    let node_object = network_object
                                        .nodes()
                                        .iter()
                                        .find(|no| no.name() == oe.node().name())
                                        .expect("invalid node");
                                    node_object
                                        .object_entries()
                                        .iter()
                                        .find(|oeo| oeo.name() == oe.name())
                                        .expect("oe not found")
                                        .clone()
                                })
                                .collect(),
                        )),
                    )),
                    message::MessageUsage::CommandReq(_) => None, //TODO
                    message::MessageUsage::CommandResp(_) => None, //TODO
                    message::MessageUsage::GetResp => Some((
                        key,
                        MessageHandler::GetRespFrameHandler(GetRespFrameHandler::create(
                            network_object,
                            msg,
                            node_id,
                        )),
                    )),
                    message::MessageUsage::GetReq => Some((
                        key,
                        MessageHandler::GetReqFrameHandler(GetReqFrameHandler::create(msg)),
                    )),
                    message::MessageUsage::SetResp => Some((
                        key,
                        MessageHandler::SetRespFrameHandler(SetRespFrameHandler::create(
                            network_object,
                            msg,
                            node_id,
                        )),
                    )),
                    message::MessageUsage::SetReq => Some((
                        key,
                        MessageHandler::SetReqFrameHandler(SetReqFrameHandler::create(msg)),
                    )),
                    message::MessageUsage::Heartbeat => Some((
                        key,
                        MessageHandler::HeartbeatFrameHandler(HeartbeatFrameHandler::create(
                            msg,
                            network_object.nodes(),
                        )),
                    )),
                    message::MessageUsage::External { interval: _ } => None,
                }
            })
            .flatten()
            .collect();

        Self(map)
    }

    pub fn get_handler(&self, key: u32) -> Option<&MessageHandler> {
        self.0.get(&key)
    }
}
