<script lang="ts">
    import {Table, Localiser, TileGrid, Tile, Chart, inputTurn, GrandDataDistributor} from "$lib";
    import {RunMode} from "$lib/types";

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
    const location = storeManager.getStore("Localisation");
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Location & IMU</h2>
    <TileGrid columns="1fr 1fr" rows="">
        <Tile containerClass="col-span-2">
            <Localiser loc={$location} max={50} turning={$inputTurn !== RunMode.ShortRun}/>
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
<!--        <Tile containerClass="col-start-1 col-span-2">-->
<!--            <Table tableArr={tableArr2} background="bg-surface-900" titles={["Important", "Variable"]}/>-->
<!--        </Tile>-->
    </TileGrid>
</div>
