use defmt::info;
use crate::core::finite_state_machine::{Event, FSM, State};

impl FSM {
    pub fn boot_entry(&mut self) {

        info!("Entering Boot State");

        if !(self.peripherals.rearm_breaks()) {
            self.react(Event::BootingFailedEvent);
        }
        info!("Booting complete");

        // TODO -> Start also the connection with the sensor hub ||| I think this will be a task that starts can bus 1 and 2
    }

    pub fn react_boot(&mut self, event: Event) {
        match event {
            Event::BootingCompleteEvent => {
                info!("Booting complete");

                self.transit(State::EstablishConnection);
            }
            Event::BootingFailedEvent => {


                todo!();

                self.transit(State::Exit)
            }
            _ => {
                info!("The current state ignores");
                event.fmt();
            }
        }
    }
}