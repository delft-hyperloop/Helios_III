import {TableCell, TableRow, styled, Typography} from "@mui/material";
import { TraceEvent } from "./types/TraceEvent";

const StyledTableRow = styled(TableRow)(({theme}) => ({
  backgroundColor: theme.palette.background.warn,
  // hide last border
}));


interface UndefinedRowProps {
  event: TraceEvent,
  useAbsoluteTime: boolean,
}

function UndefinedRow({ useAbsoluteTime, event }: Readonly<UndefinedRowProps>) {
  return (<StyledTableRow>
      <TableCell sx={{ padding: 0, textAlign: "center", lineHeight: "100%" }}>
      </TableCell>
      <TableCell>
          <Typography style={{ opacity: event.timeSinceLast > 5000 ? "20%" : "100%" }} variant="body2">
              {useAbsoluteTime ? `${event.absoluteTime}s` : `${event.deltaTime}ms`}
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
    </StyledTableRow>);

}
export default UndefinedRow;
