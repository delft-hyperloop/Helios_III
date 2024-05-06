pub static GS_IP_ADDRESS: ([u8;4],u16) = ([192,168,1,4],6942);
pub static GS_UPD_IP_ADDRESS: ([u8;4],u16) = ([192,168,1,4],6943);
pub const NETWORK_BUFFER_SIZE: usize = 1460;
pub const IP_TIMEOUT: u64 = 15000;
pub static POD_IP_ADDRESS: ([u8;4],u16) = ([192,168,1,69],17034);
pub static POD_UDP_IP_ADDRESS: ([u8;4],u16) = ([192,168,1,69],17035);
pub static POD_MAC_ADDRESS: [u8;6] = [0,30,103,76,92,62];
pub const KEEP_ALIVE: u64 = 1000;
pub const EVENT_QUEUE_SIZE: usize = 128;
pub const DATA_QUEUE_SIZE: usize = 256;
pub const CAN_QUEUE_SIZE: usize = 128;
pub const LV_IDS: [u16;2] = [69, 42];
pub const HV_IDS: [u16;0] = [];
pub const GFD_IDS: [u16;0] = [];
pub const BATTERY_GFD_IDS: [u16;2] = [69, 42];


pub enum Command {
    DefaultCommand(u64),
    Levitate(u64),
    StopLevitating(u64),
    Configure(u64),
    StartRun(u64),
    EmergencyBrake(u64),
    Shutdown(u64),
    StartHV(u64),
    StopHV(u64),

}
impl Command {
    pub fn to_id(&self)->u16 {
        match *self {
            Command::DefaultCommand(_) => 1,
            Command::Levitate(_) => 90,
            Command::StopLevitating(_) => 91,
            Command::Configure(_) => 92,
            Command::StartRun(_) => 93,
            Command::EmergencyBrake(_) => 255,
            Command::Shutdown(_) => 95,
            Command::StartHV(_) => 96,
            Command::StopHV(_) => 97,

        }
    }
    pub fn from_id(id:u16) -> Self {
        match id {
            1 => Command::DefaultCommand(0u64),
            90 => Command::Levitate(0u64),
            91 => Command::StopLevitating(0u64),
            92 => Command::Configure(0u64),
            93 => Command::StartRun(0u64),
            255 => Command::EmergencyBrake(0u64),
            95 => Command::Shutdown(0u64),
            96 => Command::StartHV(0u64),
            97 => Command::StopHV(0u64),

            _ => Command::DefaultCommand(0)
        }
    }
}

pub enum Datatype {
    DefaultDatatype,
    PropulsionTemperature,
    LevitationTemperature,
    BatteryVoltage,
    TotalBatteryVoltage,
    BatteryTemperature,
    BatteryBalance,
    SingleCellVoltage,
    SingleCellTemperature,
    ChargeState,
    BatteryCurrent,
    BrakeTemperature,
    PropulsionSpeed,
    BrakePressure,
    HighVoltage,
    HighVoltageInsulation,
    FSMState,
    FSMEvent,
    PodDropTriggered,
    Localisation,
    GFDIsolation,
    DefaultBMS,
    UnknownCanId,
    Info,

}

impl Datatype {
    pub fn to_id(&self)->u16 {
        match *self {
            Datatype::DefaultDatatype => 0,
            Datatype::PropulsionTemperature => 10,
            Datatype::LevitationTemperature => 11,
            Datatype::BatteryVoltage => 413,
            Datatype::TotalBatteryVoltage => 418,
            Datatype::BatteryTemperature => 420,
            Datatype::BatteryBalance => 416,
            Datatype::SingleCellVoltage => 444,
            Datatype::SingleCellTemperature => 476,
            Datatype::ChargeState => 417,
            Datatype::BatteryCurrent => 419,
            Datatype::BrakeTemperature => 19,
            Datatype::PropulsionSpeed => 20,
            Datatype::BrakePressure => 21,
            Datatype::HighVoltage => 22,
            Datatype::HighVoltageInsulation => 23,
            Datatype::FSMState => 24,
            Datatype::FSMEvent => 25,
            Datatype::PodDropTriggered => 26,
            Datatype::Localisation => 27,
            Datatype::GFDIsolation => 56,
            Datatype::DefaultBMS => 412,
            Datatype::UnknownCanId => 2032,
            Datatype::Info => 2042,

        }
    }
    pub fn from_id(id:u16) -> Self {
        match id {
            0 => Datatype::DefaultDatatype,
            10 => Datatype::PropulsionTemperature,
            11 => Datatype::LevitationTemperature,
            413 => Datatype::BatteryVoltage,
            418 => Datatype::TotalBatteryVoltage,
            420 => Datatype::BatteryTemperature,
            416 => Datatype::BatteryBalance,
            444 => Datatype::SingleCellVoltage,
            476 => Datatype::SingleCellTemperature,
            417 => Datatype::ChargeState,
            419 => Datatype::BatteryCurrent,
            19 => Datatype::BrakeTemperature,
            20 => Datatype::PropulsionSpeed,
            21 => Datatype::BrakePressure,
            22 => Datatype::HighVoltage,
            23 => Datatype::HighVoltageInsulation,
            24 => Datatype::FSMState,
            25 => Datatype::FSMEvent,
            26 => Datatype::PodDropTriggered,
            27 => Datatype::Localisation,
            56 => Datatype::GFDIsolation,
            412 => Datatype::DefaultBMS,
            2032 => Datatype::UnknownCanId,
            2042 => Datatype::Info,

            _ => Datatype::DefaultDatatype,
        }
    }
}
pub static DATA_IDS : [u16;24] = [0, 10, 11, 413, 418, 420, 416, 444, 476, 417, 419, 19, 20, 21, 22, 23, 24, 25, 26, 27, 56, 412, 2032, 2042];


pub static EVENTS_DISPLAY: [&str; 34] = ["DefaultEvent","BootingCompleteEvent","BootingFailedEvent","ConnectionEstablishedEvent","ConnectionEstablishmentFailedEvent","SetRunConfig","RunConfigCompleteEvent","RunConfigFailedEvent","LevitationErrorEvent","PropulsionErrorEvent","PowertrainErrorEvent","EmergencyBrakeCommand","ConnectionLossEvent","LVLevitationReadyEvent","LVPropulsionReadyEvent","LVPowertrainReadyEvent","ArmBrakesCommand","TurnOnHVCommand","HVPowertrainReadyEvent","HVLevitationReadyEvent","StartLevitatingCommand","HVPropulsionReadyEvent","StartAcceleratingCommand","DesiredSpeedReachedEvent","BrakingPointReachedEvent","LaneSwitchingPointReachedEvent","LaneSwitchingCompleteEvent","DirectionChangedEvent","RunFinishedEvent","SystemResetCommand","PodDropSwitchTriggered","EndOfTrackReached","ExitEvent","Unknown"];

#[derive(Debug, PartialEq, Eq)]
pub enum Event {
    DefaultEvent,
    BootingCompleteEvent,
    BootingFailedEvent,
    ConnectionEstablishedEvent,
    ConnectionEstablishmentFailedEvent,
    SetRunConfig(u64),
    RunConfigCompleteEvent,
    RunConfigFailedEvent,
    LevitationErrorEvent,
    PropulsionErrorEvent,
    PowertrainErrorEvent,
    EmergencyBrakeCommand,
    ConnectionLossEvent,
    LVLevitationReadyEvent,
    LVPropulsionReadyEvent,
    LVPowertrainReadyEvent,
    ArmBrakesCommand,
    TurnOnHVCommand,
    HVPowertrainReadyEvent,
    HVLevitationReadyEvent,
    StartLevitatingCommand,
    HVPropulsionReadyEvent,
    StartAcceleratingCommand,
    DesiredSpeedReachedEvent,
    BrakingPointReachedEvent,
    LaneSwitchingPointReachedEvent,
    LaneSwitchingCompleteEvent,
    DirectionChangedEvent,
    RunFinishedEvent,
    SystemResetCommand,
    PodDropSwitchTriggered,
    EndOfTrackReached,
    ExitEvent,

}
impl Event {
    pub fn to_id(&self)->u16 {
        match *self {
            Event::DefaultEvent => 2,
            Event::BootingCompleteEvent => 161,
            Event::BootingFailedEvent => 162,
            Event::ConnectionEstablishedEvent => 163,
            Event::ConnectionEstablishmentFailedEvent => 164,
            Event::SetRunConfig(_) => 165,
            Event::RunConfigCompleteEvent => 166,
            Event::RunConfigFailedEvent => 167,
            Event::LevitationErrorEvent => 168,
            Event::PropulsionErrorEvent => 169,
            Event::PowertrainErrorEvent => 170,
            Event::EmergencyBrakeCommand => 171,
            Event::ConnectionLossEvent => 172,
            Event::LVLevitationReadyEvent => 173,
            Event::LVPropulsionReadyEvent => 174,
            Event::LVPowertrainReadyEvent => 175,
            Event::ArmBrakesCommand => 176,
            Event::TurnOnHVCommand => 177,
            Event::HVPowertrainReadyEvent => 178,
            Event::HVLevitationReadyEvent => 179,
            Event::StartLevitatingCommand => 180,
            Event::HVPropulsionReadyEvent => 181,
            Event::StartAcceleratingCommand => 182,
            Event::DesiredSpeedReachedEvent => 183,
            Event::BrakingPointReachedEvent => 184,
            Event::LaneSwitchingPointReachedEvent => 185,
            Event::LaneSwitchingCompleteEvent => 186,
            Event::DirectionChangedEvent => 187,
            Event::RunFinishedEvent => 188,
            Event::SystemResetCommand => 189,
            Event::PodDropSwitchTriggered => 190,
            Event::EndOfTrackReached => 191,
            Event::ExitEvent => 192,

        }
    }
    pub fn from_id(id:u16) -> Self {
        match id {
            2 => Event::DefaultEvent,
            161 => Event::BootingCompleteEvent,
            162 => Event::BootingFailedEvent,
            163 => Event::ConnectionEstablishedEvent,
            164 => Event::ConnectionEstablishmentFailedEvent,
            165 => Event::SetRunConfig(0),
            166 => Event::RunConfigCompleteEvent,
            167 => Event::RunConfigFailedEvent,
            168 => Event::LevitationErrorEvent,
            169 => Event::PropulsionErrorEvent,
            170 => Event::PowertrainErrorEvent,
            171 => Event::EmergencyBrakeCommand,
            172 => Event::ConnectionLossEvent,
            173 => Event::LVLevitationReadyEvent,
            174 => Event::LVPropulsionReadyEvent,
            175 => Event::LVPowertrainReadyEvent,
            176 => Event::ArmBrakesCommand,
            177 => Event::TurnOnHVCommand,
            178 => Event::HVPowertrainReadyEvent,
            179 => Event::HVLevitationReadyEvent,
            180 => Event::StartLevitatingCommand,
            181 => Event::HVPropulsionReadyEvent,
            182 => Event::StartAcceleratingCommand,
            183 => Event::DesiredSpeedReachedEvent,
            184 => Event::BrakingPointReachedEvent,
            185 => Event::LaneSwitchingPointReachedEvent,
            186 => Event::LaneSwitchingCompleteEvent,
            187 => Event::DirectionChangedEvent,
            188 => Event::RunFinishedEvent,
            189 => Event::SystemResetCommand,
            190 => Event::PodDropSwitchTriggered,
            191 => Event::EndOfTrackReached,
            192 => Event::ExitEvent,

            _ => Event::DefaultEvent,
        }
    }
    pub fn priority(&self) -> usize {
        match self {
            Event::DefaultEvent => 0,
            Event::BootingCompleteEvent => 0,
            Event::BootingFailedEvent => 0,
            Event::ConnectionEstablishedEvent => 0,
            Event::ConnectionEstablishmentFailedEvent => 0,
            Event::SetRunConfig(_) => 0,
            Event::RunConfigCompleteEvent => 0,
            Event::RunConfigFailedEvent => 0,
            Event::LevitationErrorEvent => 4,
            Event::PropulsionErrorEvent => 3,
            Event::PowertrainErrorEvent => 2,
            Event::EmergencyBrakeCommand => 10,
            Event::ConnectionLossEvent => 1,
            Event::LVLevitationReadyEvent => 0,
            Event::LVPropulsionReadyEvent => 0,
            Event::LVPowertrainReadyEvent => 0,
            Event::ArmBrakesCommand => 0,
            Event::TurnOnHVCommand => 0,
            Event::HVPowertrainReadyEvent => 0,
            Event::HVLevitationReadyEvent => 0,
            Event::StartLevitatingCommand => 0,
            Event::HVPropulsionReadyEvent => 0,
            Event::StartAcceleratingCommand => 0,
            Event::DesiredSpeedReachedEvent => 0,
            Event::BrakingPointReachedEvent => 0,
            Event::LaneSwitchingPointReachedEvent => 0,
            Event::LaneSwitchingCompleteEvent => 0,
            Event::DirectionChangedEvent => 0,
            Event::RunFinishedEvent => 0,
            Event::SystemResetCommand => 0,
            Event::PodDropSwitchTriggered => 5,
            Event::EndOfTrackReached => 5,
            Event::ExitEvent => 0,

            _ => 0,
        }
    }
    fn to_idx(&self) -> usize {
        match self {
            Event::DefaultEvent => 0,
            Event::BootingCompleteEvent => 1,
            Event::BootingFailedEvent => 2,
            Event::ConnectionEstablishedEvent => 3,
            Event::ConnectionEstablishmentFailedEvent => 4,
            Event::SetRunConfig(_) => 5,
            Event::RunConfigCompleteEvent => 6,
            Event::RunConfigFailedEvent => 7,
            Event::LevitationErrorEvent => 8,
            Event::PropulsionErrorEvent => 9,
            Event::PowertrainErrorEvent => 10,
            Event::EmergencyBrakeCommand => 11,
            Event::ConnectionLossEvent => 12,
            Event::LVLevitationReadyEvent => 13,
            Event::LVPropulsionReadyEvent => 14,
            Event::LVPowertrainReadyEvent => 15,
            Event::ArmBrakesCommand => 16,
            Event::TurnOnHVCommand => 17,
            Event::HVPowertrainReadyEvent => 18,
            Event::HVLevitationReadyEvent => 19,
            Event::StartLevitatingCommand => 20,
            Event::HVPropulsionReadyEvent => 21,
            Event::StartAcceleratingCommand => 22,
            Event::DesiredSpeedReachedEvent => 23,
            Event::BrakingPointReachedEvent => 24,
            Event::LaneSwitchingPointReachedEvent => 25,
            Event::LaneSwitchingCompleteEvent => 26,
            Event::DirectionChangedEvent => 27,
            Event::RunFinishedEvent => 28,
            Event::SystemResetCommand => 29,
            Event::PodDropSwitchTriggered => 30,
            Event::EndOfTrackReached => 31,
            Event::ExitEvent => 32,

            _ => 33,
        }
    }
    pub fn to_str(&self) -> &'static str {
        EVENTS_DISPLAY[self.to_idx()]
    }
}

pub static EVENT_IDS : [u16;33] = [2, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192];
