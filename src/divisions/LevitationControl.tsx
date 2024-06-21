import { Paper, Stack, Typography } from "@mui/material";
import { NodeInformation } from "../nodes/types/NodeInformation.ts";
import PIDControl from "./levitation/PIDControl.tsx";
import PIControl from "./levitation/PIControl.tsx";
import PIDGraph from "./levitation/PIDGraph.tsx";
import PIGraph from "./levitation/PIGraph.tsx";



interface NodesProps {
  nodes: NodeInformation[],
}


function LevitationControl({ }: Readonly<NodesProps>) {

  return (
    <Stack direction="column" justifyContent="start" spacing={2}
      sx={{
        margin: 2,
      }}>
      <Stack direction="row"
        justifyContent="space-between"
        justifyItems="start"
        spacing={2}>
        <Paper sx={{
          width: "50%",
          padding: 1,
        }}>
          <Typography textAlign={"center"} paddingBottom={1}>
            Airgap PID Controller
          </Typography>
          <PIDControl />
        </Paper>
        <Paper sx={{
          width: "50%",
          padding: 1,
        }}>
          <Typography textAlign={"center"} paddingBottom={1}>
            Current PI Controller
          </Typography>
          <PIControl />
        </Paper>
      </Stack>
      <Paper sx={{
        width: "100%",
        height: "500px",
        padding: 1,
      }}>
        <PIDGraph />
      </Paper>

      <Paper sx={{
        width: "100%",
        height: "500px",
        padding: 1,
      }}>
      <PIGraph/>
      </Paper>
    </Stack>
  );
}

export default LevitationControl;
