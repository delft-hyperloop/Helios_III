<script lang="ts">
    import {Command} from "$lib";
    import {NamedCommandValues} from "$lib/types";

    const values:number[] = new Array(NamedCommandValues.length).fill(0);

    export const pop_up: boolean = true;
</script>

<h2 class="text-xl font-semibold mb-4">Andreas</h2>

<div class="grid grid-cols-4 w-full gap-4 pb-20">
    {#each NamedCommandValues as cmd, i}
        <Command {cmd} val={Number(values[i])}/>
        <input bind:value={values[i]} type="number" class="input">
    {/each}
</div>

