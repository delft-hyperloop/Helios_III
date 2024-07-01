<script lang="ts">
    import Keydown from "svelte-keydown";
    import {Tab, TabGroup} from "@skeletonlabs/skeleton";
    import {
        HomeTab,
        ProceduresTab,
        RunInitTab,
        detailTabSet,
        LocationTab,
        LeviTab,
        PneumaticsTab,
        BatteriesTab,
        DebugTab, details_pane
    } from "$lib";

    let i = 0;
    let tabs = [
        {name: "Home", value: i++},
        {name: "Run", value: i++},
        {name: "Location & IMU", value: i++},
        {name: "Batteries", value: i++},
        {name: "Levitation", value: i++},
        {name: "Pneumatics", value: i++},
        {name: "Procedures", value: i++},
        {name: "Debug", value: i++}
    ];

    let style: string;
    $: style = `height: ${$details_pane-9}vh`;
</script>

<Keydown pauseOnInput on:combo={({detail}) => {
    const num = parseInt(detail, 10);
    if (!isNaN(num) && num <= tabs.length) {
        detailTabSet.set(num - 1); // subtract 1 because your tabs are 0-indexed
    }
    }}/>
<TabGroup regionPanel="h-full" padding="px-3 py-3" regionList="bg-surface-700" border="border-b border-surface-900">
    {#each tabs as tab}
        <Tab bind:group={$detailTabSet} value={tab.value} name={tab.name}><span>{tab.name}</span></Tab>
    {/each}
    <svelte:fragment slot="panel">
        <div style={style} class="snap-x scroll-px-4 snap-mandatory scroll-smooth overflow-x-auto">
            <div class="h-full" style="margin-top: -16px;">
                {#if $detailTabSet === 0}
                    <HomeTab />
                {:else if $detailTabSet === 1}
                    <RunInitTab />
                {:else if $detailTabSet === 2}
                    <LocationTab />
                {:else if $detailTabSet === 3}
                    <BatteriesTab />
                {:else if $detailTabSet === 4}
                    <LeviTab />
                {:else if $detailTabSet === 5}
                    <PneumaticsTab />
                {:else if $detailTabSet === 6}
                    <ProceduresTab />
                {:else if $detailTabSet === 7}
                    <DebugTab />
                {/if}
            </div>
        </div>
    </svelte:fragment>
</TabGroup>