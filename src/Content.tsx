import CustomAppBar from "./app_bar/CustomAppBar";
import React, { useEffect, useState } from "react";
import SideMenu from "./side_menu/SideMenu";
import CssBaseline from "@mui/material/CssBaseline";
import {
    Backdrop,
    Box,
    Button,
    CircularProgress,
    Dialog,
    DialogActions,
    DialogContent,
    DialogTitle,
    useTheme
} from "@mui/material";
import ShowPages from "./dashboard/ShowPages";
import { invoke } from "@tauri-apps/api";
import { listen } from "@tauri-apps/api/event";


function restart() {
  invoke("restart").catch(console.error);
}


function Content() {
  const [open, setOpen] = useState<boolean>(false);
  const [backendError, setBackendError] = useState<string>();
    const [loading, setLoading] = React.useState<boolean>(false);

    function exportLog(){
        setLoading(true)
        invoke("export").then(() => setLoading(false));
    }

    useEffect(() => {

    function readBackendStatus(connection: string) {
      if (connection == "network-connected") {
        setBackendError(undefined);
      } else if (connection == "sync-done") {
        setBackendError(undefined);
      } else if (connection == "heartbeat-miss") {
        setBackendError("Heartbeat timed out");
      } else if (connection == "network-disconnected") {
        setBackendError("Network disconnected");
      } else if (connection == "frontend-wdg-timeout") {
        setBackendError("Frontend freezed");
      } else if (connection == "deadlock-wdg-timeout") {
        setBackendError("Detected deadlock")
      } else {
        setBackendError("Oh wow we fucked");
      }
    }

    let unlistenJs = listen<string>("connection-status", event => readBackendStatus(event.payload))

    invoke<string>("get_connection_status").then(readBackendStatus).catch(console.error);
    return () => {
      unlistenJs.then(f => f()).catch(console.error);
    };
  }, []);


  const theme = useTheme();
  return (
    <Box id="content" component="div" sx={{ display: 'flex' }}>
      <CssBaseline />
      <CustomAppBar
        stateColor="stateIdle"
        open={open}
        toggleOpen={() => setOpen(x => !x)} />
      <SideMenu open={open} toggleOpen={() => setOpen(x => !x)} />
      <Box
        component="main"
        sx={{
          backgroundColor: theme.palette.background.main,
          flexGrow: 1,
          minHeight: 'calc(100vh - 75px)',
          maxHeight: 'calc(100vh - 75px)',
          overflow: 'auto',
          position: "relative",
          marginTop: "75px",
        }}
      >
        <Box component="div" sx={{ width: '100%' }}>
          <ShowPages />
        </Box>
      </Box>
      <Dialog open={backendError != undefined} >
        <DialogTitle>Network Connection closed</DialogTitle>
        <DialogContent>
          {backendError}
        </DialogContent>
        <DialogActions>
          <Button onClick={restart}>Restart</Button>
          <Button onClick={exportLog}>Export Logfiles</Button>
        </DialogActions>
      </Dialog>
        <Backdrop
            sx={{color: '#fff', zIndex: (theme) => theme.zIndex.drawer + 1}}
            open={loading}
        >
            <CircularProgress color="inherit"/>
        </Backdrop>
    </Box>
  );
}

export default Content;
