import Table from '@mui/material/Table';
import TableBody from '@mui/material/TableBody';
import TableCell from '@mui/material/TableCell';
import TableContainer from '@mui/material/TableContainer';
import TableHead from '@mui/material/TableHead';
import TableRow from '@mui/material/TableRow';
import Paper from '@mui/material/Paper';
import '../styles.css'
import CustomTableCell from "./CustomTableCell.tsx";
import {ValueTableCellInformation} from "./types/ValueTableCellInformation.tsx";
import {Skeleton} from "@mui/material";

interface ValueTableProps {
    entries: ValueTableCellInformation[];
    title: string;
    width: number;
    height: number;
    rows: number;
    columns: number
}

// Only for numerical ObjectEntries
// number of entries must equal rows * columns
export default function ValueTable({entries, title, width, height, rows, columns}: Readonly<ValueTableProps>) {
    return (
        <div className="ControlTable">
            <TableContainer component={Paper}>
                <Table sx={{width: {width}, height: height}} aria-label="simple table">
                    <TableHead>
                        <TableRow>
                            <TableCell align="center" colSpan={columns}>
                                {title}
                            </TableCell>
                        </TableRow>
                    </TableHead>
                    {(entries.length !== 0) ? <TableBody>
                            {Array.from(Array(rows).keys()).map((row, index) => (
                                <TableRow key={index}>
                                    {Array.from(Array(columns).keys()).map((col) => (
                                        <CustomTableCell key={entries[columns * row + col].entry} node={entries[columns * row + col].node}
                                                         name={entries[columns * row + col].entry}
                                                         min={entries[columns * row + col].min}
                                                         max={entries[columns * row + col].max}/>
                                    ))}
                                </TableRow>
                            ))}
                        </TableBody>
                        : <Skeleton variant="rounded"/>}
                </Table>
            </TableContainer>
        </div>
    );
}
