<script lang="ts">
    import Command from "$lib/components/abstract/Command.svelte";

    import {TabGroup, Tab, AppBar, TabAnchor} from "@skeletonlabs/skeleton";
    import HomeTab from "$lib/panels/tabs/HomeTab.svelte";
    import ProceduresTab from "$lib/panels/tabs/ProceduresTab.svelte";

    let selectedTab:number = 7;

    let i = 0;
    let tabs = [
        {name: "Home", value: ++i},
        {name: "Run", value: ++i},
        {name: "Location", value: ++i},
        {name: "IMU", value: ++i},
        {name: "Pressure", value: ++i},
        {name: "Current", value: ++i},
        {name: "Procedures", value: ++i},
        {name: "Debug", value: ++i}
    ];
</script>


<TabGroup regionPanel="h-full" padding="px-3 py-3" regionList="bg-surface-700" border="border-b border-surface-900">
    {#each tabs as tab}
        <Tab bind:group={selectedTab} value={tab.value} name={tab.name}><span>{tab.name}</span></Tab>
    {/each}
    <svelte:fragment slot="panel">
        <div class="h-full" style="margin-top: -16px;">
            {#if selectedTab === 1}
                <HomeTab />
            {:else if selectedTab === 2}
                <p>a</p>
            {:else if selectedTab === 3}
                <p>a</p>
            {:else if selectedTab === 4}
                <p>a</p>
            {:else if selectedTab === 5}
                <p>a</p>
            {:else if selectedTab === 6}
                <p>a</p>
            {:else if selectedTab === 7}
                <ProceduresTab />
            {:else if selectedTab === 8}
                <p>Andreas</p>
            {/if}
        </div>
    </svelte:fragment>
</TabGroup>