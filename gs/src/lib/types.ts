/* AUTO GENERATED USING npm run generate:commands */
export type NamedCommand = "DefaultCommand" | "Levitate" | "StopLevitating" | "Configure" | "StartRun" | "EmergencyBrake" | "Shutdown" | "StartHV" | "StopHV"
    /* debug commands */ | 'establish_connection' | 'start_north_bridge' | 'start_south_bridge' | 'abort'

/*AUTO GENERATED USING npm run generate:datatypes */
export type NamedDatatype = "DefaultDatatype" | "PropulsionTemperature" | "LevitationTemperature" | "BatteryVoltage" | "TotalBatteryVoltage" | "BatteryTemperature" | "BatteryBalance" | "SingleCellVoltage" | "SingleCellTemperature" | "ChargeState" | "BatteryCurrent" | "BrakeTemperature" | "PropulsionSpeed" | "BrakePressure" | "HighVoltage" | "HighVoltageInsulation" | "FSMState" | "FSMEvent" | "PodDropTriggered" | "Localisation" | "GFDIsolation" | "DefaultBMS"

export type TauriInvoker = "send_command" | "unload_buffer";

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
    value: number,
    timestamp: number,
}

/**
 * Event to listen on.
 */
export type EventChannel = 'status_channel' | 'info_channel' | 'warning_channel' | 'error_channel'
    | 'north_bridge' | 'south_bridge';

export type TempTableEntry = {name:string, value: number}
export type Log = {
    log_type:string, message:string, timestamp:number
}
export type IntervalFunction = () => void;
export type Segment = 'L1' | 'L2' | 'L3' | 'L4' | 'L5' | 'L6';