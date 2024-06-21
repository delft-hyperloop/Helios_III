use std::{collections::HashMap, sync::Arc};

use canzero_config::config::MessageRef;

use crate::cnl::{
    self,
    deserialize::FrameDeserializer,
    errors::{Error, Result},
    frame::{Frame, TFrame, Value},
    network::{object_entry_object::ObjectEntryObject, NetworkObject},
};

use canzero_common::TCanFrame;

struct SetResponseFrame {
    server_id: u8,
    client_id: u8,
    result: cnl::errors::Result<()>,
    oe_index: u32,
}

impl SetResponseFrame {
    pub fn create(frame: &Frame) -> SetResponseFrame {
        let Some(header) = frame.attribute("header") else {
            panic!("DETECTED INVALID CONFIG: invalid format of set_resp_frame : header missing");
        };
        let Some(Value::UnsignedValue(object_entry_id)) = header.attribute("od_index") else {
            panic!("DETECTED INVALID CONFIG: invalid format of set_resp_frame : header.od_index missing");
        };
        let Some(Value::UnsignedValue(server_id)) = header.attribute("server_id") else {
            panic!("DETECTED INVALID CONFIG: invalid format of set_resp_frame : header.server_id missing");
        };
        let Some(Value::UnsignedValue(client_id)) = header.attribute("client_id") else {
            panic!("DETECTED INVALID CONFIG: invalid format of set_resp_frame : header.client_id missing");
        };
        let Some(Value::EnumValue(erno)) = header.attribute("erno") else {
            panic!(
                "DETECTED INVALID CONFIG: invalid format of set_resp_frame : header.erno missing"
            );
        };
        // TODO: properly use erno
        let result = if erno == "Success" {
            Ok(())
        } else {
            println!("setter returned with an error");
            Ok(())
        };
        Self {
            server_id: *server_id as u8,
            client_id: *client_id as u8,
            oe_index: *object_entry_id as u32,
            result,
        }
    }
}

#[derive(PartialEq, Eq, Hash)]
struct SetResponseIdentifier {
    server_id: u8,
    oe_index: u32,
}

pub struct SetRespFrameHandler {
    frame_deserializer: FrameDeserializer,
    set_resp_lookup: HashMap<SetResponseIdentifier, Arc<ObjectEntryObject>>,
    node_id: u8,
}

impl SetRespFrameHandler {
    pub fn create(
        network_object: &Arc<NetworkObject>,
        set_resp_msg: &MessageRef,
        node_id: u8,
    ) -> Self {
        let mut set_resp_lookup = HashMap::new();
        for node in network_object.nodes() {
            let node_id = node.id() as u8;
            for object_entry in node.object_entries() {
                set_resp_lookup.insert(
                    SetResponseIdentifier {
                        server_id: node_id,
                        oe_index: object_entry.id(),
                    },
                    object_entry.clone(),
                );
            }
        }
        Self {
            frame_deserializer: FrameDeserializer::new(set_resp_msg),
            set_resp_lookup,
            node_id,
        }
    }
    pub async fn handle(&self, can_frame: &TCanFrame) -> Result<TFrame> {
        let frame = self
            .frame_deserializer
            .deserialize(can_frame.get_data_u64());
        let set_resp = SetResponseFrame::create(&frame);

        if set_resp.client_id == self.node_id {
            let set_resp_id = SetResponseIdentifier {
                server_id: set_resp.server_id,
                oe_index: set_resp.oe_index,
            };
            if let Some(oe_object) = self.set_resp_lookup.get(&set_resp_id) {
                oe_object.push_set_response(set_resp.result).await;
            } else {
                return Err(Error::InvalidSetResponseServerOrObjectEntryNotFound);
            };
        }

        Ok(can_frame.new_value(frame))
    }
}
