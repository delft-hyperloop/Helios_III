export type Payload = {
    value: number,
    values: number[],
    timestamp: number,
}

export type NamedCommand = 'start_north_bridge' | 'start_south_bridge' | 'abort'
    | 'start_logs' | 'start_errors' | 'establish_connection' | 'hv_on' | 'hv_off' | 'levitation_on' | 'levitation_off' | 'start_run'
export type EventChannel = 'north_bridge' | 'south_bridge'

export type TempTableEntry = {name:string, value: number}

export type Log = {
    log_type:string, message:string, timestamp:number
}

export type Segment = 'L1' | 'L2' | 'L3' | 'L4' | 'L5' | 'L6';