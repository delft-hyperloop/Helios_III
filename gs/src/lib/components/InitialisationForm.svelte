<script lang="ts">
    import Command from "$lib/components/abstract/Command.svelte";
    import {inputSpeed} from "$lib/stores/state";

    let selectedButton = 1;

    function selectButton(value:number) {
        selectedButton = value;
    }
</script>

<!--     Forms       -->
<div class="flex flex-col gap-2">
    <p>Mode: </p>
    <div class="flex">
        <button class="btn bg-surface-700 rounded-none p-2" type="button" class:active={selectedButton === 1} on:click={() => selectButton(1)}>
            short run
        </button>
        <button class="btn bg-surface-700 rounded-none p-2" type="button" class:active={selectedButton === 2} on:click={() => selectButton(2)}>
            lane-switch left
        </button>
        <button class="btn bg-surface-700 rounded-none p-2" type="button" class:active={selectedButton === 3} on:click={() => selectButton(3)}>
            lane-switch right
        </button>
    </div>
    <p>Speed: </p>
    <input bind:value={$inputSpeed} class="input rounded-md px-2" type="number" min="0" max="100" step="1">
    <Command command="establish_connection" classes="btn rounded-md bg-surface-700 hover:bg-primary-500" />
    <div class="flex gap-2">
        <Command command="hv_on" classes="btn flex-grow rounded-md bg-surface-700 hover:bg-primary-500" />
        <Command command="hv_off" classes="btn flex-grow rounded-md bg-surface-700 hover:bg-primary-500" />
    </div>
    <div class="flex gap-2">
        <Command command="levitation_on" classes="btn flex-grow rounded-md bg-surface-700 hover:bg-primary-500" />
        <Command command="levitation_off" classes="btn flex-grow rounded-md bg-surface-700 hover:bg-primary-500" />
    </div>
    <Command command="start_run" classes="btn w-full rounded-md bg-primary-500" />
</div>

<style lang="scss">
  .active {
    background-color: rgb(77, 156, 137);
  }
</style>