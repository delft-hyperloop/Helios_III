import { Skeleton, TableCell, TableRow} from "@mui/material";
import { ObjectEntryInformation } from "../../types/ObjectEntryInformation";
import { useEffect, useState } from "react";
import { invoke } from "@tauri-apps/api";
import { ObjectEntryListenLatestResponse } from "../../types/events/ObjectEntryListenLatestResponse";
import { listen } from "@tauri-apps/api/event";
import { ObjectEntryEvent } from "../../types/events/ObjectEntryEvent";



export interface NumberListEntryProps {
  nodeName: string,
  objectEntryName: string,
  label?: string,

}

function NumberListEntry({ label, nodeName, objectEntryName }: Readonly<NumberListEntryProps>) {

  const [information, setInformation] = useState<ObjectEntryInformation>();
  const [value, setValue] = useState<number>();

  useEffect(() => {
    async function asyncSetup() {
      try {
      const info = await invoke<ObjectEntryInformation>("object_entry_information", { nodeName, objectEntryName });
      setInformation(info);
      const resp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", { nodeName, objectEntryName });
      if (resp.latest !== undefined && resp.latest !== null) {
        setValue(resp.latest.value as number);
      }
      let unlisten = await listen<ObjectEntryEvent>(resp.event_name, event => {
        setValue(event.payload.value as number);
      });
      return () => {
        invoke("unlisten_from_latest_object_entry_value", { nodeName, objectEntryName }).catch(console.error);
        unlisten();
      };
      }catch {
        console.error(`Failed to register listeners for NumberListEntry component: Object entry ${nodeName}:${objectEntryName} not found.`);
        return () => {
        }
      }
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
      {information ?
        <>
          <TableCell
            sx={{
              width: "60%",
            }}>
            {label ?? `${nodeName}::${objectEntryName}`}
          </TableCell>
          <TableCell
            sx={{
              width: "40%",
              minWidth: "100px",
              textAlign: "right",
            }}>
            {value ? Math.round(value * 100.0) / 100.0 : "-"} {information?.unit ?? ""}
          </TableCell>
        </>
        : <>
          <TableCell sx={{width: "60%"}}>
            {label ?? `${nodeName}::${objectEntryName}`}
          </TableCell>
          <TableCell sx={{width: "40%", minWidth: "100px"}}>
            <Skeleton />
          </TableCell>
        </>}
    </TableRow>
  );
}

export default NumberListEntry;
