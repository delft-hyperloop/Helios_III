<script lang="ts">
    import type {NamedDatatype} from "$lib/types";
    import {GrandDataDistributor} from "$lib";
    import {latestTimestamp} from "$lib/stores/state";


    export let datatype: NamedDatatype;
    const store = GrandDataDistributor.getInstance().stores.getWritable(datatype);

    $: store;
</script>

<span class="text-{$latestTimestamp - $store.timestamp > 10000 ? 'surface' : $store.style === 'critical' ? 'error' : $store.style}-400">
    {typeof $store.value === "number" ?
        $store.value.toFixed(2) : $store.value} {$store.units}
</span>


