import { IconButton, SxProps, Theme } from "@mui/material";
import EditIcon from '@mui/icons-material/Edit';
import { useEffect, useState } from "react";
import { ObjectEntryInformation } from "../types/ObjectEntryInformation";
import EditDialog from "../edit_dialog/EditDialog";
import { invoke } from "@tauri-apps/api";

interface SetValueButtonProps {
  nodeName: string,
  objectEntryInfo?: ObjectEntryInformation,
  objectEntryName?: string,
  sx?: SxProps<Theme>,
}

function SetValueButton({ nodeName, objectEntryInfo, objectEntryName, sx }: Readonly<SetValueButtonProps>) {
  const [showDialog, setShowDialog] = useState(false);

  const [objectEntryInformation, setObjectEntryInformation]
    = useState<ObjectEntryInformation | undefined>(objectEntryInfo);

  useEffect(() => {
    if (objectEntryInfo?.name != objectEntryName) {
      async function fetchInfo() {
        const info = await invoke<ObjectEntryInformation>(
          "object_entry_information",
          { nodeName, objectEntryName: objectEntryName ?? objectEntryInfo?.name });
        setObjectEntryInformation(info);
      }
      fetchInfo().catch(console.error);
    }
  }, [objectEntryInfo, objectEntryName]);


  return (
    <>
      <IconButton
        size="small"
        onClick={() => setShowDialog(true)}
        sx={sx}
      >
        <EditIcon fontSize="small" />
      </IconButton>
      {(showDialog && objectEntryInformation) ? <EditDialog
        open={showDialog}
        onClose={() => setShowDialog(false)}
        nodeName={nodeName}
        objectEntryInfo={objectEntryInformation}
      /> : undefined}
    </>
  );

}

export default SetValueButton
