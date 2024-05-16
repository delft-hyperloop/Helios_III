/**
 * BMS Module Voltage
 * This type is to be used for store type on receiving the
 */
interface BmsModuleVoltage {
    id: number;
    max: number;
    min: number;
    avg: number;
}

/**
 * BMS Diagnostic
 * This interface is to be used as a store type when receiving
 */
interface BMSDiagnostic {
    errors: string[]
}

interface BmsModuleTemperature {
    id: number;
    max: number;
    min: number;
    avg: number;
}

interface BMSEvent {
    event: string
}

export function moduleVoltage(data: number): BmsModuleVoltage {
    let id = data >> 48;
    let voltage = data & 0x0000FFFFFFFFFFFF;
    let max = ((voltage & 0x000000000000FFFF) + 200) * 0.1;
    let min = (((voltage & 0x00000000FFFF0000) >> 16) + 200) * 0.1;
    let avg = (((voltage & 0x0000FFFF00000000) >> 32) + 200) * 0.1;
    return {id, max, min, avg};
}

export function moduleTemperature(data: number): BmsModuleVoltage {
    let id = data >> 48;
    let temperature = data & 0x0000FFFFFFFFFFFF;
    let max = temperature & 0x000000000000FFFF - 100;
    let min = ((temperature & 0x00000000FFFF0000) >> 16) - 100;
    let avg = ((temperature & 0x0000FFFF00000000) >> 32) - 100;
    return {id, max, min, avg};
}

/*
Protection status, encoded by bits for each protection type. If byte value is 0, then system is OK and no protection flag is
active. Other byte values are encoded by bits listed below:
Bit 0: Under-voltage – some cell is below critical minimum voltage.
Bit 1: Over-voltage – some cell is above critical maximum voltage.
Bit 2: Discharge Over-current – discharge current (negative current) exceeds the critical discharge current setting.
Bit 3: Charge Over-current – charge current (positive current) exceeds the critical charge current setting.
Bit 4: Cell Module Overheat – cell module temperature exceeds maximum critical temperature setting.
Bit 5: Leakage – leakage signal was detected on leakage input pin.
Bit 6: No Cell Communication – loss of communication to cells.
Bit 7: Reserved
WARNING (REDUCTION) FLAGS  |  Warning (power reduction) status, encoded by bits for each warning (requested power reduction) type. If byte value is 0, then
no power reduction is requested. Other byte values are encoded by bits listed below:
Bit 0: Low voltage – some cell is below low voltage warning setting.
Bit 1: High current – discharge current (negative current) exceeds the current warning setting.
Bit 2: High temperature – cell module temperature exceeds warning temperature setting.
PROTECTION FLAGS (MSB) | Protection status, encoded by bits for each protection type. If byte value is 0, then system is OK and no protection flag is
active. Other byte values are encoded by bits listed below:
Bits 0-2 an bits 4-7: Reserved;
Bit 3: Cell Overheat – cell temperature exceeds maximum cell temperature threshold;
Bit 4: No Current Sensor;
Bit 5: Pack Under-Voltage;
BATTERY STATUS FLAGS | Battery status and cell communication status flags. Bit meanings:
Bit 0: Cell voltages validity (1 if valid, 0 if invalid);
Bit 1; Cell module temperatures validity;
Bit 2: Cell balancing rates validity;
Bit 3: Number of live cells validity;
Bit 4: Battery charging finished (1 if active, 0 if inactive). This flag is used only when using non-CAN charger.
Bit 5: Cell temperatures validity;
Bits 6-7 are reserved.
*/

/**
 * DATATYPE DIAGNOSTIC
 * @param data
 * @constructor
 */
export function BMSDiagnosticTranslation(data: number): BMSDiagnostic {
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
    let important = [0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 19, 20, 21, 24, 25, 26, 27, 28, 29]
    for (let i of important) {
        if (data & 1 << i) {
            errors.push(possibleErrors[i]);
        }
    }
    return {errors};
}

//DATA[MSB]
// 0 – No event;
// 1 – BMS Started;
// 2 – Lost communication to cells;
// 3 – Established communication to cells;
// 4 – Cells voltage critically low;
// 5 – Critical low voltage recovered;
// 6 – Cells voltage critically high;
// 7 – Critical high voltage recovered;
// 8 – Discharge current critically high;
// Page 61 of 63G1 Control Unit CAN Protocol
// 9 – Discharge critical high current recovered;
// 10 – Charge current critically high;
// 11 – Charge critical high current recovered;
// 12 – Cell module temperature critically high;
// 13 – Critical high cell module temperature recovered;
// 14 – Leakage detected;
// 15 – Leakage recovered;
// 16– Warning: Low voltage - reducing power;
// 17 – Power reduction due to low voltage recovered;
// 18– Warning: High current - reducing power;
// 19 – Power reduction due to high current recovered;
// 20 – Warning: High cell module temperature - reducing power;
// 21 – Power reduction due to high cell module temperature recovered;
// 22 – Charger connected;
// 23 – Charger disconnected;
// 24 – Started pre-heating stage;
// 25 – Started pre-charging stage;
// 26 – Started main charging stage;
// 27 – Started balancing stage;
// 28 – Charging finished;
// 29 – Charging error occurred;
// 30 – Retrying charging;
// 31 – Restarting charging;
// 42 – Cell temperature critically high;
// 43 – Critically high cell temperature recovered;
// 44 – Warning: High cell temperature – reducing power;
// 45 – Power reduction due to high cell temperature recovered.


/**
 * DATATYPE BMS EVENT
 * @param data
 * @constructor
 */
export function BMSEvent(data: number): BMSEvent {
    data = data & 0x0000FFFFFFFF0000;

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
    return {event: possibleEvents[(data >> 16) & 0xFFFF]};
}