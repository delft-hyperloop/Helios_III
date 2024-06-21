use std::path::{Path, PathBuf};

use canzero_config::config::NetworkRef;
use serde::{Deserialize, Serialize};

pub type Result<T> = std::result::Result<T, AppDataError>;

#[derive(Debug)]
pub enum AppDataError {
    BrokenConfig,
    InvalidConfigPath,
    Io(std::io::Error),
    ConfigError(canzero_yaml::errors::Error),
}

impl From<canzero_yaml::errors::Error> for AppDataError {
    fn from(value: canzero_yaml::errors::Error) -> Self {
        AppDataError::ConfigError(value)
    }
}

impl From<std::io::Error> for AppDataError {
    fn from(value: std::io::Error) -> Self {
        AppDataError::Io(value)
    }
}

#[derive(Serialize, Deserialize, Clone, PartialEq, Copy, Debug)]
pub enum WdgLevel {
    Disable,
    Ignore,
    Active
}

#[derive(Clone)]
pub struct AppData {
    config_change_flag: bool,
    config: AppDataConfig,
}

#[derive(Clone, Serialize, Deserialize)]
#[serde(rename_all = "camelCase")]
pub struct AppDataConfig {
    config_path: Option<PathBuf>,
    frontend_wdg_lvl: WdgLevel,
    deadlock_wdg_lvl: WdgLevel,
}


impl AppData {
    pub fn read() -> Result<Self> {
        let appdata_path = Self::appdata_path();
        if appdata_path.exists() {
            let appdata_toml = std::fs::read_to_string(appdata_path)?;
            let appdata_raw = toml::from_str::<AppDataConfig>(&appdata_toml).map_err(|err| {
                eprintln!("{err:?}");
                AppDataError::BrokenConfig
            })?;
            Ok(AppData {
                config_change_flag: false,
                config: appdata_raw,
            })
        } else {
            Ok(Self::default())
        }
    }

    pub fn get_config(&self) -> &AppDataConfig {
       &self.config 
    }

    pub fn dir() -> PathBuf {
        let mut appdata_path = dirs::home_dir().expect("No home directory avaiable on the OS");
        appdata_path.push(".canzero");
        appdata_path
    }

    pub fn set_config_path(&mut self, path: Option<PathBuf>) -> Result<()> {
        let new_config_path = match path {
            Some(path) => Some(std::fs::canonicalize(path)?),
            None => None,
        };
        if let Some(config_path) = new_config_path.clone() {
            if config_path.is_dir() {
                return Err(AppDataError::InvalidConfigPath);
            }
        }
        if new_config_path != self.config.config_path {
            self.config.config_path = new_config_path;
            self.config_change_flag = true;
        }
        Ok(())
    }

    pub fn set_frontend_wdg_lvl(&mut self, lvl: WdgLevel) {
        if self.get_frontend_wdg_lvl() != lvl {
            self.config.frontend_wdg_lvl = lvl;
            self.config_change_flag = true;
        }
    }

    pub fn set_deadlock_wdg_lvl(&mut self, lvl: WdgLevel) {
        if self.get_deadlock_wdg_lvl() != lvl {
            self.config.deadlock_wdg_lvl = lvl;
            self.config_change_flag = true;
        }
    }

    pub fn get_config_path(&self) -> Option<&PathBuf> {
        self.config.config_path.as_ref()
    }

    pub fn get_frontend_wdg_lvl(&self) -> WdgLevel {
        self.config.frontend_wdg_lvl
    }

    pub fn get_deadlock_wdg_lvl(&self) -> WdgLevel {
        self.config.deadlock_wdg_lvl
    }

    fn appdata_path() -> PathBuf {
        let mut appdata_path = dirs::home_dir().expect("No home directory avaiable on the OS");
        appdata_path.push(".canzero");
        appdata_path.push("canzero.toml");
        appdata_path
    }

    fn rec_create_directories(dir: &Path) -> Result<()> {
        if !dir.exists() {
            if let Some(parent) = dir.parent() {
                Self::rec_create_directories(parent)?;
            }
            std::fs::create_dir(dir)?;
        }
        Ok(())
    }

    pub fn config(&self) -> Result<NetworkRef> {
        match self.get_config_path() {
            Some(path) => canzero_yaml::parse_yaml_config_from_file(
                path.to_str()
                    .expect("non utf file paths are not supported by CANzero"),
            )
            .map_err(|err| AppDataError::ConfigError(err)),
            None => Err(canzero_yaml::errors::Error::Io(std::io::Error::new(
                std::io::ErrorKind::NotFound,
                "No config file specified".to_owned(),
            ))
            .into()),
        }
    }

    pub fn config_files(&self) -> Result<Vec<PathBuf>> {
        match self.get_config_path() {
            Some(path) => canzero_yaml::parse_yaml_config_files_from_file(
                path.to_str()
                    .expect("non utf file paths are not supported by CANzero"),
            )
            .map_err(|err| AppDataError::ConfigError(err)),
            None => Err(canzero_yaml::errors::Error::Io(std::io::Error::new(
                std::io::ErrorKind::NotFound,
                "No config file specified".to_owned(),
            ))
            .into()),
        }
    }
}

impl Drop for AppData {
    fn drop(&mut self) {
        if self.config_change_flag {
            let appdata_path = Self::appdata_path();
            if let Some(parent) = appdata_path.parent() {
                Self::rec_create_directories(parent)
                    .expect(&format!("Failed to create config directories {parent:?}"));
            }
            let appdata_toml = toml::to_string_pretty(&self.config).unwrap();
            std::fs::write(appdata_path.clone(), &appdata_toml)
                .expect(&format!("Failed to write to {appdata_path:?}"));
        }
    }
}

impl Default for AppData {
    fn default() -> Self {
        Self {
            config_change_flag: false,
            config: AppDataConfig {
                config_path: None,
                deadlock_wdg_lvl: WdgLevel::Active,
                frontend_wdg_lvl: WdgLevel::Active,
            },
        }
    }
}
