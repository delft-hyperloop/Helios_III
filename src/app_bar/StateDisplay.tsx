import {Paper, Stack, Typography} from "@mui/material";


interface StateDisplayProps {
  state: string,
}

function StateDisplay({ state }: Readonly<StateDisplayProps>) {
    return (
        <Paper sx={{
            paddingLeft: 1,
            paddingTop: 1,
            paddingBottom: 0.5,
            paddingRight: 0.5,
            background: "white",
            width: "150px",
            height: "55px",
        }}
        >
            <Stack direction="column" spacing={0}  fontSize={12}>
                    <Typography variant="caption" color="grey" fontSize={10} >
                        {`Current State`}
                    </Typography>
                {state}
            </Stack>
        </Paper>
    );


}
export default StateDisplay;
