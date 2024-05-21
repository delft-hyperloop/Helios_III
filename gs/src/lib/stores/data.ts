// src/lib/store.ts
import {type Writable, writable} from 'svelte/store';
import type {BmsModuleTemperature, BmsModuleVoltage, Payload} from "$lib/types";

export const south_bridge_payload: Writable<Payload> = writable({
    value: 0,
    values: [],
    timestamp: 0
});


export const hvBattery: Writable<bigint> = writable(BigInt(-1));
export const lvBattery: Writable<bigint> = writable(BigInt(-1));
export const hvBatCurrent: Writable<bigint> = writable(BigInt(-1));
export const lvBatCurrent: Writable<bigint> = writable(BigInt(-1));

// MODULES
export const hvModulesTemp: Writable<BmsModuleTemperature[]> = writable([
    {id: BigInt(0), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(1), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(2), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(3), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(4), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(5), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(6), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(7), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
])
export const hvModulesVol: Writable<BmsModuleVoltage[]> = writable([
    {id: BigInt(0), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(1), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(2), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(3), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(4), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(5), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(6), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(7), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
])
