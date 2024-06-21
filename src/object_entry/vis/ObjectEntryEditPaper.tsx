import { Input, Paper, Stack, Typography } from "@mui/material";
import React, { useRef, useState } from "react";



interface ObjectEntryPropertyInputFieldProps {
  nodeName: string,
  objectEntryName: string,
}

function ObjectEntryPropertyInputField({ }: Readonly<ObjectEntryPropertyInputFieldProps>) {

  const unit = "°C";

  const [input, setInput] = useState(unit);
  const inputElement = useRef();

  return (
    <Input disableUnderline sx={{
      boxShadow: "none",
    }} inputProps={{ style: { boxShadow: "none" } }} value={input} ref={inputElement}
      onInputCapture={(e: React.ChangeEvent<HTMLInputElement>) => {
        let v;
        if (!e.target.value.endsWith(unit)) {
          v = unit;
        } else {
          v = e.target.value;
        }
        e.target.setSelectionRange(v.length - unit.length, v.length - unit.length);
        setInput(v);
      }}
      onFocus={e => {
        setTimeout(() => {
          e.target.setSelectionRange(e.target.value.length - unit.length, e.target.value.length - unit.length);
        }, 0);
      }}
      // onKeyDown={(e: React.KeyboardEvent<HTMLInputElement>) => {
      //   setTimeout(() => {
      //     if (e.target.selectionStart > e.target.value.length - unit.length) {
      //       e.target.setSelectionRange((e.target as any).value.length - unit.length, (e.target as any).value.length - unit.length);
      //     }
      //   }, 0);
      // }}
      // onClick={(e: React.MouseEvent<HTMLInputElement>) => {
      //   if (e.target.selectionStart > e.target.value.length - unit.length) {
      //     e.target.setSelectionRange((e.target as any).value.length - unit.length, (e.target as any).value.length - unit.length);
      //   }
      // }}
    >
    </Input>
  );
}

interface ObjectEntryEditPaperProps {
  nodeName: string,
  objectEntryName: string
  title?: string
}


function ObjectEntryEditPaper({ nodeName, objectEntryName, title }: Readonly<ObjectEntryEditPaperProps>) {

  return (
    <Paper sx={{
      paddingLeft: 1,
      paddingTop: 0.5,
      paddingBottom: 0.5,
      paddingRight: 0.5
    }}>
      <Stack direction="column" spacing={0}>
        {title ?
          <Typography variant="caption" color="grey">
            {`${title}:`}
          </Typography> : <></>
        }
        <ObjectEntryPropertyInputField nodeName={nodeName} objectEntryName={objectEntryName} />
      </Stack>
    </Paper>
  );

}

export default ObjectEntryEditPaper;

