import { ObjectEntryEvent } from "./ObjectEntryEvent";

export interface ObjectEntryListenHistoryResponse {
  event_name : string,
  history : ObjectEntryEvent[],
  now : number,
}

