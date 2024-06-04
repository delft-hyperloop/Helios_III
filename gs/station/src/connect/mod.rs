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
) -> anyhow::Result<()> {
    // Bind the listener to the address
    message_transmitter.send(Message::Warning(format!(
        "trying to connect... {:?}",
        gs_socket()
    )))?;
    let listener = TcpListener::bind(gs_socket()).await?;
    message_transmitter.send(Message::Status(crate::Info::ServerStarted))?;
    message_transmitter.send(Message::Info(format!(
        "Server Listening on: {}",
        gs_socket()
    )))?;
    loop {
        // The second item contains the IP and port of the new connection.
        let (socket, client_addr) = listener.accept().await?;
        message_transmitter.send(Message::Info(format!(
            "New connection from: {}",
            client_addr
        )))?;
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
        match get_messages_from_tcp(reader, transmit.clone()).await {
            Ok(_) => {
                transmit
                    .send(Message::Error(
                        "[get_messages_from_tcp] exited with no errors.".to_string(),
                    ))
                    .expect("messaging channel closed... this is irrecoverable");
            }
            Err(e) => {
                transmit
                    .send(Message::Error(format!(
                        "[get_messages_from_tcp] finished with errors: {:?}",
                        e
                    )))
                    .expect("messaging channel closed... this is irrecoverable");
            }
        }
    });
    let transmit = message_transmitter.clone();
    tokio::spawn(async move {
        match transmit_commands_to_tcp(command_receiver, transmit.clone(), writer).await {
            Ok(_) => {
                transmit
                    .send(Message::Error(
                        "[transmit_commands_to_tcp] exited with no errors.".to_string(),
                    ))
                    .expect("messaging channel closed... this is irrecoverable");
            }
            Err(e) => {
                transmit
                    .send(Message::Error(format!(
                        "[transmit_commands_to_tcp] finished with errors: {:?}",
                        e
                    )))
                    .expect("messaging channel closed... this is irrecoverable");
            }
        }
    });
}
