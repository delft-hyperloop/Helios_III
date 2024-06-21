import { IconButton, SxProps, Theme } from "@mui/material";
import TimelineIcon from '@mui/icons-material/Timeline';
import { useNavigate } from "react-router-dom";


interface ObjectEntryButtonLinkProps {
  nodeName: string,
  objectEntryName: string,
  sx?: SxProps<Theme>,
  disabled?: boolean,
}




function ObjectEntryButtonLink({ disabled, nodeName, objectEntryName, sx }: Readonly<ObjectEntryButtonLinkProps>) {
  const nav = useNavigate();

  return (
    <IconButton 
      disabled={disabled}
      size="small"
      onClick={()=>nav(`/${nodeName}/${objectEntryName}`)}
      sx={sx}>
      <TimelineIcon fontSize="small" />
    </IconButton>
  )
}


export default ObjectEntryButtonLink;
