use crate::core::communication::Datapoint;
use crate::core::finite_state_machine::{State, FSM};
use crate::{Datatype, Event};
use defmt::{error, info};

impl FSM {
    pub async fn boot_entry(&mut self) {
        info!("Entering Boot State");

        self.data_queue
            .send(Datapoint::new(Datatype::FSMState, 13, embassy_time::Instant::now().as_ticks())).await;
        self.react(Event::BootingCompleteEvent);
        return;
        if !self.peripherals.braking_controller.arm_breaks() {
            self.react(Event::BootingFailedEvent);
        }
        info!("Booting complete");
        // TODO -> Start also the connection with the sensor hub ||| I think this will be a task that starts can bus 1 and 2
    }

    pub async fn react_boot(&mut self, event: Event) {
        match event {
            Event::BootingCompleteEvent => {
                info!("Booting complete");

                self.transit(State::EstablishConnection).await;
            }
            Event::BootingFailedEvent => {
                error!("Booting failed!!");

                self.transit(State::Exit).await
            }
            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
