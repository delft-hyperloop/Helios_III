<script lang="ts">
    import {Command} from "$lib";
    import {NamedCommandValues} from "$lib/types";
    import { procedures } from "$lib/stores/data"
    import { ViewWindow } from "$lib/util/WindowControl"
    import Icon from "@iconify/svelte"

    const values:number[] = new Array(NamedCommandValues.length).fill(0);

    export const pop_up: boolean = true;
</script>

<div class="flex gap-x-2 items-start">
    <h2 class="text-xl font-semibold mb-4">Andreas</h2>
    {#if pop_up}
        <button on:click={() => new ViewWindow("Procedures", `/view/tab/6`)}>
            <Icon icon="carbon:popup" />
        </button>
    {/if}
</div>

<div class="grid grid-cols-4 w-full gap-4 pb-20">
    {#each NamedCommandValues as cmd, i}
        <Command {cmd} val={Number(values[i])}/>
        <input bind:value={values[i]} type="number" class="input">
    {/each}
</div>

