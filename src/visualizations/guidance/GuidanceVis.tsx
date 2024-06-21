import { Box, Paper, Stack, Typography, useTheme } from "@mui/material";
import "./GuidanceVis.css"

function GuidanceVis() {

  const theme = useTheme();

  return (
    <Paper sx={{
      width: "60%",
      height: "27vh",
    }}>
      <Stack direction="row" spacing={2} alignItems="center" sx={{
        height: "100%",
        padding: 2,
      }}>
        <Box id="guidance-vis">
          <div className="border">
          </div>
          <div className="g1">
          </div>
          <div className="g2">
          </div>
          <div className="title">
            <h4>
              Guidance-System<br/>Airgaps
            </h4>
          </div>
        </Box>
        <Stack direction="column" justifyContent={"start"} sx={{
          height: "100%",
          width: "50%",
        }} spacing={1}>
          <Paper sx={{
            padding: 1,
            backgroundColor: theme.palette.background.paper2,
          }}>
            <Typography textAlign="center" variant="h6">
              Levitation
            </Typography>
            <Stack direction="row" justifyContent={"space-between"} sx={{
              paddingLeft : 2,
              paddingRight : 2,
            }}>
              <Box>
                <Typography fontSize={"0.75em"}>
                  Average:
                </Typography>
                <Typography fontSize={"0.75em"}>
                  Average Current:
                </Typography>
                <Typography fontSize={"0.75em"}>
                  Variance:
                </Typography>
              </Box>
              <Box>
                <Typography fontSize={"0.75em"}>
                  16.8361mm
                </Typography>
                <Typography fontSize={"0.75em"}>
                  9.9287A
                </Typography>
                <Typography fontSize={"0.75em"}>
                  0.0063mm
                </Typography>
              </Box>
            </Stack>
          </Paper>
          <Paper sx={{
            padding: 1,
            backgroundColor: theme.palette.background.paper2,
          }}>
            <Typography textAlign="center" variant="h6">
              Guidance
            </Typography>
            <Stack direction="row" justifyContent={"space-between"} sx={{
              paddingLeft : 2,
              paddingRight : 2,
            }}>
              <Box>
                <Typography fontSize={"0.75em"}>
                  Average (Left):
                </Typography>
                <Typography fontSize={"0.75em"}>
                  Average (Right):
                </Typography>
                <Typography fontSize={"0.75em"}>
                  Variance:
                </Typography>
              </Box>
              <Box>
                <Typography fontSize={"0.75em"}>
                  12.7412mm
                </Typography>
                <Typography fontSize={"0.75em"}>
                  12.1982mm
                </Typography>
                <Typography fontSize={"0.75em"}>
                  0.0163mm
                </Typography>
              </Box>
            </Stack>
          </Paper>
        </Stack>
      </Stack>
    </Paper>
  );
}


export default GuidanceVis;
