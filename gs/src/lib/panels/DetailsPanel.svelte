<script lang="ts">
    import Command from "$lib/components/abstract/Command.svelte";

    import {TabGroup, Tab} from "@skeletonlabs/skeleton";

    let selectedTab:number = 1;

    let tabs = [
        {name: "Home", value: 1},
        {name: "Run", value: 2},
        {name: "IMU", value: 3},
        {name: "Pressure", value: 4},
        {name: "Current", value: 5},
        {name: "Procedures", value: 6}
    ];
</script>

<TabGroup>
    {#each tabs as tab}
        <Tab bind:group={selectedTab} value={tab.value} name={tab.name}>{tab.name}</Tab>
    {/each}
    <svelte:fragment slot="panel">
        {#if selectedTab === 1}
            <Command command="start_north_bridge" />
        {:else if selectedTab === 2}
            <Command command="start_south_bridge" />
        {/if}
    </svelte:fragment>
</TabGroup>