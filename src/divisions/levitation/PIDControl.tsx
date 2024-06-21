import { useEffect, useState } from "react";
import Mode from "./mode";
import { invoke } from "@tauri-apps/api";
import sendSetReq from "./set_req_util";
import { ObjectEntryListenLatestResponse } from "../../object_entry/types/events/ObjectEntryListenLatestResponse";
import { Value } from "../../object_entry/types/Value";
import { Button, ButtonGroup, IconButton, Stack } from "@mui/material";
import RealPropertyInputField from "../../object_entry/edit_dialog/RealPropertyInputField";

import { listen } from "@tauri-apps/api/event";

import UploadIcon from '@mui/icons-material/Upload';
import RefreshIcon from "@mui/icons-material/Refresh";
import { ObjectEntryEvent } from "../../object_entry/types/events/ObjectEntryEvent";

function PIDControl() {

  const [Kp, setKp] = useState<number>();
  const [Ki, setKi] = useState<number>();
  const [Kd, setKd] = useState<number>();
  const [KiMin, setKiMin] = useState<number>();
  const [KiMax, setKiMax] = useState<number>();
  const [emaAlpha, setEmaAlpha] = useState<number>();

  const [KpInput, setKpInput] = useState<number | null>();
  const [KiInput, setKiInput] = useState<number | null>();
  const [KdInput, setKdInput] = useState<number | null>();
  const [KiMinInput, setKiMinInput] = useState<number | null>();
  const [KiMaxInput, setKiMaxInput] = useState<number | null>();
  const [emaAlphaInput, setEmaAlphaInput] = useState<number | null>();


  const [mode, setMode] = useState(Mode.All);


  async function refresh(nodeName: string) {
    await invoke("request_object_entry_value", {
      nodeName,
      objectEntryName: "airgap_pid",
    });

    await invoke("request_object_entry_value", {
      nodeName,
      objectEntryName: "airgap_pid_extra",
    });
  }

  function onRefreshClick() {
    switch (mode) {
      case Mode.Board1: {
        refresh("levitation_board1").catch(console.error);
        break;
      }
      case Mode.Board2: {
        refresh("levitation_board2").catch(console.error);
        break;
      }
      case Mode.Board3: {
        refresh("levitation_board3").catch(console.error);
        break;
      }
      case Mode.All: {
        refresh("levitation_board1").catch(console.error);
        break;
      }
    }
  }

  function uploadValid() {
    return KpInput !== null && KiInput !== null
      && KdInput !== null && KiMinInput !== null
      && KiMaxInput !== null && emaAlphaInput !== null
      && Ki !== undefined && KiMin !== undefined
      && (
        KpInput !== undefined || KiInput !== undefined
        || KdInput !== undefined || KiMaxInput !== undefined
        || KiMinInput !== undefined || emaAlphaInput !== undefined
      );
  }

  function onUploadClick() {
    const KpValue = (KpInput === undefined ? Kp : KpInput)!;
    const KiValue = (KiInput === undefined ? Ki : KiInput)!;
    const KdValue = (KdInput === undefined ? Kd : KdInput)!;
    const KiMinValue = (KiMinInput === undefined ? KiMin : KiMinInput)!;
    const KiMaxValue = (KiMaxInput === undefined ? KiMax : KiMaxInput)!;
    const emaAlphaValue = (emaAlphaInput === undefined ? emaAlpha : emaAlphaInput)!;

    const airgapPid = {
      Kp: KpValue,
      Ki: KiValue,
      Kd: KdValue,
    };
    const airgapPidExtra = {
      Ki_min: KiMinValue,
      Ki_max: KiMaxValue,
      ema_alpha: emaAlphaValue,
    };
    switch (mode) {
      case Mode.Board1: {
        sendSetReq("levitation_board1", "airgap_pid", airgapPid);
        sendSetReq("levitation_board1", "airgap_pid_extra", airgapPidExtra);
        break;
      }
      case Mode.Board2: {
        sendSetReq("levitation_board2", "airgap_pid", airgapPid);
        sendSetReq("levitation_board2", "airgap_pid_extra", airgapPidExtra);
        break;
      }
      case Mode.Board3: {
        sendSetReq("levitation_board3", "airgap_pid", airgapPid);
        sendSetReq("levitation_board3", "airgap_pid_extra", airgapPidExtra);
        break;
      }
      case Mode.All: {
        sendSetReq("levitation_board1", "airgap_pid", airgapPid);
        sendSetReq("levitation_board1", "airgap_pid_extra", airgapPidExtra);
        sendSetReq("levitation_board2", "airgap_pid", airgapPid);
        sendSetReq("levitation_board2", "airgap_pid_extra", airgapPidExtra);
        sendSetReq("levitation_board3", "airgap_pid", airgapPid);
        sendSetReq("levitation_board3", "airgap_pid_extra", airgapPidExtra);
        break;
      }
    }
  }

  async function registerListener(nodeName: string) {
    await refresh(nodeName);

    const resp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", {
      nodeName,
      objectEntryName: "airgap_pid",
    });
    if (resp.latest !== undefined && resp.latest !== null) {
      const value = resp.latest.value as { [name: string]: Value };
      setKp(value["Kp"] as number);
      setKi(value["Ki"] as number);
      setKd(value["Kd"] as number);
    }
    const unregisterPID = await listen<ObjectEntryEvent>(resp.event_name, event => {
      const value = event.payload.value as { [name: string]: Value };
      setKp(value["Kp"] as number);
      setKi(value["Ki"] as number);
      setKd(value["Kd"] as number);
    });

    let respExtra = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", {
      nodeName,
      objectEntryName: "airgap_pid_extra",
    });
    if (respExtra.latest !== undefined && respExtra.latest !== null) {
      const value = respExtra.latest.value as { [name: string]: Value };
      setKiMin(value["Ki_min"] as number);
      setKiMax(value["Ki_max"] as number);
      setEmaAlpha(value["ema_alpha"] as number);
    }
    const unregisterExtra = await listen<ObjectEntryEvent>(respExtra.event_name, event => {
      const value = event.payload.value as { [name: string]: Value };
      setKiMin(value["Ki_min"] as number);
      setKiMax(value["Ki_max"] as number);
      setEmaAlpha(value["ema_alpha"] as number);
    });

    return () => {
      unregisterPID();
      unregisterExtra();
      invoke("unlisten_from_latest_object_entry_value", {
        nodeName: "levitation_board1",
        objectEntryName: "airgap_pid",
      }).catch(console.error);
      invoke("unlisten_from_latest_object_entry_value", {
        nodeName: "levitation_board1",
        objectEntryName: "airgap_pid_extra",
      }).catch(console.error);
    };
  }

  useEffect(() => {
    async function asyncSetup(mode: Mode) {
      let unlisten;
      switch (mode) {
        case Mode.Board1: {
          unlisten = await registerListener("levitation_board1");
          break;
        }
        case Mode.Board2: {
          unlisten = await registerListener("levitation_board2");
          break;
        }
        case Mode.Board3: {
          unlisten = await registerListener("levitation_board3");
          break;
        }
        case Mode.All: {
          unlisten = await registerListener("levitation_board1");
          break;
        }
      }
      return () => {
        unlisten();
      };
    }

    const asyncCleanup = asyncSetup(mode);
    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    }
  }, [mode]);

  return (
    <Stack direction="column" justifyContent="space-between" spacing={2}>
      <Stack direction="row" spacing={2}>
        <Stack direction="column" justifyContent="start" spacing={1}
          sx={{
            width: "50%",
          }}>
          <RealPropertyInputField
            name={"Kp"}
            min={0}
            max={100}
            onUpdate={(x) => setKpInput(x)}
            currentValue={Kp}
            bitSize={64}
            width="100%"
          />
          <RealPropertyInputField
            name={"Ki"}
            min={0}
            max={100}
            onUpdate={(x) => setKiInput(x)}
            currentValue={Ki}
            bitSize={64}
            width="100%"
          />
          <RealPropertyInputField
            name={"Kd"}
            min={0}
            max={100}
            onUpdate={(x) => setKdInput(x)}
            currentValue={Kd}
            bitSize={64}
            width="100%"
          />
        </Stack>
        <Stack direction="column" justifyContent="start" spacing={1}
          sx={{
            width: "50%",
          }}>
          <RealPropertyInputField
            name={"Ki_min"}
            min={-500}
            max={500}
            onUpdate={(x) => setKiMinInput(x)}
            currentValue={KiMin}
            bitSize={64}
            width="100%"
          />
          <RealPropertyInputField
            name={"Ki_max"}
            min={-500}
            max={500}
            onUpdate={(x) => setKiMaxInput(x)}
            currentValue={KiMax}
            bitSize={64}
            width="100%"
          />
          <RealPropertyInputField
            name={"ema_alpha"}
            min={0}
            max={1}
            onUpdate={(x) => setEmaAlphaInput(x)}
            currentValue={emaAlpha}
            bitSize={64}
            width="100%"
          />
        </Stack>
      </Stack>
      <Stack direction="row" justifyContent="end" spacing={2} sx={{
        width: "100%",
      }}>

        <IconButton
          size="small"
          sx={{
            width: "35px",
            height: "35px",
          }}
          disabled={!uploadValid()}
          onClick={onUploadClick}
        >
          <UploadIcon fontSize="small" />
        </IconButton>

        <IconButton
          size="small"
          sx={{
            width: "35px",
            height: "35px",
          }}
          onClick={onRefreshClick}
        >
          <RefreshIcon fontSize="small" />
        </IconButton>
        <ButtonGroup variant="contained" aria-label="Basic button group">
          <Button variant={mode == Mode.Board1 ? "contained" : "text"}
            onClick={() => setMode(Mode.Board1)}>
            1
          </Button>
          <Button variant={mode == Mode.Board2 ? "contained" : "text"}
            onClick={() => setMode(Mode.Board2)}
          >
            2
          </Button>
          <Button variant={mode == Mode.Board3 ? "contained" : "text"}
            onClick={() => setMode(Mode.Board3)}>
            3
          </Button>
          <Button variant={mode == Mode.All ? "contained" : "text"}
            onClick={() => setMode(Mode.All)}>
            ∀
          </Button>
        </ButtonGroup>
      </Stack>
    </Stack >
  );
}

export default PIDControl;
