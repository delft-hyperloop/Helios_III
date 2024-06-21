import { styled, useTheme, } from '@mui/material/styles';
import MuiDrawer from '@mui/material/Drawer';
import Toolbar from '@mui/material/Toolbar';
import List from '@mui/material/List';
import IconButton from '@mui/material/IconButton';
import ChevronLeftIcon from '@mui/icons-material/ChevronLeft';
import { ListEntries } from '../dashboard/PageList';
import { Box } from '@mui/material';
import StateIndicatorBar from '../app_bar/StateIndicatorBar.tsx';
import { useEffect, useState } from 'react';
import { invoke } from '@tauri-apps/api';
import { listen } from '@tauri-apps/api/event';
import { ObjectEntryListenLatestResponse } from '../object_entry/types/events/ObjectEntryListenLatestResponse';
import { ObjectEntryEvent } from '../object_entry/types/events/ObjectEntryEvent';

export const DRAWER_WIDTH: number = 220;

const Drawer = styled(MuiDrawer, { shouldForwardProp: (prop) => prop !== 'open' })(
  ({ theme, open }) => ({
    '& .MuiDrawer-paper': {
      position: 'relative',
      overflow: "hidden",
      whiteSpace: 'nowrap',
      width: DRAWER_WIDTH,
      transition: theme.transitions.create('width', {
        easing: theme.transitions.easing.sharp,
        duration: theme.transitions.duration.enteringScreen,
      }),
      boxSizing: 'border-box',
      ...(!open && {
        overflowX: 'hidden',
        transition: theme.transitions.create('width', {
          easing: theme.transitions.easing.sharp,
          duration: theme.transitions.duration.leavingScreen,
        }),
        width: theme.spacing(7),
        [theme.breakpoints.up('sm')]: {
          width: theme.spacing(7.5),
        },
      }),
    },
  }),
);

const STATE_OE = { nodeName: "mother_board", objectEntryName: "state" };

interface SideMenuProps {
  open: boolean,
  toggleOpen: () => void,
}

function SideMenu({ open, toggleOpen }: Readonly<SideMenuProps>) {
  const theme = useTheme();

  const [state, setState] = useState<string>("COM_DISCONNECTED");

  useEffect(() => {
    async function asyncSetup() {

      try {
        const resp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", STATE_OE);
        if (resp.latest !== undefined && resp.latest !== null) {
          setState(resp.latest.value as string);
        }
        listen<ObjectEntryEvent>(resp.event_name, event => {
          setState(event.payload.value as string);
        }).catch(console.error);
      } catch {
        console.error(`Failed to register listener for SideMenu component: Object entry ${STATE_OE.nodeName}:${STATE_OE.objectEntryName} not found`)
      }
      return () => {
      }
    }

    const asyncCleanup = asyncSetup();

    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    }
  }, []);

  return (
    <Drawer
      variant="permanent"
      open={open}
      PaperProps={{
        sx: {
          border: "none",
          height: "100%",
          overflowY: "hidden",
          margin: 0,
          padding: 0,
        }
      }}
    >
      <Toolbar
        sx={{
          display: 'flex',
          alignItems: 'center',
          justifyContent: 'flex-start',
          px: [1],
          m: 0,
          height: "81px",
          backgroundColor: theme.palette.background.appBar
        }}
      >
        <IconButton
          onClick={toggleOpen}
          sx={{
              backgroundColor: theme.palette.background.drawer,
              '&:hover': {
                  backgroundColor: theme.palette.background.paper,
              }
          }}
        >
          <ChevronLeftIcon />
        </IconButton>
      </Toolbar>
      <StateIndicatorBar state={state} voffset="-6px" />
      <Box
        component="div"
        sx={{
          backgroundColor: theme.palette.background.drawer,
          position: "relative",
          top: "-5px",
          borderRight: `1px solid ${theme.palette.background.trace}`,
          minHeight: "calc(100vh - 85px)",
          maxHeight: "calc(100vh - 85px)",
        }}
      >
        <List component="nav">
          <ListEntries open={open} />
        </List>
      </Box>
    </Drawer>
  );
}

export default SideMenu;
