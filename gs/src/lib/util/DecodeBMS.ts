import type {dataConvFun, BMSDiagnostic, BMSEvent, BmsModuleVoltage} from "$lib/types";

/**
 * DATATYPE BMS MODULE VOLTAGE
 * @param data - the data to be converted received at the DATAPOINT.value
 */
export const moduleVoltage: dataConvFun<BmsModuleVoltage> = (data: bigint) => {
    let id = data >> BigInt(48);
    let voltage = data & BigInt(0x0000FFFFFFFFFFFF);
    let max = ((voltage & BigInt(0x000000000000FFFF)) + BigInt(200)) * BigInt(0.1);
    let min = (((voltage & BigInt(0x00000000FFFF0000)) >> BigInt(16)) + BigInt(200)) * BigInt(0.1);
    let avg = (((voltage & BigInt(0x0000FFFF00000000)) >> BigInt(32)) + BigInt(200)) * BigInt(0.1);
    return {id, max, min, avg};
}


/**
 * DATATYPE BMS MODULE TEMPERATURE
 * @param data - the data to be converted received at the DATAPOINT.value
 */
export const moduleTemperature = (data: bigint): BmsModuleVoltage => {
    let id = data >> BigInt(48);
    let temperature = data & BigInt(0x0000FFFFFFFFFFFF);
    let max = temperature & BigInt(0x000000000000FFFF) - BigInt(100);
    let min = ((temperature & BigInt(0x00000000FFFF0000)) >> BigInt(16)) - BigInt(100);
    let avg = ((temperature & BigInt(0x0000FFFF00000000)) >> BigInt(32)) - BigInt(100);
    return {id, max, min, avg};
}

















/**
 * DATATYPE DIAGNOSTIC
 * @param data
 * @constructor
 */
export const BMSDiagnosticTranslation: dataConvFun<BMSDiagnostic> = (data: bigint): BMSDiagnostic => {
    let possibleErrors = ["Under-voltage – some cell is below critical minimum voltage",
        "Over-voltage – some cell is above critical maximum volta",
        "Discharge Over-current -  discharge current (negative current) exceeds the critical discharge current setting",
        "Charge Over-current  – charge current (positive current) exceeds the critical charge current setting.",
        "Cell Module Overheat – cell module temperature exceeds maximum critical temperature setting.",
        "Leakage – leakage signal was detected on leakage input pin.",
        "No Cell Communication – loss of communication to cells.",
        "Low voltage – some cell is below low voltage warning setting",
        "High current – discharge current (negative current) exceeds the current warning setting.",
        "High temperature – cell module temperature exceeds warning temperature setting.",
        "Cell Overheat – cell temperature exceeds maximum cell temperature threshold",
        "No Current Sensor",
        "Pack Under-Voltage",
        "Cell voltages validity ",
        "Cell module temperatures validity",
        "Cell balancing rates validity",
        "Number of live cells validity",
        "Battery charging finished",
        "Cell temperatures validity"];
    let errors = [];
    let important: number[] = [0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 19, 20, 21, 24, 25, 26, 27, 28, 29]
    for (let i of important) {
        if ((data & BigInt(1)) << BigInt(i)) {
            errors.push(possibleErrors[i]);
        }
    }
    return {errors};
}

/**
 * DATATYPE BMS EVENT
 * @param data
 * @constructor
 */
export function BMSEvent(data: bigint): BMSEvent {
    data = data & BigInt(0x0000FFFFFFFF0000);

    let possibleEvents = ["No event",
        "BMS Started",
        "Lost communication to cells",
        "Established communication to cells",
        "Cells voltage critically low",
        "Critical low voltage recovered",
        "Cells voltage critically high",
        "Critical high voltage recovered",
        "Discharge current critically high",
        "Discharge critical high current recovered",
        "Charge current critically high",
        "Charge critical high current recovered",
        "Cell module temperature critically high",
        "Critical high cell module temperature recovered",
        "Leakage detected",
        "Leakage recovered",
        "Warning: Low voltage - reducing power",
        "Power reduction due to low voltage recovered",
        "Warning: High current - reducing power",
        "Power reduction due to high current recovered",
        "Warning: High cell module temperature - reducing power",
        "Power reduction due to high cell module temperature recovered",
        "Charger connected",
        "Charger disconnected",
        "Started pre-heating stage",
        "Started pre-charging stage",
        "Started main charging stage",
        "Started balancing stage",
        "Charging finished",
        "Charging error occurred",
        "Retrying charging",
        "Restarting charging",
        "Cell temperature critically high",
        "Critically high cell temperature recovered",
        "Warning: High cell temperature – reducing power",
        "Power reduction due to high cell temperature recovered"];
    return {event: possibleEvents[Number((data >> BigInt(16)) & BigInt(0xFFFF))]};
}