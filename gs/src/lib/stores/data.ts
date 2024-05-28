// src/lib/store.ts
import {type Writable, writable} from 'svelte/store';
import type {BmsModuleTemperature, Payload} from "$lib/types";

export const south_bridge_payload: Writable<Payload> = writable({
    value: 0,
    values: [],
    timestamp: 0
});

// MODULES
export const initTemps: BmsModuleTemperature[] = [
    {id: BigInt(0), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(1), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(2), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(3), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(4), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(5), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(6), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
    {id: BigInt(7), max: BigInt(1), min: BigInt(1), avg: BigInt(1)},
]
