// src/lib/stores/data.ts

import type {Procedure, RouteConfig} from "$lib/types";
import {writable, type Writable} from 'svelte/store';
import {invoke} from "@tauri-apps/api/tauri";
import {parseProcedure} from "$lib/util/parsers";

export const procedures: Writable<Procedure[]> = writable([{
  name: "NO PROCEDURES LOADED",
  title: "NO PROCEDURES LOADED",
  people: ["NO PROCEDURES LOADED"],
  content: "NO PROCEDURES LOADED",
  equipment: ["NO PROCEDURES LOADED"],
  id: "NO PROCEDURES LOADED"
}]);

export const initProcedures = async () => {
  await invoke("procedures").then(r => {
    console.log(`PROCEDURES LOADED`);
    procedures.set((r as string[][]).map(parseProcedure));
  }).catch((e) => {
    console.error(`Error loading procedures: ${e}`);
  });
}

export type SpeedFormKey =
  "BackwardC" | "ForwardB" | "ForwardA" | "LaneSwitchCurved" | "ForwardC" | "LaneSwitchStraight" | "BackwardA" | "BackwardB";

export const routeConfig:Writable<RouteConfig> = writable({
  speeds: {
    BackwardsA: 0,
    BackwardsB: 0,
    BackwardsC: 0,
    ForwardA: 0,
    ForwardB: 0,
    ForwardC: 0,
    LaneSwitchCurved: 0,
    LaneSwitchStraight: 0,
  },
  positions: [],
  current_position: 0,
})