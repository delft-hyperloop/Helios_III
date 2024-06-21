import { ListItem, ListItemIcon, ListItemText, Tooltip, useTheme } from "@mui/material";

import CancelIcon from '@mui/icons-material/Cancel';
import FeedbackIcon from '@mui/icons-material/Feedback';
import WarningIcon from '@mui/icons-material/Warning';
import { Value } from "../../types/Value";
import { useEffect, useState } from "react";
import { listen } from "@tauri-apps/api/event";
import { ObjectEntryListenLatestResponse } from "../../types/events/ObjectEntryListenLatestResponse";
import { invoke } from "@tauri-apps/api";
import { ObjectEntryEvent } from "../../types/events/ObjectEntryEvent";
import { ObjectEntryInformation } from "../../types/ObjectEntryInformation";
import { ErrorId } from "./ErrorList";


export type ErrorLevel = 0 | 1 | 2 | 3;

interface ErrorListItemProps {
  level: ErrorLevel,
  errorId: ErrorId,
}

function ErrorListItem({
  level,
  errorId,
}: Readonly<ErrorListItemProps>) {

  const [value, setValue] = useState<Value>();
  const [unit, setUnit] = useState<string>();
  const [description, setDescription] = useState<string>();

  useEffect(() => {
    async function async_setup() {
      let info_error = await invoke<ObjectEntryInformation>("object_entry_information", { nodeName: errorId.error.nodeName, objectEntryName: errorId.error.objectEntryName });
      setDescription(info_error.description);
      let unlistenJs;
      if (errorId.value !== undefined) {
        let info_value = await invoke<ObjectEntryInformation>("object_entry_information", { nodeName: errorId.value.nodeName, objectEntryName: errorId.value.objectEntryName });
        setUnit(info_value.unit);
        let event = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", { nodeName: errorId.value.nodeName, objectEntryName: errorId.value.objectEntryName });
        setValue(event.latest?.value);
        unlistenJs = await listen<ObjectEntryEvent>(event.event_name, event => {
          setValue(event.payload.value);
        });
      } else {
        unlistenJs = () => { }
      }

      return () => {
        unlistenJs();
        if (errorId.value !== undefined) {
          invoke("unlisten_from_latest_object_entry_value", {
            nodeName: errorId.value.nodeName,
            objectEntryName: errorId.value.objectEntryName
          }).catch(console.error);
        }
      };
    }
    let async_cleanup = async_setup();
    return () => {
      async_cleanup.then(f => f()).catch(console.error);
    };
  }, [errorId]);


  const theme = useTheme();

  let backgroundColor;
  let icon;
  switch (level) {
    case 1:
      backgroundColor = "lightblue";
      icon = <FeedbackIcon sx={{
        fontSize: "1em",
        color: "blue",
      }} />
      break;
    case 2:
      backgroundColor = theme.palette.background.warn;
      icon = <WarningIcon sx={{
        fontSize: "1em",
        color: "orange",
      }} />
      break;
    case 3:
      backgroundColor = theme.palette.background.error;
      icon = <CancelIcon sx={{
        fontSize: "1em",
        color: "red",
      }}
      />
      break;
  }

  return (
    <Tooltip title={description} placement="top">
      <ListItem sx={{
        padding: 0,
        marginLeft: 0,
        marginRight: 0,
        marginTop: "1px",
        backgroundColor: backgroundColor,
      }}
        secondaryAction={
          <ListItemText>
            {(value === undefined ? "?" : value.toString()) + (unit ?? "")}
          </ListItemText>
        }>
        <ListItemIcon sx={{
          width: "1em",
          minWidth: "1.5em",
          maxWidth: "1.5em",
          marginLeft: 1,
        }}>
          {icon}
        </ListItemIcon>
        <ListItemText
          primaryTypographyProps={{
            padding: 0,
            fontSize: "0.8em",

          }}
        >
          {errorId.error.objectEntryName}
        </ListItemText>
      </ListItem>
    </Tooltip>
  );

}

export default ErrorListItem;
