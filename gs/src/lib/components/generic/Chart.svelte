<script lang="ts">
    import {onDestroy, onMount} from 'svelte';
    import 'uplot/dist/uPlot.min.css';
    import {type EventCallback, listen, type UnlistenFn} from '@tauri-apps/api/event';
    import {z} from "zod";
    import {PlotBuffer} from "$lib";
    import {chartStore} from "$lib/stores/state";


    export let title: string;
    export let dataPointsCount: number = 1000;
    export let refreshRate: number = 100;

    export let eventChannel = "south_bridge";
    export let eventCallback: EventCallback<unknown> = (event) => {
        // @ts-ignore
        chart.addEntry(1, z.number().parse(event.payload.data));
    };

    export let background: string = "bg-surface-800";
    export let height: number = 200;
    export let yRange: [number, number] = [0, 100];
    export let showLegend: boolean = false;

    export let chart: PlotBuffer;

    let width: number;
    let resize = (width:number) => {
        chart?.setSize(width-15, height);
    }

    $: resize(width);

    let unlisten: UnlistenFn;
    let plotContainer: HTMLDivElement;

    onMount(async () => {
        let storedChart = $chartStore.get(title);
        if (storedChart) {
            chart = storedChart;
        } else {
            chart = new PlotBuffer(dataPointsCount, yRange, showLegend);
            chartStore.update(store => {
                store.set(title, chart!);
                return store;
            });
        }

        chart.draw(plotContainer, refreshRate);
        resize(width)

        unlisten = await listen(eventChannel, eventCallback);
    })

    onDestroy(() => {
        unlisten();
        chart!.destroy();
    });
</script>

<div bind:clientWidth={width} class="flex flex-col {background} rounded-md pt-2 {width < 550 ? 'text-sm' : ''}">
    <div class="flex gap-2 ml-6">
        <h4 class="text-md text-primary-100">{title}</h4> <span class="font-mono"></span>
    </div>
    <div class="flex flex-col justify-center items-center w-full">
        <div class="rounded-md" bind:this={plotContainer} />
    </div>
</div>

