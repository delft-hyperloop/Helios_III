import { StaticRouter } from "react-router-dom/server";
import "./App.css";
import { MemoryRouter } from "react-router-dom";
import { Backdrop, CircularProgress, ThemeProvider } from "@mui/material";
import { SnackbarProvider } from "notistack";
import NotificationSystem from "./dashboard/NotificationSystem.tsx";
import React, { useEffect } from "react";
import Content from "./Content.tsx";
import theme from "./theme.ts"
import { invoke } from "@tauri-apps/api";
import { listen } from "@tauri-apps/api/event";
import { Heartbeat } from "./heartbeat/Heartbeat.tsx";
import { appWindow } from "@tauri-apps/api/window";
import { ask, confirm } from "@tauri-apps/api/dialog";


function Router(props: Readonly<{ children?: React.ReactNode }>) {
  const { children } = props;
  if (typeof window === 'undefined') {
    return <StaticRouter location="/">{children}</StaticRouter>;
  }

  return (
    <MemoryRouter initialEntries={['/']} initialIndex={0}>
      {children}
    </MemoryRouter>
  );
}

function App() {
  const [loading, setLoading] = React.useState<boolean>(false)

  const [syncDone, setSyncDone] = React.useState<boolean>(false);

  useEffect(() => {

    let unlistenJs = listen<string>("connection-status", event => {
      let state = event.payload;
      setSyncDone(state == "sync-done");
    });
    
    invoke<string>("get_connection_status").then(state => {
      setSyncDone(state == "sync-done");
    }).catch(console.error);
    
    return () => {
      unlistenJs.then(f => f()).catch(console.error);
    };
  }, []);

  useEffect(() => {
    invoke("close_startup", {}).catch(console.error);
  }, []);

  useEffect(() => {
    async function close() {
      const unlisten = await appWindow.onCloseRequested(async (event) => {
        const confirmClose = await confirm("Close Control Panel?");
        if (!confirmClose) {
          event.preventDefault();
        } else {
          const unregisterHeartbeat = await ask("Unregister from heartbeat before closing?");
          if (unregisterHeartbeat) {
            await invoke("unregister_from_heartbeat")
          }
          const saveLogs = await ask("Save logs before closing?");
          if (saveLogs) {
            setLoading(true)
            invoke("export").then(() => setLoading(false));
          }
        }
      });

      return () => {
        unlisten();
      };
    }

    let asyncCleanup = close();
    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    };
  }, []);

  return (
    <ThemeProvider theme={theme}>
      <SnackbarProvider preventDuplicate maxSnack={7}>
        <Heartbeat />
        <NotificationSystem />
        <Router>
          <Content />
        </Router>
        <Backdrop
          sx={{ color: '#fff', zIndex: (theme) => theme.zIndex.drawer + 1 }}
          open={loading || !syncDone}
        >
          <CircularProgress color="inherit" />
        </Backdrop>
      </SnackbarProvider>
    </ThemeProvider>
  );
}

export default App;
