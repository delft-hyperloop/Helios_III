import { AppBar as MuiAppBar, AppBarProps as MuiAppBarProps, IconButton, Toolbar, styled, Stack, useTheme } from "@mui/material";
import MenuIcon from '@mui/icons-material/Menu';
import { DRAWER_WIDTH } from "../side_menu/SideMenu";
import AppBarButton from "./AppBarButton";
import StateDisplay from "./StateDisplay";
import { ReactElement, useEffect, useState } from "react";
import { ObjectEntryListenLatestResponse } from "../object_entry/types/events/ObjectEntryListenLatestResponse";
import { invoke } from "@tauri-apps/api";
import { listen } from "@tauri-apps/api/event";
import { ObjectEntryEvent } from "../object_entry/types/events/ObjectEntryEvent";
import StateIndicatorBar from "./StateIndicatorBar.tsx";
import WarningIconDisplay from "../object_entry/vis/icons/WarningIconDisplay";
import BatteryIconDisplay from "../object_entry/vis/icons/BatteryIconDisplay";
import TemperatureIconDisplay from "../object_entry/vis/icons/TemperatureIconDisplay";
import ElectricIconDisplay from "../object_entry/vis/icons/ElectricIconDisplay";
import { sendCalibrate, sendEmergencyCommand, sendShutdown, sendStart45Command, sendStartController, sendStartLevitationCommand, sendStartPropulsionCommand, sendStop45Command, sendStopController, sendStopLevitationCommand, sendStopPropulsionCommand } from "./commands.ts";

interface AppBarProps extends MuiAppBarProps {
  open?: boolean;
}

const AppBar = styled(MuiAppBar, {
  shouldForwardProp: (prop) => prop !== 'open',
})<AppBarProps>(({ theme, open }) => ({
  zIndex: theme.zIndex.drawer + 1,
  transition: theme.transitions.create(['width', 'margin'], {
    easing: theme.transitions.easing.sharp,
    duration: theme.transitions.duration.leavingScreen,
  }),
  ...(open && {
    marginLeft: DRAWER_WIDTH,
    width: `calc(100% - ${DRAWER_WIDTH}px)`,
    transition: theme.transitions.create(['width', 'margin'], {
      easing: theme.transitions.easing.sharp,
      duration: theme.transitions.duration.enteringScreen,
    }),
  }),
}));


interface CustomAppBarProps {
  open: boolean,
  stateColor: string,
  toggleOpen: () => void,
}


const STATE_OE = { nodeName: "mother_board", objectEntryName: "state" };

const START_45V_LABEL = <p>Start<br />45V-System [F1]</p>;
const STOP_45V_LABEL = <p>Stop<br />45V-System [F2]</p>;
const START_LEVI_LABEL = <p>Start<br />Levitation [F1]</p>;
const STOP_LEVI_LABEL = <p>Stop<br />Levitation [F2]</p>;
const START_PROP_LABEL = <p>Start<br />Propulsion [F1]</p>;
const STOP_PROP_LABEL = <p>Stop<br />Propulsion [F2]</p>;

const GAMEPAD_CONTROL = <p>Gamepad<br />Control [F2]</p>;
const STOP_GAMEPAD_CONTROL = <p>Stop<br />Gamepad [F2]</p>;

const CALIBRATE_LABEL = <p>Calibrate<br />Sensors [F3]</p>;
const SHUTDOWN_LABEL = <p>Shutdown<br />System [F2]</p>;

interface CommandList {
  startCommandLabel: ReactElement;
  disableStart: boolean,
  startCommand: () => void,

  stopCommandLabel: ReactElement;
  disableStop: boolean,
  stopCommand: () => void,

  option1Label: ReactElement,
  disableOption1: boolean,
  option1Command: () => void,

  option2Label: ReactElement,
  disableOption2: boolean,
  option2Command: () => void,

}

function CustomAppBar({ open, toggleOpen }: Readonly<CustomAppBarProps>) {

  const theme = useTheme();
  const [state, setState] = useState<string>("COM_DISCONNECTED");
  const [commandList, setCommandList] = useState<CommandList>({
    startCommandLabel: <p>Setting up</p>,
    disableStart: true,
    startCommand: () => { },

    stopCommandLabel: <p>Setting up</p>,
    disableStop: true,
    stopCommand: () => { },

    option1Label: <></>,
    disableOption1: true,
    option1Command: () => { },

    option2Label: <></>,
    disableOption2: true,
    option2Command: () => { },
  });

  function updateState(state: string) {
    setState(state);

    let startCommandLabel: ReactElement;
    let disableStart: boolean;
    let startCommand: () => void;
    let stopCommandLabel: ReactElement;
    let disableStop: boolean;
    let stopCommand: () => void;

    let option1Label = <></>;
    let disableOption1 = true;
    let option1Command = () => { };

    let option2Label = <></>;
    let disableOption2 = true;
    let option2Command = () => { };


    switch (state) {
      case "COM_DISCONNECTED":
      case "INIT":
        startCommandLabel = START_45V_LABEL;
        disableStart = true;
        startCommand = () => { };
        stopCommandLabel = STOP_45V_LABEL;
        disableStop = true;
        stopCommand = () => { };

        break;
      case "IDLE":
        startCommandLabel = START_45V_LABEL;
        disableStart = false;
        startCommand = sendStart45Command;
        stopCommandLabel = SHUTDOWN_LABEL;
        disableStop = false;
        stopCommand = sendShutdown;

        disableOption1 = false;
        option1Label = CALIBRATE_LABEL;
        option1Command = sendCalibrate;
        break;
      case "ARMING45":
        startCommandLabel = START_45V_LABEL;
        disableStart = true;
        startCommand = () => { };
        stopCommandLabel = STOP_45V_LABEL;
        disableStop = false;
        stopCommand = sendStop45Command;
        break;
      case "PRECHARGE":
        startCommandLabel = START_45V_LABEL;
        disableStart = true;
        startCommand = () => { };
        stopCommandLabel = STOP_45V_LABEL;
        disableStop = false;
        stopCommand = sendStop45Command;
        break;
      case "DISARMING45":
        startCommandLabel = START_45V_LABEL;
        disableStart = true;
        startCommand = () => { };
        stopCommandLabel = STOP_45V_LABEL;
        disableStop = true;
        stopCommand = () => { };
        break;
      case "READY":
        startCommandLabel = START_LEVI_LABEL;
        disableStart = false;
        startCommand = sendStartLevitationCommand;
        stopCommandLabel = STOP_45V_LABEL;
        disableStop = false;
        stopCommand = sendStop45Command;
        break;
      case "START_LEVITATION":
      case "LEVITATION_STABLE":
      case "START_GUIDANCE":
        startCommandLabel = START_LEVI_LABEL;
        disableStart = true;
        startCommand = () => { };
        stopCommandLabel = STOP_LEVI_LABEL;
        disableStop = false;
        stopCommand = sendStopLevitationCommand;
        break;
      case "GUIDANCE_STABLE":
        startCommandLabel = START_PROP_LABEL;
        disableStart = false;
        startCommand = sendStartPropulsionCommand;
        stopCommandLabel = STOP_LEVI_LABEL;
        disableStop = false;
        stopCommand = sendStopLevitationCommand;

        option1Label = GAMEPAD_CONTROL;
        disableOption1 = false;
        option1Command = sendStartController;
        break;
      case "CRUISING":
      case "ACCELERATION":
        startCommandLabel = START_PROP_LABEL;
        disableStart = true;
        startCommand = () => { };
        stopCommandLabel = STOP_PROP_LABEL;
        disableStop = false;
        stopCommand = sendStopPropulsionCommand;
        break;
      case "CONTROLLER":
        startCommandLabel = GAMEPAD_CONTROL;
        disableStart = true;
        startCommand = () => { };
        stopCommandLabel = STOP_GAMEPAD_CONTROL;
        disableStop = false;
        stopCommand = sendStopController;
        break;
      case "DECELERATION":
        startCommandLabel = START_PROP_LABEL;
        disableStart = true;
        startCommand = () => { };
        stopCommandLabel = STOP_PROP_LABEL;
        disableStop = true;
        stopCommand = () => { };
        break;
      default:
        startCommandLabel = <p>Emergency</p>;
        stopCommandLabel = <p>Emergency</p>;
        disableStop = false;
        disableStart = false;
        startCommand = () => { };
        stopCommand = () => { };
    }
    setCommandList({
      startCommandLabel,
      disableStart,
      startCommand,
      stopCommandLabel,
      disableStop,
      stopCommand,

      option1Label,
      disableOption1,
      option1Command,

      option2Label,
      disableOption2,
      option2Command,
    });
  }

  useEffect(() => {
    async function asyncSetup() {
      try {
        const resp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", STATE_OE);
        if (resp.latest !== undefined && resp.latest !== null) {
          updateState(resp.latest.value as string);
        }
        const unlistenJs = await listen<ObjectEntryEvent>(resp.event_name, event => {
          updateState(event.payload.value as string);
        });
        return () => {
          invoke("unlisten_from_latest_object_entry_value", STATE_OE).catch(console.error);
          unlistenJs();
        }
      } catch (e) {
        console.error(`Failed to register listeners for CustomAppBar component: Object entry ${STATE_OE.nodeName}:${STATE_OE.objectEntryName} not found`);
        return () => {
        }
      }
    }

    const asyncCleanup = asyncSetup();

    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    }
  }, []);

  useEffect(() => {
    const keyDownHandler = (event: { key: string; preventDefault: () => void; }) => {
      if (event.key === ' ') {
        event.preventDefault();
        sendEmergencyCommand();
      } else if (event.key === "F1") {
        event.preventDefault()
        if (commandList !== undefined && !commandList.disableStart) {
          commandList.startCommand();
        }
      } else if (event.key === "F2") {
        event.preventDefault()
        if (commandList !== undefined && !commandList.disableStop) {
          commandList.stopCommand();
        }
      }
    };
    document.addEventListener('keydown', keyDownHandler);
    return () => {
      document.removeEventListener('keydown', keyDownHandler);
    };
  }, [commandList]);

  return (
    <AppBar
      position="absolute"
      open={open}
      sx={{
        backgroundColor: theme.palette.background.appBar,
        boxShadow: "none"
      }}

    >
      <Toolbar
        sx={{
          pr: '24px', // keep right padding when drawer closed
          height: "75px",
          boxShadow: "none",
        }}
      >
        {open ? <></> :
          <IconButton
            edge="start"
            aria-label="open drawer"
            onClick={toggleOpen}
            sx={{
              marginRight: '100px',
              backgroundColor: theme.palette.background.drawer,
              '&:hover': {
                backgroundColor: theme.palette.background.paper,
              }
            }}
          >
            <MenuIcon />
          </IconButton>
        }
        <Stack
          direction="row"
          sx={{
            width: "100%",
            margin: 0,
            padding: 0,
          }}
          justifyContent="space-between"
          alignItems="center"
        >
          <Stack
            direction="row"
            justifyContent="flex-end"
            alignItems="center"
            spacing={2}
          >
            <StateDisplay state={state} />
            {/* Buttons */}
            <AppBarButton variant="contained" width="18em" 
                color="cmdAbort" onClick={sendEmergencyCommand} >
              <p>Emergency <br />[Space bar]</p>
            </AppBarButton>

            <AppBarButton color="cmdStart" disabled={commandList.disableStart} onClick={commandList.startCommand} >
              {commandList.startCommandLabel}
            </AppBarButton>

            <AppBarButton color="cmdStop" disabled={commandList.disableStop} onClick={commandList?.stopCommand} >
              {commandList.stopCommandLabel}
            </AppBarButton>

            <AppBarButton color="cmdExtra" disabled={commandList.disableOption1} onClick={commandList?.option1Command} >
              <p>{commandList.option1Label}</p>
            </AppBarButton>

            <AppBarButton color="cmdExtra" disabled={commandList.disableOption2} onClick={commandList?.option2Command} >
              <p>{commandList.option2Label}</p>
            </AppBarButton>

          </Stack>
          <Stack
            direction="row"
            justifyContent="flex-end"
            alignItems="center"
            spacing={2}
            sx={{
              position: "relative",
              top: "0.2em",
              marginRight: "1rem",
            }}
          >
            <WarningIconDisplay />
            <BatteryIconDisplay />
            <TemperatureIconDisplay />
            <ElectricIconDisplay />
          </Stack>
        </Stack>
      </Toolbar>
      <StateIndicatorBar state={state} />
    </AppBar>)
}

export default CustomAppBar;


