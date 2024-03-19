# Ground Station
*goose*

## Overview
the ground station is made up of two
important components:
1. The Backend
2. The GUI

## 1. Backend

## 2. GUI
unlike the backed, the gui is not yet 
(13/3/2024 09:31) decided on.
What we do know, is that it will be comprised
of two parts: the functional and the UI.

By "functional", what we mean is *bindings* to 
functions that communicate by the backend. 
These functions are responsible for fetching
data and sending commands.

If we use a *rust* frontend, which will
probably be [ratatui](https://ratatui.rs),
the code for the bindings (and thus the whole
backend) will be compiled with the frontend
in the same binary. This means no need for 
inter-process communication.

If we use a *python* frontend, for example,
last year's pyqt5, we will have to use
[PyO3](https://pyo3.rs) to bind the rust
functions to methods that someone else can use
in python to a) fetch data and b) send
commands.