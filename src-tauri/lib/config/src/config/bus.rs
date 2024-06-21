use std::hash::Hash;

use super::ConfigRef;



pub type BusRef = ConfigRef<Bus>;

#[derive(Debug)]

pub struct Bus {
    id : u32,
    baudrate : u32,
    name : String,
}

impl Bus {
    pub fn new(name : &str, id : u32, baudrate : u32) -> Self{
        Self {
            id,
            baudrate,
            name : name.to_owned(),
        }
    }
    pub fn id(&self) -> u32 {
        self.id
    }
    pub fn baudrate(&self) -> u32 {
        self.baudrate
    }
    pub fn name(&self) -> &str {
        &self.name
    }
}


impl Hash for Bus {
    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        state.write_u32(self.id);
        state.write_u32(self.baudrate);
        for b in self.name.bytes() {
            state.write_u8(b);
        }
    }
}
