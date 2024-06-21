import { useEffect, useState } from "react";
import { Value } from "../object_entry/types/Value";
import { invoke } from "@tauri-apps/api";
import { UnlistenFn, listen } from "@tauri-apps/api/event";
import { ObjectEntryListenLatestResponse } from "../object_entry/types/events/ObjectEntryListenLatestResponse";
import { ObjectEntryEvent } from "../object_entry/types/events/ObjectEntryEvent";



function useObjectEntryValue(nodeName: string, objectEntryName: string) {
  const [value, setValue] = useState<Value>();

  useEffect(() => {
    let unlistenJs : UnlistenFn | undefined;
    invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", {
      nodeName, objectEntryName,
    }).then(resp => {
      listen<ObjectEntryEvent>(resp.event_name, event => {
        setValue(event.payload.value);
      }).then(unlisten => unlistenJs = unlisten).catch(console.error);
    }).catch(console.error);
    return () => {
      if (unlistenJs !== undefined) {
        unlistenJs();
      }
      invoke("unlisten_from_latest_object_entry_value", { nodeName, objectEntryName }).catch(console.error);
    };
  }, [nodeName, objectEntryName]);

  return value;
}

export default useObjectEntryValue;
