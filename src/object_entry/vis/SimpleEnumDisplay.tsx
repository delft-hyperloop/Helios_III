import { TextField } from "@mui/material";
import { useEffect, useState } from "react";
import { ObjectEntryListenLatestResponse } from "../types/events/ObjectEntryListenLatestResponse";
import { invoke } from "@tauri-apps/api";
import { ObjectEntryEvent } from "../types/events/ObjectEntryEvent";
import { listen } from "@tauri-apps/api/event";


interface SimpleEnumDisplayProps {
  nodeName: string,
  objectEntryName: string,
}

function SimpleEnumDisplay({ nodeName, objectEntryName }: Readonly<SimpleEnumDisplayProps>) {

  const [value, setValue] = useState<string>("UNKNOWN");

  useEffect(() => {
    async function asyncSetup() {
      const resp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", {
        nodeName, objectEntryName
      });
      if (resp.latest !== undefined && resp.latest !== null) {
        setValue(resp.latest.value as string);
      }
      const unlistenJs = await listen<ObjectEntryEvent>(resp.event_name, event => {
        setValue(event.payload.value as string);
      });

      return () => {
        invoke("unlisten_from_latest_object_entry_value", {nodeName, objectEntryName}).catch(console.error);
        unlistenJs();
      };
    }
    const asyncCleanup = asyncSetup();
    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    };
  }, [nodeName, objectEntryName]);

  return (
    <TextField
      id="state-display-button"
      label={`${nodeName}::${objectEntryName}`}
      variant="filled"
      value={value}
      sx={{
        input: {
          background: "white",
          width: "200px",
        },
      }}
      InputProps={{
        readOnly: true,
        disableUnderline: true,
      }}
    />
  );


}

export default SimpleEnumDisplay;
