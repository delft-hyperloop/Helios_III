<script lang="ts">
    import {south_bridge_payload, Table, Localiser, TileGrid, Tile, Chart, inputTurn} from "$lib";
    import {RunMode} from "$lib/types";

    let tableArr2:any[][];
    $: tableArr2 = [
        ["Some", $south_bridge_payload.value],
        ["Important", $south_bridge_payload.value],
        ["Value", $south_bridge_payload.value],
        ["That", $south_bridge_payload.value],
        ["Could", $south_bridge_payload.value],
        ["stay", $south_bridge_payload.value],
        ["as a", $south_bridge_payload.value],
        ["table entry", $south_bridge_payload.value],
        ["here", $south_bridge_payload.value]
    ]
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Location & IMU</h2>
    <TileGrid columns="1fr 1fr" rows="">
        <Tile containerClass="col-span-2">
            <Localiser loc={$south_bridge_payload.value} max={50} turning={$inputTurn !== RunMode.ShortRun}/>
        </Tile>
        <Tile>
            <Chart title="Speed" background="bg-surface-900" />
        </Tile>
        <Tile>
            <Chart title="Acceleration" background="bg-surface-900" />
        </Tile>
        <Tile containerClass="col-start-1 col-span-2">
            <Table tableArr={tableArr2} background="bg-surface-900" titles={["Important", "Variable"]}/>
        </Tile>
    </TileGrid>
</div>