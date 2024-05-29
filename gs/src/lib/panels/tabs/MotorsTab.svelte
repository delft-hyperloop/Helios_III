<script lang="ts">
    import {south_bridge_payload, Chart, TileGrid, Tile, PlotBuffer, StrokePresets} from "$lib";
    import {onMount} from "svelte";
    import {z} from "zod";

    let width:number;
    let updateSizes:((w:number)=>void)[] = [];
    $: updateSizes.forEach(updateSize => updateSize(width));


    let hemsChart:PlotBuffer;
    let emsChart:PlotBuffer;

    onMount(() => {
        hemsChart.addSeries(StrokePresets.theoretical())
        hemsChart.addSeries(StrokePresets.yellow())
        hemsChart.addSeries(StrokePresets.blue())

        emsChart.addSeries(StrokePresets.theoretical())
        emsChart.addSeries(StrokePresets.yellow())
        emsChart.addSeries(StrokePresets.blue())
    })
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Current</h2>
    <TileGrid columns="3" rows="">
        <Tile>
            <Chart  eventCallback={(event) => {
                // @ts-ignore
                hemsChart.addEntry(1, z.number().parse(event.payload.values[0]));
                // @ts-ignore
                hemsChart.addEntry(2, z.number().parse(event.payload.values[1]));
                // @ts-ignore
                hemsChart.addEntry(3, z.number().parse(event.payload.values[2]));
                // @ts-ignore
                hemsChart.addEntry(4, z.number().parse(event.payload.values[3]));
            }} bind:chart={hemsChart} eventChannel="hems" title="HEMS" background="bg-surface-900" />
        </Tile>
        <Tile>
            <Chart eventCallback={(event) => {
                // @ts-ignore
                emsChart.addEntry(1, z.number().parse(event.payload.values[0]));
                // @ts-ignore
                emsChart.addEntry(2, z.number().parse(event.payload.values[1]));
                // @ts-ignore
                emsChart.addEntry(3, z.number().parse(event.payload.values[2]));
                // @ts-ignore
                emsChart.addEntry(4, z.number().parse(event.payload.values[3]));
            }} bind:chart={emsChart} eventChannel="ems" title="EMS" background="bg-surface-900" />
        </Tile>
    </TileGrid>
</div>