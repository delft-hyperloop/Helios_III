import { writable, type Writable } from 'svelte/store';

export const detailTabSet: Writable<number> = writable(0);