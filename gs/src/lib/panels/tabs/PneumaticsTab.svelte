<script lang="ts">
    import {GrandDataDistributor, Pneumatics, Table, Tile, TileGrid} from "$lib";
    import {DatatypeEnum as DE} from "$lib/namedDatatypeEnum";

    const storeManager = GrandDataDistributor.getInstance().stores;
    const lowPressure = storeManager.getStore("LowPressureSensor");
    const highPressure = storeManager.getStore("HighPressureSensor");

    $: pressureTable = [
        ["Low Pressure", DE.LOWPRESSURESENSOR],
        ["High Pressure", DE.HIGHPRESSURESENSOR],
        ["Braking Comm", DE.BRAKINGCOMMDEBUG],
        ["Braking Signal", DE.BRAKINGSIGNALDEBUG],
        ["Braking Rearm", DE.BRAKINGREARMDEBUG],
    ]
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Pneumatics</h2>
    <TileGrid columns="3fr 1fr" rows="">
        <Tile>
            <Pneumatics pressure_left={$highPressure} max_pressure_left={250}
                        pressure_right={$lowPressure} max_pressure_right={100}/>
        </Tile>
        <Tile>
            <Table background="bg-surface-900" titles={["Section", "Bars"]} tableArr={pressureTable}/>
        </Tile>
    </TileGrid>
</div>