import { List, Paper, Typography, useTheme } from "@mui/material";
import ErrorListItem, { ErrorLevel } from "./ErrorListItem";
import { useEffect, useState } from "react";
import { invoke } from "@tauri-apps/api";
import { NetworkInformation } from "../../../nodes/types/NetworkInformation";
import { NodeInformation } from "../../../nodes/types/NodeInformation";
import { ObjectEntryInformation } from "../../types/ObjectEntryInformation";
import { EnumTypeInfo } from "../../types/Type";
import { ObjectEntryListenLatestResponse } from "../../types/events/ObjectEntryListenLatestResponse";
import { listen } from "@tauri-apps/api/event";
import { ObjectEntryEvent } from "../../types/events/ObjectEntryEvent";
import { Value } from "../../types/Value";


export interface ObjectEntryId {
  nodeName: string,
  objectEntryName: string,
}

export interface ErrorId {
  value?: ObjectEntryId,
  error: ObjectEntryId,
}

interface ErrorListProps {
  width?: string,
  height?: string,
}

function ErrorList({width, height} : Readonly<ErrorListProps>) {
  const theme = useTheme();

  const [errorIds, setErrorIds] = useState<ErrorId[]>([]);

  useEffect(() => {
    async function asyncSetup() {
      setErrorIds([]);
      const nodes = await invoke<NetworkInformation>("network_information");
      let errorIds: ErrorId[] = [];
      for (let nodeName of nodes.node_names) {
        const nodeInfo = await invoke<NodeInformation>("node_information", { nodeName });
        for (let objectEntryName of nodeInfo.object_entries) {
          const objectEntryInfo = await invoke<ObjectEntryInformation>("object_entry_information", { nodeName, objectEntryName });
          if (objectEntryInfo.ty.id == "enum") {
            const enumName = (objectEntryInfo.ty.info as EnumTypeInfo).name;
            if (enumName == "error_flag" || enumName == "error_level") {
              let value = undefined;
              if (objectEntryInfo.friend !== undefined && objectEntryInfo.friend !== null) {
                value = {nodeName, objectEntryName : objectEntryInfo.friend};
              }
              errorIds.push({ error: { nodeName, objectEntryName }, value});
            }
          }
        }
      }
      setErrorIds(errorIds);
      return () => {
      };
    }
    let asyncCleanup = asyncSetup();
    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    };
  }, []);

  interface ErrorValue {
    errorId: ErrorId,
    level: ErrorLevel,
  }

  const [sortedErrors, setSortedErrors] = useState<ErrorValue[]>([]);

  function ValueToErrorLevel(value: Value) {
    if (value == "OK") {
      return 0;
    } else if (value == "INFO") {
      return 1;
    } else if (value == "WARNING") {
      return 2;
    } else {
      return 3;
    }
  }

  function updateError(id: ErrorId, level: ErrorLevel) {
    setSortedErrors(prev => {
      const next = prev.slice();
      const index = prev.findIndex(value => {
        return value.errorId.error.nodeName == id.error.nodeName && value.errorId.error.objectEntryName == id.error.objectEntryName;
      });
      if (index == -1) {
        if (level == 0) {
          return prev;
        } else {
          next.push({ errorId: id, level });
        }
      } else {
        if (level == 0) {
          next.splice(index, 1);
        } else {
          if (prev[index].level === level) {
            return prev;
          }
          next[index].level = level;
        }
      }
      next.sort((a, b) => b.level - a.level);
      return next;
    });
  }

  useEffect(() => {

    async function asyncFunc() {
      setSortedErrors(_ => []);
      const listeners: any[] = [];
      for (let errorId of errorIds) {
        const resp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value",
          { nodeName: errorId.error.nodeName, objectEntryName: errorId.error.objectEntryName });

        if (resp.latest !== null && resp.latest !== undefined) {
          updateError(errorId, ValueToErrorLevel(resp.latest.value));
        }


        let unlistenJs = listen<ObjectEntryEvent>(resp.event_name, event => {
          updateError(errorId, ValueToErrorLevel(event.payload.value));
        });
        listeners.push(() => {
          unlistenJs.then(f => f()).catch(console.error);
          invoke("unlisten_from_latest_object_entry_value", {
            nodeName: errorId.error.nodeName,
            objectEntryName: errorId.error.objectEntryName
          }).catch(console.error);
        });
      }
      return () => {
        for (let listener of listeners) {
          listener();
        }
      };
    }
    let asyncCleanup = asyncFunc();

    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    };
  }, [errorIds]);

  return (
    <Paper component="div" sx={{
      width,
      height,
    }}>
      <Typography textAlign="center" paddingTop="0.5em" paddingBottom="0.5em" variant="h6">
        Errors
      </Typography>
      <Paper sx={{
        backgroundColor: theme.palette.background.paper2,
        marginLeft: "0.5em",
        marginRight: "0.5em",
        marginBottom: "0.5em",
        overflow: "auto",
        height: `calc(${height} - 65px)`,
      }}>
        <List sx={{
          padding: 0,
          margin: 0,
        }}>
          {
            sortedErrors.map(v =>
              <ErrorListItem
                level={v.level}
                errorId={v.errorId}
              />
            )
          }
        </List>
      </Paper>
    </Paper>
  );
}

export default ErrorList;

