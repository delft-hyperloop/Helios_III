
use canzero_config::config::{Type, TypeRef};
use std::io::Write;
use chrono::{Datelike, Timelike};
use tauri::api::dialog::FileDialogBuilder;

use crate::{
    cnl::{frame::Value, network::object_entry_object::latest::event::OwnedObjectEntryEvent},
    state::cnl_state::CNLState,
};

#[tauri::command]
pub async fn export(
    state: tauri::State<'_, CNLState>,
) -> Result<(), ()> {
    println!("invoke: export()");

    let cnl = state.lock().await;

    struct ObjectEntryExport {
        pub name: String,
        pub ty: TypeRef,
        pub values: Vec<OwnedObjectEntryEvent>,
    }

    struct NodeExport {
        pub name: String,
        pub object_entry_export: Vec<ObjectEntryExport>,
    }

    let mut export_data: Vec<NodeExport> = vec![];
    for node in cnl.nodes() {
        let mut object_entry_export = vec![];
        for oe in node.object_entries() {
            object_entry_export.push(ObjectEntryExport {
                name: oe.name().to_owned(),
                ty: oe.ty().clone(),
                values: oe.complete_history().await,
            });
        }
        export_data.push(NodeExport {
            name: node.name().to_owned(),
            object_entry_export,
        });
    }

    drop(cnl);

    let (tx,rx) = tokio::sync::oneshot::channel::<()>();

    tokio::task::spawn_blocking(move || {
        FileDialogBuilder::new()
            .set_title("Select export directory")
            .pick_folder(move |folder| {
                let Some(mut folder) = folder else {
                    return;
                };
                let time = chrono::Local::now();
                let year = time.year();
                let month = time.month();
                let day = time.day();
                let hour = time.hour();
                let min = time.minute();
                let sec = time.second();

                folder.push(format!("{year}-{month}-{day}_{hour}_{min}_{sec}"));
                std::fs::create_dir(folder.clone())
                    .expect(&format!("Failed to create directory {folder:?}"));

                for node in export_data {
                    let mut node_dir = folder.clone();
                    node_dir.push(&node.name);
                    std::fs::create_dir(node_dir.clone()).expect("Failed to create node directory");
                    // create directory
                    for oe in node.object_entry_export {
                        let mut path = node_dir.clone();
                        path.push(oe.name);
                        path.set_extension("csv");
                        let mut file = std::fs::File::create(path.clone())
                            .expect(&format!("Failed to create file {path:?}"));
                        struct Column {
                            pub name: String,
                            pub values: Vec<String>,
                        }
                        let mut columns: Vec<Column> = vec![];
                        columns.push(Column {
                            name: "timestamp".to_owned(),
                            values: vec![],
                        });
                        fn create_columns(
                            ty: &Type,
                            column_name: Option<String>,
                            columns: &mut Vec<Column>,
                        ) {
                            match ty {
                                Type::Primitive(_) => {
                                    columns.push(Column {
                                        name: column_name.unwrap_or("value".to_owned()),
                                        values: vec![],
                                    });
                                }
                                Type::Struct {
                                    name: _,
                                    description: _,
                                    attribs,
                                    visibility: _,
                                } => {
                                    for (attrib_name, attrib_type) in attribs {
                                        let column_name = match &column_name {
                                            Some(column_name) => {
                                                format!("{column_name}.{attrib_name}")
                                            }
                                            None => attrib_name.to_owned(),
                                        };
                                        create_columns(attrib_type, Some(column_name), columns);
                                    }
                                }
                                Type::Enum {
                                    name: _,
                                    description: _,
                                    size: _,
                                    entries: _,
                                    visibility: _,
                                } => {
                                    columns.push(Column {
                                        name: column_name.unwrap_or("value".to_owned()),
                                        values: vec![],
                                    });
                                }
                                Type::Array { len: _, ty: _ } => panic!("Arrays not implemented"),
                            }
                        }
                        create_columns(&&oe.ty, None, &mut columns);

                        fn add_value_to_columns(
                            value: &Value,
                            c: &mut usize,
                            columns: &mut Vec<Column>,
                        ) {
                            match value {
                                Value::UnsignedValue(v) => {
                                    columns[*c].values.push(format!("{v}"));
                                    *c += 1;
                                }
                                Value::SignedValue(v) => {
                                    columns[*c].values.push(format!("{v}"));
                                    *c += 1;
                                }
                                Value::RealValue(v) => {
                                    columns[*c].values.push(format!("{v}"));
                                    *c += 1;
                                }
                                Value::StructValue(attribs) => {
                                    for attrib in attribs {
                                        add_value_to_columns(attrib.value(), c, columns);
                                    }
                                }
                                Value::EnumValue(v) => {
                                    columns[*c].values.push(format!("{v}"));
                                    *c += 1;
                                }
                            }
                        }

                        for value in &oe.values {
                            let us = value.timestamp.as_micros();
                            columns[0].values.push(format!("{us}"));
                            add_value_to_columns(&value.value, &mut 1, &mut columns);
                        }

                        // write headers
                        let mut first = true;
                        for column in &columns {
                            if !first {
                                write!(file, ",").expect("Failed to write to file");
                            }
                            first = false;
                            write!(file, "{}", column.name).expect("Failed to write to file");
                        }
                        writeln!(file).expect("Failed to write to file");

                        // write values
                        for i in 0..oe.values.len() {
                            let mut first = true;
                            for column in &columns {
                                if !first {
                                    write!(file, ",").expect("Failed to write to file");
                                }
                                first = false;
                                write!(file, "{}", column.values[i]).expect("Failed to write to file");
                            }
                            writeln!(file).expect("Failed to write to file");
                        }
                    }
                }
                tx.send(()).unwrap();
            })
    })
    .await
    .expect("Failed to join blocking io task");


    rx.await.expect("Failed to await oneshot duing export");
    println!("EXPORT EXIT");

    Ok(())
}
