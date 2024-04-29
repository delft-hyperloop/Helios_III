<script lang="ts">
    import Keydown from "svelte-keydown";
    import {TabGroup, Tab} from "@skeletonlabs/skeleton";
    import HomeTab from "$lib/panels/tabs/HomeTab.svelte";
    import ProceduresTab from "$lib/panels/tabs/ProceduresTab.svelte";
    import {detailTabSet} from "$lib/stores/state";
    import RunInitTab from "$lib/panels/tabs/RunInitTab.svelte";
    import LocationTab from "$lib/panels/tabs/LocationTab.svelte";
    import IPPTab from "$lib/panels/tabs/IPPTab.svelte";
    import CurrentTab from "$lib/panels/tabs/CurrentTab.svelte";


    let i = 0;
    let tabs = [
        {name: "Home", value: i++},
        {name: "Run", value: i++},
        {name: "Location", value: i++},
        {name: "IMU, Pneumatics, Pressure", value: i++},
        {name: "Current", value: i++},
        {name: "Procedures", value: i++},
        {name: "Debug", value: i++}
    ];
</script>

<Keydown on:combo={({detail}) => {
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
        <div class="h-full" style="margin-top: -16px;">
            {#if $detailTabSet === 0}
                <HomeTab />
            {:else if $detailTabSet === 1}
                <RunInitTab />
            {:else if $detailTabSet === 2}
                <LocationTab />
            {:else if $detailTabSet === 3}
                <IPPTab />
            {:else if $detailTabSet === 4}
                <CurrentTab />
            {:else if $detailTabSet === 5}
                <ProceduresTab />
            {:else if $detailTabSet === 6}
                <p>Andreas</p>
            {/if}
        </div>
    </svelte:fragment>
</TabGroup>