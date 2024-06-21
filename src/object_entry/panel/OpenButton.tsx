
import {IconButton, SxProps, Theme} from "@mui/material";
import LaunchIcon from '@mui/icons-material/Launch';
import { invoke } from "@tauri-apps/api";

interface OpenButtonProps {
    nodeName: string,
    objectEntryName: string,
    sx? : SxProps<Theme>
}

function OpenButton({sx, nodeName, objectEntryName}: Readonly<OpenButtonProps>) {

    return <IconButton
        size="small"
        onClick={() => invoke("open_floating_object_entry_window", {nodeName, objectEntryName}).catch(console.error)}
        sx={sx}
        >
        <LaunchIcon fontSize="small"/>
    </IconButton>
}

export default OpenButton
