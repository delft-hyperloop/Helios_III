# Scrutineering Checklist for the Graphical Control Panel

- [?] The demonstrator bears resemblance with the proposed FDD concept.
    - no clue on this one
- [ ] Safe range for monitored variables is clearly indicated.
    - not present anywhere in the GUI currently
    - we can get the values from the configuration files (lower, upper)
- [ ] The demonstrator can brake using a physical button of the Control Station.
    - if the escape key counts as a physical button then yes,
    - except that it doesn't work
- [~] GUI monitors the speed of the demonstrator.
    - yes but it's not visible enough
- [ ] GUI does not display outdated values.
    - i am pretty sure it does for text boxes.
    - charts are safe because they  show the timestamp,
    - we can maybe make charts for all the important values
- [X] Stop command is implemented on the GUI.
- [X] Person monitoring the speed of the demonstrator has quick access to the emergency brakes.
- [ ] Demonstrator’s health must be visible to an external viewer using colored visual indicators.
    - no, the value fields have no colours,
    - limits aren't visible anywhere
    - connection status isn't implemented anywhere
- [ ] Test cut off battery command and verify correct result.
    - no such button exists currently
    - the function for this is `send_command StopHV` 
- [X] The GUI logs individual cell voltage of 100% of low voltage Cells.
    - i think this is true but i am not sure
    - if a cell stops sending data currently it will just display the old value afaik
    - if we don't want charts for these, maybe we can colour-code how old the values are.
- [X] The GUI logs data of at least 25% of cell temperatures.
    - pretty sure this is fine, double-check with kiko
- [X] The GUI logs SOC of the low voltage battery.
    - yes but i want to colour-code the HV battery icon differently than LV battery
- [X] The GUI logs individual cell voltage of 100% of low voltage Cells.
    - yeah i think this is fine, maybe made into charts
- [X] The demonstrator logs data in Fault State.
- [X] The demonstrator can be restarted from Fault State.

## Andreas judging the UI 

### Home tab
- [x] rename the procedures button to "refresh procedures" and make a notification pop up when it finishes successfully
- [x] PLEASE increase the hitbox for dragging the logs panel up and down
- [ ] change the description under the title
- [ ] none of the keyboard shortcuts work
- [ ] add a note that `Quit Server` doesn't kill an active connection
- [ ] add a button and a text field to `Save logs to file` (backend already implemented)

### Run tab
- [x] remove start server button
- [x] rename `Run Config` button to `Configure Run`
- [x] if state != 2 (runconfig) gray out the configure run button
- [x] what on earth is a theoretical run?
- [ ] statuses are cool, but they don't work, must fix (this includes backend work)
- [x] you can't scroll this panel enough to show all content when the logs panel is extended (visible) pls fix 
- [ ] discuss with andreas the functionality of run config (it didn't work when we tried)

### Location tab
- [x] rename tab to `Location` instead of `Location & IMU`
- [ ] fix the graph (kiko is working on this)
- [ ] fix the lighting up of the SVG with the new graph
- [ ] we need buttons to actually control levitation. ask sjoerd what buttons are necessary for manual use and what should instead be automated by the FSM

### Batteries tab
- [ ] colour-code the low voltage and high voltage batteries (i think blue for LV and purple/magenta for HV?)
- [ ] the HV battery relay status is confusing, does green mean active or safe? since there's a procedure for turning on high voltage, make two disjoint buttons for `Enable HV Relays` and `Disable HV Relays`, make red text for HV ON and white HV OFF
- [ ] the DC converter status text and colours are confusing, make the text white for `Off` and green for `Charging`
- [ ] consider making the battery stats charts. discuss with kiko

### Levitation tab 
- [ ] i dont think you need the last 30 minutes of data... ask sjoerd but maybe only display 3 minutes, since everything can be logged anyway
- [ ] tables at the bottom are not visible at all when logs panel is open

### Pneumatics
- [ ] add fields for datatypes `BrakingCommDebug`, `BrakingSignalDebug`, `BrakingRearmDebug`
- [ ] multiply `BrakingCommDebug` by `3.3` and divide by `65535`, unit is volts
- [ ] if the colours on the graph can change pls make sure this works / is actually implemented everywhere (frontend + backend if necessary)
- [ ] please please increase the hitbox of the log panel scrolling

### Procedures
- [ ] top item in the left sidebar gets cut off, add some margin or padding
- [ ] make it actually work with the backend command:
    - the tauri command `procedures()` gives an array of length 6:
        0. the procedure name as should be displayed in the sidebar
        1. title, `<h1>`
        2. id, displayed as monospace and is what other procedures link to. if you can make links between them it would be great, but dont lose time on this.
        3. people, a string of people needed in this procedure, delimited by newlines
        4. equipment, a string of items needed in this procedure, delimited by newlines
        5. content, one long string (`<p>` probably)
    
### Vitals
- [ ] make fsm a bit smaller.
- [ ] the location diagram should be visible here.
- [ ] we really need buttons for other important actions:
    - turn off high voltage
    - arm brakes
    - continue run (`send_command StartRun`)


