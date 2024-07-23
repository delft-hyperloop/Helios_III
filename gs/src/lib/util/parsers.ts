import {type dataConvFun, type Procedure, STATUS} from "$lib/types";
import {PlotBuffer} from "$lib/util/PlotBuffer";
import {detailTabSet} from "$lib";
import {invoke} from "@tauri-apps/api/tauri";
const MAX_VALUE = 4_294_967_295;

const tempParse: dataConvFun<number> = (data: number) => {
    return Number(data) - 100;
}

const voltParse: dataConvFun<string> = (data: number) => {
    return Number(data) === 200 ? "INVALID" : (Number(data) / 100).toString();
}

const addEntryToChart = (chart: PlotBuffer, data: number, index: number) => {
    chart.addEntry(index, data);
    return data;
}


const sensorParse = (u64 : bigint) : number =>{
    return u64>MAX_VALUE-100000 ? - (MAX_VALUE-Number(u64)+1)/100 : Number(u64)/100;
}

const pressureParse = (u64 : bigint) : number => {
    console.log(u64);
    return u64>100_000_000 ? 0 : Number(u64)/100;
}

const metersPerMinuteToByte = (mpm: number): number => {
    if (mpm === 0) return 0;

    const speed_min = -500;
    const speed_max = 500;
    const byte_min = 50;
    const byte_max = 255;

    let mappedValue = ((mpm - speed_min) / (speed_max - speed_min)) * (byte_max - byte_min) + byte_min;

    mappedValue = Math.max(byte_min, Math.min(byte_max, mappedValue));
    mappedValue = Math.round(mappedValue);

    return mappedValue;
}

const parseProcedure = (data: string[]):Procedure => {
    return {
        name: data[0],
        title: data[1],
        id: data[2],
        people: data[3].trim().split('\n'),
        equipment: data[4].trim().split('\n'),
        content: data[5]
    }
}

const parseShortCut = async (shortcut:string):Promise<void> => {
    const tabMatch = shortcut.match(/^tab_(\d)$/);
    if (tabMatch) {
        const tab = tabMatch[1];
        console.log(`Switching to tab ${tab}`);
        detailTabSet.set(Number(tab) - 1);
    } else if (shortcut === "emergency_brake") {
        console.log("Emergency brake");
        await invoke('send_command', {cmdName: "EmergencyBrake", val: 0});
    } else if (shortcut === "heartbeat") {
        await invoke('send_command', {cmdName: "FrontendHeartbeat", val: 0});
    }
}

function setBitsToBooleans(num: number): boolean[] {
    console.log("We are statusing " + num);

    const numBits = 6;
    const bits = Array(numBits).fill(false);

    for (let i = 0; i < numBits; i++) {
        // Shift right by i and check if the least significant bit is 1
        bits[numBits - 1 - i] = ((num >> i) & 1) === 1;
    }

    console.log(bits);

    return bits;
}

export {tempParse, voltParse, addEntryToChart,  sensorParse, pressureParse, metersPerMinuteToByte, parseProcedure, parseShortCut, setBitsToBooleans};
