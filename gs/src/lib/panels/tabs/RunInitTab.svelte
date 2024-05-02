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
    <h2 class="text-xl font-semibold mb-4">Initialization</h2>
    <div class="flex gap-16">
        <InitialisationForm />
        <div class="flex-grow pt-1 h-full w-1/2 bg-surface-900 rounded-lg">
            <Table tableArr={tableArr2} background="bg-surface-900" titles={["important", "variable"]}/>
        </div>
    </div>
</div>