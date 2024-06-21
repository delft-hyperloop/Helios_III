use std::{hash::Hash, sync::OnceLock};

use super::{ConfigRef, NodeRef, TypeRef, Visibility};

pub type ObjectEntryRef = ConfigRef<ObjectEntry>;

#[derive(Debug, Clone)]
pub enum ObjectEntryAccess {
    Const,  // no write
    Local,  // local write public read
    Global, // public write
}

impl Hash for ObjectEntryAccess {
    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        match &self {
            ObjectEntryAccess::Const => state.write_u8(0),
            ObjectEntryAccess::Local => state.write_u8(1),
            ObjectEntryAccess::Global => state.write_u8(2),
        }
    }
}

#[derive(Debug)]
pub struct ObjectEntry {
    name: String,
    description: Option<String>,
    friend: Option<String>,
    unit: Option<String>,
    id: u32,
    ty: TypeRef,
    access: ObjectEntryAccess,
    visibility: Visibility,
    node: OnceLock<NodeRef>,
}

impl Hash for ObjectEntry {
    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        for b in self.name.bytes() {
            state.write_u8(b);
        }
        match &self.unit {
            Some(unit) => {
                state.write_u8(1);
                for b in unit.bytes() {
                    state.write_u8(b);
                }
            }
            None => state.write_u8(0),
        }
        state.write_u32(self.id);
        self.ty.hash(state);
        self.access.hash(state);
        self.visibility.hash(state);
    }
}

impl ObjectEntry {
    pub fn new(
        name: String,
        description: Option<String>,
        friend: Option<String>,
        unit: Option<String>,
        id: u32,
        ty: TypeRef,
        access: ObjectEntryAccess,
        visibility: Visibility,
    ) -> Self {
        Self {
            name,
            description,
            friend,
            unit,
            id,
            ty,
            access,
            visibility,
            node: OnceLock::new(),
        }
    }
    pub fn id(&self) -> u32 {
        self.id
    }
    pub fn name(&self) -> &str {
        &self.name
    }
    pub fn description(&self) -> Option<&str> {
        match &self.description {
            Some(some) => Some(&some),
            None => None,
        }
    }
    pub fn ty(&self) -> &TypeRef {
        &self.ty
    }
    pub fn access(&self) -> &ObjectEntryAccess {
        &self.access
    }
    pub fn unit(&self) -> Option<&str> {
        match &self.unit {
            Some(unit) => Some(&unit),
            None => None,
        }
    }
    pub fn friend(&self) -> Option<&str> {
        self.friend.as_ref().map(|f| f.as_str())
    }
    pub fn __set_node(&self, node: NodeRef) {
        self.node
            .set(node)
            .expect("can't set the node of a object entry");
    }
    pub fn node(&self) -> &NodeRef {
        self.node.get().unwrap()
    }
}
