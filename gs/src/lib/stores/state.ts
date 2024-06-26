import { writable, type Writable } from 'svelte/store';
import {RunMode} from "$lib/types";
import {PlotBuffer} from "$lib";

export const detailTabSet: Writable<number> = writable(1);
export const inputSpeed: Writable<number> = writable(50);
export const inputPosit: Writable<number> = writable(-1);
export const inputEmerg: Writable<number> = writable(-1);
export const inputTurn: Writable<RunMode> = writable(RunMode.ShortRun);

export const vitals_pane: Writable<number> = writable(40)
export const details_pane: Writable<number> = writable(80)

export const chartStore = writable(new Map<string, PlotBuffer>());

export const serverStatus: Writable<boolean> = writable(false);