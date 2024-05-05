<script lang="ts">
    import {Battery, south_bridge_payload, Table} from "$lib";

    let titles = ["Battery", "Voltage", "Current", "Temperature"];
    let tableArr:any[][] = [
        ["Battery 1", "12.5V", "1.5A", "25°C"],
        ["Battery 2", "12.5V", "1.5A", "25°C"],
        ["Battery 3", "12.5V", "1.5A", "25°C"],
        ["Battery 4", "12.5V", "1.5A", "25°C"],
    ]

</script>


<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Batteries</h2>
    <div class="flex flex-col gap-4">
        <div class="flex gap-4">
            <div class="flex flex-col items-center">
                <Battery orientation="horizontal" height={40} perc={$south_bridge_payload.value} />
                <p>Low voltage</p>
            </div>
            <div class="flex flex-col items-center">
                <Battery orientation="horizontal" height={40} perc={$south_bridge_payload.value} />
                <p>High voltage</p>
            </div>
        </div>
        <div class="grid grid-cols-2 gap-4">
            <Table background="bg-surface-900" {tableArr} {titles} />
            <Table background="bg-surface-900" {tableArr} {titles} />
            <Table background="bg-surface-900" {tableArr} {titles} />
            <Table background="bg-surface-900" {tableArr} {titles} />
        </div>
    </div>
</div>