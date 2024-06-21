import { SxProps, Table, TableBody, TableCell, TableContainer, TableHead, TableRow, Theme, useTheme } from "@mui/material";
import { ReactElement } from "react";

interface ObjectEntryListProps {
  children: ReactElement[] | ReactElement,
  sx?: SxProps<Theme>,
  label?: string,
}


function ObjectEntryListProps({ children, sx, label }: Readonly<ObjectEntryListProps>) {
  const theme = useTheme();
  return (
    <div className="ControlTable">
      <TableContainer component="div">
        <Table sx={sx} aria-label="number-list-table">
          {label ?
            <TableHead>
              <TableRow>
                <TableCell 
                  align="center" 
                  sx={{ width: "100%", backgroundColor: theme.palette.background.appBar}} 
                  colSpan={2}>
                  {label}
                </TableCell>
              </TableRow>
            </TableHead>
            : <></>}
          <TableBody>
            {children}
          </TableBody>
        </Table>
      </TableContainer>
    </div>
  );
}

export default ObjectEntryListProps;
