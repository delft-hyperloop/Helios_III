import ListItemIcon from '@mui/material/ListItemIcon';
import ListItemText from '@mui/material/ListItemText';
import TerminalIcon from '@mui/icons-material/Terminal';
import GamesIcon from '@mui/icons-material/Games';
import ExpandMoreIcon from '@mui/icons-material/ExpandMore';
import ChevronRightIcon from '@mui/icons-material/ChevronRight';
import FlightTakeoff from '@mui/icons-material/FlightTakeoff';
import Speed from '@mui/icons-material/Speed';
import EditRoad from '@mui/icons-material/EditRoad';
import BatteryChargingFullIcon from '@mui/icons-material/BatteryChargingFull';
import clsx from 'clsx';
import {Link as RouterLink, LinkProps as RouterLinkProps, useNavigate,} from 'react-router-dom';
import {Divider, ListItemButton, Typography} from '@mui/material';
import {TreeItem, TreeItemContentProps, TreeItemProps, TreeView, useTreeItem} from '@mui/x-tree-view';
import {NetworkInformation} from '../nodes/types/NetworkInformation.ts';
import {NodeInformation} from '../nodes/types/NodeInformation.ts';
import React, {useEffect, useState} from "react";
import {invoke} from '@tauri-apps/api';
import Box from "@mui/material/Box";
import SaveIcon from '@mui/icons-material/Save';
import {ObjectEntryInformation} from '../object_entry/types/ObjectEntryInformation.tsx';
import HeartbeatNodeStatus from './HeartbeatNodeStatus.tsx';

interface ListItemLinkProps {
    icon?: React.ReactElement;
    text: string;
    to: string;
}

const CustomContent = React.forwardRef(function CustomContent(
    props: TreeItemContentProps,
    ref,
) {
    const {
        classes,
        className,
        label,
        nodeId,
        icon: iconProp,
        expansionIcon,
        displayIcon,
    } = props;

    const {
        disabled,
        expanded,
        selected,
        focused,
        handleExpansion,
        preventSelection,
    } = useTreeItem(nodeId);

    const icon = iconProp || expansionIcon || displayIcon;
    const navigate = useNavigate();

    const handleMouseDown = (event: React.MouseEvent<HTMLDivElement, MouseEvent>) => {
        preventSelection(event);
    };

    const handleExpansionClick = (
        event: React.MouseEvent<HTMLDivElement, MouseEvent>,
    ) => {
        handleExpansion(event);
    };

    const handleSelectionClick = () => {
        navigate(nodeId)
    };

    return (
        <div
            className={clsx(className, classes.root, {
                [classes.expanded]: expanded,
                [classes.selected]: selected,
                [classes.focused]: focused,
                [classes.disabled]: disabled,
            })}
            onMouseDown={handleMouseDown}
            ref={ref as React.Ref<HTMLDivElement>}
        >
            <div onClick={handleExpansionClick} className={classes.iconContainer}>
                {icon}
            </div>
            <Typography
                onClick={handleSelectionClick}
                onDoubleClick={handleExpansionClick}
                component="div"
                className={classes.label}
            >
                {label}
            </Typography>
        </div>

    );
});

interface CustomTreeItemProps extends TreeItemProps {
    nodeName: string,
    busNames: string[],
}

const CustomNodeTreeItem = React.forwardRef(function CustomTreeItem(
    props: CustomTreeItemProps,
    ref: React.Ref<HTMLLIElement>,
) {

    return <TreeItem
        ContentComponent={CustomContent}
        nodeId={props.nodeId}
        children={props.children}
        label={(<HeartbeatNodeStatus nodeName={props.nodeId} busNames={props.busNames}></HeartbeatNodeStatus>)}
        ref={ref}/>;
});

const CustomTreeItem = React.forwardRef(function CustomTreeItem(
    props: TreeItemProps,
    ref: React.Ref<HTMLLIElement>,
) {

    return <TreeItem ContentComponent={CustomContent} {...props} ref={ref}/>;
});

const Link = React.forwardRef<HTMLAnchorElement, RouterLinkProps>(function Link(
    itemProps,
    ref,
) {
    return <RouterLink ref={ref} {...itemProps} role={undefined}/>;
});

function ListItemButtonLink(props: Readonly<ListItemLinkProps>) {
    const {icon, text, to} = props;
    return (
        <li>
            <ListItemButton component={Link} to={to} sx={{
                "&:hover": {
                    color: "primary.main"
                }
            }}>
                {icon ? <ListItemIcon>{icon}</ListItemIcon> : null}
                <ListItemText primary={text} sx={{
                    "&:hover": {
                        color: "primary.main"
                    }
                }}/>
            </ListItemButton>
        </li>
    );
}

export const RouterList = (
    <React.Fragment>
        <ListItemButtonLink to="/" text="Overview" icon={<GamesIcon/>}/>
        <ListItemButtonLink to="/TracePanel" text="Trace" icon={<TerminalIcon/>}/>
        <ListItemButtonLink to="/LevitationControl" text="Levitation Control" icon={<FlightTakeoff/>}/>
        <ListItemButtonLink to="/GuidanceControl" text="Guidance Control" icon={<EditRoad/>}/>
        <ListItemButtonLink to="/MotorControl" text="Motor Control" icon={<Speed/>}/>
        <ListItemButtonLink to="/PowerControl" text="Power Control" icon={<BatteryChargingFullIcon/>}/>
    </React.Fragment>
);

interface NodeEntriesProps {
    nodeInfo: CompleteNodeInformation,
}

function NodeEntries({nodeInfo}: Readonly<NodeEntriesProps>) {


    /*Page name has to equal the nodeId!*/
    return (<>
        {nodeInfo.objectEntries.filter(e => e.plottable).map((entry) =>
            <CustomTreeItem key={nodeInfo.node.name + "/" + entry.name} nodeId={nodeInfo.node.name + "/" + entry.name}
                            label={entry.name}/>
        )}
    </>);

}

interface CompleteNodeInformation {
    node: NodeInformation,
    objectEntries: ObjectEntryInformation[],
}

export function NodeList() {
    const [nodes, setNodes] = useState<CompleteNodeInformation[]>();

    useEffect(() => {
        async function asyncFetchNetworkInfo() {
            let networkInfo = await invoke<NetworkInformation>("network_information");
            let nodes: CompleteNodeInformation[] = [];
            for (let nodeName of networkInfo.node_names) {
                let node = await invoke<NodeInformation>("node_information", {nodeName});
                let objectEntries: ObjectEntryInformation[] = [];
                for (let objectEntryName of node.object_entries) {
                    let objectEntry = await invoke<ObjectEntryInformation>("object_entry_information", {
                        nodeName,
                        objectEntryName
                    });
                    objectEntries.push(objectEntry);
                }
                nodes.push({node, objectEntries});
            }
            setNodes(nodes);
        }

        if (nodes === undefined) {
            asyncFetchNetworkInfo().catch(console.error);
        }
    }, []);

    return (
        <TreeView
            aria-label="icon expansion"
            defaultCollapseIcon={<ExpandMoreIcon/>}
            defaultExpandIcon={<ChevronRightIcon/>}
        >
            {nodes === undefined
                ? <></>
                : nodes.map((completeNode) =>
                    <CustomNodeTreeItem
                        key={completeNode.node.name}
                        nodeId={completeNode.node.name}
                        label={completeNode.node.name}
                        nodeName={completeNode.node.name}
                        busNames={completeNode.node.buses}>
                        <NodeEntries nodeInfo={completeNode}/>
                    </CustomNodeTreeItem>)
            }

        </TreeView>
    );
}


function ExportListButton() {
    return (
        <li>
            <ListItemButtonLink to="/Logging" text="Export" icon={<SaveIcon/>}/>
        </li>
    );
}

interface ListEntriesProps {
    open: boolean,
}

export function ListEntries({open}: Readonly<ListEntriesProps>) {
    if (open) {
        return <>
            {RouterList}
            <Divider sx={{my: 1}}/>
            <ExportListButton/>
            <Divider sx={{my: 1}}/>
            <Box component="div" sx={{
                height: "calc(100vh - 353px)",
                overflow: 'auto'
            }}>
                <NodeList/>
            </Box>
        </>;
    } else {
        return <>
            {RouterList}
            <Divider sx={{my: 1}}/>
            <ExportListButton/>
            <Divider sx={{my: 1}}/>
        </>;
    }
}
