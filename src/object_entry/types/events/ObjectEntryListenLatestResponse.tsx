import { ObjectEntryEvent } from "./ObjectEntryEvent";

export interface ObjectEntryListenLatestResponse {
  event_name : string,
  latest? : ObjectEntryEvent
}

