import { useEffect, useState } from "react";
import { ObjectEntryInformation } from "../object_entry/types/ObjectEntryInformation";
import { invoke } from "@tauri-apps/api";
import { Value } from "../object_entry/types/Value";
import { TableCell, Typography } from "@mui/material";


interface ObjectEntryValueCellProps {
  nodeName: string,
  objectEntryName: string,
  value : Value | undefined,
}

function ObjectEntryValueCell({ nodeName, objectEntryName , value}: ObjectEntryValueCellProps) {
  const [info, setInfo] = useState<ObjectEntryInformation | undefined>(undefined);

  useEffect(() => {
    async function fetchInfo() {
      const info = await invoke<ObjectEntryInformation>("object_entry_information", { nodeName, objectEntryName });
      setInfo(info);
    }
    fetchInfo().catch(console.error);
  }, [nodeName, objectEntryName]);

  const unit = info?.unit ?? "";

  return (
    <TableCell sx={{
      width: "100%",
    }}>
      <Typography style={{
        textAlign : "right"
      }} variant="body2">
      {value != undefined ? `${value} ${unit}` : "-"}
      </Typography>
    </TableCell>
  );

}

export default ObjectEntryValueCell;
