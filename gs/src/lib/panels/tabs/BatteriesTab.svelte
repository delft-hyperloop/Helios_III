<script lang="ts">
    import {Battery, Chart, south_bridge_payload, Status, Table, Tile, TileGrid} from "$lib";
    import {hvModulesTemp, hvModulesVol} from "$lib/stores/data";

    let titles = ["Battery", "Avg cell V", "Max cell V", "Min cell V"
        , "Avg cell °C", "Max cell °C", "Min cell °C"];
    let tableArr:any[][] = [
        ["LV", "12.5V", "13.5V", "10.5V", "30°C", "50°C", "20°C"],
    ]

    $: {
        for (let i = 0; i < 8; i++) {
            tableArr[i+1] = [`HV mod ${i}`, $hvModulesVol[i].avg, $hvModulesVol[i].max, $hvModulesVol[i].min, $hvModulesTemp[i].avg, $hvModulesTemp[i].max, $hvModulesTemp[i].min];
        }
    }
</script>

<div class="p-4">
    <p>{$hvModulesTemp[0].avg}</p>
    <h2 class="text-xl font-semibold mb-4">Batteries</h2>
    <TileGrid columns="1fr 1fr 1fr 1fr" rows="auto 1fr auto">
        <Tile insideClass="flex h-full items-center gap-4">
            <div class="flex flex-col items-center">
                <Battery orientation="horizontal" height={40} perc={$south_bridge_payload.value} />
                <p>Low voltage</p>
            </div>
            <div class="flex flex-col items-center">
                <Battery orientation="horizontal" height={40} perc={$south_bridge_payload.value} />
                <p>High voltage</p>
            </div>
        </Tile>
        <Tile containerClass="col-span-2" insideClass="flex justify-center h-full gap-2 items-center">
            <p>HV Battery relay status:</p>
            <Status status={false} />
        </Tile>
        <Tile insideClass="flex h-full items-center">
            <div class="flex flex-col ml-4">
                <p>LV Current: {$south_bridge_payload.value}</p>
                <p>HV Current: {$south_bridge_payload.value}</p>
            </div>
        </Tile>
        <Tile containerClass="col-span-4" heading="Battery stats">
            <Table background="bg-surface-900" {tableArr} {titles} />
        </Tile>
        <Tile containerClass="col-span-2" heading="LV Current">
            <Chart title="LVI" background="bg-surface-900" />
        </Tile>
        <Tile containerClass="col-span-2" heading="HV Current">
            <Chart title="LVI" background="bg-surface-900" />
        </Tile>
    </TileGrid>
</div>