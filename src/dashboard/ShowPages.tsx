import { Route, Routes, useLocation } from "react-router-dom";
import OverviewPanel from "../overview/OverviewPanel.tsx";
import { Typography } from "@mui/material";
import { useEffect, useState } from "react";
import { invoke } from "@tauri-apps/api";
import { NetworkInformation } from "../nodes/types/NetworkInformation.ts";
import NodePanel from "../nodes/NodePanel.tsx";
import { NodeInformation } from "../nodes/types/NodeInformation.ts";
import LevitationControl from "../divisions/LevitationControl.tsx";
import GuidanceControl from "../divisions/GuidanceControl.tsx";
import MotorControl from "../divisions/MotorControl.tsx";
import PowerControl from "../divisions/PowerControl.tsx";
import ObjectEntryPanel from "../object_entry/panel/ObjectEntryPanel.tsx";
import Trace from '../trace/Trace.tsx';
import Logging from "../logging/Logging.tsx";

function Content() {
  const location = useLocation();
  return (
    <Typography variant="body2" sx={{ pb: 2 }} color="text.secondary">
      Current route: {location.pathname}
    </Typography>
  );
}

function ShowPages() {
  const [nodes, setNodes] = useState<NodeInformation[]>([]);



  useEffect(() => {
    async function asyncFetchNodeData() {
      let nodes = [];
      let networkInformation = await invoke<NetworkInformation>("network_information");
      for (let nodeName of networkInformation.node_names) {
        let nodeInformation = await invoke<NodeInformation>("node_information", { nodeName: nodeName });
        nodes.push(nodeInformation);
      }
      setNodes(nodes);
    }
    // this asynchronously (in the background) invokes function
    asyncFetchNodeData().catch(console.error);
  }, []); 
  // [] is intentional, because *_information commands will always return the same value, making it useless to call 
  // them multiple times! (only once when mounting the component is sufficient)

  let key = 0;
  let routes = [];

  if (nodes) {
    routes.push(<Route key="Overview" index element={<OverviewPanel nodes={nodes} />} />);
  }
  routes.push(<Route key="TracePanel" path="TracePanel" element={<Trace />} />);
  if (nodes) {
    routes.push(<Route key="Logging" path="Logging" element={<Logging nodes={nodes} />} />);
  }
  if (nodes) {
    routes.push(<Route key="LevitationControl" path="LevitationControl" element={<LevitationControl nodes={nodes} />} />);
    routes.push(<Route key="GuidanceControl" path="GuidanceControl" element={<GuidanceControl nodes={nodes} />} />);
    routes.push(<Route key="MotorControl" path="MotorControl" element={<MotorControl nodes={nodes} />} />);
    routes.push(<Route key="PowerControl" path="PowerControl" element={<PowerControl nodes={nodes} />} />);
  }
  for (let node of nodes) {
    routes.push(<Route key={key++} path={node.name} element={<NodePanel node={node} />} />);
    for (let objectEntryName of node.object_entries) {
      routes.push(
        <Route
          key={`${node.name}::${objectEntryName}`}
          path={`${node.name}/${objectEntryName}`}
          element={<ObjectEntryPanel node={node} name={objectEntryName} />}
        />);
    }
  }

  routes.push(<Route key="root" path="*" element={<Content />} />);


  return (
    <Routes>
      {routes}
    </Routes>
  );
}

export default ShowPages;
