pub type Result<T> = std::result::Result<T, Error>;

#[derive(Debug)]
pub enum Error {
    InvalidGetResponseSofFlag,
    InvalidGetResponseEofFlag,
    InvalidGetResponseToggleFlag,
    InvalidGetResponseServerOrObjectEntryNotFound,
    InvalidSetResponseServerOrObjectEntryNotFound,
    InvalidHeartbeatNodeId
}

impl Error {
    pub fn reason(&self) -> &str {
        match &self {
            Error::InvalidGetResponseSofFlag => "invalid get response: invalid sof bit",
            Error::InvalidGetResponseEofFlag => "invalid get response: invalid eof bit",
            Error::InvalidGetResponseToggleFlag => "invalid get response: invalid toggle bit",
            Error::InvalidGetResponseServerOrObjectEntryNotFound => "invalid get response: server or object entry not found",
            Error::InvalidSetResponseServerOrObjectEntryNotFound => "invalid set response: server or object entry not found",
            Error::InvalidHeartbeatNodeId => "invalid heartbeat message: node id does not exists",
        }
    }

    pub fn description(&self) -> &str {
        match &self {
            Error::InvalidGetResponseSofFlag => "invalid get response: invalid sof bit",
            Error::InvalidGetResponseEofFlag => "invalid get response: invalid eof bit",
            Error::InvalidGetResponseToggleFlag => "invalid get response: invalid toggle bit",
            Error::InvalidGetResponseServerOrObjectEntryNotFound => "invalid get response: server not found",
            Error::InvalidSetResponseServerOrObjectEntryNotFound => "No node with given id and object entry index could be found",
            Error::InvalidHeartbeatNodeId => "invalid heartbeat message: node id does not exists",
        }
    }
}
