import { Paper, Skeleton, Stack, Typography, useTheme } from "@mui/material";
import { invoke } from "@tauri-apps/api";
import { useEffect, useState } from "react";
import { NodeInformation } from "./nodes/types/NodeInformation";
import { ObjectEntryInformation } from "./object_entry/types/ObjectEntryInformation";
import { GraphInterpolation } from "./graph/GraphInterpolation";
import RefreshButton from "./object_entry/panel/RefreshButton";
import SetValueButton from "./object_entry/panel/SetValueButton";
import InterpolationModeButton from "./object_entry/panel/InterpolationModeButton";
import GraphBufferingButton from "./object_entry/panel/GraphBufferingButton";
import ObjectEntryGraph from "./object_entry/graph/ObjectEntryGraph";


function FloatingPlotContent() {
  const [node, setNode] = useState<NodeInformation>();
  const [objectEntryName, setObjectEntryName] = useState<string>();

  useEffect(() => {
    invoke<[string, string]>("get_floating_window_info").then(([nodeName, objectEntryName]) => {
      invoke<NodeInformation>("node_information", { nodeName }).then(setNode).catch(console.error);
      setObjectEntryName(objectEntryName as any);
    }).catch(console.error);
  }, []);

  if (node === undefined || objectEntryName === undefined) {
    return <Skeleton />
  } else {
    return <FloatingObjectEntryPanel node={node} name={objectEntryName} />
  }
}



interface FloatingObjectEntryPanelProps {
  node: NodeInformation,
  name: string,
}

function FloatingObjectEntryPanel({ node, name }: Readonly<FloatingObjectEntryPanelProps>) {

  const [information, setInformation] = useState<ObjectEntryInformation | null>(null);

  const [interpolationMode, setInterpolationMode] = useState<GraphInterpolation>(GraphInterpolation.Step);
  const [buffering, setBuffering] = useState<boolean>(true);

  const theme = useTheme();

  useEffect(() => {
    async function fetchInformation() {
      let information = await invoke<ObjectEntryInformation>("object_entry_information",
        { nodeName: node.name, objectEntryName: name });
      setInformation(information);
    }

    fetchInformation().catch(console.error);
    return () => {
      setInformation(null);
    };
  }, [node, name]);

  return <Paper sx={{
    marginTop: "8px",
    marginLeft: "8px",
    marginRight: "10px",
    paddingLeft: "12px",
    paddingRight: "12px",
    paddingTop: "55px",
    paddingBottom: "20px",
    width: "calc(100% - 40px)",
    position: "relative"
  }}>
    <Stack component="div" sx={{
      position: "absolute",
      top: "0px",
      left: "12px",
      padding: "1px",
    }} direction="row">
      <Typography
        sx={{
          "&:hover": { color: theme.palette.info.main, textDecoration: "underline" }
        }}
        variant="h5"
      >{node.name}
      </Typography>
      <Typography sx={{
      }} variant="h5">::{name}
      </Typography>
    </Stack>
    {
      !information ? <Skeleton variant="rounded" height={"300px"} /> :
        <>
          {information.description ? <Typography sx={{
            position: "absolute",
            top: "30px",
            left: "20px",
            padding: "1px",

          }} variant="subtitle2">{information.description}</Typography>
            : <></>}
          <RefreshButton
            nodeName={node.name}
            objectEntryName={information.name}
            sx={{
              position: "absolute",
              top: "7px",
              left: "calc(100% - 50px)",
            }}
          />
          <SetValueButton
            nodeName={node.name}
            objectEntryInfo={information}
            sx={{
              position: "absolute",
              top: "7px",
              left: "calc(100% - 90px)",
            }}
          />
          <InterpolationModeButton
            sx={{
              position: "absolute",
              top: "7px",
              left: "calc(100% - 130px)",
            }}
            mode={interpolationMode}
            onClick={() => {
              setInterpolationMode(mode => {
                switch (mode) {
                  case GraphInterpolation.Step:
                    return GraphInterpolation.Linear;
                  case GraphInterpolation.Linear:
                    return GraphInterpolation.MonotoneSpline;
                  default:
                    return GraphInterpolation.Step;
                }
              });
            }}
          />
          <GraphBufferingButton
            sx={{
              position: "absolute",
              top: "7px",
              left: "calc(100% - 170px)",
            }}
            buffer={buffering}
            onClick={() => {
              setBuffering(buffering => !buffering);
            }}
          />
          <ObjectEntryGraph
            nodeName={node.name}
            objectEntryName={name}
            timeDomain={1000}
            interpolation={interpolationMode}
            buffering={buffering}
          />
        </>
    }

  </Paper >
}



export default FloatingPlotContent;
