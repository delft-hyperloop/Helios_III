import { TableCell, TableRow} from "@mui/material";
import { useEffect, useState } from "react";
import { invoke } from "@tauri-apps/api";
import { ObjectEntryListenLatestResponse } from "../../types/events/ObjectEntryListenLatestResponse";
import { listen } from "@tauri-apps/api/event";
import { ObjectEntryEvent } from "../../types/events/ObjectEntryEvent";



export interface EnumListEntryProps {
  nodeName: string,
  objectEntryName: string,
  label?: string,

}

function EnumListEntry({ label, nodeName, objectEntryName }: Readonly<EnumListEntryProps>) {

  const [value, setValue] = useState<string>();

  useEffect(() => {
    async function asyncSetup() {
      const resp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", { nodeName, objectEntryName });
      if (resp.latest !== undefined && resp.latest !== null) {
        setValue(resp.latest.value as string);
      }
      let unlisten = await listen<ObjectEntryEvent>(resp.event_name, event => {
        setValue(event.payload.value as string);
      });
      return () => {
        invoke("unlisten_from_latest_object_entry_value", { nodeName, objectEntryName }).catch(console.error);
        unlisten();
      };
    }
    const asyncCleanup = asyncSetup();
    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    };
  }, []);


  return (
    <TableRow sx={{
      width: "100%",
    }}>
      <TableCell
        sx={{
          width: "40%",
        }}>
        {label ?? `${nodeName}::${objectEntryName}`}
      </TableCell>
      <TableCell
        sx={{
          width: "60%",
          minWidth: "100px",
          textAlign: "right",
        }}>
        {value ?? "-"}
      </TableCell>
    </TableRow >
  );
}

export default EnumListEntry;
