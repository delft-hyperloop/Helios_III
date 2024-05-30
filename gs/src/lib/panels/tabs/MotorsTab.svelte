<script lang="ts">
    import {Chart, TileGrid, Tile, PlotBuffer} from "$lib";
    let width:number;
    let updateSizes:((w:number)=>void)[] = [];
    $: updateSizes.forEach(updateSize => updateSize(width));


    let hemsChart:PlotBuffer;
    let emsChart:PlotBuffer;
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Current</h2>
    <TileGrid columns="3" rows="">
        <Tile>
            <Chart bind:chart={hemsChart} title="HEMS" background="bg-surface-900" />
        </Tile>
        <Tile>
            <Chart bind:chart={emsChart}    title="EMS" background="bg-surface-900" />
        </Tile>
    </TileGrid>
</div>