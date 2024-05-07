import { writable, type Writable } from 'svelte/store';

export const detailTabSet: Writable<number> = writable(1);
export const inputSpeed: Writable<number> = writable(50);

export const vitals_pane: Writable<number> = writable(40)
export const details_pane: Writable<number> = writable(80)
