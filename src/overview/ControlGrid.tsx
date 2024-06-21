import { Grid, Paper, styled } from '@mui/material';
import { NodeInformation } from "../nodes/types/NodeInformation.ts";
import ObjectEntryGrid from "./ObjectEntryGrid.tsx";
import { ObjectEntryGridInformation } from "./types/ObjectEntryGridInformation.tsx";
import NumberListEntry from '../object_entry/vis/list/NumberListEntry.tsx';
import ObjectEntryList from '../object_entry/vis/list/ObjectEntryList.tsx';
import {ValueTableCellInformation} from "./types/ValueTableCellInformation.tsx";
import ValueTable from "./ValueTable.tsx";

const Item = styled(Paper)(({ theme }) => ({
  backgroundColor: theme.palette.mode === 'dark' ? '#1A2027' : '#fff',
  ...theme.typography.body2,
  padding: theme.spacing(1),
  textAlign: 'center',
  color: theme.palette.text.secondary,
}));

interface ControlGridProps {
  nodes: NodeInformation[];
}

// function Model(props: JSX.IntrinsicAttributes & { [properties: string]: any; }) {
//   const { scene } = useGLTF(BMW);
//   return <primitive object={scene} scale={0.01} {...props} />;
// }
//
// function Pod3DModel() {
//   return (
//     <Canvas dpr={[1, 2]} shadows camera={{ fov: 45 }}>
//       <PresentationControls global speed={1.5} zoom={0.5} polar={[-Math.PI, Math.PI]}>
//         <Stage environment={null} shadows={true}>
//           <Model scale={0.01} />
//         </Stage>
//       </PresentationControls>
//     </Canvas>
//   );
// }

function createGridEntries(nodes: NodeInformation[]) {
  let entries: ObjectEntryGridInformation[] = [];
  nodes.map((node: NodeInformation) => {
    if (node.name === "motor_driver") {
      entries.push({ node: node, entry: "motor_temperature1", interpolate: true, min: 0, max: 20 })
      entries.push({ node: node, entry: "motor_temperature2", interpolate: true, min: 0, max: 20 })
      entries.push({ node: node, entry: "motor_temperature3", interpolate: true, min: 0, max: 20 })
      entries.push({ node: node, entry: "motor_temperature4", interpolate: true, min: 0, max: 20 })
    }
  });
  return entries;
}

function createValueTableEntries(nodes: NodeInformation[]) {
  let entries: ValueTableCellInformation[] = [];
  nodes.map((node: NodeInformation) => {
    if (node.name === "motor_driver") {
      entries.push({ node: node, entry: "motor_temperature1", min: 0, max: 20 })
      entries.push({ node: node, entry: "motor_temperature2", min: 0, max: 20 })
      entries.push({ node: node, entry: "motor_temperature3", min: 0, max: 20 })
      entries.push({ node: node, entry: "motor_temperature4", min: 0, max: 20 })

    }
  });
  return entries;
}

function ControlGrid({ nodes }: Readonly<ControlGridProps>) {
  return (
    <Grid container rowSpacing={2} columnSpacing={{ xs: 1, md: 2 }} sx={{ margin: "1%" }}>
      <Grid item xs={6} md={6}>
        <Item sx={{ width: "100%", height: "300px" }}>
          3D Pod Model
        </Item>
      </Grid>
      <Grid item xs={6} md={6}>
        <Item sx={{ width: "100%", height: "300px" }}>
          Table 02
        </Item>
      </Grid>
      <Grid item xs={6} md={8}>
        <Item sx={{ width: "100%", height: "300px" }}>
          <ObjectEntryGrid entries={createGridEntries(nodes)} width={200} />
        </Item>
      </Grid>

      <Grid item xs={12} md={12}>
        <Item sx={{ width: "100%", height: "400px" }}>
          <ValueTable entries={createValueTableEntries(nodes)} title={"Temp"} width={600} height={40} rows={2} columns={2}/>
        </Item>
      </Grid>

      <Grid item xs={12} md={6}>
        <Item sx={{ width: "400px", margin: 0, padding: 0 }}>
          <ObjectEntryList
            sx={{ width: "100%" }}
            label="Motor Temperatures"
          >
            <NumberListEntry label="dslim_starboard" nodeName="motor_driver" objectEntryName="motor_temperature1" />
            <NumberListEntry label="dslim_port" nodeName="motor_driver" objectEntryName="motor_temperature2" />
            <NumberListEntry label="mosfet" nodeName="motor_driver" objectEntryName="motor_temperature3" />
            <NumberListEntry nodeName="motor_driver" objectEntryName="motor_temperature4" />
          </ObjectEntryList>
        </Item>
      </Grid>
    </Grid>
  );
}

export default ControlGrid;
