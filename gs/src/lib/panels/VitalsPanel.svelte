<script lang="ts">
    import {Chart, Battery, Table, FSM, south_bridge_payload} from "$lib";
    import {AppBar} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import {invoke} from "@tauri-apps/api/tauri";
    import Keydown from "svelte-keydown";

    let width:number;

    let tableArr:any[][];
    let tableArr2:any[][];
    $: tableArr = [
        ["Upper drawer VB", $south_bridge_payload.value],
        ["Bottom drawer VB", $south_bridge_payload.value],
        ["outside of VB", $south_bridge_payload.value],
        ["HEMS", $south_bridge_payload.value],
        ["Motor core", $south_bridge_payload.value],
    ]
    $: tableArr2 = [
        ["Current State", $south_bridge_payload.value],
        ["Bottom drawer VB", $south_bridge_payload.value],
        ["outside of VB", $south_bridge_payload.value],
        ["HEMS", $south_bridge_payload.value],
        ["Motor core", $south_bridge_payload.value]
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
        <div class="flex flex-col h-full pb-20 justify-between items-center">
            <button on:click={() => {invoke('abort')}} class="btn border border-error-500 bg-error-500 rounded-sm">
                <span style="writing-mode: vertical-lr">ABORT</span>
            </button>
            <span style="writing-mode: vertical-lr" class="font-medium">Vitals Panel</span>
            <div class="flex flex-col gap-4">
                <Battery orientation="vertical" height={55} perc={$south_bridge_payload.value} />
                <Battery orientation="vertical" height={55} perc={$south_bridge_payload.value} />
            </div>
        </div>
    {:else}
        <div class="w-full p-4 pb-16 h-full flex flex-col gap-2 overflow-y-auto overflow-x-clip text-surface-50">
            <!--     FSM       -->
            <div>
                {#if width > 550}
                    <FSM size="sm" />
                {:else}
                    <FSM size="lg" />
                {/if}
            </div>
            <!--      Under FSM      -->
            <div class="flex flex-wrap justify-between">
                <div class="flex gap-4">
                    <p>Velocity: <span class="font-mono font-medium">{$south_bridge_payload.value}</span></p>
                    <p>Position: <span class="font-mono font-medium">{$south_bridge_payload.value}</span></p>
                </div>
                <div class="flex gap-4">
                    <div class="flex gap-2">
                        <span>LV: </span>
                        <Battery orientation="horizontal" perc={$south_bridge_payload.value} />
                    </div>
                    <div class="flex gap-2">
                        <span>HV: </span>
                        <Battery orientation="horizontal" perc={$south_bridge_payload.value} />
                    </div>
                </div>
            </div>
            <!--     TEMPERATURE TABLE      -->
            <div class="grid {width < 550 ? 'grid-cols-1' : 'grid-cols-2'} gap-2">
                <Table {tableArr} />
                <Table titles={["Variable", "Status"]} tableArr={tableArr2} />
            </div>
            <!--     OFFSET GRAPHS       -->
            <div class="flex flex-col gap-2">
                <div class="grid gap-2 {width < 550 ? 'grid-cols-1' : 'grid-cols-2'}">
                    <Chart eventChannel="north_bridge" title="Offset horizontal" refreshRate={5} />
                    <Chart eventChannel="north_bridge" title="Offset top" refreshRate={100} />
                    <div class="{width < 550 ? 'col-span-1' : 'col-span-2'}">
                        <Chart title="Velocity" refreshRate={100} />
                    </div>
                </div>
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
            </div>
        </div>
    {/if}
</div>