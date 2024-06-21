import { Paper, Stack } from "@mui/material";
import { NodeInformation } from "../nodes/types/NodeInformation.ts";
import TemperatureVis from "../visualizations/temperature/TemperatureVis.tsx";
import StateVis from "../visualizations/state/StateVis.tsx";
import SdcVis from "../visualizations/sdc/SdcVis.tsx";
import PodSideView from "../visualizations/side/PodSideView.tsx";
import ErrorList from "../object_entry/vis/errors/ErrorList.tsx";
import GuidanceVis from "../visualizations/guidance/GuidanceVis.tsx";

interface NodesProps {
  // we can probably remove this fetching data early is kind of unnecassary.
  nodes: NodeInformation[],
  // useGraphScrolling?: boolean,
}

function GuidanceControl({ }: Readonly<NodesProps>) {
  return (
    <Stack direction="column">
      <Stack direction="row" spacing={2} sx={{
        justifyContent: "space-around",
        marginTop: 2,
        marginRight : 2,
        marginLeft : 2,
      }}>
        <TemperatureVis />
        <StateVis />
        <Stack direction="column" spacing={2} justifyContent="space-between" sx={{
          width: "100%",
        }}>
          <Paper sx={{
            width: "100%",
          }}>
            <SdcVis />
          </Paper>
          <Paper sx={{
            width: "100%",
            height: "100%",
          }}>
            <PodSideView />
          </Paper>
        </Stack>
      </Stack>
      <Stack direction="row" sx={{
        justifyContent: "space-between",
        marginTop: 2,
        marginLeft : 2,
        marginRight : 2,
      }}>
        <Paper sx={{
          width: "59%",
          height: "40vh",
        }}>
          <GuidanceVis />
        </Paper>
        <ErrorList width="40%" height="40vh"/>
      </Stack>
    </Stack>
  );
}

export default GuidanceControl;
