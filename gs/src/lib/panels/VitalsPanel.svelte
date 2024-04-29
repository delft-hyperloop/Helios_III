<script lang="ts">
    import Chart from "$lib/components/generic/Chart.svelte";
    import {AppBar, TabAnchor} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import {south_bridge_payload} from "$lib/stores/data";
    import Table from "$lib/components/generic/Table.svelte";
    import type {TempTableEntry} from "$lib/types";
    import FSM from "$lib/components/FSM.svelte";
    import {invoke} from "@tauri-apps/api/tauri";
    import Keydown from "svelte-keydown";

    let width:number;
    let updateSizes:((w:number)=>void)[] = [];
    $: updateSizes.forEach(updateSize => updateSize(width));

    let tableArr:TempTableEntry[];
    let tableArr2:TempTableEntry[];
    $: tableArr = [
        {name: "Upper drawer VB", value: $south_bridge_payload.value},
        {name: "Bottom drawer VB", value: $south_bridge_payload.value},
        {name: "outside of VB", value: $south_bridge_payload.value},
        {name: "HEMS", value: $south_bridge_payload.value},
        {name: "Motor core", value: $south_bridge_payload.value},
    ]
    $: tableArr2 = [
        {name: "Current State", value: $south_bridge_payload.value},
        {name: "Bottom drawer VB", value: $south_bridge_payload.value},
        {name: "outside of VB", value: $south_bridge_payload.value},
        {name: "HEMS", value: $south_bridge_payload.value},
        {name: "Motor core", value: $south_bridge_payload.value},
    ]
</script>

<Keydown on:combo={({detail}) => {
    if (detail === "Control- -Enter") {
        invoke('abort')
    }
    }}/>

<div bind:clientWidth={width} class="h-full bg-surface-700 text-surface-50">
    <AppBar padding="p-3" border="border-b border-b-surface-900" background="bg-surface-700">
        <svelte:fragment slot="lead"><Icon icon="codicon:graph-line" /></svelte:fragment>
        <span>Vitals</span>
        <svelte:fragment slot="trail">
            <button on:click={() => {invoke('abort')}} class="btn py-0 border border-error-500 bg-error-500 rounded-sm">ABORT</button>
        </svelte:fragment>
    </AppBar>

    {#if width < 200}
        <div class="flex flex-col gap-4 h-full justify-center items-center">
            <button on:click={() => {invoke('abort')}} class="btn border border-error-500 bg-error-500 rounded-sm">
                <span style="writing-mode: vertical-lr"> ABORT</span>
            </button>
            <span style="writing-mode: vertical-lr">VITALS PANEL</span>
        </div>
    {:else}
        <div class="w-full p-4 pb-16 h-full flex flex-col gap-4 overflow-y-auto overflow-x-clip text-surface-50">
            <!--     OFFSET GRAPHS       -->
            <div class="flex flex-col gap-2">
                <div class="flex flex-wrap items-center gap-x-8 font-mono">
                    <h3 class="text-lg font-medium">Offset data:</h3>
                    <div class="flex gap-4">
                        <p>X1: {$south_bridge_payload.value}</p>
                        <p>X2: {$south_bridge_payload.value}</p>
                        <p>X3: {$south_bridge_payload.value}</p>
                        <p>X4: {$south_bridge_payload.value}</p>
                    </div>
                    <div class="flex gap-4">
                        <p>Y1: {$south_bridge_payload.value}</p>
                        <p>Y2: {$south_bridge_payload.value}</p>
                        <p>Y3: {$south_bridge_payload.value}</p>
                        <p>Y4: {$south_bridge_payload.value}</p>
                    </div>
                </div>
                <div class="flex gap-2 flex-wrap items-start font-mono">
                    <Chart title="Offset left" bind:resize={updateSizes[0]} refreshRate={100} />
                    <Chart title="Offset right" bind:resize={updateSizes[1]} refreshRate={100} />
                    <Chart title="Offset top" bind:resize={updateSizes[2]} shrink={false} refreshRate={100} />
                </div>
            </div>
            <!--     TEMPERATURE TABLE      -->
            <div class="flex flex-wrap gap-2 ">
                <div class="flex-grow">
                    <Table {tableArr} />
                </div>
                <div class="flex-grow">
                    <Table titles={["VARIABLE", "STATE"]} tableArr={tableArr2} />
                </div>
            </div>
            <div>
                {#if width > 650}
                    <FSM size="sm" />
                {:else}
                    <FSM size="lg" />
                {/if}
            </div>
        </div>
    {/if}
</div>