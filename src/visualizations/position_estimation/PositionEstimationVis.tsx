import { Paper } from "@mui/material";
import Graph from "./Graph";


function PositionEstimationVis(){
  return (
    <Paper sx={{
      width : "100%",
      height: "26.5vh",
    }}>
      <Graph/>
    </Paper>
  );

}

export default PositionEstimationVis;
