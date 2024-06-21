
use serde::Serialize;

use self::ty::ObjectEntryType;

pub mod ty;


// In typescript represented as types/ObjectEntryInformation
#[derive(Serialize, Clone)]
pub struct ObjectEntryInformation {
    name: String,
    description: Option<String>,
    friend : Option<String>,
    id: u16,
    unit: Option<String>,
    ty : ObjectEntryType,
    plottable : bool,
}

impl ObjectEntryInformation {
    pub fn new(name : String, description : Option<String>, 
               friend : Option<String>,
               id : u16,
               unit : Option<String>,
               ty : ObjectEntryType, plottable : bool) -> Self {
        Self {
            name,
            description,
            friend,
            id,
            unit,
            ty,
            plottable

        }
    }
}

