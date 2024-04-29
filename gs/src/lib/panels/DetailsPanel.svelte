<script lang="ts">
    import Keydown from "svelte-keydown";
    import {TabGroup, Tab} from "@skeletonlabs/skeleton";
    import HomeTab from "$lib/panels/tabs/HomeTab.svelte";
    import ProceduresTab from "$lib/panels/tabs/ProceduresTab.svelte";
    import {detailTabSet} from "$lib/stores/state";


    let i = 0;
    let tabs = [
        {name: "Home", value: i++},
        {name: "Run", value: i++},
        {name: "Location", value: i++},
        {name: "IMU", value: i++},
        {name: "Pressure", value: i++},
        {name: "Current", value: i++},
        {name: "Procedures", value: i++},
        {name: "Debug", value: i++}
    ];
    let combo:string ='';
</script>

<p>{combo}</p>
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
                <p>a</p>
            {:else if $detailTabSet === 2}
                <p>a</p>
            {:else if $detailTabSet === 3}
                <p>a</p>
            {:else if $detailTabSet === 4}
                <p>a</p>
            {:else if $detailTabSet === 5}
                <p>a</p>
            {:else if $detailTabSet === 6}
                <ProceduresTab />
            {:else if $detailTabSet === 7}
                <p>Andreas</p>
            {/if}
        </div>
    </svelte:fragment>
</TabGroup>