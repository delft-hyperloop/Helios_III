<script lang="ts">
    import Localiser from "$lib/components/Localiser.svelte";
    import {south_bridge_payload} from "$lib/stores/data";
    import Pneumatics from "$lib/components/Pneumatics.svelte";
</script>

<script lang="ts">
    import {south_bridge_payload, Table, InitialisationForm} from "$lib";

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
    <div class="flex flex-col gap-4">
        <Localiser loc={$south_bridge_payload.value} max={10} turning={true}/>
        <div class="w-7/12">
            <Pneumatics pressure_left={10 - $south_bridge_payload.value} pressure_right={$south_bridge_payload.value} max_pressure={10}/>
        </div>
    </div>
    <div class="grid grid-cols-2 gap-4">
        <Table tableArr={tableArr2} background="bg-surface-900" titles={["Important", "Variable"]}/>
        <Table tableArr={tableArr2} background="bg-surface-900" titles={["Important", "Variable"]}/>
    </div>
</div>