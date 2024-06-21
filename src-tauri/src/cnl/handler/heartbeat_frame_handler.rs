use std::sync::Arc;

use canzero_common::TCanFrame;
use canzero_config::config::MessageRef;

use crate::cnl::deserialize::FrameDeserializer;
use crate::cnl::errors::Result;
use crate::cnl::frame::{Frame, TFrame, Value};
use crate::cnl::network::node_object::NodeObject;

pub struct HeartbeatFrameHandler {
    frame_deserializer: FrameDeserializer,
    node_objects: Vec<Arc<NodeObject>>,
    bus_id: u32,
}

struct HeartbeatFrame {
    node_id: u8,
    unregister: bool,
    ticks_next: u8,
}

impl HeartbeatFrame {
    fn create(frame: &Frame) -> Self {
        let Some(Value::UnsignedValue(node_id)) = frame.attribute("node_id") else {
            panic!("DETECTED INVALID CONFIG: invalid format of heartbeat : node_id missing");
        };
        let Some(Value::UnsignedValue(unregister)) = frame.attribute("unregister") else {
            panic!("DETECTED INVALID CONFIG: invalid format of heartbeat : unregister missing");
        };
        let Some(Value::UnsignedValue(ticks_next)) = frame.attribute("ticks_next") else {
            panic!("DETECTED INVALID CONFIG: invalid format of heartbeat : ticks_next missing");
        };
        HeartbeatFrame {
            node_id: *node_id as u8,
            unregister: match unregister {
                0 => false,
                _ => true,
            },
            ticks_next: *ticks_next as u8,
        }
    }
}

impl HeartbeatFrameHandler {
    pub fn create(heartbeat_message: &MessageRef, node_objects: &Vec<Arc<NodeObject>>) -> Self {
        Self {
            frame_deserializer: FrameDeserializer::new(heartbeat_message),
            node_objects: node_objects.clone(),
            bus_id: heartbeat_message.bus().id(),
        }
    }
    pub async fn handle(&self, can_frame: &TCanFrame) -> Result<TFrame> {
        let frame = self
            .frame_deserializer
            .deserialize(can_frame.get_data_u64());
        let heartbeat_frame = HeartbeatFrame::create(&frame);
        let Some(node_object) = self
            .node_objects
            .iter()
            .find(|n| n.id() == heartbeat_frame.node_id)
        else {
            return Ok(can_frame.new_value(frame));
        };
        node_object
            .reset_heartbeat_wdg(
                self.bus_id,
                heartbeat_frame.unregister,
                heartbeat_frame.ticks_next,
            )
            .await;
        Ok(can_frame.new_value(frame))
    }
}
