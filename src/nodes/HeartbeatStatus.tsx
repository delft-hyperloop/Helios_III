import { invoke } from "@tauri-apps/api";
import { listen } from "@tauri-apps/api/event";
import { useEffect, useState } from "react"

interface HeartbeatProps {
  nodeName: string,
  busName: string

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


function HeartbeatStatus({ nodeName, busName }: Readonly<HeartbeatProps>) {
  const [heartbeatState, setHeartbeatState] = useState<string>();


  useEffect(() => {
    async function asyncSetup() {
      invoke<HeartbeatState>("get_heartbeat_status", { nodeName, busName }).then(s => {
        setHeartbeatState(stateToString(s))
      }).catch(console.error);
      let evt_name = await invoke<string>("listen_to_heartbeat", { nodeName, busName });

      let unlistenJs = await listen<HeartbeatState>(evt_name, evt => {
        setHeartbeatState(stateToString(evt.payload));
      });

      return () => {
        unlistenJs();
        invoke("unlisten_from_heartbeat", { nodeName, busName })
          .catch(console.error);
      };
    }

    let asyncCleanup = asyncSetup();
    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    }
  }, [heartbeatState, nodeName]);

  return (
    <div style={{
      color: "red",
      width: "0.8em",
      height: "0.8em",
      borderRadius: "50%",
      backgroundColor: heartbeatState,
      boxShadow: heartbeatState === undefined ? undefined : "1px 1px 1px grey",
    }}></div>
  );

}

export default HeartbeatStatus;
