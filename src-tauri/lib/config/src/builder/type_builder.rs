use crate::{config::Visibility, errors};

use super::{make_builder_ref, BuilderRef};



#[derive(Clone, Debug)]
pub struct EnumBuilder(pub BuilderRef<EnumData>);
#[derive(Debug)]
pub struct EnumData {
    pub name: String,
    pub description: Option<String>,
    pub entries: Vec<(String, Option<u64>)>,
    pub visibility: Visibility,
}

#[derive(Debug, Clone)]
pub struct StructBuilder(pub BuilderRef<StructData>);
#[derive(Debug)]
pub struct StructData {
    pub name: String,
    pub description: Option<String>,
    pub attributes: Vec<(String, String)>,
    pub visibility: Visibility,
}

#[derive(Debug, Clone)]
pub enum TypeBuilder {
    Enum(EnumBuilder),
    Struct(StructBuilder),
}

impl EnumBuilder {
    pub fn new(name: &str) -> EnumBuilder {
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Creating enum {name}");
        EnumBuilder(make_builder_ref(EnumData {
            name: name.to_owned(),
            description: None,
            entries: vec![],
            visibility: Visibility::Global,
        }))
    }
    pub fn add_description(&self, description: &str) {
        let mut enum_data = self.0.borrow_mut();
        enum_data.description = Some(description.to_owned());
    }
    pub fn add_entry(&self, name: &str, value: Option<u64>) -> errors::Result<()> {
        let mut enum_data = self.0.borrow_mut();
        if enum_data.entries.iter().any(|a| a.0 == name) {
            return Err(errors::ConfigError::DuplicatedEnumEntry(name.to_owned()));
        }
        enum_data.entries.push((name.to_owned(), value));
        Ok(())
    }
    pub fn hide(&self) {
        let mut enum_data = self.0.borrow_mut();
        enum_data.visibility = Visibility::Static;
    }
}

impl StructBuilder {
    pub fn new(name: &str) -> StructBuilder {
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Creating struct {name}");
        StructBuilder(make_builder_ref(StructData {
            name: name.to_owned(),
            description: None,
            attributes: vec![],
            visibility: Visibility::Global,
        }))
    }
    pub fn add_description(&self, description: &str) {
        let mut struct_data = self.0.borrow_mut();
        struct_data.description = Some(description.to_owned());
    }
    pub fn add_attribute(&self, name: &str, ty: &str) -> errors::Result<()> {
        let mut struct_data = self.0.borrow_mut();
        if struct_data.attributes.iter().any(|a| a.0 == name) {
            return Err(errors::ConfigError::DuplicatedStructAttribute(
                name.to_owned(),
            ));
        }
        struct_data
            .attributes
            .push((name.to_owned(), ty.to_owned()));
        Ok(())
    }
    pub fn hide(&self) {
        let mut struct_data = self.0.borrow_mut();
        struct_data.visibility = Visibility::Static;
    }
}

impl TypeBuilder {
    pub fn name(&self) -> String {
        match &self {
            TypeBuilder::Enum(enum_builder) => enum_builder.0.borrow().name.clone(),
            TypeBuilder::Struct(struct_builder) => struct_builder.0.borrow().name.clone(),
        }
    }
}
