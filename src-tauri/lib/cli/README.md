# `CANzero`

> A CAN communication toolchain developed for mu-zero HYPERLOOP.

### Features
- **server** : Hosts a CANzero server, which allows connecting CAN networks over TCP.
- **client** : Connects a local SocketCAN network with a CANzero server.
- **cross-compiling** : Allows remotely updating the server, by cross compiling the binary.
- **scanning** : Scan for CANzero communication servers in the local network.


## Getting Started
##### Dependencies
- optional [`cross`](https://github.com/mu-zero-HYPERLOOP/can-cli-rs/wiki/Cross%E2%80%90compiling-for-the-raspberry-pi) for cross-compiling for the raspberry pi
- can-utils for running the tcp server/ client.

##### Installing
Simple to install the CLI
```
$ cargo install --git="https://github.com/mu-zero-HYPERLOOP/can-cli-rs"
```
For installing it on a remote platform
```
$ canzero update server --host=<ip>
```
##### Updating
To update the CLI locally run
```
$ canzero update self
```
For updating the CLI on a remote platform run 
```
$ canzero update server --restart --host=<ip>
```

the ```--host``` option is only required on the first installation. Or if the TCP server is not currently running.


#### Examples
- Start a CANzero server ``` $ canzero run server ```
- Start a CANzero client ``` $ canzero run client // starts the server ```
- View server log files  ``` $ canzero get server-log ```
- Scan for CANzero servers ``` $ canzero scan ```
- Connect to server ``` $ canzero ssh```
- Restart CANzero server remotly ``` $ canzero ssh --restart ```


