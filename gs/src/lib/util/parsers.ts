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
    const buffer = new ArrayBuffer(8);
    const view = new DataView(buffer);

    const high = Number(u64 / BigInt(2**32));
    const low = Number(u64 % BigInt(2**32));

    view.setUint32(0, low, true);
    view.setUint32(4, high, true);

    return view.getFloat64(0, true);
}

export {tempParse, voltParse, addEntryToChart, u64ToDouble};