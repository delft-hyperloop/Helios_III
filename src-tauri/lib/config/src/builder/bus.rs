use super::{BuilderRef, make_builder_ref};


#[derive(Debug, Clone)]
pub struct BusBuilder(pub BuilderRef<BusData>);

#[derive(Debug)]
pub struct BusData {
    pub name : String,
    pub id : u32,
    pub baudrate : u32,
    pub expected_utilization : u32,
}

impl BusBuilder {
    pub fn new(name : &str, id : u32, baudrate: Option<u32>) -> Self {
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Creating bus {name} with id {id}");
        BusBuilder(make_builder_ref(BusData {
            name : name.to_owned(),
            id,
            baudrate : baudrate.unwrap_or(1000000),
            expected_utilization : 0,
        }))
    }

    pub fn baudrate(&self, baudrate : u32) {
        self.0.borrow_mut().baudrate = baudrate;
    }
}

