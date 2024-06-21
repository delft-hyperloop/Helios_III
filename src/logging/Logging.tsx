import {NodeInformation} from "../nodes/types/NodeInformation.ts";
import {
    Backdrop,
    Checkbox, CircularProgress,
    IconButton,
    InputAdornment,
    Paper,
    Skeleton,
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
import {TableComponents, TableVirtuoso} from "react-virtuoso";
import React, {useEffect, useRef, useState} from "react";
import {invoke} from "@tauri-apps/api";
import useFocusOnCtrlShortcut from "../trace/FocusOnKey.tsx";
import SearchIcon from "@mui/icons-material/Search";
import LoggingRow from "./LoggingRow.tsx";
import SaveIcon from "@mui/icons-material/Save";

interface ExportPanelProps {
    nodes: NodeInformation[]
}

interface RowData {
    nodeName: string,
    objectEntryName: string,
}

interface TopBarProps {
    nodes: NodeInformation[],
    filter: number[],
    rowData: RowData[],
    selected: [string, string][],
    setSelected: (selected: [string, string][]) => void,
    searchString: string,
    setSearchString: (str: string) => void,
    updateFilter: (str: string) => void,
    setLoading: (value: boolean) => void
}

function TopBar({
                    nodes,
                    filter,
                    rowData,
                    selected,
                    setSelected,
                    searchString,
                    setSearchString,
                    updateFilter,
                    setLoading
                }: Readonly<TopBarProps>) {
    const theme = useTheme();
    const searchFieldRef = useRef() as any;

    useFocusOnCtrlShortcut("f", searchFieldRef)

    const handleSelectAllClick = (event: React.ChangeEvent<HTMLInputElement>) => {
        if (event.target.checked) {
            setSelected(filter.map(i => [rowData[i].nodeName, rowData[i].objectEntryName]));
            return;
        }
        setSelected([]);
    };

    function selectAll() {
        const newSelected: [string, string][] = []
        for (let node of nodes) {
            for (let oe of node.object_entries) {
                newSelected.push([node.name, oe])
            }
        }
        setSelected(newSelected);
    }

    return (
        <>
            <Checkbox
                color="primary"
                sx={{
                    position: "absolute",
                    top: "5px",
                    left: "20px",
                    maxWidth: "400px",
                }}
                defaultChecked
                onChange={handleSelectAllClick}
            />
            <Typography sx={{
                position: "absolute",
                top: "15px",
                left: "60px",
                maxWidth: "400px",
            }}>
                Select all
            </Typography>
            <IconButton color="primary"
                        sx={{
                            position: "absolute",
                            top: "1px",
                            right: "435px",
                            backgroundColor: theme.palette.background.paper2
                        }}
                        onClick={() => {
                            setLoading(true)
                             invoke("export", {
                                nodes: selected.map((value: [string, string]) => value[0]),
                                oes: selected.map((value: [string, string]) => value[1])
                            }).then(() => setLoading(false));
                        }}
            >
                <SaveIcon/>
            </IconButton>
            <TextField
                inputRef={searchFieldRef}
                value={searchString}
                sx={{
                    position: "absolute",
                    top: "5px",
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
                onAnimationStart={() => selectAll()}
                onChange={event => {
                    setSearchString(event.target.value);
                    updateFilter(event.target.value);
                    invoke("store_search_string", {page: "export", string: event.target.value}).catch(console.error)
                }}
                InputProps={{
                    startAdornment: <InputAdornment position="start"><SearchIcon fontSize="small"/></InputAdornment>,
                }}
            >
            </TextField>
        </>
    )
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

function indexOf(arr: [string, string][], id: [string, string]) {
    for (let i = 0; i < arr.length; i += 1) {
        if (arr[i][0] === id[0] && arr[i][1] === id[1]) return i
    }
    return -1
}

function Logging({nodes}: Readonly<ExportPanelProps>) {
    const [filter, setFilter] = useState<number[]>([]);
    const [searchString, setSearchString] = useState<string>("");
    const [rowData, setRowData] = useState<RowData[]>([]);
    const [selected, setSelected] = React.useState<[string, string][]>([]);
    const [loading, setLoading] = React.useState<boolean>(false);

    function updateFilter(filter_string: string) {
        const filter = [];
        let offset = 0
        for (let node of nodes) {
            for (let oe_index = 0; oe_index < node.object_entries.length; oe_index++) {
                if (node.object_entries[oe_index].includes(filter_string) || node.name.includes(filter_string)) {
                    filter.push(oe_index + offset);
                }
            }
            offset = offset + node.object_entries.length
        }
        setFilter(filter);
    }

    useEffect(() => {
        updateFilter(searchString);
    }, []);


    useEffect(() => {
        async function asyncSetup() {
            const storedSearchString = await invoke<string | null>("get_stored_search_string", {page: "export"});
            if (storedSearchString !== null) {
                setSearchString(storedSearchString)
                updateFilter(storedSearchString)
            }
            let rowData: RowData[] = [];
            for (let node of nodes) {
                let nodeInformation = await invoke<NodeInformation>("node_information", {nodeName: node.name});
                for (let objectEntryName of nodeInformation.object_entries) {
                    rowData.push({
                        nodeName: node.name,
                        objectEntryName,
                    });
                }
            }
            setRowData(rowData);
        }

        asyncSetup().catch(console.error);
    }, [nodes]);

    function rowContent(_index: number, row?: RowData) {
        if (row !== undefined) return <LoggingRow nodeName={row.nodeName} objectEntryName={row?.objectEntryName}
                                                  handleClick={handleClick} isSelected={isSelected}/>
        console.log("undefined");
        return undefined;
    }

    const theme = useTheme();


    const isSelected = (id: [string, string]) => indexOf(selected, id) !== -1;

    const handleClick = (id: [string, string]) => {
        const selectedIndex = indexOf(selected, id);
        let newSelected: [string, string][] = [];

        if (selectedIndex === -1) {
            newSelected = newSelected.concat(selected, [id]);
        } else if (selectedIndex === 0) {
            newSelected = newSelected.concat(selected.slice(1));
        } else if (selectedIndex === selected.length - 1) {
            newSelected = newSelected.concat(selected.slice(0, -1));
        } else if (selectedIndex > 0) {
            newSelected = newSelected.concat(
                selected.slice(0, selectedIndex),
                selected.slice(selectedIndex + 1),
            );
        }
        setSelected(newSelected);
    };

    return (
        <Paper sx={{
            marginTop: "30px",
            marginLeft: "8px",
            marginRight: "10px",
            paddingLeft: "12px",
            paddingRight: "12px",
            width: "calc(100% - 16px)",
            height: "calc(100vh - 115px)",
            paddingTop: "45px",
            paddingBottom: "20px",
            position: "relative"
        }}
        >

            <TopBar nodes={nodes} filter={filter} rowData={rowData} selected={selected} setSelected={setSelected}
                    searchString={searchString}
                    setSearchString={setSearchString} updateFilter={updateFilter} setLoading={setLoading}/>

            {rowData.length == 0 ? <Skeleton

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
                    key={"x"}
                    data={filter.map(i => rowData.flat()[i])}
                    components={VirtuosoTableComponents}
                    itemContent={rowContent}
                >
                </TableVirtuoso>
            }
            <Backdrop
                sx={{color: '#fff', zIndex: (theme) => theme.zIndex.drawer + 1}}
                open={loading}
            >
                <CircularProgress color="inherit"/>
            </Backdrop>
        </Paper>
    );
}

export default Logging;
