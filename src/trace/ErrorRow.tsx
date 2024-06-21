import { Box, Collapse, IconButton, TableCell, TableRow, Typography, styled } from "@mui/material";
import { TraceEvent } from "./types/TraceEvent";

import KeyboardArrowDownIcon from '@mui/icons-material/KeyboardArrowDown';
import KeyboardArrowRightIcon from '@mui/icons-material/KeyboardArrowRight';
import React from "react";


const StyledTableRow = styled(TableRow)(() => ({
  backgroundColor: "#f2d5d5",
  // hide last border
}));


interface ErrorRowProps {
  open: { [key: number]: boolean },
  setOpen: React.Dispatch<React.SetStateAction<{ [key: number]: boolean }>>
  event: TraceEvent,
  useAbsoluteTime: boolean,
}

function ErrorRow({ useAbsoluteTime, open, setOpen, event }: Readonly<ErrorRowProps>) {
  let description = event.frame.detail as string;
  return (<>
    <StyledTableRow>
      <TableCell sx={{ padding: 0, textAlign: "center", lineHeight: "100%" }}>
        <IconButton
          sx={{
            padding: "2px",
            margin: 0,
            boxShadow: "none",
            borderRadius: "10px",
            borderWidth: 0
          }}
          onClick={() => {
            setOpen((prev: { [key: number]: boolean }) => {
              let x = { ...prev };
              x[event.key] = !x[event.key];
              return x;
            });
          }}
        >
          {open[event.key]
            ? <KeyboardArrowDownIcon style={{ fontSize: "20px", padding: 0, margin: 0 }} />
            : <KeyboardArrowRightIcon style={{ fontSize: "20px", padding: 0, margin: 0 }} />
          }
        </IconButton>
      </TableCell>
      <TableCell>
        <Typography style={{ opacity: event.timeSinceLast > 5000 ? "20%" : "100%" }} variant="body2">
          {useAbsoluteTime ? `${event.absoluteTime}s` : `${event.deltaTime}ms`}
        </Typography>
      </TableCell>
      <TableCell>
        <Typography style={{ opacity: event.timeSinceLast > 5000 ? "20%" : "100%" }} variant="body2">
          -
        </Typography>
      </TableCell>
      <TableCell>
        <Typography style={{ opacity: event.timeSinceLast > 5000 ? "20%" : "100%" }} variant="body2">
          {event.frame.name}
        </Typography>
      </TableCell>
      <TableCell>
        <Typography style={{ opacity: event.timeSinceLast > 5000 ? "20%" : "100%" }} variant="body2">
          {event.bus}
        </Typography>
      </TableCell>
      <TableCell>
        <Typography style={{ opacity: event.timeSinceLast > 5000 ? "20%" : "100%" }} variant="body2">
          {event.frame.dlc}
        </Typography>
      </TableCell>
    </StyledTableRow>
    <TableRow sx={{ backgroundColor: "#f2e6e6", padding: 0, margin: 0 }}>
      <TableCell style={{ padding: 0 }} colSpan={6}>
        <Collapse in={open[event.key]} timeout="auto" unmountOnExit sx={{ margin: 0, padding: 0 }}>
          <Box component="div" sx={{
            marginLeft: 1,
            marginTop: 0.5,
            marginRight: 1,
            marginBottom: 0.5,
          }}>
            <Typography variant="body2">
              {description}
            </Typography>
          </Box>
        </Collapse>
      </TableCell>

    </TableRow></>);
}
export default ErrorRow;
