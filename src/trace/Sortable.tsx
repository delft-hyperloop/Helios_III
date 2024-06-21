
import NorthIcon from '@mui/icons-material/North';
import SouthIcon from '@mui/icons-material/South';
import { IconButton, Stack } from '@mui/material';
import {ReactElement, useState} from 'react';


export enum Sorting {
  None,
  ByTime,
  ById,
  ByName,
  ByBus,
  ByDlc,
}

interface SortableProps {
  children : ReactElement,
  sortAsc : boolean
  self : Sorting,
  value : Sorting,
  setSorting : (sorting : Sorting, toggleAsc : boolean) => void,
}

function Sortable({children, sortAsc, self, value, setSorting} : Readonly<SortableProps>) {
  const [hover, setHover] = useState<boolean>(false);

  return <Stack
    direction="row"
    alignItems="center"
    justifyContent="flex-start"
    spacing={1}
    onMouseEnter={() => {
      setHover(true);
    }}
    onMouseLeave={() => {
      setHover(false);
    }}
  >
    {children}
    <IconButton
      sx={{
        opacity: (value == self || hover) ? "100%" : "0%",
        boxShadow: "none",
        color: (value == self) ? "black" : "grey",
      }}
      onClick={() => {
        if (self == value) {
          setSorting(self, true);
        }else {
          setSorting(self, false);
        }
      }}
    >
      {sortAsc ? <SouthIcon style={{fontSize : "15px"}} /> : <NorthIcon style={{fontSize: "15px"}} />}
    </IconButton>
  </Stack>

}

export default Sortable;
