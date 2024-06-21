import { Stack, TableCell, TableRow, Typography } from "@mui/material";
import { Value } from "../object_entry/types/Value";
import ObjectEntryValueCell from "./ObjectEntryValueCell";
import SetValueButton from "../object_entry/panel/SetValueButton";
import RefreshButton from "../object_entry/panel/RefreshButton";
import ObjectEntryButtonLink from "../object_entry/links/ObjectEntryButtonLink";
import { useEffect, useState } from "react";
import { ObjectEntryInformation } from "../object_entry/types/ObjectEntryInformation";
import { invoke } from "@tauri-apps/api";
import OpenButton from "../object_entry/panel/OpenButton";


interface ObjectEntryRowProps {
  nodeName: string,
  objectEntryName: string,
  value: Value | undefined,
}


interface ObjectEntryAttribRowProps {
  name: string,
  value: Value,
}

function ObjectEntryAttribRow({ name, value }: Readonly<ObjectEntryAttribRowProps>) {
  if (typeof value === "object") {
    return Object.entries(value).map(([attrib_name, attrib_value]) => {
      return <ObjectEntryAttribRow name={`${name}.${attrib_name}`} value={attrib_value} key={`${name}.${attrib_name}`} />
    });
  } else {
    return (
      <TableRow>
        <TableCell sx={{
          minWidth: "20vw",
          maxWidth: "20vw",
          overflow: "clip",
        }}>

          <Typography variant="body2" sx={{ marginLeft: "5px" }}>
            {`• ${name}`}
          </Typography>
        </TableCell>
        <TableCell sx={{
          width: "100%",
        }}>
          {value}
        </TableCell>
        <TableCell sx={{ width: "20px" }} />
      </TableRow>
    );
  }
}

function ObjectEntryRow({ nodeName, objectEntryName, value }: Readonly<ObjectEntryRowProps>) {
  const [info, setInfo] = useState<ObjectEntryInformation>();

  useEffect(() => {
    invoke<ObjectEntryInformation>("object_entry_information", { nodeName, objectEntryName })
      .then(setInfo).catch(console.error);
    return () =>{
      setInfo(undefined);
    }
  }, [nodeName, objectEntryName]);

  if (typeof value === "object") {
    return (<>
      <TableRow >
        <TableCell sx={{
          minWidth: "25vw",
          maxWidth: "25vw",
          overflow: "clip",
          minHeight:  "100px",
          maxHeight:  "100px",
          heigt:  "100px",
        }}>
          {objectEntryName}
        </TableCell>
        <TableCell
          sx={{
            width: "100%",
          }}
        >
          {value == undefined ? "-" : ""}
        </TableCell>
        <TableCell
          sx={{
            width: "20px",
          }}
        >
          <Stack direction="row" spacing={1}>
            <SetValueButton nodeName={nodeName} objectEntryName={objectEntryName} />
            <RefreshButton nodeName={nodeName} objectEntryName={objectEntryName} />
            <ObjectEntryButtonLink nodeName={nodeName} objectEntryName={objectEntryName} disabled={info == undefined ? true : !info.plottable} />
            <OpenButton nodeName={nodeName} objectEntryName={objectEntryName} />
          </Stack>
        </TableCell>
      </TableRow >
      {value == undefined ? <></> :
        Object.entries(value).map(([attrib_name, attrib_value]) => {
          return <ObjectEntryAttribRow name={attrib_name} value={attrib_value} key={`${attrib_name}`} />;
        })
      }
    </>);
  } else {
    return (
      <TableRow>
        <TableCell
          sx={{
            minWidth: "25vw",
            maxWidth: "25vw",
            overflow: "clip",
          }}
        >
          {objectEntryName}
        </TableCell>
        <ObjectEntryValueCell
          nodeName={nodeName}
          objectEntryName={objectEntryName}
          value={value}
        />
        <TableCell
          sx={{
            width: "20px",
          }}
        >
          <Stack direction="row" spacing={1}>
            <SetValueButton nodeName={nodeName} objectEntryName={objectEntryName} />
            <RefreshButton nodeName={nodeName} objectEntryName={objectEntryName} />
            <ObjectEntryButtonLink nodeName={nodeName} objectEntryName={objectEntryName} disabled={info == undefined ? true : !info.plottable} />
            <OpenButton nodeName={nodeName} objectEntryName={objectEntryName} />
          </Stack>
        </TableCell>
      </TableRow>);
  }



}

export default ObjectEntryRow;
