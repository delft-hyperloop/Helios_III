use crate::datatypes::Config;
use crate::datatypes::Datatype;

pub fn generate_tauri_emitters(path: &str) -> String {
    let config: Config = toml::from_str(path).unwrap();
    let mut datatype_matching = String::new();

    for dp in config.Datatype {
        datatype_matching.push_str(&format!("\
                    Datatype::{} => {{\
                        let dp = Datapoint::new(Datatype::{}, dp.value, dp.timestamp);\n\t\t\t\ttx.send(Message::Data(dp)).expect(\"Failed to send on msg tx\");\n\t\t\t}},\n", dp.name, dp.name));
    }

    format!("\
            match msg {{
                Data(dp) => {}
            }}
            ")
}