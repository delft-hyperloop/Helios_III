# Sense and control scrutineering

- [X] display all individual cell voltages -> fix table render
- [X] cut off floating points
- [X] remove insulation from vitals if it is not measured
- [X] remove 1-7 shortcuts
- [X] prevent shitty line splits (`High\nVoltage`, `HV Relays\nOff`) 
- [ ] debug why tf it doesnt connect without flashing (voltage issue?) (it connects if i plug it into my laptop without needing to flash it)
- [ ] visual confirmation that button was pressed *and* that the main pcb received the command
- [ ] number for what override was set
- [X] wtf is propulsion temperature = 10000
- [X] button for saving

- [ ] LOGS SENDING NOTIFICATIONS DOES NOT WORK
- [ ] not everything is printed to the logs 
->> for these two, please leave all the functionality to the backend

- [X] update svg for fsm and state mappings

- [ ] turn hv on/off switch doesn't work 
- [ ] out of range values don't say that they ebraked
- [ ] instant overflow in the precharge delay
- [ ] connections list doesn't work 
- [ ] find every single place we cause emergency braking and make a log 
- [ ] confirmation when saving to file


- [ ] dynamically load config...?
- [ ] at least the file to save at

- [ ] balance tcp load
- [ ] emergency button doesnt work on gs (only shortcuts work) (or there's no visual indication that it works)

- [ ] shortcuts don't show notification
