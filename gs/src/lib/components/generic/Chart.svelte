<script lang="ts">
    import {onDestroy, onMount} from 'svelte';
    import 'uplot/dist/uPlot.min.css';
    import {type EventCallback, listen, type UnlistenFn} from '@tauri-apps/api/event';
    import {z} from "zod";
    import {PlotBuffer, StrokePresets} from "$lib";

    export let title: string;
    export let eventChannel = "south_bridge";
    export let eventCallback: EventCallback<unknown> = (event) => {
        // @ts-ignore
        info = z.number().parse(event.payload.data);
        chart.addEntry(1, info);
    };
    export let dataPointsCount: number = 1000;
    export let refreshRate: number = 100;
    export let background: string = "bg-surface-800";
    export let height: number = 200;
    export let yRange: [number, number] = [0, 100];
    export let showLegend: boolean = false;

    export const chart = new PlotBuffer(dataPointsCount, yRange, showLegend);

    let width: number;
    let resize = (width:number) => {
        chart?.setSize(width-25, height);
    }

    $: resize(width);

    let unlisten: UnlistenFn;
    let plotContainer: HTMLDivElement;
    let info:number = 0;

    onMount(async () => {
        chart.addSeries(StrokePresets.hyperLoopGreen());

        chart.draw(plotContainer, refreshRate);
        resize(width)

        unlisten = await listen(eventChannel, eventCallback);
    })

    onDestroy(() => {
        unlisten();
        chart.destroy();
    });
</script>

<div bind:clientWidth={width} class="flex flex-col {background} rounded-md pt-2 {width < 550 ? 'text-sm' : ''}">
    <div class="flex gap-2 ml-6">
        <h4 class="text-md text-primary-100">{title}</h4> <span class="font-mono">{info.toFixed(2)}</span>
    </div>
    <div class="flex flex-col justify-center items-center w-full">
        <div class="rounded-md" bind:this={plotContainer} />
    </div>
</div>

