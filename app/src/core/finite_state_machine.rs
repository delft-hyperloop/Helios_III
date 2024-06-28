use core::cmp::Ordering;

use defmt::*;
use embassy_time::Instant;

use crate::core::communication::Datapoint;
use crate::core::controllers::finite_state_machine_peripherals::FSMPeripherals;
use crate::core::fsm_status::{Route, RouteUse};
use crate::core::fsm_status::Status;
use crate::DataSender;
use crate::Datatype;
use crate::Event;
use crate::EventReceiver;
use crate::Info;

#[macro_export]
macro_rules! transit {
    ($fsm:expr, $ns:expr) => {
        info!("Exiting state: {:?}", $fsm.state);
        info!("Entering state: {:?}", $ns);
        $fsm.state = $ns;
        $fsm.entry().await;
    };
}

//Enum holding different states that the FSM can be in
#[derive(Clone, Copy, Debug, Format)]
#[allow(dead_code)]
#[repr(u64)]
pub enum State {
    Boot,
    EstablishConnection,
    RunConfig,
    Idle,
    HVOn,
    Levitating,
    MovingST,
    MovingLSST,
    MovingLSCV,
    EndST,
    EmergencyBraking,
    Exit,
    Crashing,
}

/// All the functionalities states can have like converting to id's or format print statements should go here
/// The actual implementation of each state should just be attached to the state machine in separate files
impl State {}

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

#[allow(dead_code)]
pub struct Fsm {
    pub state: State,
    pub peripherals: FSMPeripherals,
    pub event_queue: EventReceiver,
    pub data_queue: DataSender,
    pub status: Status,
    pub route: Route,
}

/// * Finite State Machine (FSM) for the DH08 POD -> Helios III
/// * This FSM is a singleton and an entity. Its name is Megalo coming from the ancient greek word for "Big" and from the gods Megahni and Gonzalo
impl Fsm {
    pub fn new(p: FSMPeripherals, pq: EventReceiver, dq: DataSender) -> Self {
        Self {
            state: State::Boot,
            peripherals: p,
            event_queue: pq,
            data_queue: dq,
            status: Status::default(),
            route: Route::default(),
        }
    }

    pub async fn entry(&mut self) {
        #[cfg(debug_assertions)]
        info!("entry called: {:?}", self.state);

        self.data_queue
            .send(Datapoint::new(
                Datatype::FSMState,
                self.state as u64,
                Instant::now().as_ticks(),
            ))
            .await;

        match self.state {
            State::Boot => self.boot_entry(),
            State::EstablishConnection => self.entry_establish_connection(),
            State::Idle => self.entry_idle(),
            State::RunConfig => self.entry_run_config(),
            State::HVOn => self.entry_hv_on(),
            State::Levitating => self.entry_levitating(),
            State::MovingST => self.entry_accelerating(),
            State::MovingLSST => self.entry_cruising(),
            State::MovingLSCV => self.entry_ls_cv(),
            State::EndST => self.entry_end_st(),
            State::EmergencyBraking => {
                self.entry_emergency_braking();
                self.pod_safe().await;
            }
            State::Exit => self.entry_exit(),
            State::Crashing => self.entry_exit(),
        };
    }
    pub(crate) async fn react(&mut self, event: Event) {
        info!("[fsm] reacting to {}", event.to_str());
        self.data_queue
            .send(Datapoint::new(
                Datatype::FSMEvent,
                event.to_id() as u64,
                Instant::now().as_ticks(),
            ))
            .await;
        match event {
            Event::LevitationErrorEvent
            | Event::PropulsionErrorEvent
            | Event::PowertrainErrorEvent
            | Event::ConnectionLossEvent
            | Event::EmergencyBrakeCommand => {
                transit!(self, State::EmergencyBraking);
                return;
            }
            Event::TurnAllHVRelaysOnEvent => {
                self.peripherals.hv_peripherals.pin_4.set_high();
                self.peripherals.hv_peripherals.pin_6.set_high();
                self.peripherals.hv_peripherals.pin_7.set_high();
            }

            Event::LVPropulsionReadyEvent => {
                let p = self.route.next_position();
                let s = self.route.speed_at(p);
                self.peripherals.propulsion_controller.set_speed(s);
                self.send_data(Datatype::PropulsionSpeed, s as u64).await;
            }

            _ => {
                trace!("Event was not emergency brake, continuing...");
            }
        }
        match self.state {
            State::Boot => self.react_boot(event).await,
            State::EstablishConnection => self.react_establish_connection(event).await,
            State::Idle => self.react_idle(event).await,
            State::RunConfig => self.react_run_config(event).await,
            State::HVOn => self.react_hv_on(event).await,
            State::Levitating => self.react_levitating(event).await,
            State::MovingST => self.react_mv_st(event).await,
            State::MovingLSST => self.react_mv_ls_st(event).await,
            State::MovingLSCV => self.react_mv_ls_cv(event).await,
            State::EndST => self.react_end_st(event).await,
            State::Exit => self.react_exit(event).await,
            State::EmergencyBraking => self.react_emergency_braking(event).await,
            State::Crashing => {
                self.log(crate::Info::Crashed).await;
                info!("TRYING TO REACT WHILE CRASHING!!!!!!");
            }
        }
    }

    /// # Send data to the ground station
    #[allow(unused)]
    pub async fn send_data(&mut self, dtype: Datatype, data: u64) {
        self.data_queue
            .send(Datapoint::new(dtype, data, Instant::now().as_ticks()))
            .await;
    }

    /// # Send a command to Levi
    #[allow(unused)]
    pub async fn send_levi_cmd(&mut self, cmd: crate::Command) {
        self.data_queue
            .send(Datapoint::new(
                crate::Datatype::LeviInstruction,
                cmd.to_id() as u64,
                Instant::now().as_ticks(),
            ))
            .await;
    }

    pub async fn log(&self, info: crate::Info) {
        self.data_queue
            .send(Datapoint::new(
                Datatype::Info,
                info.to_idx(),
                Instant::now().as_ticks(),
            ))
            .await;
    }

    pub async fn pod_safe(&self) {
        self.data_queue
            .send(Datapoint::new(
                Datatype::Info,
                Info::to_idx(&Info::Safe),
                Instant::now().as_ticks(),
            ))
            .await;
    }

    pub async fn pod_unsafe(&self) {
        self.data_queue
            .send(Datapoint::new(
                Datatype::Info,
                Info::to_idx(&Info::Unsafe),
                Instant::now().as_ticks(),
            ))
            .await;
    }
}

/*
/// Function used to transit states of Megalo --> Comes from Megahni and Gonzalo
    ///
    pub async fn transit(&mut self, next_state: State) {
        info!("Exiting state: {:?}", self.state);
        info!("Entering state: {:?}", next_state);
        self.state = next_state;
        self.entry().await;
    }
    */
