use canzero_config::config;

pub struct CommandObject {
    command_ref: config::CommandRef,
}

impl CommandObject {
    pub fn create(command_config: &config::CommandRef, _app_handle: &tauri::AppHandle) -> Self {
        Self {
            command_ref: command_config.clone(),
        }
    }
    pub fn name(&self) -> &str {
        self.command_ref.name()
    }
    pub fn description(&self) -> Option<&String> {
        self.command_ref.description()
    }

    #[allow(unused)] //FIXME
    pub fn build_invoke(&self) -> InvokeCommandBuilder {
        InvokeCommandBuilder::new(self)
    }

    pub async fn deadlock_watchdog(&self) {
        // pass
    }
}

pub struct InvokeCommandBuilder {
}

impl InvokeCommandBuilder {
    pub fn new(_command_object: &CommandObject) -> Self {
        InvokeCommandBuilder {
        }
    }
}


#[allow(unused)] //FIXME
enum CommandEvent {
    Resp,
    Req(u32),
    Timeout(u32),
}
