use std::{
    path::{Path, PathBuf},
    time::Duration,
};

use canzero_config::{
    builder::{bus::BusBuilder, EnumBuilder, NetworkBuilder, NodeBuilder, StructBuilder},
    config::ObjectEntryAccess,
};

use crate::errors::{Error, Result};

pub fn parse_object_entry(
    oe_name: &str,
    oe_map: &yaml_rust::Yaml,
    node_builder: &mut NodeBuilder,
) -> Result<()> {
    let yaml_rust::Yaml::Hash(map) = oe_map else {
        return Err(Error::YamlInvalidType(format!(
            "object_entries have to be defined by mapps"
        )));
    };

    let yaml_rust::Yaml::String(type_name) = &oe_map["type"] else {
        return Err(Error::YamlInvalidType(format!(
            "types have to be defined as strings by their name"
        )));
    };


    let oe_builder = node_builder.create_object_entry(oe_name, &type_name);

    if map.contains_key(&yaml_rust::Yaml::String("description".to_owned())) {
        let yaml_rust::Yaml::String(description) = &oe_map["description"] else {
            return Err(Error::YamlInvalidType(format!(
                "descriptions have to be defined has strings"
            )));
        };
        oe_builder.add_description(&description);
    }

    if map.contains_key(&yaml_rust::Yaml::String("friend".to_owned())) {
        let yaml_rust::Yaml::String(friend) = &oe_map["friend"] else {
            return Err(Error::YamlInvalidType(format!(
                "descriptions have to be defined has strings"
            )));
        };
        oe_builder.friend(&friend);
    }

    if map.contains_key(&yaml_rust::Yaml::String("unit".to_owned())) {
        let yaml_rust::Yaml::String(unit) = &oe_map["unit"] else {
            return Err(Error::YamlInvalidType(format!(
                "unit has to be defined as a string"
            )));
        };
        oe_builder.add_unit(&unit);
    }

    if map.contains_key(&yaml_rust::Yaml::String("access".to_owned())) {
        let yaml_rust::Yaml::String(access) = &oe_map["access"] else {
            return Err(Error::YamlInvalidType(format!(
                "access has to be defined as a string"
            )));
        };
        let access = access.to_lowercase();
        if access == "const" {
            oe_builder.set_access(ObjectEntryAccess::Const);
        } else if access == "local" || access == "readonly" || access == "static" {
            oe_builder.set_access(ObjectEntryAccess::Local);
        } else if access == "global" || access == "readwrite" {
            oe_builder.set_access(ObjectEntryAccess::Global);
        } else if access == "extern" || access == "external" {
            oe_builder.set_access(ObjectEntryAccess::Global);
        }
    }

    Ok(())
}

pub fn parse_tx_stream(
    stream_name: &str,
    stream_def: &yaml_rust::Yaml,
    node_builder: &mut NodeBuilder,
) -> Result<()> {
    let stream_builder = node_builder.create_stream(stream_name);

    let yaml_rust::Yaml::Hash(map) = stream_def else {
        return Err(Error::YamlInvalidType(format!(
            "streams have to be defined has maps"
        )));
    };

    if map.contains_key(&yaml_rust::Yaml::String("description".to_owned())) {
        let yaml_rust::Yaml::String(description) = &stream_def["description"] else {
            return Err(Error::YamlInvalidType(format!(
                "description has to be a string"
            )));
        };
        stream_builder.add_description(&description);
    }

    if map.contains_key(&yaml_rust::Yaml::String("mapping".to_owned())) {
        let yaml_rust::Yaml::Array(array) = &stream_def["mapping"] else {
            return Err(Error::YamlInvalidType(format!(
                "stream mappings have to be arrays"
            )));
        };
        for oe_name in array {
            let yaml_rust::Yaml::String(oe_name) = oe_name else {
                return Err(Error::YamlInvalidType(format!(
                    "stream mappings entries have to be names of object entries"
                )));
            };
            stream_builder.add_entry(oe_name);
        }
    }

    if map.contains_key(&yaml_rust::Yaml::String("interval".to_owned())) {
        let yaml_rust::Yaml::String(interval) = &stream_def["interval"] else {
            return Err(Error::YamlInvalidType(format!(
                "stream intervals have to be defined has strings"
            )));
        };

        let range_interval = regex::Regex::new(
            r"(?<min>\d+)\s*(?<min_unit>(ms|s))\s*-\s*(?<max>\d+)\s*(?<max_unit>(ms|s))",
        )
        .unwrap();
        match range_interval.captures(interval) {
            Some(captures) => {
                let min = &captures["min"];
                let min_unit = &captures["min_unit"];
                let max = &captures["max"];
                let max_unit = &captures["max_unit"];

                let min: u64 = min.parse().unwrap();
                let min = if min_unit == "ms" {
                    Duration::from_millis(min)
                } else if min_unit == "s" {
                    Duration::from_secs(min)
                } else {
                    panic!()
                };
                let max: u64 = max.parse().unwrap();
                let max = if max_unit == "ms" {
                    Duration::from_millis(max)
                } else if max_unit == "s" {
                    Duration::from_secs(max)
                } else {
                    panic!()
                };
                stream_builder.set_interval(min, max);
            }
            None => {
                let single_interval = regex::Regex::new(r"(?<x>\d+)\s*(?<unit>(ms|s))").unwrap();
                match single_interval.captures(interval) {
                    Some(captures) => {
                        let interval = &captures["x"];
                        let unit = &captures["unit"];
                        let interval: u64 = interval.parse().unwrap();
                        let interval = if unit == "ms" {
                            Duration::from_millis(interval)
                        } else if unit == "s" {
                            Duration::from_secs(interval)
                        } else {
                            panic!()
                        };
                        stream_builder.set_interval(interval, interval);
                    }
                    None => {
                        panic!("intervals have to be defined as strings with \"\\d+(ms|s)\"");
                    }
                }
            }
        }
    }

    // TODO parse interval.

    Ok(())
}

pub fn parse_tx_command(
    command_name: &str,
    command_map: &yaml_rust::Yaml,
    node_builder: &mut NodeBuilder,
) -> Result<()> {
    let command_builder = node_builder.create_command(command_name, None);

    let yaml_rust::Yaml::Hash(map) = command_map else {
        return Err(Error::YamlInvalidType(format!(
            "commands have to be defined has maps"
        )));
    };

    if map.contains_key(&yaml_rust::Yaml::String("description".to_owned())) {
        let yaml_rust::Yaml::String(description) = &command_map["description"] else {
            return Err(Error::YamlInvalidType(format!(
                "description has to be a string"
            )));
        };
        command_builder.add_description(&description);
    }

    if map.contains_key(&yaml_rust::Yaml::String("arguments".to_owned())) {
        let yaml_rust::Yaml::Array(args) = &command_map["arguments"] else {
            return Err(Error::YamlInvalidType(format!(
                "the argument list of a command has to be a array"
            )));
        };
        for arg_map in args {
            let yaml_rust::Yaml::Hash(arg_map) = arg_map else {
                return Err(Error::YamlInvalidType(format!(
                    "command args have to be defined as \" <name> : <type> \" "
                )));
            };
            if arg_map.len() != 1 {
                return Err(Error::YamlInvalidType(format!(
                    "command args have to be defined as \" <name> : <type> \" "
                )));
            }
            let (name_yaml, type_yaml) = arg_map.iter().next().unwrap();
            let yaml_rust::Yaml::String(name) = name_yaml else {
                return Err(Error::YamlInvalidType(format!(
                    "command args have to be defined as \" <name> : <type> \" "
                )));
            };
            let yaml_rust::Yaml::String(ty) = type_yaml else {
                return Err(Error::YamlInvalidType(format!(
                    "command args have to be defined as \" <name> : <type> \" "
                )));
            };
            command_builder.add_argument(name, ty);
        }
    }

    if map.contains_key(&yaml_rust::Yaml::String("callee".to_owned())) {
        let yaml_rust::Yaml::Array(callees) = &command_map["callee"] else {
            return Err(Error::YamlInvalidType(format!(
                "the argument list of a command has to be a array"
            )));
        };
        for callee in callees {
            let yaml_rust::Yaml::String(callee_name) = callee else {
                return Err(Error::YamlInvalidType(format!(
                    "callees have to refered to by name (String)"
                )));
            };
            command_builder.add_callee(callee_name);
        }
    }

    Ok(())
}

pub fn parse_rx_stream(
    node_name: &str,
    stream_name: &str,
    stream_def: &yaml_rust::Yaml,
    node_builder: &mut NodeBuilder,
) -> Result<()> {
    let rx_stream_builder = node_builder.receive_stream(node_name, stream_name);

    //parse stream_def as oe mapping
    let yaml_rust::Yaml::Hash(map) = stream_def else {
        return Err(Error::YamlInvalidType(format!(
            "rx_streams have to be defined as maps of oe entries"
        )));
    };
    for (tx_oe_name, rx_oe_name) in map {
        let yaml_rust::Yaml::String(tx_oe_name) = tx_oe_name else {
            return Err(Error::YamlInvalidType(format!(
                "object entries have to be refered to by name in rx_stream definition"
            )));
        };
        let yaml_rust::Yaml::String(rx_oe_name) = rx_oe_name else {
            return Err(Error::YamlInvalidType(format!(
                "object entries have to be refered to by name in rx_stream definition"
            )));
        };
        rx_stream_builder.map(tx_oe_name, rx_oe_name);
    }
    Ok(())
}

pub fn parse_node(
    node_name: &str,
    node_map: &yaml_rust::Yaml,
    network_builder: &mut NetworkBuilder,
) -> Result<()> {
    let mut node_builder = network_builder.create_node(node_name);
    let yaml_rust::Yaml::Hash(map) = node_map else {
        return Err(Error::YamlInvalidType(format!(
            "nodes have to be defined as maps"
        )));
    };

    if map.contains_key(&yaml_rust::Yaml::String("description".to_owned())) {
        let yaml_rust::Yaml::String(description) = &node_map["description"] else {
            return Err(Error::YamlInvalidType(format!(
                "description has to be a string"
            )));
        };
        node_builder.add_description(&description);
    }
    if map.contains_key(&yaml_rust::Yaml::String("object_dictionary".to_owned())) {
        let yaml_rust::Yaml::Hash(od_map) = &node_map["object_dictionary"] else {
            return Err(Error::YamlInvalidType(format!(
                "object_dictionary has to be a map"
            )));
        };
        for (name, oe_map) in od_map {
            let yaml_rust::Yaml::String(name) = name else {
                return Err(Error::YamlInvalidType(format!(
                    "the name of a object_entry has to be a string"
                )));
            };
            parse_object_entry(name, oe_map, &mut node_builder)?;
        }
    }

    if map.contains_key(&yaml_rust::Yaml::String("tx_streams".to_owned())) {
        let yaml_rust::Yaml::Hash(streams_map) = &node_map["tx_streams"] else {
            return Err(Error::YamlInvalidType(format!(
                "tx_streams have to be defined as maps"
            )));
        };
        for (stream_name, stream_def) in streams_map {
            let yaml_rust::Yaml::String(stream_name) = stream_name else {
                return Err(Error::YamlInvalidType(format!(
                    "the name of a stream has to be a string"
                )));
            };
            parse_tx_stream(&stream_name, stream_def, &mut node_builder)?;
        }
    }

    if map.contains_key(&yaml_rust::Yaml::String("rx_streams".to_owned())) {
        let yaml_rust::Yaml::Hash(rx_node) = &node_map["rx_streams"] else {
            return Err(Error::YamlInvalidType(format!(
                "rx_streams have to be defined as maps"
            )));
        };
        for (node_name, tx_node_streams) in rx_node {
            let yaml_rust::Yaml::String(node_name) = node_name else {
                return Err(Error::YamlInvalidType(format!(
                    "rx_streams has to contains the names of the tx_nodes has strings"
                )));
            };
            let yaml_rust::Yaml::Hash(tx_node_streams) = tx_node_streams else {
                return Err(Error::YamlInvalidType(format!(
                    "rx_streams has to be a map of names of tx_nodes, which has to be a map of the tx_streams that are received"
                )));
            };
            for (stream_name, stream_def) in tx_node_streams {
                let yaml_rust::Yaml::String(stream_name) = stream_name else {
                    return Err(Error::YamlInvalidType(format!(
                        "stream names have to be defined as strings"
                    )));
                };
                parse_rx_stream(node_name, stream_name, stream_def, &mut node_builder)?;
            }
        }
    }

    if map.contains_key(&yaml_rust::Yaml::String("commands".to_owned())) {
        let yaml_rust::Yaml::Hash(commands) = &node_map["commands"] else {
            return Err(Error::YamlInvalidType(format!(
                "command lists have to be defined has maps"
            )));
        };
        for (command_name, command_def) in commands {
            let yaml_rust::Yaml::String(command_name) = command_name else {
                return Err(Error::YamlInvalidType(format!(
                    "the name of a command has to be a string"
                )));
            };
            parse_tx_command(command_name, command_def, &mut node_builder)?;
        }
    }
    Ok(())
}

pub fn parse_enum_type(enum_map: &yaml_rust::Yaml, enum_builder: &mut EnumBuilder) -> Result<()> {
    let yaml_rust::Yaml::Hash(enum_hash_map) = enum_map else {
        return Err(Error::YamlInvalidType(format!(
            "Enums have to be given as a map with variants"
        )));
    };
    for (variant_name, variant_value) in enum_hash_map {
        let yaml_rust::Yaml::String(variant_name) = variant_name else {
            return Err(Error::YamlInvalidType(format!(
                "enum variants must be string"
            )));
        };
        let value = match variant_value {
            yaml_rust::Yaml::Integer(value) => {
                if *value < 0 {
                    return Err(Error::YamlInvalidType(format!(
                        "enum values must be positive"
                    )));
                }
                Some(*value as u64)
            }
            yaml_rust::Yaml::Null => None,
            _ => {
                return Err(Error::YamlInvalidType(format!(
                    "enum variants must be string"
                )));
            }
        };
        enum_builder.add_entry(variant_name, value)?;
    }
    Ok(())
}

pub fn parse_struct_type(
    struct_map: &yaml_rust::Yaml,
    struct_builder: &mut StructBuilder,
) -> Result<()> {
    let yaml_rust::Yaml::Hash(struct_hash_map) = struct_map else {
        return Err(Error::YamlInvalidType(format!(
            "structs have to be given as a map with of attributes"
        )));
    };
    for (attribute_name, attribute_type) in struct_hash_map {
        let yaml_rust::Yaml::String(attribute_name) = attribute_name else {
            return Err(Error::YamlInvalidType(format!(
                "struct attributes have to be denoted by strings"
            )));
        };
        let yaml_rust::Yaml::String(attribute_type) = attribute_type else {
            return Err(Error::YamlInvalidType(format!(
                "struct attributes need to have a string encoded type"
            )));
        };
        struct_builder.add_attribute(attribute_name, attribute_type)?;
    }
    Ok(())
}

pub fn parse_bus(
    network_builder: &NetworkBuilder,
    bus_map: &yaml_rust::Yaml,
    bus_builder: &BusBuilder,
) -> Result<()> {
    let yaml_rust::Yaml::Hash(bus_hash_map) = bus_map else {
        return Err(Error::YamlInvalidType(format!(
            "bus must be described by a map"
        )));
    };

    bus_hash_map
        .get(&yaml_rust::yaml::Yaml::String("baudrate".to_owned()))
        .map(|yaml| {
            let yaml_rust::Yaml::Integer(baudrate) = yaml else {
                panic!("baudrate must be integer value");
            };
            bus_builder.baudrate(*baudrate as u32);
        });

    bus_hash_map
        .get(&yaml_rust::yaml::Yaml::String("database".to_owned()))
        .map(|yaml| {
            let yaml_rust::Yaml::String(path) = yaml else {
                panic!("database paths have to be strings ending in .dbc");
            };
            match network_builder.include_dbc(&bus_builder.0.borrow().name, path) {
                Ok(_) => (),
                Err(err) => panic!("Failed to include DBC \n{err:?}"),
            }
        });

    Ok(())
}

pub fn parse_top_level(
    yaml: &yaml_rust::yaml::Yaml,
    network_builder: &mut NetworkBuilder,
    path: &Path,
) -> Result<()> {
    let yaml_rust::Yaml::Hash(_) = yaml else {
        return Err(Error::YamlInvalidFormat(format!("")));
    };

    let nodes_map = if let yaml_rust::Yaml::String(include_path) = &yaml["nodes"] {
        let mut buf = path.parent().unwrap().to_path_buf();
        buf.push(include_path);
        let path = buf.as_path();
        let yaml_str = std::fs::read_to_string(&path).expect(&format!("Failed to read {path:?}"));
        let docs = yaml_rust::yaml::YamlLoader::load_from_str(&yaml_str).unwrap();
        let doc = &docs[0];
        doc.as_hash().unwrap().clone()
    } else {
        let yaml_rust::Yaml::Hash(nodes_map) = &yaml["nodes"] else {
            return Err(Error::YamlInvalidType(format!(
                "enums must be given as a map"
            )));
        };
        nodes_map.clone()
    };

    for (name, node_def) in &nodes_map {
        let yaml_rust::Yaml::String(name) = name else {
            return Err(Error::YamlInvalidType(format!(
                "name of a node has to be a string"
            )));
        };

        let node_def = if let yaml_rust::Yaml::String(include_path) = node_def {
            let mut buf = path.parent().unwrap().to_path_buf();
            buf.push(include_path);
            let path = buf.as_path();
            let yaml_str =
                std::fs::read_to_string(&path).expect(&format!("Failed to read {path:?}"));
            let docs = yaml_rust::yaml::YamlLoader::load_from_str(&yaml_str).unwrap();
            let doc = &docs[0];
            doc.clone()
        } else {
            node_def.clone()
        };
        parse_node(name, &node_def, network_builder)?;
    }

    if !yaml["struct_types"].is_null() && !yaml["struct_types"].is_badvalue() {
        let structs_map = if let yaml_rust::Yaml::String(include_path) = &yaml["struct_types"] {
            let mut buf = path.parent().unwrap().to_path_buf();
            buf.push(include_path);
            let path = buf.as_path();
            let yaml_str =
                std::fs::read_to_string(&path).expect(&format!("Failed to read {path:?}"));
            let docs = yaml_rust::yaml::YamlLoader::load_from_str(&yaml_str).unwrap();
            let doc = &docs[0];
            doc.as_hash().unwrap().clone()
        } else {
            let yaml_rust::Yaml::Hash(structs_map) = &yaml["struct_types"] else {
                return Err(Error::YamlInvalidType(format!(
                    "enums must be given as a map"
                )));
            };
            structs_map.clone()
        };

        for (name, struct_map) in &structs_map {
            let yaml_rust::Yaml::String(struct_name) = name else {
                return Err(Error::YamlInvalidType(format!(
                    "struct names must be primitive string keys"
                )));
            };

            parse_struct_type(struct_map, &mut network_builder.define_struct(struct_name))?;
        }
    }

    if !yaml["enum_types"].is_null() && !yaml["enum_types"].is_badvalue() {
        let enums_map = if let yaml_rust::Yaml::String(include_path) = &yaml["enum_types"] {
            let mut buf = path.parent().unwrap().to_path_buf();
            buf.push(include_path);
            let path = buf.as_path();
            let yaml_str =
                std::fs::read_to_string(&path).expect(&format!("Failed to read {path:?}"));
            let docs = yaml_rust::yaml::YamlLoader::load_from_str(&yaml_str).unwrap();
            let doc = &docs[0];
            doc.as_hash().unwrap().clone()
        } else {
            let yaml_rust::Yaml::Hash(enums_map) = &yaml["enum_types"] else {
                return Err(Error::YamlInvalidType(format!(
                    "enums must be given as a map"
                )));
            };
            enums_map.clone()
        };

        for (name, enum_map) in &enums_map {
            let yaml_rust::Yaml::String(enum_name) = name else {
                return Err(Error::YamlInvalidType(format!(
                    "struct names must be primitive string keys"
                )));
            };

            parse_enum_type(enum_map, &mut network_builder.define_enum(enum_name))?;
        }
    }

    let bus_map = if let yaml_rust::Yaml::String(include_path) = &yaml["buses"] {
        let mut buf = path.parent().unwrap().to_path_buf();
        buf.push(include_path);
        let path = buf.as_path();
        let yaml_str = std::fs::read_to_string(&path).expect(&format!("Failed to read {path:?}"));
        let docs = yaml_rust::yaml::YamlLoader::load_from_str(&yaml_str).unwrap();
        let doc = &docs[0];
        doc.as_hash().unwrap().clone()
    } else {
        let yaml_rust::Yaml::Hash(buses) = &yaml["buses"] else {
            return Err(Error::YamlInvalidType(format!(
                "enums must be given as a map"
            )));
        };
        buses.clone()
    };

    for (name, bus_map) in &bus_map {
        let yaml_rust::Yaml::String(bus_name) = name else {
            return Err(Error::YamlInvalidType(format!(
                "bus names must be primitive string keys"
            )));
        };

        parse_bus(
            &network_builder,
            bus_map,
            &mut network_builder.create_bus(bus_name, None),
        )?;
    }

    // all nodes are connected to all buses!!
    let node_builders = network_builder.0.borrow().nodes.clone();
    let bus_builders = network_builder.0.borrow().buses.clone();
    for node_builder in node_builders.borrow().iter() {
        for bus_builder in bus_builders.borrow().iter() {
            node_builder.assign_bus(&bus_builder.0.borrow().name);
        }
    }

    Ok(())
}

pub fn parse_included_files(yaml: &yaml_rust::yaml::Yaml, path: &Path) -> Result<Vec<PathBuf>> {
    let mut paths = vec![];

    let yaml_rust::Yaml::Hash(_) = yaml else {
        return Err(Error::YamlInvalidFormat(format!("")));
    };

    let nodes_map = if let yaml_rust::Yaml::String(include_path) = &yaml["nodes"] {
        let mut buf = path.parent().unwrap().to_path_buf();
        buf.push(include_path);
        let path = buf.as_path();
        paths.push(path.to_path_buf());
        let yaml_str = std::fs::read_to_string(&path).expect(&format!("Failed to read {path:?}"));
        let docs = yaml_rust::yaml::YamlLoader::load_from_str(&yaml_str).unwrap();
        let doc = &docs[0];
        doc.as_hash().unwrap().clone()
    } else {
        let yaml_rust::Yaml::Hash(nodes_map) = &yaml["nodes"] else {
            return Err(Error::YamlInvalidType(format!(
                "enums must be given as a map"
            )));
        };
        nodes_map.clone()
    };

    for (_, node_def) in &nodes_map {
        if let yaml_rust::Yaml::String(include_path) = node_def {
            let mut buf = path.parent().unwrap().to_path_buf();
            buf.push(include_path);
            let path = buf.as_path();
            paths.push(path.to_path_buf());
        };
    }

    if !yaml["struct_types"].is_null() && !yaml["struct_types"].is_badvalue() {
        if let yaml_rust::Yaml::String(include_path) = &yaml["struct_types"] {
            let mut buf = path.parent().unwrap().to_path_buf();
            buf.push(include_path);
            let path = buf.as_path();
            paths.push(path.to_path_buf());
        };
    }

    if !yaml["enum_types"].is_null() && !yaml["enum_types"].is_badvalue() {
        if let yaml_rust::Yaml::String(include_path) = &yaml["enum_types"] {
            let mut buf = path.parent().unwrap().to_path_buf();
            buf.push(include_path);
            let path = buf.as_path();
            paths.push(path.to_path_buf());
        };
    }

    if let yaml_rust::Yaml::String(include_path) = &yaml["buses"] {
        let mut buf = path.parent().unwrap().to_path_buf();
        buf.push(include_path);
        let path = buf.as_path();
        paths.push(path.to_path_buf());
    };

    Ok(paths)
}
