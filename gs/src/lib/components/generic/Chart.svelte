<script lang="ts">
    import {onDestroy, onMount} from 'svelte';
    import 'uplot/dist/uPlot.min.css';
    import {PlotBuffer} from "$lib";
    import {chartStore} from "$lib/stores/state";

    export let title: string;

    export let background: string = "bg-surface-800";
    export let height: number = 200;
    export let chart: PlotBuffer|undefined = $chartStore.get(title);

    let width: number;
    let resize = (width:number) => {
        chart?.setSize(plotContainer, width-15, height);
    }

    $: resize(width);
    let plotContainer: HTMLDivElement;

    onMount(async () => {
        chart?.draw(plotContainer);
        resize(width)
    })

    onDestroy(() => {
        chart?.destroy(plotContainer);
    });
</script>

{#if chart}
    <div bind:clientWidth={width} class="flex flex-col {background} rounded-md pt-2 {width < 550 ? 'text-sm' : ''}">
        <div class="flex gap-2 ml-6">
            <h4 class="text-md text-primary-100">{title}</h4> <span class="font-mono"></span>
        </div>
        <div class="flex flex-col justify-center items-center w-full">
            <div class="rounded-md" bind:this={plotContainer} />
        </div>
    </div>
{:else}
    <p>CHART {title} NOT FOUND</p>
{/if}


