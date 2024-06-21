import { IconButton, InputAdornment, Paper, Stack, Table, TableBody, TableCell, TableContainer, TableHead, TableRow, TextField, Typography, styled } from '@mui/material';
import SearchIcon from '@mui/icons-material/Search';
import AccessTimeIcon from '@mui/icons-material/AccessTime';
import ChangeHistoryIcon from '@mui/icons-material/ChangeHistory';
import { useEffect, useRef, useState } from 'react';
import Sortable, { Sorting } from './Sortable';
import useFocusOnCtrlShortcut from './FocusOnKey';
import { invoke } from '@tauri-apps/api';
import { listen } from '@tauri-apps/api/event';
import { TraceEvent } from './types/TraceEvent';
import ErrorRow from './ErrorRow';
import UndefinedRow from './UndefinedRow';
import NormalRow from './NormalRow';


const StyledTableHeader = styled(TableRow)(({theme}) => ({
  "& th": {
    backgroundColor: theme.palette.background.trace,
  },
}));

async function notifyBackendAboutSorting(sorting: Sorting, sortAsc: boolean, absTime: boolean) {
  let criteria: string | undefined = undefined;
  switch (sorting) {
    case Sorting.ById:
      criteria = "id";
      break;
    case Sorting.ByName:
      criteria = "name";
      break;
    case Sorting.ByTime:
      if (absTime) {
        criteria = "absolute-time";
      } else {
        criteria = "delta-time";
      }
      break;
    case Sorting.ByBus:
      criteria = "bus";
      break;
    case Sorting.ByDlc:
      criteria = "dlc";
      break;
  }
  await invoke("sort_trace_by", { criteria, sortAsc })
}

function Trace() {

  const [useAbsoluteTime, setUseAbsoluteTime] = useState<boolean>(false);

  const [sorting, setSorting] = useState<Sorting>(Sorting.None);
  const [sortAsc, setSortAsc] = useState<boolean>(false);

  const [open, setOpen] = useState<{ [key: number]: boolean }>({});
  const [searchString, setSearchString] = useState<string>("");

  function updateSorting(sorting: Sorting, toggleAsc: boolean) {
    setSorting(sorting);
    if (toggleAsc) {
      setSortAsc(x => {
        notifyBackendAboutSorting(sorting, !x, useAbsoluteTime).catch(console.error);
        return !x;
      });
    } else {
      notifyBackendAboutSorting(sorting, sortAsc, useAbsoluteTime).catch(console.error);
    }
  }

  function updateFilter(filterString: string | undefined) {
    filterString = filterString?.length === 0 ? undefined : filterString;
    invoke("filter_trace_by", { filterString }).catch(console.error);
  }

  const searchFieldRef = useRef() as any;
  useFocusOnCtrlShortcut("f", searchFieldRef)

  const [frames, setFrames] = useState<TraceEvent[]>([]);

  useEffect(() => {
    async function asyncSetup() {
      const storedSearchString = await invoke<string | null>("get_stored_search_string", {page: "trace"});
      if (storedSearchString !== null) {
          setSearchString(storedSearchString)
          updateFilter(storedSearchString)
      }
      const eventName = await invoke<string>("listen_to_trace");
      const unlisten = await listen<TraceEvent[]>(eventName, event => {
        setFrames(event.payload);
      });
      return () => {
        invoke("unlisten_from_trace").catch(console.error);
        unlisten();
      };
    }
    setSearchString("");
    const asyncCleanup = asyncSetup();
    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    };
  }, []);


  return <TableContainer
      component={Paper}
      sx={{
        marginTop: "20px",
        marginLeft: "10px",
        width: "calc(100% - 20px)",
        height: "calc(100%)",
      }}
  >
    <Table
        stickyHeader
        aria-label="sticky table"
        size="small"
    >
      <TableHead>
        <StyledTableHeader>
          <TableCell
              align="left"
              sx={{
                width: "30px",
                borderRightWidth: 1,
                borderRightColor: "lightgray",
                borderRightStyle: "solid",
              }}
          >
          </TableCell>
          <TableCell
              align="left"
              sx={{
                width: "110px",
                borderRightWidth: 1,
                borderRightColor: "lightgray",
                borderRightStyle: "solid",
              }}
          >
            <Sortable
                sortAsc={sortAsc}
                self={Sorting.ByTime}
                value={sorting}
                setSorting={updateSorting}
            >
              <IconButton
                  sx={{
                    boxShadow: "none",
                    color: "black",
                  }}
                  onClick={() => {
                    setUseAbsoluteTime(prev => !prev);
                  }}
              >
                {useAbsoluteTime ? <AccessTimeIcon fontSize="small" /> : <ChangeHistoryIcon fontSize="small" />}
              </IconButton>
            </Sortable>
          </TableCell >
          <TableCell
              align="left"
              sx={{
                width: "10px",
                borderRightWidth: 1,
                borderRightColor: "lightgray",
                borderRightStyle: "solid",
              }}
          >
            <Sortable
                sortAsc={sortAsc}
                self={Sorting.ById}
                value={sorting}
                setSorting={updateSorting}
            >
              <Typography variant="subtitle1" >
                ID
              </Typography>
            </Sortable>
          </TableCell>
          <TableCell
              align="left"
              sx={{
                borderRightWidth: 1,
                borderRightColor: "lightgray",
                borderRightStyle: "solid",
              }}
          >
            <Stack
                direction="row"
                alignItems="flex-start"
                justifyContent="space-between"
            >
              <Sortable
                  sortAsc={sortAsc}
                  self={Sorting.ByName}
                  value={sorting}
                  setSorting={updateSorting}
              >
                <Typography variant="subtitle1" >
                  Name
                </Typography>
              </Sortable>
              <TextField
                  inputRef={searchFieldRef}
                  value={searchString}
                  sx={{
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
                    invoke("store_search_string", {page: "trace", string: event.target.value}).catch(console.error)
                  }}
                  InputProps={{
                    startAdornment: <InputAdornment position="start"><SearchIcon fontSize="small" /></InputAdornment>,
                  }}
              >
              </TextField>
            </Stack>

          </TableCell>
          <TableCell
              align="left"
              sx={{
                width: "100px",
                borderRightWidth: 1,
                borderRightColor: "lightgray",
                borderRightStyle: "solid",
              }}
          >
            <Sortable
                sortAsc={sortAsc}
                self={Sorting.ByBus}
                value={sorting}
                setSorting={updateSorting}
            >
              <Typography variant="subtitle1" >
                Bus
              </Typography>
            </Sortable>
          </TableCell >
          <TableCell
              align="left"
              sx={{
                width: "100px",
                borderRightWidth: 1,
                borderRightColor: "lightgray",
                borderRightStyle: "solid",
              }}
          >
            <Sortable
                sortAsc={sortAsc}
                self={Sorting.ByDlc}
                value={sorting}
                setSorting={updateSorting}
            >
              <Typography variant="subtitle1" >
                DLC
              </Typography>
            </Sortable>
          </TableCell >
        </StyledTableHeader>
      </TableHead>
      <TableBody>
        {frames.map(event => {
          if (event.frame.ty == "normal") {
            return <NormalRow key={event.key} open={open} setOpen={setOpen} event={event} useAbsoluteTime={useAbsoluteTime} />
          }else if (event.frame.ty == "undefined") {
            return <UndefinedRow key={event.key} event={event} useAbsoluteTime={useAbsoluteTime} />
          } else if (event.frame.ty == "error") {
            return <ErrorRow key={event.key} open={open} setOpen={setOpen} event={event} useAbsoluteTime={useAbsoluteTime} />
          }
        })}

      </TableBody>
    </Table>
  </TableContainer >

}

export default Trace;
