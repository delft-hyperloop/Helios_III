import {ObjectEntryGridInformation} from "./types/ObjectEntryGridInformation.tsx";
import ObjectEntryField from "./ObjectEntryField.tsx";
import { Box } from "@mui/material";

interface ObjectEntryGridProps {
    entries: ObjectEntryGridInformation[];
    width: number;
}

function ObjectEntryGrid({entries, width}: Readonly<ObjectEntryGridProps>) {
    return (
        <Box
            component="form"
            sx={{
                '& > :not(style)': { m: 0.7, width: width },
            }}
            noValidate
            autoComplete="off"
        >
            {
                entries.map((entry) => <ObjectEntryField
                    key={`${entry.node.name}/${entry.entry}`}
                    node={entry.node}
                    entry={entry.entry}
                    interpolate={entry.interpolate}
                    min={entry.min}
                    max={entry.max}
                    warning={entry.warning}
                    ok={entry.ok}
                    tooGood={entry.tooGood}
                />)
            }
        </Box>
    );
}

export default ObjectEntryGrid
