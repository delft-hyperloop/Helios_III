use embassy_executor::Spawner;
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::Sender;
use heapless::binary_heap::Max;
use crate::Event;
pub struct Status{
    pub propulsion_ready : bool,
    pub levitation_ready : bool,
    pub powertrain_ready : bool,
}

impl Status {

    pub fn new() -> Self{
        Self {
            propulsion_ready : false,
            levitation_ready : false,
            powertrain_ready : false,
        }
    }
    pub fn check_propulsion(&mut self) -> bool {
        self.propulsion_ready = true;
        return true;
    }
    pub fn check_levitation(&mut self) -> bool {
        self.levitation_ready = true;
        return true;
    }
    pub fn check_powertrain(&mut self) -> bool {
        self.powertrain_ready = true;
        return true;
    }
    pub fn check_all(&self) -> bool {
        return if (self.propulsion_ready && self.levitation_ready && self.powertrain_ready) {
            true
        } else {
            false
        }
    }
    pub fn reset(&mut self){
        self.propulsion_ready = false;
        self.levitation_ready = false;
        self.powertrain_ready = false;
    }
}