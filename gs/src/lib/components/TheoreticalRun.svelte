<script lang="ts">
    import {Chart, PlotBuffer, StrokePresets} from "$lib";
    import {onMount} from "svelte";
    import {type TypedArray} from "uplot";

    export let xDataCount = 100;

    let chart:PlotBuffer;
    let data:TypedArray = new Int32Array(xDataCount);

    onMount(() => {
        chart?.addSeries(StrokePresets.theoretical());
        chart?.updateSeries(2, data);
    })

    export function calculateTheoretical() {
        let data = new Int32Array(xDataCount);
        for (let i = 0; i < xDataCount; i++) {
            data[i] = Math.random() * 50;
        }
        chart?.updateSeries(2, data);
        chart?.redraw();
    }

    export function clearRuns() {
        chart?.updateSeries(2, new Int32Array(xDataCount));
        chart?.updateSeries(1, new Int32Array(xDataCount));
        chart?.redraw();
    }

</script>

<Chart height={250} background="bg-surface-900" title="Theoretical vs Real run" bind:chart={chart} refreshRate={100} />