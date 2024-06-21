
use canzero_config::config::MessageRef;
use canzero_common::TCanFrame;

use crate::cnl::frame::TFrame;
use crate::cnl::deserialize::FrameDeserializer;
use crate::cnl::errors::Result;


pub struct SetReqFrameHandler {
    frame_deserializer: FrameDeserializer,
}

impl SetReqFrameHandler {
    pub fn create(
        set_req_message : &MessageRef,
    ) -> Self {
        Self {
            frame_deserializer: FrameDeserializer::new(set_req_message),
        }
    }
    pub async fn handle(&self, can_frame: &TCanFrame) -> Result<TFrame> {
        let frame = self
            .frame_deserializer
            .deserialize(can_frame.get_data_u64());
        Ok(can_frame.new_value(frame))
    }
}
