interface GroundFaultDetection_Voltage {
    voltage: number;
}
interface GroundFaultDetection_Isolation {
    isolation: number;
}

export function decodeGroundFaultDetection(data: number): GroundFaultDetection_Voltage {
    let voltage = (data & 0xFFFF000000000000)>>48;
    return { voltage}
}
export function decodeGroundFaultDetection(data: number): GroundFaultDetection_Isolation {
    let isolation = (data & 0x0000FFFF00000000)>>32;
    return { isolation }
}
