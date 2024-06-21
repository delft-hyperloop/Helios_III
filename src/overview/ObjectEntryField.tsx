import {ReactElement, useEffect, useState} from "react";
import {ObjectEntryInformation} from "../object_entry/types/ObjectEntryInformation.ts";
import {ObjectEntryEvent} from "../object_entry/types/events/ObjectEntryEvent.ts";
import {invoke} from "@tauri-apps/api";
import {ObjectEntryListenLatestResponse} from "../object_entry/types/events/ObjectEntryListenLatestResponse.ts";
import {listen} from "@tauri-apps/api/event";
import {Skeleton} from "@mui/material";
import TextField from "@mui/material/TextField";
import interpolate from "color-interpolate";
import {ObjectEntryGridInformation} from "./types/ObjectEntryGridInformation.tsx";
import {isEnum, isInt, isReal, isUInt, StructTypeInfo, Type} from "../object_entry/types/Type.tsx";
import {Value} from "../object_entry/types/Value.tsx";

function getColorDiscrete(value: number | string, warning: number[] | string[],
                          ok: number[] | string[], tooGood: number[] | string[]) {
    if (value in tooGood) {
        return "#1976d2"
    } else if (value in ok) {
        return "#2E9B33"
    } else if (value in warning)
        return "#FFD500"
    else {
        return "#E32E13"
    }
}

function getColorInterpolate(value: number, min: number, max: number) {
    let colormap = interpolate(['#2E9B33', '#FFD500', '#E32E13']);
    let percent = (value - min) / (max - min)
    return colormap(percent)
}

function displayEntryDiscrete(ty: Type, value: Value, name: string,
                              warning: number[] | string[], ok: number[] | string[], tooGood: number[] | string[]): ReactElement {
    if (isEnum(ty.id)) {
        return <TextField InputProps={{readOnly: true}} value={value} label={name} sx={{
            '& .MuiOutlinedInput-root': {
                '& fieldset': {
                    borderWidth: "2px",
                    borderColor: getColorDiscrete(String(value), warning, ok, tooGood),
                },
                '&:hover fieldset': {
                    borderWidth: "2px",
                    borderColor: getColorDiscrete(String(value), warning, ok, tooGood),
                },
                '&.Mui-focused fieldset': {
                    borderWidth: "3px",
                    borderColor: getColorDiscrete(String(value), warning, ok, tooGood),
                },
            },
        }}/>
    } else if (isInt(ty.id) || isUInt(ty.id) || isReal(ty.id)) {
        return <TextField InputProps={{readOnly: true}} value={Number(value).toFixed(1)} label={name} sx={{
            '& .MuiOutlinedInput-root': {
                '& fieldset': {
                    borderWidth: "2px",
                    borderColor: getColorDiscrete(Number(value), warning, ok, tooGood),
                },
                '&:hover fieldset': {
                    borderWidth: "2px",
                    borderColor: getColorDiscrete(Number(value), warning, ok, tooGood),
                },
                '&.Mui-focused fieldset': {
                    borderWidth: "3px",
                    borderColor: getColorDiscrete(Number(value), warning, ok, tooGood),
                },
            },
        }}/>
    } else {
        let oec: {[name : string] : Value} = value as {[name : string] : Value}
        return (<>
            {Object.entries(oec).map(([name, value]) => displayEntryDiscrete((ty.info as StructTypeInfo).attributes[name], value, name, warning, ok, tooGood))}
        </>)

    }
}


function displayEntryInterpolate(ty: Type, value: Value, name: string, min: number, max: number): ReactElement {
    if (isEnum(ty.id)) {
        return <TextField InputProps={{readOnly: true}} value={value} label={name} sx={{
            '& .MuiOutlinedInput-root': {
                '&:hover fieldset': {
                    borderColor: "#B7BFC7",
                },
            },
        }}/>
    } else if (isInt(ty.id) || isUInt(ty.id) || isReal(ty.id)) {
        return <TextField InputProps={{readOnly: true}} value={Number(value).toFixed(1)} label={name} sx={{
            '& .MuiOutlinedInput-root': {
                '& fieldset': {
                    borderWidth: "2px",
                    borderColor: getColorInterpolate(Number(value), min, max),
                },
                '&:hover fieldset': {
                    borderWidth: "2px",
                    borderColor: getColorInterpolate(Number(value), min, max),
                },
                '&.Mui-focused fieldset': {
                    borderWidth: "3px",
                    borderColor: getColorInterpolate(Number(value), min, max),
                },
            },
        }}/>
    } else {
        let oec: {[name : string] : Value} = value as {[name : string] : Value}
        return (<>
            {Object.entries(oec).map(([name, value]) => displayEntryInterpolate((ty.info as StructTypeInfo).attributes[name], value, name, min, max))}
        </>)
    }
}

function displayEntry(ty: Type, value: Value, name: string): ReactElement {
    if (isEnum(ty.id)) {
        return <TextField InputProps={{readOnly: true}} value={value} label={name} sx={{
            '& .MuiOutlinedInput-root': {
                '&:hover fieldset': {
                    borderColor: "#B7BFC7",
                },
            },
        }}/>
    } else if (isInt(ty.id) || isUInt(ty.id) || isReal(ty.id)) {
        return <TextField InputProps={{readOnly: true}} value={Number(value).toFixed(1)} label={name} sx={{
            '& .MuiOutlinedInput-root': {
                '&:hover fieldset': {
                    borderColor: "#B7BFC7",
                },
            },
        }}/>
    } else {
        let oec: {[name : string] : Value} = value as {[name : string] : Value}
        return (<>
            {Object.entries(oec).map(([name, value]) => displayEntry((ty.info as StructTypeInfo).attributes[name], value, name))}
        </>)
    }
}


function ObjectEntryField({node, entry, interpolate, min, max, warning, ok, tooGood}: Readonly<ObjectEntryGridInformation>) {
    let [information, setInformation] = useState<ObjectEntryInformation | null>(null);
    let [value, setValue] = useState<ObjectEntryEvent | null>(null);

    function updateValue(event: ObjectEntryEvent) {
        setValue(event);
    }

    async function fetchInformation() {
        let information = await invoke<ObjectEntryInformation>("object_entry_information",
            {nodeName: node.name, objectEntryName: entry});
        setInformation(information);
        return information;
    }

    async function registerListener() {
        let {event_name, latest} = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value",
            {nodeName: node.name, objectEntryName: entry});
        if (latest !== undefined) updateValue(latest);
        let unlistenBackend = () => invoke("unlisten_from_latest_object_entry_value", {
            nodeName: node.name, objectEntryName: entry
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
    }, [node, entry]);


    if (information && value) {
        if (interpolate && min !== undefined && max !== undefined && !isEnum(information.ty.id)) {
            return displayEntryInterpolate(information.ty, value.value, information.name, min, max)
        } else if (!interpolate && warning && ok && tooGood) {
            return displayEntryDiscrete(information.ty, value.value, information.name, warning, ok, tooGood)
        } else {
            return displayEntry(information.ty, value.value, information.name)
        }
    } else {
        return <Skeleton variant="rounded" height={"50px"}/>
    }
}

export default ObjectEntryField