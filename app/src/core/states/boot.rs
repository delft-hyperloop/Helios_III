use defmt::info;
use crate::core::communication::{Datapoint};
use crate::core::finite_state_machine::{FSM, State};
use crate::{Datatype, Event};

impl FSM {
    pub fn boot_entry(&mut self) {

        info!("Entering Boot State");

        self.data_queue.send(Datapoint::new(Datatype::FSMState, 13, 69));
        self.react(Event::BootingCompleteEvent);
        return;
        if !self.peripherals.braking_controller.rearm_breaks() {
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
                info!("The current state ignores {}", event.to_str());

            }
        }
    }

}
