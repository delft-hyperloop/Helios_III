use crate::connect::Datapoint;

pub enum Status {
    ServerStarted,
    ServerFailedToStart,
    UnknownClient,
    ConnectionEstablished,
    ConnectionClosedByClient,
    ConnectionClosedByServer,
    ConnectionDropped,
    FailedToReadFromConnection,
}

pub enum Message {
    Data(Datapoint),
    Status(Status),
    Info(String),
    Warning(String),
    Error(String),
}