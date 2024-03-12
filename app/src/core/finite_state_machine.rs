use defmt::*;
use embassy_stm32;
use embassy_stm32::Peripherals;


//Enum holding different states that the FSM can be in
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


//All the functionalities states can have like converting to id's or format print statements should go here
//! The actual implementation of each state should just be attached to the state machine in separate files
impl State {
    pub fn fmt(&self) {
        match self {
            State::Boot => info!("Boot"),
            State::EstablishConnection => info!("EstablishConnection"),
            State::Idle => info!("Idle"),
            State::HVSystemChecking => info!("HVSystemChecking"),
            State::Levitating => info!("Levitating"),
            State::Accelerating => info!("Accelerating"),
            State::Cruising => info!("Cruising"),
            State::LaneSwitch => info!("LaneSwitching"),
            State::Braking => info!("Braking"),
            State::EmergencyBraking => info!("EmergencyBraking"),
            State::Exit => info!("Quit"),
            State::Crashing => info!("Crashing"),
            _ => info! { "Unknown"},
        }
    }
}


//Enum holding different events that the FSM can react to
pub enum Event {
    // Boot state related events
    BootingCompleteEvent,
    BootingFailedEvent,

    // Establish Connection state related events
    ConnectionEstablishedEvent,
    ConnectionEstablishmentFailedEvent,

    // Run Config state related events
    RunConfigCompleteEvent,
    RunConfigFailedEvent,

    //Error Handling events
    LevitationErrorEvent,
    PropulsionErrorEvent,
    PowertrainErrorEvent,
    EmergencyBrakeCommand,
    ConnectionLossEvent,

    // Idle state related events
    LVLevitationReadyEvent,
    LVPropulsionReadyEvent,
    LVPowertrainReadyEvent,
    ArmBrakesCommand,


    // HV System Checking state
    HVPowertrainReadyEvent,
    HVLevitationReadyEvent,
    StartLevitatingCommand,

    // Levitating
    HVPropulsionReadyEvent,
    StartAcceleratingCommand,

    // Accelerating
    DesiredSpeedReachedEvent,
    BrakingPointReachedEvent,

    // Cruising
    LaneSwitchingPointReachedEvent,


    //LaneSwitching
    LaneSwitchingCompleteEvent,

    // Braking
    DirectionChangedEvent,
    RunFinishedEvent,

    // EmergencyBraking
    SystemResetCommand,

    ExitEvent,
}
// Again some functionalities that might be useful for the events to have mut be here
impl Event {
    pub fn fmt(&self) {
        match self {
            Event::BootingCompleteEvent => info!("BootingCompleteEvent"),
            Event::BootingFailedEvent => info!("BootingFailedEvent"),
            Event::ConnectionEstablishedEvent => info!("ConnectionEstablishedEvent"),
            Event::ConnectionEstablishmentFailedEvent => { info!("ConnectionEstablishmentFailedEvent") }
            Event::LVLevitationReadyEvent => info!("LVLevitationReadyEvent"),
            Event::LVPropulsionReadyEvent => info!("LVPropulsionReadyEvent"),
            Event::LVPowertrainReadyEvent => info!("LVPowertrainReadyEvent"),
            Event::HVPowertrainReadyEvent => info!("HVPowertrainReadyEvent"),
            Event::HVLevitationReadyEvent => info!("HVLevitationReadyEvent"),
            Event::StartLevitatingCommand => info!("StartLevitatingCommand"),
            Event::HVPropulsionReadyEvent => info!("HVPropulsionReadyEvent"),
            Event::StartAcceleratingCommand => info!("StartAcceleratingCommand"),
            Event::DesiredSpeedReachedEvent => info!("DesiredSpeedReachedEvent"),
            Event::BrakingPointReachedEvent => info!("BrakingPointReachedEvent"),
            Event::DirectionChangedEvent => info!("DirectionChangedEvent"),
            Event::SystemResetCommand => info!("SystemResetCommand"),
            Event::LevitationErrorEvent => info!("LevitationErrorEvent"),
            Event::PropulsionErrorEvent => info!("PropulsionErrorEvent"),
            Event::PowertrainErrorEvent => info!("PowertrainErrorEvent"),
            Event::EmergencyBrakeCommand => info!("EmergencyBrakeCommand"),
            Event::RunFinishedEvent => info!("RunFinishedEvent"),
            Event::LaneSwitchingPointReachedEvent => info!("LaneSwitchingPointReachedEvent"),
            Event::LaneSwitchingCompleteEvent => info!("LaneSwitchingCompleteEvent"),
            Event::ConnectionLossEvent => info!("ConnectionLossEvent"),
            Event::ArmBrakesCommand => info!("ArmBrakesCommand"),
            Event::ExitEvent => info!("QuitEvent"),
            _ => info! { "Unknown"},
        }
    }
}

//!TODO: Add all the parameters that the FSM might need to have
//! This bad boy will be a singleton and it will be passed around everywhere
//! Just be careful with the STD's
pub struct FSM {
    state: State,
    peripherals: Peripherals,
}

impl FSM {
    pub fn new(p: Peripherals) -> Self {

        //TODO: Decide if main should be dirty with peripheral initialization or if it should be done here

        Self {
            state: State::Boot,
            peripherals:p,
        }
    }
    pub fn entry(&mut self) {
        match self.state {
            State::Boot => {
                self.boot_entry();
            }
            State::EstablishConnection => {
                self.entry_establish_connection();
            }
            State::Idle => {
                self.entry_idle();
            }
            State::RunConfig => {
                self.entry_path_checking();
            }
            State::HVSystemChecking => {
                self.entry_hv_system_checking();
            }
            State::Levitating => {
                self.entry_levitating();
            }
            State::Accelerating => {
                self.entry_accelerating();
            }
            State::Cruising => {
                self.entry_cruising();
            }
            State::LaneSwitch => {
                self.entry_lane_switching();
            }
            State::Braking => {
                self.entry_braking();
            }
            State::EmergencyBraking => {
                self.entry_emergency_braking();
            }
            State::Exit => {
                self.entry_exit();
            }
            _ => {
                info!("Im going against a wall for sure this time");//<--- This is what happens if the Crashing state ever gets triggered
            }
        }
    }
    pub(crate) fn react(&mut self, event: Event) {
        match self.state {
            State::Boot => {
                self.react_boot(event);
            }
            State::EstablishConnection => {
                self.react_establish_connection(event);
            }
            State::Idle => {
                self.react_idle(event);
            }
            State::RunConfig => {
                self.react_path_checking(event);
            }
            State::HVSystemChecking => {
                self.react_hv_system_checking(event);
            }
            State::Levitating => {
                self.react_levitating(event);
            }
            State::Accelerating => {
                self.react_accelerating(event);
            }
            State::Cruising => {
                self.react_cruising(event);
            }
            State::LaneSwitch => {
                self.react_lane_switching(event);
            }
            State::Braking => {
                self.react_braking(event);
            }
            State::Exit => {
                self.react_exit(event);
            }
            _ => {
                info!("Unknown state"); // <---- Kiko: Im forced to have this here but im against it
            }
        }
    }

    fn exit(&mut self) {
        match self.state {
            State::Boot => {
                self.exit_boot();
            }
            State::EstablishConnection => {
                self.exit_establish_connection();
            }
            State::Idle => {
                self.exit_idle();
            }
            State::RunConfig => {
                self.exit_path_checking();
            }
            State::HVSystemChecking => {
                self.exit_hv_system_checking();
            }
            State::Levitating => {
                self.exit_levitating();
            }
            State::Accelerating => {
                self.exit_accelerating();
            }
            State::Cruising => {
                self.exit_cruising();
            }
            State::LaneSwitch => {
                self.exit_lane_switching();
            }
            State::Braking => {
                self.exit_braking();
            }
            State::EmergencyBraking => {
                self.exit_emergency_braking();
            }
            State::Crashing => {
                self.exit_crashing();
            }
            State::Exit => {
                self.exit_exit();
            }
            _ => {
                info!("Unknown state"); // <---- Kiko: If this is ever triggered something is very wrong
            }
        }
    }
}
