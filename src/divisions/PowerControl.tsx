import {NodeInformation} from "../nodes/types/NodeInformation.ts";
import {Box, Paper, Stack, Typography} from "@mui/material";
import theme from "../theme.ts";
import Speedometer, {
    Background,
    Arc,
    Needle,
    Progress,
    Marks,
    Indicator,
} from 'react-speedometer';
import {DangerPath} from "react-speedometer/dist";


interface NodesProps {
    nodes: NodeInformation[],
}

function LevitationConsumption() {
    return (
        <Paper sx={{
            padding: 1,
            backgroundColor: theme.palette.background.paper2,
        }}>
            <Stack direction="row" justifyContent={"space-between"} sx={{
                paddingLeft : 2,
                paddingRight : 2,
            }}>
                <Box>
                    <Typography> Levitation 1 </Typography>
                </Box>
                <Box>
                    TODO
                </Box>
                <Box>
                    <Typography textAlign="end"> 14kW </Typography>
                </Box>
            </Stack>
        </Paper>
    )
}

function PowerConsumption() {
    return (
        <Stack direction="row" spacing={2} alignItems="center" sx={{
            height: "100%",
            padding: 2,
        }}>
            <Stack direction="column" justifyContent={"start"} sx={{
                height: "100%",
                width: "100%",
            }} spacing={1}>
                <LevitationConsumption/>
                <LevitationConsumption/>
                <LevitationConsumption/>
                <LevitationConsumption/>
            </Stack>
        </Stack>
    )
}

function PowerControl({}: Readonly<NodesProps>) {
    return (
        <Stack direction="column" sx={{margin: 2}}>
            <Stack direction="row"
                   justifyContent="space-evenly"
                   spacing={2}>
                <Paper sx={{
                    width: "65%",
                    height: "89vh",
                    padding: 1,
                }}>
                    <Typography textAlign={"left"} paddingTop={1} paddingLeft={2}>
                        Power Consumption
                    </Typography>
                    <PowerConsumption/>

                </Paper>
                <Stack direction="column" spacing={1.2} justifyContent="space-evenly" width="35%">
                    <Paper sx={{
                        width: "100%",
                        height: "44vh",
                        padding: 1,
                    }}>
                        <Typography textAlign={"center"} paddingBottom={1}>
                            Consumption
                        </Typography>
                        <Box paddingTop="70px" textAlign="center">
                            <Speedometer
                                width={400}
                                value={20}
                                max={20}
                                angle={160}
                                fontFamily='Arial'
                            >
                                <Background angle={180} color="#000000" />
                                <Arc/>
                                <Needle offset={40} circleRadius={30} circleColor={theme.palette.background.appBar}/>
                                <DangerPath/>
                                <Progress/>
                                <Marks step={2}/>
                                <Indicator color="#000000" y={280} x={175}>
                                </Indicator>
                            </Speedometer>
                        </Box>
                        <Typography marginTop="-170px" textAlign="center" fontSize="2.5em" marginLeft="70px">
                            kW
                        </Typography>
                    </Paper>
                    <Paper sx={{
                        width: "100%",
                        height: "44vh",
                        padding: 1,
                    }}>
                        <Typography textAlign={"center"} paddingBottom={1}>
                            Fancy graph
                        </Typography>
                    </Paper>
                </Stack>
            </Stack>
        </Stack>
    );
}

export default PowerControl;
