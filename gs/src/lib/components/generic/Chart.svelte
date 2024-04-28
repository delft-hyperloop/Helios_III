<script lang="ts">
    import {onDestroy, onMount} from 'svelte';
    import 'uplot/dist/uPlot.min.css';
    import { listen, type UnlistenFn } from '@tauri-apps/api/event';
    import {z} from "zod";
    import {GraphPlot} from "$lib/util/GraphPlot";

    // props
    export let dataPointsCount: number = 1000;
    export let refreshRate: number = 100;
    export let title: string = "North Bridge Temperature";

    let unlisten: UnlistenFn;
    let plotContainer: HTMLDivElement;
    const chart = new GraphPlot(dataPointsCount, title);
    let info:number = 0;

    // On mount, draw the chart and start listening for events.
    onMount(async () => {
        chart.draw(plotContainer, refreshRate);

        unlisten = await listen('south_bridge', (event) => {
            // @ts-ignore
            info = z.number().parse(event.payload.value);
            chart.addEntry(info);
        });
    })

    // Free up resources when the component is destroyed
    onDestroy(() => {
        unlisten();
        chart.destroy();
    });
</script>

<div class="flex flex-col bg-surface-800 items-center">
    <h4 class="text-md font-bold text-primary-100">{title}</h4>
    <div class="flex flex-nowrap w-full">
        <div class="rounded-md" bind:this={plotContainer} />
        <div>
            Data: {info.toFixed(2)}
        </div>
    </div>
</div>

