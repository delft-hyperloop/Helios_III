/* AUTO GENERATED USING npm run generate:commands */
export type NamedCommand = "DefaultCommand" | "Levitate" | "StopLevitating" | "Configure" | "StartRun" | "EmergencyBrake" | "Shutdown" | "StartHV" | "StopHV"
    /* debug commands */ | 'establish_connection' | 'start_north_bridge' | 'start_south_bridge' | 'abort' | 'OpenContactor' | 'CloseContactor' | 'DcOff' | 'DcOn'

/*AUTO GENERATED USING npm run generate:datatypes */
export type NamedDatatype = "DefaultDatatype" | "PropulsionTemperature" | "LevitationTemperature" | "IMDGeneralInfo" | "IMDIsolationDetails" | "IMDVoltageDetails" | "DefaultBMSLow" | "DiagonosticBMSLow" | "DefaultBMSHigh" | "DiagonosticBMSHigh" | "BatteryVoltageLow" | "BatteryVoltageHigh" | "TotalBatteryVoltageLow" | "TotalBatteryVoltageHigh" | "BatteryTemperatureLow" | "BatteryTemperatureHigh" | "BatteryBalanceLow" | "BatteryBalanceHigh" | "SingleCellVoltageLow" | "SingleCellTemperatureLow" | "ChargeStateLow" | "SingleCellVoltageHigh" | "SingleCellTemperatureHigh" | "ChargeStateHigh" | "BatteryCurrentLow" | "BatteryCurrentHigh" | "BatteryEnergyParamsLow" | "BatteryEnergyParamsHigh" | "BatteryMaxVoltageLow" | "BatteryEstimatedChargeLow" | "BatteryMinTemperatureLow" | "BatteryMaxTemperatureLow" | "BatteryMinBalancingLow" | "BatteryMaxBalancingLow" | "BatteryMinVoltageLow" | "BatteryMinVoltageHigh" | "BatteryMaxVoltageHigh" | "BatteryEstimatedChargeHigh" | "BatteryMinTemperatureHigh" | "BatteryMaxTemperatureHigh" | "BatteryMinBalancingHigh" | "BatteryMaxBalancingHigh" | "BrakeTemperature" | "PropulsionSpeed" | "BrakePressure" | "FSMState" | "FSMEvent" | "PodDropTriggered" | "Localisation" | "UnknownCanId" | "Info"

// Not touched by auto-gen

/**
 * Payload for the event
 * @deprecated this exists only for testing purposes
 */
export type Payload = {
    value: number,
    values: number[],
    timestamp: number,
}

/**
 * Datapoint to be sent to the frontend
 */
export type Datapoint = {
    datatype: NamedDatatype,
    value: bigint,
    timestamp: number,
}

/**
 * Event channels to listen on
 */
export const EventChannels = {
    STATUS: 'status_channel',
    INFO: 'info_channel',
    WARNING: 'warning_channel',
    ERROR: 'error_channel',
}

/**
 * Event to listen on.
 */
export type EventChannel = 'north_bridge' | 'south_bridge';

/**
 * Function to convert data received at DATAPOINT.value to a given type
 */
export type dataConvFun<T> = (data: bigint, old:T) => T;

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
 * Used in for the Localiser and for when choosing a rung in the RunInit tab.
 * @enum {string} - straight, left or right
 */
export enum RunMode {
    ShortRun = 'straight',
    LeftSwitch = 'left',
    RightSwitch = 'right'
}

// OLD TYPES
export type Log = {
    log_type:string, message:string, timestamp:number
}
export type IntervalFunction = () => void;
export type Segment = 'L1' | 'L2' | 'L3' | 'L4' | 'L5' | 'L6';