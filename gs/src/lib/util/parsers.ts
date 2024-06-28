import type {dataConvFun} from "$lib/types";
import {PlotBuffer} from "$lib/util/PlotBuffer";

const tempParse:dataConvFun<number> = (data:bigint) => {
    return Number(data) - 100;
}

const voltParse:dataConvFun<string> = (data:bigint) => {
    return Number(data) === 200 ? "INVALID" : (Number(data) / 100).toString();
}

const addEntryToChart = (chart:PlotBuffer, data:bigint, index:number) => {
    const curr = u64ToDouble(data);
    chart.addEntry(index, curr);
    return curr;
}

const u64ToDouble = (u64: bigint): number => {
    const buffer = Buffer.alloc(8);

    const high = Number(u64 / BigInt(2**32));
    const low = Number(u64 % BigInt(2**32));

    buffer.writeUInt32LE(low, 0);
    buffer.writeUInt32LE(high, 4);

    return buffer.readDoubleLE(0);
}

export {tempParse, voltParse, addEntryToChart, u64ToDouble};