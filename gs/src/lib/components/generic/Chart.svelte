<script lang="ts">
    import {onDestroy, onMount} from 'svelte';
    import 'uplot/dist/uPlot.min.css';
    import { listen, type UnlistenFn } from '@tauri-apps/api/event';
    import {z} from "zod";
    import {GraphPlot} from "$lib/util/GraphPlot";

    export let dataPointsCount: number = 1000;
    export let refreshRate: number = 100;

    let unlisten: UnlistenFn;
    let plotContainer: HTMLDivElement;

    const chart = new GraphPlot(dataPointsCount);

    // On mount, draw the chart and start listening for events.
    onMount(async () => {
        chart.draw(plotContainer, refreshRate);

        unlisten = await listen('north_bridge', (event) => {
            // @ts-ignore
            chart.addEntry(z.number().parse(event.payload.value));
        });
    })

    // Free up resources when the component is destroyed
    onDestroy(() => {
        unlisten();
        chart.destroy();
    });
</script>

<div bind:this={plotContainer}></div>