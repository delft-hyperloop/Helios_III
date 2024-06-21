use crate::config::{ObjectEntryAccess, Visibility};

use super::{make_builder_ref, BuilderRef};


#[derive(Debug, Clone)]
pub struct ObjectEntryBuilder(pub BuilderRef<ObjectEntryData>);
#[derive(Debug)]
pub struct ObjectEntryData {
    pub name: String,
    pub description: Option<String>,
    pub friend : Option<String>,
    pub unit: Option<String>,
    pub ty: String,
    pub access: ObjectEntryAccess,
    pub visibility: Visibility,
}


impl ObjectEntryBuilder {
    pub fn new(name: &str, ty: &str, node_name : &str) -> ObjectEntryBuilder {
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Create ObjectEntry {node_name}::{name} : {ty}");
        ObjectEntryBuilder(make_builder_ref(ObjectEntryData {
            name: name.to_owned(),
            ty: ty.to_owned(),
            description: None,
            friend:  None,
            unit: None,
            access: ObjectEntryAccess::Global,
            visibility: Visibility::Global,
        }))
    }
    pub fn hide(&self) {
        let mut data = self.0.borrow_mut();
        data.visibility = Visibility::Static;
    }
    pub fn friend(&self, friend : &str) {
        self.0.borrow_mut().friend = Some(friend.to_owned());
    }
    pub fn add_description(&self, description: &str) {
        let mut data = self.0.borrow_mut();
        data.description = Some(description.to_owned());
    }
    pub fn set_access(&self, access: ObjectEntryAccess) {
        let mut data = self.0.borrow_mut();
        data.access = access;
    }
    pub fn add_unit(&self, unit: &str) {
        let mut data = self.0.borrow_mut();
        data.unit = Some(unit.to_owned());
    }
}

