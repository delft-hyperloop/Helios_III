import { Value } from "../Value";

export interface ObjectEntryEvent {
  value: Value
  timestamp: number,
  delta_time: number,
}
