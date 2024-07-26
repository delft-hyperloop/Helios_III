# Next Steps for `goose`
todo's for continuing after the 2024 EHW

### Most important:

1. Clean up, write documentation, remove unused code
2. Rework connecting to ground station (see requirements in [connecting](#Connecting))
3. 

### In no particular order

- [ ] custom `serde` format for parsing procedures (pls remove regex)
- [ ] strongly typed FSM states and transitions
- [ ] statically generate DAG for the FSM 
- [ ] create SVG from fsm dag 
- [ ] 


## Connecting 

- Pod is server instead of ground station
- allow multiple connections
- some form of auth token in the backend (so you don't accept arbitrary external connection)
- open 1 tcp connection for `gs -> pod` sending commands and `pod -> gs` important data
- UDP send less important data `pod -> gs`
- keep listening indefinitely for new connections 
- smoothly handle connection drops 
    - one ground station is critical (marked in handshake), `e_brake` on disconnect
    - `e_brake` if all ground stations are disconnected
    - don't brake if non-critical gs disconnects
