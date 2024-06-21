import { invoke } from "@tauri-apps/api";
import { Value } from "../../object_entry/types/Value";

async function sendSetReq(nodeName: string,
  objectEntryName: string, value: Value) {
  await invoke("set_object_entry_value", {
    nodeName,
    objectEntryName,
    newValueJson: JSON.stringify(value),
  });
}

export default sendSetReq;
