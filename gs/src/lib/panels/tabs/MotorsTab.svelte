<script lang="ts">
    import {south_bridge_payload, Chart} from "$lib";

    let width:number;
    let updateSizes:((w:number)=>void)[] = [];
    $: updateSizes.forEach(updateSize => updateSize(width));

    let charts = ["Motor 1", "Motor 2", "HEMS", "EMS"];
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Motors</h2>
    <div bind:clientWidth={width} class="grid grid-cols-2 gap-2">
        {#each charts as title, i}
            <Chart {title} background="bg-surface-900" height={250} refreshRate={100} />
        {/each}
    </div>
    <div class="flex justify-center mt-4 gap-4">
        <p class="text-sm text-gray-400">Motor 1: <span class="font-mono">{$south_bridge_payload.value}</span></p>
        <p class="text-sm text-gray-400">Motor 2: <span class="font-mono">{$south_bridge_payload.value}</span></p>
        <p class="text-sm text-gray-400">HEMS: <span class="font-mono">{$south_bridge_payload.value}</span></p>
        <p class="text-sm text-gray-400">EMS: <span class="font-mono">{$south_bridge_payload.value}</span></p>
    </div>
</div>