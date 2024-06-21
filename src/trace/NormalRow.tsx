
import {Collapse, IconButton, Table, TableBody, TableCell, TableRow, styled, useTheme, Typography} from "@mui/material";
import { TraceEvent, TraceFrameAttribute } from "./types/TraceEvent";

import KeyboardArrowDownIcon from '@mui/icons-material/KeyboardArrowDown';
import KeyboardArrowRightIcon from '@mui/icons-material/KeyboardArrowRight';
import React from "react";


const StyledTableRow = styled(TableRow)(({theme}) => ({
  backgroundColor: theme.palette.background.paper
  // hide last border
}));


interface UndefinedRowProps {
  open: { [key: number]: boolean },
  setOpen: React.Dispatch<React.SetStateAction<{ [key: number]: boolean }>>
  event: TraceEvent,
  useAbsoluteTime: boolean,
}

function NormalRow({ useAbsoluteTime, open, setOpen, event }: Readonly<UndefinedRowProps>) {
  let attributes = event.frame.detail as TraceFrameAttribute[];

  const theme = useTheme();
  return (<>
    <StyledTableRow>
      <TableCell sx={{ padding: 0, textAlign: "center", lineHeight: "100%" }}>
        {attributes ?
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
          : undefined
        }
      </TableCell>
      <TableCell>
        <Typography style={{ opacity: event.timeSinceLast > 5000 ? "20%" : "100%" }} variant="body2">
          {useAbsoluteTime ? `${event.absoluteTime}` : `${event.deltaTime}`}
        </Typography>
      </TableCell>
      <TableCell>
        <Typography style={{ opacity: event.timeSinceLast > 5000 ? "20%" : "100%" }} variant="body2">
          {event.frame.id}
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
    {attributes ?
      <TableRow sx={{ backgroundColor: theme.palette.background.paper2, padding: 0, margin: 0 }}>
        <TableCell style={{ padding: 0 }} colSpan={6}>
          <Collapse in={open[event.key]} timeout="auto" unmountOnExit sx={{ margin: 0, padding: 0 }}>
            <Table
              size="small"
              aria-label="purchases"
              sx={{
                margin: 1,
                padding: 0,
                maxWidth: "500px",
                backgroundColor: theme.palette.background.paper
              }}
            >
              <TableBody sx={{ maxWidth: "500px" }}>
                {attributes.map(attrib => {
                  return <TableRow sx={{ maxWidth: "500px" }} key={attrib.name}>
                    <TableCell align="right" sx={{ width: "200px", textAlign: "left" }}>
                      {attrib.name}
                    </TableCell>
                    <TableCell align="left" sx={{ width: "200px", textAlign: "right" }}>
                      {attrib.value}
                    </TableCell>
                  </TableRow>
                })}
              </TableBody>
            </Table>
          </Collapse>
        </TableCell>

      </TableRow>
      : undefined
    }
  </>);
}
export default NormalRow;
