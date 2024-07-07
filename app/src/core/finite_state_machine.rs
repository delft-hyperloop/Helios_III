use core::cmp::Ordering;

use defmt::*;
use embassy_time::Instant;

use crate::core::communication::Datapoint;
use crate::core::controllers::breaking_controller::ENABLE_BRAKING_COMM;
use crate::core::controllers::finite_state_machine_peripherals::FSMPeripherals;
use crate::core::fsm_status::Route;
use crate::core::fsm_status::Status;
use crate::DataSender;
use crate::Datatype;
use crate::Event;
use crate::EventReceiver;
use crate::Info;

#[macro_export]
macro_rules! transit {
    ($fsm:expr, $ns:expr) => {
        {
            info!("Exiting state: {:?}", $fsm.state);
            info!("Entering state: {:?}", $ns);
            $fsm.state = $ns;
            $fsm.entry().await;
        }
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
    EndLS,
    EmergencyBraking,
    Exit,
    Crashing,
}

impl PartialOrd for Event {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.priority().cmp(&other.priority()))
    }
}
impl Ord for Event {
    fn cmp(&self, other: &Self) -> Ordering { self.priority().cmp(&other.priority()) }
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

/// # Finite State Machine (FSM)
/// ### for the DH08 POD Helios III
/// * This FSM is a singleton.
/// * It is the main controller for the pod.
/// Pretty closely following the principles of Event-Driven-Finite-State-Machine
/// (EDFSM) architecture, other components are responsible for creating `event`s,
/// and the FSM is responsible for `react`ing to them.
///
/// ## States
/// Starting from the boot state, the fsm can go through the procedure of a run by receiving
/// events and transitioning to different states.
///
/// A state here entails of:
/// * entry() method: What to do when entering the state
/// * react() method: What to do when receiving an event
/// * a case clause in the FSM::entry() match statement
/// * a case clause in the FSM::react() match statement
///
/// Important notes:
/// * the entry() method must not be async to prevent recursive `Future`s
///
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
            .send(Datapoint::new(Datatype::FSMState, self.state as u64, Instant::now().as_ticks()))
            .await;

        self.peripherals.led_controller.state_led(self.state as u8).await;

        match self.state {
            State::Boot => self.boot_entry(),
            State::EstablishConnection => self.entry_establish_connection(),
            State::Idle => self.entry_idle(),
            State::RunConfig => self.entry_run_config(),
            State::HVOn => self.entry_hv_on(),
            State::Levitating => self.entry_levitating(),
            State::MovingST => self.entry_mv_st(),
            State::MovingLSST => self.entry_cruising(),
            State::MovingLSCV => self.entry_ls_cv(),
            State::EndST => self.entry_end_st(),
            State::EndLS => self.entry_end_ls(),
            State::EmergencyBraking => {
                self.entry_emergency_braking();
                self.pod_safe().await;
            },
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
            Event::EmergencyBrake
            | Event::LevitationErrorEvent
            | Event::PropulsionErrorEvent
            | Event::PowertrainErrorEvent
            | Event::ConnectionLossEvent
            | Event::ValueOutOfBounds => {
                transit!(self, State::EmergencyBraking);
                return;
            },

            Event::Heartbeat => {
                self.data_queue
                    .send(Datapoint::new(
                        Datatype::FSMState,
                        self.state as u64,
                        Instant::now().as_ticks(),
                    ))
                    .await;
            },

            Event::ExitEvent => {
                transit!(self, State::Exit);
                return;
            },

            ///////////////////
            // Debugging events

            // Enable or disable braking from a falling edge of the braking communication signal
            Event::PreventBrakingComm => unsafe {
                ENABLE_BRAKING_COMM = false;
            },
            Event::EnableBrakingComm => unsafe {
                ENABLE_BRAKING_COMM = true;
            },

            // Override enabling or disabling propulsion GPIO
            Event::DisablePropulsionCommand => {
                self.peripherals.propulsion_controller.disable();
                self.log(Info::DisablePropulsionGpio).await;
                self.send_data(Datatype::PropGPIODebug, 0).await;
            },
            Event::EnablePropulsionCommand => {
                self.peripherals.propulsion_controller.enable();
                self.log(Info::EnablePropulsionGpio).await;
                self.send_data(Datatype::PropGPIODebug, 1).await;
            },
            // Override immediately setting the speed of the propulsion controller
            Event::SetCurrentSpeedCommand(x) => {
                self.peripherals.propulsion_controller.set_speed(x as u8);
                self.send_data(Datatype::PropulsionSpeed, x).await;
            },

            ///////////////////
            _ => {
                trace!("Event has no override, continuing...");
            },
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
            State::EndLS => self.react_end_ls(event).await,
            State::Exit => self.react_exit(event).await,
            State::EmergencyBraking => self.react_emergency_braking(event).await,
            State::Crashing => self.log(Info::Crashed).await,
        }
    }

    /// # Send data to the ground station
    #[allow(unused)]
    pub async fn send_data(&mut self, dtype: Datatype, data: u64) {
        self.data_queue.send(Datapoint::new(dtype, data, Instant::now().as_ticks())).await;
    }

    /// # Send a command to Levi
    /// Send a command to the Levitation controller
    #[allow(unused)]
    pub async fn send_levi_cmd(&mut self, cmd: crate::Command) {
        self.data_queue
            .send(Datapoint::new(
                Datatype::LeviInstruction,
                cmd.to_id() as u64,
                Instant::now().as_ticks(),
            ))
            .await;
    }

    /// # Log an info message
    /// Send an info message to the ground station,
    /// from the `enum Info`
    pub async fn log(&self, info: Info) {
        self.data_queue
            .send(Datapoint::new(Datatype::Info, info.to_idx(), Instant::now().as_ticks()))
            .await;
    }

    /// Tell the ground station that the pod is now safe to approach (HV off)
    pub async fn pod_safe(&self) {
        self.data_queue
            .send(Datapoint::new(
                Datatype::Info,
                Info::to_idx(&Info::Safe),
                Instant::now().as_ticks(),
            ))
            .await;
    }

    /// Tell the ground station that the pod is not safe to approach (HV on)
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
