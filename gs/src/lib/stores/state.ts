import { writable, type Writable } from 'svelte/store';

export const detailTabSet: Writable<number> = writable(1);
export const inputSpeed: Writable<number> = writable(50);