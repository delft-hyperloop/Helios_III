import { ObjectEntryEvent } from "../../object_entry/types/events/ObjectEntryEvent";



export interface NodeEvent {
  object_entry_values : (ObjectEntryEvent | null)[],
}
