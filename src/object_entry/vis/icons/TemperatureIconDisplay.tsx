import { Thermostat } from "@mui/icons-material";
import { Box, Typography } from "@mui/material";
import { invoke } from "@tauri-apps/api";
import { useEffect, useState } from "react";
import { ObjectEntryListenLatestResponse } from "../../types/events/ObjectEntryListenLatestResponse";
import { listen } from "@tauri-apps/api/event";
import { ObjectEntryEvent } from "../../types/events/ObjectEntryEvent";
import theme from "../../../theme.ts";



const OE = { nodeName: "master", objectEntryName: "error_over_temperature" };

function TemperatureIconDisplay() {

  const [state, setState] = useState<boolean>(false);

  useEffect(() => {
    async function asyncSetup() {
      try {
        const resp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", OE);
        if (resp.latest !== undefined && resp.latest !== null) {
          setState(resp.latest.value as string == "CLOSED");
        }
        const unlisten = await listen<ObjectEntryEvent>(resp.event_name, event => {
          setState(event.payload.value as string == "CLOSED");
        });
        return () => {
          unlisten();
          invoke("unlisten_from_latest_object_entry_value", OE).catch(console.error);
        };
      } catch(e) {
        console.error(`Failed to register listener for temperature icon: Object entry ${OE.nodeName}:${OE.objectEntryName} not found`);
        return () => {}
      }
    }
    const asyncCleanup = asyncSetup();

    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    };

  }, []);

  return (
    <Box component="div" sx={{
      textAlign: "center",
    }}>
      <Thermostat sx={{ fontSize: "32px", color: state ? "red" : theme.palette.background.disabled  }} />
      <div style={{ marginBottom: "-6px" }} />
      <Typography color="white">
        OverTemp
      </Typography>
    </Box>
  );
}

export default TemperatureIconDisplay;
