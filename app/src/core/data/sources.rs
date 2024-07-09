use crate::Datatype;

pub enum Subsystems {
    GroundStation,
    SensorHub,
    Propulsion,
    Batteries,
    Levitation,
}

pub const GROUND_STATION_DATA: [Datatype; 1] = [
    Datatype::ResponseHeartbeat,
];

pub const SENSOR_HUB_DATA: [Datatype; 9] = [
    Datatype::Acceleration,
    Datatype::Velocity,
    Datatype::Localisation,
    Datatype::AccelerationX,
    Datatype::AccelerationY,
    Datatype::AccelerationZ,
    Datatype::GyroscopeX,
    Datatype::GyroscopeY,
    Datatype::GyroscopeZ,
];

pub const PROPULSION_DATA: [Datatype; 3] = [
    Datatype::PropulsionSpeed,
    Datatype::PropulsionVoltage,
    Datatype::PropulsionCurrent,
];

pub const HV_BMS_DATA: [Datatype; 3] = [
    Datatype::BatteryBalanceHigh,
    Datatype::BatteryCurrentHigh,
    Datatype::BatteryEstimatedChargeHigh,
];

pub const LV_BMS_DATA: [Datatype; 6] = [
    Datatype::BatteryBalanceLow,
    Datatype::BatteryCurrentLow,
    Datatype::BatteryEstimatedChargeLow,
    Datatype::BatteryVoltageLow,
    Datatype::BatteryTemperatureLow,
    Datatype::ChargeStateLow,
];
