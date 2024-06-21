import {Paper, Stack} from '@mui/material';
import {NodeInformation} from "../nodes/types/NodeInformation.ts";
import ErrorList from '../object_entry/vis/errors/ErrorList.tsx';
import PodSideView from '../visualizations/side/PodSideView.tsx';
import SdcVis from '../visualizations/sdc/SdcVis.tsx';
import StateVis from '../visualizations/state/StateVis.tsx';
import TemperatureVis from '../visualizations/temperature/TemperatureVis.tsx';
import PositionEstimationVis from '../visualizations/position_estimation/PositionEstimationVis.tsx';
import FsmVis from '../visualizations/fsm/FsmVis.tsx';

interface OverviewProps {
    nodes: NodeInformation[];
}
function OverviewPanel({}: Readonly<OverviewProps>) {

  return (
    <Stack direction="column" spacing={2} sx={{
      padding : 2,
    }}>
      <Stack direction="row" spacing={2} sx={{
        justifyContent: "space-around",
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
      <Stack direction="row" spacing={2} sx={{
        justifyContent: "end",
        marginTop: 2,
        marginLeft : 2,
        marginRight : 2,
      }}>
        <FsmVis/>
        <ErrorList width="50%" height="27vh"/>
      </Stack>
      <PositionEstimationVis/>
    </Stack>
  );
}

export default OverviewPanel;
