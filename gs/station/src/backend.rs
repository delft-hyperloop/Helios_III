use crate::api::Message;
use crate::Command;

// /// Any frontend that interfaces with this backend needs to comply to this trait
// pub trait Frontend {
//     /// This is called from main.rs, can be used for any initialisation
//     fn start();
//     /// When the backend has data available, it will call this function
//     fn receive_data(&mut self, data: Vec<Message>);
//     ///
//     fn send_command(&self, cmd: Command);
// }


pub struct Backend {
    pub data_buffer: Vec<Message>,
    pub command_buffer: Vec<Command>,
}
//
// impl Backend {
//     pub fn start() -> Self { todo!() }
//
//     pub fn
// }