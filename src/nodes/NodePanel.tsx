import {
    Box,
    InputAdornment,
    Paper,
    Skeleton,
    Stack,
    styled,
    Table,
    TableBody,
    TableContainer,
    TableHead,
    TableRow,
    TextField,
    Typography,
    useTheme
} from "@mui/material";
import {NodeInformation} from "./types/NodeInformation.ts";
import React, {useEffect, useRef, useState} from "react";
import {ObjectEntryEvent} from "../object_entry/types/events/ObjectEntryEvent.tsx";
import {invoke} from "@tauri-apps/api";
import {listen} from "@tauri-apps/api/event";
import {NodeEvent} from "./types/NodeEvent.ts";
import ObjectEntryRow from "./ObjectEntryRow.tsx";
import {TableComponents, TableVirtuoso} from "react-virtuoso";
import SearchIcon from '@mui/icons-material/Search';
import useFocusOnCtrlShortcut from "../trace/FocusOnKey.tsx";
import HeartbeatStatus from "./HeartbeatStatus.tsx";


interface NodePanelProps {
    node: NodeInformation
}

interface RowData {
    objectEntryName: string,
    value: ObjectEntryEvent | null,
}


const StyledTableRow = styled(TableRow)(({theme}) => ({
    backgroundColor: theme.palette.background.paper2,
    // hide last border
}));

const VirtuosoTableComponents: TableComponents<RowData> = {
    Scroller: React.forwardRef<HTMLDivElement>((props, ref) => (
        <TableContainer component={Paper} {...props} ref={ref}/>
    )),
    Table: (props) => (
        <Table {...props} size="small" sx={{borderCollapse: 'separate', tableLayout: 'fixed'}}/>
    ),
    TableHead: TableHead as any,
    TableRow: ({item: _item, ...props}) => <StyledTableRow {...props} />,
    TableBody: React.forwardRef<HTMLTableSectionElement>((props, ref) => (
        <TableBody {...props} ref={ref}/>
    )),
};


function NodePanel({node}: Readonly<NodePanelProps>) {

    const [rowData, setRowData] = useState<(RowData)[]>([]);
    const [currNodeName, setCurrNodeName] = useState<string>(node.name);
    const [filter, setFilter] = useState<number[]>(node.object_entries.map((_, i) => i));
    const [searchString, setSearchString] = useState<string>("");


    // register listener
    useEffect(() => {
        async function asyncSetup() {
            const storedSearchString = await invoke<string | null>("get_stored_search_string", {page: node.name});
            if (storedSearchString !== null) {
                setSearchString(storedSearchString)
                updateFilter(storedSearchString)
            }
            const event_name = await invoke<string>("listen_to_node_latest", {nodeName: node.name});
            const unlistenJs = await listen<NodeEvent>(event_name, event => {
                const rowData = event.payload.object_entry_values.map((value, index) => {
                    return {
                        objectEntryName: node.object_entries[index],
                        value,
                    };
                });
                setRowData(rowData);
            });

            return () => {
                unlistenJs();
                invoke("unlisten_from_node_latest", {nodeName: node.name}).catch(console.error);
            };
        }

        // init!
        setRowData([]);
        setCurrNodeName(node.name)
        setFilter(node.object_entries.map((_, i) => i));
        setSearchString("");
        let asyncCleanup = asyncSetup();
        return () => {
            asyncCleanup.then(f => f()).catch(console.error);
        };
    }, [node.name]);

    function rowContent(_index: number, row: RowData) {
        return <ObjectEntryRow nodeName={currNodeName} objectEntryName={row?.objectEntryName} value={row.value?.value}/>
    }

    const searchFieldRef = useRef() as any;

    useFocusOnCtrlShortcut("f", searchFieldRef)

    function updateFilter(filter_string: string) {
        const filter = [];
        for (let oe_index = 0; oe_index < node.object_entries.length; oe_index++) {
            if (node.object_entries[oe_index].includes(filter_string)) {
                filter.push(oe_index);
            }
        }
        setFilter(filter);
    }

    const theme = useTheme();

    return (
        <Paper sx={{
            marginTop: "16px",
            marginLeft: "8px",
            marginRight: "10px",
            paddingLeft: "12px",
            paddingRight: "12px",
            width: "calc(100% - 16px)",
            height: "calc(102vh - 120px)",
            paddingTop: "60px",
            paddingBottom: "8px",
            position: "relative"
        }}>
            <Stack direction={"row"} sx={{
                position: "absolute",
                top: "2px",
                left: "12px",
                padding: "1px",
            }} spacing={2} alignItems={"center"}>
                <Typography variant="h5">{node.name}</Typography>
                {
                    node.buses.map(bus => (
                        <Box position={"relative"} top={"-0.10em"} key={bus}>
                            <HeartbeatStatus nodeName={node.name} busName={bus}>
                            </HeartbeatStatus>
                        </Box>
                    ))
                }
            </Stack>

            {node.description ? <Typography sx={{
                    position: "absolute",
                    top: "32px",
                    left: "20px",
                    padding: "1px",

                }} variant="subtitle2">{node.description}</Typography>
                : <></>}

            <TextField
                inputRef={searchFieldRef}
                value={searchString}
                sx={{
                    position: "absolute",
                    top: "10px",
                    right: "20px",
                    width: "50%",
                    maxWidth: "400px",
                }}
                variant="standard"
                inputProps={{
                    style: {
                        boxShadow: "none"
                    }
                }}
                onChange={event => {
                    setSearchString(event.target.value);
                    updateFilter(event.target.value);
                    invoke("store_search_string", {page: node.name, string: event.target.value}).catch(console.error)
                }}
                InputProps={{
                    startAdornment: <InputAdornment position="start"><SearchIcon fontSize="small"/></InputAdornment>,
                }}
            >
            </TextField>
            {(rowData.length == 0 || currNodeName !== node.name) ? <Skeleton

                    variant="rounded"
                    animation="wave"
                    sx={{
                        padding: 0,
                        margin: 0,
                        height: "100%",
                    }}
                />
                :
                <TableVirtuoso
                    style={{
                        height: "100%",
                        width: "100%",
                        backgroundColor: theme.palette.background.paper2,
                    }}
                    data={filter.map(i => rowData[i])}
                    components={VirtuosoTableComponents}
                    itemContent={rowContent}
                >
                </TableVirtuoso>
            }
        </Paper>
    );
}

export default NodePanel
