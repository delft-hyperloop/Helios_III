<script lang="ts">
    import { Chart, GrandDataDistributor, Pneumatics, Table, Tile, TileGrid } from "$lib"
    import {DatatypeEnum as DE} from "$lib/namedDatatypeEnum";

    const storeManager = GrandDataDistributor.getInstance().stores;
    const lowPressure = storeManager.getWritable("LowPressureSensor");
    const highPressure = storeManager.getWritable("HighPressureSensor");

    $: pressureTable = [
        ["Low Pressure", DE.LOWPRESSURESENSOR],
        ["High Pressure", DE.HIGHPRESSURESENSOR],
        ["Braking Comm", DE.BRAKINGCOMMDEBUG],
        ["Braking Signal", DE.BRAKINGSIGNALDEBUG],
        ["Braking Rearm", DE.BRAKINGREARMDEBUG],
    ]

    export const pop_up: boolean = true;
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Pneumatics</h2>

    <TileGrid columns="3fr 1fr" rows="">
        <Tile>
            <Pneumatics pressure_left={$highPressure.value} max_pressure_left={250}
                        pressure_right={$lowPressure.value} max_pressure_right={100}/>
        </Tile>
        <Tile>
            <Table background="bg-surface-900" titles={["Section", "Bars"]} tableArr={pressureTable}/>
        </Tile>
        <Tile>
            <Chart title="Breaking Comms" />
        </Tile>
    </TileGrid>
</div>