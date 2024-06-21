

import { IconButton, SxProps, Theme } from "@mui/material";
import BlurOnIcon from '@mui/icons-material/BlurOn';
import BlurOffIcon from '@mui/icons-material/BlurOff';

interface GraphBufferingButton {
  sx?: SxProps<Theme>
  buffer: boolean
  onClick: () => void,
}

function GraphBufferingButton({ sx, buffer, onClick }: Readonly<GraphBufferingButton>) {
  if (buffer) {
    return <IconButton
      size="small"
      onClick={onClick}
      sx={sx}
    >
      <BlurOnIcon fontSize="small" />
    </IconButton>
  } else {
    return <IconButton
      size="small"
      onClick={onClick}
      sx={sx}
    >
      <BlurOffIcon fontSize="small" />
    </IconButton>
  }

}

export default GraphBufferingButton;
