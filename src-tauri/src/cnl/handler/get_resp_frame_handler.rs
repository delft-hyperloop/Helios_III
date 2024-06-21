use std::{collections::HashMap, sync::Arc, time::Duration};

use bitvec::view::AsBits;
use canzero_config::config;

use crate::cnl::{
    deserialize::{type_deserializer::TypeDeserializer, FrameDeserializer},
    errors::{Error, Result},
    frame::{Frame, TFrame, Value},
    network::{object_entry_object::ObjectEntryObject, NetworkObject},
};

use canzero_common::TCanFrame;

const UNSOLICITED_ID: u8 = 0xff;

struct GetRespFrame {
    sof: bool,
    eof: bool,
    toggle: bool,
    server_id: u8,
    client_id: u8,
    object_entry_id: u16,
    data: u32,
}

impl GetRespFrame {
    pub fn new(frame: &Frame) -> Self {
        let Some(header) = frame.attribute("header") else {
            panic!("DETECTED INVALID CONFIG: invalid format of get_resp_frame : header missing");
        };
        let Some(Value::UnsignedValue(sof)) = header.attribute("sof") else {
            panic!(
                "DETECTED INVALID CONFIG: invalid format of get_resp_frame : header.sof missing"
            );
        };
        let Some(Value::UnsignedValue(eof)) = header.attribute("eof") else {
            panic!(
                "DETECTED INVALID CONFIG: invalid format of get_resp_frame : header.eof missing"
            );
        };
        let Some(Value::UnsignedValue(toggle)) = header.attribute("toggle") else {
            panic!(
                "DETECTED INVALID CONFIG: invalid format of get_resp_frame : header.toggle missing"
            );
        };
        let Some(Value::UnsignedValue(object_entry_id)) = header.attribute("od_index") else {
            panic!("DETECTED INVALID CONFIG: invalid format of get_resp_frame : header.od_index missing");
        };
        let Some(Value::UnsignedValue(server_id)) = header.attribute("server_id") else {
            panic!("DETECTED INVALID CONFIG: invalid format of get_resp_frame : header.server_id missing");
        };
        let Some(Value::UnsignedValue(client_id)) = header.attribute("client_id") else {
            panic!("DETECTED INVALID CONFIG: invalid format of get_resp_frame : header.client_id missing");
        };
        let Some(Value::UnsignedValue(data)) = frame.attribute("data") else {
            panic!(
                "DETECTED INVALID CONFIG: invalid format of get_resp_frame : header.data missing"
            );
        };
        Self {
            sof: *sof != 0,
            eof: *eof != 0,
            toggle: *toggle != 0,
            server_id: *server_id as u8,
            client_id: *client_id as u8,
            object_entry_id: *object_entry_id as u16,
            data: *data as u32,
        }
    }
}

// expecting toggle low on first frame
struct GetRespState {
    fragmentation_offset: usize,
    single_lookahead: bool,
}

struct GetResp {
    state: GetRespState,
    object_entry: Arc<ObjectEntryObject>,
    type_deserializer: TypeDeserializer,
    size: u32,
    buffer: Vec<u32>,
}

impl GetResp {
    async fn receive(&mut self, frame: GetRespFrame, timestamp: &Duration, unsolicited: bool) -> Result<()> {
        assert_eq!(frame.object_entry_id, self.object_entry.id() as u16);

        if frame.sof {
            let (expected_toggle, expected_eof) = (false, self.size.div_ceil(32) == 1);
            if expected_toggle != frame.toggle {
                return Err(Error::InvalidGetResponseToggleFlag);
            }
            if expected_eof != frame.eof {
                return Err(Error::InvalidGetResponseEofFlag);
            }
            self.state.fragmentation_offset = 0;
            self.buffer[self.state.fragmentation_offset] = frame.data;
            match self.state.single_lookahead {
                true => {
                    self.state.fragmentation_offset += 2;
                    self.state.single_lookahead = false;
                }
                false => self.state.fragmentation_offset += 1,
            }
        } else {
            let expected_toggle = self.state.fragmentation_offset % 2 == 1;
            let expected_eof =
                self.state.fragmentation_offset + 1 == self.size.div_ceil(32) as usize;
            if expected_toggle == frame.toggle
                && expected_eof == frame.eof
                && self.state.fragmentation_offset != 0
            {
                // everything as expected
                self.buffer[self.state.fragmentation_offset] = frame.data;
                match self.state.single_lookahead {
                    true => {
                        self.state.fragmentation_offset += 2;
                        self.state.single_lookahead = false;
                    }
                    false => self.state.fragmentation_offset += 1,
                }
            } else if !self.state.single_lookahead
                && self.state.fragmentation_offset + 1 < self.size.div_ceil(32) as usize
            {
                let accepted_toggle = !expected_toggle;
                let accepted_eof =
                    self.state.fragmentation_offset + 2 == self.size.div_ceil(32) as usize;
                if accepted_toggle == frame.toggle && accepted_eof == frame.eof {
                    // assume that this frame arrived before previous one
                    self.buffer[self.state.fragmentation_offset + 1] = frame.data;
                    self.state.single_lookahead = true;
                }
            } else {
                // TODO: actually split this up for correct error
                return Err(Error::InvalidGetResponseToggleFlag);
            }
        }

        if self.state.fragmentation_offset >= self.size.div_ceil(32) as usize {
            let value = self
                .type_deserializer
                .deserialize(&self.buffer.as_slice().as_bits());
            if unsolicited {
                self.object_entry.push_get_response_unsolicited(value, timestamp).await;
            } else {
                self.object_entry.push_get_response(value, timestamp).await;
            }
            self.state.fragmentation_offset = 0;
            self.state.single_lookahead = false;
            self.buffer.fill(0);
        }
        Ok(())
    }
}

#[derive(PartialEq, Eq, Hash)]
struct GetRespIdentifier {
    server_id: u8,
    object_entry_id: u16,
    unsolicited: bool
}

pub struct GetRespFrameHandler {
    frame_deserializer: FrameDeserializer,
    get_resp_lookup: HashMap<GetRespIdentifier, tokio::sync::Mutex<GetResp>>,
    node_id: u8,
}

impl GetRespFrameHandler {
    pub fn create(
        network: &Arc<NetworkObject>,
        get_resp_msg: &config::MessageRef,
        node_id: u8,
    ) -> Self {
        let mut get_resp_lookup = HashMap::new();
        for node in network.nodes() {
            let node_id = node.id() as u8;
            for object_entry in node.object_entries() {
                get_resp_lookup.insert(
                    GetRespIdentifier {
                        server_id: node_id,
                        object_entry_id: object_entry.id() as u16,
                        unsolicited: false,
                    },
                    tokio::sync::Mutex::new(GetResp {
                        object_entry: object_entry.clone(),
                        buffer: vec![0; object_entry.ty().size().div_ceil(32) as usize],
                        state: GetRespState { fragmentation_offset: 0, single_lookahead: false },
                        size: object_entry.ty().size(),
                        type_deserializer: TypeDeserializer::new(object_entry.ty()),
                    }),
                );
                get_resp_lookup.insert(
                    GetRespIdentifier {
                        server_id: node_id,
                        object_entry_id: object_entry.id() as u16,
                        unsolicited: true,
                    },
                    tokio::sync::Mutex::new(GetResp {
                        object_entry: object_entry.clone(),
                        buffer: vec![0; object_entry.ty().size().div_ceil(32) as usize],
                        state: GetRespState { fragmentation_offset: 0, single_lookahead: false },
                        size: object_entry.ty().size(),
                        type_deserializer: TypeDeserializer::new(object_entry.ty()),
                    }),
                );
            }
        }
        Self {
            frame_deserializer: FrameDeserializer::new(get_resp_msg),
            get_resp_lookup,
            node_id,
        }
    }

    pub async fn handle(&self, can_frame: &TCanFrame) -> Result<TFrame> {
        let frame = self
            .frame_deserializer
            .deserialize(can_frame.get_data_u64());

        let get_resp_frame = GetRespFrame::new(&frame);

        if get_resp_frame.client_id != self.node_id && get_resp_frame.client_id != UNSOLICITED_ID {
            return Ok(can_frame.new_value(frame));
        }
        let get_resp_identifier = GetRespIdentifier {
            server_id: get_resp_frame.server_id,
            object_entry_id: get_resp_frame.object_entry_id,
            unsolicited: get_resp_frame.client_id == UNSOLICITED_ID,
        };

        // lookup the correct GetResp "similar to handlers"
        let Some(get_resp) = self.get_resp_lookup.get(&get_resp_identifier) else {
            return Err(Error::InvalidGetResponseServerOrObjectEntryNotFound);
        };

        get_resp
            .lock()
            .await
            .receive(get_resp_frame, &can_frame.timestamp, get_resp_identifier.unsolicited)
            .await?;

        Ok(can_frame.new_value(frame))
    }
}
