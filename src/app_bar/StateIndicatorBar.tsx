import { PaletteColor, Skeleton, useTheme } from "@mui/material";


interface StateIndicatorBarProps {
  state?: string,
  voffset?: number | string
}

function StateIndicatorBar({ state, voffset = "0px" }: Readonly<StateIndicatorBarProps>) {
  const theme = useTheme();
  let color: PaletteColor;
  switch (state) {
    case "COM_DISCONNECTED":
      color = theme.palette.disconnected;
      break;
    case "INIT":
      color = theme.palette.stateInit;
      break;
    case "IDLE":
      color = theme.palette.stateIdle;
      break;
    case "ARMING45":
      color = theme.palette.stateArming45;
      break;
    case "PRECHARGE":
      color = theme.palette.statePrecharge;
      break;
    case "DISARMING45":
      color = theme.palette.stateDisarming45;
      break;
    case "READY":
      color = theme.palette.stateReady;
      break;
    case "START_LEVITATION":
      color = theme.palette.stateStartLevitation;
      break;
    case "LEVITATION_STABLE":
      color = theme.palette.stateLevitation;
      break;
    case "START_GUIDANCE":
      color = theme.palette.stateStartGuidance;
      break;
    case "GUIDANCE_STABLE":
      color = theme.palette.stateGuidance;
      break;
    case "ACCELERATION":
      color = theme.palette.stateAccelerate;
      break;
    case "CONTROLLER":
      color = theme.palette.stateController;
      break;
    case "CRUISING":
      color = theme.palette.stateCruising;
      break;
    case "DECELERATE":
      color = theme.palette.stateDeceleration;
      break;
    case "STOP_LEVITATION":
      color = theme.palette.stateStopLevitation;
      break;
    case "STOP_GUIDANCE":
      color = theme.palette.stateStopGuidance;
      break;
    case "SHUTDOWN":
      color = theme.palette.stateShutdown;
      break;
    case "RESTARTING":
      color = theme.palette.stateRestarting;
      break;
    case "CALIBRATING":
      color = theme.palette.stateCalibrating;
      break;
    default:
      color = theme.palette.disconnected;
      break;
  }
  return (
    <Skeleton
      animation="pulse"
      variant="rectangular"
      sx={{
        position: "relative",
        top: voffset,
        padding: 0,
        margin: 0,
        borderRadius: 0,
        width: "100%",
        height: "6px",
        bgcolor: color.main
      }}
    />
  );
}

export default StateIndicatorBar;
