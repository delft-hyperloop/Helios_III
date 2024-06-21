import { AppBar, Box, Checkbox, Container, CssBaseline, IconButton, List, ListItem, ListItemButton, ListItemIcon, ListItemText, Stack, Toolbar, Typography, useTheme } from "@mui/material";
import CloseIcon from '@mui/icons-material/Close';
import SettingsApplicationsIcon from '@mui/icons-material/SettingsApplications';
import { invoke } from "@tauri-apps/api";
import { useEffect, useState } from "react";

enum WdgLevel {
  Disable = "Disable",
  Ignore = "Ignore",
  Active = "Active",
}

interface Settings {
  configPath: string,
  frontendWdgLvl: WdgLevel,
  deadlockWdgLvl: WdgLevel,
}


function SettingsContent() {
  const theme = useTheme();
  const [frontendLvl, setFrontendLvl] = useState<WdgLevel>(WdgLevel.Active);
  const [deadlockLvl, setDeadlockLvl] = useState<WdgLevel>(WdgLevel.Active);
  const [configPath, setConfigPath] = useState<string>();


  useEffect(() => {
    invoke<Settings>("get_settings").then(s => {
      setFrontendLvl(s.frontendWdgLvl);
      setDeadlockLvl(s.deadlockWdgLvl);
      setConfigPath(s.configPath);
    }).catch(console.error);

  }, []);

  return (
    <Box id="content" component="div" display="flex">
      <CssBaseline />
      <AppBar position="absolute" sx={{
        backgroundColor: theme.palette.background.paper,
        height: "60px",
      }}>
        <Container component="div">
          <Toolbar disableGutters sx={{
            justifyContent: "space-between",
          }}>
            <Stack component="div" direction="row">
              <Typography variant="h5" color={theme.palette.text.secondary}>
                CANzero
              </Typography>
              <Typography marginLeft="0.5em" variant="h5" color={theme.palette.text.disabled}>
                Settings
              </Typography>
            </Stack>
            <Stack component="div" direction="row" spacing={2}>
              <IconButton onClick={() => invoke("close_settings").catch(console.error)}>
                <CloseIcon />
              </IconButton>
            </Stack>
          </Toolbar>
        </Container>
      </AppBar>
      <Container component="main" sx={{
        backgroundColor: theme.palette.background.main,
        flexGrow: 1,
        minHeight: 'calc(100vh - 60px)',
        maxHeight: 'calc(100vh - 60px)',
        width: "100%",
        overflow: 'auto',
        position: "relative",
        marginTop: "60px",
      }}>
        <List>
          <ListItem disablePadding>
            <ListItemButton onClick={() => {
              invoke("select_network_configuration").catch(console.error);
            }}>
              <ListItemIcon sx={{ justifyContent: "center" }}>
                <SettingsApplicationsIcon />
              </ListItemIcon>
              <ListItemText primary="Select network configuration" secondary={configPath} />
            </ListItemButton>
          </ListItem>
          <ListItem disablePadding>
            <ListItemButton>
              <ListItemIcon sx={{ justifyContent: "center" }}>
                <Checkbox checked={frontendLvl !== WdgLevel.Active} onChange={(evt) => {
                  invoke<WdgLevel>("set_frontend_lvl", {
                    lvl: evt.target.checked ? WdgLevel.Ignore : WdgLevel.Active
                  })
                    .then(i => setFrontendLvl(i))
                    .catch(console.error);
                }} />
              </ListItemIcon>
              <ListItemText
                primary="Ignore Frontend Watchdog"
                secondary="Timeout still signaled as a warining" />
            </ListItemButton>
          </ListItem>
          <ListItem disablePadding>
            <ListItemButton>
              <ListItemIcon sx={{ justifyContent: "center" }}>
                <Checkbox
                  disabled={frontendLvl === WdgLevel.Active}
                  checked={frontendLvl === WdgLevel.Disable} onChange={(evt) => {
                    invoke<WdgLevel>("set_frontend_lvl", {
                      lvl: evt.target.checked ? WdgLevel.Disable : WdgLevel.Ignore
                    })
                      .then(i => setFrontendLvl(i))
                      .catch(console.error);
                  }} />
              </ListItemIcon>
              <ListItemText
                primary="Disable Frontend Watchdog"
                secondary="Danger: A frozen frontend might not lead to a shutdown" />
            </ListItemButton>
          </ListItem>
          <ListItem disablePadding>
            <ListItemButton>
              <ListItemIcon sx={{ justifyContent: "center" }}>
                <Checkbox checked={deadlockLvl !== WdgLevel.Active} onChange={(evt) => {
                  invoke<WdgLevel>("set_deadlock_lvl", {
                    lvl: evt.target.checked ? WdgLevel.Ignore : WdgLevel.Active
                  })
                    .then(i => setDeadlockLvl(i))
                    .catch(console.error);
                }} />
              </ListItemIcon>
              <ListItemText
                primary="Ignore Deadlock Watchdog"
                secondary="Timeout still signaled as a warining" />
            </ListItemButton>
          </ListItem>
          <ListItem disablePadding>
            <ListItemButton>
              <ListItemIcon sx={{ justifyContent: "center" }}>
                <Checkbox
                  disabled={deadlockLvl === WdgLevel.Active}
                  checked={deadlockLvl === WdgLevel.Disable}
                  onChange={(evt) => {
                    invoke<WdgLevel>("set_deadlock_lvl", {
                      lvl: evt.target.checked ? WdgLevel.Disable : WdgLevel.Ignore
                    })
                      .then(i => setDeadlockLvl(i))
                      .catch(console.error);
                  }} />
              </ListItemIcon>
              <ListItemText
                primary="Disable Deadlock Watchdog"
                secondary="Danger: A deadlocked backend might not lead to a shutdown" />
            </ListItemButton>
          </ListItem>
        </List>
      </Container>

    </Box >
  );
}

export default SettingsContent;
