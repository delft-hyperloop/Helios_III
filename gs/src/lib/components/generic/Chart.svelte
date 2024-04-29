<script lang="ts">
    import {onDestroy, onMount} from 'svelte';
    import 'uplot/dist/uPlot.min.css';
    import { listen, type UnlistenFn } from '@tauri-apps/api/event';
    import {z} from "zod";
    import {GraphPlot} from "$lib/util/GraphPlot";

    // props
    export let dataPointsCount: number = 1000;
    export let refreshRate: number = 100;
    export let title: string = "Offset Voltage";
    export let shrink: boolean = true;

    export const resize = (width:number) => {
        if (chart) {
            if (width < 750)
                chart.setSize(width-25, 200);
            else
                shrink ? chart.setSize((width-50)/2, 200) : chart.setSize(width-42, 200);
        }
    }

    let unlisten: UnlistenFn;
    let plotContainer: HTMLDivElement;
    const chart = new GraphPlot(dataPointsCount);
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

<div class="flex flex-col bg-surface-800 rounded-md pt-2">
    <div class="flex gap-4 mx-4">
        <h4 class="text-md text-primary-100">{title}</h4>
        <b>Data</b>: <span class="font-mono">{info.toFixed(2)}</span>
    </div>
    <div class="flex flex-col justify-center items-center w-full">
        <div class="rounded-md" bind:this={plotContainer} />
    </div>
</div>

