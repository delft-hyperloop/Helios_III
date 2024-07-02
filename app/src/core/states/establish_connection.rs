use crate::core::finite_state_machine::{State, FSM};
use crate::{Datatype, Event};
use defmt::info;
use crate::core::communication::Datapoint;

impl FSM {
    pub async fn entry_establish_connection(&mut self) {
        info!("Entering Establish Connection State");
        // self.peripherals.braking_controller.brake();
        // TODO -> Start connection with the ground station, with levi and propulsion
    }

    pub async fn react_establish_connection(&mut self, event: Event) {
        match event {
            Event::ConnectionEstablishedEvent => {
                self.transit(State::RunConfig).await;
            }
            Event::ConnectionEstablishmentFailedEvent => {
                self.transit(State::Exit).await;
            }
            Event::ArmBrakesCommand => {
                match self.peripherals.braking_controller.arm_breaks() {
                    true => {
                        self.data_queue.send(Datapoint::new(Datatype::Info, 1, embassy_time::Instant::now().as_ticks())).await;
                    }
                    false => {
                        self.transit(State::Exit).await;
                    }
                }
            }

            _ => {
                info!("The current state ignores {}", event.to_str());
            }
        }
    }
}
