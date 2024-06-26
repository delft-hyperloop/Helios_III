# Delft Hyperloop - Helios III
*sponsored by goose*

./app ->> main application source code
./gs  ->> ground station frontend code
./gs/station ->> ground station backend code

# Running
this project is built on `rustc 1.79.0 (129f3b996 2024-06-10)` and is needed for all components.

## Main application
flashing & running the main application requires 
- [probe-rs](https://probe.rs),
- [`rustup target thumbv7em-none-eabihf`](https://doc.rust-lang.org/nightly/rustc/platform-support/thumbv7em-none-eabi.html)
- a connected `STM32H743ZIT6` device

`cargo run` will generate debug symbols and enable logging, `cargo run --release` will disable all logging.

## Ground station
The ground station backend can no longer be run independently, and thus it needs a frontend.

There's 2 to pick from, a *text-based user interface* and a *graphical user interface*.

To run the graphical user interface run
```
cd ./gs/
npm i
npm run tauri dev
```
(obviously requires NPM as well)

To run the more lightweight TUI
```
cd ./gs/station/
cargo run --no-default-features --features tui
```
(only rust needed)

# Maintaining

## Main application
PANICKING IS NOT ALLOWED!!
if you `.unwrap()` anywhere i will find you

## Ground station
The ground station backend functionality entirely resides in 
```
./gs/station/src/backend.rs
```
in the `struct Backend`.

To implement a frontend, all you need to do is `Backend::new()`, create listeners for the `broadcast::channel`s, receive `Message`s and send `Command`s.


```
© 2024 Andreas Tsatsanis, Fransisco Amaro, Kiril Panayotov
```

