<script lang="ts">
    import type {NamedDatatype} from "$lib/types";
    import {GrandDataDistributor} from "$lib";

    export let datatype: NamedDatatype;
    const store = GrandDataDistributor.getInstance().stores.getStore(datatype);

    // instead of this shit, fetch the
    const lower_error_threshold = 0;
    const lower_warn_threshold = 0.1;
    const upper_warn_threshold = 1.1;
    const upper_error_threshold = 1.2;

    let colourClass = "";
    $: if ($store < lower_error_threshold || $store > upper_error_threshold) {
        colourClass = "text-error-500";
    } else if ($store < lower_warn_threshold || $store > upper_warn_threshold) {
        colourClass = "text-warning-500";
    } else {
        colourClass = "";
    }
</script>

<span class={colourClass}>{$store}</span>