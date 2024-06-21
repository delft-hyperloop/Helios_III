use std::path::PathBuf;

use build_time::build_time_local; use clap::{Parser, Subcommand};
use config::command_config_get;

use crate::{
    client::command_client,
    config::{
        command_config_check, command_config_hash, command_config_messages_list,
        command_config_nodes_list, command_config_object_entries_list, command_config_set,
        command_config_show,
    },
    dump::command_dump,
    errors::Error,
    generate::command_generate,
    scan::command_scan,
    server::command_server,
    ssh::{command_ssh, command_ssh_reboot},
    status::command_status,
    update::{command_update_self, command_update_server},
};

mod client;
mod config;
mod dump;
mod errors;
mod generate;
mod get;
mod scan;
mod server;
mod ssh;
mod status;
mod update;

#[derive(Parser, Debug)]
#[command(
    version,
    about = "Canzero is a CAN toolchain for fast prototyping",
)]
struct Cli {
    #[command(subcommand)]
    command: Option<Command>,
}

#[derive(Subcommand, Debug)]
enum Command {
    #[command(
        about = "Display and select the current network configuration.",
        arg_required_else_help = true
    )]
    Config {
        #[command(subcommand)]
        command: ConfigCommand,
    },
    #[clap(alias = "gen")]
    #[command(about = "Generate c code from the selected network configuration.")]
    Generate {
        node_name: String,
        output_dir: PathBuf,
    },
    #[command(about = "Start canzero graphical user interface.")]
    Gui,
    #[command(about = "Interact with or start the server node.")]
    Server {
        #[command(subcommand)]
        command: ServerCommand,
    },
    #[command(about = "Connect to a network (SocketCAN).")]
    Connect,
    #[command(about = "Print the CAN trace to the control.")]
    Dump {
        #[clap(alias = "msg")]
        #[arg(short, long, num_args=0..)]
        messages: Vec<String>,
        #[clap(alias = "id")]
        #[arg(short, long, num_args=0..)]
        ids: Vec<String>,
    },
    #[command(about = "Check the status of all connected nodes.")]
    Status,
    #[command(about = "Update CANzero.")]
    Update {
        #[arg(short='s', long="socketcan", action = clap::ArgAction::SetTrue)]
        socketcan: bool,
    },
    Version
}

#[derive(Subcommand, Debug)]
enum ConfigCommand {
    #[command(
        about = "Set path to network configuration.",
        arg_required_else_help = true
    )]
    Set { path: PathBuf },
    #[command(
        about = "Display the network configuration.",
        arg_required_else_help = false
    )]
    Show {
        #[command(subcommand)]
        command: Option<ConfigShowCommand>,
    },
    #[command(
        about = "Check the network configuration for errors.",
        arg_required_else_help = false
    )]
    Check,
    Where,
}

#[derive(Subcommand, Debug)]
enum ConfigShowCommand {
    Hash,
    Messages {
        #[arg(short, long)]
        node: Option<String>,
        #[arg(short, long)]
        bus: Option<String>,
    },
    Nodes,
    ObjectEntries {
        node: String,
    },
}

#[derive(Subcommand, Debug)]
enum ServerCommand {
    Start,
    Scan,
    Restart,
    Reboot,
    Ssh { host: Option<String> },
    Update { host: Option<String> },
}

#[derive(Subcommand, Debug)]
enum ClientCommand {
    Start,
}

/// returns true iff. the gui should be started!
pub async fn run_cli(armv7_cli_binary : Option<PathBuf>) -> bool {
    let cli = Cli::parse();
    let res = match cli.command {
        Some(cmd) => match cmd {
            Command::Config { command } => match command {
                ConfigCommand::Set { path } => command_config_set(path),
                ConfigCommand::Show { command } => match command {
                    Some(config_show_command) => match config_show_command {
                        ConfigShowCommand::Hash => command_config_hash(),
                        ConfigShowCommand::Messages { node, bus } => {
                            command_config_messages_list(node, bus)
                        }
                        ConfigShowCommand::Nodes => command_config_nodes_list(),
                        ConfigShowCommand::ObjectEntries { node } => {
                            command_config_object_entries_list(node)
                        }
                    },
                    None => command_config_show(),
                },
                ConfigCommand::Check => command_config_check(),
                ConfigCommand::Where => command_config_get(),
            },
            Command::Generate {
                node_name,
                output_dir,
            } => command_generate(&node_name, &output_dir),
            Command::Gui => return true,
            Command::Server { command } => match command {
                ServerCommand::Start => command_server().await,
                ServerCommand::Scan => command_scan().await,
                ServerCommand::Restart => Err(Error::NotYetImplemented),
                ServerCommand::Reboot => command_ssh_reboot(None).await,
                ServerCommand::Ssh { host } => command_ssh(host).await,
                ServerCommand::Update { host } => {
                    command_update_server(host, false, true, armv7_cli_binary).await
                }
            },
            Command::Connect => command_client().await,
            Command::Dump { messages, ids } => command_dump(messages, ids).await,
            Command::Status => command_status().await,
            Command::Update { socketcan } => command_update_self(socketcan),
            Command::Version => {
                println!("build-time : {}", build_time_local!());
                if cfg!(feature="socket-can") {
                    println!("socket-can : enabled");
                }else {
                    println!("socket-can : disabled");
                }
                Ok(())
            }
        },
        None => return true,
    };
    if let Err(err) = res {
        eprintln!("{err:?}");
    }
    return false;
}

