<script lang="ts">
    import type {NamedDatatype} from "$lib/types";
    import {GrandDataDistributor} from "$lib";

    export let datatype: NamedDatatype;
    const store = GrandDataDistributor.getInstance().stores.getStore(datatype);
    const writable = store.writable;
</script>

<span class={store.style}>{typeof $writable === "number" ? $writable.toFixed(2) : $writable}</span>