/* AUTO GENERATED USING npm run generate:commands */
export type NamedCommand = "default_command" | "levitate" | "stop_levitating" | "configure" | "start_run" | "emergency_brake" | "shutdown" | "start_hv" | "stop_hv"
    /* debug commands */ | 'establish_connection' | 'start_north_bridge' | 'start_south_bridge' | 'abort' | 'start_logs' | 'start_errors'

// Not touched by auto-gen
export type Payload = {
    value: number,
    values: number[],
    timestamp: number,
}
export type EventChannel = 'north_bridge' | 'south_bridge'
export type TempTableEntry = {name:string, value: number}
export type Log = {
    log_type:string, message:string, timestamp:number
}
export type IntervalFunction = () => void;
export type Segment = 'L1' | 'L2' | 'L3' | 'L4' | 'L5' | 'L6';