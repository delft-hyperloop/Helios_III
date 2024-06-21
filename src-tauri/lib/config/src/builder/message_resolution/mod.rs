use crate::{config::TypeRef, errors};

use self::{filter_configuration::NodeFilterBank, fixed_messages::MessageSplit};

use super::{bus::BusBuilder, MessageBuilder, NodeBuilder};

mod assign_messages;
mod bus_balancing;
mod filter_configuration;
mod fixed_messages;
mod logging;
mod receive_set;
mod set_minimization;

pub fn resolve_ids_filters_and_buses(
    buses: &Vec<BusBuilder>,
    messages: &Vec<MessageBuilder>,
    nodes: &Vec<NodeBuilder>,
    types: &Vec<TypeRef>,
) -> errors::Result<Vec<NodeFilterBank>> {
    let mut messages = messages.clone();
    let mut nodes = nodes.clone();
    let mut buses = buses.clone();
    let mut types = types.clone();
    // NOTE hack deterministic behaviour
    messages.sort_by_key(|k| k.0.borrow().name.clone());
    nodes.sort_by_key(|k| k.0.borrow().name.clone());
    buses.sort_by_key(|k| k.0.borrow().name.clone());
    types.sort_by_key(|t| t.name());


    #[cfg(feature = "logging_idrp")]
    let logging_info = logging::cache_logging_info(&types, &messages);

    let message_split = MessageSplit::from(&messages);
    let network_info =
        receive_set::generate_receive_sets_from_messages(&nodes, message_split.prio_messages());
    let minimized_network = set_minimization::minimize_sets(network_info);
    let filter_infos = assign_messages::assign_messages_ids(
        message_split.fixed_messages(),
        minimized_network,
        &nodes,
    );
    bus_balancing::balance_buses(&messages, &types, &buses);
    let filter_banks = filter_configuration::find_filter_configuration(filter_infos);

    #[cfg(feature = "logging_idrp")]
    logging::log_info(logging_info);

    Ok(filter_banks)
}

//
// #[cfg(test)]
// mod tests {
//     use std::{
//         collections::hash_map::DefaultHasher,
//         hash::{Hash, Hasher},
//     };
//
//     use crate::builder::{MessagePriority, NetworkBuilder};
//
//     #[test]
//     pub fn test_1() {
//         let network_builder = NetworkBuilder::new();
//         network_builder.create_bus("can0", Some(1000000));
//         network_builder.create_bus("can1", Some(1000000));
//
//         struct MessageNameGen {
//             acc : u32,
//         }
//         impl MessageNameGen {
//             pub fn new() -> Self {
//                 Self {
//                     acc : 0,
//                 }
//             }
//             pub fn next(&mut self) -> String {
//                 let next = format!("test_msg_{}", self.acc);
//                 self.acc += 1;
//                 next
//             }
//         }
//
//         let mut name_gen = MessageNameGen::new();
//
//         fn create_test_message(
//             network_builder: &NetworkBuilder,
//             rx_node_name: &str,
//             name_gen: &mut MessageNameGen,
//         ) {
//             let name = name_gen.next();
//             let mut hasher = DefaultHasher::new();
//             name.hash(&mut hasher);
//             let x = network_builder.create_message(&name, None);
//             let priority = MessagePriority::from_u32(
//                 (hasher.finish() % MessagePriority::count() as u64) as u32,
//             );
//             x.set_any_std_id(priority);
//             x.add_receiver(rx_node_name);
//         }
//         let message_per_node = 70;
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "secu", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "master", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "pdu24", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "pdu12", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "becu", &mut name_gen);
//         }
//
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "clu", &mut name_gen);
//         }
//
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "mlu1", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "mlu2", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "mlu3", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "mlu4", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "mlu5", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "mlu6", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "motor1", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "motor2", &mut name_gen);
//         }
//
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "lgu1", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "lgu2", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "lgu3", &mut name_gen);
//         }
//         for _ in 0..message_per_node {
//             create_test_message(&network_builder, "lgu4", &mut name_gen);
//         }
//
//
//         // let fixed = network_builder.create_message("fixed_secu1", None);
//         // fixed.set_std_id(0xFF);
//         //
//         // let fixed = network_builder.create_message("fixed_master", None);
//         // fixed.set_std_id(0xFA);
//         //
//         // let fixed = network_builder.create_message("fixed_clu", None);
//         // fixed.set_std_id(0xFB);
//         //
//         // let fixed = network_builder.create_message("fixed_secu2", None);
//         // fixed.set_std_id(0xFE);
//         //
//         // let fixed = network_builder.create_message("fixed_secu3", None);
//         // fixed.set_ext_id(0xFD);
//
//         network_builder.build().unwrap();
//
//         assert!(false);
//
//     }
// }
