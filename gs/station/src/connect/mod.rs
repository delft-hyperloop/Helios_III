mod handle_incoming_data;
mod queueing;
mod tcp_reader;
mod tcp_writer;

use anyhow::Result;
use gslib::socket;
use gslib::Info;
use gslib::Message;
use tokio::net::TcpListener;
use tokio::net::TcpStream;
use tokio::task::JoinHandle;

use crate::battery::aggregate_voltage_readings;
use crate::battery::DataReceiver;
use crate::battery::DataSender;
use crate::connect::tcp_reader::get_messages_from_tcp;
use crate::connect::tcp_writer::transmit_commands_to_tcp;
use crate::CommandReceiver;
use crate::CommandSender;
use crate::MessageSender;

pub async fn connect_main(
    message_transmitter: MessageSender,
    command_receiver: CommandReceiver,
    command_transmitter: CommandSender,
    data_receiver: DataReceiver,
    data_sender: DataSender,
) -> Result<()> {
    // connect the stream to the address
    message_transmitter.send(Message::Warning(format!("trying to connect... {:?}", socket())))?;
    // let connection = TcpStream::connect(socket()).await?;
    let connection = TcpListener::bind(socket()).await?;
    let (connection, x) = connection.accept().await?;
    message_transmitter.send(Message::Warning(format!("connected with {:?}", x)))?;
    message_transmitter.send(Message::Status(Info::ConnectionEstablished))?;
    let (x, y, z) = process_stream(
        connection,
        message_transmitter.clone(),
        command_receiver.resubscribe(),
        command_transmitter.clone(),
        data_receiver.resubscribe(),
        data_sender.clone(),
    )
    .await?;

    x.await?;
    y.await?;
    z.await?;

    Ok(())
}

async fn process_stream(
    socket: TcpStream,
    message_transmitter: MessageSender,
    command_receiver: CommandReceiver,
    command_transmitter: CommandSender,
    data_receiver: DataReceiver,
    data_sender: DataSender,
) -> Result<(JoinHandle<()>, JoinHandle<()>, JoinHandle<()>)> {
    let (reader, writer) = socket.into_split();
    let transmit = message_transmitter.clone();
    let t = command_transmitter.clone();
    let a = tokio::spawn(async move {
        match get_messages_from_tcp(reader, transmit.clone(), t.clone(), data_sender).await {
            Ok(_) => {
                transmit
                    .send(Message::Warning(
                        "[get_messages_from_tcp] finished with no errors.".to_string(),
                    ))
                    .expect("messaging channel closed... this is irrecoverable");
            },
            Err(e) => {
                transmit
                    .send(Message::Error(format!(
                        "[get_messages_from_tcp] finished with errors: {:?}",
                        e
                    )))
                    .expect("messaging channel closed... this is irrecoverable");
            },
        }
    });
    let transmit = message_transmitter.clone();
    let b = tokio::spawn(async move {
        match transmit_commands_to_tcp(command_receiver, transmit.clone(), writer).await {
            Ok(_) => {
                transmit
                    .send(Message::Warning(
                        "[transmit_commands_to_tcp] finished with no errors.".to_string(),
                    ))
                    .expect("messaging channel closed... this is irrecoverable");
            },
            Err(e) => {
                transmit
                    .send(Message::Error(format!(
                        "[transmit_commands_to_tcp] finished with errors: {:?}",
                        e
                    )))
                    .expect("messaging channel closed... this is irrecoverable");
            },
        }
    });
    let t = command_transmitter.clone();
    let c = tokio::spawn(async move {
        aggregate_voltage_readings(data_receiver, t.clone(), message_transmitter.clone()).await
    });

    Ok((a, b, c))
}
