use std::fmt::Display;

use canzero_appdata::AppDataError;



pub type Result<T> = std::result::Result<T, Error>;

#[derive(Debug)]
pub enum Error {
    NoConfigSelected,
    FileNotFound(String),
    CodegenError(canzero_codegen::errors::Error),
    Io(std::io::Error),
    AppDataError(AppDataError),
    MissingDependency(String),
    InvalidResponse,
    InvalidNodeName(String),
    InvalidBusName(String),
    NoServerFound,
    NotYetImplemented,
}

impl From<AppDataError> for Error {
    fn from(value: AppDataError) -> Self {
        Error::AppDataError(value)
    }
}

impl From<std::io::Error> for Error {
    fn from(value: std::io::Error) -> Self {
        Error::Io(value)
    }
}

impl From<canzero_codegen::errors::Error> for Error {
    fn from(value: canzero_codegen::errors::Error) -> Self {
        Error::CodegenError(value)
    }
}


impl Display for Error {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match &self {
            Error::NoConfigSelected => write!(f, "No config was selected with \"config select <path or github repo>\""),
            Error::FileNotFound(path) => write!(f, "Failed to find file {path:?}"),
            Error::CodegenError(err) => write!(f, "{err:?}"),
            Error::Io(err) => write!(f, "{err:?}"),
            Error::AppDataError(err) => write!(f, "{err:?}"),
            Error::MissingDependency(dep) => write!(f, "Missing dependency {dep}"),
            Error::InvalidResponse => write!(f, "Invalid Response"),
            Error::InvalidNodeName(node_name) => write!(f, "Invalid node name : {node_name}"),
            Error::InvalidBusName(bus_name) => write!(f, "Invalid bus name : {bus_name}"),
            Error::NoServerFound => write!(f, "No server found"),
            Error::NotYetImplemented => write!(f, "Not yet implemented"),
        }
    }
}
