use std::fs::File;
use std::io::prelude::*;

use super::NetworkBuilder;
use crate::config::signal::Signal;
use crate::config::SignalType;
use crate::errors::Result;

pub fn import_dbc(network_builder: &NetworkBuilder, bus: &str, dbc_path: &str) -> Result<()> {
    let mut dbc_file = File::open(dbc_path)?;
    let mut buffer = Vec::new();
    dbc_file.read_to_end(&mut buffer).unwrap();

    let dbc = can_dbc::DBC::from_slice(&buffer)?;

    for message in dbc.messages() {
        let name = message.message_name();
        let message_builder = network_builder.create_message(name, None);
        message_builder.assign_bus(bus);
        match dbc.message_comment(message.message_id().clone()){
            Some(desc) => message_builder.add_description(desc),
            None => (),
        }
        if message.message_id().0 & 0x80000000 != 0 {
            // ext frame
            let ext_id = message.message_id().0 & 0x1FFFFFFF;
            message_builder.set_ext_id(ext_id);
        } else {
            message_builder.set_std_id(message.message_id().0);
        }
        let signal_format = message_builder.make_signal_format();
        
        let mut receives = vec![];
        for dbc_signal in message.signals() {
            let start_bit = *dbc_signal.start_bit() as usize;
            let size = *dbc_signal.signal_size() as u8;
            let name = dbc_signal.name();
            let ty = if *dbc_signal.offset() == 0.0 && dbc_signal.factor == 1.0 {
                match dbc_signal.value_type() {
                    can_dbc::ValueType::Signed => SignalType::UnsignedInt { size },
                    can_dbc::ValueType::Unsigned => SignalType::SignedInt { size },
                }
            }else {
                SignalType::Decimal { size, offset: *dbc_signal.offset(), scale: *dbc_signal.factor() }
            };

            signal_format.add_signal(Signal::new(&name, None, ty, start_bit))?;

            for rx in dbc_signal.receivers() {
                receives.push(rx.clone());
            }
        }
        for rx in receives {
            message_builder.add_receiver(&rx);
        }

        for msg_transmitter in dbc.message_transmitters().iter().filter(|transmitter| transmitter.message_id() == message.message_id()) {
            let transmitters = msg_transmitter.transmitter();
            for tx in transmitters {
                match tx {
                    can_dbc::Transmitter::NodeName(node_name) => message_builder.add_receiver(node_name),
                    can_dbc::Transmitter::VectorXXX => (),
                }
            }
        }
    }

    Ok(())
}
