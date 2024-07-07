use std::cmp::min;
use std::collections::HashSet;

pub mod commands;
pub mod datatypes;
pub mod events;
pub mod info;
pub mod ip;
mod shared;

pub fn check_ids(dp: &str, cp: &str, ep: &str) -> Vec<u16> {
    let mut ids = vec![];
    ids.extend(datatypes::get_data_ids(dp));
    ids.extend(commands::get_command_ids(cp));
    ids.extend(events::get_event_ids(ep));
    let mut seen = HashSet::new();
    for id in &ids {
        if !seen.insert(id) {
            panic!(
                "\nDuplicate id found: {} ({}). Closest available id is: {}\n",
                format_args!("{:#05x}", id),
                format_args!("{:#05x}", id),
                format_args!("{:#05x}", nearest_id(*id, &ids)),
            );
        } else if *id > 2u16.pow(11) {
            panic!(
                "\nId out of range: {}. Allowed ids are 0x000-0x7ff. Closest available id is: {}\n",
                format_args!("{:#05x}", id),
                format_args!("{:#05x}", nearest_id(*id, &ids))
            );
        }
    }
    ids
}

fn nearest_id(id: u16, ids: &[u16]) -> u16 {
    for i in min(id, 2u16.pow(11))..2u16.pow(11) {
        if !ids.contains(&i) {
            return i;
        }
    }
    for j in (0u16..2u16.pow(11)).rev() {
        if !ids.contains(&j) {
            return j;
        }
    }
    panic!("There are no more available ids!")
}
