<script lang="ts">
    import Chart from "$lib/components/generic/Chart.svelte";
    import {AppBar} from "@skeletonlabs/skeleton";
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
                <span style="writing-mode: vertical-lr">ABORT</span>
            </button>
            <span style="writing-mode: vertical-lr" class="font-medium">Vitals Panel</span>
        </div>
    {:else}
        <div class="w-full p-4 pb-16 h-full flex flex-col gap-4 overflow-y-auto overflow-x-clip text-surface-50">
            <!--     FSM       -->
            <div>
                {#if width > 550}
                    <FSM size="sm" />
                {:else}
                    <FSM size="lg" />
                {/if}
            </div>
            <!--     TEMPERATURE TABLE      -->
            <div class="grid {width < 550 ? 'grid-cols-1' : 'grid-cols-2'} gap-2">
                <Table {tableArr} />
                <Table titles={["Variable", "Status"]} tableArr={tableArr2} />
            </div>
            <!--     OFFSET GRAPHS       -->
            <div class="flex flex-col gap-2">
                <div class="flex flex-wrap items-center gap-x-4 {width < 550 ? 'text-sm' : ''}">
                    <h3 class="text-lg font-medium">Offset data:</h3>
                    <div class="flex flex-wrap gap-4">
                        <div class="flex gap-4">
                            <p class="font-mono">X1: {$south_bridge_payload.value}</p>
                            <p class="font-mono">X2: {$south_bridge_payload.value}</p>
                            <p class="font-mono">X3: {$south_bridge_payload.value}</p>
                            <p class="font-mono">X4: {$south_bridge_payload.value}</p>
                        </div>
                        <div class="flex gap-4">
                            <p class="font-mono">Y1: {$south_bridge_payload.value}</p>
                            <p class="font-mono">Y2: {$south_bridge_payload.value}</p>
                            <p class="font-mono">Y3: {$south_bridge_payload.value}</p>
                            <p class="font-mono">Y4: {$south_bridge_payload.value}</p>
                        </div>
                    </div>
                </div>
                <div class="grid gap-2 {width < 550 ? 'grid-cols-1' : 'grid-cols-2'}">
                    <Chart parentWidth={width} title="Offset left" bind:resize={updateSizes[0]} refreshRate={100} />
                    <Chart parentWidth={width} title="Offset right" bind:resize={updateSizes[1]} refreshRate={100} />
                    <div class="{width < 550 ? 'col-span-1' : 'col-span-2'}">
                        <Chart parentWidth={width} title="Offset top" bind:resize={updateSizes[2]} shrink={false} refreshRate={100} />
                    </div>
                </div>
            </div>
        </div>
    {/if}
</div>