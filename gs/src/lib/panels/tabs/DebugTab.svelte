<script lang="ts">
    import {Command} from "$lib";
    import {NamedCommandValues} from "$lib/types";

    const values:number[] = new Array(NamedCommandValues.length).fill(0);
</script>

<p>Andreas</p>

<div class="grid grid-cols-4 w-full gap-4 pb-20">
    {#each NamedCommandValues as cmd, i}
        <Command {cmd} val={Number(values[i])}/>
        <input bind:value={values[i]} type="number" class="input">
    {/each}
</div>

