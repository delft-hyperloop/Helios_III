<script lang="ts">
    import type {TempTableEntry} from "$lib/types";
    import {south_bridge_payload} from "$lib/stores/data";
    import Table from "$lib/components/generic/Table.svelte";
    import InitialisationForm from "$lib/components/InitialisationForm.svelte";

    let tableArr2:TempTableEntry[];
    $: tableArr2 = [
        {name: "Some", value: $south_bridge_payload.value},
        {name: "Important", value: $south_bridge_payload.value},
        {name: "Value", value: $south_bridge_payload.value},
        {name: "That", value: $south_bridge_payload.value},
        {name: "Could", value: $south_bridge_payload.value},
        {name: "stay", value: $south_bridge_payload.value},
        {name: "as a", value: $south_bridge_payload.value},
        {name: "table entry", value: $south_bridge_payload.value},
        {name: "here", value: $south_bridge_payload.value},
    ]
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Initialization</h2>
    <div class="flex gap-16">
        <div class="">
            <InitialisationForm />
        </div>
        <div class="flex-grow w-1/2">
            <Table tableArr={tableArr2} titles={["important", "variable"]}/>
        </div>
    </div>
</div>