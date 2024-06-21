import {NodeInformation} from "../nodes/types/NodeInformation.ts";
import {useEffect, useState} from "react";
import {ObjectEntryInformation} from "../object_entry/types/ObjectEntryInformation.ts";
import {invoke} from "@tauri-apps/api";
import {ObjectEntryEvent} from "../object_entry/types/events/ObjectEntryEvent.ts";
import {ObjectEntryListenLatestResponse} from "../object_entry/types/events/ObjectEntryListenLatestResponse.ts";
import {listen} from "@tauri-apps/api/event";
import interpolate from "color-interpolate";
import {Skeleton, TableCell} from "@mui/material";
import {isInt, isReal, isUInt} from "../object_entry/types/Type.tsx";

function getColor(value: number, min: number, max: number) {
    let colormap = interpolate(['#2E9B33', '#FFD500', '#E32E13']);
    let percent = (value - min) / (max - min)
    return colormap(percent)
}

interface TableCellProps {
    node: NodeInformation,
    name: string,
    min: number
    max: number
}

function CustomTableCell({node, name, min, max}: Readonly<TableCellProps>) {
    let [information, setInformation] = useState<ObjectEntryInformation | null>(null);
    let [value, setValue] = useState<ObjectEntryEvent | null>(null);

    function updateValue(event: ObjectEntryEvent) {
        setValue(event);
    }

    async function fetchInformation() {
        let information = await invoke<ObjectEntryInformation>("object_entry_information",
            {nodeName: node.name, objectEntryName: name});
        setInformation(information);
        return information;
    }

    async function registerListener() {
        let {event_name, latest} = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value",
            {nodeName: node.name, objectEntryName: name});
        if (latest !== undefined) updateValue(latest);
        let unlistenBackend = () => invoke("unlisten_from_latest_object_entry_value", {
            nodeName: node.name, objectEntryName: name
        }).catch(console.error);

        let unlistenReact = await listen<ObjectEntryEvent>(event_name, event => updateValue(event.payload));

        return () => {
            unlistenBackend();
            unlistenReact();
        }
    }

    async function asyncTask() {
        await fetchInformation();
        // wait for fetch Information to be complete before listeningS
        // allows using the information in updateValue!
        return await registerListener();
    }

    useEffect(() => {

        let cleanup = asyncTask();
        return () => {
            cleanup.then(f => f()).catch(console.error);
            setInformation(null);
            setValue(null);
        }
    }, [node, name]);

    if (information && value && (isInt(information.ty.id) || isUInt(information.ty.id) || isReal(information.ty.id))) {
        return <TableCell align="center"
                          style={{backgroundColor: getColor(Number(value.value), min, max)}}
                          padding="none"
                          sx={{maxWidth: 20}}>
            {Number(value.value).toFixed(1)}
        </TableCell>
    } else if (information && value) {
        return <TableCell align="center" color="error">Not a Number</TableCell>
    } else {
        return <Skeleton variant="rounded"/>
    }
}

export default CustomTableCell