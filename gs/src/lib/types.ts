/* AUTO GENERATED USING npm run generate:commands */
export type NamedCommand = "DefaultCommand" | "Heartbeat" | "FrontendHeartbeat" | "ls0" | "ls1" | "ls2" | "enable_axis" | "disable_axis" | "init" | "reboot" | "launch" | "vert0" | "lat0" | "land" | "vert_mode_normal" | "lat_mode_normal" | "vert_mode_offsets" | "vert_mode_dance" | "vert_mode_sine" | "vert0_reset" | "lat0_reset" | "LeviPropulsionStart" | "LeviPropulsionStop" | "SetRoute" | "SetSpeeds" | "SetOverrides" | "EmergencyBrake" | "StartRun" | "ContinueRun" | "StartHV" | "StopHV" | "SystemReset" | "ArmBrakes" | "FinishRunConfig" | "Shutdown" | "DcOff" | "DcOn" | "OpenContactor" | "CloseContactor" | "SetCurrentSpeed" | "CreateDatapoint" | "EmitEvent";
export const NamedCommandValues:NamedCommand[] = ["DefaultCommand", "Heartbeat", "FrontendHeartbeat", "ls0", "ls1", "ls2", "enable_axis", "disable_axis", "init", "reboot", "launch", "vert0", "lat0", "land", "vert_mode_normal", "lat_mode_normal", "vert_mode_offsets", "vert_mode_dance", "vert_mode_sine", "vert0_reset", "lat0_reset", "LeviPropulsionStart", "LeviPropulsionStop", "SetRoute", "SetSpeeds", "SetOverrides", "EmergencyBrake", "StartRun", "ContinueRun", "StartHV", "StopHV", "SystemReset", "ArmBrakes", "FinishRunConfig", "Shutdown", "DcOff", "DcOn", "OpenContactor", "CloseContactor", "SetCurrentSpeed", "CreateDatapoint", "EmitEvent"];

/*AUTO GENERATED USING npm run generate:datatypes */
export type NamedDatatype = "YourNewDatatypeName" | "Example1" | "Example2" | "Example3" | "DefaultDatatype" | "ConnectionStatus" | "PropulsionTemperature" | "PropulsionVoltage" | "PropulsionCurrent" | "PropulsionVRefInt" | "LevitationTemperature" | "AccelerationX" | "AccelerationY" | "AccelerationZ" | "GyroscopeX" | "GyroscopeY" | "GyroscopeZ" | "IMDGeneralInfo" | "IMDIsolationDetails" | "IMDVoltageDetails" | "InsulationNegative" | "InsulationPositive" | "InsulationOriginal" | "DefaultBMSLow" | "DiagnosticBMSLow" | "DefaultBMSHigh" | "DiagnosticBMSHigh" | "BatteryVoltageLow" | "BatteryVoltageHigh" | "TotalBatteryVoltageLow" | "TotalBatteryVoltageHigh" | "BatteryTemperatureLow" | "BatteryTemperatureHigh" | "BatteryBalanceLow" | "BatteryBalanceHigh" | "SingleCellVoltageLow" | "SingleCellTemperatureLow" | "ChargeStateLow" | "ChargeStateHigh" | "BatteryCurrentLow" | "BatteryCurrentHigh" | "BatteryEnergyParamsLow" | "BatteryEnergyParamsHigh" | "BatteryMaxVoltageLow" | "BatteryEstimatedChargeLow" | "BatteryMinTemperatureLow" | "BatteryMaxTemperatureLow" | "BatteryMinBalancingLow" | "BatteryMaxBalancingLow" | "BatteryMinVoltageLow" | "BatteryMinVoltageHigh" | "BatteryMaxVoltageHigh" | "BatteryEstimatedChargeHigh" | "BatteryMinTemperatureHigh" | "BatteryMaxTemperatureHigh" | "BatteryMinBalancingHigh" | "BatteryMaxBalancingHigh" | "BatteryEventLow" | "BatteryEventHigh" | "BrakeTemperature" | "PropulsionSpeed" | "FSMState" | "FSMEvent" | "EndOfTrackTriggered" | "Localisation" | "Velocity" | "Acceleration" | "Direction" | "BrakePressure" | "UnknownCanId" | "Info" | "Presure_VB" | "Average_Temp_VB_Bottom" | "Average_Temp_VB_top" | "Temp_HEMS_1" | "Temp_HEMS_2" | "Temp_HEMS_3" | "Temp_HEMS_4" | "Temp_Motor_1" | "Temp_Motor_2" | "Ambient_presure" | "Ambient_temp" | "Temp_EMS_1" | "Temp_EMS_2" | "Temp_EMS_3" | "Temp_EMS_4" | "SingleCellVoltageHigh" | "SingleCellVoltageHigh_1" | "SingleCellTemperatureHigh_1" | "SingleCellVoltageHigh_2" | "SingleCellTemperatureHigh_2" | "SingleCellVoltageHigh_3" | "SingleCellTemperatureHigh_3" | "SingleCellVoltageHigh_4" | "SingleCellTemperatureHigh_4" | "SingleCellVoltageHigh_5" | "SingleCellTemperatureHigh_5" | "SingleCellVoltageHigh_6" | "SingleCellTemperatureHigh_6" | "SingleCellVoltageHigh_7" | "SingleCellTemperatureHigh_7" | "SingleCellVoltageHigh_8" | "SingleCellTemperatureHigh_8" | "SingleCellVoltageHigh_9" | "SingleCellTemperatureHigh_9" | "SingleCellVoltageHigh_10" | "SingleCellTemperatureHigh_10" | "SingleCellVoltageHigh_11" | "SingleCellTemperatureHigh_11" | "SingleCellVoltageHigh_12" | "SingleCellTemperatureHigh_12" | "SingleCellVoltageHigh_13" | "SingleCellTemperatureHigh_13" | "SingleCellVoltageHigh_14" | "SingleCellTemperatureHigh_14" | "Module1MaxVoltage" | "Module2MaxVoltage" | "Module3MaxVoltage" | "Module4MaxVoltage" | "Module5MaxVoltage" | "Module6MaxVoltage" | "Module7MaxVoltage" | "Module8MaxVoltage" | "Module1MinVoltage" | "Module2MinVoltage" | "Module3MinVoltage" | "Module4MinVoltage" | "Module5MinVoltage" | "Module6MinVoltage" | "Module7MinVoltage" | "Module8MinVoltage" | "Module1MaxTemperature" | "Module2MaxTemperature" | "Module3MaxTemperature" | "Module4MaxTemperature" | "Module5MaxTemperature" | "Module6MaxTemperature" | "Module7MaxTemperature" | "Module8MaxTemperature" | "Module1MinTemperature" | "Module2MinTemperature" | "Module3MinTemperature" | "Module4MinTemperature" | "Module5MinTemperature" | "Module6MinTemperature" | "Module7MinTemperature" | "Module8MinTemperature" | "Module1AvgVoltage" | "Module2AvgVoltage" | "Module3AvgVoltage" | "Module4AvgVoltage" | "Module5AvgVoltage" | "Module6AvgVoltage" | "Module7AvgVoltage" | "Module8AvgVoltage" | "Module1AvgTemperature" | "Module2AvgTemperature" | "Module3AvgTemperature" | "Module4AvgTemperature" | "Module5AvgTemperature" | "Module6AvgTemperature" | "Module7AvgTemperature" | "Module8AvgTemperature" | "ResponseHeartbeat" | "LeviInstruction" | "LowPressureSensor" | "HighPressureSensor" | "levi_hems_gap_a" | "levi_hems_gap_b" | "levi_hems_gap_c" | "levi_hems_gap_d" | "levi_ems_gap_a" | "levi_ems_gap_b" | "levi_ems_gap_c" | "levi_ems_gap_d" | "levi_hems_current_a1" | "levi_hems_current_a2" | "levi_hems_current_b1" | "levi_hems_current_b2" | "levi_hems_current_c1" | "levi_hems_current_c2" | "levi_hems_current_d1" | "levi_hems_current_d2" | "levi_ems_current_ab" | "levi_ems_current_cd" | "levi_hems_airgap" | "levi_hems_pitch" | "levi_hems_roll" | "levi_ems_offset_ab" | "levi_ems_offset_cd" | "levi_hems_power" | "levi_ems_power" | "levi_volt_min" | "levi_volt_max" | "levi_volt_avg" | "levi_volt_A" | "levi_volt_B" | "levi_volt_C" | "levi_volt_D" | "levi_volt_E" | "levi_location" | "levi_speed" | "BrakingCommDebug" | "BrakingSignalDebug" | "BrakingBoolDebug" | "BrakingRearmDebug" | "PropGPIODebug" | "ReceivedCan" | "SendingCANEvent" | "RoutePlan" | "CurrentPosition" | "CommandHash" | "EventsHash" | "DataHash" | "ConfigHash" | "ValueError" | "ValueWarning" | "ValueCausedBraking" | "NextPositionDebug" | "LocalisationHeartbeat" | "SensorHubHeartbeat" | "FrontendHeartbeating" | "HeartbeatExpired" | "OverflowUnit" | "SingleCellVoltageLV1" | "SingleCellVoltageLV2" | "SingleCellVoltageLV3" | "SingleCellVoltageLV4" | "SingleCellVoltageLV5" | "SingleCellVoltageLV6" | "SingleCellVoltageLV7" | "SingleCellVoltageLV8" | "SingleCellVoltageHV1" | "SingleCellVoltageHV2" | "SingleCellVoltageHV3" | "SingleCellVoltageHV4" | "SingleCellVoltageHV5" | "SingleCellVoltageHV6" | "SingleCellVoltageHV7" | "SingleCellVoltageHV8" | "SingleCellVoltageHV9" | "SingleCellVoltageHV10" | "SingleCellVoltageHV11" | "SingleCellVoltageHV12" | "SingleCellVoltageHV13" | "SingleCellVoltageHV14" | "SingleCellVoltageHV15" | "SingleCellVoltageHV16" | "SingleCellVoltageHV17" | "SingleCellVoltageHV18" | "SingleCellVoltageHV19" | "SingleCellVoltageHV20" | "SingleCellVoltageHV21" | "SingleCellVoltageHV22" | "SingleCellVoltageHV23" | "SingleCellVoltageHV24" | "SingleCellVoltageHV25" | "SingleCellVoltageHV26" | "SingleCellVoltageHV27" | "SingleCellVoltageHV28" | "SingleCellVoltageHV29" | "SingleCellVoltageHV30" | "SingleCellVoltageHV31" | "SingleCellVoltageHV32" | "SingleCellVoltageHV33" | "SingleCellVoltageHV34" | "SingleCellVoltageHV35" | "SingleCellVoltageHV36" | "SingleCellVoltageHV37" | "SingleCellVoltageHV38" | "SingleCellVoltageHV39" | "SingleCellVoltageHV40" | "SingleCellVoltageHV41" | "SingleCellVoltageHV42" | "SingleCellVoltageHV43" | "SingleCellVoltageHV44" | "SingleCellVoltageHV45" | "SingleCellVoltageHV46" | "SingleCellVoltageHV47" | "SingleCellVoltageHV48" | "SingleCellVoltageHV49" | "SingleCellVoltageHV50" | "SingleCellVoltageHV51" | "SingleCellVoltageHV52" | "SingleCellVoltageHV53" | "SingleCellVoltageHV54" | "SingleCellVoltageHV55" | "SingleCellVoltageHV56" | "SingleCellVoltageHV57" | "SingleCellVoltageHV58" | "SingleCellVoltageHV59" | "SingleCellVoltageHV60" | "SingleCellVoltageHV61" | "SingleCellVoltageHV62" | "SingleCellVoltageHV63" | "SingleCellVoltageHV64" | "SingleCellVoltageHV65" | "SingleCellVoltageHV66" | "SingleCellVoltageHV67" | "SingleCellVoltageHV68" | "SingleCellVoltageHV69" | "SingleCellVoltageHV70" | "SingleCellVoltageHV71" | "SingleCellVoltageHV72" | "SingleCellVoltageHV73" | "SingleCellVoltageHV74" | "SingleCellVoltageHV75" | "SingleCellVoltageHV76" | "SingleCellVoltageHV77" | "SingleCellVoltageHV78" | "SingleCellVoltageHV79" | "SingleCellVoltageHV80" | "SingleCellVoltageHV81" | "SingleCellVoltageHV82" | "SingleCellVoltageHV83" | "SingleCellVoltageHV84" | "SingleCellVoltageHV85" | "SingleCellVoltageHV86" | "SingleCellVoltageHV87" | "SingleCellVoltageHV88" | "SingleCellVoltageHV89" | "SingleCellVoltageHV90" | "SingleCellVoltageHV91" | "SingleCellVoltageHV92" | "SingleCellVoltageHV93" | "SingleCellVoltageHV94" | "SingleCellVoltageHV95" | "SingleCellVoltageHV96" | "SingleCellVoltageHV97" | "SingleCellVoltageHV98" | "SingleCellVoltageHV99" | "SingleCellVoltageHV100" | "SingleCellVoltageHV101" | "SingleCellVoltageHV102" | "SingleCellVoltageHV103" | "SingleCellVoltageHV104" | "SingleCellVoltageHV105" | "SingleCellVoltageHV106" | "SingleCellVoltageHV107" | "SingleCellVoltageHV108" | "SingleCellVoltageHV109" | "SingleCellVoltageHV110" | "SingleCellVoltageHV111" | "SingleCellVoltageHV112"
export const NamedDatatypeValues = ["YourNewDatatypeName" , "Example1" , "Example2" , "Example3" , "DefaultDatatype" , "ConnectionStatus" , "PropulsionVoltage" , "PropulsionCurrent" , "PropulsionVRefInt" ,
    "LevitationTemperature" , "AccelerationX" , "AccelerationY" , "AccelerationZ" , "GyroscopeX" , "GyroscopeY" , "GyroscopeZ" , "IMDGeneralInfo" , "IMDIsolationDetails" ,
    "IMDVoltageDetails" , "InsulationNegative" , "InsulationPositive" , "InsulationOriginal" , "DefaultBMSLow" , "DiagnosticBMSLow" , "DefaultBMSHigh" , "DiagnosticBMSHigh"
    , "BatteryVoltageLow" , "BatteryVoltageHigh" , "TotalBatteryVoltageLow" , "TotalBatteryVoltageHigh" , "BatteryTemperatureLow" , "BatteryTemperatureHigh" , "BatteryBalanceLow" , "BatteryBalanceHigh" , "SingleCellVoltageLow" , "SingleCellTemperatureLow" , "ChargeStateLow" , "ChargeStateHigh" , "BatteryCurrentLow" , "BatteryCurrentHigh" ,
    "BatteryEnergyParamsLow" , "BatteryEnergyParamsHigh" , "BatteryMaxVoltageLow" , "BatteryEstimatedChargeLow" , "BatteryMinTemperatureLow" , "BatteryMaxTemperatureLow" , "BatteryMinBalancingLow" , "BatteryMaxBalancingLow" , "BatteryMinVoltageLow" , "BatteryMinVoltageHigh" , "BatteryMaxVoltageHigh" , "BatteryEstimatedChargeHigh" , "BatteryMinTemperatureHigh" , "BatteryMaxTemperatureHigh" , "BatteryMinBalancingHigh" , "BatteryMaxBalancingHigh" , "BatteryEventLow" , "BatteryEventHigh" , "BrakeTemperature" ,
    "PropulsionSpeed" , "FSMState" , "FSMEvent" , "EndOfTrackTriggered" , "Localisation" , "Velocity" , "Acceleration" , "Direction" , "BrakePressure" , "UnknownCanId" , "Info" , "Presure_VB" , "Average_Temp_VB_Bottom" , "Average_Temp_VB_top" , "Temp_HEMS_1" , "Temp_HEMS_2" , "Temp_HEMS_3" , "Temp_HEMS_4" , "Temp_Motor_1" , "Temp_Motor_2"
    , "Ambient_presure" , "Ambient_temp" , "Temp_EMS_1" , "Temp_EMS_2" , "Temp_EMS_3" , "Temp_EMS_4" , "SingleCellVoltageHigh" , "SingleCellVoltageHigh_1" , "SingleCellTemperatureHigh_1" , "SingleCellVoltageHigh_2" , "SingleCellTemperatureHigh_2" , "SingleCellVoltageHigh_3" , "SingleCellTemperatureHigh_3" , "SingleCellVoltageHigh_4" , "SingleCellTemperatureHigh_4" , "SingleCellVoltageHigh_5" , "SingleCellTemperatureHigh_5" , "SingleCellVoltageHigh_6" , "SingleCellTemperatureHigh_6" , "SingleCellVoltageHigh_7" , "SingleCellTemperatureHigh_7" , "SingleCellVoltageHigh_8" , "SingleCellTemperatureHigh_8" , "SingleCellVoltageHigh_9" , "SingleCellTemperatureHigh_9" , "SingleCellVoltageHigh_10" , "SingleCellTemperatureHigh_10" , "SingleCellVoltageHigh_11" , "SingleCellTemperatureHigh_11" , "SingleCellVoltageHigh_12" , "SingleCellTemperatureHigh_12" , "SingleCellVoltageHigh_13" , "SingleCellTemperatureHigh_13" , "SingleCellVoltageHigh_14" , "SingleCellTemperatureHigh_14" , "Module1MaxVoltage" , "Module2MaxVoltage" , "Module3MaxVoltage" , "Module4MaxVoltage" , "Module5MaxVoltage" , "Module6MaxVoltage" , "Module7MaxVoltage" , "Module8MaxVoltage" , "Module1MinVoltage" , "Module2MinVoltage" , "Module3MinVoltage" , "Module4MinVoltage" , "Module5MinVoltage" , "Module6MinVoltage" , "Module7MinVoltage" , "Module8MinVoltage" , "Module1MaxTemperature" , "Module2MaxTemperature" , "Module3MaxTemperature" , "Module4MaxTemperature" , "Module5MaxTemperature" , "Module6MaxTemperature" , "Module7MaxTemperature" , "Module8MaxTemperature" , "Module1MinTemperature" , "Module2MinTemperature" , "Module3MinTemperature" , "Module4MinTemperature" , "Module5MinTemperature" , "Module6MinTemperature" ,
    "Module7MinTemperature" , "Module8MinTemperature" , "Module1AvgVoltage" , "Module2AvgVoltage" , "Module3AvgVoltage" , "Module4AvgVoltage" , "Module5AvgVoltage" , "Module6AvgVoltage" , "Module7AvgVoltage" , "Module8AvgVoltage" , "Module1AvgTemperature" , "Module2AvgTemperature" , "Module3AvgTemperature" , "Module4AvgTemperature" , "Module5AvgTemperature" , "Module6AvgTemperature" , "Module7AvgTemperature" , "Module8AvgTemperature" , "ResponseHeartbeat" , "LeviInstruction" , "LowPressureSensor" , "HighPressureSensor" , "levi_hems_gap_a" , "levi_hems_gap_b" , "levi_hems_gap_c" , "levi_hems_gap_d" , "levi_ems_gap_a" , "levi_ems_gap_b" , "levi_ems_gap_c" , "levi_ems_gap_d" , "levi_hems_current_a1" , "levi_hems_current_a2" , "levi_hems_current_b1" , "levi_hems_current_b2" , "levi_hems_current_c1" , "levi_hems_current_c2" , "levi_hems_current_d1" , "levi_hems_current_d2" , "levi_ems_current_ab" , "levi_ems_current_cd" , "levi_hems_airgap" , "levi_hems_pitch" , "levi_hems_roll" , "levi_ems_offset_ab" , "levi_ems_offset_cd" , "levi_hems_power" , "levi_ems_power" , "levi_volt_min" , "levi_volt_max" , "levi_volt_avg" , "levi_volt_A" , "levi_volt_B" , "levi_volt_C" , "levi_volt_D" , "levi_volt_E" , "levi_location" , "levi_speed" , "BrakingCommDebug" , "BrakingSignalDebug" , "BrakingBoolDebug" , "BrakingRearmDebug" , "PropGPIODebug" , "ReceivedCan" , "SendingCANEvent" , "RoutePlan" , "CurrentPosition" , "CommandHash" , "EventsHash" , "DataHash" , "ConfigHash" , "ValueError" , "ValueWarning" , "ValueCausedBraking" , "NextPositionDebug" , "LocalisationHeartbeat" , "SensorHubHeartbeat" , "FrontendHeartbeating" , "HeartbeatExpired" , "SingleCellVoltageLV1" , "SingleCellVoltageLV2" , "SingleCellVoltageLV3" , "SingleCellVoltageLV4" , "SingleCellVoltageLV5" , "SingleCellVoltageLV6" , "SingleCellVoltageLV7" , "SingleCellVoltageLV8" , "SingleCellVoltageHV1" , "SingleCellVoltageHV2" , "SingleCellVoltageHV3" , "SingleCellVoltageHV4" , "SingleCellVoltageHV5" , "SingleCellVoltageHV6" , "SingleCellVoltageHV7" , "SingleCellVoltageHV8" , "SingleCellVoltageHV9" , "SingleCellVoltageHV10" , "SingleCellVoltageHV11" , "SingleCellVoltageHV12" , "SingleCellVoltageHV13" , "SingleCellVoltageHV14" , "SingleCellVoltageHV15" , "SingleCellVoltageHV16" , "SingleCellVoltageHV17" , "SingleCellVoltageHV18" , "SingleCellVoltageHV19" , "SingleCellVoltageHV20" , "SingleCellVoltageHV21" , "SingleCellVoltageHV22" , "SingleCellVoltageHV23" , "SingleCellVoltageHV24" , "SingleCellVoltageHV25" , "SingleCellVoltageHV26" , "SingleCellVoltageHV27" , "SingleCellVoltageHV28" , "SingleCellVoltageHV29" , "SingleCellVoltageHV30" , "SingleCellVoltageHV31" , "SingleCellVoltageHV32" , "SingleCellVoltageHV33" , "SingleCellVoltageHV34" , "SingleCellVoltageHV35" , "SingleCellVoltageHV36" , "SingleCellVoltageHV37" , "SingleCellVoltageHV38" , "SingleCellVoltageHV39" , "SingleCellVoltageHV40" , "SingleCellVoltageHV41" , "SingleCellVoltageHV42" , "SingleCellVoltageHV43" , "SingleCellVoltageHV44" , "SingleCellVoltageHV45" , "SingleCellVoltageHV46" , "SingleCellVoltageHV47" , "SingleCellVoltageHV48" , "SingleCellVoltageHV49" , "SingleCellVoltageHV50" , "SingleCellVoltageHV51" , "SingleCellVoltageHV52" , "SingleCellVoltageHV53" , "SingleCellVoltageHV54" , "SingleCellVoltageHV55" , "SingleCellVoltageHV56" , "SingleCellVoltageHV57" , "SingleCellVoltageHV58" , "SingleCellVoltageHV59" , "SingleCellVoltageHV60" , "SingleCellVoltageHV61" , "SingleCellVoltageHV62" , "SingleCellVoltageHV63" , "SingleCellVoltageHV64" , "SingleCellVoltageHV65" , "SingleCellVoltageHV66" , "SingleCellVoltageHV67" , "SingleCellVoltageHV68" , "SingleCellVoltageHV69" , "SingleCellVoltageHV70" , "SingleCellVoltageHV71" , "SingleCellVoltageHV72" , "SingleCellVoltageHV73" , "SingleCellVoltageHV74" , "SingleCellVoltageHV75" , "SingleCellVoltageHV76" , "SingleCellVoltageHV77" , "SingleCellVoltageHV78" , "SingleCellVoltageHV79" , "SingleCellVoltageHV80" , "SingleCellVoltageHV81" , "SingleCellVoltageHV82" , "SingleCellVoltageHV83" , "SingleCellVoltageHV84" , "SingleCellVoltageHV85" , "SingleCellVoltageHV86" , "SingleCellVoltageHV87" , "SingleCellVoltageHV88" , "SingleCellVoltageHV89" , "SingleCellVoltageHV90" , "SingleCellVoltageHV91" , "SingleCellVoltageHV92" , "SingleCellVoltageHV93" , "SingleCellVoltageHV94" , "SingleCellVoltageHV95" , "SingleCellVoltageHV96" , "SingleCellVoltageHV97" , "SingleCellVoltageHV98" , "SingleCellVoltageHV99" , "SingleCellVoltageHV100" , "SingleCellVoltageHV101" , "SingleCellVoltageHV102" , "SingleCellVoltageHV103" , "SingleCellVoltageHV104" , "SingleCellVoltageHV105" , "SingleCellVoltageHV106" , "SingleCellVoltageHV107" , "SingleCellVoltageHV108" , "SingleCellVoltageHV109" , "SingleCellVoltageHV110" , "SingleCellVoltageHV111" , "SingleCellVoltageHV112" ,"PropulsionTemperature"
];
// Not touched by auto-gen

/**
 * Datapoint to be sent to the frontend
 */
export type Datapoint = {
    datatype: NamedDatatype,
    value: number,
    timestamp: number,
    style: string,
    units: string
}

/**
 * Event channels to listen on
 */
export const EventChannel = {
    STATUS: 'status_channel',
    INFO: 'info_channel',
    WARNING: 'warning_channel',
    ERROR: 'error_channel',
}

/**
 * Function to convert data received at DATAPOINT.value to a given type
 */
export type dataConvFun<T> = (data: number, old:T) => T;

/**
 * BMS Module Voltage
 * This type is to be used for store type on receiving the
 */
export type BmsModuleVoltage = {
    id: bigint;
    max: bigint;
    min: bigint;
    avg: bigint;
}

/**
 * BMS Diagnostic
 * This interface is to be used as a store type when receiving
 */
export type BMSDiagnostic = {
    errors: string[]
}

/**
 * BMS Module Temperature
 * This type is to be used for store type on receiving bigint with the datatype
 */
export type BmsModuleTemperature = {
    id: bigint;
    max: bigint;
    min: bigint;
    avg: bigint;
}

/**
 * BMS Event with attached string event
 */
export type BMSEvent = {
    event: string
}

/**
 * Enumerator for the types of run you can have
 * Used in for the Localiser and for when choosing a run in the RunInit tab.
 * @enum {string} - straight, left or right
 */
export enum RunMode {
    ShortRun = 'straight',
    LeftSwitch = 'left',
    RightSwitch = 'right'
}

/**
 * Log type to be displayed in the log tab
 */
export type Log = {
    log_type:LogType, message:string, timestamp:number
}

export type RouteStep = "ForwardA"|"ForwardB"|"ForwardC"|"BackwardsA"|"BackwardsB"|"BackwardsC"|
                        "LaneSwitchStraight"|"LaneSwitchCurved"|"StopAndWait"|"BrakeHere";

export type Procedure = {
    name: string,
    title: string,
    id: string,
    people: string[],
    equipment: string[],
    content: string
}

export enum STATUS {
    MAIN_PCB,
    PROPULSION,
    LEVITATION,
    SENSOR_HUB,
    LV_BATTERIES,
    HV_BATTERIES,
    BRAKING_PCB,
    VOLTAGE_OVER,
    TURNING
}

export type LogType = 'INFO' | 'WARNING' | 'ERROR' | 'STATUS';

export type RouteConfig = {
    speeds: {
        BackwardsA: number
        BackwardsB: number
        BackwardsC: number
        ForwardA: number
        ForwardB: number
        ForwardC: number
        LaneSwitchCurved: number
        LaneSwitchStraight: number
    },
    positions: RouteStep[],
    current_position: number
}

export const LOCALISATION_NAME = "Localisation"; // 'levi_location'

// OLD TYPES
export type IntervalFunction = () => void;
export type Segment = 'L1' | 'L2' | 'L3' | 'L4' | 'L5' | 'L6';
