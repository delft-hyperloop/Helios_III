mod queueing;
mod tcp_reader;
mod tcp_writer;

use crate::api::{gs_socket, Message};
use crate::connect::tcp_reader::get_messages_from_tcp;
use crate::connect::tcp_writer::transmit_commands_to_tcp;
use tokio::net::{TcpListener, TcpStream};

pub async fn connect_main(
    message_transmitter: tokio::sync::broadcast::Sender<crate::api::Message>,
    command_receiver: tokio::sync::broadcast::Receiver<crate::Command>,
) {
    // Bind the listener to the address
    message_transmitter.send(Message::Warning(format!("trying to connect... {:?}", gs_socket()))).unwrap();
    let listener = TcpListener::bind(gs_socket()).await.unwrap();
    message_transmitter.send(Message::Status(crate::api::Status::ServerStarted)).unwrap();
    message_transmitter
        .send(Message::Info(format!(
            "Server Listening on: {}",
            gs_socket()
        )))
        .unwrap();
    loop {
        // The second item contains the IP and port of the new connection.
        let (socket, client_addr) = listener.accept().await.unwrap();
        message_transmitter
            .send(crate::api::Message::Info(format!(
                "New connection from: {}",
                client_addr
            )))
            .unwrap();
        process(
            socket,
            message_transmitter.clone(),
            command_receiver.resubscribe(),
        )
        .await;
    }
}

async fn process(
    socket: TcpStream,
    message_transmitter: tokio::sync::broadcast::Sender<crate::api::Message>,
    command_receiver: tokio::sync::broadcast::Receiver<crate::Command>,
) {
    let (reader, writer) = socket.into_split();
    let transmit = message_transmitter.clone();
    tokio::spawn(async move {
        get_messages_from_tcp(reader, transmit).await;
    });
    let transmit = message_transmitter.clone();
    tokio::spawn(async move {
        transmit_commands_to_tcp(command_receiver, transmit, writer).await;
    });
}
