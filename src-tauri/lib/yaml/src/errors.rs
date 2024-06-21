
pub type Result<T> = std::result::Result<T, Error>;

#[derive(Debug)]
pub enum Error {
    YamlScanError(yaml_rust::ScanError),
    YamlInvalidFormat(String),
    YamlInvalidType(String),
    ConfigError(canzero_config::errors::ConfigError),
    Io(std::io::Error),
}

impl From<yaml_rust::ScanError> for Error {
    fn from(value: yaml_rust::ScanError) -> Self {
        Error::YamlScanError(value)
    }
}

impl From<canzero_config::errors::ConfigError> for Error {
    fn from(value: canzero_config::errors::ConfigError) -> Self {
        Error::ConfigError(value)
    }
}

impl From<std::io::Error> for Error {
    fn from(value: std::io::Error) -> Self {
        Error::Io(value)
    }
}
