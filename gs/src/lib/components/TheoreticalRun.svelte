<script lang="ts">
    import {Chart, GraphPlot} from "$lib";
    import {onMount} from "svelte";
    import {type TypedArray} from "uplot";

    let chart:GraphPlot;
    let data:TypedArray = new Int32Array(100);

    onMount(() => {
        chart?.addSeries({
            label: "Theoretical run",
            stroke: "red",
            width: 2
        }, data);
    })

    export function calculateTheoretical() {
        // TODO: Implement the theoretical calculation
        let data = new Int32Array(100);
        for (let i = 0; i < 100; i++) {
            data[i] = Math.random() * 50;
        }
        chart?.updateSeries(2, data);
        chart?.redraw();
    }

    function DEBUG_populate_non_theoretical() {
        let data = new Int32Array(100);
        for (let i = 0; i < 100; i++) {
            data[i] = Math.random() * 50;
        }
        chart?.updateSeries(1, data);
        chart?.redraw();
    }

</script>

<Chart height={300} background="bg-surface-900" yRange={[0, 50]} dataPointsCount={100} title="Theoretical vs Real run" bind:chart={chart} refreshRate={0} />