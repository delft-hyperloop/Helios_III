<script lang="ts">
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
    import { ViewWindow } from "$lib/util/WindowControl"

    let i = 0;
    let tabs = [
        {name: "Home", value: i++},
        {name: "Run", value: i++},
        {name: "Location", value: i++},
        {name: "Batteries", value: i++},
        {name: "Levitation", value: i++},
        {name: "Pneumatics", value: i++},
        {name: "Procedures", value: i++},
        {name: "Debug", value: i++}
    ];

    let style: string;
    $: style = `height: ${$details_pane-9}vh`;
</script>

<TabGroup regionPanel="m-0 !mt-0" padding="px-3 py-3" regionList="bg-surface-700" border="border-b border-surface-900" >
    {#each tabs as tab}
        <Tab bind:group={$detailTabSet} value={tab.value} name={tab.name}>
            <span>{tab.name}</span>
        </Tab>
    {/each}
    <svelte:fragment slot="panel">
        <div style={style} class="snap-x scroll-px-4 snap-mandatory scroll-smooth overflow-x-auto">
            <div class="h-full">
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
