<script lang="ts">
    import {Battery, south_bridge_payload, Status, Table, Tile, TileGrid} from "$lib";

    let titles = ["Battery", "Avg cell V", "Max cell V", "Min cell V"
        , "Avg cell °C", "Max cell °C", "Min cell °C"];
    let tableArr:any[][] = [
        ["LV", "12.5V", "13.5V", "10.5V", "30°C", "50°C", "20°C"],
        ["HV mod 1", "12.5V", "13.5V", "10.5V", "30°C", "50°C", "20°C"],
        ["HV mod 2", "12.5V", "13.5V", "10.5V", "30°C", "50°C", "20°C"],
        ["HV mod 3", "12.5V", "13.5V", "10.5V", "30°C", "50°C", "20°C"],
        ["HV mod 4", "12.5V", "13.5V", "10.5V", "30°C", "50°C", "20°C"],
        ["HV mod 5", "12.5V", "13.5V", "10.5V", "30°C", "50°C", "20°C"],
        ["HV mod 6", "12.5V", "13.5V", "10.5V", "30°C", "50°C", "20°C"],
        ["HV mod 7", "12.5V", "13.5V", "10.5V", "30°C", "50°C", "20°C"],
        ["HV mod 8", "12.5V", "13.5V", "10.5V", "30°C", "50°C", "20°C"],
    ]
</script>


<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Batteries</h2>
    <TileGrid columns="1fr 1fr" rows="">
        <Tile col_span={1} className="flex h-full items-center gap-4">
            <div class="flex flex-col items-center">
                <Battery orientation="horizontal" height={40} perc={$south_bridge_payload.value} />
                <p>Low voltage</p>
            </div>
            <div class="flex flex-col items-center">
                <Battery orientation="horizontal" height={40} perc={$south_bridge_payload.value} />
                <p>High voltage</p>
            </div>
            <div class="flex flex-col ml-4">
                <p>LV Current: {$south_bridge_payload.value}</p>
                <p>HV Current: {$south_bridge_payload.value}</p>
            </div>
        </Tile>
        <Tile className="flex justify-center h-full gap-2 items-center">
            <p>HV Battery relay status:</p>
            <Status status={false} />
        </Tile>
        <Tile row_start={2} col_span={2} heading="Battery stats">
            <Table background="bg-surface-900" {tableArr} {titles} />
        </Tile>
    </TileGrid>
</div>