import { Typography } from "@mui/material";
import { invoke } from "@tauri-apps/api";
import { UnlistenFn, listen } from "@tauri-apps/api/event";
import { useEffect, useState } from "react"

interface HeartbeatProps {
  nodeName: string,
  busNames: string[]
}

enum HeartbeatState {
  TimedOut = "TimedOut",
  Good = "Good",
  InActive = "InActive"
}

function stateToString(heartbeatState: HeartbeatState) {
  switch (heartbeatState) {
    case HeartbeatState.TimedOut:
      return "red";
    case HeartbeatState.InActive:
      return "grey";
    case HeartbeatState.Good:
      return "green";
    default:
      console.error();
  }
}

function statesToNodeState(states: string[]) {
  if (states.every(stat => stat === "green")) {
    return "green";
  } else if (states.some(stat => stat === "red")) {
    return "red";
  } else {
    return "grey";
  }
}


function HeartbeatNodeStatus({ nodeName, busNames }: Readonly<HeartbeatProps>) {
  const [heartbeatNodeState, setHeartbeatNodeState] = useState<string>();
  const [_, setHeartbeatStates] = useState<string[]>([]);

  useEffect(() => {
    async function asyncSetup() {

      busNames.map((busName, idx) => {
        invoke<HeartbeatState>("get_heartbeat_status", { nodeName, busName }).then(s => {
          setHeartbeatStates(old => {
            let updt = old.slice();
            updt[idx] = stateToString(s)!;
            setHeartbeatNodeState(statesToNodeState(updt));
            return updt;
          })
        }).catch(console.error)
      });
      let evtNames: string[] = [];
      for (let idx in busNames) {
        evtNames[idx] = await invoke<string>("listen_to_heartbeat", { nodeName, busName: busNames[idx] });
      }
      let unlistenJss: UnlistenFn[] = [];
      evtNames.map(async (evtName, idx) => {
        unlistenJss.push(await listen<HeartbeatState>(evtName, evt => {
          setHeartbeatStates(old => {
            let updt = old.slice();
            updt[idx] = stateToString(evt.payload) ?? updt[idx];
            setHeartbeatNodeState(statesToNodeState(updt));
            return updt;
          });
        }));
      });

      return () => {
        unlistenJss.map(unlistenJs => unlistenJs());
        busNames.map(busName => {
          invoke("unlisten_from_heartbeat", { nodeName, busName }).catch(console.error);
        });
      };
    }

    let asyncCleanup = asyncSetup();
    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    }
  }, [nodeName]);

  return (
    <Typography variant="body1" color={heartbeatNodeState}>{nodeName}</Typography>
  );
}

export default HeartbeatNodeStatus;
