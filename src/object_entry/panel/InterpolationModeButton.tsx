

import { IconButton, SxProps, Theme } from "@mui/material";
import TimelineIcon from '@mui/icons-material/Timeline';
import { GraphInterpolation } from "../../graph/GraphInterpolation";
import SignalCellularAltIcon from '@mui/icons-material/SignalCellularAlt';
import InsightsIcon from '@mui/icons-material/Insights';

interface InterpolationModeButtonProps {
  sx?: SxProps<Theme>
  onClick: () => void,
  mode : GraphInterpolation,
}

function InterpolationModeButton({ sx, onClick, mode}: Readonly<InterpolationModeButtonProps>) {
  let icon;
  switch (mode) {
    case GraphInterpolation.Step:
      icon = <SignalCellularAltIcon fontSize="small" />
      break;
    case GraphInterpolation.Linear:
      icon = <TimelineIcon fontSize="small" />
      break;
    default:
      icon = <InsightsIcon fontSize="small" />
      break;
  }

  return <IconButton
    size="small"
    onClick={onClick}
    sx={sx}
  >
    {icon}
  </IconButton>
}

export default InterpolationModeButton
