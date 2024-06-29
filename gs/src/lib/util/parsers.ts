import type {dataConvFun} from "$lib/types";
import {PlotBuffer} from "$lib/util/PlotBuffer";
const MAX_VALUE = 4_294_967_295;

const tempParse: dataConvFun<number> = (data: bigint) => {
    return Number(data) - 100;
}

const voltParse: dataConvFun<string> = (data: bigint) => {
    return Number(data) === 200 ? "INVALID" : (Number(data) / 100).toString();
}

const addEntryToChart = (chart: PlotBuffer, data: bigint, index: number) => {
    const curr = u64ToDouble(data);
    chart.addEntry(index, curr);
    return curr;
}

const u64ToDouble = (u64: bigint): number => {
    const buffer = new ArrayBuffer(8);
    const view = new DataView(buffer);

    const high = Number(BigInt(u64) / BigInt(2 ** 32));
    const low = Number(BigInt(u64) % BigInt(2 ** 32));

    view.setUint32(0, low, true);
    view.setUint32(4, high, true);

    return view.getFloat64(0, true);
}

const sensorParse = (u64 : bigint) : number =>{
    return u64>MAX_VALUE-100000 ? -(MAX_VALUE-Number(u64)+1)/100 : Number(u64)/100;
}

const pressureParse = (u64 : bigint) : number => {
    return u64>-MAX_VALUE-100000 ? 0 : Number(u64)/100;
}

const metersPerMinuteToByte = (mpm: number): number => {
    if (mpm === 0) return 0;

    const speed_min = -500;
    const speed_max = 500;
    const byte_min = 0;
    const byte_max = 255;

    let mappedValue = ((mpm - speed_min) / (speed_max - speed_min)) * (byte_max - byte_min) + byte_min;

    mappedValue = Math.max(byte_min, Math.min(byte_max, mappedValue));
    mappedValue = Math.round(mappedValue);

    return mappedValue;
}

export {tempParse, voltParse, addEntryToChart, u64ToDouble, sensorParse, pressureParse, metersPerMinuteToByte};