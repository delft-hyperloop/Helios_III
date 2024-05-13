use crate::commands::Config;
use crate::commands::Command;

pub fn generate_tauri_commands(path: &str) -> String {
    let config: Config = toml::from_str(path).unwrap();
    let mut out = String::new();
    for cmd in config.Command {
        format!("
#[tauri::command]
pub fn {}(msg: String) {{
                match msg {{
                    Data(dp) => {}
                }}
            }}
            ", cmd.name, "yo")
    }

    out
}

