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
        Datatype::BatteryEstimatedChargeHigh | Datatype::BatteryEstimatedChargeLow => x / 100.0,
        Datatype::TotalBatteryVoltageHigh | Datatype::TotalBatteryVoltageLow => x / 100.0 - 2.0,
        Datatype::BatteryCurrentLow => x / 10.0 + 150.0,
        Datatype::BatteryCurrentHigh => x / 10.0 + 10.0,

        Datatype::BrakingCommDebug => x * 3.3 / 65535.0,

        Datatype::IMDVoltageDetails => {
            if datapoint.value == 65535 {
                0.0
            } else {
                x * 0.005 * 110.0 / 250.0
            }
        },

        Datatype::Localisation => x * 1.6,

        _ => x,
    };

    ProcessedData {
        datatype: datapoint.datatype,
        value,
        timestamp: datapoint.timestamp,
        style,
        units: datapoint.datatype.unit(),
    }
}
