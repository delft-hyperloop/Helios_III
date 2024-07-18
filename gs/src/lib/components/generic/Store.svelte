<script lang="ts">
    import type {NamedDatatype} from "$lib/types";
    import {GrandDataDistributor} from "$lib";

    export let datatype: NamedDatatype;
    $: store = GrandDataDistributor.getInstance().stores.getStore(datatype);

    $: style = store.style;
    $: units = store.units;

    $: writable = store.writable;
</script>

<span class={style}>{typeof $writable === "number" ? $writable.toFixed(2) : $writable} {units}</span>


