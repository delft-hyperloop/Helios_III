// src/lib/store.ts
import {type Writable, writable} from 'svelte/store';
import type {Payload} from "$lib/types";

export const south_bridge_payload: Writable<Payload> = writable({
    value: 0,
    values: [],
    timestamp: 0
});


export const hvBattery: Writable<number> = writable(-1);
export const lvBattery: Writable<number> = writable(-1);
export const hvBatCurrent: Writable<number> = writable(-1);