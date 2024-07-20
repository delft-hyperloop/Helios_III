<script lang="ts">
    import { Localiser, TileGrid, Tile, Chart, inputTurn, GrandDataDistributor } from "$lib"
    import {LOCALISATION_NAME, RunMode} from "$lib/types";

    let tableArr2:any[][];
    $: tableArr2 = [
        ["Some", 0],
        ["Important", 0],
        ["Value", 0],
        ["That", 0],
        ["Could", 0],
        ["stay", 0],
        ["as a", 0],
        ["table entry", 0],
        ["here", 0]
    ]

    const storeManager = GrandDataDistributor.getInstance().stores;
    const location = storeManager.getWritable(LOCALISATION_NAME);

    export const pop_up: boolean = true;
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Location & IMU</h2>

    <TileGrid columns="1fr 1fr" rows="">
        <Tile containerClass="col-span-2">
            <Localiser loc={$location.value} max={13000} turning={$inputTurn !== RunMode.ShortRun}/>
        </Tile>
        <Tile>
            <Chart title="Velocity" background="bg-surface-900" />
        </Tile>
        <Tile>
            <Chart title="Acceleration" background="bg-surface-900" />
        </Tile>
        <Tile containerClass="col-start-1 col-span-2">
            <Chart title="Localisation" background="bg-surface-900" />
        </Tile>
    </TileGrid>
</div>
