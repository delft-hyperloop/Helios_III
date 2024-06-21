use std::{
    cell::{OnceCell, RefCell},
    cmp::Ordering,
    time::Duration,
};

use regex::Regex;

use crate::{
    builder::message_resolution::resolve_ids_filters_and_buses,
    config::{
        self,
        bus::BusRef,
        encoding::{CompositeSignalEncoding, PrimitiveSignalEncoding},
        make_config_ref,
        message::MessageUsage,
        signal::Signal,
        stream::Stream,
        Command, ConfigRef, Message, MessageEncoding, MessageId, Network, NetworkRef, Node,
        ObjectEntry, SignalRef, SignalType, Type, TypeRef, TypeSignalEncoding,
    },
    errors::Result,
    errors::{self},
};

use super::{
    bus::BusBuilder, import_dbc::import_dbc, make_builder_ref, message_builder::MessageIdTemplate,
    BuilderRef, EnumBuilder, MessageBuilder, MessageFormat, MessagePriority, NodeBuilder,
    StructBuilder, TypeBuilder,
};

#[derive(Debug, Clone)]
pub struct NetworkBuilder(pub BuilderRef<NetworkData>);

#[derive(Debug)]
pub struct NetworkData {
    pub messages: BuilderRef<Vec<MessageBuilder>>,
    pub types: BuilderRef<Vec<TypeBuilder>>,
    pub nodes: BuilderRef<Vec<NodeBuilder>>,
    pub get_req_message: OnceCell<MessageBuilder>,
    pub get_resp_message: OnceCell<MessageBuilder>,
    pub set_req_message: OnceCell<MessageBuilder>,
    pub set_resp_message: OnceCell<MessageBuilder>,
    pub buses: BuilderRef<Vec<BusBuilder>>,
}

impl NetworkBuilder {
    pub fn new() -> NetworkBuilder {
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Create Network");
        let network_builder = NetworkBuilder(make_builder_ref(NetworkData {
            messages: make_builder_ref(vec![]),
            types: make_builder_ref(vec![]),
            nodes: make_builder_ref(vec![]),
            get_req_message: OnceCell::new(),
            get_resp_message: OnceCell::new(),
            set_req_message: OnceCell::new(),
            set_resp_message: OnceCell::new(),
            buses: make_builder_ref(vec![]),
        }));

        let client_id_name = "client_id";
        let server_id_name = "server_id";
        let oe_index_name = "od_index";
        let sof_name = "sof";
        let eof_name = "eof";
        let toggle_name = "toggle";

        let get_resp_erno = network_builder.define_enum("get_resp_erno");
        get_resp_erno.add_entry("Success", Some(0)).unwrap();
        get_resp_erno.add_entry("Error", Some(1)).unwrap();

        let set_resp_erno = network_builder.define_enum("set_resp_erno");
        set_resp_erno.add_entry("Success", Some(0)).unwrap();
        set_resp_erno.add_entry("Error", Some(1)).unwrap();

        let get_req_message = network_builder.create_message("get_req", None);
        get_req_message.set_any_std_id(MessagePriority::Low);
        get_req_message.__assign_to_configuration();
        let get_req_format = get_req_message.make_type_format();
        let get_req_header = network_builder.define_struct("get_req_header");
        get_req_header.add_attribute(oe_index_name, "u13").unwrap();
        get_req_header.add_attribute(client_id_name, "u8").unwrap();
        get_req_header.add_attribute(server_id_name, "u8").unwrap();
        get_req_format.add_type("get_req_header", "header");
        network_builder
            .0
            .borrow_mut()
            .get_req_message
            .set(get_req_message)
            .unwrap();

        let get_resp_message = network_builder.create_message("get_resp", None);
        get_resp_message.set_any_std_id(MessagePriority::Low);
        get_resp_message.__assign_to_configuration();
        let get_resp_format = get_resp_message.make_type_format();
        let get_resp_header = network_builder.define_struct("get_resp_header");
        get_resp_header.add_attribute(sof_name, "u1").unwrap();
        get_resp_header.add_attribute(eof_name, "u1").unwrap();
        get_resp_header.add_attribute(toggle_name, "u1").unwrap();
        get_resp_header.add_attribute(oe_index_name, "u13").unwrap();
        get_resp_header.add_attribute(client_id_name, "u8").unwrap();
        get_resp_header.add_attribute(server_id_name, "u8").unwrap();
        get_resp_format.add_type("get_resp_header", "header");
        get_resp_format.add_type("u32", "data");
        network_builder
            .0
            .borrow_mut()
            .get_resp_message
            .set(get_resp_message)
            .unwrap();

        let set_req_message = network_builder.create_message("set_req", None);
        set_req_message.set_any_std_id(MessagePriority::Low);
        set_req_message.__assign_to_configuration();
        let set_req_format = set_req_message.make_type_format();
        let set_req_header = network_builder.define_struct("set_req_header");
        set_req_header.add_attribute(sof_name, "u1").unwrap();
        set_req_header.add_attribute(eof_name, "u1").unwrap();
        set_req_header.add_attribute(toggle_name, "u1").unwrap();
        set_req_header.add_attribute(oe_index_name, "u13").unwrap();
        set_req_header.add_attribute(client_id_name, "u8").unwrap();
        set_req_header.add_attribute(server_id_name, "u8").unwrap();
        set_req_format.add_type("set_req_header", "header");
        set_req_format.add_type("u32", "data");
        network_builder
            .0
            .borrow_mut()
            .set_req_message
            .set(set_req_message)
            .unwrap();

        let set_resp_message = network_builder.create_message("set_resp", None);
        set_resp_message.set_any_std_id(MessagePriority::Low);
        set_resp_message.__assign_to_configuration();
        let set_resp_format = set_resp_message.make_type_format();
        let set_resp_header = network_builder.define_struct("set_resp_header");
        set_resp_header.add_attribute(oe_index_name, "u13").unwrap();
        set_resp_header.add_attribute(client_id_name, "u8").unwrap();
        set_resp_header.add_attribute(server_id_name, "u8").unwrap();
        set_resp_header
            .add_attribute("erno", "set_resp_erno")
            .unwrap();
        set_resp_format.add_type("set_resp_header", "header");
        network_builder
            .0
            .borrow_mut()
            .set_resp_message
            .set(set_resp_message)
            .unwrap();

        let command_resp = network_builder.define_enum("command_resp_erno");
        command_resp.add_entry("Success", Some(0)).unwrap();
        command_resp.add_entry("Error", Some(1)).unwrap();

        let date_struct = network_builder.define_struct("date_time");
        date_struct.add_attribute("year", "u16").unwrap();
        date_struct.add_attribute("month", "u8").unwrap();
        date_struct.add_attribute("day", "u8").unwrap();
        date_struct.add_attribute("hour", "u8").unwrap();
        date_struct.add_attribute("min", "u8").unwrap();
        date_struct.add_attribute("sec", "u8").unwrap();



        network_builder
    }

    pub fn include_dbc(&self, bus: &str, dbc_path: &str) -> Result<()> {
        import_dbc(self, bus, dbc_path)
    }

    pub fn create_bus(&self, name: &str, baudrate: Option<u32>) -> BusBuilder {
        let network_data = self.0.borrow_mut();
        let id = network_data.buses.borrow().len();
        let bus = BusBuilder::new(name, id as u32, baudrate);
        network_data.buses.borrow_mut().push(bus.clone());
        bus
    }

    pub fn create_message(
        &self,
        name: &str,
        expected_interval: Option<Duration>,
    ) -> MessageBuilder {
        let network_data = self.0.borrow();
        let message_builder = MessageBuilder::new(name, &self, expected_interval);
        network_data
            .messages
            .borrow_mut()
            .push(message_builder.clone());
        message_builder
    }
    pub fn define_enum(&self, name: &str) -> EnumBuilder {
        let network_data = self.0.borrow();
        let type_builder = EnumBuilder::new(name);
        network_data
            .types
            .borrow_mut()
            .push(TypeBuilder::Enum(type_builder.clone()));
        type_builder
    }
    pub fn define_struct(&self, name: &str) -> StructBuilder {
        let network_data = self.0.borrow();
        let type_builder = StructBuilder::new(name);
        network_data
            .types
            .borrow_mut()
            .push(TypeBuilder::Struct(type_builder.clone()));
        type_builder
    }
    pub fn create_node(&self, name: &str) -> NodeBuilder {
        let network_data = self.0.borrow();
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::construct] Require node {name}");
        // check if node already exists.
        let existing_node = network_data
            .nodes
            .borrow()
            .iter()
            .find(|n| n.0.borrow().name == name)
            .map(NodeBuilder::to_owned);
        let Some(node) = existing_node else {
            let node_builder = NodeBuilder::new(name, &self);
            network_data.nodes.borrow_mut().push(node_builder.clone());
            return node_builder;
        };
        node
    }

    pub fn _get_req_message(&self) -> MessageBuilder {
        self.0.borrow().get_req_message.get().unwrap().clone()
    }

    pub fn _get_resp_message(&self) -> MessageBuilder {
        self.0.borrow().get_resp_message.get().unwrap().clone()
    }

    pub fn _set_req_message(&self) -> MessageBuilder {
        self.0.borrow().set_req_message.get().unwrap().clone()
    }

    pub fn _set_resp_message(&self) -> MessageBuilder {
        self.0.borrow().set_resp_message.get().unwrap().clone()
    }
}

impl NetworkBuilder {
    pub fn resolve_type(
        defined_types: &Vec<TypeRef>,
        type_name: &str,
    ) -> errors::Result<ConfigRef<Type>> {
        let int_regex = regex::Regex::new(r#"^i(?<size>[0-9]{1,2})$"#).unwrap();
        match int_regex.captures(type_name) {
            Some(cap) => {
                let size = &cap["size"];
                let size = size.parse::<u8>().unwrap();
                if size > 0 && size <= 64 {
                    return Ok(make_config_ref(Type::Primitive(SignalType::SignedInt {
                        size,
                    })));
                }
            }
            None => (),
        }
        let uint_regex = regex::Regex::new(r#"^u(?<size>[0-9]{1,2})$"#).unwrap();
        match uint_regex.captures(type_name) {
            Some(cap) => {
                let size = &cap["size"];
                let size = size.parse::<u8>().unwrap();
                if size > 0 && size <= 64 {
                    return Ok(make_config_ref(Type::Primitive(SignalType::UnsignedInt {
                        size,
                    })));
                }
            }
            None => (),
        }
        let dec_regex = regex::Regex::new(r"^d(?<size>[0-9]{1,2})<(?<min>[+-]?([0-9]*[.])?[0-9]+)\.\.(?<max>[+-]?([0-9]*[.])?[0-9]+)>$").unwrap();
        match dec_regex.captures(type_name) {
            Some(cap) => {
                let size = &cap["size"];
                let size = size.parse::<u8>().unwrap();
                let min = &cap["min"];
                let min = min.parse::<f64>().unwrap();
                let max = &cap["max"];
                let max = max.parse::<f64>().unwrap();
                if min >= max {
                    return Err(errors::ConfigError::InvalidRange(
                        "invalid decimal range min has to be less than max".to_owned(),
                    ));
                }
                let range = max - min;
                let scale = range / ((0xFFFFFFFFFFFFFFFF as u64 >> (64 - size)) as f64);
                let offset = min;
                if size <= 64 {
                    return Ok(make_config_ref(Type::Primitive(SignalType::Decimal {
                        size,
                        offset,
                        scale,
                    })));
                }
            }
            None => (),
        }
        let array_regex =
                regex::Regex::new(r#"^(?<type>[a-zA-Z][a-zA-Z0-9]*(<[+-]?([0-9]*[.])?[0-9]+\.\.[+-]?([0-9]*[.])?[0-9]+>)?)\[(?<len>[0-9]+)\]$"#).unwrap();
        match array_regex.captures(type_name) {
            Some(cap) => {
                let len = &cap["len"];
                let len = len.parse::<usize>().unwrap();
                let ty = &cap["type"];
                let inner_type = Self::resolve_type(defined_types, ty)?;
                return Ok(make_config_ref(Type::Array {
                    len,
                    ty: inner_type,
                }));
            }
            None => (),
        }
        for ty in defined_types {
            match ty as &Type {
                Type::Struct {
                    name,
                    description: _,
                    attribs: _,
                    visibility: _,
                } if name == type_name => return Ok(ty.clone()),
                Type::Enum {
                    name,
                    description: _,
                    size: _,
                    entries: _,
                    visibility: _,
                } if name == type_name => return Ok(ty.clone()),
                _ => (),
            }
        }
        return Err(errors::ConfigError::InvalidType(format!(
            "failed to resolve type : {type_name:?}"
        )));
    }

    fn topo_sort_types(types: &Vec<TypeRef>) -> Vec<TypeRef> {
        let n = types.len();
        struct Node {
            // index: usize,
            adj_list: Vec<usize>,
        }
        let mut nodes: Vec<Node> = vec![];
        for i in 0..n {
            let ty = &types[i];
            let mut adj_list = vec![];
            match ty as &Type {
                Type::Struct {
                    name: _,
                    description: _,
                    attribs,
                    visibility: _,
                } => {
                    for (_, attrib_type) in attribs {
                        match types.iter().position(|t| t == attrib_type) {
                            Some(adj) => adj_list.push(adj),
                            None => (),
                        }
                    }
                }
                Type::Array { len: _, ty } => match types.iter().position(|t| t == ty) {
                    Some(adj) => adj_list.push(adj),
                    None => (),
                },
                _ => (),
            }
            nodes.push(Node {
                // index: i,
                adj_list,
            })
        }
        let mut stack: Vec<usize> = vec![];
        let mut visited = vec![false; nodes.len()];
        fn topo_sort_rec(
            nodes: &Vec<Node>,
            visited: &mut Vec<bool>,
            current: usize,
            stack: &mut Vec<usize>,
        ) {
            visited[current] = true;
            for adj_index in &nodes[current].adj_list {
                if !visited[*adj_index] {
                    topo_sort_rec(nodes, visited, *adj_index, stack);
                }
            }
            stack.push(current);
        }
        for i in 0..n {
            if !visited[i] {
                topo_sort_rec(&nodes, &mut visited, i, &mut stack);
            }
        }

        stack.iter().map(|index| types[*index].clone()).collect()
    }

    fn topo_sort_type_builders(
        type_builders: &Vec<TypeBuilder>,
    ) -> errors::Result<Vec<TypeBuilder>> {
        // TODO check for cycles in the graph
        // number of nodes
        let n = type_builders.len();

        #[derive(Debug)]
        struct Node {
            // index: usize,
            adj_list: Vec<usize>,
        }

        let mut nodes: Vec<Node> = vec![];
        for node_index in 0..n {
            let adj_list = match &type_builders[node_index] {
                TypeBuilder::Enum(_) => vec![],
                TypeBuilder::Struct(struct_builder) => {
                    let struct_data = struct_builder.0.borrow();
                    let mut dependencies = vec![];
                    for (_, attrib_type_name) in &struct_data.attributes {
                        //check if type is a inplace definition (u?, i?, d?)
                        let is_inplace = Self::resolve_type(&vec![], attrib_type_name).is_ok();
                        if is_inplace {
                            continue;
                        }
                        let opt = type_builders
                            .iter()
                            .position(|builder| &builder.name() == attrib_type_name);
                        match opt {
                            Some(adj_index) => {
                                dependencies.push(adj_index);
                            }
                            None => {
                                return Err(errors::ConfigError::UndefinedType(format!(
                                    "{attrib_type_name}"
                                )))
                            }
                        }
                    }
                    dependencies
                }
            };
            nodes.push(Node {
                // index: node_index,
                adj_list,
            });
        }

        let mut stack: Vec<usize> = vec![];
        let mut visited = vec![false; nodes.len()];
        fn topo_sort_rec(
            nodes: &Vec<Node>,
            visited: &mut Vec<bool>,
            current: usize,
            stack: &mut Vec<usize>,
        ) {
            visited[current] = true;
            for adj_index in &nodes[current].adj_list {
                if !visited[*adj_index] {
                    topo_sort_rec(nodes, visited, *adj_index, stack);
                }
            }
            stack.push(current);
        }
        for i in 0..n {
            if !visited[i] {
                topo_sort_rec(&nodes, &mut visited, i, &mut stack);
            }
        }
        Ok(stack
            .iter()
            .map(|index| type_builders[*index].clone())
            .collect())
    }

    pub fn build(self) -> errors::Result<NetworkRef> {
        if self.0.borrow().buses.borrow().is_empty() {
            // ensure that there is always at least one bus defined!
            self.create_bus("can0", None);
            #[cfg(feature = "logging_info")]
            println!("[CANZERO-CONFIG::build] Implicitly added can0 as the only bus");
        }
        let builder = self.0.borrow();

        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::build] Building buses");
        let buses: Vec<BusRef> = builder
            .buses
            .borrow()
            .iter()
            .map(|bus_builder| {
                let bus_data = bus_builder.0.borrow();
                make_config_ref(config::bus::Bus::new(
                    &bus_data.name,
                    bus_data.id,
                    bus_data.baudrate,
                ))
            })
            .collect();

        // Generate Heartbeat messages!
        let enum_node_id = self.define_enum("node_id");
        let mut node_id = 0;
        for node_builder in self.0.borrow().nodes.borrow().iter() {
            let node_name = node_builder.0.borrow().name.clone();
            enum_node_id.add_entry(&node_name, Some(node_id))?;
            node_id += 1;
        }
        enum_node_id.add_entry("count", Some(node_id))?;
        drop(builder);

        for bus in buses.iter() {
            let heartbeat_message = self.create_message(
                &format!("heartbeat_{}", bus.name()), 
                Some(Duration::from_millis(100)));
            heartbeat_message.assign_bus(bus.name());
            heartbeat_message.__assign_to_heartbeat();
            heartbeat_message.set_any_std_id(MessagePriority::SuperLow);
            let heartbeat_message_format = heartbeat_message.make_type_format();
            heartbeat_message_format.add_type("u8", "node_id");
            heartbeat_message_format.add_type("u1", "unregister");
            heartbeat_message_format.add_type("u7", "ticks_next");
            for node_builder in self.0.borrow().nodes.borrow().iter() {
                node_builder.add_tx_message(&heartbeat_message);
                node_builder.add_rx_message(&heartbeat_message);
            }
        }
        let builder = self.0.borrow();


        // sort types in topological order!
        let type_builders = Self::topo_sort_type_builders(&builder.types.borrow())?;

        // define types.
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::build] Building Types");
        let mut types = vec![];
        for type_builder in type_builders.iter() {
            let type_ref: TypeRef = match type_builder {
                TypeBuilder::Enum(enum_builder) => {
                    let enum_data = enum_builder.0.borrow();

                    let mut entries: Vec<(String, u64)> = vec![];
                    let mut max_entry = 0;
                    for (entry_name, opt_value) in &enum_data.entries {
                        match opt_value {
                            Some(explicit_value) => {
                                entries.push((entry_name.clone(), *explicit_value));
                                max_entry = max_entry.max(*explicit_value);
                            }
                            None => {
                                if !entries.is_empty() {
                                    max_entry += 1;
                                }
                                entries.push((entry_name.clone(), max_entry));
                            }
                        }
                    }

                    let size = if max_entry == 0 {
                        1
                    } else {
                        (max_entry as f64).log2().floor() as u8 + 1
                    };
                    make_config_ref(Type::Enum {
                        name: enum_data.name.clone(),
                        size,
                        description: enum_data.description.clone(),
                        entries,
                        visibility: enum_data.visibility.clone(),
                    })
                }
                TypeBuilder::Struct(struct_builder) => {
                    let struct_data = struct_builder.0.borrow();
                    let mut attribs = vec![];
                    for (name, type_name) in &struct_data.attributes {
                        // this call requires topological sort over dependencies
                        // otherwise a type could not be defined.
                        // This creates the restiction that the types
                        // are not defined recursivly which is probably
                        // a good restriction
                        let ty = Self::resolve_type(&types, type_name)?;
                        attribs.push((name.clone(), ty));
                    }
                    make_config_ref(Type::Struct {
                        name: struct_data.name.clone(),
                        description: struct_data.description.clone(),
                        attribs,
                        visibility: struct_data.visibility.clone(),
                    })
                }
            };
            types.push(type_ref);
        }

        let tmp_buses = builder.buses.borrow().clone();
        let tmp_messages = builder.messages.borrow().clone();
        // we have to drop builder before we assign ids, because the following
        // function might require a mutable reference to self for assigning ids
        // and buses!
        let nodes = builder.nodes.borrow().clone();
        drop(builder);
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::build] Resolving message ids and bus assignments");
        resolve_ids_filters_and_buses(&tmp_buses, &tmp_messages, &nodes, &types)?;
        let builder = self.0.borrow();

        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::build] Building messages");
        let mut messages = vec![];
        for message_builder in builder.messages.borrow().iter() {
            let message_data = message_builder.0.borrow();
            let id = match message_data.id {
                MessageIdTemplate::StdId(id) => MessageId::StandardId(id),
                MessageIdTemplate::ExtId(id) => MessageId::ExtendedId(id),
                MessageIdTemplate::AnyStd(_) => panic!("unresolved id"),
                MessageIdTemplate::AnyExt(_) => panic!("unresolved id"),
                MessageIdTemplate::AnyAny(_) => panic!("unresolved id"),
            };
            let (signals, encoding) = match &message_data.format {
                MessageFormat::Signals(signal_format_builder) => {
                    let mut offset: usize = 0;
                    let signal_format_data = signal_format_builder.0.borrow();
                    let mut signals = vec![];
                    for signal_data in signal_format_data.0.iter() {
                        signals.push(make_config_ref(Signal {
                            name: format!("{}_{}", message_data.name, signal_data.name),
                            offset,
                            ..signal_data.clone()
                        }));
                        offset += signal_data.size() as usize;
                    }
                    (signals, None)
                }
                MessageFormat::Types(type_format_builder) => {
                    let type_format_data = type_format_builder.0.borrow();
                    let mut attributes: Vec<TypeSignalEncoding> = vec![];
                    let mut signals = vec![];
                    let mut offset: usize = 0;

                    pub fn build_attribute(
                        ty: &TypeRef,
                        name: &str,
                        offset: &mut usize,
                        prefix: &str,
                        signals: &mut Vec<SignalRef>,
                    ) -> TypeSignalEncoding {
                        match ty as &Type {
                            Type::Primitive(signal_type) => {
                                let signal = make_config_ref(Signal::new(
                                    &format!("{prefix}_{name}"),
                                    None,
                                    signal_type.clone(),
                                    *offset,
                                ));
                                signals.push(signal.clone());
                                *offset += signal.size() as usize;
                                TypeSignalEncoding::Primitive(PrimitiveSignalEncoding::new(
                                    name.to_owned(),
                                    ty.clone(),
                                    signal,
                                ))
                            }
                            Type::Struct {
                                name: struct_name,
                                description: _,
                                attribs,
                                visibility: _,
                            } => {
                                let mut attributes = vec![];
                                for (attrib_name, attrib_type) in attribs {
                                    attributes.push(build_attribute(
                                        attrib_type,
                                        attrib_name,
                                        offset,
                                        &format!("{prefix}_{struct_name}"),
                                        signals,
                                    ));
                                }
                                TypeSignalEncoding::Composite(CompositeSignalEncoding::new(
                                    name.to_owned(),
                                    attributes,
                                    ty.clone(),
                                ))
                            }
                            Type::Enum {
                                name: enum_name,
                                description: _,
                                size,
                                entries: _,
                                visibility: _,
                            } => {
                                let size = *size;
                                let signal = make_config_ref(Signal::new(
                                    &format!("{prefix}_{enum_name}"),
                                    None,
                                    SignalType::UnsignedInt { size },
                                    *offset,
                                ));
                                signals.push(signal.clone());
                                *offset += signal.size() as usize;
                                TypeSignalEncoding::Primitive(PrimitiveSignalEncoding::new(
                                    name.to_owned(),
                                    ty.clone(),
                                    signal,
                                ))
                            }
                            Type::Array { len: _, ty: _ } => todo!(),
                        }
                    }

                    for (type_name, var_name) in &type_format_data.0 {
                        let type_ref = Self::resolve_type(&types, type_name)?;
                        attributes.push(build_attribute(
                            &type_ref,
                            var_name,
                            &mut offset,
                            &format!("value_name"),
                            &mut signals,
                        ));
                    }
                    let encoding = MessageEncoding::new(attributes);

                    (signals, Some(encoding))
                }
                MessageFormat::Empty => (vec![], None),
            };

            let mut max_bit = 0;
            for signal in &signals {
                let signal_max_bit = signal.byte_offset() + signal.size() as usize;
                max_bit = max_bit.max(signal_max_bit);
            }
            let dlc = ((max_bit + 8 - 1) / 8) as u8;

            let bus = buses
                .iter()
                .find(|bus| bus.id() == message_data.bus.clone().unwrap().0.borrow().id)
                .unwrap()
                .clone();

            messages.push(make_config_ref(Message::new(
                message_data.name.clone(),
                message_data.description.clone(),
                id,
                encoding,
                signals,
                message_data.visibility.clone(),
                dlc,
                bus,
            )));
        }
        let get_resp_message = messages
            .iter()
            .find(|m| m.name() == builder.get_resp_message.get().unwrap().0.borrow().name)
            .unwrap()
            .clone();
        get_resp_message.__set_usage(MessageUsage::GetResp);
        let get_req_message = messages
            .iter()
            .find(|m| m.name() == builder.get_req_message.get().unwrap().0.borrow().name)
            .unwrap()
            .clone();
        get_req_message.__set_usage(MessageUsage::GetReq);
        let set_resp_message = messages
            .iter()
            .find(|m| m.name() == builder.set_resp_message.get().unwrap().0.borrow().name)
            .unwrap()
            .clone();
        set_resp_message.__set_usage(MessageUsage::SetResp);
        let set_req_message = messages
            .iter()
            .find(|m| m.name() == builder.set_req_message.get().unwrap().0.borrow().name)
            .unwrap()
            .clone();
        set_req_message.__set_usage(MessageUsage::SetReq);
        let heartbeat_messages = messages
            .iter()
            .filter(|message| message.name().starts_with("heartbeat_"))
            .cloned()
            .collect::<Vec<config::MessageRef>>();
        for heartbeat_msg in heartbeat_messages.iter() {
            heartbeat_msg.__set_usage(MessageUsage::Heartbeat);
        }


        pub fn rec_type_acc(node_types: &mut Vec<TypeRef>, encoding: &TypeSignalEncoding) {
            match encoding {
                TypeSignalEncoding::Composite(composite) => {
                    if !node_types.contains(composite.ty()) {
                        node_types.push(composite.ty().clone());
                    }
                    for attribute in composite.attributes() {
                        rec_type_acc(node_types, attribute);
                    }
                }
                TypeSignalEncoding::Primitive(primitive) => match primitive.ty() as &Type {
                    Type::Primitive(_) => (),
                    Type::Struct {
                        name: _,
                        description: _,
                        attribs: _,
                        visibility: _,
                    } => panic!("not a primitive"),
                    Type::Enum {
                        name: _,
                        description: _,
                        size: _,
                        entries: _,
                        visibility: _,
                    } => {
                        if !node_types.contains(primitive.ty()) {
                            node_types.push(primitive.ty().clone());
                        }
                    }
                    Type::Array { len: _, ty: _ } => todo!(),
                },
            }
        }

        // add get and set req,resp to all nodes
        let n_nodes = builder.nodes.borrow().len();
        let node_id_type = types.iter().find(|&t| {
            match t as &Type {
                Type::Primitive(_) => return false,
                Type::Struct { .. } => return false,
                Type::Enum { name, .. } => return name == "node_id",
                Type::Array { .. } => return false,
            }
        }).expect("node_id enum is missing from types!").clone();

        let mut nodes = vec![];
        // first create messages with tx and rx messages.
        for node_builder in builder.nodes.borrow().iter() {
            let node_data = node_builder.0.borrow();

            let mut node_types = vec![];

            // node_id enum should be available on all nodes
            node_types.push(node_id_type.clone());

            #[cfg(feature = "logging_info")]
            println!(
                "[CANZERO-CONFIG::build] Collecting all messages received by node {}",
                &node_data.name
            );
            let mut rx_messages = vec![];
            for rx_message_builder in &node_data.rx_messages {
                let message_ref = messages
                    .iter()
                    .find(|m| m.name() == rx_message_builder.0.borrow().name)
                    .expect("invalid message_builder was probably not added to the network");

                match &message_ref.encoding() {
                    Some(encoding) => {
                        for attribute in encoding.attributes() {
                            rec_type_acc(&mut node_types, attribute);
                        }
                    }
                    None => (),
                }
                rx_messages.push(message_ref.clone());
            }
            #[cfg(feature = "logging_info")]
            println!(
                "[CANZERO-CONFIG::build] Collecting all messages transmitted by node {}",
                &node_data.name
            );
            let mut tx_messages = vec![];
            for tx_message_builder in &node_data.tx_messages {
                let message_ref = messages
                    .iter()
                    .find(|m| m.name() == tx_message_builder.0.borrow().name)
                    .expect("invalid message_builder was probably not added to the network");
                match &message_ref.encoding() {
                    Some(encoding) => {
                        for attribute in encoding.attributes() {
                            rec_type_acc(&mut node_types, attribute);
                        }
                    }
                    None => (),
                }
                tx_messages.push(message_ref.clone());
            }

            #[cfg(feature = "logging_info")]
            println!(
                "[CANZERO-CONFIG::build] Building all commands transmitted by node {}",
                &node_data.name
            );
            let mut commands: Vec<ConfigRef<Command>> = vec![];
            for tx_command_builder in &node_builder.0.borrow().commands {
                let command_data = tx_command_builder.0.borrow();
                let tx_message = messages
                    .iter()
                    .find(|m| m.name() == command_data.call_message.0.borrow().name)
                    .expect("invalid command builder tx_message wasn't added to the network")
                    .clone();
                let rx_message = messages
                    .iter()
                    .find(|m| m.name() == command_data.resp_message.0.borrow().name)
                    .expect("invalid command builder rx_message wasn't added to the network")
                    .clone();
                let command_ref = make_config_ref(Command::new(
                    command_data.name.clone(),
                    command_data.description.clone(),
                    tx_message.clone(),
                    rx_message.clone(),
                    command_data.visibility.clone(),
                    command_data.expected_interval.clone(),
                ));
                rx_message.__set_usage(MessageUsage::CommandResp(command_ref.clone()));
                tx_message.__set_usage(MessageUsage::CommandReq(command_ref.clone()));

                commands.push(command_ref);
            }

            #[cfg(feature = "logging_info")]
            println!(
                "[CANZERO-CONFIG::build] Building Object Entries of node {}",
                &node_data.name
            );
            let mut object_entries = vec![];
            let mut id_acc = 0;
            for object_entry_builder in &node_builder.0.borrow().object_entries {
                let object_entry_data = object_entry_builder.0.borrow();
                let ty = Self::resolve_type(&mut types, &object_entry_data.ty)?;
                fn rec_add_type(node_types: &mut Vec<TypeRef>, ty: &TypeRef) {
                    match ty as &Type {
                        Type::Primitive(_) => (),
                        Type::Struct {
                            name: _,
                            description: _,
                            attribs,
                            visibility: _,
                        } => {
                            if !node_types.contains(ty) {
                                node_types.push(ty.clone());
                            }
                            for (_, attrib_ty) in attribs {
                                rec_add_type(node_types, attrib_ty);
                            }
                        }
                        Type::Enum {
                            name: _,
                            description: _,
                            size: _,
                            entries: _,
                            visibility: _,
                        } => {
                            if !node_types.contains(ty) {
                                node_types.push(ty.clone());
                            }
                        }
                        Type::Array { len: _, ty: _ } => todo!(),
                    };
                }
                rec_add_type(&mut node_types, &ty);
                let id = id_acc;
                id_acc += 1;
                object_entries.push(make_config_ref(ObjectEntry::new(
                    object_entry_data.name.clone(),
                    object_entry_data.description.clone(),
                    object_entry_data.friend.clone(),
                    object_entry_data.unit.clone(),
                    id,
                    ty,
                    object_entry_data.access.clone(),
                    object_entry_data.visibility.clone(),
                )));
            }

            #[cfg(feature = "logging_info")]
            println!(
                "[CANZERO-CONFIG::build] Building streams transmitted by node {}",
                node_data.name
            );
            let mut tx_streams = vec![];
            for tx_stream in &node_builder.0.borrow().tx_streams {
                let stream_data = tx_stream.0.borrow();

                //resolve message
                let message = messages
                    .iter()
                    .find(|m| m.name() == stream_data.message.0.borrow().name)
                    .expect("stream message was not added to the network")
                    .clone();
                let mut mappings = vec![];
                for oe_builder in &stream_data.object_entries {
                    let oe_data = oe_builder.0.borrow();
                    let oe = object_entries
                        .iter()
                        .find(|oe| oe.name() == oe_data.name)
                        .expect("stream object entry wasn't added to the node")
                        .clone();
                    mappings.push(Some(oe));
                }

                let stream_ref = make_config_ref(Stream::new(
                    stream_data.name.clone(),
                    stream_data.description.clone(),
                    mappings,
                    message.clone(),
                    stream_data.visbility.clone(),
                    stream_data.interval,
                ));
                message.__set_usage(MessageUsage::Stream(stream_ref.clone()));
                tx_streams.push(stream_ref);
            }
            #[cfg(feature = "logging_info")]
            println!(
                "[CANZERO-CONFIG::build] Collected all types used by node {}",
                &node_data.name
            );

            #[cfg(feature = "logging_info")]
            println!(
                "[CANZERO-CONFIG::build] Sorting all types of {} in topological order",
                &node_data.name
            );
            let node_types = Self::topo_sort_types(&node_types);

            let node_buses = node_data
                .buses
                .iter()
                .map(|bus_builder| {
                    buses
                        .iter()
                        .find(|bus| bus.id() == bus_builder.0.borrow().id)
                        .unwrap()
                        .clone()
                })
                .collect();
            #[cfg(feature = "logging_info")]
            println!(
                "[CANZERO-CONFIG::build] Collecting all buses the node {} is connected to",
                node_data.name
            );

            #[cfg(feature = "logging_info")]
            println!(
                "[CANZERO-CONFIG::build] Successfully build transmitting part of node {}",
                node_data.name
            );
            nodes.push(RefCell::new(Node::new(
                node_data.name.clone(),
                node_data.description.clone(),
                nodes.len() as u8,
                node_types,
                commands,
                vec![],
                tx_streams,
                vec![],
                rx_messages,
                tx_messages,
                object_entries,
                node_buses,
            )));
        }

        // add extern commands to nodes
        // requires all nodes to be constructed beforehand.
        for i in 0..n_nodes {
            let node_builder = &builder.nodes.borrow()[i];
            let node_data = node_builder.0.borrow();
            #[cfg(feature = "logging_info")]
            println!(
                "[CANZERO-CONFIG::build] Linking Received command of node {}",
                node_data.name
            );
            for rx_command in &node_data.extern_commands {
                let rx_command_data = rx_command.0.borrow();
                'outer: for j in 0..n_nodes {
                    if i == j {
                        continue;
                    }
                    let other_node = nodes[j].borrow();
                    for tx_command in other_node.commands() {
                        if tx_command.tx_message().name()
                            == rx_command_data.call_message.0.borrow().name
                        {
                            nodes[i]
                                .borrow_mut()
                                .extern_commands_mut()
                                .push((other_node.name().to_owned(), tx_command.clone()));
                            break 'outer;
                        }
                    }
                }
            }
            #[cfg(feature = "logging_info")]
            println!(
                "[CANZERO-CONFIG::build] Linking Received streams to node {}",
                node_data.name
            );
            for rx_stream in &node_data.rx_streams {
                let rx_stream_data = rx_stream.0.borrow();
                let tx_stream_builder = rx_stream_data.stream_builder.clone();
                let tx_stream_data = tx_stream_builder.0.borrow();
                let tx_node_builder = tx_stream_data.tx_node.clone();
                let tx_node_data = tx_node_builder.0.borrow();
                // resolve node.
                let tx_node = nodes
                    .iter()
                    .find(|n| n.borrow().name() == tx_node_data.name)
                    .unwrap()
                    .borrow();
                let tx_stream = tx_node
                    .tx_streams()
                    .iter()
                    .find(|s| s.name() == tx_stream_data.name)
                    .unwrap()
                    .clone();

                let mut builder_mapping = rx_stream_data.object_entries.clone();
                builder_mapping.sort_by(|(i1, _), (i2, _)| {
                    if i1 < i2 {
                        Ordering::Less
                    } else if i1 == i2 {
                        Ordering::Equal
                    } else {
                        Ordering::Greater
                    }
                });
                let oe_count = builder_mapping.len();
                let mut mappings = vec![];
                let mut j = 0;
                let rx_node_data = rx_stream_data.rx_node.0.borrow();
                let rx_node = nodes
                    .iter()
                    .find(|n| n.borrow().name() == rx_node_data.name)
                    .unwrap()
                    .borrow();
                for i in 0..oe_count {
                    if builder_mapping[j].0 == i {
                        // search for object entry in rx_node
                        let oe = rx_node
                            .object_entries()
                            .iter()
                            .find(|oe| oe.name() == builder_mapping[j].1 .0.borrow().name)
                            .unwrap();
                        mappings.push(Some(oe.clone()));
                        j += 1;
                    } else {
                        // insert null mapping
                        mappings.push(None);
                    }
                }

                drop(tx_node);
                drop(rx_node);
                nodes[i]
                    .borrow_mut()
                    .rx_streams_mut()
                    .push(make_config_ref(Stream::new(
                        tx_stream.name().to_owned(),
                        tx_stream.description().map(|d| d.to_owned()),
                        mappings,
                        tx_stream.message().clone(),
                        rx_stream_data.visibility.clone(),
                        *tx_stream.interval(),
                    )));
            }
        }

        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::build] Successfully build all nodes");
        let nodes: Vec<ConfigRef<Node>> = nodes
            .into_iter()
            .map(|n| make_config_ref(n.into_inner()))
            .collect();

        // set node for all object entries!
        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::build] Linking Object Entries to nodes");
        for node in &nodes {
            for oe in node.object_entries() {
                oe.__set_node(node.clone());
            }
        }

        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::build] Finalizing usage of all messages");
        // set usage for all messages!
        for message in &messages {
            let once_cell = message.__get_usage();
            if once_cell.get().is_none() {
                let expected = builder
                    .messages
                    .borrow()
                    .iter()
                    .find(|m| &m.0.borrow().name == message.name())
                    .unwrap()
                    .0
                    .borrow()
                    .usage
                    .clone();
                let interval = match expected {
                    crate::builder::message_builder::MessageBuilderUsage::External { interval } => {
                        interval
                    }
                    crate::builder::message_builder::MessageBuilderUsage::Heartbeat => {
                        Some(Duration::from_millis(100))
                    }
                    _ => panic!(),
                }
                .unwrap_or(Duration::from_secs(60));

                once_cell.set(MessageUsage::External { interval }).unwrap();
            }
        }

        #[cfg(feature = "logging_info")]
        println!("[CANZERO-CONFIG::build] Successfully build configuration");
        let network_ref = make_config_ref(Network::new(
            chrono::Local::now(),
            nodes,
            messages,
            types,
            get_req_message,
            get_resp_message,
            set_req_message,
            set_resp_message,
            heartbeat_messages,
            buses,
        ));

        // SEMANTIC CHECKS!
        
        // check that all names are valid c/c++ variables
        let valid_c_var = Regex::new(r"^[a-zA-Z_]+[a-zA-Z0-9_]*$").unwrap();
        let is_c_keyword = Regex::new(r"^(restrict|alignas|alignof|and|and_eq|asm|atomic_cancel|atomic_commit|auto|bitand|bitor|bool|break|case|catch|char|char8_t|char16_t|char32_t|class|compl|concept|const|consteval|constexpr|constinit|const_cast|continue|co_await|co_return|co_yield|decltype|default|delete|do|double|dynamic_cast|else|enum|explicit|export|extern|false|float|for|friend|goto|if|inline|int|long|mutable|namespace|new|noexpect|not|not_eq|nullptr|operator|or|or_eq|private|protected|public|reflexpr|register|reinterpret_cast|require|return|short|signed|sizeof|static|static_assert|static_cast|struct|switch|synchronized|template|this|thread_local|throw|true|try|typedef|typeid|typename|union|unsigned|using|virtual|void|volatile|wchar_t|while|xor|xor_eq)$").unwrap();
        for node in network_ref.nodes() {
            let node_name = node.name();
            if !valid_c_var.is_match(node_name) || is_c_keyword.is_match(node_name) {
                panic!("{node_name} is not a valid node name.");
            }
            for stream in node.tx_streams() {
                let name = stream.name();
                if !valid_c_var.is_match(name) || is_c_keyword.is_match(name) {
                    panic!("{name} is not a valid stream name.");
                }
            }
            for oe in node.object_entries() {
                let name = oe.name();
                if !valid_c_var.is_match(name) || is_c_keyword.is_match(name) {
                    panic!("{name} is not a valid object entry name.");
                }
            }
            for cmd in node.commands() {
                let name = cmd.name();
                if !valid_c_var.is_match(name) || is_c_keyword.is_match(name) {
                    panic!("{name} is not a valid command name");
                }
            }
        }

        for bus in network_ref.buses() {
            let name = bus.name();
            if !valid_c_var.is_match(name) || is_c_keyword.is_match(name) {
                panic!("{name} is not a valid bus name");
            }
        }

        for message in network_ref.messages() {
            let dlc = message.dlc();
            let msg_name = message.name();

            if !valid_c_var.is_match(msg_name) || is_c_keyword.is_match(msg_name) {
                panic!("{msg_name} is not a valid name for a message.");
            }
            if dlc > 8 {
                panic!(
                    "All messages have to have a dlc less than 8. \n{msg_name} has dlc = {dlc}."
                );
            }

            if dlc == 0 {
                println!("WARN: message {msg_name} is empty");
            }
        }

        fn check_ty(ty: &Type, valid_c_var: &Regex, c_keyword: &Regex) {
            match &ty as &Type {
                Type::Primitive(_) => (),
                Type::Struct {
                    name,
                    description : _,
                    attribs,
                    visibility : _,
                } => {
                    if !valid_c_var.is_match(name) || c_keyword.is_match(name) {
                        panic!("{name} is not a valid name for a struct");
                    }
                    for (attrib_name, attrib_ty) in attribs {
                        if !valid_c_var.is_match(attrib_name) || c_keyword.is_match(attrib_name) {
                            panic!("{attrib_name} is not a valid attribute for a struct (in struct {name})");
                        }
                        check_ty(attrib_ty, valid_c_var, c_keyword)
                    }
                }
                Type::Enum {
                    name,
                    description : _,
                    size : _,
                    entries : _,
                    visibility : _,
                } => {
                    if !valid_c_var.is_match(name) || c_keyword.is_match(name) {
                        panic!("{name} is not a valid name for a struct");
                    }
                }
                Type::Array { len : _, ty } => check_ty(ty, valid_c_var, c_keyword),
            }
        }

        for ty in network_ref.types() {
            check_ty(ty, &valid_c_var, &is_c_keyword);
        }

        Ok(network_ref)
    }
}
