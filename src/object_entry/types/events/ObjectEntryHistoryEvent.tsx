import { ObjectEntryEvent } from "./ObjectEntryEvent";

export interface ObjectEntryHistoryEvent {
  new_values : ObjectEntryEvent[],
  deprecated_count : number,
}
