use std::time::Duration;

use serde::Serialize;
use tauri::Manager;

use crate::cnl::frame::{Attribute, Value};
use crate::cnl::network::object_entry_object::info::ObjectEntryInformation;
use crate::cnl::network::object_entry_object::latest::event::OwnedObjectEntryEvent;
use crate::state::cnl_state::CNLState;

use canzero_config::config;
use canzero_config::config::{SignalType, Type};

use serde_json;

use super::network_information::NodeInformation;

#[tauri::command]
pub async fn set_object_entry_value(
    state: tauri::State<'_, CNLState>,
    node_name: String,
    object_entry_name: String,
    new_value_json: String,
) -> Result<(), ()> {
    let cnl = state.lock().await;

    let Some(node) = cnl.nodes().iter().find(|no| no.name() == &node_name) else {
        return Err(());
    };
    let Some(object_entry_object) = node
        .object_entries()
        .iter()
        .find(|oe| oe.name() == &object_entry_name)
    else {
        return Err(());
    };
    let oe_type = object_entry_object.ty();

    let json_value = match serde_json::from_str::<serde_json::Value>(&new_value_json) {
        Ok(v) => v,
        Err(_) => return Err(()),
    };

    fn parse_value(oe_type: &config::TypeRef, json_value: &serde_json::Value) -> Result<Value, ()> {
        match oe_type.as_ref() {
            Type::Primitive(SignalType::SignedInt { size }) => {
                if let Some(val) = json_value.as_i64() {
                    let max_uvalue = u64::MAX >> (64 - *size as u32);
                    let max_ivalue: i64 = (max_uvalue >> 1) as i64;
                    let min_ivalue: i64 = unsafe {
                        std::mem::transmute(u64::MAX << (*size as u32 - 1))
                    };
                    if val <= max_ivalue && val >= min_ivalue {
                        Ok(Value::SignedValue(val))
                    } else {
                        return Err(());
                    }
                } else {
                    return Err(());
                }
            }
            Type::Primitive(SignalType::UnsignedInt { size }) => {
                if let Some(val) = json_value.as_u64() {
                    let max_uvalue = u64::MAX >> (64 - *size as u32);
                    if val <= max_uvalue {
                        Ok(Value::UnsignedValue(val))
                    } else {
                        return Err(());
                    }
                } else {
                    return Err(());
                }
            }
            Type::Primitive(SignalType::Decimal {
                size,
                offset,
                scale,
            }) => {
                if let Some(val) = json_value.as_f64() {
                    let max_uvalue = u64::MAX >> (64 - *size as u32);
                    let min = *offset;
                    let max = (max_uvalue as f64) * scale + offset;
                    if val <= max && val >= min {
                        Ok(Value::RealValue(val))
                    } else {
                        return Err(());
                    }
                } else {
                    return Err(());
                }
            }

            Type::Struct {
                name: _,
                description: _,
                attribs,
                visibility: _,
            } => {
                if let Some(map) = json_value.as_object() {
                    let mut attributes: Vec<Attribute> = vec![];

                    for (name, attr_type) in attribs {
                        if let Some(val) = map.get(name) {
                            if let Ok(type_val) = parse_value(attr_type, val) {
                                attributes.push(Attribute::new(name, type_val));
                            } else {
                                return Err(());
                            }
                        } else {
                            return Err(());
                        }
                    }
                    Ok(Value::StructValue(attributes))
                } else {
                    return Err(());
                }
            }
            Type::Enum {
                name: _,
                description: _,
                size: _,
                entries,
                visibility: _,
            } => {
                if let Some(variant_str) = json_value.as_str() {
                    if entries.iter().any(|e| e.0 == variant_str) {
                        Ok(Value::EnumValue(variant_str.to_string()))
                        // Ok(TypeValue::Enum(oe_type.clone(), variant_str.to_string()))
                    } else {
                        return Err(());
                    }
                } else {
                    return Err(());
                }
            }
            Type::Array { len: _, ty: _ } => todo!(),
        }
    }


    let value = match parse_value(oe_type, &json_value) {
        Ok(x) => x,
        Err(_) => return Err(()),
    };

    object_entry_object.set_request(value).await;

    Ok(())
}

#[derive(Debug, Clone, Serialize)]
pub struct ObjectEntryListenLatestResponse {
    event_name: String,
    latest: Option<OwnedObjectEntryEvent>,
}

#[tauri::command]
pub async fn listen_to_latest_object_entry_value(
    state: tauri::State<'_, CNLState>,
    node_name: String,
    object_entry_name: String,
) -> Result<ObjectEntryListenLatestResponse, ()> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: listen_to_latest_object_entry_value({node_name:?}, {object_entry_name:?})");
    let cnl = state.lock().await;

    let Some(node) = cnl.nodes().iter().find(|no| no.name() == &node_name) else {
        return Err(());
    };
    let Some(object_entry_object) = node
        .object_entries()
        .iter()
        .find(|oe| oe.name() == &object_entry_name)
    else {
        return Err(());
    };
    object_entry_object.listen_to_latest();

    let x = ObjectEntryListenLatestResponse {
        event_name: object_entry_object.latest_event_name().to_owned(),
        latest: object_entry_object
            .latest_event()
            .await
            .map(|x| x.to_owned()),
    };

    Ok(x)
}

#[tauri::command]
pub async fn unlisten_from_latest_object_entry_value(
    state: tauri::State<'_, CNLState>,
    node_name: String,
    object_entry_name: String,
) -> Result<(), ()> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: unlisten_from_latest_object_entry_value({node_name}, {object_entry_name})");
    let cnl = state.lock().await;

    let Some(node) = cnl.nodes().iter().find(|no| no.name() == &node_name) else {
        return Err(());
    };
    let Some(object_entry_object) = node
        .object_entries()
        .iter()
        .find(|oe| oe.name() == &object_entry_name)
    else {
        return Err(());
    };
    object_entry_object.unlisten_from_latest().await;
    Ok(())
}

#[derive(Debug, Clone, Serialize)]
pub struct ObjectEntryListenHistoryResponse {
    event_name: String,
    history: Vec<OwnedObjectEntryEvent>,
    now: u64,
}

#[tauri::command]
pub async fn listen_to_history_of_object_entry(
    state: tauri::State<'_, CNLState>,
    node_name: String,
    object_entry_name: String,
    frame_size: u64,
    min_interval: u64,
) -> Result<ObjectEntryListenHistoryResponse, ()> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: listen_to_history_of_object_entry({node_name:?}, {object_entry_name:}, {frame_size})");
    let frame_size = Duration::from_millis(frame_size);
    let min_interval = Duration::from_millis(min_interval);

    let cnl = state.lock().await;

    let Some(node) = cnl.nodes().iter().find(|no| no.name() == &node_name) else {
        eprintln!("error during listen_to_history_of_object_entry");
        return Err(());
    };
    let Some(object_entry_object) = node
        .object_entries()
        .iter()
        .find(|oe| oe.name() == &object_entry_name)
    else {
        eprintln!("error during listen_to_history_of_object_entry");
        return Err(());
    };
    let (event_name, history) = object_entry_object
        .listen_to_history(frame_size, min_interval)
        .await;

    let x = ObjectEntryListenHistoryResponse {
        event_name,
        history,
        now: object_entry_object.now().as_millis() as u64,
    };

    Ok(x)
}

#[tauri::command]
pub async fn unlisten_from_history_of_object_entry(
    state: tauri::State<'_, CNLState>,
    node_name: String,
    object_entry_name: String,
    event_name: String,
) -> Result<(), ()> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: unlisten_from_history_object_entry({node_name}, {object_entry_name})");
    let cnl = state.lock().await;

    let Some(node) = cnl.nodes().iter().find(|no| no.name() == &node_name) else {
        return Err(());
    };
    let Some(object_entry_object) = node
        .object_entries()
        .iter()
        .find(|oe| oe.name() == &object_entry_name)
    else {
        return Err(());
    };
    object_entry_object.unlisten_from_history(&event_name).await;
    Ok(())
}

#[tauri::command]
pub async fn request_object_entry_value(
    state: tauri::State<'_, CNLState>,
    node_name: String,
    object_entry_name: String,
) -> Result<(), ()> {
    #[cfg(feature = "logging-invoke")]
    println!("invoke: (get-request) request_object_entry_value({node_name}, {object_entry_name})");
    let cnl = state.lock().await;

    let Some(node) = cnl.nodes().iter().find(|no| no.name() == &node_name) else {
        return Err(());
    };
    let Some(object_entry) = node
        .object_entries()
        .iter()
        .find(|oe| oe.name() == &object_entry_name)
    else {
        return Err(());
    };

    object_entry.request_current_value().await;

    Ok(())
}

#[tauri::command]
pub fn get_floating_window_info(window: tauri::Window) -> (String, String) {
    let split : Vec<&str> = window.label().split("-").collect();
    let node_name = split.get(1).unwrap();
    let object_entry_name = split.get(2).unwrap();
    return ((*node_name).to_owned(), (*object_entry_name).to_owned());
}

#[tauri::command]
pub fn open_floating_object_entry_window(
    app_handle: tauri::AppHandle,
    node_name: String,
    object_entry_name: String,
) {
    let label = format!("plot-{node_name}-{object_entry_name}");
    let None = app_handle.get_window(&label) else {
        return;
    };

    tauri::WindowBuilder::new(
        &app_handle,
        label,
        tauri::WindowUrl::App("plot.html".into()),
    )
    .center()
    .title(format!("CANzero {node_name}::{object_entry_name}"))
    .inner_size(1200f64, 525f64)
    .resizable(true)
    .visible(true)
    .build()
    .unwrap();
}
