
pub type Result<T> = std::result::Result<T, ConfigError>;

#[derive(Debug)]
pub enum ConfigError {
    InvalidRange(String),
    InvalidType(String),
    DuplicatedSignal(String),
    DuplicatedEnumEntry(String),
    DuplicatedStructAttribute(String),
    UndefinedType(String),
    InvalidDecimalDefinition(String),
    FailedToResolveId,
    NoBusAvaiable,
    Io(std::io::Error),
    CanDbc(String),
}

impl From<std::io::Error> for ConfigError {
    fn from(value: std::io::Error) -> Self {
        ConfigError::Io(value)
    }
}

impl<'a> From<can_dbc::Error<'a>> for ConfigError {
    fn from(value: can_dbc::Error) -> Self {
        ConfigError::CanDbc(format!("{value:?}"))
    }
}

