use gslib::Datapoint;
use gslib::Datatype;
use gslib::ProcessedData;
use gslib::ValueCheckResult;

/// Preprocessing data from the pod before sending to the frontend
pub fn process(datapoint: &Datapoint) -> ProcessedData {
    let style = match datapoint.datatype.check_bounds(datapoint.value) {
        ValueCheckResult::Fine => "".to_string(),
        ValueCheckResult::Warn => "yellow".to_string(),
        ValueCheckResult::Error => "warning".to_string(),
        ValueCheckResult::BrakeNow => "error".to_string(),
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
        | Datatype::BatteryVoltageLow
        | Datatype::SingleCellVoltageLV1
        | Datatype::SingleCellVoltageLV2
        | Datatype::SingleCellVoltageLV3
        | Datatype::SingleCellVoltageLV4
        | Datatype::SingleCellVoltageLV5
        | Datatype::SingleCellVoltageLV6
        | Datatype::SingleCellVoltageLV7
        | Datatype::SingleCellVoltageLV8
        | Datatype::SingleCellVoltageHV1
        | Datatype::SingleCellVoltageHV2
        | Datatype::SingleCellVoltageHV3
        | Datatype::SingleCellVoltageHV4
        | Datatype::SingleCellVoltageHV5
        | Datatype::SingleCellVoltageHV6
        | Datatype::SingleCellVoltageHV7
        | Datatype::SingleCellVoltageHV8
        | Datatype::SingleCellVoltageHV9
        | Datatype::SingleCellVoltageHV10
        | Datatype::SingleCellVoltageHV11
        | Datatype::SingleCellVoltageHV12
        | Datatype::SingleCellVoltageHV13
        | Datatype::SingleCellVoltageHV14
        | Datatype::SingleCellVoltageHV15
        | Datatype::SingleCellVoltageHV16
        | Datatype::SingleCellVoltageHV17
        | Datatype::SingleCellVoltageHV18
        | Datatype::SingleCellVoltageHV19
        | Datatype::SingleCellVoltageHV20
        | Datatype::SingleCellVoltageHV21
        | Datatype::SingleCellVoltageHV22
        | Datatype::SingleCellVoltageHV23
        | Datatype::SingleCellVoltageHV24
        | Datatype::SingleCellVoltageHV25
        | Datatype::SingleCellVoltageHV26
        | Datatype::SingleCellVoltageHV27
        | Datatype::SingleCellVoltageHV28
        | Datatype::SingleCellVoltageHV29
        | Datatype::SingleCellVoltageHV30
        | Datatype::SingleCellVoltageHV31
        | Datatype::SingleCellVoltageHV32
        | Datatype::SingleCellVoltageHV33
        | Datatype::SingleCellVoltageHV34
        | Datatype::SingleCellVoltageHV35
        | Datatype::SingleCellVoltageHV36
        | Datatype::SingleCellVoltageHV37
        | Datatype::SingleCellVoltageHV38
        | Datatype::SingleCellVoltageHV39
        | Datatype::SingleCellVoltageHV40
        | Datatype::SingleCellVoltageHV41
        | Datatype::SingleCellVoltageHV42
        | Datatype::SingleCellVoltageHV43
        | Datatype::SingleCellVoltageHV44
        | Datatype::SingleCellVoltageHV45
        | Datatype::SingleCellVoltageHV46
        | Datatype::SingleCellVoltageHV47
        | Datatype::SingleCellVoltageHV48
        | Datatype::SingleCellVoltageHV49
        | Datatype::SingleCellVoltageHV50
        | Datatype::SingleCellVoltageHV51
        | Datatype::SingleCellVoltageHV52
        | Datatype::SingleCellVoltageHV53
        | Datatype::SingleCellVoltageHV54
        | Datatype::SingleCellVoltageHV55
        | Datatype::SingleCellVoltageHV56
        | Datatype::SingleCellVoltageHV57
        | Datatype::SingleCellVoltageHV58
        | Datatype::SingleCellVoltageHV59
        | Datatype::SingleCellVoltageHV60
        | Datatype::SingleCellVoltageHV61
        | Datatype::SingleCellVoltageHV62
        | Datatype::SingleCellVoltageHV63
        | Datatype::SingleCellVoltageHV64
        | Datatype::SingleCellVoltageHV65
        | Datatype::SingleCellVoltageHV66
        | Datatype::SingleCellVoltageHV67
        | Datatype::SingleCellVoltageHV68
        | Datatype::SingleCellVoltageHV69
        | Datatype::SingleCellVoltageHV70
        | Datatype::SingleCellVoltageHV71
        | Datatype::SingleCellVoltageHV72
        | Datatype::SingleCellVoltageHV73
        | Datatype::SingleCellVoltageHV74
        | Datatype::SingleCellVoltageHV75
        | Datatype::SingleCellVoltageHV76
        | Datatype::SingleCellVoltageHV77
        | Datatype::SingleCellVoltageHV78
        | Datatype::SingleCellVoltageHV79
        | Datatype::SingleCellVoltageHV80
        | Datatype::SingleCellVoltageHV81
        | Datatype::SingleCellVoltageHV82
        | Datatype::SingleCellVoltageHV83
        | Datatype::SingleCellVoltageHV84
        | Datatype::SingleCellVoltageHV85
        | Datatype::SingleCellVoltageHV86
        | Datatype::SingleCellVoltageHV87
        | Datatype::SingleCellVoltageHV88
        | Datatype::SingleCellVoltageHV89
        | Datatype::SingleCellVoltageHV90
        | Datatype::SingleCellVoltageHV91
        | Datatype::SingleCellVoltageHV92
        | Datatype::SingleCellVoltageHV93
        | Datatype::SingleCellVoltageHV94
        | Datatype::SingleCellVoltageHV95
        | Datatype::SingleCellVoltageHV96
        | Datatype::SingleCellVoltageHV97
        | Datatype::SingleCellVoltageHV98
        | Datatype::SingleCellVoltageHV99
        | Datatype::SingleCellVoltageHV100
        | Datatype::SingleCellVoltageHV101
        | Datatype::SingleCellVoltageHV102
        | Datatype::SingleCellVoltageHV103
        | Datatype::SingleCellVoltageHV104
        | Datatype::SingleCellVoltageHV105
        | Datatype::SingleCellVoltageHV106
        | Datatype::SingleCellVoltageHV107
        | Datatype::SingleCellVoltageHV108
        | Datatype::SingleCellVoltageHV109
        | Datatype::SingleCellVoltageHV110
        | Datatype::SingleCellVoltageHV111
        | Datatype::SingleCellVoltageHV112 => {
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
        | Datatype::AccelerationZ
        | Datatype::HighPressureSensor
        | Datatype::LowPressureSensor => {
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
