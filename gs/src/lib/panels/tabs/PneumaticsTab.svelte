<script lang="ts">
    import {GrandDataDistributor, Pneumatics, Table, Tile, TileGrid} from "$lib";

    const storeManager = GrandDataDistributor.getInstance().stores;
    const lowPressure = storeManager.getStore("LowPressureSensor");
    const highPressure = storeManager.getStore("HighPressureSensor");

    $: pressureTable = [
        ["Low Pressure", $lowPressure],
        ["High Pressure", $highPressure]
    ]
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Pneumatics</h2>
    <TileGrid columns="3fr 1fr" rows="">
        <Tile>
            <Pneumatics pressure_left={Math.random()*9} pressure_right={9-Math.random()*9} max_pressure={9} />
        </Tile>
        <Tile>
            <Table background="bg-surface-900" titles={["Value", "V"]} tableArr={pressureTable} />
        </Tile>
    </TileGrid>
</div>