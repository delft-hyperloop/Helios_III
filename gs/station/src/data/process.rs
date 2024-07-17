use crate::api::Datapoint;
use crate::api::ProcessedData;
use crate::Datatype;
use crate::ValueCheckResult;

/// Preprocessing data from the pod before sending to the frontend
pub fn process(datapoint: &Datapoint) -> ProcessedData {
    let style = match datapoint.datatype.check_bounds(datapoint.value) {
        ValueCheckResult::Fine => "".to_string(),
        ValueCheckResult::Warn => "warning".to_string(),
        ValueCheckResult::Error => "error".to_string(),
        ValueCheckResult::BrakeNow => "critical".to_string(),
    };
    let x = datapoint.value as f64;
    let value = match datapoint.datatype {
        Datatype::ChargeStateLow | Datatype::ChargeStateHigh => x * 0.01,
        Datatype::TotalBatteryVoltageHigh | Datatype::TotalBatteryVoltageLow => x / 100.0 - 2.0,
        Datatype::BatteryCurrentLow | Datatype::BatteryCurrentHigh => (x - 2000.0) * 0.1,
        Datatype::BrakingCommDebug => x * 3.3 / 65535.0,
        Datatype::IMDVoltageDetails => {
            if datapoint.value == 65535 {
                0.0
            } else {
                x * 0.005 * 110.0 / 250.0
            }
        },

        Datatype::Localisation => x * 1.6,

        Datatype::Module1AvgTemperature
        | Datatype::Module2AvgTemperature
        | Datatype::Module3AvgTemperature
        | Datatype::Module4AvgTemperature
        | Datatype::Module5AvgTemperature
        | Datatype::Module6AvgTemperature
        | Datatype::Module7AvgTemperature
        | Datatype::Module8AvgTemperature
        | Datatype::Module1MinTemperature
        | Datatype::Module2MinTemperature
        | Datatype::Module3MinTemperature
        | Datatype::Module4MinTemperature
        | Datatype::Module5MinTemperature
        | Datatype::Module6MinTemperature
        | Datatype::Module7MinTemperature
        | Datatype::Module8MinTemperature
        | Datatype::Module1MaxTemperature
        | Datatype::Module2MaxTemperature
        | Datatype::Module3MaxTemperature
        | Datatype::Module4MaxTemperature
        | Datatype::Module5MaxTemperature
        | Datatype::Module6MaxTemperature
        | Datatype::Module7MaxTemperature
        | Datatype::Module8MaxTemperature
        | Datatype::BatteryMinTemperatureHigh
        | Datatype::BatteryMaxTemperatureHigh
        | Datatype::BatteryTemperatureHigh
        | Datatype::BatteryTemperatureLow
        | Datatype::BatteryMinTemperatureLow
        | Datatype::BatteryMaxTemperatureLow => {
            if x - 100.0 <= 0.0 {
                0.0
            } else {
                x - 100.0
            }
        },
        Datatype::Module1AvgVoltage
        | Datatype::Module2AvgVoltage
        | Datatype::Module3AvgVoltage
        | Datatype::Module4AvgVoltage
        | Datatype::Module5AvgVoltage
        | Datatype::Module6AvgVoltage
        | Datatype::Module7AvgVoltage
        | Datatype::Module8AvgVoltage
        | Datatype::Module1MinVoltage
        | Datatype::Module2MinVoltage
        | Datatype::Module3MinVoltage
        | Datatype::Module4MinVoltage
        | Datatype::Module5MinVoltage
        | Datatype::Module6MinVoltage
        | Datatype::Module7MinVoltage
        | Datatype::Module8MinVoltage
        | Datatype::Module1MaxVoltage
        | Datatype::Module2MaxVoltage
        | Datatype::Module3MaxVoltage
        | Datatype::Module4MaxVoltage
        | Datatype::Module5MaxVoltage
        | Datatype::Module6MaxVoltage
        | Datatype::Module7MaxVoltage
        | Datatype::Module8MaxVoltage
        | Datatype::BatteryMinVoltageLow
        | Datatype::BatteryMaxVoltageHigh
        | Datatype::BatteryMinVoltageHigh
        | Datatype::BatteryMaxVoltageLow
        | Datatype::BatteryVoltageHigh
        | Datatype::BatteryVoltageLow => {
            if x == 200.0 {
                0.0
            } else {
                x / 100.0
            }
        },
        Datatype::Velocity => x / 100.0,
        Datatype::BrakeTemperature | Datatype::BrakePressure => {
            if x > 100_000_000.0 {
                0.0
            } else {
                x / 100.0
            }
        },
        Datatype::GyroscopeX
        | Datatype::GyroscopeY
        | Datatype::GyroscopeZ
        | Datatype::AccelerationX
        | Datatype::AccelerationY
        | Datatype::AccelerationZ => {
            if x > 4_294_967_295.0 - 100000.0 {
                (4_294_967_295.0 - x + 1.0) / 100.0
            } else {
                x / 100.0
            }
        },
        Datatype::Average_Temp_VB_Bottom
        | Datatype::Average_Temp_VB_top
        | Datatype::Temp_HEMS_1
        | Datatype::Temp_HEMS_2
        | Datatype::Temp_HEMS_3
        | Datatype::Temp_HEMS_4
        | Datatype::Temp_Motor_1
        | Datatype::Temp_Motor_2
        | Datatype::Ambient_presure
        | Datatype::Ambient_temp
        | Datatype::Temp_EMS_1
        | Datatype::Temp_EMS_2
        | Datatype::Temp_EMS_3
        | Datatype::Temp_EMS_4 => x / 100.0,
        _ => x,
    };

    let significant = (value * 1000.0).round() / 1000.0;

    ProcessedData {
        datatype: datapoint.datatype,
        value: significant,
        timestamp: datapoint.timestamp,
        style,
        units: datapoint.datatype.unit(),
    }
}
