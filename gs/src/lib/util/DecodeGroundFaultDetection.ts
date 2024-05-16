interface GroundFaultDetection_Voltage {
    voltage: number;
}
interface GroundFaultDetection_Isolation {
    insulation: number;
}

export function decodeVoltageFaultDetection(data: number): GroundFaultDetection_Voltage {
    let voltage = (data & 0xFFFF000000000000)>>48;
    return { voltage}
}
export function decodeInsulationFaultDetection(data: number): GroundFaultDetection_Isolation {
    let insulation = (data & 0x0000FFFF00000000)>>32;
    return { insulation }
}
