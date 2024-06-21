use crate::builder::NodeBuilder;

use super::assign_messages::NodeFilterInfo;

pub struct NodeFilterBank {
    filters: Vec<Filter>,
    node: NodeBuilder,
}

impl NodeFilterBank {
    pub fn node(&self) -> &NodeBuilder {
        &self.node
    }
    pub fn filters(&self) -> &Vec<Filter> {
        &self.filters
    }
}

pub struct Filter {
    mask: u32,
    id: u32,
}
impl Filter {
    pub fn mask(&self) -> u32 {
        self.mask
    }
    pub fn id(&self) -> u32 {
        self.id
    }
}

pub fn find_filter_configuration(filter_infos: Vec<NodeFilterInfo>) -> Vec<NodeFilterBank> {
    filter_infos
        .iter()
        .map(|node_filter_info| NodeFilterBank {
            filters: node_filter_info.filter_infos().iter().map(|filter| -> Filter{
                match filter {
                    super::assign_messages::FilterInfo::Setcode { setcode, setcode_len, ide : _ } => Filter {
                        mask : u32::MAX >> (32 - *setcode_len),
                        id : *setcode
                    },
                    super::assign_messages::FilterInfo::Single { id, ide : _ } => {
                        Filter {
                            mask : 0xFFFFFFFFu32,
                            id : *id,
                        }
                    }
                }
            }).collect(),
            node: node_filter_info.node().clone(),
        })
        .collect()
}
