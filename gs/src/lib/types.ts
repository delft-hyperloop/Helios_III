export type Payload = {
    value: number,
    values: number[],
    timestamp: number,
}

export type NamedCommand = 'start_north_bridge' | 'start_south_bridge' | 'abort'
export type EventChannel = 'north_bridge' | 'south_bridge'

export type TempTableEntry = {name:string, value: number}