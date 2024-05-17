use crate::core::communication::Datapoint;
use crate::core::controllers::finite_state_machine_peripherals::FSMPeripherals;
use crate::core::controllers::hv_controller::Status;
use crate::{DataSender, Datatype, Event, EventReceiver};
use core::cmp::{Eq, Ordering, PartialEq};
use defmt::*;
use embassy_stm32;
use embassy_stm32::Peripherals;
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::priority_channel::{PriorityChannel, Receiver};
use embassy_time::Instant;
use heapless::binary_heap::Max;
use heapless::Deque;

//Enum holding different states that the FSM can be in
#[derive(Clone, Copy, Debug, Format)]
#[repr(u64)]
pub enum State {
    Boot,
    EstablishConnection,
    RunConfig,
    Idle,
    HVSystemChecking,
    Levitating,
    Accelerating,
    Cruising,
    LaneSwitch,
    Braking,
    EmergencyBraking,
    Exit,
    Crashing,
}

/// All the functionalities states can have like converting to id's or format print statements should go here
/// The actual implementation of each state should just be attached to the state machine in separate files
impl State {

}

// [!!!!!] [April 3 2024] -> This is here as a reference only, if you want to add or edit events go to ../config/events.toml
/*
//Enum holding different events that the FSM can react to
// #[derive(Debug, PartialEq, Eq)]
// pub enum Event {
//     DefaultEvent,
//     // Boot state related events
//     BootingCompleteEvent,
//     BootingFailedEvent,
//     // Establish Connection state related events
//     ConnectionEstablishedEvent,
//     ConnectionEstablishmentFailedEvent,
//     // Run Config state related events
//     SetRunConfig(u32),
//     RunConfigCompleteEvent,
//     RunConfigFailedEvent,
//
//     //Error Handling events
//     LevitationErrorEvent,
//     PropulsionErrorEvent,
//     PowertrainErrorEvent,
//     EmergencyBrakeCommand,
//     ConnectionLossEvent,
//
//     // Idle state related events
//     LVLevitationReadyEvent,
//     LVPropulsionReadyEvent,
//     LVPowertrainReadyEvent,
//     ArmBrakesCommand,
//     TurnOnHVCommand,
//
//
//     // HV System Checking state
//     HVPowertrainReadyEvent,
//     HVLevitationReadyEvent,
//     StartLevitatingCommand,
//
//     // Levitating
//     HVPropulsionReadyEvent,
//     StartAcceleratingCommand,
//
//     // Accelerating
//     DesiredSpeedReachedEvent,
//     BrakingPointReachedEvent,
//
//     // Cruising
//     LaneSwitchingPointReachedEvent,
//
//
//     //LaneSwitching
//     LaneSwitchingCompleteEvent,
//
//     // Braking
//     DirectionChangedEvent,
//     RunFinishedEvent,
//
//     // EmergencyBraking
//     SystemResetCommand,
//
//     ExitEvent,
// }*/
// Again some functionalities that might be useful for the events to have mut be here

//TODO: Add all the parameters that the FSM might need to have
// This bad boy will be a singleton and it will be passed around everywhere
// Just be careful with the STD's

impl PartialOrd for Event {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}
impl Ord for Event {
    fn cmp(&self, other: &Self) -> Ordering {
        self.priority().cmp(&other.priority())
    }
}

pub struct FSM {
    state: State,
    pub peripherals: FSMPeripherals,
    pub event_queue: EventReceiver,
    pub data_queue: DataSender,
    pub status: Status,
}

/// * Finite State Machine (FSM) for the DH08 POD -> Helios III
/// * This FSM is a singleton and an entity. Its name is Megalo coming from the ancient greek word for "Big" and from the gods Megahni and Gonzalo
impl FSM {
    pub fn new(p: FSMPeripherals, pq: EventReceiver, dq: DataSender) -> Self {
        //TODO: Decide if main should be dirty with peripheral initialization or if it should be done here

        Self {
            state: State::Boot,
            peripherals: p,
            event_queue: pq,
            data_queue: dq,
            status: Status::new(),
        }
    }

    /// Function used to transit states of Megalo --> Comes from Megahni and Gonzalo
    ///
    pub async fn transit(&mut self, next_state: State) {
        info!("Exiting state: {:?}", self.state);
        info!("Entering state: {:?}", next_state);
        self.state = next_state;
        self.data_queue.send(Datapoint::new(Datatype::FSMState, next_state as u64, Instant::now().as_ticks())).await;
        self.entry();
    }
    pub async fn entry(&mut self) {
        match self.state {
            State::Boot => self.boot_entry().await,
            State::EstablishConnection => self.entry_establish_connection().await,
            State::Idle => self.entry_idle().await,
            State::RunConfig => self.entry_run_config().await,
            State::HVSystemChecking => self.entry_hv_system_checking().await,
            State::Levitating => self.entry_levitating().await,
            State::Accelerating => self.entry_accelerating().await,
            State::Cruising => self.entry_cruising().await,
            State::LaneSwitch => self.entry_lane_switch().await,
            State::Braking => self.entry_braking().await,
            State::EmergencyBraking => self.entry_emergency_braking().await,
            State::Exit => self.entry_exit().await,
            State::Crashing => {
                info!("Im going against a wall for sure this time"); //<--- This is what happens if the Crashing state ever gets triggered
            }
        }
    }
    pub(crate) async fn react(&mut self, event: Event) {
        info!("[fsm] reacting to {}", event.to_str());
        self.data_queue
            .send(Datapoint::new(Datatype::FSMEvent, event.to_id() as u64, 69))
            .await;
        match event {
            Event::LevitationErrorEvent
            | Event::PropulsionErrorEvent
            | Event::PowertrainErrorEvent
            | Event::ConnectionLossEvent
            | Event::EmergencyBrakeCommand => {
                self.transit(State::EmergencyBraking).await;
                return;
            }
            _ => {}
        }
        match self.state {
            State::Boot => self.react_boot(event).await,
            State::EstablishConnection => self.react_establish_connection(event).await,
            State::Idle => self.react_idle(event).await,
            State::RunConfig => self.react_run_config(event).await,
            State::HVSystemChecking => self.react_hv_system_checking(event).await,
            State::Levitating => self.react_levitating(event).await,
            State::Accelerating => self.react_accelerating(event).await,
            State::Cruising => self.react_cruising(event).await,
            State::LaneSwitch => self.react_lane_switch(event).await,
            State::Braking => self.react_braking(event).await,
            State::Exit => self.react_exit(event).await,
            State::EmergencyBraking => {}
            State::Crashing => {}
        }
    }
}
