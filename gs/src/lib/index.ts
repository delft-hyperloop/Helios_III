// Panels
import VitalsPanel from "$lib/panels/VitalsPanel.svelte";
import LogsPanel from "$lib/panels/LogsPanel.svelte";
import DetailsPanel from "$lib/panels/DetailsPanel.svelte";

// Tabs
import BatteriesTab from "$lib/panels/tabs/BatteriesTab.svelte";
import MotorsTab from "$lib/panels/tabs/MotorsTab.svelte";
import HomeTab from "$lib/panels/tabs/HomeTab.svelte";
import LocationTab from "$lib/panels/tabs/LocationTab.svelte";
import ProceduresTab from "$lib/panels/tabs/ProceduresTab.svelte";
import RunInitTab from "$lib/panels/tabs/RunInitTab.svelte";
import DebugTab from "$lib/panels/tabs/DebugTab.svelte";
import PneumaticsTab from "$lib/panels/tabs/PneumaticsTab.svelte";

// Components
import Battery from "$lib/components/Battery.svelte";
import BottomBar from "$lib/components/BottomBar.svelte";
import FSM from "$lib/components/FSM.svelte";
import Localiser from "$lib/components/Localiser.svelte";
import Pneumatics from "$lib/components/Pneumatics.svelte";
import TitleBar from "$lib/components/TitleBar.svelte";
import Chart from "$lib/components/generic/Chart.svelte";
import Table from "$lib/components/generic/Table.svelte";
import Command from "$lib/components/abstract/Command.svelte";
import TheoreticalRun from "$lib/components/TheoreticalRun.svelte";
import Status from "$lib/components/generic/Status.svelte";
import Tile from "$lib/components/generic/Tile.svelte";
import TileGrid from "$lib/components/generic/TileGrid.svelte";
import ToggleCommand from "$lib/components/abstract/ToggleCommand.svelte";

// Utils
import {PlotBuffer, StrokePresets} from "$lib/util/PlotBuffer";
import {GrandDataDistributor} from "$lib/util/GrandDataDistributor";
import util from "$lib/util/util";

import type {Payload, NamedCommand, EventChannel, Log} from "$lib/types";

// Stores
import {south_bridge_payload} from "$lib/stores/data";
import {detailTabSet, inputSpeed, details_pane, vitals_pane, inputTurn} from "$lib/stores/state";
import uPlot from "uplot";

export const chartDataStore = new Map<string, uPlot.AlignedData>();

// Export all
export {
    ToggleCommand,
    inputTurn,
    StrokePresets,
    GrandDataDistributor,
    PneumaticsTab,
    TileGrid,
    details_pane,
    vitals_pane,
    Tile,
    DebugTab,
    util,
    Status,
    VitalsPanel,
    LogsPanel,
    DetailsPanel,
    BatteriesTab,
    MotorsTab,
    HomeTab,
    LocationTab,
    ProceduresTab,
    RunInitTab,
    Battery,
    BottomBar,
    FSM,
    TitleBar,
    Chart,
    Table,
    Command,
    PlotBuffer,
    south_bridge_payload,
    detailTabSet,
    inputSpeed,
    Pneumatics,
    Localiser,
    TheoreticalRun
}
export type {Payload, NamedCommand, EventChannel, Log}