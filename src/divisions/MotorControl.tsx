import { Button, Paper, Stack, useTheme, } from "@mui/material";
import { NodeInformation } from "../nodes/types/NodeInformation.ts";
import PrechargeVis from "../visualizations/precharge/PrechargeVis.tsx";
import ErrorList from "../object_entry/vis/errors/ErrorList.tsx";
import SimpleEnumDisplay from "../object_entry/vis/SimpleEnumDisplay.tsx";
import { invoke } from "@tauri-apps/api";
import SimpleNumberDisplay from "../object_entry/vis/SimpleNumberDisplay.tsx";
import SetValueButton from "../object_entry/panel/SetValueButton.tsx";
import RefreshButton from "../object_entry/panel/RefreshButton.tsx";

function setMotorCommand(command: string) {
  invoke("set_object_entry_value", {
    nodeName: "motor_driver",
    objectEntryName: "command",
    newValueJson: JSON.stringify(command),
  });
}

interface SimpleNumberRow {
  nodeName: string,
  objectEntryName: string,
}

function SimpleEnumRow({ nodeName, objectEntryName }: SimpleNumberRow) {
  const theme = useTheme();
  return (
    <Paper sx={{ padding: 1, backgroundColor: theme.palette.background.trace }} >
      <Stack direction="row" justifyContent="space-between" spacing={2}>
        <SimpleEnumDisplay
          nodeName={nodeName}
          objectEntryName={objectEntryName} />
        <Stack direction="row" justifyContent="end" alignItems="center"
          spacing={2}>
          <SetValueButton
            nodeName={nodeName}
            objectEntryName={objectEntryName}
          />
          <RefreshButton
            nodeName={nodeName}
            objectEntryName={objectEntryName}
          />
        </Stack>
      </Stack>
    </Paper>
  );
}

interface SimpleNumberRow {
  nodeName: string,
  objectEntryName: string,
}

function SimpleNumberRow({ nodeName, objectEntryName }: SimpleNumberRow) {
  const theme = useTheme();
  return (
    <Paper sx={{ padding: 1, backgroundColor: theme.palette.background.trace }} >
      <Stack direction="row" justifyContent="space-between" spacing={2}>
        <SimpleNumberDisplay
          nodeName={nodeName}
          objectEntryName={objectEntryName} />
        <Stack direction="row" justifyContent="end" alignItems="center"
          spacing={2}>
          <SetValueButton
            nodeName={nodeName}
            objectEntryName={objectEntryName}
          />
          <RefreshButton
            nodeName={nodeName}
            objectEntryName={objectEntryName}
          />
        </Stack>
      </Stack>
    </Paper>
  );
}

interface NodesProps {
  nodes: NodeInformation[],
}

function MotorControl({ nodes: _ }: Readonly<NodesProps>) {

  return (
    <Stack direction="column">
      <Stack direction="row" spacing={2} sx={{
        justifyContent: "space-between",
        marginTop: 2,
        marginRight: 2,
        marginLeft: 2,
      }}>
        <Stack direction="column" spacing={2} sx={{
          width: "90%",
        }}>
          <Paper sx={{ padding: 1 }}>
            <Stack direction="row" justifyContent="space-between" spacing={2}>
              <Button variant="contained"
                fullWidth color="subStateArm" onClick={() => setMotorCommand("ARM45")}>
                Arm45
              </Button>
              <Button variant="contained" fullWidth color="subStatePrecharge"
                onClick={
                  () => setMotorCommand("PRECHARGE")
                }>
                Precharge
              </Button>
              <Button variant="contained" fullWidth color="subStateStart" onClick={() => setMotorCommand("START")}>
                Start
              </Button>
              <Button variant="contained" fullWidth color="subStateStop" onClick={() => setMotorCommand("STOP")}>
                Stop
              </Button>
              <Button variant="contained" fullWidth color="subStateDisarm" onClick={() => setMotorCommand("DISARM45")}>
                Disarm45
              </Button>
            </Stack>
          </Paper>
          <Paper sx={{ padding: 1 }}>
            <Stack direction="column" spacing={1}>
              <Stack direction="row" justifyContent="start" spacing={2}>
                <SimpleEnumDisplay
                  nodeName="motor_driver"
                  objectEntryName="state" />
                <SimpleEnumDisplay
                  nodeName="motor_driver"
                  objectEntryName="command" />
                <SimpleEnumDisplay
                  nodeName="motor_driver"
                  objectEntryName="control_active" />
                <SimpleNumberDisplay
                  nodeName="motor_driver"
                  objectEntryName="loop_frequency" />
                <SimpleEnumDisplay
                  nodeName="motor_driver"
                  objectEntryName="sdc_status" />
              </Stack>

              <Stack direction="row" justifyContent="start" spacing={2}>
                <SimpleEnumDisplay
                  nodeName="motor_driver"
                  objectEntryName="board_avg_temperature" />
                <SimpleEnumDisplay
                  nodeName="motor_driver"
                  objectEntryName="current_max" />
                <SimpleEnumDisplay
                  nodeName="motor_driver"
                  objectEntryName="vdc_voltage" />
                <SimpleEnumDisplay
                  nodeName="motor_driver"
                  objectEntryName="precharge_status" />

                <SimpleEnumDisplay
                  nodeName="motor_driver"
                  objectEntryName="feedthrough_status" />
              </Stack>
            </Stack>
          </Paper>
          <Paper sx={{ padding: 1 }}>
            <Stack direction="row" spacing={2} justifyContent="space-around">
              <Stack direction="column" spacing={1}>
                <SimpleNumberRow nodeName="motor_driver"
                  objectEntryName="frequency" />
                <SimpleNumberRow nodeName="motor_driver"
                  objectEntryName="modulation_index" />
              </Stack>

              <Stack direction="column" spacing={1}>
                <SimpleEnumRow nodeName="motor_driver"
                  objectEntryName="error_arming_failed" />
                <SimpleEnumRow nodeName="motor_driver"
                  objectEntryName="error_precharge_failed" />
              </Stack>

              <Stack direction="column" spacing={1}>
                <SimpleNumberRow nodeName="motor_driver"
                  objectEntryName="board_avg_temperature" />
                <SimpleNumberRow nodeName="motor_driver"
                  objectEntryName="lim_average_temperature" />
              </Stack>


            </Stack>
          </Paper>
        </Stack>
        <PrechargeVis
          width="10%"
          nodeName="motor_driver"
        />
      </Stack>
      <Stack direction="row" sx={{
        justifyContent: "end",
        marginTop: 2,
        marginLeft: 2,
        marginRight: 2,
      }}>
        <ErrorList width="40%" height="40vh" />
      </Stack>
    </Stack>
  );
}

export default MotorControl;
